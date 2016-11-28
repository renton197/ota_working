//*****************************************************************************
//
//! @file am_util_stdio.h
//!
//! @brief A few printf-style functions for use with Ambiq products
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_UTIL_STDIO_H
#define AM_UTIL_STDIO_H

/* get va_list from compiler. */
#include <stdarg.h>

#ifdef __cplusplus
extern "C"
{
#endif
//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************

// buffer size for printf
#ifndef AM_PRINTF_BUFSIZE
#define AM_PRINTF_BUFSIZE              256
#endif

typedef void (*am_util_stdio_print_char_t)(char *pcStr);

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern void am_util_stdio_printf_init(am_util_stdio_print_char_t pfnCharPrint);
extern uint32_t am_util_stdio_strtoul(const char *str, char **endptr, int base);
extern bool am_util_stdio_textmode_set(bool bSetTextTranslationMode);
extern uint32_t am_util_stdio_vsprintf(char *pcBuf, const char *pcFmt, va_list pArgs);
extern uint32_t am_util_stdio_sprintf(char *pui8Buf, const char *pui8Fmt, ...);
extern uint32_t am_util_stdio_printf(const char *pui8Fmt, ...);
extern void am_util_stdio_terminal_clear(void);

#ifdef __cplusplus
}
#endif

#endif // AM_UTIL_STDIO_H

