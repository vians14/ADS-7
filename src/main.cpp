// src/main.cpp
#include "train.h"
#include <iostream>

int main() {
    Train train;
    int count = 60;
    
    while (count--)
        train.addCar(false);
    
    std::cout << train.getLength() << std::endl;
    std::cout << train.getOpCount() << std::endl;
    
    return 0;
}
