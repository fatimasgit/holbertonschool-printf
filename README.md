# _printf Function

## Description

_printf is a custom C function designed to mimic the behavior of the standard C library function printf. It provides a basic set of formatting options, including %s for strings, %c for characters, %i for integers, and %d for decimal integers.

## Usage

### Function Signature

int _printf(const char *format, ...);

### Parameters

- format: A string containing the format specifications.

### Return Value

- On success, the total number of characters written is returned.
- On failure, a negative value is returned.
