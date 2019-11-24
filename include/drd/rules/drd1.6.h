///
/// @file include/drd/rules/1.6/class.h
///
/// DrD character class API.
///
// SIMPLIFIED BSD LICENSE (FREEBSD LICENSE):
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


#ifndef INCLUDE_DRD_RULES_1_6_H
#define INCLUDE_DRD_RULES_1_6_H

#if defined(__cplusplus)
extern "C" {
#endif

// -------------------------------------
// Includes
// -------------------------------------


// Environment


// System includes

// Project includes
#include <drd/util/utils.h>

// Sub-rules.
#include <drd/rules/1.6/race.h>
#include <drd/rules/1.6/class.h>

// -------------------------------------
// Constants
// -------------------------------------

/// Size Class.
typedef enum
{
	/// Size Class A0 - Rats, etc.
    SIZE_CLASS_A0 = 0,

	/// Size Class A - Hobbits, etc.
    SIZE_CLASS_A = 1,

	/// Size Class B - Humans, etc.INCLUDE_DRD_CLASS_H_
    SIZE_CLASS_B = 2,

	/// Size Class C - Kroll, etc.
    SIZE_CLASS_C = 3,

	/// Size Class D - Giant, etc.
    SIZE_CLASS_D = 4,

	/// Size Class E - Dragon, etc.
    SIZE_CLASS_E = 5
} DRD_SizeClass_t;


/// Check result codes.
typedef enum
{
	/// Common failure.
    CHECK_FAILURE = 0x00,

	/// Common success.
    CHECK_SUCCESS = 0x01,

	/// Critical failure.
    CHECK_CRIT_FAILURE = 0x02,

	/// Critical success (whatever it means)...
    CHECK_CRIT_SUCCESS = 0x03
} DRD_CheckResult_t;

// -------------------------------------
// Macros
// -------------------------------------

// -------------------------------------
// Global Data Types
// -------------------------------------

// -------------------------------------
// External Variable Declarations
// -------------------------------------

// -------------------------------------
// Function Definitions
// -------------------------------------

#if defined(__cplusplus)
}
#endif
#endif /* INCLUDE_DRD_RULES_1_6_H */

// -------------------------------------
// An empty line follows.

