# The Perspectiva Documentation
## Basic Input/Output

This header contains the following public elements whose function will be explained further in this file:

- `namespace pers`[^1]
    - `class BIO`
        - `BIO (std::istream&, std::ostream&, std::ostream& errs, const char* o_separator)`
        - `void set_input_stream (std::istream&)`
        - `void set_output_stream (std::ostream&)`
        - `set_error_stream (std::ostream&)`
        - `void set_o_sep (const char*)`
        - `const char* get_o_sep (void)`
        - `template <class ... T> void out (const T& ...)`
        - `template <class ... T> void pout (const T& ...)`
        - `template <class ... T> void outln (const T& ...)`
        - `template <class ... t> void err (const t& ...)`
        - `template <class ... t> void perr (const t& ...)`
        - `template <class ... T> void errln (const T& ...)`
        - `template <class ... T> void in (T& ...)`
    - `BIO bio`

[^1] This page does not explain [`namespace pers`](./namespacePers.md).

### `class BIO`

The `class BIO` is automatically initialized by the `BIO ()` constructor with `(std::cin, std::cout, std::cerr, "\t")` as the default parameters.
The 'default-initialized' instance of it is `BIO bio`, whose methods are used in most of the library's headers.

#### `set_input_stream`, `set_output_stream` & `set_error_stream`

Each stream setter of the `class BIO` assigns an `istream&` or an `ostream&` to the class' parameters that should be used (encapsulated) like `std::cin`, `std::cout` & `std::cerr`, respectively.

#### `set_o_sep`

The `void set_o_sep (const char*)` method sets the separator for the non-pure output functions, i.e. `out`, `outln`, `err` & `errln`.

...
[WIP]
