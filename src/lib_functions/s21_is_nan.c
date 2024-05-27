#include "../s21_math.h"

int s21_is_nan(double x) { return x != x ? 1 : 0; }