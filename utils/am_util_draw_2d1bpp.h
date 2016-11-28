//*****************************************************************************
//
//! @file am_util_draw_2d1bpp.h
//!
//! @brief High level 1bpp drawing routines for Ambiq Micro products.
//!
//! This file contains the high level, 1bpp drawing routines used for
//! displaying to an LCD screen.  The routines draw into a framebuffer
//! and do not draw directly to the display.
//
//*****************************************************************************

//*****************************************************************************
//
// ${copyright}
//
// This is part of revision ${version} of the AmbiqSuite Development Package.
//
//*****************************************************************************
#ifndef AM_UTIL_DRAW_2D1BPP_H
#define AM_UTIL_DRAW_2D1BPP_H

#ifdef __cplusplus
extern "C"
{
#endif

//*****************************************************************************
//
// C99
//
//*****************************************************************************
#include <stdint.h>
#include <stdbool.h>

//*****************************************************************************
//
// Macro definitions
//
//*****************************************************************************


//*****************************************************************************
// Drawing operations:
//
//  These ROPs apply only to am_util_draw_2d1bpp_bitmap_draw():
//      AM_UTIL_DRAW_ROPS_INVERT
//      AM_UTIL_DRAW_ROPS_MIRROR
//
//  These ROPs apply to all drawing functions:
//      AM_UTIL_DRAW_ROPS_COPY
//      AM_UTIL_DRAW_ROPS_XOR
//      AM_UTIL_DRAW_ROPS_OR
//
//*****************************************************************************
//
// AM_UTIL_DRAW_ROPS_COPY copies the bitmap pattern to the framebuffer.
// Note that AM_UTIL_DRAW_ROPS_NORMAL is deprecated.
//
#define AM_UTIL_DRAW_ROPS_COPY          0x0000
#define AM_UTIL_DRAW_ROPS_NORMAL        AM_UTIL_DRAW_ROPS_COPY

//
// AM_UTIL_DRAW_ROPS_INVERT inverts the bitmap pattern then copies it to the
// framebuffer.
//
#define AM_UTIL_DRAW_ROPS_INVERT        0x0001

//
// AM_UTIL_DRAW_ROPS_MIRROR mirrors the bitmap pattern (rotating it 180 degrees)
// then copies it to the framebuffer.
//
#define AM_UTIL_DRAW_ROPS_MIRROR        0x0002

//
// AM_UTIL_DRAW_ROPS_XOR performs a Boolean operation (XOR, OR, AND) between
// the bitmap pattern (including lines, rectanges, ellipses, etc) and the
// existing framebuffer data.
//
#define AM_UTIL_DRAW_ROPS_XOR           0x0004
#define AM_UTIL_DRAW_ROPS_OR            0x0008


//*****************************************************************************
//
// Data structure used for display devices.
//
//*****************************************************************************
typedef struct
{
    //*************************************************************************
    // All members of this structure are initialized by the application using
    //  respective members of the display device structure, which is filled in
    //  by the call to the display driver init function.
    // Therefore, this structure is intialized AFTER the display driver init
    //  function is called, but before calling any drawing function.
    //*************************************************************************
    //
    // Framebuffer pointer.
    // The framebuffer must be guaranteed to be 32-bit aligned.
    //
    uint8_t *pui8Framebuffer;

    //
    // Display width (X dimension).
    //
    uint32_t ui32DrawWidth;

    //
    // Display height (Y dimension).
    //
    uint32_t ui32DrawHeight;

    //
    // The ui32DrawPolarity is set by the display driver and determines the
    //  polarity used by the display for drawing the background.
    // If 1, the display is cleared with all 0xFFs.
    // If 0, the display is cleared with all 0x00s.
    //
    uint32_t ui32DrawPolarity;

    //*****************************************************************************
    // Font selector is updated after a call to am_util_draw_2d1bpp_font_select().
    //*****************************************************************************
    //
    // Font selector
    //
    uint32_t ui32FontSel;
}
am_util_draw_2d1bpp_context_t;

//*****************************************************************************
//
// External function definitions
//
//*****************************************************************************
extern uint32_t am_util_draw_2d1bpp_pixel_get(
                            am_util_draw_2d1bpp_context_t *psDrawContext,
                            uint32_t ui32X, uint32_t ui32Y);
extern void     am_util_draw_2d1bpp_pixel_set(
                            am_util_draw_2d1bpp_context_t *psDrawContext,
                            uint32_t ui32X, uint32_t ui32Y,
                            uint32_t ui32Color);
extern bool     am_util_draw_2d1bpp_bitmap_draw(
                            am_util_draw_2d1bpp_context_t *psDrawContext,
                            const uint8_t *pui8Bitmap,
                            uint32_t ui32Width, uint32_t ui32Height,
                            uint32_t ui32DstX,  uint32_t ui32DstY,
                            uint32_t ui32DrawingOps);
extern bool     am_util_draw_2d1bpp_font_select(
                            am_util_draw_2d1bpp_context_t *psDrawContext,
                            uint32_t ui32FontSel);
extern uint32_t am_util_draw_2d1bpp_fontsize_get(
                            am_util_draw_2d1bpp_context_t *psDrawContext);
extern bool     am_util_draw_2d1bpp_char_draw(
                            am_util_draw_2d1bpp_context_t *psDrawContext,
                            uint8_t ui16Char, uint32_t ui32X, uint32_t ui32Y,
                            uint32_t ui32Color);
extern bool     am_util_draw_2d1bpp_string_draw(
                            am_util_draw_2d1bpp_context_t *psDrawContext,
                            uint8_t *pui8Char, uint32_t ui32X, uint32_t ui32Y,
                            uint32_t ui32DrawingOps,
                            uint32_t ui32Color );
extern bool     am_util_draw_2d1bpp_rectangle_draw(
                            am_util_draw_2d1bpp_context_t *psDrawContext,
                            uint32_t ui32DstX,  uint32_t ui32DstY,
                            uint32_t ui32Width, uint32_t ui32Height,
                            uint32_t ui32DrawingOps,
                            uint32_t ui32Color, bool bFill );
extern bool     am_util_draw_2d1bpp_line_draw(
                            am_util_draw_2d1bpp_context_t *psDrawContext,
                            uint32_t ui32X1,  uint32_t ui32Y1,
                            uint32_t ui32X2,  uint32_t ui32Y2,
                            uint32_t ui32LineWidth,
                            uint32_t ui32DrawingOps, uint32_t ui32Color );
extern bool     am_util_draw_2d1bpp_ellipse_draw(
                            am_util_draw_2d1bpp_context_t *psDrawContext,
                            uint32_t ui32X,    uint32_t ui32Y,
                            uint32_t ui32Xrad, uint32_t ui32Yrad,
                            uint32_t ui32DrawingOps,
                            uint32_t ui32Color, bool bFill );

#ifdef __cplusplus
}
#endif

#endif // AM_UTIL_DRAW_2D1BPP_H
