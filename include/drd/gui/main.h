///
/// @file /include/drd/gui/main.h
/// 
/// 
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


#ifndef INCLUDE_DRD_GUI_MAIN_H_
#define INCLUDE_DRD_GUI_MAIN_H_

#if defined(__cplusplus)
extern "C" {
#endif

// -------------------------------------
// Includes
// -------------------------------------


// Environment
#include <drd/Environment.h>

// System includes

// Project includes

// -------------------------------------
// Constants
// -------------------------------------

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

///
/// Runs Main GUI Loop
///
void DRD_GUI_RunMain(int argc, char* argv[]);

#if defined(__cplusplus)
}
#endif
#endif /* INCLUDE_DRD_GUI_MAIN_H_ */

// -------------------------------------
// An empty line follows.
