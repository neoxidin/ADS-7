#include "../include/train.h"

Train::Train()
    : first_(nullptr),
      count_op_(0) {}

Train::~Train() {
  if (first_ == nullptr) {
    return;
  }

  Car* current = first_->next;

  while (current != first_) {
    Car* next = current->next;
    delete current;
    current = next;
  }

  delete first_;
}

void Train::AddCar(bool light) {
  Car* car = new Car(light);

  if (first_ == nullptr) {
    first_ = car;
    first_->next = first_;
    first_->prev = first_;
    return;
  }

  Car* last = first_->prev;

  last->next = car;
  car->prev = last;

  car->next = first_;
  first_->prev = car;
}

int Train::GetLength() {
  count_op_ = 0;

  Car* start = first_;

  start->light = true;

  int distance = 1;

  while (true) {
    Car* current = start;

    for (int i = 0; i < distance; ++i) {
      current = current->next;
      ++count_op_;
    }

    if (current->light) {
      current->light = false;

      for (int i = 0; i < distance; ++i) {
        current = current->prev;
        ++count_op_;
      }

      if (!current->light) {
        return distance;
      }
    }

    ++distance;
  }
}

int Train::GetOpCount() const {
  return count_op_;
}
