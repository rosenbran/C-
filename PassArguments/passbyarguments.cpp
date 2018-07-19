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