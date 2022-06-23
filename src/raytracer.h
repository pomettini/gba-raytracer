#pragma once

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 160

const float PI = 3.14159265;

#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct
{
    float x, y, z;
} vector;

typedef struct
{
    vector start;
    vector dir;
} ray;

typedef struct
{
    float red, green, blue;
} color;

typedef struct
{
    color diffuse;
} material;

typedef struct
{
    vector pos;
    float radius;
    material material;
} sphere;

typedef struct
{
    vector pos;
    color intensity;
} light;

static inline vector vector_sub(vector *v1, vector *v2);
static inline float vector_dot(vector *v1, vector *v2);
static inline int intersect_ray_sphere(ray *r, sphere *s, float *t);

static inline void put_pixel(int x, int y, short color);
static inline unsigned short rgb(int r, int g, int b);

static float square_root(float n);
