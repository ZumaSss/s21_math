#include <math.h>

#include "../s21_math.h"

long double s21_log(double x) {
  long double res = 0;
  if (x < 0 || x == NEG_INF || s21_is_nan(x)) {
    res = s21_NAN;
  } else if (x == 0) {
    res = NEG_INF;
  } else if (x == POS_INF) {
    res = POS_INF;
  } else if (x == 1) {
    res = 0;
  } else {
    double N = 0.0, P = x, A = 0;
    while (P >= s21_E) {
      P /= s21_E;
      N++;
    }
    N += (P / s21_E);
    P = x;
    int j = 0;
    do {
      double L, R;
      A = N;
      L = (P / (s21_exp(N - 1.0)));
      R = ((N - 1.0) * s21_E);
      N = ((L + R) / s21_E);
      j++;
    } while (N != A && j < 10000);
    res = N;
  }
  return res;
}