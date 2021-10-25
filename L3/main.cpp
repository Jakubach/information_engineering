#include <iostream>

int main() {

    // This is additional lesson (3.1), more exercises for loops and if statements.
    // Square ex.1
    int side = 4;
    for(int i = 0; i < side; i++){
        for(int j = 0; j < side; j++){
            if(i == 0 || i == side - 1){
                std::cout << "*";
                continue;
            }
            if(j>0 && j<side-1){
                std::cout << " ";
            }
            else{
                std::cout << "*";
            }
        }
        std::cout << std::endl;
    }

    // Pyramide ex.2
    // 1. center of pyramide (==height)
    // 2. draw if j belongs to height +/- (i-1) where j is column and i is row, both starting from 1
    int height = 5;
    //std::cin>>height; for coderunner
    for (int i = 1; i <= height; i++){
        for(int j = 1; j <= 2*height-1; j++){
            if(j>=height -(i-1) && j<= height +(i-1)){
                std::cout << "*";
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }


    // Ex.3 decode message
    //std::string a = "4 1 18 5 127 1023 1023 1023 13 9 7 8 20 25 127 123 20 8 9 14 7 19";
    //std::cout << a << std::endl;

    int a[5] = {4,1,18,5,127};
    for(int i=0;i<5;i++){
        if(a[i]<27) {
            char b = 'A' + a[i] - 1;
            std::cout << b;
        }
    }

    // If there is more time you can do:
    // https://www.codingame.com/training/easy/power-of-thor-episode-1
    return 0;
}
