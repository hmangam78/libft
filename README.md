# libft
A C library implementing commonly-used functions from the C standard library plus a handful of extra utilities used in 42-school projects.

This repository contains reimplementations and helper functions typically used throughout C projects: character tests, string and memory manipulation, dynamic allocation helpers, conversions, formatted printing (`ft_printf`), a buffered line reader (`get_next_line`), linked list helpers, and a few utility functions.

## Build

A `Makefile` is included. Typical workflow:

```bash
make
# produces libft.a or builds object files depending on the Makefile rules
```

## How this README is organized

- Short description of the library
- Build instructions and usage notes
- A per-function reference (signature + description, parameters, return value, notes)

## Function reference

Notes:
- All function names are prefixed with `ft_`.
- Signatures below match the prototypes in `libft.h`.

### Character and classification

- int ft_isalpha(int c)
  - Returns non-zero if `c` is an alphabetic character (A–Z or a–z), 0 otherwise.

- int ft_isdigit(int c)
  - Returns non-zero if `c` is a decimal digit (0–9), 0 otherwise.

- int ft_isalnum(int c)
  - Returns non-zero if `c` is alphanumeric (letter or digit), 0 otherwise.

- int ft_isascii(int c)
  - Returns non-zero if `c` is an ASCII character (value between 0 and 127), 0 otherwise.

- int ft_isprint(int c)
  - Returns non-zero if `c` is printable (including space), 0 otherwise.

- int ft_isspace(int c)
  - Returns non-zero if `c` is a whitespace character (space, tab, newline, etc.), 0 otherwise.

- int ft_toupper(int c)
  - Converts lowercase letter to uppercase; returns the converted character or `c` unchanged if not lowercase.

- int ft_tolower(int c)
  - Converts uppercase letter to lowercase; returns the converted character or `c` unchanged if not uppercase.

### Memory management

- void *ft_memset(void *s, int c, size_t n)
  - Fills the first `n` bytes of the memory area pointed to by `s` with the byte `c`.
  - Returns `s`.

- void ft_bzero(void *s, size_t n)
  - Sets the first `n` bytes of `s` to zero.

- void *ft_memcpy(void *dest_str, const void *src_str, size_t n)
  - Copies `n` bytes from `src_str` to `dest_str`. The memory areas must not overlap.
  - Returns `dest_str`.

- void *ft_memmove(void *dest_str, const void *src_str, size_t n)
  - Copies `n` bytes from `src_str` to `dest_str`. Handles overlapping memory areas safely.
  - Returns `dest_str`.

- void *ft_memchr(const void *buf, int c, size_t count)
  - Scans the first `count` bytes of `buf` for the byte `c`. Returns pointer to the matching byte or `NULL` if not found.

- int ft_memcmp(const void *buf1, const void *buf2, size_t count)
  - Compares the first `count` bytes of `buf1` and `buf2`. Returns an integer less than, equal to, or greater than zero if `buf1` is found, respectively, to be less than, to match, or be greater than `buf2`.

- void *ft_calloc(size_t num, size_t size)
  - Allocates memory for an array of `num` elements of `size` bytes each and initializes all bytes to zero. Returns pointer or `NULL` on allocation failure.

- char *ft_strcalloc(size_t num, size_t size)
  - Convenience wrapper allocating `num * size` bytes and returning a `char *` (zero-initialized). Returns `NULL` on failure.

### String handling

- int ft_strlen(const char *s)
  - Returns the length of the string `s` (number of characters before the terminating `\0`).

- size_t ft_strlcpy(char *dst, const char *src, size_t size)
  - Copies up to `size - 1` characters from `src` to `dst`, null-terminating the result (if `size` != 0). Returns the total length of `src`.

- size_t ft_strlcat(char *dst, const char *src, size_t size)
  - Appends `src` to string `dst` of size `size` (like `strlcat`). Returns total length of string it tried to create (initial length of `dst` + length of `src`).

