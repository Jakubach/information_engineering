#include <iostream>
#include <cstring>
#include <limits>

using std::cout;
using std::endl;
using std::cin;

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int ar1[4];     // Good

    //const int cnum = 4;
    //int ar3[cnum];  // Good
    /*
    char surname[100];

    cin >> surname;
    int i = 0;
    while(surname[i] != '\0'){ 
        cout << surname[i] << " : " << (int)surname[i] << endl;
        i++;
    }
    */
   
   /*
    char address[100] = "https://www.";
    char address_suffix[50];
    cin >> address_suffix;
    cin >> address;strcat(address, address_suffix);
    cout << address << endl;
    for(int i = 0; i <strlen(address); i++){
        cout << (int)address[i] << endl;
    }
*/
    // Not clearing buffer effect

    int x;
    char str[80];
    cout << "Enter a number and a string:\n";
    cin >> x;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.getline(str,80); //take a string
    cout << "You have entered:\n";
    cout << x << endl;
    cout << str << endl;
    return 0;
}
