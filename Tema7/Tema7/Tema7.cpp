#include <iostream>
#include <vector>
#include <string>

class MyClass {
private:
    std::string name;
    std::vector<int> data;

public:
    MyClass(const std::string& n, int size) : name(n), data(size, 0) {
        std::cout << "Constructor standard apelat" << std::endl;
    }
        
    MyClass(const std::string& n) : MyClass(n, 10) {
        std::cout << "Constructor delegat apelat" << std::endl;
    }
        
    MyClass(MyClass&& other) noexcept : name(std::move(other.name)), data(std::move(other.data)) {
        std::cout << "Move constructor apelat" << std::endl;
    }
        
    void afisare() const {
        std::cout << "Name: " << name << ", Data: " << std::endl;
        for (int val : data) {
            std::cout << val << " " << std::endl;
        }
    }
};

class Point {
private:
    int x, y;

public:
    Point(int x_val = 0, int y_val = 0) : x(x_val), y(y_val) {}

    // Suprascriere operator +
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }
        
    void afisare() const {
        std::cout << "Point(" << x << " , " << y << ")" << std::endl;
    }
};

class Aplicatie {
private:
    int* value;

public:
    Aplicatie(int v) {
        value = new int(v);
        std::cout << "Constructor default apelat" << std::endl;
    }
    
    Aplicatie (const Aplicatie& other) {
        value = new int(*other.value);
        std::cout << "Copy constructor apelat" << std::endl;
    }

    void afisare() const {
        std::cout << "Value: " << *value << std::endl;
    }
        
    ~Aplicatie() {
        delete value;
    }
};

int main() {
    // 1 - MyClass
    MyClass obj1("Test", 5); // Constructorul standard
    obj1.afisare();

    MyClass obj2("AnotherTest"); // Constructorul delegat
    obj2.afisare();

    MyClass obj3 = std::move(obj1); // Move constructor
    obj3.afisare();

    // 2 - Point
    Point p1(4 , 5);
    Point p2(6 , 7);
    Point p3 = p1 + p2; // Suprascriere operator +
    p3.afisare();

    // 3 - Aplicatie
    Aplicatie obj4(10);
    obj4.afisare();

    Aplicatie obj5 = obj4; // Copy constructor
    obj5.afisare();

    return 0;
}
