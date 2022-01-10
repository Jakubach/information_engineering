#include <person.h>
#include <iostream>
#include <algorithm>

Person initialise_person(){
    Person person;
    std::cout << "Enter person's first name: ";
    std::cin >> person.name;
    std::cout << "Enter person's surname: ";
    std::cin >> person.surname;
    std::cout << "Enter person's age: ";
    std::cin >> person.age;
    std::cout << "Enter person's height: ";
    std::cin >> person.height;
    std::cout << "Enter person's weight: ";
    std::cin >>person.weight;
    return person;
}

void print_person(Person &person)
{
   std::cout << "Full name: " << person.name + " " + person.surname << std::endl;
   std::cout << "Age: " << person.age << std::endl;
   std::cout << "Height: " << person.height << std::endl;
   std::cout << "Weight: " << person.weight << std::endl;
}

float average_weight(const std::vector<Person> &persones){
    float average_weight = 0;
    for(const auto& person : persones){
        average_weight += person.weight;
    }
    return average_weight/persones.size();
}

Person tallest_person(const std::vector<Person>& persones){
    int max_height = persones.front().height; // persones[0].height;
    Person tallest_person = persones.front();
    for(const auto& person : persones){
        if(person.height > max_height){
            max_height = person.height;
            tallest_person = person;
        }
    }
    return tallest_person;
}

bool compare_persones_ages(const Person &p1, const Person &p2) {
    return p1.age > p2.age;
}

void sort_by_age(std::vector<Person>& persones){
    std::sort(persones.begin(), persones.end(), compare_persones_ages);
}
