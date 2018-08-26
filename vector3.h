typedef struct vec3
{
	float x;
	float y;
	float z;
} vec3_t;

vec3_t vec3_create(float, float, float);
vec3_t vec3_add(vec3_t, vec3_t);
vec3_t vec3_sub(vec3_t, vec3_t);
float vec3_dot(vec3_t, vec3_t);
vec3_t vec3_cross(vec3_t, vec3_t);
vec3_t vec3_mul(vec3_t, vec3_t);
vec3_t vec3_scaled(vec3_t, float);
float vec3_len(vec3_t);
float vec3_len_sq(vec3_t);
void vec3_normalize(vec3_t *);
vec3_t vec3_normalized(vec3_t);