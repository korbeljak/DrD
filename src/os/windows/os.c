///
/// @file src/os/windows/os.c
///
/// Windows implementation of os primitives.
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
#define WIN32_NO_STATUS
	#include <windows.h>
#undef WIN32_NO_STATUS

#include <winternl.h>
#include <ntstatus.h>
#include <winerror.h>
#include <bcrypt.h>

// Project includes
#include <drd/os/os.h>

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

//
// Initializes and starts up the random engine.
//
void OS_RandStartup(void)
{
	// Empty.
}

//
// Returns 4 bytes of randomness.
//
uint32_t OS_Rand(void)
{
	uint32_t result = 0;
	NTSTATUS status =
			BCryptGenRandom(NULL, &result,
				sizeof(result),
				BCRYPT_USE_SYSTEM_PREFERRED_RNG);
	OS_ASSERT(status == STATUS_SUCCESS);

	return result;
}


//
// Returns n bytes of randomness.
//
void OS_RandBuf(uint8_t* pBuf, unsigned int bufBytes)
{
	NTSTATUS status =  BCryptGenRandom(NULL, pBuf, bufBytes,
							BCRYPT_USE_SYSTEM_PREFERRED_RNG);
	OS_ASSERT(status == STATUS_SUCCESS);
}

//
// Destroys the random engine.
//
void OS_RandShutdown(void)
{
	// Empty.
}


// Private Functions

// -------------------------------------
// An empty line follows.

