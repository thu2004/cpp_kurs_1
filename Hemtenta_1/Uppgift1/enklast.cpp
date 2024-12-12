#include <iostream>
#include <vector>
#include <climits> // För att använda INT_MIN
using namespace std;

int main() {
    vector<int> nummer; // Här sparar jag alla nummer
    int tal;

    // Läs in tal från användaren
    cout << "Hej! Skriv in heltal (obs! mata in 0 för att avsluta):" << endl;

    while (true) {
        cin >> tal;

        // koden ska kontrollera om inmatningen är ogiltig
        if (cin.fail()) {
            cin.clear(); // rensa felstatus
            cin.ignore(1000, '\n'); // ignorera felaktig inmatning
            cout << "obs!! ogiltig inmatning! Försök igen tack: ";
            continue;
        }

        if (tal == 0) { // det kommer att avsluta när användaren matar in talet 0.
            break;
        }

        nummer.push_back(tal); // lägg till talet i listan
    }

    // Kontrollera om det finns några nummer att bearbeta
    if (nummer.empty()) {
        cout << "Inga giltiga tal matades in." << endl;
        return 0;
    }

    // här är variabler för beräkningar
    int produkt = 1; // För produkten av positiva tal.
    int antal_jämna = 0; // För att räkna jämna tal.
    int antal_udda = 0; // För att räkna udda tal.
    int största = INT_MIN; // Startvärde för största talet.
    int näst_största = INT_MIN; // Startvärde för näst största talet.

    // bearbeta talen i listan
    for (int n : nummer) {
        // Kolla om talet är positivt
        if (n > 0) {
            produkt *= n; // här multiplicera positiva tal.
        }

        // kolla om talet är jämnt eller udda
        if (n % 2 == 0) {
            antal_jämna++; // öka räknaren för jämna.
        } else {
            antal_udda++; // öka räknaren för udda
        }

        // hitta största och näst största talen
        if (n > största) {
            näst_största = största;
            största = n;
        } else if (n > näst_största && n != största) {
            näst_största = n;
        }
    }

    // Hantera fallet om det inte finns ett näst största tal
    if (nummer.size() == 1) {
        cout << " tyvär det finns inget näst största tal eftersom bara ett tal matades in." << endl;
    } else if (näst_största == INT_MIN) {
        cout << "det finns inget näst största tal." << endl;
    } else {
        cout << "det näst största talet är: " << näst_största << endl;
    }

    // Skriv ut resultaten :)
    cout << "produkten av alla positiva tal är: " << produkt << endl;
    cout << "antal jämna tal är : " << antal_jämna << endl;
    cout << "antal udda tal är: " << antal_udda << endl;

    return 0;
}
