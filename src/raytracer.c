#include "raytracer.h"

static inline vector vector_sub(vector *v1, vector *v2)
{
	vector result = {v1->x - v2->x, v1->y - v2->y, v1->z - v2->z};
	return result;
}

static inline float vector_dot(vector *v1, vector *v2)
{
	return v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
}

static inline int intersect_ray_sphere(ray *r, sphere *s, float *t)
{
	int ret = 0;

	float a = vector_dot(&r->dir, &r->dir);
	vector dist = vector_sub(&r->start, &s->pos);
	float b = 2 * vector_dot(&r->dir, &dist);
	float c = vector_dot(&dist, &dist) - (s->radius * s->radius);
	float discr = b * b - 4 * a * c;

	if (discr < 0)
		ret = 0;
	else
	{
		float sqrt_discr = square_root(discr);
		float t0 = (-b + sqrt_discr) / 2;
		float t1 = (-b - sqrt_discr) / 2;

		if (t0 > t1)
			t0 = t1;

		if ((t0 > 0.001f) && (t0 < *t))
		{
			*t = t0;
			ret = 1;
		}
		else
			ret = 0;
	}

	return ret;
}

static inline vector vector_scale(float c, vector *v)
{
	vector result = {v->x * c, v->y * c, v->z * c};
	return result;
}

static inline vector vector_add(vector *v1, vector *v2)
{
	vector result = {v1->x + v2->x, v1->y + v2->y, v1->z + v2->z};
	return result;
}

static inline unsigned short rgb(int r, int g, int b)
{
	return r | (g << 5) | (b << 10);
}

static inline void put_pixel(int x, int y, short color)
{
	((unsigned short *)0x06000000)[y * SCREEN_WIDTH + x] = color;
}

static float square_root(float n)
{
	float x = n;
	for (int i; i < 20; i++)
	{
		x = (((x * x) + n) / (2 * x));
	}
	return x;
}
