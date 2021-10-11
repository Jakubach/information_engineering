#include <iostream>

int main(int argc, char const *argv[])
{
    // 1. Program input parameters:

    // Print how many parameters we have received
    std::cout << "Got " << argc << " param(s)." << std::endl;

    // First program argument is always the program name
    std::cout << "Program: " << argv[0] << std::endl;

    for(int i=1; i < argc; i++){ // From 1 on
        std::cout << "Param: " << argv[i] << std::endl;
    }

    // 2. Avoid comparing floats:

    const float var = 3.14;
    std::cout << "Is " << var << " equal to 3.14? " << std::boolalpha << (var == 3.14) << std::endl;

    // 3. C++ identifiers
    /*
     An identifier is an arbitrarily long sequence of digits, underscores, lowercase and uppercase Latin letters, and most Unicode characters. A valid identifier must begin with a non-digit character.
     It could be used for naming.
     */
    int m_var;
    int M_var;
    int mVar;
    //int 6_var; INCORRECT
    int this_is_very_long_name;

    int studying_time; // Should be different than 0 :P

    // 4. Declarations
    /*
     Declarations may introduce entities, associate them with names and define their properties. The declarations that define all properties required tp ise an entity are defitnitions.
     */
    extern int foo; // introduce enitity named "foo"
    // Declares, but doesn't define foo (doesn't reserve memory)

    // 4. Definitions
    /*
     Definitions of functions usually include sequences of statements, some of which include expressions, which specify the computations to be performed by the program.
     "definition = declaration + memory space reservation"
     */
    int boo;
    int booo = 0;

    return 0;
}
