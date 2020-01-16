#include <stdlib.h>
#include <iostream>

void f(void)
{
    int *x = (int *)malloc(10 * sizeof(int));
    std::cout << sizeof(x) << std::endl;
    x[10] = 0; // problem 1: heap block overrun
} // problem 2: memory leak -- x not freed

int main(void)
{
    f();
    return 0;
}