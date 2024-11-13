#include <iostream> // Include the iostream library for input and output operations
using namespace std;

int main() {
    //Skapa parseobjekt och läs in filen
    YamlParser parser("file.yml");

    // Hämta data
    std::string name = parser.getString("name");
    std::string age = parser.getString("age");
    bool isMarried = parser.getBool("isMarried");
    bool hasCar = parser.getBool("hasCar");
    std::vector<std::string> items = parser.getList("items");

    // Skriv ut värden
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Is married: " <<std::boolalpha<< isMarried << std::endl;
    std::cout << name <<" has a car: " <<std::boolalpha<< hasCar << std::endl;
    std::cout << "Items:" << std::endl;
    for (const auto& item : items) {
        std::cout << "- " << item << std::endl;
    }

    return 0;
}
