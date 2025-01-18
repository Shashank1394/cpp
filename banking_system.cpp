#include <iomanip> // For fixed and setprecision
#include <iostream>
#include <limits>
#include <string>

class BankAccount {
private:
  int accountNumber;
  std::string accountHolderName;
  float balance;

public:
  // Constructor to initialize account details
  BankAccount(int accountNumber, const std::string &accountHolderName,
              float balance)
      : accountNumber(accountNumber), accountHolderName(accountHolderName),
        balance(balance) {
    std::cout << "\nAccount created successfully with initial balance: $"
              << std::fixed << std::setprecision(2) << balance << std::endl;
  }

  // Method to deposit money
  void deposit(float depositAmount) {
    if (depositAmount == 0) {
      std::cout << "\nError: Deposit amount cannot be $0.\n";
    } else if (depositAmount > 0) {
      balance += depositAmount;
      std::cout << "\n$" << std::fixed << std::setprecision(2) << depositAmount
                << " deposited successfully. New balance: $" << balance
                << std::endl;
    } else {
      std::cout << "\nError: Deposit amount must be greater than $0.\n";
    }
  }

  // Method to withdraw money
  void withdraw(float withdrawAmount) {
    if (withdrawAmount > balance) {
      std::cout << "\nError: Insufficient balance. Current balance: $"
                << std::fixed << std::setprecision(2) << balance
                << ", attempted withdrawal: $" << withdrawAmount << ".\n";
    } else if (withdrawAmount > 0) {
      balance -= withdrawAmount;
      std::cout << "\n$" << std::fixed << std::setprecision(2) << withdrawAmount
                << " withdrawn successfully. Remaining balance: $" << balance
                << std::endl;
    } else {
      std::cout << "\nError: Withdrawal amount must be greater than $0.\n";
    }
  }

  // Method to display account details
  void displayDetails() const {
    std::cout << "\nAccount Number: " << accountNumber << std::endl;
    std::cout << "Holder's Name: " << accountHolderName << std::endl;
    std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance
              << std::endl;
  }
};

class SavingsAccount {};

float getAmount() {
  float amount;
  if (!(std::cin >> amount) || amount <= 0) {
    std::cout << "\nInvalid amount. Please enter a positive number.\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return amount;
}

int main() {
  BankAccount account(101, "John Doe", 100.0f);

  int choice;
  float amount;

  do {
    std::cout << "\n--------------------------";
    std::cout << "\n      Banking System      ";
    std::cout << "\n--------------------------";
    std::cout << "\n1.Deposit \n2.Withdraw \n3.Display Details \n4.Exit ";
    std::cout << "\nEnter your choice: ";
    if (!(std::cin >> choice)) {
      std::cout << "\nInvalid input. Please enter a valid number.\n";
      std::cin.clear(); // Clear error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                      '\n'); // Discard invalid input
      continue;
    }

    switch (choice) {
    case 1:
      std::cout << "\nEnter deposit amount: $";
      amount = getAmount();
      account.deposit(amount);
      break;

    case 2:
      std::cout << "\nEnter withdrawal amount: $";
      amount = getAmount();
      account.withdraw(amount);
      break;

    case 3:
      std::cout << "\nAccount details:";
      account.displayDetails();
      break;

    case 4:
      std::cout << "\nExiting the banking system. Thank You!\n";
      break;

    default:
      std::cout << "\nInvalid choice. Please try again.\n";
    }
  } while (choice != 4);
}
