#include "ruby.h"
#include <math.h>

int verify_triangle(double a, double b, double c) {
  int pos_values = (a > 0 && b > 0 && c > 0);
  int proper_construction = (a + b > c && a + c > b && b + c > a);
  return (pos_values && proper_construction);
}

float heron(double a, double b, double c) {
  double s = (a + b + c)/2.0;
  double area = sqrt(s * (s - a) * (s - b) * (s - c));
  return area;
}

VALUE _verify_triangle(VALUE obj, VALUE _a, VALUE _b, VALUE _c) {
  double a = NUM2DBL(_a), b = NUM2DBL(_b), c = NUM2DBL(_c);
  if (verify_triangle(a, b, c) == 0) {
    return Qfalse;
  } else {
    return Qtrue;
  }
}

VALUE _heron(VALUE obj, VALUE _a, VALUE _b, VALUE _c) {
  double a = NUM2DBL(_a), b = NUM2DBL(_b), c = NUM2DBL(_c);
  double area = heron(a, b, c);
  return DBL2NUM(area);
}

void Init_heron() {
  rb_define_global_function("heron", _heron, 3);
  rb_define_global_function("verify_triangle", _verify_triangle, 3);
}
