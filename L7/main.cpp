#include <iostream>

#define ARR_SIZE 100

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void swap(char &a, char &b){
    char temp = a;
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

void bubble_sort(char tab[], int arr_size)
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

void count_capital_letters(char* arr, int arr_size){
    int ascii_capital_letters[ARR_SIZE];
    int n = 0;
    for(int i=0; i<arr_size; i++){
        if(arr[i] == '\0'){
            break;
        }
        if(arr[i]>='A' && arr[i]<='Z'){
            ascii_capital_letters[n] = (int)arr[i];
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
    std::cout << std::endl;
    char array[ARR_SIZE] = "ABCdefB";
    count_capital_letters(array,ARR_SIZE);
    std::cout << std::endl;
    return 0;
}
