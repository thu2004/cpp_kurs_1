#include <iostream>
using namespace std;

// Klass som representerar en bokning
class Booking {
public:
    int bokningsID; // Unikt ID för bokningen
    string kundNamn; // Kundens namn
    string kontaktInfo; // Kontaktinformation för kunden
    string datum; // Datum för bokningen
    string status; // Status på bokningen (ex. "Bekräftad", "Avbokad")

    // Konstruktor för att skapa en bokning med specificerade värden
    Booking(int bokningsID, string kundNamn, string kontaktInfo, string datum, string status) {
        this->bokningsID = bokningsID;
        this->kundNamn = kundNamn;
        this->kontaktInfo = kontaktInfo;
        this->datum = datum;
        this->status = status;
    }

    // Metod för att visa detaljer om bokningen
    void displayInfo() const {
        cout <<"******************************"<<endl; 
        cout << "BookingsID: " << bokningsID << endl;
        cout << "Kundens namn: " << kundNamn << endl;
        cout << "Kontakt information: " << kontaktInfo << endl;
        cout << "Datum: " << datum << endl;
        cout << "Status: " << status << endl;
        cout << "******************************" << endl;
    }
};

// Klass för att hantera bokningar
class Bokningshanterare {
private:
    Booking** bokningar; // Dynamisk array för att lagra pekare till bokningar
    int aktuellaBokningar; // Antal aktuella bokningar
    int maxBokningar; // Maximalt antal bokningar innan arrayen behöver expanderas

public:
    // Konstruktor som initierar bokningshanteraren med ett standard- eller angivet maxantal bokningar
    Bokningshanterare(int initialMaxBokningar = 5) {
        maxBokningar = initialMaxBokningar;
        bokningar = new Booking*[maxBokningar]; // Allokerar minne för bokningar
        aktuellaBokningar = 0;
    }

    // Destruktor för att frigöra allokerat minne
    ~Bokningshanterare() {
        for (int i = 0; i < aktuellaBokningar; ++i) {
            delete bokningar[i]; // Frigör varje bokning
        }
        delete[] bokningar; // Frigör arrayen
    }

    // Skapar och lägger till en ny bokning
    void skapaBokning(int id, string namn, string kontakt, string datum, string status) {
        if (aktuellaBokningar == maxBokningar) {
            cout << "Ingen plats för fler bokningar. Expanderar..." << endl;
            expanderaBokningar(); // Ökar storleken på arrayen om nödvändigt
        }

        bokningar[aktuellaBokningar++] = new Booking(id, namn, kontakt, datum, status);
    }

    // Tar bort en bokning med ett specifikt ID
    void taBortBokning(int id) {
        for (int i = 0; i < aktuellaBokningar; ++i) {
            if (bokningar[i]->bokningsID == id) {
                delete bokningar[i]; // Frigör minnet för bokningen
                
                // Flytta de efterföljande bokningarna för att fylla gapet
                for (int j = i; j < aktuellaBokningar - 1; ++j) {
                    bokningar[j] = bokningar[j + 1];
                }

                aktuellaBokningar--; // Minska räkningen för aktuella bokningar
                cout << "Bokning med ID " << id << " har tagits bort." << endl;
                return;
            }
        }
        cout << "Bokning med ID " << id << " hittades inte!" << endl;
    }

    // Söker efter en bokning med ett specifikt ID och returnerar en pekare till den
    Booking* sokBokning(int id) {
        for (int i = 0; i < aktuellaBokningar; ++i) {
            if (bokningar[i]->bokningsID == id) {
                return bokningar[i];
            }
        }
        cout << "Bokning med ID " << id << " hittades inte!" << endl;
        return nullptr; // Returnerar nullpekare om bokningen inte hittas
    }

    // Visar information om alla bokningar
    void visaAllaBokningar() const {
        if (aktuellaBokningar == 0) {
            cout << "Inga bokningar tillgängliga." << endl;
            return;
        }

        for (int i = 0; i < aktuellaBokningar; ++i) {
            bokningar[i]->displayInfo();
        }
    }

private:
    // Expanderar storleken på arrayen när det behövs
    void expanderaBokningar() {
        maxBokningar *= 2; // Fördubblar kapaciteten
        Booking** nyaBokningar = new Booking*[maxBokningar]; // Skapar en ny, större array

        // Kopierar över befintliga bokningar till den nya arrayen
        for (int i = 0; i < aktuellaBokningar; ++i) {
            nyaBokningar[i] = bokningar[i];
        }

        delete[] bokningar; // Frigör minnet för den gamla arrayen
        bokningar = nyaBokningar; // Pekar om till den nya arrayen
    }
};

int main() {
    Bokningshanterare bokningshanterare; // Skapar en instans av bokningshanteraren

    // Skapar några bokningar
    bokningshanterare.skapaBokning(1, "Chi Thu Lee", "chithu@example.com", "2024-12-10", "Bekräftad");
    bokningshanterare.skapaBokning(2, "Linus Åkesson", "linusakesson@example.com", "2024-12-15", "Väntande");
    bokningshanterare.skapaBokning(3, "Gül Baran", "gulbaran@example.com", "2024-12-20", "Avbokad");

    // Visar alla bokningar
    cout << "Alla bokningar:" << endl;
    bokningshanterare.visaAllaBokningar();

    // Söker efter en specifik bokning
    cout << "Söker efter bokning med ID 2:" << endl;
    Booking* hittadBokning = bokningshanterare.sokBokning(2);
    if (hittadBokning) {
        hittadBokning->displayInfo();
    }

    // Tar bort en bokning
    cout << "Tar bort bokning med ID 3:" << endl;
    bokningshanterare.taBortBokning(3);

    // Visar alla bokningar igen efter borttagning
    cout << "Alla bokningar efter borttagning:" << endl;
    bokningshanterare.visaAllaBokningar();

    return 0;
}
