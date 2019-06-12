#include <iostream>
#include <string>

class Foo {
    int width_, height_;
  public:
    Foo();
    Foo(const int width, const int height);
    void printInfo();
    ~Foo();
};

Foo::Foo() {
    std::cout << "No-arg constructor" << std::endl;
}
Foo::Foo(const int width, const int height) {
    std::cout << "2-arg constructor" << std::endl;
    width_ = width;
    height_ = height;
}
void Foo::printInfo() {
    std::cout << width_ << ", " << height_ << std::endl;
}

Foo::~Foo() {
    printInfo();
    std::cout << "I was destroyed" << std::endl;
}

int main(int argc, char* arv[]) {
    {
        Foo foo1; // uses Foo(); constructor
    }
    Foo foo2(32, 16); // uses Foo(int, int);
}