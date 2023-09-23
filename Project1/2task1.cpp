#include <iostream>
#include <string>
#include <algorithm>

/*
1) strlen - C++ has a size() function for string objects of std::string class, which returns the length of the string.
2) strcpy - in C++ you can use assignment operator = to copy strings: string a = "foo"; string b; a = b;.
3) strcmp - C++ has the string.compare() function that compares two strings and returns the result of the comparison (a negative number if the first string is smaller; a positive number if the first string is larger; 0 if the strings are equal).
4) strcat - C++ has a + operator that can be used to concatenate strings OR strcat().
5) someString[index] - C++ uses the [] operator to access string characters by index: string a = "boo"; a[index] OR a.at(index).
6) push_back - a method of the std::string class that adds a character to the end of the string. In C: char str[5] = "Foo"; arr[3] = value; - no direct equivalent.
7) pop_back - a method of std::string class that removes the last character from the string. In C: char str[5] = "Foo"; str[strlen(str) - 1] = "\0"; - no direct equivalent.

The main difference between strings in C and
C++ is that in C strings are represented as arrays of characters,
while in C++ there are arrays of characters.
arrays of characters, while in C++ there is a std::string class
that provides convenient methods and operators for working with
strings. and operators for working with strings. The std::string
class provides safer work with strings because it performs
automaticwith strings, because it performs automatic memory
management and prevents buffer overflow errors,
related to buffer overflows. Also, the std::string
class provides more convenient functions for working with strings.
*/


int main() {
    std::string inputString;                                                                       //Declaring the variable inputString of type std::string, which is a class for working with strings in C++
    std::cout << "Enter the string: ";                                                             //The output operator << is used to output the string "Enter the string: " to a standard output stream (usually a console).
    std::getline(std::cin, inputString);                                                           //The std::getline() function is used to read a string from a standard input stream (usually console) and store it in the inputString variable.

    // Remove spaces and punctuation marks
    inputString.erase(                                                                             //The erase() method is used to remove elements from a string.
        std::remove_if(inputString.begin(), inputString.end(),                                     //The std::remove_if() function takes a range of elements and a predicate and removes elements for which the predicate returns true. In this case, the predicate is represented as a lambda expression that checks whether a character is either a space or a punctuation mark, returning true or false, respectively
            [](unsigned char c) { return std::isspace(c) || std::ispunct(c); }),                   
        inputString.end());                                                                        //A call to the end() method returns an iterator pointing to the position behind the last element of the string. In this case, the erase() method removes all elements of the string from the found position to the end of the string

    //  Sort the letters in alphabetical order
    std::sort(inputString.begin(), inputString.end());                                            //The std::sort() function sorts the elements of a string in alphabetical order by rearranging the elements. In this case, the function uses the begin() and end() iterators to specify the range of elements in the string.

    // Output the sorted string
    std::cout << "the sorted string: " << inputString << std::endl;                               //The output operator "<<" is used to output the string "the sorted string: " and the value of the variable inputString to the standard output stream. std::endl is used for carriage return and clearing the output buffer.

    return 0;
}


/*ex:
Enter the string: LdkjNSDMFKKN aksfjjkaskjakskjskas xiusfyujasmn
the sorted string: DFKKLMNNSaaaaadffijjjjjjkkkkkkkmnsssssssuuxy
*/