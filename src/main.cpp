// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
    Train train;
    
    train.addCar(false);
    train.addCar(false);
    train.addCar(true);
    train.addCar(false);
    train.addCar(true);
    
    int length = train.getLength();
    int operations = train.getOpCount();
    
    return 0;
}
