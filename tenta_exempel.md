
Instruktioner: Du får använda din lärobok, anteckningar och onlinedokumentation (men inte AI-verktyg eller kodkomplettering).

## Del 1: Grundnivå
### Fråga 1
Skapa ett program som hanterar en enkel betygskalkylator för studenter:
- Skapa en klass som heter `Student` med attribut för namn och tre provresultat
- Inkludera metoder för att:
  - Beräkna genomsnittspoäng
  - Avgöra om studenten är godkänd (genomsnitt >= 60)
  - Visa all studentinformation
- Skapa ett huvudprogram som skapar minst två Student-objekt och demonstrerar all funktionalitet

### Fråga 2
Skriv ett program som läser in tal från användaren tills de matar in -1. Programmet ska:
- Lagra talen i en vektor
- Beräkna och visa:
  - Summan av alla tal
  - Medelvärdet av talen
  - Det största och minsta inmatade talet

### Fråga 3
Felsök och åtgärda följande kod. Förklara varje fel du hittar och hur du åtgärdade det:
```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[] = {1, 2, 3, 4, 5);
    int sum;
    
    for(int i = 0; i <= 5; i++) {
        sum += numbers[i];
    }
    
    cout << "The average is: " << sum/5.0;
}
```

## Del 2: Mellannivå
### Fråga 2
Skriv ett program som implementerar en enkel telefonbok:
- Använd en map för att lagra namn och telefonnummer
- Implementera funktioner för att:
  - Lägga till nya kontakter
  - Ta bort kontakter
  - Söka efter en kontakt
  - Visa alla kontakter i alfabetisk ordning
- Inkludera inmatningsvalidering och felhantering

## Del 3: Avancerad nivå
### Fråga 1
Skapa en mallbaserad datastruktur som implementerar en enkel Kö med följande krav:
- Använd en mallklass för att få den att fungera med alla datatyper
- Implementera följande metoder:
  - enqueue (lägg till i slutet)
  - dequeue (ta bort från början)
  - peek (visa första elementet)
  - isEmpty
  - size
- Inkludera lämplig felhantering för tomma kö-operationer
- Skapa ett omfattande testprogram som:
  - Testar kön med minst två olika datatyper
  - Demonstrerar all funktionalitet
  - Inkluderar kantfall
  - Hanterar och visar fel på rätt sätt
- Skriv kommentarer som förklarar dina implementeringsval

## Inlämningsriktlinjer:
1. Varje svar ska vara i en separat .cpp-fil med lämpligt namn
2. Inkludera kommentarer som förklarar din kod
3. Alla program måste kompilera utan fel

## Obs:
- Alla program måste innehålla lämpliga headers
- Använd korrekt indentering och namnkonventioner
- Inkludera inmatningsvalidering där det är lämpligt
- Program ska hantera ogiltig inmatning på ett smidigt sätt