- char *ft_strchr(const char *string, int c)
  - Returns pointer to first occurrence of `c` in `string`, or `NULL` if not found.

- char *ft_strrchr(const char *string, int c)
  - Returns pointer to last occurrence of `c` in `string`, or `NULL`.

- int ft_strncmp(const char *string1, const char *string2, size_t count)
  - Compares up to `count` characters of `string1` and `string2`. Returns <0, 0 or >0.

- char *ft_strdup(const char *string)
  - Allocates and returns a new string which is a duplicate of `string`. Returns `NULL` on allocation failure.

- char *ft_substr(char const *s, unsigned int start, size_t len)
  - Allocates and returns a substring from `s` starting at index `start` and of maximum length `len`.

- char *ft_strjoin(char *s1, char *s2)
  - Allocates and returns a new string which is the concatenation of `s1` and `s2`. Note: the implementation may free inputs depending on project conventions—check source if ownership matters.

- char *ft_strtrim(char const *s1, char const *set)
  - Allocates and returns a copy of `s1` with characters in `set` removed from the beginning and end.

- char **ft_split(char const *s, char c)
  - Splits string `s` by delimiter `c` into a NULL-terminated array of strings. Returns allocated array or `NULL` on failure.

- void ft_striteri(char *s, void (*f)(unsigned int, char *))
  - Iterates over `s` and applies function `f` to each character, passing the index and a pointer to the character.

- char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
  - Creates a new string by applying `f` to each character of `s` with its index; returns the new string.

- int ft_strcmp(const char *str1, const char *str2)
  - Compares `str1` and `str2` like the usual `strcmp`. Returns <0, 0 or >0.

- char *ft_strnstr(const char *big, const char *little, size_t len)
  - Locates the first occurrence of `little` in `big`, where not more than `len` characters are searched. Returns pointer or `NULL`.

### Conversions and number utilities

- int ft_atoi(const char *string)
  - Converts the initial portion of the string to an `int`. Handles optional leading whitespace and sign.

- char *ft_itoa(int n)
  - Allocates and returns a string representing the integer `n`.

- char *ft_itobin(int n)
  - Converts integer `n` to a binary string representation (implementation-specific formatting). Returns allocated string.

- int ft_bintoi(const char *string)
  - Converts a binary string (containing '0' and '1') to its integer value.

### Output / printing helpers

- void ft_putchar_fd(char c, int fd)
  - Writes character `c` to file descriptor `fd`.

- void ft_putstr_fd(char *s, int fd)
  - Writes string `s` to file descriptor `fd`.

- void ft_putendl_fd(char *s, int fd)
  - Writes string `s` followed by a newline to `fd`.

- void ft_putnbr_fd(int n, int fd)
  - Writes integer `n` to `fd` as ASCII characters.

- int ft_putchar(int c)
  - Writes a single character to the standard output (or underlying implementation). Returns number of bytes written or a status code (implementation-defined).

- int ft_putnbr(long long int nb)
  - Writes number `nb` to standard output. Returns number of characters written or status code.

- int ft_putptr(unsigned long long ptr)
  - Writes a pointer value (usually in hexadecimal) to standard output. Returns number of characters written.

- int ft_putstr(char *s)
  - Writes string `s` to standard output. Returns number of characters written.

- int ft_pr_hex(unsigned int nb, const char *base)
  - Prints `nb` in hexadecimal using the provided `base` string (e.g., "0123456789abcdef"). Returns number of characters printed.

- int ft_pr_unsigned(unsigned int nb)
  - Prints an unsigned integer to standard output. Returns number of characters printed.

- int ft_printf(char const *str, ...)
  - Formatted printing function similar to `printf`. Supports format specifiers implemented in the project. Returns number of characters printed.

