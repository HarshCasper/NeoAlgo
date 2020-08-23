## Introduction
A programming language must be simple, easy to learn and use, have good readability and human recognizable, should be well structured and documented so that it is suitable for application development.
Programming language must be consistent in terms of syntax and semantics.

The goal of these standards is to increase portability, reduce maintenance, and above all improve clarity.Many of the style choices here are somewhat arbitrary.

Mixed coding style is harder to maintain than bad coding style. When changing existing code it is better to conform to the style (indentation, spacing, commenting, naming conventions) of the existing code than it is to blindly follow this document.

Code with “*good style*” is defined as that which is:
- Organized
- Easy to read
- Easy to understand
- Maintainable
- Efficient

*"Good programming style begins with the
effective organization of code. By using a
clear and consistent organization of the
components of your programs, you make
them more efficient, readable, and
maintainable."*
– Steve Oualline, C Elements of Style

## File Organisation

A file consists of various sections that should be separated by several blank lines. Although there is no maximum length limit for source files,
files with more than about 1000 lines are cumbersome to deal with. The editor may not have enough temp space to edit the file, compilations will
go more slowly, etc. Many rows of asterisks, for example, present little information compared to the time it takes to scroll past, and are 
discouraged. Lines longer than 79 columns are not handled well by all terminals and should be avoided if possible. Excessively long lines
which result from deep indenting are often a symptom of poorly-organized code.

## File Naming Convention
File names are made up of a base name, and an optional period and suffix. The first character of the name should be a letter and all 
characters (except the period) should be lower-case letters and numbers. The base name should be eight or fewer characters and the suffix 
should be three or fewer characters (four, if you include the period). These rules apply to both program files and default files used and 
produced by the program 
e.g., "triple.sav"

Some compilers and tools require certain suffix conventions for names of files. The following suffixes are required:

* C source file names must end in .c

* Assembler source file names must end in .s

* The following conventions are universally followed:

    * Relocatable object file names end in .o

    * Include header file names end in .h. An alternate convention that may be preferable in multi-language environments is to suffix both the language type and .h (e.g. foo.c.h; or foo.ch).

    * Yacc source file names end in .y

    * Lex source file names end in .l

* C++ has compiler-dependent suffix conventions, including .c, ..c, .cc, .c.c, and .C. Since much C code is also C++ code, there is no clear solution here.

In addition, it is conventional to use Makefile (not makefile) for the control file for make (for systems that support it) and "README" for a summary of the contents of the directory or directory tree.

## White Spaces

Write code that is as easy as possible to read and maintain (taking into consideration
performance tradeoffs for real-time systems when it is appropriate). Adding white
space in the form of blank lines, spaces, and indentation will significantly improve the
readability of your code

- **Blank Lines**

 A careful use of blank lines between code “paragraphs” can greatly enhance
 readability by making the logical structure of a sequence of lines more obvious. Using
 blank lines to create paragraphs in your code or comments can make your programs
 more understandable. The following example illustrates how the use of blank lines
 helps break up lines of text into meaningful chunks.
 ```
  Example: code paragraphing
       #define LOWER 0
       #define UPPER 300
       #define STEP 20
       main() /* Fahrenheit-Celsius table */
       {
           int fahr;
           for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
           printf(“%4d %6.1f\n”, fahr, (5.0/9.0)*(fahr - 32));
       }
```
However, overuse of blank lines can defeat the purpose of grouping and can actually
reduce readability. Therefore, use a single blank line to separate parts of your
program from one another.

