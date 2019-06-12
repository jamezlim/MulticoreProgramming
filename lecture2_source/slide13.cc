#include <iostream>
#include <string>

class Parent {
  public:
    Parent() {
        printName();
    }
    virtual void printName() {
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
Child* child = new Child;
    child->printName();
    Parent* parent = (Parent*)child;
    parent->printName();
}
