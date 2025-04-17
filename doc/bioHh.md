# The Perspectiva Documentation
## Basic Input/Output (`bio.h++`)

This header contains the following public elements whose function will be explained further in this file:

- `namespace pers`[^1]
    - `class BIO`
        - `BIO (std::istream&, std::ostream&, std::ostream& errs, const char* o_separator)`
        - `void set_input_stream (std::istream&)`
        - `void set_output_stream (std::ostream&)`
        - `set_error_stream (std::ostream&)`
        - `void set_o_sep (const char*)`
        - `const char* get_o_sep (void)`
        - `void set_o_l_sep (const char*)`
        - `const char* get_o_l_sep (void)`
        - `template <class ... Ts> void out (const Ts& ...)`
        - `template <class ... Ts> void pout (const Ts& ...)`
        - `template <class ... Ts> void outln (const Ts& ...)`
        - `void flush_out (void)`
        - `template <class ... Ts> void err (const Ts& ...)`
        - `template <class ... Ts> void perr (const Ts& ...)`
        - `template <class ... Ts> void errln (const Ts& ...)`
        - `void flush_err (void)`
        - `template <class ... Ts> void in (Ts& ...)`
    - `BIO bio`

[^1]: This page does not explain [`namespace pers`](./namespacePers.md).

### `class BIO`

The `class BIO` is Tsmatically initialized by the `BIO ()` constructor with `(std::cin, std::cout, std::cerr, "\t")` as the default parameters.
The 'default-initialized' instance of it is `BIO bio`, whose methods are used in most of the library's headers.

#### `set_input_stream`, `set_output_stream` & `set_error_stream`

Each stream setter of the `class BIO` assigns an `istream&` or an `ostream&` to the class' parameters that should be used (encapsulated) like `std::cin`, `std::cout` & `std::cerr`, respectively.

#### `set_o_sep`, `set_o_l_sep`, `get_o_sep` & `get_o_l_sep`

The `void set_o_sep (const char*)` method sets the separator string for the non-pure output functions, i.e. `out`, `outln`, `err` & `errln`.

The `void set_o_l_sep (const char*)` method sets the line separator string for the same functions.

#### `out`, `err`, `outln`, `errln`, `pout` & `perr`

The `template <class ... Ts> void out (const Ts& ...)` and `template <class ... Ts> void err (const Ts& ...)` method templates output each of their arguments ordely to the output and error streams, respectively, with the output separator following each.

The `template <class ... Ts> void outln (const Ts& ...)` and `template <class ... Ts> void errln (const Ts& ...)` method templates have the same functionality, but they add the line separator at the end.

The `template <class ... Ts> void pout (const Ts& ...)` and `template <class ... Ts> void perr (const Ts& ...)` method templates also output each of their arguments to their respective streams, but there are no separators or modifications to the given arguments that will be outputted.

#### `flush_out` & `flush_err`

The `void flush_out (void)` and `void flush_err (void)` methods simply execute the `flush` method of the output and error streams, respectively.

#### `in`

The `template <class ... Ts> void in (Ts& ...)` method template takes a reference of each of its arguments and ordely reads each of their values from the input stream.
If the input fails, the method causes an assertion failure with `void assert (int)` (q. v. <cassert> header).
