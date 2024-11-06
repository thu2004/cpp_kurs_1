#include <iostream>
#include <vector>
#include <memory>

// Basklass som representerar en allmän geometrisk form
class Shape {
public:
    virtual void draw() const = 0;   // Ren virtuell funktion, gör Shape till en abstrakt klass
    virtual double area() const = 0; // Ren virtuell funktion för att beräkna arean
    virtual ~Shape() {}              // Virtuell destruktör
};

// En konkret subklass som representerar en cirkel
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() const override {
        std::cout << "Drawing a Circle with radius " << radius << std::endl;
    }

    double area() const override {
        return 3.14159 * radius * radius;
    }
};

// En konkret subklass som representerar en rektangel
class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    void draw() const override {
        std::cout << "Drawing a Rectangle with width " << width << " and height " << height << std::endl;
    }

    double area() const override {
        return width * height;
    }
};

// En funktion som tar en pekare till en Shape och anropar dess metoder
void demonstratePolymorphism(const Shape& shape) {
    shape.draw();
    std::cout << "Area: " << shape.area() << std::endl;
}

int main() {
    // Skapa en vektor med pekare till Shape-objekt
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));

    // Iterera genom vektorn och demonstrera polymorfi
    for (const Shape* shape : shapes) {
        demonstratePolymorphism(*shape);
        std::cout << "-------------------------" << std::endl;
    }

    for (const Shape* shape : shapes) {
        delete shape;
    }
    return 0;
}