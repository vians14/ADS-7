// Copyright 2021 NNTU-CS
#include <iostream>
#include <fstream>
#include <random>
#include "train.h"

int main() {
  std::ofstream dataFile("data.csv");
  dataFile << "n,all_off,all_on,random\n";

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 1);

  for (int n = 10; n <= 400; n += 10) {
    Train trainOff;
    for (int i = 0; i < n; ++i) trainOff.addCar(false);
    trainOff.getLength();
    int opsOff = trainOff.getOpCount();

    Train trainOn;
    for (int i = 0; i < n; ++i) trainOn.addCar(true);
    trainOn.getLength();
    int opsOn = trainOn.getOpCount();

    int randomSum = 0;
    const int trials = 10;
    for (int t = 0; t < trials; ++t) {
      Train trainRand;
      for (int i = 0; i < n; ++i) {
        trainRand.addCar(dis(gen) == 1);
      }
      trainRand.getLength();
      randomSum += trainRand.getOpCount();
    }
    int opsRandom = randomSum / trials;

    dataFile << n << "," << opsOff << "," << opsOn << "," << opsRandom << "\n";
  }

  dataFile.close();
  std::cout << "Experiment completed. Data saved to data.csv\n";
  return 0;
}
