#include <iostream>
using namespace std;

int main() {
    //Fel i deklarationen av arrayen. Saknades en stängande klammer
    double temperatures[] = {98.6, 99.2, 97.9, 100.1, 98.8}; 
    
    double average = 0; //Variabeln "average" måste initieras, annars innehåller den skräpdata.

    //Felaktig loopbetingelse. Ändrade `i <= 4` till `i < 5` för att undvika out-of-bounds-access.
    for(int i = 0; i < 5; i++) {
        average += temperatures[i];
    }
    
    //Divisionen var felaktig - ändrade "average/4" till "average/5" eftersom det finns 5 element.
    cout << "Den genomsnittliga temperaturen är: " << average / 5 << endl;

    return 0; //Lägg till "return 0;" för god princip i main-funktionen.
}
