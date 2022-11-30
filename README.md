# cruby_heron

Just a little practice with the Ruby C API. This repo contains a C-extension for Ruby which contains two methods:
- verifies that a triangle is legitimate (verify_triangle)
- computes the area of a triangle using Heron's formula (heron)

## Compilation

This was compiled using GCC on x86_64 Mac OS X with Ruby 3.0.2 (tested with 2.6+).

1. Pull down the code from the repository.
2. Run `ruby extconf.rb` and it will create a Makefile.
3. Run `make` to generate the `heron.bundle` and `heron.o` libs.

## Testing in IRB

1. Run `irb`
2. Once in IRB, run `require_relative "./heron.bundle"` and you should see `true` as output.

## `verify_triangle`

To verify a triangle is legitimate, run `verify_triangle(a, b, c)` where a, b, and c are numeric values. Floats are accepted and ints are auto-converted.

## `heron`

To compute the area of a triangle, run `heron(a, b, c)` where a, b, and c are numeric values. Once again, floats are accepted and ints are auto-converted.
