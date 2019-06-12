#include <iostream>
#include <string>

struct Parent {
    int i;
    std::string s;
};
struct Child : private Parent {
    double f;
    void setS(const std::string& new_s) {
        s = new_s;
    }
    const std::string getS() const {
        return s;
    }
};

int main(int argc, char* arv[]) {
    Parent p;
    Child c;
    p.i = 3;
    p.s = "hello";
    c.f = 3.5;
    std::string h = "hello";
    c.setS(h);
    h = "goodbye";
    std::cout << c.getS() << std::endl;
}
