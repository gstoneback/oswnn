#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
 
#include <kernel/tty.h>
 
#include "vga.h"
 
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
static uint16_t* const VGA_MEMORY = (uint16_t*) 0xB8000;
 
static size_t tty_row;
static size_t tty_column;
static uint8_t tty_color;
static uint16_t* tty_buffer;
 
void tty_scroll(void) {
	for(size_t y = 0; y < VGA_HEIGHT-1; y++) {
		for(size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			tty_buffer[index] = tty_buffer[index+VGA_WIDTH];
		}
	}
	for(size_t x = 0; x < VGA_WIDTH; x++) {
		const size_t index = (VGA_WIDTH-1) * VGA_WIDTH + x;
		tty_buffer[index] = vga_entry(' ', tty_color);
	}
}
void tty_initialize(void) {
	tty_row = 0;
	tty_column = 0;
	tty_color = vga_entry_color(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	tty_buffer = VGA_MEMORY;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			tty_buffer[index] = vga_entry(' ', tty_color);
		}
	}
}
 
void tty_setcolor(uint8_t color) {
	tty_color = color;
}
 
void tty_putentryat(unsigned char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	tty_buffer[index] = vga_entry(c, color);
}
 
void tty_putchar(char c) {
	unsigned char uc = c;
	switch (uc) {
		case '\t':
			tty_column = ((tty_column/4)+1)*4;
			break;
		case '\r':
			tty_column = 0;
			break;
		case '\n':
			tty_column = 0;
			++tty_row;
			break;
		default:
			tty_putentryat(uc, tty_color, tty_column, tty_row);
			if (++tty_column == VGA_WIDTH) {
				tty_column = 0;
				if (++tty_row == VGA_HEIGHT)
					tty_row = 0;
			}
	}
}
 
void tty_write(const char* data, size_t size) {
	for (size_t i = 0; i < size; i++)
		tty_putchar(data[i]);
}
 
void tty_writestring(const char* data) {
	tty_write(data, strlen(data));
}