- **Spacing**

  Appropriate spacing enhances the readability of lexical elements such as variables and
  operators. The following examples illustrate how to use individual spaces to improve
  readability and to avoid errors. The second example is not only harder to read, but the
  spacing introduces an error, where the operator /* will be interpreted by the compiler
  as the beginning of a comment. Put one space after a comma to improve readability,
  as shown in the third example below.
 ```
 Example: good spacing
          *average = *total / *count; /* compute the average */
 Example: poor spacing
          *average=*total/*count; /* compute the average */
                ^ begin comment end comment^
 Example: comma spacing
          concat(s1, s2)
 ```
- **Identation**

  Use indentation to show the logical structure of your code. Research has shown that
  **four spaces** is the optimum indent for readability and maintainability. However, in
  highly nested code with long variable names, four-space indentation may cause the
  lines of code to overrun the end of the line. Use four spaces unless other
  circumstances make it unworkable.
  ```
   Example: four-space indentation
   main()
   {
       int c;
       c = getchar();
       while (c!= EOF)
       {
           putchar(c);
           c = getchar();
       }
   }
  ```
## Comments

Judiciously placed comments in the code can provide information that a person could
not discern simply by reading the code. Comments can be added at many different
levels
Comments can be written in several styles depending on their purpose and length.
Use comments to add information for the reader or to highlight sections of code.
Do not paraphrase the code or repeat information contained in the Program Design
Language (PDL).
- All code must have some comments (there is no such thing as self-documenting code).
- Describe the intent of a block of code.
- A description should appear at the top of each function.
- Describe the use of a variable where it is declared, if not obvious.

This section describes the use of comments and provides examples.

• **Boxed comments**—Use for prologs or as section separators
```
Example: boxed comment prolog
/*****************************************************
 * FILE NAME *
 * *
 * PURPOSE *
 * *
 *****************************************************/
```
• **Block comments**—Use at the beginning of each major section of the code as a
narrative description of that portion of the code.
```
Example: block comment
/*
 * Write the comment text here, in complete sentences.
 * Use block comments when there is more than one
 * sentence.
 */
```
• **Short comments**—Write on the same line as the code or data definition they
describe.
```
Example: short comments
double ieee_r[]; /* array of IEEE real*8 values */
unsigned char ibm_r[]; /* string of IBM real*8 values */
int count; /* number of real*8 values */
```
• **Inline comments**—Write at the same level of indentation as the code they
describe
```
Example: inline comment
switch (ref_type)
{
/* Perform case for either s/c position or velocity
 * vector request using the RSL routine c_calpvs */
case 1:
case 2:
...
case n:
}
```

In general, use short comments to document variable definitions and block comments
to describe computation processes.
```
Example: block comment vs. short comment
       preferred style:
           /*
            * Main sequence: get and process all user requests
            */
           while (!finish())
           {
           inquire();
           process();
           }
       not recommended:
           while (!finish()) /* Main sequence:      */
           {                 /*                     */
           inquire();        /* Get user request    */
           process();        /* And carry it out    */
           }                 /* As long as possible */
```
## Naming Conventions

Choose names for files, functions, constants, or variables that are meaningful and
readable. The following guidelines are recommended for creating element names.

- Choose names with meanings that are precise and use them consistently
  throughout the program.
- Follow a uniform scheme when abbreviating names.
- Avoid abbreviations that form letter combinations that may suggest
  unintended meanings.
- Use underscores within names to improve readability and clarity:
  get_best_fit_model
  load_best_estimate_model
- Assign names that are unique (with respect to the number of unique characters
  permitted on your system).
- Use longer names to improve readability and clarity. However, if names are
  too long, the program may be more difficult to understand and it may be
  difficult to express the structure of the program using proper indentation.
- Names more than four characters in length should differ by at least two
  characters. For example, “systst” and “sysstst” are easily confused. Add
  underscores to distinguish between similar names:
  systst sys_tst
  sysstst sys_s_tst
- Do not rely on letter case to make a name unique. Do not define two variables with
  the same spelling, but different case.
- Do not assign a variable and a typedef (or struct) with the same name, even
  though C allows this. This type of redundancy can make the program difficult
  to follow.

### Standard Names

Some standard short names for code elements are listed in the example below. While
use of these names is acceptable if their meaning is clear, we recommend using longer,
more explicit names, such as “buffer_index.”

```
    Example: standard short names
            c           characters
            i, j, k     indices
            n           counters
            p, q        pointers
            s           strings
    Example: standard suffixes for variables
            _ptr        pointer
            _file       variable of type file*
            _fd         file descriptor
