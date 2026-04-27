## Specific Instructions for C++

*   Write your code in this directory. You may write source and header files,
    or simply declare and define everything within header files.
*   Place necessary #include directives in the `solution.hpp` file, which is
    included by `main.cpp`. Don't modify the latter file directly.
*   A makefile is included which should be able to handle any file structure
    you might come up with that isn't too exotic. Run `make` to build the
    executable, or `make run` to build and run it. `make clean` removes build
    files.

### Necessary Declarations

Following are all of the publically-accesible methods and functions you'll need
to expose through #include directives in the `solution.hpp` file:

*   `CircularRobot()` (constructor)
*   `RectangularRobot()` (constructor)
*   `bool isColliding(const Robot& a, const Robot&, b)`
