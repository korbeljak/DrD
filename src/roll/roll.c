///
/// @file src/roll/roll.c
///
/// Dice roll library module.
///
// Copyright (c) 2019, Jakub Korbel <i@jakubkorbel.cz>
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// The views and conclusions contained in the software and documentation are those
// of the authors and should not be interpreted as representing official policies,
// either expressed or implied, of the DrD project.

// -------------------------------------
// Includes
// -------------------------------------

// Environment

// System includes
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

// Project includes
#include <drd/os/os.h>
#include <drd/roll/roll.h>
#include <drd/Environment.h>

// -------------------------------------
// Constants
// -------------------------------------

// -------------------------------------
// Macros
// -------------------------------------

// -------------------------------------
// Local Data Types
// -------------------------------------

///
/// Token Type
///
typedef enum
{
	/// End (\0).
	DRD_TOKEN_OP_PAR_END = 0x00, // 00 00

	/// Addition (+).
	DRD_TOKEN_OP_ADD = 0x01,  // 00 01

	/// Subtraction (-).
	DRD_TOKEN_OP_SUB = 0x05,  // 01 01

	/// Multiplication (*).
	DRD_TOKEN_OP_MUL = 0x02,  // 00 10

	/// Division (/).
	DRD_TOKEN_OP_DIV = 0x06, // 01 10

	/// Opening parenthesis "(".
	DRD_TOKEN_OP_PAR_OPEN = 0x0c, // 11 00

	/// Closing parenthesis ")".
	DRD_TOKEN_OP_PAR_CLOSE = 0x04, // 01 00

	/// A number ([0-9]*).
	DRD_TOKEN_NUM = 0x08, // 10 00

	/// Dice roll, without repetition (d).
	DRD_TOKEN_OP_DICE_NOREPEAT = 0x0a, // 1010

	/// Dice roll, with repetition (k).
	DRD_TOKEN_OP_DICE_REPEAT = 0x0e // 1110
} drd_TokenType_t;

// -------------------------------------
// Forward Declarations
// -------------------------------------

///
/// Gets Precedence value. The higher, the more priority the operator
/// has.
///
/// @param[in] tokType Token Type.
///
/// @return Precedence value (0-3).
///
static int drd_ROLL_GetPrecedence(drd_TokenType_t tokType);

///
/// Computes Operation result.
///
/// @param[in] tokType Token Type.
/// @param[in] a Left Operand.
/// @param[in] b Right Operand.
///
/// @return Operation result.
///
static int drd_ROLL_ComputeOp(drd_TokenType_t tokType, int a, int b);

///
/// Pops two items from a value stack and compute given operation.
///
/// @param[in] tokType Token Type.
/// @param[in,out] pValStackTop Pointer to the top of values stack.
/// @param[in,out] pValStack Pointer to the values stack.
///
static void drd_ROLL_PopTwoCompute(drd_TokenType_t tokType, int* pValStackTop, int* pValStack);

///
/// Pops two items from a value stack and compute given operation.
/// Result of the operation is then stored on the value stack again.
///
/// @param[in] tokType Token Type.
/// @param[in,out] pOpStackTop Pointer to the top of operation stack.
/// @param[in,out] pOpStack Pointer to the operation stack.
/// @param[in,out] pValStackTop Pointer to the top of values stack.
/// @param[in,out] pValStack Pointer to the values stack.
///
/// @retval true Operation was successfully computed and stored.
/// @retval false Error occurred.
///
static bool drd_ROLL_ComputeAllHigherPrecedence(drd_TokenType_t tokType,
		int* pOpStackTop, drd_TokenType_t* pOpStack, int* pValStackTop, int* pValStack);

///
/// Translates the command into its value.
///
/// @param[in] pCmd Command string.
/// @param[out] pRes Result of the given command.
///
/// @retval true Operation was successfully computed.
/// @retval false Error occurred.
///
static bool drd_ROLL_Translate(const char* pCmd, int* pRes);

// -------------------------------------
// Variable Definitions
// -------------------------------------

// -------------------------------------
// Function Definitions
// -------------------------------------

// Public Functions

int DRD_ROLL_Cmd(const char* pCmd)
{
	int res = -1;
	// Compose stack.
	(void)drd_ROLL_Translate(pCmd, &res);

	return res;
}

int DRD_ROLL_Roll(int k, bool repeats)
{
	int rollSingle;
	int rollRes = 0;
	int repCnt = 0;

	if (k == 0)
	{
		return 0;
	}

	do
	{
		rollSingle = (OS_Rand() % k) + 1;
		rollRes += rollSingle;

		printf("Roll (%d) 1%s%d: %d\n", repCnt,
				(repeats) ? "k":"d", k, rollSingle);
		repCnt++;
	}
	while (rollSingle == k && repeats);

	return rollRes;
}


// Private Functions

static int drd_ROLL_GetPrecedence(drd_TokenType_t tokType)
{
	return tokType & 0x3U;
}

