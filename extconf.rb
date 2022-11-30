# This requirement has the underlying machinery to generate a Makefile.
require 'mkmf'

# Whatever the name of your .c file is goes here. Since we're using `heron.c`, we include `heron`.
create_makefile("heron")
