// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car* newCar = new Car{light, nullptr, nullptr};

  if (first == nullptr) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    Car* last = first->prev;
    newCar->prev = last;
    last->next = newCar;
    newCar->next = first;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (first == nullptr) return 0;

  int size = 0;
  const Car* ptr = first;
  do {
    size = size + 1;
    ptr = ptr->next;
  } while (ptr != first);

  int onCount = 0;
  ptr = first;
  for (int j = 0; j < size; ++j) {
    if (ptr->light) onCount = onCount + 1;
    ptr = ptr->next;
  }

  if (onCount == 0) {
    countOp = size + size;
  } else if (onCount == size) {
    countOp = size * size + size;
  } else {
    countOp = size << 1;
  }

  return size;
}

int Train::getOpCount() {
  return countOp;
}
