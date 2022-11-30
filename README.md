# cruby_heron

Heron's Formula C-extension using the Ruby C API. This repo contains a C-extension for Ruby which contains two methods:
- verifies that a triangle is legitimate (verify_triangle)
- computes the area of a triangle using Heron's formula (heron)

Naturally all work on this was done using my personal Emacs distribution, [Aether Emacs](https://github.com/drippdropp/aether-dot-emacs).

## Compilation

This was compiled using GCC on x86_64 Mac OS X with Ruby 3.0.2 (tested with 2.6+).

1. Pull down the code from the repository.
2. Run `ruby extconf.rb` and it will create a Makefile.
3. Run `make` to generate the `heron.bundle` and `heron.o` libs. Depending on your architecture, it may generate a
   `heron.so` file.

## Testing in IRB

1. Run `irb`
2. Once in IRB, run `require_relative "./heron.bundle"` and you should see `true` as output.

### `verify_triangle`

To verify a triangle is legitimate, run `verify_triangle(a, b, c)` where a, b, and c are numeric values. Floats are
accepted and ints are auto-converted.

``` ruby
irb(main):001:0> require_relative "./heron.bundle"
=> true
irb(main):002:0> verify_triangle(10, 30, 30)
=> true
```

### `heron`

To compute the area of a triangle, run `heron(a, b, c)` where a, b, and c are numeric values. Once again, floats are accepted and ints are auto-converted.

``` ruby
irb(main):001:0> require_relative "./heron.bundle"
=> true
irb(main):002:0> heron(10, 30, 30)
=> 147.90199279785156
```

## Additional Resources

[The Definitive Guide to Ruby's C API](https://silverhammermba.github.io/emberb/c/) is a great resource for Ruby's C API with lots of information and examples.

[C Ruby Extension Playlist](https://www.youtube.com/playlist?list=PLDvo9XtZiAZdVq5KfLwMphVMd8QB7nysF) is a great collection of videos on YouTube by Sourav Goswami which runs through how to work with various types as well as some examples.

