## Introduction

Programming style is about how we organize and document our code. A program which is written following a consistent style is easier to read, debug and maintain.

A program may be written only once, but is read many times:

- During debugging
- When updating the program
- When trying to understand the code
- Anything that makes a program more readable and understandable saves lots of time.

Some of the often-used industry coding standards.

## Naming Conventions

The style of a name immediately informs us what sort of thing the named entity is: a type, a variable, a function, a constant, a macro, etc.
C++ allows for generally two types of style.

- CamelCase
- snake_case

1. Variable Names

   The names of variables and data members are all in lowercase generally, with underscores between words. (lowerCamelCase for variable names)

   ```
    int count

    int my_count
   ```

2) Constant Names

   Generally, these are all upper case and separated by underscores.

   ```
   int PI_CONST = 1
   ```

3) Function and Class Names

   Function names start with a capital letter. The first letter of each word is capitalized.

   ```
   AnyClass
   MyClass
   ```

4) All other Parameters use snake case

   ```
   with_map
   ```

## Whitespace and Indentation

- The most important thing is never mixing tabs and spaces.
- Use 2 or 4 spaces per level of indentation.
- You Should set your editor to replace tabs with spaces.
- Add space to improve readability between operators and operands, commas and semicolon.
- Add space on outside of parentheses and brackets wherever needed.

Example:

```
if(a+b=c)         //Not Good

if (a + b = c)    //Good

int main(){       //Not Good
   int a =10;
   cout<<"hello";
   if(a>0){
      cout<<"no"; }
}

int main() {       //Good
   int a = 10;
   cout << " hello " ;
   if(a>0) {
      cout<<"no";
   }
}
```

Conditionals:

```
if(y>0) {       //Not Good
else if(a>0){
}

if (y>0) {     //Good

} else if () {

}
```

## Comments

Comments help us debug and understand the code more easily.

- Add comment before each logical block
- Mostly // is used

```
// Divide result by two, taking into account that x
// contains the carry from the add.
for (int i = 0; i < result->size(); ++i) {
 x = (x << 8) + (*result)[i];
 (*result)[i] = x >> 1;
 x &= 1;
}
```

## Some General Points

- Correct use of header files can make a huge difference to the readability, size and performance of the code.
- Keep Lines of a Reasonable Length
- Don't leak memory i.e Every heap allocation using new should have a corresponding delete.
- Prefer using nullptr to NULL.
- Never Use using namespace in a Header File. (This causes the namespace you are using to be pulled into the namespace of the header file.)
- Use .hpp and .cpp for Your File Extensions
- Never Mix Tabs and Spaces
- Using const wherever possible. (All member functions that do not modify their object should be const.)
- Don't Name Anything Starting With \_
- Avoid Macros
- Declare a variable as locally as possible.

Example:

```
void Fun( vector<int>& v){
 //...
const size_t len = v.size();  //Immutable values are easier to understand and track.
}
```

## For More Detail Guideline

- [The standard Library c++](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-stdlib)
- [101 Rules for C++ Best Practices](http://library.bagrintsev.me/CPP/Sutter.C%2B%2B%20Coding%20Standards.2005.pdf)
