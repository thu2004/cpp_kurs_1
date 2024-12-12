/* #include <iostream>
using namespace std; */

/* This is how I would improve the code:
int main()
{
    double temperatures[] = {98.6, 99.2, 97.9, 100.1, 98.8}; // Added missing bracket
    double total = 0.0;                                    // Added a value to the variable to avoid running into undefined behavior

    for (int i = 0; i < sizeof(temperatures) / sizeof(temperatures[0]); i++)
    { // Changed the loop to iterate over the array regardless of its size
        total += temperatures[i];
    }

    cout << "The average temperature is: " << total / (sizeof(temperatures) / sizeof(temperatures[0])) // Changed the division to use the size of the array to match the iteration of the for loop. we can now add multiple values without crashing the program.
         << endl;                                                                                        // added endline for better readability of the output
}

*/

/* Syntax fix */

#include <iostream>
using namespace std;

int main()
{
    double temperatures[] = {98.6, 99.2, 97.9, 100.1, 98.8}; // Added missing bracket
    double total = 0.0;                                    // Added a value to the variable to avoid running into undefined behavior
// Changed variable name to total to better reflect what the variable is used for
    for (int i = 0; i <= 4; i++)
    {
        total += temperatures[i];
    }

    cout << "The average temperature is: " << total / 5; // Changed the number here to divide by the correct amount of values in the array
}
