#include "../include/train.h"

#include <fstream>
#include <iostream>
#include <random>

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
        train.AddCar(false);
      }

      train.GetLength();

      out << n << ",all_off,"
          << train.GetOpCount() << "\n";
    }

    {
      Train train;

      for (int i = 0; i < n; ++i) {
        train.AddCar(true);
      }

      train.GetLength();

      out << n << ",all_on,"
          << train.GetOpCount() << "\n";
    }

    {
      Train train;

      for (int i = 0; i < n; ++i) {
        train.AddCar(dist(gen));
      }

      train.GetLength();

      out << n << ",random,"
          << train.GetOpCount() << "\n";
    }
  }

  out.close();

  std::cout << "Results saved to results.csv\n";

  return 0;
}
