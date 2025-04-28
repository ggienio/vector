# Vector Library

## Overview

The Vector library is a lightweight and efficient implementation of dynamic arrays in C. It provides a flexible way to manage collections of data with automatic resizing, making it easier to work with arrays without worrying about manual memory management.

## Features

- Dynamic resizing of arrays
- Support for various data types
- Easy-to-use API for adding, removing, and accessing elements
- Memory management handled internally

## Installation

To use the Vector library in your project, simply include the source files in your build system. For example:

1. Copy the `vector.c` and `vector.h` files into your project directory.
2. Include the header file in your code:
    ```c
    #include "vector.h"
    ```

## Usage

An example of how to use the Vector library can be found in `test.c`. To compile it, simply run:
```bash
make
```
To change the type stored in the vectors (to e.g. char), type:
```c
#define VECTOR_TYPE char
```
before including the header file.

To change the step by which to expand the vector when it runs out of memory, type:
```c
#define REALLOC_STEP 16
```
before including the header file.