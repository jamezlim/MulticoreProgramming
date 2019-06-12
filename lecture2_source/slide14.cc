#include <iostream>

struct Animal {
    unsigned int legs;
    double height;
    double mass;

	virtual void info() const {
		std::cout << "Animal has " << legs << " legs" << std::endl;
	}
};
struct Elephant : public Animal {
    double trunk_length;
};
struct Bird : public Animal {
    double wingspan;
    bool migratory;
};
struct Swallow : public Bird {
    enum {
        AFRICAN,
        EUROPEAN
    } locale;

	const std::string localeToString() const {
		if (locale == AFRICAN) {
			return "African";
		} else if (locale == EUROPEAN) {
			return "European";
		} else {
			return "(unknown)";
		}
	}

	void info() const {
		Animal::info();
		std::cout << "This is a " << localeToString() << " swallow" << std::endl;
	}
};

int main(int argc, char* argv[]) {
	Swallow unladen_swallow;
	unladen_swallow.legs = 2;
	unladen_swallow.locale = Swallow::AFRICAN;
	unladen_swallow.info();

	return 0;
}
