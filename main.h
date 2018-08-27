#ifndef MAIN_H
#define MAIN_H

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160

// Thanks to purplealienplanet.com

typedef struct
{
	float x, y, z;
} vector;

typedef struct
{
	vector pos;
	float radius;
} sphere;

typedef struct
{
	vector start;
	vector dir;
} ray;

static inline vector vector_sub(vector *v1, vector *v2);
static inline float vector_dot(vector *v1, vector *v2);
static inline int intersect_ray_sphere(ray *r, sphere *s);

static inline void put_pixel(int x, int y, short color);
static inline unsigned short rgb(int r, int g, int b);

#endif