#include <iostream>
void printArray(int *array, int length)
{
    // if user passed in a null pointer for array, bail out early!
    if (!array)
        return;
 
    for (int index=0; index < length; ++index)
        cout << array[index] << ' ';
}
 
int main()
{
    int array[6] = { 6, 5, 4, 3, 2, 1 };
    printArray(array, 6);
}

//When to use
//When passing built-in arrays (if you’re okay with the fact that they’ll decay into a pointer).
//When passing a pointer and nullptr is a valid argument logically.