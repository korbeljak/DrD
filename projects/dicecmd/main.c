///
/// @file projects/dicecmd/main.c
///
/// DiceCMD utility main.
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
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

// Project includes
#include <drd/os/os.h>
#include <drd/roll/roll.h>

// -------------------------------------
// Constants
// -------------------------------------

// -------------------------------------
// Macros
// -------------------------------------

// -------------------------------------
// Local Data Types
// -------------------------------------

// -------------------------------------
// Forward Declarations
// -------------------------------------

// -------------------------------------
// Variable Definitions
// -------------------------------------

// -------------------------------------
// Function Definitions
// -------------------------------------

// Public Functions

int main(int argc, char* argv[])
{
	OS_RandStartup();

	if (argc >= 3)
	{
		if (strcmp(argv[1], "-r") == 0)
		{
			printf("Roll result: %d\n", DRD_ROLL_Cmd(argv[2]));
		}
		else
		{
			printf("Error: Invalid parameters. Expecting -r COMMAND\n");
		}
	}
	else
	{
		printf("Error: Invalid parameter count. Expecting -r COMMAND\n");
	}

	OS_RandShutdown();
	return 0;
}

// Private Functions

// -------------------------------------
// An empty line follows.


