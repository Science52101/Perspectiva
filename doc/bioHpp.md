# The Perspectiva Documentation
## Basic Input/Output

This header contains the following public elements:

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
        - `template <class ... T> void outln (const T& ... x)`
...
[WIP]
