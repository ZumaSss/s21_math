#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = s21_NAN;
  long long int mod = x / y;
  if (s21_is_nan(x) || s21_is_nan(x) || s21_fabs(x) == POS_INF) {
    result = s21_NAN;
  } else if (s21_fabs(y) == POS_INF) {
    result = x;
  } else if (y != 0) {
    result = (long double)x - mod * (long double)y;
  }
  return result;
}
