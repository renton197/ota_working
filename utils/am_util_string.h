//*****************************************************************************
//
//! @file am_util_string.h
//!
//! @brief A subset of the functions provided in the C standard string library.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_UTIL_STRING_H
#define AM_UTIL_STRING_H

#ifdef __cplusplus
extern "C"
{
#endif


//*****************************************************************************
//
// Character attributes lookup table defines.
//
//*****************************************************************************
#define AM_CATTR_NONE       0x00
#define AM_CATTR_ALPHA      0x01
#define AM_CATTR_LOWER      0x02
#define AM_CATTR_UPPER      0x04
#define AM_CATTR_DIGIT      0x08
#define AM_CATTR_XDIGIT     0x10
#define AM_CATTR_WHSPACE    0x20
#define AM_CATTR_FILENM83   0x80

//
// Set MINIMIZE_CATTR_TABLE to 1 to configure for minimal CATTR table size,
//  (256 instead of 512 bytes) but at a cost of slightly larger code size.
//  However, setting this option also provides an additional level of checking
//  of the argument; if the argument is not a uint8_t, the functions are
//  guaranteed to return 0.
//
#define MINIMIZE_CATTR_TABLE    0


//*****************************************************************************
//
// Globals
//
//*****************************************************************************
extern const uint8_t am_cattr[];


//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern int32_t am_util_string_strcmp(const char *str1, const char *str2);
extern int32_t am_util_string_stricmp(const char *str1, const char *str2);
extern int32_t am_util_string_strncmp(const char *str1, const char *str2,
                                      uint32_t num);
extern int32_t am_util_string_strnicmp(const char *str1, const char *str2,
                                      int num);
extern uint32_t am_util_string_strlen(const char *pcStr);
extern char *am_util_string_strcpy(char *pcDst, const char *pcSrc);
extern char *am_util_string_strncpy(char *pcDst, const char *pcSrc, uint32_t uNum);


//*****************************************************************************
//
// Character "is" macros and functions
//
//*****************************************************************************
//
// By default all of the "is" functions are implemented as macros.  To implement
//  as functions rather than macros, use a global compiler command line (-D)
//  option to define AM_UTIL_STRING_CTYPE_DISABLE_MACROS.
//
#ifdef AM_UTIL_STRING_CTYPE_DISABLE_MACROS
extern int am_util_string_isalnum(int c);
extern int am_util_string_isalpha(int c);
extern int am_util_string_isdigit(int c);
extern int am_util_string_islower(int c);
extern int am_util_string_isspace(int c);
extern int am_util_string_isupper(int c);
extern int am_util_string_isxdigit(int c);
extern int am_util_string_tolower(int c);
extern int am_util_string_toupper(int c);

// Non-standard "is" Functions
extern int am_util_string_isfilenm83(int c);
#else
#if MINIMIZE_CATTR_TABLE
#define am_util_string_isalnum(c)       ((c & 0xffffff80) ? 0 : (am_cattr[c] & (AM_CATTR_ALPHA | AM_CATTR_DIGIT)) ? 1 : 0)
#define am_util_string_isalpha(c)       ((c & 0xffffff80) ? 0 : (am_cattr[c] & AM_CATTR_ALPHA) ? 1 : 0)
#define am_util_string_isdigit(c)       ((c & 0xffffff80) ? 0 : (am_cattr[c] & AM_CATTR_DIGIT) ? 1 : 0)
#define am_util_string_islower(c)       ((c & 0xffffff80) ? 0 : (am_cattr[c] & AM_CATTR_LOWER) ? 1 : 0)
#define am_util_string_isspace(c)       ((c & 0xffffff80) ? 0 : (am_cattr[c] & AM_CATTR_WHSPACE) ? 1 : 0)
#define am_util_string_isupper(c)       ((c & 0xffffff80) ? 0 : (am_cattr[c] & AM_CATTR_UPPER) ? 1 : 0)
#define am_util_string_isxdigit(c)      ((c & 0xffffff80) ? 0 : (am_cattr[c] & AM_CATTR_XDIGIT) ? 1 : 0)
#define am_util_string_tolower(c)       ((am_cattr[c & 0x7f] & AM_CATTR_UPPER) ? c | 0x20 : c)
#define am_util_string_toupper(c)       ((am_cattr[c & 0x7f] & AM_CATTR_LOWER) ? c & ~0x20 : c)
#else
#define am_util_string_isalnum(c)       (am_cattr[c & 0xff] & (AM_CATTR_ALPHA | AM_CATTR_DIGIT))
#define am_util_string_isalpha(c)       (am_cattr[c & 0xff] & AM_CATTR_ALPHA)
#define am_util_string_isdigit(c)       (am_cattr[c & 0xff] & AM_CATTR_DIGIT)
#define am_util_string_islower(c)       (am_cattr[c & 0xff] & AM_CATTR_LOWER)
#define am_util_string_isspace(c)       (am_cattr[c & 0xff] & AM_CATTR_WHSPACE)
#define am_util_string_isupper(c)       (am_cattr[c & 0xff] & AM_CATTR_UPPER)
#define am_util_string_isxdigit(c)      (am_cattr[c & 0xff] & AM_CATTR_XDIGIT)
#define am_util_string_tolower(c)       ((am_cattr[c & 0xff] & AM_CATTR_UPPER) ? c | 0x20 : c)
#define am_util_string_toupper(c)       ((am_cattr[c & 0xff] & AM_CATTR_LOWER) ? c & ~0x20 : c)
#endif // MINIMIZE_CATTR_TABLE

//
// Non-standard "is" Functions
//
#define am_util_string_isfilenm83(c)    (am_cattr[c & 0xff] & AM_CATTR_FILENM83)
#endif // AM_UTIL_STRING_CTYPE_DISABLE_MACROS


#ifdef __cplusplus
}
#endif

#endif // AM_UTIL_STRING_H
