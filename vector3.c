#include "vector3.h"

vec3_t vec3_create(float x, float y, float z)
{
    vec3_t result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

vec3_t vec3_add(vec3_t v1, vec3_t v2)
{
    return vec3_create(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

vec3_t vec3_sub(vec3_t v1, vec3_t v2)
{
    return vec3_create(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

float vec3_dot(vec3_t v1, vec3_t v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

vec3_t vec3_cross(vec3_t v1, vec3_t v2)
{
    float x = v1.y * v2.z - v1.z * v2.y;
    float y = v1.z * v2.x - v1.x * v2.z;
    float z = v1.x * v2.y - v1.y * v2.x;

    return vec3_create(x, y, z);
}

vec3_t vec3_mul(vec3_t v1, vec3_t v2)
{
    return vec3_create(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
}

vec3_t vec3_scaled(vec3_t v, float s)
{
    return vec3_create(v.x * s, v.y * s, v.z * s);
}

float vec3_len(vec3_t v)
{
    return sqrt(vec3_len_sq(v));
}

float vec3_len_sq(vec3_t v)
{
    return vec3_dot(v, v);
}

void vec3_normalize(vec3_t *v)
{
    vec3_t temp = vec3_create(v->x, v->y, v->z);
    float len = vec3_len(temp);

    if(len == 0)
        return;

    v->x /= len;
    v->y /= len;
    v->z /= len;
}

vec3_t vec3_normalized(vec3_t v)
{
    float len = vec3_len(v);

    if(len == 0)
        return v;
    
    return vec3_create(v.x / len, v.y / len, v.z / len);
}