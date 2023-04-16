// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
  // реализация шаблона очереди с приоритетом на кольцевом буфере
  T* arr;
  int f, l, count;

 public:
  TPQueue(): arr(new T[size]), f(0), l(0), count(0) {}
  void push(const T & value) {
    if (count == size)
      throw std::string("FULL!");
    ++count;
    int m = l;
    for (int i = f; i < l; i++)
      if (arr[i].prior < value.prior) {
        m = i;
        break;
      }
    for (int i = last; i> m; i--)
      arr[i % size] = arr[(i - 1) % size];
    arr[m % size] = value;
    ++l;
  }
  T& pop() {
    if (count == 0) {
      throw std::string("EMPTY!");
    } else {
      count--;
      return arr[f++ % size];
    }
  }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
