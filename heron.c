#include "ruby.h"
#include <math.h>

/** verify_triangle
 *
 *  C-implementation to verify the validity of a triangle
 *  given three sides.
 */
int verify_triangle(double a, double b, double c) {
  int pos_values = (a > 0 && b > 0 && c > 0);
  int proper_construction = (a + b > c && a + c > b && b + c > a);
  return (pos_values && proper_construction);
}

/** heron
 *
 *  C-implementation of Heron's Formula to compute the area
 *  of a triangle.
 */
float heron(double a, double b, double c) {
  double s = (a + b + c)/2.0;
  double area = sqrt(s * (s - a) * (s - b) * (s - c));
  return area;
}

/** _verify_triangle
 *
 *  Method which Ruby will call. Converts Ruby numeric parameters
 *  into C Double types, executes `verify_triangle` and returns a
 *  Qfalse or Qtrue object.
 */
VALUE _verify_triangle(VALUE obj, VALUE _a, VALUE _b, VALUE _c) {
  // Use NUM2DBL macro to convert numeric Ruby objects into C-doubles.
  double a = NUM2DBL(_a), b = NUM2DBL(_b), c = NUM2DBL(_c);

  // Depending on the result, we return a Qfalse or Qtrue Ruby object.
  return (verify_triangle(a, b, c) == 0) ? Qfalse : Qtrue;
}

/** _heron
 *
 *  Method which Ruby will call. Converts Ruby numeric parameters
 *  into C Double types, executes `heron` and returns the area of
 *  the triangle.
 */
VALUE _heron(VALUE obj, VALUE _a, VALUE _b, VALUE _c) {
  double a = NUM2DBL(_a), b = NUM2DBL(_b), c = NUM2DBL(_c);
  double area = heron(a, b, c);
  return DBL2NUM(area);
}

/** Init_heron
 *
 * Ruby initialization method. Defines the `heron` and
 * `verify_triangle` methods using `rb_define_global_function`.
 */
void Init_heron() {
  // Use `rb_define_global_function` to define methods, specify
  // the functions that should be called, and the arity for each.
  rb_define_global_function("heron", _heron, 3);
  rb_define_global_function("verify_triangle", _verify_triangle, 3);
}
