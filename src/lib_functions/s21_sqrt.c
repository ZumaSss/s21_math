#include "../s21_math.h"

long double s21_sqrt(double x) {
  long double res = 0;
  if (x < 0)
    res = -s21_NAN;
  else if (x == 0)
    res = 0.0;
  else if (x == POS_INF)
    res = POS_INF;
  else {
    long double a = x / 2.0;
    long double lastA = 0;
    while (s21_fabs(lastA - a) > s21_EPS) {
      lastA = a;
      a = 0.5 * (a + x / a);
    }
    res = a;
  }

  return res;
}