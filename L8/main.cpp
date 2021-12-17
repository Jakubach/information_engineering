#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <chrono>
#include <cstdlib>              // Header with rand() and srand() functions
#include <ctime>                // Header with time() function


/*
 By default, if no container class is specified for a LIFO and FIFO structures.

 LIFO - Last Input First Output https://www.cplusplus.com/reference/stack/stack/
 Good for vectors (push_back pop_back)
 FIFO - First Input Last Output https://www.cplusplus.com/reference/queue/queue/
 Good for lists (push_back pop_front)



Vectors vs. lists:
Use sequential containers when you need to access elements by position
Use std:vector as your default sequential container, especially as an alternative to built-in arrays
Use a std::list if you need to insert/remove elements in the middle/beggining of the sequence
Use a std::vector if you will be adding and removing elements from the end
Do not use std::list if you need random access to objects
std:vector store memory contiguously
std::list allocates memory by node

https://www.youtube.com/watch?v=pBrz9HmjFOs

Why there is no subscribtion [] operator for list?
time complexity of indexing elements in list would be O(n^2).
ISO C++ standard specifically mentions that all STL sequences that support operator[] should do it in amortized constant time
which is accessible for vector
So the main reason in the consistency (which makes our code time-predictable) and then also get the better performance.


*/
bool is_prime(int number){
    if(number <= 1) return false;
    int j = 0;
    for(int i = 2; i*i <= number; i++){
        if(number % i == 0) return false;
        j++;
    }
    return true;
}

void print_vector(std::vector<int> numbers){
    for (auto value : numbers) {
        std::cout << value << ", ";
    }
    std::cout << std::endl;
}

void remove_prime_numbers(std::vector<int> &numbers){
    for(unsigned int i = 0; i < numbers.size();){
        if(is_prime(numbers[i])){
            numbers.erase(numbers.begin() + i);
        }
        else{
            i++;
        }
    }
}

void remove_prime_numbers_std(std::vector<int> &numbers){
    numbers.erase(std::remove_if(numbers.begin(),numbers.end(),is_prime),numbers.end());
}

std::vector<int> create_vector(int min, int max, bool random = false){
    std::vector<int> numbers;
    if(!random){
        for(int i = min; i <= max;i++){
            numbers.emplace_back(i);
        }
    }
    else{
        for(int i = 0; i < (max-min); i++){
            numbers.emplace_back(min + std::rand() % (max-min+1));
        }
    }
    return numbers;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(std::vector<int> numbers)
{
    bool changed = false;
    int iter_num =0;
    int k = numbers.size() - 1;
    for(unsigned int i = 0; i < numbers.size(); i++)
    {
        changed = false;
        for(int j = 0; j < k; j++)
        {
            if(numbers[j] > numbers[j+1]){
                swap(numbers[j], numbers[j+1]);
                changed = true;
            }
            iter_num++;
        }
        k--;
        if(changed == false){
            break;
        }
    }
}


int main()
{
    //srand(time(nullptr));
    srand(0);
    std::vector<int> numbers = create_vector(1,10);
    std::cout << "Before removing prime numbers: " << std::endl;
    print_vector(numbers);
    remove_prime_numbers_std(numbers);
    std::cout << "After removing prime numbers: " << std::endl;
    print_vector(numbers);

    int min = 0, max = 10000;
    std::vector<int> random_numbers = create_vector(min,max,true);
    auto start = std::chrono::steady_clock::now();
    bubble_sort(random_numbers);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start; // calculate time difference, and display in miliseconds
    std::cout << "Sorting time with " << max-min << " numbers: " << std::chrono::duration <double, std::milli>(diff).count() << " ms" << std::endl;

    /*
    std::list<int> l4{ 5, 6, 7, 8 };
    // INCORRECT IN LISTS

    for(int i = 0; i < l4.size(); i++){
        //std::cout << l4[i] << std::endl; // INCORRECT
    }
    // Correct 1
    for (auto const& i : l4) {
        std::cout << i;
    }
    // Correct 2
    for (std::list<int>::iterator it = l4.begin(); it != l4.end(); ++it){
        std::cout << *it;
    }
    */

    return 0;
}
