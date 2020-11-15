#include<iostream>
#include<string>

using namespace std;

enum class BeverageSize {
    TALL,
    GRANDE,
    VENTI
};

class Beverage {
public:
    string description = "Unknown Beverage";

    virtual string getDescription() {
        return description;
    }
    virtual double cost() {
        return 0;
    }

    BeverageSize _size = BeverageSize::TALL;

    virtual BeverageSize getSize() {
        return _size;
    }

};

class CondimentDecorator : public Beverage {

public:
    Beverage* beverage;
    string getDescription() {
        return beverage->description;
    }
};

class DarkRoast : public Beverage {
public:
    DarkRoast(BeverageSize size) {
        description = "Dark Roast Coffee";
        this->_size = size;
    }
    double cost() override {
        return .99;
    }
};

class Decaf : public Beverage {
public:
    Decaf(BeverageSize size) {
        description = "Decaf Coffee";
        this->_size = size;
    }

    double cost() override {
        return 1.05;
    }
};

class Espresso : public Beverage {
public:
    Espresso(BeverageSize size) {
        description = "Espresso";
        this->_size = size;
    }

    double cost() override {
        return 1.99;
    }
};

class HouseBlend : public Beverage {
public:
    HouseBlend(BeverageSize size) {
        description = "Houes Blend Coffee";
        this->_size = size;
    }


    double cost() override {
        return .89;
    }
};

class Milk : public CondimentDecorator {
public:
    Milk(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() override {
        return beverage->getDescription() + ", Milk";
    }
    BeverageSize getSize()  override {
        return beverage->getSize();
    }


    double cost() override {
        if (beverage->getSize() == BeverageSize::TALL) {
            return beverage->cost() + 0.20;
        }
        else if (beverage->getSize() == BeverageSize::GRANDE) {
            return beverage->cost() + 0.25;
        }
        else if (beverage->getSize() == BeverageSize::VENTI) {
            return beverage->cost() + 0.30;
        }
    }
};

class Mocha : public CondimentDecorator {
public:
    Mocha(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() override {
        return beverage->getDescription() + ", Mocha";
    }

    BeverageSize getSize() override {
        return beverage->getSize();
    }

    double cost() override {
        if (beverage->getSize() == BeverageSize::TALL) {
            return beverage->cost() + 0.10;
        }
        else if (beverage->getSize() == BeverageSize::GRANDE) {
            return beverage->cost() + 0.15;
        }
        else if (beverage->getSize() == BeverageSize::VENTI) {
            return beverage->cost() + 0.20;
        }
    }
};

class Soy : public CondimentDecorator {
public:
    Soy(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() override {
        return beverage->getDescription() + ", Soy";
    }

    BeverageSize getSize() override {
        return beverage->getSize();
    }

    double cost() override {
        if (beverage->getSize() == BeverageSize::TALL) {
            return beverage->cost() + 0.10;
        }
        else if (beverage->getSize() == BeverageSize::GRANDE) {
            return beverage->cost() + 0.15;
        }
        else if (beverage->getSize() == BeverageSize::VENTI) {
            return beverage->cost() + 0.20;
        }
    }
};

class Whip : public CondimentDecorator {
public:
    Whip(Beverage* beverage) {
        this->beverage = beverage;
    }

    string getDescription() override {
        return beverage->getDescription() + ", Whip";
    }

    BeverageSize getSize() override {
        return beverage->getSize();
    }

    double cost() override {
        if (beverage->getSize() == BeverageSize::TALL) {
            return beverage->cost() + 0.10;
        }
        else if (beverage->getSize() == BeverageSize::GRANDE) {
            return beverage->cost() + 0.15;
        }
        else if (beverage->getSize() == BeverageSize::VENTI) {
            return beverage->cost() + 0.20;
        }
    }
};

int main() {
    Beverage* beverage = new Espresso(BeverageSize::TALL);
    std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;
    delete beverage;

    Beverage* beverage2 = new DarkRoast(BeverageSize::GRANDE);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    std::cout << beverage2->getDescription() << " $" << beverage2->cost() << std::endl;
    delete beverage2;

    Beverage* beverage3 = new HouseBlend(BeverageSize::VENTI);
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    beverage3 = new Whip(beverage3);
    std::cout << beverage3->getDescription() << " $" << beverage3->cost() << std::endl;
    delete beverage3;
}