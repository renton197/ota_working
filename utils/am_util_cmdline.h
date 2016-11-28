//*****************************************************************************
//
//! @file am_util_cmdline.h
//!
//! @brief Functions to implement a simple command line interface.
//!
//! Functions supporting a command-line interface.
//
//*****************************************************************************

//*****************************************************************************
//
// Copyright (c) 2016, Ambiq Micro
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its
// contributors may be used to endorse or promote products derived from this
// software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//
// This is part of revision 1.2.1 of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_UTIL_CMDLINE_H
#define AM_UTIL_CMDLINE_H

#ifdef __cplusplus
extern "C"
{
#endif
//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************

//*****************************************************************************
//
// Standard Command Function Pointer Type
//
//*****************************************************************************
typedef uint32_t (*am_util_cmdline_func_t)(char **args, uint32_t argc);

//*****************************************************************************
//
// Command Structure.
//
//*****************************************************************************
typedef struct
{
    char *pcCommand;
    am_util_cmdline_func_t pfnCommand;
    char *pcHelpString;
}
am_util_cmdline_command_t;

//*****************************************************************************
//
// Stucture defining how the cmdline utility may transmit or receive
// characters.
//
//*****************************************************************************
typedef struct
{
    //
    // Function used to grab input characters.
    //
    uint32_t (*pfnGetChar)(char *pcChar);

    //
    // Function used to echo characters back to the output.
    //
    void (*pfnPutChar)(char pcChar);

    //
    // List of supported commands, along with their associated function
    // pointers and help strings.
    //
    am_util_cmdline_command_t *psCommandList;

    //
    // Number of supported commands. Usually just:
    // sizeof(psCommandList) / sizeof(am_util_cmdline_command_t)
    //
    uint32_t ui32NumCommands;

    //
    // Buffer space to use for incoming commands.
    //
    char *psCommandData;

    //
    // Size of command buffer. Usually just: sizeof(psCommandData)
    //
    uint32_t ui32CommandDataLen;

    //
    // Prompt String
    //
    char *pcPromptString;
}
am_util_cmdline_interface_t;

//*****************************************************************************
//
// External variable definitions
//
//*****************************************************************************

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_util_cmdline_process_commands(void);
extern void am_util_cmdline_init(am_util_cmdline_interface_t *psInterface);
extern uint32_t am_util_cmdline_run_command(char **args, uint32_t argc);

#ifdef __cplusplus
}
#endif

#endif // AM_UTIL_CMDLINE_H

