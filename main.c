#include "vector3.h"

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160

static inline void put_pixel(int x, int y, short color);
static inline unsigned short rgb(int r, int g, int b);

volatile short x;
volatile short y;

int main()
{
	*(unsigned int*)0x04000000 = 0x0403;

	for (x = 0; x < SCREEN_WIDTH; x++)
	{
		for (y = 0; y < SCREEN_HEIGHT; y++)
		{
			put_pixel(x, y, rgb(255, x, y));
		}
	}
	
	while(1);

	return 0;
}

static inline unsigned short rgb(int r, int g, int b)
{
	return r | (g << 5) | (b << 10);
}

static inline void put_pixel(int x, int y, short color)
{
	((unsigned short*)0x06000000)[y * SCREEN_WIDTH + x] = color;
}