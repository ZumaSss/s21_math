#include "../s21_math.h"

long double s21_ceil(double x) {
  if (x == x) {
    unsigned long input;
    memcpy(&input, &x, 8);
    long exp = ((input >> 52) & 2047) - 1023;
    if (exp > 0) {
      unsigned long fract_bits = 52 - exp;
      if (fract_bits > 0) {
        unsigned long mask = (unsigned long)~0 << fract_bits;
        unsigned long output = input & mask;
        memcpy(&x, &output, 8);
        if (x > 0 && output != input) ++x;
      }
    } else {
      if (x < 0) x = 0;
      if (x > 0) x = 1;
    }
  }
  return x;
}
