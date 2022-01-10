#include "pet.h"

#include <iostream>

void print_pet(Pet &pet) {
   std::cout << "Name: " << pet.name << std::endl;
   std::cout << "Age: " << pet.age << std::endl;
   std::cout << "Weight: " << pet.weight << std::endl;
}
