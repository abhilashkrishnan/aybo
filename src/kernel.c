#include "kernel.h"

uint16_t* video_mem = 0;

uint16_t terminal_make_char(char c, char color) 
{
    return (color << 8) | c;
}

void terminal_initialize() 
{
    video_mem = (uint16_t*)(0xB8000);

    for (int y = 0; y < VGA_HEIGHT; y++)
    {
        for (int x = 0; x < VGA_WIDTH; x++)
        {
            video_mem[(y * VGA_WIDTH) + x] = terminal_make_char(' ', 0);
        }
    }
    
}

void kernel_main() 
{
    terminal_initialize();

    video_mem[0] = terminal_make_char('A', 4);
    video_mem[1] = terminal_make_char('Y', 4);
    video_mem[2] = terminal_make_char('B', 4);
    video_mem[3] = terminal_make_char('O', 4);
    video_mem[4] = terminal_make_char(' ', 0);
    video_mem[5] = terminal_make_char('O', 4);
    video_mem[6] = terminal_make_char('S', 4);
}