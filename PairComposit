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

class Pair {
protected:
  Person* p1;
  Person* p2;

public:
  Pair() {
    cout << "Pair()\n";
    p1 = new Person;
    p2 = new Person;
  }

  Pair(string name1, int age1, string name2, int age2) {
    cout << "Pair(string name1, int age1, string name2, int age2)\n";
    p1 = new Person(name1, age1);
    p2 = new Person(name2, age2);
  }

  Pair(const Pair& other) {
    cout << "Pair(const Pair& other)\n";
    p1 = new Person(*other.p1);
    p2 = new Person(*other.p2);
  }

  Pair(Pair&& other) noexcept {
    cout << "Pair(Pair&& other)\n";
    p1 = other.p1;
    p2 = other.p2;

    other.p1 = nullptr;
    other.p2 = nullptr;
  }

  ~Pair() {
    cout << "~Pair()";
    delete p1;
    delete p2;
  }
};

int main() {
  Pair *p1 = new Pair;
  Pair* p2 = new Pair(*p1);

  delete p1;
  delete p2;
  return 0;
}
