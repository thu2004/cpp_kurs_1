/*
Uppgift 2 (G - 10 poäng)

Felsök och åtgärda följande kod. Förklara varje fel du hittar och hur du åtgärdade det: 

#include <iostream>
using namespace std;

int main() {
    double temperatures[] = {98.6, 99.2, 97.9, 100.1, 98.8;
    double average;
    
    for(int i = 0; i <= 4; i++) {
        average += temperatures[i];
    }
    
    cout << "The average temperature is: " << average/4;
}
*/

#if 0
// given code
#include <iostream>
using namespace std;

int main() {
	// Error: missing } brace at end of array
    double temperatures[] = {98.6, 99.2, 97.9, 100.1, 98.8;
    // Error: Undefined Behavior! variable is not initialized!
    double average;
    
    // Error: if the number of temperatures changes this loop will not work correctly.
    for(int i = 0; i <= 4; i++) {
        average += temperatures[i];
    }
    
    // Error: missing terminating newline ('\n') or std::endl at end of output.
    // Error: math is wrong. there are 5 temperatures, not 4.
    // Error: math is still wrong, dividend is a whole number and not a double.
    // Error: no point in doing the math in the printout - we will store it in result.
    cout << "The average temperature is: " << average/4;
    // Error: no return 0
}
#endif

// updated code
#include <iostream>
using namespace std;

int main() {
    double temperatures[] = { 98.6, 99.2, 97.9, 100.1, 98.8 };
    double average = 0.0;
    
    int num_temps = (int)(sizeof(temperatures) / sizeof(temperatures[0]));
    for(int i = 0; i < num_temps; i++) {
        average += temperatures[i];
    }
    
    const double result = average / (double)num_temps;
    
    cout << "The average temperature is: " << result << endl;
    return 0;
}
