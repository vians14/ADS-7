// src/train.cpp
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
    Car* newCar = new Car;
    newCar->light = light;
    newCar->next = nullptr;
    newCar->prev = nullptr;
    
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
}

int Train::getOpCount() {
    return countOp;
}

int Train::getLength() {
    if (!first) return 0;
    
    countOp = 0;
    Car* current = first;
    
    bool saved = current->light;
    current->light = true;
    
    int step = 1;
    int total = 1;
    
    while (true) {
        for (int i = 0; i < step; i++) {
            current = current->next;
            countOp++;
        }
        
        if (!current->light) {
            current->light = true;
            total += step;
            step = 1;
        } else {
            Car* back = current;
            for (int i = 0; i < total; i++) {
                back = back->prev;
                countOp++;
            }
            
            if (back == first) {
                bool ok = true;
                Car* check = first;
                for (int i = 0; i < total; i++) {
                    countOp++;
                    if (!check->light) {
                        ok = false;
                        break;
                    }
                    check = check->next;
                }
                
                if (ok) {
                    first->light = saved;
                    return total;
                }
            }
            
            step++;
        }
    }
}
