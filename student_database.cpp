#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class Student {
private:
  string name{};
  int rollNumber{};
  string studentClass{};
  char division{};
  string dob{};
  string bloodGroup{};
  string contactAddress{};
  string telephoneNumber{};
  string drivingLicenseNo{};

public:
  Student() : rollNumber(0), division('A') {
    cout << "Default constructor called.\n";
  }

  Student(string name, int rollNumber, string studentClass, char division,
          string dob, string bloodGroup, string contactAddress,
          string telephoneNumber, string drivingLicenseNo)
      : name(name), rollNumber(rollNumber), studentClass(studentClass),
        division(division), dob(dob), bloodGroup(bloodGroup),
        contactAddress(contactAddress), telephoneNumber(telephoneNumber),
        drivingLicenseNo(drivingLicenseNo) {
    cout << "Parameterized constructor called.\n";
  }

  ~Student() { cout << "Destructor called for Student: " << name << '\n'; }

  void display() const {
    cout << "\n--- Student Details ---\n";
    cout << "Name: " << name << '\n';
    cout << "Roll Number: " << rollNumber << '\n';
    cout << "Student Class: " << studentClass << '\n';
    cout << "Division: " << division << '\n';
    cout << "Date of Birth: " << dob << '\n';
    cout << "Blood Group: " << bloodGroup << '\n';
    cout << "Contact Address: " << contactAddress << '\n';
    cout << "Telephone Number: " << telephoneNumber << '\n';
    cout << "Driving License: " << drivingLicenseNo << '\n';
  }

  friend void updateTelephone(Student &student,
                              const string &newTelephoneNumber);

  void validateRollNumber() const {
    if (rollNumber <= 0) {
      throw invalid_argument("Roll number must be greater than zero.");
    }
  }
};

void updateTelephone(Student &student, const string &newTelephoneNumber) {
  student.telephoneNumber = newTelephoneNumber;
  cout << "Telephone number updated for " << student.name << '\n';
}

int main() {
  try {
    Student student1("John Doe", 101, "10th", 'B', "2005-08-15", "O+",
                     "123 Elm Street", "1234567890", "DL12345");

    student1.display();
    student1.validateRollNumber();
    updateTelephone(student1, "9876543219");
    student1.display();

    Student student2;
    student2.display();
    cout << '\n';

  } catch (const exception &e) {
    cerr << e.what() << '\n';
  }

  return 0;
}
