#include <iostream>
#include <vector>
#include <limits>
#include <algorithm> // För sortering och unique

// Funktion som beräknar produkten av alla positiva tal
double calculatePositiveProduct(const std::vector<int> &numbers)
{
    double product = 1;
    bool foundPositive = false;

    // Gå igenom alla tal i vektorn
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] > 0)
        {
            product *= numbers[i]; // Multiplicera om talet är positivt
            foundPositive = true;
        }
    }

    // Om inga positiva tal hittades, returnera 0
    return foundPositive ? product : 0;
}

// Funktion som räknar antalet jämna och udda tal
std::pair<int, int> countEvenAndOdd(const std::vector<int> &numbers)
{
    int evenCount = 0, oddCount = 0;

    // Gå igenom alla tal och räkna jämna och udda
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        if (numbers[i] % 2 == 0 && numbers[i] != 0)
        {
            ++evenCount; // Räkna jämna tal
        }
        else if (numbers[i] % 2 != 0)
        {
            ++oddCount; // Räkna udda tal
        }
    }

    // Returnera resultatet som ett std::pair
    return std::make_pair(evenCount, oddCount);
}

// Funktion som hittar det näst största talet i en vektor
int findSecondLargest(const std::vector<int> &numbers)
{
    if (numbers.size() < 2)
    {
        return 0; // Om mindre än 2 tal finns, returnera 0
    }

    // Kopiera och sortera vektorn i fallande ordning
    std::vector<int> uniqueNumbers = numbers;
    std::sort(uniqueNumbers.begin(), uniqueNumbers.end(), std::greater<int>());
    uniqueNumbers.erase(std::unique(uniqueNumbers.begin(), uniqueNumbers.end()), uniqueNumbers.end());

    // Om det finns minst två unika tal, returnera det näst största
    return uniqueNumbers.size() > 1 ? uniqueNumbers[1] : 0;
}

// Main-funktionen där inmatning sker
int main()
{
    std::vector<int> numbers; // Vektor för att lagra inmatade tal
    int input;

    std::cout << "Mata in heltal (0 för att avsluta):\n";
    // Loop för att ta emot inmatning tills användaren matar in 0
    while (true)
    {
        std::cin >> input;

        // Inmatningsvalidering
        if (std::cin.fail())
        {
            std::cin.clear();                                                   // Återställ cin-flaggorna
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Rensa bufferten
            std::cout << "Ogiltig inmatning. Försök igen:\n";
            continue;
        }
        if (input == 0)
            break;                // Avsluta inmatning om användaren skriver 0
        numbers.push_back(input); // Lägg till det giltiga talet i vektorn
    }

    // Anropa funktionerna för att beräkna resultaten
    double positiveProduct = calculatePositiveProduct(numbers);
    std::pair<int, int> counts = countEvenAndOdd(numbers);
    int secondLargest = findSecondLargest(numbers);

    // Skriv ut resultaten
    std::cout << "Produkten av alla positiva tal: " << positiveProduct << "\n";
    std::cout << "Antal jämna tal: " << counts.first << "\n";
    std::cout << "Antal udda tal: " << counts.second << "\n";
    std::cout << "Det näst största talet: " << secondLargest << "\n";

    return 0;
}
