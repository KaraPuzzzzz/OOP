#include<iostream>
#include"arr3.h"


int main() {
    Data::Array3d<int> arr(2, 3, 4); 

   
    arr.SetValues0(0, { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} });
    arr.SetValues0(1, { {13, 14, 15, 16}, {17, 18, 19, 20}, {21, 22, 23, 24} });

   
    arr.arrayPrint();

    std::vector<int> slice = arr.GetValues0(1);


    for (int i : slice) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}