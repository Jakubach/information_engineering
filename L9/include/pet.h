#pragma once

#include <string>

struct Pet {
   std::string name;
   int age;
   double weight;
};

void print_pet(Pet &pet);
