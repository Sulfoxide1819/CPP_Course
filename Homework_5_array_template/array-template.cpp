#include <algorithm>
#include <iostream>

template <class T, size_t size>
class Array {
  T array[size];

 public:
  Array(){};

  Array(T* b) {
    for (size_t i = 0; i < size; ++i) {
      array[i] = b[i];
    }
  }

  void show() {
    for (size_t i = 0; i < size; ++i) {
      std::cout << array[i] << " ";
    }
    std::cout << std::endl;
  }

  T minimum() {
    T min_val = array[0];
    for (size_t i = 1; i < size; ++i) {
      if (array[i] < min_val) {
        min_val = array[i];
      }
    }
    return min_val;
  }

  T minimum(Array<T, size>& m) {
    T min_val = m.array[0];
    for (size_t i = 1; i < size; ++i) {
      if (m.array[i] < min_val) {
        min_val = m.array[i];
      }
    }
    return min_val;
  }

  T& operator[](size_t index) {
    if (index >= size) {
      throw std::out_of_range("Index out of range");
    }
    return array[index];
  }

  size_t getSize() const { return size; }
};

int main() {
  int data1[] = {5, 2, 8, 1, 9};
  Array<int, 5> arr1(data1);

  std::cout << "Array 1: ";
  arr1.show();
  std::cout << "Minimum in array 1: " << arr1.minimum() << std::endl;

  double data2[] = {3.14, 2.71, 1.41, 1.73};
  Array<double, 4> arr2(data2);

  std::cout << "\nArray 2: ";
  arr2.show();
  std::cout << "Minimum in array 2: " << arr2.minimum() << std::endl;

  int data3[] = {10, 3, 7, 4, 6};
  Array<int, 5> arr3(data3);

  std::cout << "\nArray 3: ";
  arr3.show();
  std::cout << "Minimum in array 3 (using overloaded method): "
            << arr1.minimum(arr3) << std::endl;

  std::cout << "\nElement at index 2 of array 1: " << arr1[2] << std::endl;

  return 0;
}
