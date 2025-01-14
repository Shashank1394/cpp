#include <iostream>

int getNumber();
int evaluate(int x, int y, char op);

int main() {
  std::cout << "\nEnter 1st number: ";
  int x{getNumber()};
  std::cout << "Enter 2nd number: ";
  int y{getNumber()};

  char op{};
  std::cout << "Enter the operation (+, -, *, /): ";
  std::cin >> op;

  if (op == '+' || op == '-' || op == '*' || op == '/') {
    if (op == '/' && y == 0) {
      std::cout << "Error: You cannot divide by zero.";
      return 1;
    }
    int result = evaluate(x, y, op);
    std::cout << x << " " << op << " " << y << " = " << result;
  } else {
    std::cout << "Invalid operation. Please use one of (+, -, *, /).";
  }

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
  case '-':
    return x - y;
  case '*':
    return x * y;
  case '/':
    return x / y;
  default:
    std::cerr << "Unexpected operator. This should not occur.\n";
    return 0;
  }
}
