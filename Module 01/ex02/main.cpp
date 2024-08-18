#include <iostream>  
#include <string>

/*
Pointers vs. References:

- Pointers: Hold the memory address of a variable and require explicit dereferencing (*). 
  They can be reassigned to point to different variables or be null.
  They offer more flexibility but require careful management to avoid errors like null pointer dereferencing.

- References: Are aliases for variables, providing a simpler syntax (no need for dereferencing).
  They always refer to a valid object. 
  They cannot be null or reassigned, making them safer and more predictable, but less flexible.

Syntax differences: 

 - Pointer (*):
 Declaration: Type* pointerName;
 Initialization: pointerName = &variableName;
 Access Value: *pointerName
 Memory Address: pointerName directly holds the address

 - Reference (&):
 Declaration: Type& referenceName = variableName;
 Access Value: referenceName is used directly 
 Memory Address: &referenceName gives the memory address
*/

int main() {
    std::string str = "HI THIS IS BRAIN"; 

    // The pointer holds the memory address of the variable
    std::string* stringPTR = &str;

    // The reference is an alias for the variable
    std::string& stringREF = str;

    // Print the memory address
    std::cout << "Memory address of the string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

    // Print the value of the string variable by:
    
    // Accessing it directly
    std::cout << "Value of the string variable: " << str << std::endl;
    
    // Dereferencing it using the * operator
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    
    // Referencing it
    std::cout << "Value referred to by stringREF: " << stringREF << std::endl;

    return 0;
}
