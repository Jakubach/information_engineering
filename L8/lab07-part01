#include <iostream>
#include <vector>
#include <list>
#include <map>


int main()
{
    std::vector<int> numbers = {10,10,20,20};
    numbers.emplace_back(5);

    // moving by index
    for(int i = 0; i < numbers.size();i++){
        std::cout << numbers[i] << std::endl;
    }

    // moving by iterator
    for(std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++ ){
        std::cout << *it << std::endl;
    }

    // moving by elements
    for (auto &number : numbers) {
        std::cout << number << std::endl;
    }
    return 0;
}
