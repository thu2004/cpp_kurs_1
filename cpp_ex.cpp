#include <iostream>
using namespace std;

int main()
{
    int car_age;
    cout << "Hur gammal är din bil (jätte gammal) ? ";
    cin >> car_age;

    if (car_age <= 5) {
        cout << "Du borde skaffa helförsäkring" << endl;
    }
    else if (car_age > 5 && car_age < 25) {
        cout << "Du borde skaffa halvförsäkring" << endl;
    }
    else if (car_age >= 25) {
        cout << "Du borde skaffa veteransbilsförsäkring" << endl;
    }
}