- int ft_perror(int err_no, char const *str, ...)
  - Prints a formatted error message to standard error, possibly using `err_no` and `str` (wrapper around `perror`/`fprintf` semantics). Returns an `int` status (implementation-specific).

### Linked list helpers (singly linked list)

The library provides a simple singly-linked list type `t_list`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

- t_list *ft_lstnew(void *content)
  - Creates a new list node with `content` and `next` set to `NULL`.

- void ft_lstadd_front(t_list **lst, t_list *new)
  - Adds the node `new` at the beginning of the list pointed to by `lst`.

- int ft_lstsize(t_list *lst)
  - Returns the number of nodes in the list.

- t_list *ft_lstlast(t_list *lst)
  - Returns the last node of the list, or `NULL` if empty.

- void ft_lstadd_back(t_list **lst, t_list *new)
  - Adds the node `new` at the end of the list pointed to by `lst`.

- void ft_lstdelone(t_list *lst, void (*del)(void *))
  - Frees the content of `lst` using `del` and frees the node itself.

- void ft_lstclear(t_list **lst, void (*del)(void *))
  - Deletes and frees all nodes of the list using `del` for contents and sets `*lst` to `NULL`.

- void ft_lstiter(t_list *lst, void (*f)(void *))
  - Iterates the list and applies `f` to the content of each node.

- t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
  - Iterates `lst`, applies `f` to each content and creates a new list from the results. If allocation fails, uses `del` to free allocated contents.

### Get Next Line

- char *error_check(char *buf)
  - Internal helper used by `get_next_line` to check buffer/string error conditions (implementation detail).

- char *get_next_line(int fd)
  - Reads from `fd` and returns the next line read (including the terminating `\n` if one was encountered). Returns `NULL` on EOF or error. Uses `BUFFER_SIZE` defined in the header; default is 5.

## Notes and implementation details

- Check the corresponding `.c` files for exact behavior (ownership of returned strings, whether functions free inputs, exact return conventions for `ft_printf` and printing helpers).
- `BUFFER_SIZE` is defined in `libft.h` and can be overridden during compilation.

## Testing and usage ideas

- Compile the library with the provided `Makefile` and link `libft.a` into small test programs.
- Create unit tests for edge cases: `NULL` pointers where allowed, very long strings, large `BUFFER_SIZE` for `get_next_line`, negative numbers for conversion functions.

## Author

- Author: Hector Gamiz (hgamiz-g).

## Files

The repository includes the following notable source files (each implements the function of the same name):

- ft_atoi.c, ft_bintoi.c, ft_bzero.c, ft_calloc.c, ft_isalnum.c, ft_isalpha.c, ft_isascii.c, ft_isdigit.c, ft_isprint.c, ft_isspace.c, ft_itoa.c, ft_itobin.c, ft_lstadd_back.c, ft_lstadd_front.c, ft_lstclear.c, ft_lstdelone.c, ft_lstiter.c, ft_lstlast.c, ft_lstmap.c, ft_lstnew.c, ft_lstsize.c, ft_memchr.c, ft_memcmp.c, ft_memcpy.c, ft_memmove.c, ft_memset.c, ft_perror.c, ft_pr_hex.c, ft_pr_unsigned.c, ft_printf.c, ft_putchar_fd.c, ft_putchar.c, ft_putendl_fd.c, ft_putnbr_fd.c, ft_putnbr.c, ft_putptr.c, ft_putstr_fd.c, ft_putstr.c, ft_split.c, ft_strcalloc.c, ft_strchr.c, ft_strcmp.c, ft_strdup.c, ft_striteri.c, ft_strjoin.c, ft_strlcat.c, ft_strlcpy.c, ft_strlen.c, ft_strmapi.c, ft_strncmp.c, ft_strnstr.c, ft_strrchr.c, ft_strtrim.c, ft_substr.c, ft_tolower.c, ft_toupper.c, get_next_line_utils.c, get_next_line.c

(Refer to the `.c` files for precise behavior and examples.)
