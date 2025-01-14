#include <iostream>

int getNumber();
int evaluate(int x, int y, char op);

int main() {
  std::cout << "\nEnter 1st number: ";
  int x{getNumber()};
  std::cout << "Enter 2nd number: ";
  int y{getNumber()};

  char op{};
  std::cout << "Enter the operation (+,-,*,/): ";
  std::cin >> op;

  int result{};
  if (op == '+' || op == '-' || op == '*' || op == '/') {
    result = evaluate(x, y, op);
  } else {
    std::cout << "Invalid operation";
    return 0;
  }

  std::cout << x << " " << op << " " << y << " = " << result;
  return 0;
}

int getNumber() {
  int x{};
  std::cin >> x;
  return x;
}

int evaluate(int x, int y, char op) {
  switch (op) {
  case '+':
    return x + y;
    break;
  case '-':
    return x - y;
    break;
  case '*':
    return x * y;
    break;
  case '/':
    return x / y;
    break;
  }
  return 0;
}
