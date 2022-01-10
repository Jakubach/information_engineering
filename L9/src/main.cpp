#include <iostream>
// include string
#include <string>
#include <vector>
#include "pet.h"
#include "person.h"

// Strings cpp reference
// https://www.cplusplus.com/reference/string/string/

int main()
{
    // initializing string variable
    std::string name = "Alex";
    std::string surname = "Black";

    // string.length()
    std::cout << "First letter of name " << name << " is " << name[0] << std::endl;
    std::cout << "This name has " << name.length() << " letters" << std::endl;

    // concatenation with +
    std::string full = name + " " + surname;
    //std::cout << "Full name is: " << full << std::endl;


    // structures initializer list
    Person mechanic = {"Henryk","Mechanik", 42,178, 75};
    Person teacher = {"Jakub","Chudzinski", 26,176, 73};
    Person robotics = {"Jan","Robotyk", 28,175, 70};
    //print_person(mechanic);
    //print_person(teacher);
    //print_person(robotics);

    // structures user input
    /*
    std::cout << "Enter person's fist name: ";
    std::cin >> robotics.name;
    std::cout << "Enter person's surname: ";
    std::cin >> robotics.surname;
    std::cout << "Enter person's age: ";
    std::cin >> robotics.age;
    std::cout << "Enter person's height: ";
    std::cin >> robotics.height;
    std::cout << "Enter person's weight: ";
    std::cin >>robotics.weight;
    */

    // initialise person from function
    //Person new_person = initialise_person();
    //print_person(new_person);

    //vectors of structures
    // https://www.geeksforgeeks.org/push_back-vs-emplace_back-in-cpp-stl-vectors/
    std::vector<Person> persones;
    persones.emplace_back(mechanic);
    persones.emplace_back(teacher);
    persones.emplace_back(robotics);
    //created by user
    //persones.emplace_back(initialise_person());
    //persones.emplace_back(initialise_person());
    //persones.emplace_back(initialise_person());
    for(auto person : persones){
        print_person(person);
    }
    std::cout << "Average weight: " << average_weight(persones) << std::endl;
    Person tallest = tallest_person(persones);
    std::cout << "Talest person: " << std::endl;
    print_person(tallest);
    std::cout << "Sorted by age persones: " << std::endl;
    sort_by_age(persones);
    for(auto person : persones){
        print_person(person);
    }
    return 0;
}
