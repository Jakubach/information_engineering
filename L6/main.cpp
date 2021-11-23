#include <iostream>

int sum(int n) {
    if (n == 1) {
        return n;
    }
    return n + sum(n - 1);
}

int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

void capitals(char* array, int arr_size){
    for(int i=0;i<arr_size;i++){
        if(array[i] == '\0'){
            break;
        }
        std::cout << char(array[i]-('a'-'A'));
    }
}

// swap - reference version ( It is advised to use references instead of pointers when possible, as it is easier to avoid problems with memory management.)
void swap_elements(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}

// swap - pointers version (you have to pass addresses to variables in function)
/*
void swap_elements(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/
void bubb_sort(int array[], int arr_size){
    int iterations=0;
    bool swapped = false;
    int k = arr_size-1;
    for(int i=0;i<arr_size;i++){
        swapped = false;
        for(int j=0;j<k;j++){
            if(array[j]>array[j+1]){
                swap_elements(array[j],array[j+1]);
                swapped = true;
            }
            iterations++;
        }
        if(swapped == false){
            break;
        }
        k--;
    }
    std::cout <<"There was " << iterations << " iterations." << std::endl;

}

void bubble_sort_dowhile(int* arr, int arr_size){
    bool changed = false;
    int iter_num =0;
    int k = arr_size - 1;
    do{
        changed = false;
        for(int i = 0; i<k; i++){
            if(arr[i] > arr[i+1]){
                swap_elements(arr[i], arr[i+1]);
                changed = true;
            }
            iter_num++;
        }
        k--;
    }while(changed);
    std::cout << "Number of iterations: " << iter_num << std::endl;
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

int main() {
    // Assigment 1
    //std::cout << fibonacci(11);

    // Pointers
    int a = 5;
    int* b = &a; // b stores the memory address of variable a
    //a = a+2;
    //std::cout <<"The memory address is: "<< b << ". The value is: " << *b << std::endl;
    std::cout << &a << "==" << b << std::endl;

    // operator & returns the address of the variable in memory
    // return value type is "pointer to value type"
    // Pointer is a type to store memory addresses
    // Uninitialized pointers point to a random address
    // Always initialize pointers to an address or a nullptr
    // size of pointer is 32 bits in 32 bits systems and 64 bits in 64 bits systems
    // DEBUGGING example

    //Exercise 1
    char arr[]="informationengineering";
    capitals(arr,sizeof(arr)/sizeof(char));
    std::cout << std::endl;

    //Exercise 2
    // Check above two bubble sort implementations and description in below links:
    // https://www.geeksforgeeks.org/bubble-sort/
    // http://www.mathcs.emory.edu/~cheung/Courses/171/Syllabus/7-Sort/bubble-sort.html
    int array[]={9,1,5,4,3};
    int arr_size = sizeof(array)/sizeof(int);
    bubb_sort(array,arr_size);
    for(int i=0; i<arr_size;i++){
        std::cout << array[i]<< std::endl;
    }
    std::cout << std::endl;

    //Exercise 3
    //char input[100];
    //std::cin.getline(input,sizeof(text)/sizeof(char));
    //text_statistic(input, sizeof(text)/sizeof(char));

    // Difference between reference and pointer
    //Pointers are similar to references but have additional useful properties:
    // Can be reassigned
    // Can point to "nothing"
    // Can be stored in a vector on an array
}
