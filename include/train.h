#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Car {
    bool light;
    Car* next;
    Car* prev;

    explicit Car(bool state)
        : light(state),
          next(nullptr),
          prev(nullptr) {}
  };

  Car* first_;
  int count_op_;

 public:
  Train();
  ~Train();

  void AddCar(bool light);

  int GetLength();
  int GetOpCount() const;
};

#endif  // INCLUDE_TRAIN_H_
