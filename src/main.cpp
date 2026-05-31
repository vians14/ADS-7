// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
    Train train;
    
    train.addCar(false);
    train.addCar(false);
    train.addCar(false);
    train.addCar(false);
    
    int len = train.getLength();
    int ops = train.getOpCount();
    
    return 0;
}
