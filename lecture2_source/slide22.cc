#include <iostream>

template<typename Elem>
class MyPair {
    Elem first_;
    Elem second_;
  public:
    MyPair(const Elem& first, const Elem& second)
    : first_(first), second_(second)
    {}
    const Elem& getFirst() const { return first_; }
    const Elem& getSecond() const { return second_; }
    void print() { std::cout << first_ << ", "
                             << second_ << std::endl; }
};

class MyOtherClass {
	MyOtherClass() { }
};

int main() {
	MyPair<int> pair1(1, 10);
	MyPair<std::string> pair2("Multicore", "Programming");
	//MyPair<MyOtherClass> pair3(MyOtherClass(), MyOtherClass());	// Why doesn't this work?
	pair1.print();
	pair2.print();
	//pair3.print();		// Why doesn't this work?
}
