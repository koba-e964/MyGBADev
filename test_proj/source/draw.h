#ifndef DRAW_H_2231
#define DRAW_H_2231

#include <gba_console.h>
#include <gba_video.h>
#include <gba_interrupt.h>
#include <gba_systemcalls.h>
#include <gba_input.h>

void WaitForVsync(void);

void Mode3PutPixel(u16 x, u16 y, u16 col);

#endif
