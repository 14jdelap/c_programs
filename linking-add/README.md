# `add` linking exercise

This is a toy program to understand how linking work.

## Compilation process

There are 4 compilation steps:

1. Preprocessing
2. Compilation
3. Assembly
4. Linking

### Preprocessing

Preprocessing inputs a `.c` file, extends its directives and macros, and outputs a `.i` file.

```
gcc -E main.c -o main.i -I./add
```

`-I./add` tells `gcc` to find the header file in `/add`. This would otherwise fails because the preprocessor will not be able to resolve the `#include <add.h>` directive.

### Compilation

Compilation inputs intermediary `.i` files and compiles them to machine-specific assembly in `.s` files.

```
gcc -S main.i -o main.s
```

### Assembly

Assembly inputs assembly `.s` files and outputs `.o` relocatable object files.

```
gcc -c main.s -o main.o
```

### Linking

There are 2 methods to link multiple object files into a single executable object file:

1. Static linking
2. Dynamic linking

||Static linking|Dynamic linking|
|-|-|-|
|Links at|Compilation|Load time or run time|
|Portability|Executable is self-contained|Errors if shared libraries aren't found|
|Memory|Larger as code from libraries is copied at compile-time into every executable|Smaller as library code is loaded into memory once and shared across all proceses|
|Compilation|Executable needs to be recompiled when library changes|Only shared libraries need to be recompiled, not executables|

Since the header file defined the symbols in the C library `add` but didn't have its source code, we can both statically and dynamically link these files.

#### Static linking

We need to create a relocatable object file for the `add` library and statically link it to `main.o`.

```
gcc -c add/add.c -o add/add.o
gcc main.o add.o -o a.out
```

We can then directly load `a.out` into memory and execute it.

```
./a.out
4
```

Note that if we change `add.c` the executable will print the same value (because the source code for `add` is in `a.out`) until we recompile it.

#### Dynamic linking

You need to first create a shared object file before dynamically linking it to `main.o`.

```
gcc -shared -o add/libadd.so add/add.o
gcc main.o -o a.out -L./add -ladd
```

Note that if you change the source code in `add.c` and create a new shared object:

```
gcc -c add/add.c -o add.o
gcc -shared -o add/libadd.so add.o
```

The behavior of the functions from `add.c` referenced in `a.out` will change without having to recompile `a.out`.
