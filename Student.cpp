#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Person {
protected:
  string name;
  int age;

public:
  Person() {
    cout << "Person()\n";
    name = "Unknown";
    age = 0;
  }

  Person(string name, int age) : name(name), age(age) {
    cout << "Person(string name, int age)\n";
  }

  Person(const Person& other) {
    cout << "Person(const Person& other)\n";
    name = other.name;
    age = other.age;
  }

  Person(Person&& other) noexcept {
    cout << "Person(Person&& other)\n";
    name = move(other.name); 
    age = other.age;

    other.name.clear();
    other.age = 0;
  }

  ~Person() {
    cout << "~Person()" << " | " << name << ", " << age << '\n';
  }

  string GetName() {
    return name;
  }

  int GetAge() {
    return age;
  }

  void Clear();
};

void Person::Clear() {
  name = "Deleted";
  age = -1;
}

class Student: public Person {
protected:
  string university;

public:
  Student() : Person() {
    cout << "Student()\n";
    university = "NoUniversity";
  }

  Student(string name, int age, string university) : Person(name, age) {
    cout << "Student(string name, int age, university)\n";
    this->university = university;
  }

  Student(const Student& other) {
    cout << "Student(const Student& other)\n";
    name = other.name;
    age = other.age;
    university = other.university;
  }

  Student(Student&& other) noexcept {
    cout << "Student(Student&& other)\n";
    name = move(other.name);
    age = other.age;
    university = other.university;

    other.name.clear();
    other.age = 0;
    other.university.clear();
  }

  ~Student() {
    cout << "~Student()" << " | " << name << ", " << age << ", " << university << '\n';
  }

  void ChangeUniversity(string new_university) {
    university = new_university;
  }
};

int main() {
  cout << "Указатель на потомка, переменная - предок:\n";
  Person *p = new Student("Danil", 20, "UUST");
  Student *p1 = new Student("Timur", 21, "MSU");

  p1->GetAge();
  /* p->ChangeUniveristy("BSU"); // CE */

  delete p;
  delete p1;

  /* cout << "Указатель на предка, переменная - потомок:\n";
  Student *p = new Person("Danil", 20, "UUST"); // CE */

  /* Person *p = new Person("Vanya", 15);
  Student *p1 = p; // CE */

  delete p;
  return 0;
}