static int drd_ROLL_ComputeOp(drd_TokenType_t tokType, int a, int b)
{
	bool repeat = false;
	int val = 0;
	switch (tokType)
	{
	case DRD_TOKEN_OP_ADD:
		val = a + b;
		break;
	case DRD_TOKEN_OP_MUL:
		val = a * b;
		break;
	case DRD_TOKEN_OP_SUB:
		val = a - b;
		break;
	case DRD_TOKEN_OP_DIV:
		OS_ASSERT(b != 0);
		val = a / b;
		break;
	case DRD_TOKEN_OP_DICE_REPEAT:
		OS_ASSERT(b != 1);
		repeat = true;
		// fall-through
	case DRD_TOKEN_OP_DICE_NOREPEAT:
		for (int i = 0; i < a; i++)
		{
			val += DRD_ROLL_Roll(b, repeat);
		}
		break;
	default:
		printf("ERROR!\n");
		break;
	}

	return val;
}
static void drd_ROLL_PopTwoCompute(drd_TokenType_t tokType, int* pValStackTop, int* pValStack)
{
	int v1 = pValStack[*pValStackTop - 2];
	int v2 = pValStack[*pValStackTop - 1];
	pValStack[*pValStackTop - 2] = drd_ROLL_ComputeOp(tokType, v1, v2);
	*pValStackTop -= 1;
}

static bool drd_ROLL_ComputeAllHigherPrecedence(drd_TokenType_t tokType,
		int* pOpStackTop, drd_TokenType_t* pOpStack, int* pValStackTop, int* pValStack)
{
	for (int i = *pOpStackTop - 1;
			i >= 0;
			i--)
	{
		if (drd_ROLL_GetPrecedence(pOpStack[i])
				>= drd_ROLL_GetPrecedence(tokType))
		{
			drd_TokenType_t op = pOpStack[i];

			if (*pValStackTop >= 2)
			{
				drd_ROLL_PopTwoCompute(op, pValStackTop, pValStack);
				*pOpStackTop -= 1;
			}
			else
			{
				return false;
			}
		}
		else
		{
			break;
		}
	}

	pOpStack[*pOpStackTop] = tokType;
	*pOpStackTop += 1;
	return true;
}

static bool drd_ROLL_Translate(const char* pCmd, int* pRes)
{
	bool ok = true;
	if (pCmd != NULL)
	{
		int val = 0;
		int i = 0;
		ok = true;

		int opStackTop = 0;
		int valStackTop = 0;
		drd_TokenType_t opStack[DRD_ROLL_MAX_OP_TOKENS];
		int valStack[DRD_ROLL_MAX_NUM_TOKENS];

		while (ok)
		{
			char c = pCmd[i];
			if (c == '\0')
			{
				ok = drd_ROLL_ComputeAllHigherPrecedence(0,
						&opStackTop,
						opStack,
						&valStackTop,
						valStack);
				ok = ok && valStackTop == 1 && opStackTop == 1
						&& opStack[0] == DRD_TOKEN_OP_PAR_END;
				// End of string.
				break;
			}
			else if (c >= '0' && c <= '9')
			{
				// Parse number.
				val = val * 10 + (c - '0');

				// Look ahead:
				if (pCmd[i + 1] < '0' || pCmd[i + 1] > '9')
				{
					// Store on val stack.
					valStack[valStackTop++] = val;
					val = 0;
				}
			}
			else if (c == ' ' || c == '\n' || c == '\r' || c == '\t')
			{
				// Whitespace, skip it.
			}
			else
			{
				switch (c)
				{
				case 'k':
				// solve all ops with >= precedence
					ok = drd_ROLL_ComputeAllHigherPrecedence(DRD_TOKEN_OP_DICE_REPEAT,
							&opStackTop,
							opStack,
							&valStackTop,
							valStack);
					break;
				case 'd':
					// solve all ops with >= precedence
					ok = drd_ROLL_ComputeAllHigherPrecedence(DRD_TOKEN_OP_DICE_NOREPEAT,
							&opStackTop,
							opStack,
							&valStackTop,
							valStack);
					break;
				case '+':
					ok = drd_ROLL_ComputeAllHigherPrecedence(DRD_TOKEN_OP_ADD,
							&opStackTop,
							opStack,
							&valStackTop,
							valStack);
					break;
				case '-':
					ok = drd_ROLL_ComputeAllHigherPrecedence(DRD_TOKEN_OP_SUB,
							&opStackTop,
							opStack,
							&valStackTop,
							valStack);
					break;
				case '*':
					ok = drd_ROLL_ComputeAllHigherPrecedence(DRD_TOKEN_OP_MUL,
							&opStackTop,
							opStack,
							&valStackTop,
							valStack);
					break;
				case '/':
					ok = drd_ROLL_ComputeAllHigherPrecedence(DRD_TOKEN_OP_DIV,
							&opStackTop,
							opStack,
							&valStackTop,
							valStack);
					break;
				case '(':
					opStack[opStackTop++] = DRD_TOKEN_OP_PAR_OPEN;
					break;
				case ')':
					// drd_ROLL_opStack[drd_ROLL_opStackTop++] = TOKEN_OP_PAR_CLOSE;
					if (opStackTop > 0 && valStackTop >= 2)
					{
						drd_TokenType_t op = opStack[opStackTop - 1];
						drd_ROLL_PopTwoCompute(op,
								&valStackTop,
								valStack);
						opStackTop -= 2;
					}
					else
					{
						ok = false;
					}
					break;
				default:
					ok = false;
					break;
				}
			}

			i++;
		}

		if (ok)
		{
			*pRes = valStack[0];
		}
	}

	return ok;
}

// -------------------------------------
// An empty line follows.

