// Jonathan Standen

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Enum för att definiera bokningens status
enum Status {
    BEKRÄFTAD,  // Bokningen är bekräftad
    VÄNTANDE,   // Bokningen är väntande
    AVBOKAD     // Bokningen är avbokad
};
// Klass som representerar en Bokning
class Bokning {
public:
    int BokningsID;      // Unikt ID för bokningen
    string KundNamn;     // Kundens namn
    string KontaktInfo;  // Kundens kontaktinformation
    string Datum;        // Datum för bokningen
    Status status;       // Status för bokningen (bekräftad, väntande, avbokad)
    // Konstruktor för att skapa en bokning
    Bokning(int id, string namn, string kontakt, string dat, Status st)
        : BokningsID(id), KundNamn(namn), KontaktInfo(kontakt), Datum(dat), status(st) {}

    // Funktion för att visa information om bokningen
    void visaInfo() {
        // Skriv ut information om bokningen
        cout << "BokningsID: " << BokningsID << ", Kund: " << KundNamn
             << ", Datum: " << Datum << ", Status: ";
        // Beroende på status, skriv ut lämplig text
        switch (status) {
            case BEKRÄFTAD: cout << "Bekräftad"; break;
            case VÄNTANDE: cout << "Väntande"; break;
            case AVBOKAD: cout << "Avbokad"; break;
        }
        cout << endl;
    }
};
// Klass som hanterar bokningar
class BokningsHanterare {
private:
    vector<Bokning> bokningar;  // Lista som lagrar alla bokningar
public:
    // Metod för att skapa en bokning
    void skapaBokning(int id, string namn, string kontakt, string datum, Status st) {
        // Skapa ett nytt bokningsobjekt och lägg till det i vektorn
        bokningar.push_back(Bokning(id, namn, kontakt, datum, st));
    }
    // Metod för att visa alla bokningar
    void visaAllaBokningar() {
        cout << "Alla bokningar:" << endl;
        // Loop genom alla bokningar och skriv ut deras information
        for (auto& bokning : bokningar) {
            bokning.visaInfo();
        }
    }
    // Metod för att ta bort en bokning
    void taBortBokning(int id) {
        // Loop genom alla bokningar
        for (auto it = bokningar.begin(); it != bokningar.end(); ++it) {
            // Om vi hittar bokningen med det angivna ID:t, ta bort den
            if (it->BokningsID == id) {
                bokningar.erase(it);  // Ta bort bokningen från listan
                cout << "Bokning med ID " << id << " är borttagen." << endl;
                return;
            }
        }
        // Om bokningen inte hittades så skriver den hitttades inte
        cout << "Bokning med ID " << id << " kunde inte hittas." << endl;
    }
    // Metod för att söka efter en bokning baserat på ID
    void sokBokning(int id) {
        // Här Loopar genom alla bokningar
        for (auto& bokning : bokningar) {
            // Om koden hittar bokningen med det angivna ID:t, visar den informationen
            if (bokning.BokningsID == id) {
                bokning.visaInfo();
                return;
            }
        }
        // Om bokningen inte hittades
        cout << "Bokning med ID " << id << " hittades inte." << endl;
    }
};
// Huvudprogrammet
int main() {
    BokningsHanterare hanterare;  // Skapar ett objekt av BokningsHanterare
    // Här skapar några bokningar och lägger till dem i bokningshanteraren
    hanterare.skapaBokning(1, "Victor Davidsson", "victor@mail.com", "1999-12-10", VÄNTANDE);
    hanterare.skapaBokning(2, "Erik Carlsson", "erik@mail.com", "1993-3-12", BEKRÄFTAD);
    hanterare.skapaBokning(3, "John Carlsson", "john@mail.com", "2022-1-4", AVBOKAD);
    hanterare.skapaBokning(4, "Atlas Erikson", "atlas@mail.com", "2014-12-15", BEKRÄFTAD);
    hanterare.skapaBokning(5, "Dan Davidsson", "dan@mail.com", "2000-7-9", VÄNTANDE);
    hanterare.skapaBokning(6, "Jennifer Jacksson", "jennifer@mail.com", "2018-1-4", AVBOKAD);

    // Visa alla bokningar
    cout << "Alla bokningar innan borttagning:" << endl;
    hanterare.visaAllaBokningar();

    // Ta bort en bokning med ID 1
    hanterare.taBortBokning(1);

    // Visa alla bokningar igen efter borttagning
    cout << "\nAlla bokningar efter borttagning:" << endl;
    hanterare.visaAllaBokningar();

    // Sök efter bokning med ID 2 och visa information
    cout << "\nSöker efter bokning med ID 2:" << endl;
    hanterare.sokBokning(2);

    return 0;
}