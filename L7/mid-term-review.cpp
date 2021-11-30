#include <iostream>

#define ARR_SIZE 100

using namespace std;

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


int main()
{
    cout << "Please select a task." << endl;
    char key;
    do{
        std::cout << "1 - Task 1" << std::endl << "2 - Task 2" << std::endl << "X - exit" <<std::endl;
        std::cin >> key;
        switch(key) {
        case '1':{
            std::cout << "Task 1"<< std::endl;
            char array[ARR_SIZE];
            std::cin.clear(); // Clears error state of the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores rest of the line
            std::cin.getline(array,ARR_SIZE);
            count_small_letters(array,ARR_SIZE);
            break;
        }
        case '2':
        {
            std::cout << "Task 2" << std::endl;
            break;
        }
        case 'X':
        {
            std::cout << "Exit"<< std::endl;
            break;
        }
        default:{
            std::cout << "Please select task again"<< std::endl;
            break;
        }

        }
    }while(key != 'X');
    return 0;
}
