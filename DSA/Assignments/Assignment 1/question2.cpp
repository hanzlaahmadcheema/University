#include <iostream>
#include <cmath>
using namespace std;

class Shape {
public:
    virtual float getArea() = 0; 
    virtual ~Shape() {} 
};

class Circle : public Shape {
private:
    float radius;
public:
    Circle(float r) : radius(r) {}

    float getArea() override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    float length, width;
public:
    Rectangle(float l, float w) : length(l), width(w) {}

    float getArea() override {
        return length * width;
    }
};

int main() {
    const int size = 2;
    Shape* shapes[size];

    shapes[0] = new Circle(5.5);         
    shapes[1] = new Rectangle(4.0, 6.0);  

    for (int i = 0; i < size; i++) {
        cout << "Area of Shape " << i + 1 << " = " << shapes[i]->getArea() << endl;
    }

    
    for (int i = 0; i < size; i++) {
        delete shapes[i];
    }

    return 0;
}
