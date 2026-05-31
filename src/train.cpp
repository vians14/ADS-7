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
    if (length == 1) return 1;
    
    countOp = 0;
    Car* current = first;
    
    current->light = true;
    
    int step = 1;
    int totalLength = 1;
    
    while (true) {
        for (int i = 0; i < step; i++) {
            current = current->next;
            countOp++;
        }
        
        if (!current->light) {
            current->light = true;
            totalLength += step;
            step = 1;
            continue;
        }
        
        Car* test = current;
        for (int i = 0; i < totalLength; i++) {
            test = test->prev;
            countOp++;
            if (test == first) {
                bool allLight = true;
                Car* check = first;
                for (int j = 0; j < totalLength; j++) {
                    countOp++;
                    if (!check->light) {
                        allLight = false;
                        break;
                    }
                    check = check->next;
                }
                
                if (allLight) {
                    return totalLength;
                }
            }
        }
        
        step++;
    }
}
