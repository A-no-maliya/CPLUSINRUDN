#include <iostream>

/*
1) int ptr = (int)malloc(sizeof(int)) - in C++ you can use the new operator to allocate memory:
int *ptr = new int;

2) int ptrArr = (int)malloc(sizeof(int)*N) - in C++ you can also use new[] to allocate an array of memory:
int *ptrArr = new int[N];

3) free(ptr) - in C++, you must use the delete operator to free memory:
delete ptr;

4) free(ptrArr) - in C++, the delete[] operator is used to free the memory of the allocated array:
delete[] ptrArr

In C++, it is necessary to free dynamic memory using delete and delete[] operators, depending
on whether a single object or an array has been allocated. Freeing memory twice can lead to
undefined program behavior. You cannot free unallocated memory.
*/


int main() {
    int numRows;
    std::cout << "Enter the number of rows of the Fibonacci triangle: ";
    std::cin >> numRows;

    // Allocating memory for Fibonacci triangle
    int** triangle = new int* [numRows];
    for (int i = 0; i < numRows; i++) {
        triangle[i] = new int[i + 1];
    }

    // Filling the Fibonacci triangle
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == 0 || j == 0 || j == i) {
                // The values on the triangle boundaries are always equal to 1
                *(*(triangle + i) + j) = 1;
            }
            else {
                // The value inside the triangle is the sum of the two previous values
                *(*(triangle + i) + j) = *(*(triangle + i - 1) + j - 1) + *(*(triangle + i - 1) + j);
            }
        }
    }

    // Derivation of the Fibonacci triangle
    std::cout << "THe Fibonacci Triangle:" << std::endl;
    for (int i = 0; i < numRows; i++) {
        // Print the values of the string
        for (int j = 0; j <= i; j++) {
            std::cout << *(*(triangle + i) + j) << " ";
        }
        std::cout << std::endl;
    }

    // Memory release
    for (int i = 0; i < numRows; i++) {
        delete[] triangle[i];
    }
    delete[] triangle;

    return 0;
}

/*
I'm too lazy to write a commit for each line, so a general way of working the code:
In this program, we first ask the user for the number of rows of a Fibonacci triangle.
Then we allocate memory for the two-dimensional triangle array using dynamic memory
allocation. Then we fill the Fibonacci triangle with values using pointer arithmetic.
Next, we output the Fibonacci triangle using pointer arithmetic to access the array elements.
At the end of the program we free the allocated memory using delete and delete[] operators.
*/

/*I got stuck in compilation so I check programs through online compiler).*/