// Copyright 2022 NNTU-CS

#include "train.h"

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

void Train::addCar(bool light) {
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

int Train::getLength() {
  count_op_ = 0;

  if (first_ == nullptr) {
    return 0;
  }

  int length = 1;
  Car* current = first_;

  while (current->next != first_) {
    current = current->next;
    ++length;
    ++count_op_;
  }

  return length;
}

int Train::getOpCount() {
  return count_op_;
}
