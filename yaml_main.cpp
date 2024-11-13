#include <iostream> // Include the iostream library for input and output operations
using namespace std;
int main() {
    YamlParser parser("example.yaml"); // Create a YamlParser object and load the YAML file

    // Extract values from the YAML file
    string name = parser.getString("name"); // Get the string value for the key "name"
    int age = parser.getInt("age"); // Get the integer value for the key "age"
    vector<string> hobbies = parser.getStringList("hobbies"); // Get the list of strings for the key "items"

    // Print the extracted values
    cout << "Name: " << name << endl; // Print the name
    cout << "Age: " << age << endl; // Print the age
    cout << "Hobbies: " << endl; // Print the items header
    for (const auto& hobby : hobbies) { // Loop through each item in the list
        cout << "- " << hobby << endl; // Print each item
    }

    return 0; // Return 0 to indicate successful execution
}
