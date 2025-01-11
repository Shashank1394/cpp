#include <iostream>

int getValueFromUser() {
  int input{};
  std::cin >> input;

  return input;
}

void printAddtion(int x, int y) {
  std::cout << x << " + " << y << " = " << x + y;
}

int main() {
  std::cout << "Enter a number: ";
  int x{getValueFromUser()};

  std::cout << "Enter another number: ";
  int y{getValueFromUser()};

  printAddtion(x, y);

  return 0;
}
