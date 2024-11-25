<div align="center">
<picture>
  <img alt="Get Next line project" src="https://github.com/ayogun/42-project-badges/blob/main/badges/ft_printfe.png" />
</picture>

# ft_printf

</div>

This project is a part of the [Hive Helsinki (42 School Network)](https://www.hive.fi/en/curriculum) core curriculum. There is a custom version of the `printf` function in C, called `ft_printf`. It mimics the behavior of the standard `printf` function, handling various format specifiers and flags. The goal of this project is to understand and practice working with variadic functions, type conversions, and custom formatting in C.   

### Features  
- Support for standard format specifiers: %c, %s, %d, %i, %u, %x, %X, %p, %%. 
- Edge case handling: Special cases like null pointers, large values, and negative numbers are handled appropriately.  

#### Format specifiers:  
 * `%c` Prints a single character.  
 * `%s` Prints a string (as defined by the common C convention).  
 * `%p` The void * pointer argument has to be printed in hexadecimal format.  
 * `%d` Prints a decimal (base 10) number.  
 * `%i` Prints an integer in base 10.  
 * `%u` Prints an unsigned decimal (base 10) number.  
 * `%x` Prints a number in hexadecimal (base 16) lowercase format.  
 * `%X` Prints a number in hexadecimal (base 16) uppercase format.  
 * `%%` Prints a percent sign.  

### Installation  
To use `ft_printf` function, in the project, follow these steps:  
1. **Clone the Repository.**
```sh
git clone https://github.com/ipersids/42-ft-printf.git
cd 42-ft-printf
```
2. **Build the Library.**   
Use the Makefile to compile the source files and create the static library.  
```sh
make all
```
Commands:  
- `make all` will build a static library containing the mandatory functions.  
- `make clean` will remove all .o files from the directory.  
- `make fclean` will remove all .o and executable files.  
- `make re` will trigger the fclean command and rebuild the mandatory functions.  

3. **Include the header file** in the source code.  
```c
#include "ft_printf.h"
```

4. **Link the static library.**  
Link the static library in the project's build process to use the functions as described in the header file. For example, if using gcc, you can compile and link the project with the library as follows:  
```sh
gcc -I<folder_path> -o program_name program_name.c -L<lib_path> -lftprintf
```
Flags and arguments:

- `-I<folder_path>` tells the compiler to look in the specified directory for any header files included in the source code.  
- `-o program_name` is the name of the output file.  
- `program_name.c` is the name of the source file to be compiled.  
- `-L<lib_path>` tells the linker to look in the specified directory for any libraries specified with the -l option.  
- `-lftprintf` tells the linker to link the program with the liblftprintf.a library (the lib prefix and the .a extension are automatically added by the linker).  

______________
Developed by **Julia Persidskaia**.    
[LinkedIn](https://www.linkedin.com/in/iuliia-persidskaia/)  
