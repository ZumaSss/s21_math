#include "../s21_math.h"

long double s21_sin(double x) {
  long double res = 0;
  if (x == PI)
    res = 0.0;
  else if (x == 2 * PI)
    res = -0.0;
  else if (x == POS_INF || s21_is_nan(x))
    res = s21_NAN;
  else {
    x = s21_fmod(x, 2 * PI);

    long double temp = x;
    long double sigmaTemp = 0;
    long double i = 1;

    while (s21_fabs(temp - sigmaTemp) > s21_EPS) {
      res += temp;
      sigmaTemp = temp;
      temp *= (-1) * (x * x) / ((2 * i + 1) * (2 * i));
      i += 1;
    }
  }

  return res;
}