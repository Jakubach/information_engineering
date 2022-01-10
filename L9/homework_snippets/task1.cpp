#include <iostream>
#include <string>

// Your structure here...

int main(){
    Athlete first_athlete = {"Franek","Atleta",100,120};
    std::cout << "Full name: " << first_athlete.name + " " + first_athlete.surname << std::endl;
    std::cout << "Bench press personal best: " << first_athlete.bench_press_record << " kg. " << std::endl;
    std::cout << "Deadlift personal best: " << first_athlete.deadlift_record << " kg. " << std::endl;
}
