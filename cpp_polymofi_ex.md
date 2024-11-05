**You:**

skriv en c++ klasser för demostrera pholymophy

* * *

**ChatGPT:**

Här är ett exempel på hur du kan använda polymorfi i C++ genom att definiera en basklass och några derivata klasser. Detta exempel använder polymorfi för att hantera olika typer av geometriska former.

### Exempel på Polymorfi i C++

```cpp
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
    std::vector<std::unique_ptr<Shape>> shapes;
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));

    // Iterera genom vektorn och demonstrera polymorfi
    for (const auto& shape : shapes) {
        demonstratePolymorphism(*shape);
        std::cout << "-------------------------" << std::endl;
    }

    return 0;
}
```

### Förklaring

* **Basklass (`Shape`)**: Detta är en abstrakt klass med två rena virtuella funktioner: `draw` och `area`. Det betyder att alla subklasser måste implementera dessa funktioner.
* **Subklasser (`Circle` och `Rectangle`)**: Dessa klasser ärver från `Shape` och implementerar sina egna versioner av `draw` och `area`. `Circle` beräknar area baserat på cirkelns formel, medan `Rectangle` beräknar area baserat på rektangelns formel.
* **Polymorfism**: Vi använder polymorfi när vi anropar `demonstratePolymorphism`-funktionen, som tar en referens till `Shape`. Eftersom `draw` och `area` är virtuella funktioner, kommer C++ att avgöra vilken version av funktionen som ska användas baserat på det faktiska objektets typ (antingen `Circle` eller `Rectangle`).

### Utdata

Körningen av programmet kommer att resultera i utdata som liknar följande:

```markdown
Drawing a Circle with radius 5
Area: 78.53975
-------------------------
Drawing a Rectangle with width 4 and height 6
Area: 24
-------------------------
```

Det här exemplet visar hur polymorfi i C++ gör att vi kan hantera objekt av olika typer (t.ex. `Circle` och `Rectangle`) genom en gemensam basklass (`Shape`) och anropa rätt implementering av virtuella funktioner.