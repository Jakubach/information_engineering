#include <iostream>

void capital_text(char* arr){
    int i = 0;
    while(arr[i] != '\0'){
        std::cout << char(arr[i] - ('a' - 'A'));
        i++;
    }
}

void capital_text(char* arr, int arr_size){
    for(int i=0; i<arr_size; i++){
        if(arr[i] == '\0'){
            break;
        }
        std::cout << char(arr[i] - ('a' - 'A'));
    }
}

int sum(int* arr, int arr_size){
    int sum = 0;
    for(int i=0; i<arr_size; i++){
        sum += arr[i];
    }
    return sum;
}

// swap - reference version

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// swap - pointers version (you have to pass addresses to variables in function)

/*
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/


void bubble_sort_dowhile(int* arr, int arr_size){
    bool changed = false;
    int iter_num =0;
    do{
        changed = false;
        int k = arr_size - 1;
        for(int i = 0; i<k; i++){
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                changed = true;
            }
            iter_num++;
        }
        k--;
    }while(changed);
    std::cout << "Number of iterations: " << iter_num << std::endl;
}

void bubble_sort_for(int tab[], int arr_size)
{
    bool changed = false;
    int iter_num =0;
    for(int i = 0; i < arr_size; i++)
    {
        changed = false;
        int k = arr_size - 1;
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
    // Some improvments:
    // 1. Check with uncommented changed statement - it allow us to skip last empty loop
    // 2. The bubble sort algorithm can be optimized by observing that the n-th pass finds the n-th largest element and puts it into its final place. (k--)
}



void text_statistic(char* arr, int arr_size){
    int n = 1;
    for(int i=1; i<arr_size; i++){
        if(arr[i-1] == '\0'){
            break;
        }
        if(arr[i-1] != ' '){
            if(arr[i] == arr[i-1]){
                n++;
            }
            else{
                std::cout << (char)arr[i-1] << " : " << n << std::endl;
                n = 1;
            }
        }
    }
}



int main()
{
    int a = 1;
    // operator & returns the address of the variable in memory
    // return value type is "pointer to value type"
    // Pointer is a type to store memory addresses
    // Uninitialized pointers point to a random address
    // Always initialize pointers to an address or a nullptr
    // size of pointer is 32 bits in 32 bits systems and 64 bits in 64 bits systems
    int* b = &a; // b stores the memory address of variable a
    //DEBUG
    std::cout << &a << "==" << b << std::endl;

    // Exercise 1
    char text[] = "informationengineering";
    std::cout << sizeof(text) <<std::endl;
    capital_text(text);
    std::cout << std::endl;
    capital_text(text,sizeof(text)/sizeof(char));
    std::cout << std::endl;
    int values[] = {9,4,2,1,3,7,5};
    int values_size = sizeof(values)/sizeof(int);
    std::cout << sum(values,values_size) << std::endl;

    //Exercise 2
    // Bubble sort
    // https://www.geeksforgeeks.org/bubble-sort/
    // http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/7-Sort/bubble-sort.html

    bubble_sort_for(values, values_size);
    int valuess[] = {9,4,2,1,3,7,5};
    bubble_sort_dowhile(valuess, values_size);
    for(int i = 0; i<values_size;i++){
        std::cout << values[i] << std::endl;
    }

    //Exercise 3
    char input[100];
    std::cin.getline(input,sizeof(text)/sizeof(char));
    text_statistic(input, sizeof(text)/sizeof(char));


    // Difference between reference and pointer
    //Pointers are similar to references but have additional useful properties:
    // Can be reassigned
    // Can point to "nothing"
    // Can be stored in a vector on an array
    return 0;
}
