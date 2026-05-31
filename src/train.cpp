// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr), length(0) {}

Train::~Train() {
    if (!first) return;
    Car* current = first;
    Car* nextCar;
    do {
        nextCar = current->next;
        delete current;
        current = nextCar;
    } while (current != first);
}

void Train::addCar(bool light) {
    Car* newCar = new Car(light);
    
    if (!first) {
        first = newCar;
        first->next = first;
        first->prev = first;
    } else {
        Car* last = first->prev;
        last->next = newCar;
        newCar->prev = last;
        newCar->next = first;
        first->prev = newCar;
    }
    length++;
}

int Train::getLength() {
    if (!first) return 0;
    
    countOp = 0;
    Car* current = first;
    
    bool initialState = current->light;
    current->light = true;
    
    int step = 1;
    int result = 0;
    
    while (result == 0) {
        for (int i = 0; i < step; i++) {
            current = current->next;
            countOp++;
        }
        
        if (!current->light) {
            current->light = true;
            step = 1;
        } else {
            bool success = true;
            Car* check = current;
            
            for (int i = 0; i < step; i++) {
                check = check->prev;
                countOp++;
            }
            
            Car* verify = check;
            for (int i = 0; i < step; i++) {
                countOp++;
                if (!verify->light) {
                    success = false;
                    break;
                }
                verify = verify->next;
            }
            
            if (success) {
                result = step;
            } else {
                step++;
            }
        }
    }
    
    current = first;
    for (int i = 0; i < result; i++) {
        current->light = true;
        current = current->next;
        if (i < result - 1) countOp++;
    }
    first->light = initialState;
    
    return result;
}
