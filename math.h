#ifndef MATH_H
#define MATH_H

const float PI = 3.14159226;
const int TERMS = 7;

static inline float sine(int deg);
static inline float cosine(int deg);
static inline float tangent(int deg);
static inline float power(float base, int exp);
static inline int fact(int n);
static inline float square_root(float n);

#endif