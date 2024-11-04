#include <cstring>
#include <iostream>

class Car {
 public:
  char* brand;  // Dynamiska minnesallokering
  char* model;
  int year;
  double milage;

    // Konstruktor
  Car(const char* brand, const char* model, int year, double milage) {
    this->brand = new char[strlen(brand) + 1];
    strcpy(this->brand, brand);
    this->model = new char[strlen(model) + 1];
    strcpy(this->model, model);
    this->year = year;
    this->milage = milage;
  }
    // Koperiongskonstruktor
  /*
  Car(const Car& other) {
    this->brand = new char[strlen(other.brand) + 1];
    strcpy(this->brand, other.brand);
    this->model = new char[strlen(other.model) + 1];
    strcpy(this->model, other.model);
    this->year = other.year;
    this->milage = other.milage;
  }
  */

  // Functions
  void drive(double distance) { this->milage += distance; }
  void displayInfo() {
    std::cout << "Brand: " << this->brand << std::endl;
    std::cout << "Model: " << this->model << std::endl;
    std::cout << "Year: " << this->year << std::endl;
    std::cout << "Milage: " << this->milage << std::endl;
  }
  int getYear() { return this->year; }
  double getMilage() { return this->milage; }


// Destructor
  //~Car() {
  //  delete[] brand;
  //  delete[] model;
  //}
};

int main() {

    // Create object and set properties
  Car myCar("Batman", "Batmobile", 1939, 100000);

    // Call functions
  myCar.displayInfo();
  myCar.drive(1337);


    // Get properties from object
  std::cout << "Year: " << myCar.getYear() << std::endl;
  std::cout << "Mileage: " << myCar.getMilage() << std::endl;

  // Copy with copyconstructor
  Car carCopy = myCar;

  // Call drive function on copy
  carCopy.drive(100);

  // Print properties of copy
  std::cout << "Mileage: " << carCopy.getMilage() << std::endl;

  return 0;
}
