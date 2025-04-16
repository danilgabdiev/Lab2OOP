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
    name = "Неизвестный";
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
    cout << "~Person()\n";
  }
};

int main() {
  Person p1;
  Person p2("Danil", 20);
  Person p3(p2);
  
  vector<Person> people;
  people.push_back(Person("Kirill", 25));

  return 0;
}
