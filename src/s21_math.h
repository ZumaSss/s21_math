#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POS_INF 1.0 / 0.0
#define NEG_INF -1.0 / 0.0
#define s21_NAN 0.0 / 0.0
#define S21_SQRT_3 ((float)1.732050807569)

#define s21_is_inf __builtin_isinf

#define PI 3.1415926535897932384626433832795
#define LN2 0.693147180559945309417232121458
#define s21_EPS 0.000001L
#define s21_EPS_test 1e-7
#define s21_E 2.71828182845904523536028747
#define S21_NEGZERO -0.0

long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_fmod(double x, double y);
long double s21_floor(double x);
int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
int s21_is_nan(double x);
double s21_fuctorial(int x);
long double s21_pow_int(double base, long long int exp);