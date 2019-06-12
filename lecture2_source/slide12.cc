#include <iostream>
#include <string>

class Parent {
  public:
    Parent() {
        printName();
    }
    void printName() {
      std::cout << "Parent" << std::endl;
    }
};

class Child : public Parent {
  public:
    void printName() {
      std::cout << "Child" << std::endl;
    }
};

int main() {
    Parent parent;
    Child child;
    parent.printName();
    child.printName();
}