```
### Variable Names

In separate functions, variables that share the same name can be declared. However,
the identical name should be used only when the variables also have the identical
meaning. When the meanings of two variables are only similar or coincidental, use
unique names to avoid confusion.

### Capitalization

The following capitalization style is recommended because it gives the programmer as
well as the reader of the code more information.

- **Variables**: Use lower-case words separated by underscores.
- **Function names**: Capitalize the first letter of each word; do not use
  underscores.
- **Constants**: Use upper-case words separated by underscores.
- **C bindings**: Use the letter “c” followed by an underscore and the binding
  name.
  ```
  Example: capitalization style
           open_database   variables
           ProcessError    function names
           MAX_COUNT       constants
           c_ephemrd       C bindings
  ```
## Functions

- **You must avoid code duplication by calling appropriate functions (rather than cutting and pasting code).
- Input parameters must appear before out parameters.**
- Annotate helper functions with static.
- Annotate unmodified parameters with const.
- And annotate functions intended to be used from outside with extern.
- Functions should represent a reasonable unit of complexity or be reused frequently.
- If the parameter list extends beyond 80 characters, arrange parameters line by line. Here is an example:
  ```
  void process(int my_first_value, int temperature, float pressure, int altitude, char color)
                {
                   /* Code here */
                }
  ```
## C Style Guidelines
**(Summary of above all as well as some other genral points)**

1. Meaningful names for variables, constants and functions. Do not use camelcase;
1. Good indentation (3 or 4 spaces). Use a proper editor (e.g., emacs, vi) that assists with indentation.
1. Use braces; avoid loops and conditionals without them.
1. #defined constants must be in uppercase (e.g., #define MAX_LEN 10 and NOT #define max_len 10).
1. Leave one blank line between variable declarations and the first line of code in a function
1. If the code is too complicated to be read on its own, simplify/split/rename variables.
1. Avoid global variables where they are unnecessary.
1. If p is a pointer to a structure, you should access members by using p->member rather than (*p).member
1. You must avoid code duplication.
1. Make sure you read all the information on this page. You will lose credit if you don't follow the suggestions we have defined.
1. The main() function is either first or last.
1. #includes and #defines in the middle of code are usually frowned upon.
1. Make sure you read all the information on this page. You will lose credit if you don't follow the suggestions we have defined.

## Examples
```
1. if ( age == 1 ) use instead if (age == 1)  /* no spaces after ( and before ) 
```
```
2. Don't put description for a function inside of a function; place it on top:
   Instead of:
   int main() {
      /* this function process */
      /* this data */
      int x;
   }
   Do this:
   /*************************/
   /* this function process */
   /* this data             */
   /*************************/
   int main() {
      int x;
   }
```
```
3. Make sure that comments you provide look symmetrical: 
   Instead of:
   /* this is */
   /* part of the code for this function */
   int task() {
      ...
   }
   Do this:
   /* this is part of the    */
   /* code for this function */
   int task() {
      ...
   }
```
```
4. Leave a blank space after a comma
   Instead of:
   scanf("%d",&x);
   Do this:
   scanf("%d", &x);
   
```
```
5. Regarding if:
    /* Preferred */
    if (x > 0) {   /* Space before { and after f */
       y = 100;
    } else {   /* Space before and after else; else follows { (not on the next line) */
       y = 200;
    }
```

*Full style example*

```
#include <stdio.h>
int main() {
   int temperature = 0, height;
   char gender;
   
   printf("Enter Gender (m/f): ");
   scanf("%c", &gender);
   printf("Enter temperature: ");
   scanf("%d", &temperature);
   printf("Enter height (inches): ");
   scanf("%d", &height);
   if (gender == 'f') {
      printf("Female\n");
   } else {
      printf("Male\n");
   }
   do {
      if (temperature % 2 == 0) {
         printf("Even temperature %d\n", temperature);
      }
      temperature--;
   } while (temperature >= 0);
   /* This is a cascaded if statement example */
   if (height > 0 && height <= 15) {
      printf("Type1\n");
   } else if (height > 15 && height <= 30) {
      printf("type2\n");
   } else {
      printf("Other type\n");
   }
   return 0;
}
```
## Reference

- ["C Programming Style" Paul Krzyzanowski](http://www.pk.org/rutgers/notes/pdf/Cstyle.pdf)
- [coding standards](http://users.ece.cmu.edu/~eno/coding/CCodingStandard.html)
- [SEL](https://pdfs.semanticscholar.org/4c0f/60983b227236f3a56332079f0f80086f7d00.pdf)
- [cs.umd.edu/cstyleguide](http://www.cs.umd.edu/~nelson/classes/resources/cstyleguide/)
