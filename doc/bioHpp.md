# The Perspectiva Documentation
## Basic Input/Output

This header contains the following public elements whose function will be explained further in this file:

- `namespace pers`
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

### `class BIO`
