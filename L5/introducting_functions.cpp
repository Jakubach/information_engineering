#include <iostream>
#include <string>

using namespace std;

void SayHello(std::string name = ""){
    std::cout << "Hello " << name << std::endl;
}

void SayHello(int age){
    std::cout << "Hello. I am " << age << " years old." << std::endl;
}

std::string GetName(){
    std::string name;
    std::cin >> name;
    return name;
}

int main()
{
    //cout << "Hello World!" << endl;
    SayHello("Jakub");
    std::string name = GetName();
    SayHello(name);
    SayHello(25);
    SayHello();
    return 0;
}


