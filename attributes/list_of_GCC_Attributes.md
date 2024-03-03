# GCC Compiler Attributes:  
The GNU Compiler Collection (GCC) supports numerous attributes that allow programmers to specify special properties for variables, functions, and types. These attributes can be used to optimize performance, check the correctness of code, or inform the compiler about certain aspects of the code that are not evident from the syntax alone.   

Here's a list of some commonly used GCC attributes:   

**aligned:** Specifies the minimum alignment (in bytes) for a variable or structure field.   

**packed:** Packs structure fields together without padding, potentially reducing the size of the structure.    

**deprecated:** Marks a function, variable, or type as deprecated, generating a warning if it is used.   

**noreturn:** Specifies that a function does not return. The compiler can use this information for optimizations.    

**pure:** Indicates that a function has no effects except its return value and its return value depends only on the parameters and/or global variables.   

**const:** Similar to pure, but also implies that the function does not access any global memory.    
  
**unused:** Indicates that a function, variable, or type may be unused, suppressing unused warnings.    

**weak:** Marks a symbol as a weak symbol, meaning it can be overridden by other symbols.    

**constructor:** Specifies a function to be called automatically before execution enters main().    

**destructor:** Specifies a function to be called automatically after main() completes or exit() is called.    

**visibility:** Sets the visibility of ELF symbols, which can be default, hidden, protected, or internal.    

**nonnull:** Specifies pointers (by their parameters number) that must not be NULL.    

**returns_nonnull:** Indicates that a function’s return value will never be NULL.    

**section:** Places the function or variable in a specific section of the output file.    

**format:** Specifies that a function takes printf, scanf, strftime, or strfmon style arguments which should be type-checked.

**hot:** Indicates that a function, loop, or variable is a hot spot of the program.

**cold:** Indicates that a function, loop, or variable is unlikely to be executed.

**optimize:** Allows setting optimization options for a specific function.

**nonnull:** Indicates that some function parameters should be non-null pointers.

**sentinel:** Used for functions that accept a variable number of arguments, ensuring the argument list is terminated with a null pointer.

**warn_unused_result:** Causes a warning to be emitted if a caller of the function does not use its return value.

**malloc:** Tells the compiler that a function is malloc-like, meaning that it returns a pointer to memory that is not aliasing any other pointer and that it returns NULL if and only if it fails.

This is not an exhaustive list as GCC continues to evolve and new attributes are added. Moreover, some attributes may be specific to certain target architectures or GCC versions. For the most up-to-date and comprehensive list, you should refer to the official GCC documentation relevant to the specific version of the compiler you are using.

Here's how you can use some of the commonly used GCC attributes in C code. Note that not all attributes will be demonstrated due to the extensive nature of the list, but this should give you a good starting point:
```
#include <stdio.h>
#include <stdlib.h>

// 'aligned' attribute
struct __attribute__((aligned(16))) my_struct {
    int x;
};

// 'packed' attribute
struct __attribute__((packed)) packed_struct {
    char a;
    int b;
};

// 'deprecated' attribute
int old_function() __attribute__((deprecated));

int old_function() {
    return 0;
}

// 'noreturn' attribute
void die() __attribute__((noreturn));

void die() {
    exit(1); // Terminate program
}

// 'pure' attribute
int __attribute__((pure)) add(int a, int b) {
    return a + b;
}

// 'const' attribute
int __attribute__((const)) multiply(int a, int b) {
    return a * b;
}

// 'unused' attribute
void test_function() __attribute__((unused));

void test_function() {
    printf("This is an unused function.\n");
}

// 'weak' attribute
int weak_var __attribute__((weak)) = 0;

// 'constructor' and 'destructor' attributes
void __attribute__((constructor)) init_function() {
    printf("Initialization function called.\n");
}

void __attribute__((destructor)) cleanup_function() {
    printf("Cleanup function called.\n");
}

// 'visibility' attribute
int __attribute__((visibility("default"))) visible_function() {
    return 0;
}

// 'nonnull' attribute
void print_numbers(int *a, int *b) __attribute__((nonnull(1,2)));

void print_numbers(int *a, int *b) {
    printf("%d, %d\n", *a, *b);
}

// 'returns_nonnull' attribute
int *create_array() __attribute__((returns_nonnull));

int *create_array() {
    return malloc(10 * sizeof(int)); // Assume malloc never fails for simplicity
}

// 'section' attribute
int __attribute__((section(".my_section"))) special_var = 0;

// 'format' attribute
void my_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));

void my_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

// 'hot' attribute
void __attribute__((hot)) frequently_used_function() {
    // Function implementation
}

// 'cold' attribute
void __attribute__((cold)) rarely_used_function() {
    // Function implementation
}

// 'optimize' attribute
void __attribute__((optimize("O3"))) optimized_function() {
    // Function implementation
}

// 'sentinel' attribute
void print_strings(char *first, ...) __attribute__((sentinel));

void print_strings(char *first, ...) {
    va_list args;
    char *str;

    va_start(args, first);
    str = first;
    while (str) {
        printf("%s ", str);
        str = va_arg(args, char*);
    }
    va_end(args);
    printf("\n");
}

// 'warn_unused_result' attribute
int __attribute__((warn_unused_result)) important_function() {
    return 42; // Important value
}

// 'malloc' attribute
void *__attribute__((malloc)) my_malloc(size_t size);

void *my_malloc(size_t size) {
    return malloc(size);
}

int main() {
    // Usage examples
    int result = old_function(); // Will trigger a deprecated warning
    die(); // Will not return
    int sum = add(5, 10);
    int product = multiply(5, 10);
    int important_value = important_function();
    (void)important_value; // Suppress unused result warning

    return 0;
}

```

