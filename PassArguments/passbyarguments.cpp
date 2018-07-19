#include <iostream>
 
void foo(int y)
{
    std::cout << "y = " << y << '\n';
}
 
int main()
{
    foo(5); // first call
 
    int x = 6;
    foo(x); // second call
    foo(x+1); // third call
 
    return 0;
}

//Pros
//Arguments passed by value can be variables (e.g. x), literals (e.g. 6), expressions (e.g. x+1), structs & classes, and enumerators. In other words, just about anything
//Arguments are never changed by the function being called, which prevents side effects.

//Cons
//Copying structs and classes can incur a significant performance penalty, especially if the function is called many times.
