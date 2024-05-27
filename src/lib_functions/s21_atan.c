#include "../s21_math.h"

long double s21_atan(double x) {
  long double res = 0;
  if (s21_is_nan(x) || x == POS_INF)
    res = s21_NAN;
  else {
    int sign = 0, size = 0;
    long double x2 = 0;
    if (x < 0.F) {
      x = -x;
      sign |= 1;
    }
    if (x > s21_pow(10, 7)) {
      x = s21_pow(10, 7);
    }
    if (x > 1.F) {
      x = 1.F / x;
      sign |= 2;
    }
    while (x > PI / 12.F) {
      size++;
      res = 1.F / (x + S21_SQRT_3);
      x = ((x * S21_SQRT_3) - 1) * res;
    }
    x2 = s21_pow(x, 2);
    res = x * (0.55913709 / (1.4087812 + x2) + 0.60310579 - 0.05160454 * x2);
    while (size > 0) {
      res += PI / 6.F;
      size--;
    }
    (sign & 2) ? res = PI / 2.F - res : res;
    (sign & 1) ? res = -res : res;
  }

  return res;
}
