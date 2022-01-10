#pragma once

#include <string>
#include <vector>

struct Person
{
    std::string name;
    std::string surname;
    int age;
    int height;
    int weight;
};

Person initialise_person();
void print_person(Person &person);
float average_weight(const std::vector<Person>& persones);
Person tallest_person(const std::vector<Person>& persones);
void sort_by_age(std::vector<Person>& persones);
