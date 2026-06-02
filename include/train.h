#include "train.h"

Train::Train() : countOp_(0), first_(nullptr) {}

Train::~Train() {
  if (!first_) return;
  Car* cur = first_->next;
  while (cur != first_) {
    Car* tmp = cur;
    cur = cur->next;
    delete tmp;
  }
  delete first_;
}

void Train::addCar(bool light) {
  Car* car = new Car{light, nullptr, nullptr};
  if (!first_) {
    car->next = car;
    car->prev = car;
    first_ = car;
  } else {
    Car* last = first_->prev;
    last->next = car;
    car->prev  = last;
    car->next  = first_;
    first_->prev = car;
  }
}

int Train::getLength() {
  if (!first_) return 0;
  int  len = 1;
  Car* cur = first_->next;
  while (cur != first_) {
    ++countOp_;
    ++len;
    cur = cur->next;
  }
  return len;
}

int Train::getOpCount() {
  return countOp_;
}
