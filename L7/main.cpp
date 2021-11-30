#include <iostream>

#define ARR_SIZE 100

void swap(char &a, char &b){
    char temp = a;
    a = b;
    b = temp;
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void bubble_sort(int tab[], int arr_size)
{
    bool changed = false;
    int iter_num =0;
    int k = arr_size - 1;
    for(int i = 0; i < arr_size; i++)
    {
        changed = false;
        for(int j = 0; j < k; j++)
        {
            if(tab[j] > tab[j+1]){
                swap(tab[j], tab[j+1]);
                changed = true;
            }
            iter_num++;
        }
        k--;
        if(changed == false){
            break;
        }
    }
    std::cout << "Number of iterations: " << iter_num << std::endl;
}

void count_small_letters(char* text, int arr_size){
    int ascii_capital_letters[ARR_SIZE];
    int n = 0;
    for(int i=0; i<arr_size; i++){
        if(text[i] == '\0'){
            break;
        }
        if(text[i]>='a' && text[i]<='z'){
            ascii_capital_letters[n] = (int)text[i];
            n++;
        }
    }
    bubble_sort(ascii_capital_letters, n);
    int counter = 1;
    for(int i=1; i<n+1; i++){
        if((char)ascii_capital_letters[i] == (char)ascii_capital_letters[i-1]){
            counter++;
        }
        else{
            std::cout << (char)ascii_capital_letters[i-1] << " : " << counter << std::endl;
            counter = 1;
        }
    }
}

void count_small_letter(char* text, int arr_size){
    for(int i=0; i<26; i++){
        //std::cout << "Couting letter: " << char(i+'a') << std::endl;
        int counter = 0;
        for(int j=0;j<arr_size;j++){
            if(text[j]=='\0'){
                break;
            }
            else if(text[j] == char(i+'a')){
                counter++;
            }
        }
        if(counter > 0){
            std::cout << char(i+'a') << " occurs " << counter << " times." << std::endl;
        }
    }
}

void count_at(char* text, int arr_size){
    int counter = 0;
    for(int i=0;i<arr_size-1;i++){
        if(text[i]=='\0'){
            break;
        }
        if(text[i] == 'a' && text[i+1] == 't'){
            counter++;
        }
    }
    std::cout << "at" << " occurs "<< counter << " times." << std::endl;
}

unsigned int semifactorial(unsigned int n)
{
    int result = 1;
    //round up positive number x <=> (x + 1) / 2;
    for (int i=0; i<=(n + 1) / 2 - 1; i++){
        result *= (n - 2 * i);
    }
    // another version
    /*
    for (int i=n; i>=0; i=i-2)
    {
        if(i<=1){
            return result;
        }
        else{
            result *= i;
        }
    }
    */
    return result;
}

unsigned int recursive_semifactorial(unsigned int n)
{
    if(n<=1){
        return 1;
    }
    return n*recursive_semifactorial(n-2);
}

int main()
{
    // Mid-term review
    // Exercise 0: Creating a menu
    // Exercise 1: Count all small letters in sentence (functions, arrays, pointers, conditionals)
    // Exercise 2: Count all "at" in sentence (functions, arrays, pointers, conditionals)
    // Exercise 3: Write semifactorial function in two ways, using recursion and using loop.
    // https://en.wikipedia.org/wiki/Double_factorial

    int key;
    do{
        std::cout << "Please select a task." << std::endl;
        std::cout << "1 - Task 1" << std::endl << "2 - Task 2" << std::endl << "3 - Task 3" << std::endl<< "0 - Exit"<< std::endl;
        std::cin >> key;
        switch (key) {
        case 1:{
            std::cout << "Task 1 selected" << std::endl;
            char text_array[ARR_SIZE];
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.getline(text_array, ARR_SIZE);
            count_small_letter(text_array,ARR_SIZE);
            break;
        }
        case 2:{
            std::cout << "Task 2 selected" << std::endl;
            char text_array[ARR_SIZE];
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.getline(text_array, ARR_SIZE);
            count_at(text_array,ARR_SIZE);
            break;
        }
        case 3:{
            std::cout << "Task 3 selected" << std::endl;
            int semifactorial_argument = 0;
            std::cin >> semifactorial_argument;
            std::cout << "Result from semifactorial with loop: " << semifactorial(semifactorial_argument) << std::endl;
            std::cout << "Result from semifactorial with recursion: " << recursive_semifactorial(semifactorial_argument) << std::endl;
            break;
        }
        case 0:{
            std::cout << "Exitting" << std::endl;
            break;
        }
        default:{
            std::cout << "Please input different number" <<std::endl;
            break;
        }

        }
    }while(key);

    return 0;
}
