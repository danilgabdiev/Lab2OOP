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
};

int main() {
  Person *p1 = new Person;
  Person *p2 = new Person("Danil", 20);
  Person *p3 = new Person(*p2);
  
  vector<Person> people;
  Person* p4 = new Person;
  people.push_back(move(*p4));

  delete p1;
  delete p2;
  delete p3;
  delete p4;

  return 0;
}
