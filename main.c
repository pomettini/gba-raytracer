#include "main.h"

static inline vector vector_sub(vector *v1, vector *v2)
{
	vector result = { v1->x - v2->x, v1->y - v2->y, v1->z - v2->z };
	return result;
}

static inline float vector_dot(vector *v1, vector *v2)
{
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

static inline int intersect_ray_sphere(ray *r, sphere *s)
{
	float a = vector_dot(&r->dir, &r->dir);
	vector dist = vector_sub(&r->start, &s->pos);
	float b = 2 * vector_dot(&r->dir, &dist);
	float c = vector_dot(&dist, &dist) - (s->radius * s->radius);
	float discr = b * b - 4 * a * c;

	if (discr < 0)
		return 0;
	else
		return 1;
}

static inline unsigned short rgb(int r, int g, int b)
{
	return r | (g << 5) | (b << 10);
}

static inline void put_pixel(int x, int y, short color)
{
	((unsigned short*)0x06000000)[y * SCREEN_WIDTH + x] = color;
}

int main()
{
	// Cartridge init
	*(unsigned int*)0x04000000 = 0x0403;

	sphere s1;
	sphere s2;
	ray r;

	int x, y;

	int hit1;
	int hit2;

	s1.pos.x = 40;
	s1.pos.y = 40;
	s1.pos.z = 20;

	s1.radius = 40;

	s2.pos.x = 60;
	s2.pos.y = 60;
	s2.pos.z = 20;

	s2.radius = 40;

	r.dir.x = 0;
	r.dir.y = 0;
	r.dir.z = 1;

	r.start.z = 0;

	for (y = 0; y < SCREEN_HEIGHT; y++)
	{
		r.start.y = y;
		for (x = 0; x < SCREEN_WIDTH; x++)
		{
			r.start.x = x;
			
			hit1 = intersect_ray_sphere(&r, &s1);
			hit2 = intersect_ray_sphere(&r, &s2);
			
			if (hit2)
			{
				put_pixel(x, y, rgb(255, 255, 0));
			}
			else if (hit1)
			{
				put_pixel(x, y, rgb(255, 0, 255));
			}
		}
	}

	while(1);

	return 0;
}
