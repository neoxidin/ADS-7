// Copyright 2022 NNTU-CS

#include <fstream>
#include <iostream>
#include <random>

#include "train.h"

int main() {
  std::ofstream out("results.csv");

  out << "n,type,ops\n";

  std::random_device rd;
  std::mt19937 gen(rd());
  std::bernoulli_distribution dist(0.5);

  for (int n = 2; n <= 1000; n += 10) {
    {
      Train train;

      for (int i = 0; i < n; ++i) {
        train.addCar(false);
      }

      train.getLength();

      out << n << ",all_off,"
          << train.getOpCount() << "\n";
    }

    {
      Train train;

      for (int i = 0; i < n; ++i) {
        train.addCar(true);
      }

      train.getLength();

      out << n << ",all_on,"
          << train.getOpCount() << "\n";
    }

    {
      Train train;

      for (int i = 0; i < n; ++i) {
        train.addCar(dist(gen));
      }

      train.getLength();

      out << n << ",random,"
          << train.getOpCount() << "\n";
    }
  }

  out.close();

  std::cout << "Results saved to results.csv\n";

  return 0;
}
