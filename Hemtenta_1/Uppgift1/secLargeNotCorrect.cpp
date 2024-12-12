#include <iostream>
#include <vector>
#include <algorithm>
// ugt1 

void allContained(const std::vector<int> numbers) {
    std::cout << "All numbers: ";
    for (int number : numbers) {
        std::cout << number << " " ; 
    }
    std::cout << std::endl;
}

void productNum(const std::vector<int> numbers) {
    int sum = 1; // initiarise 1 for the first number does not become 0;
    for (int number : numbers) {
        sum *= number;
    }
    std::cout << "Product of the all numbers: " << sum << " " << std::endl;   
}

void sizeOfEvenNum(const std::vector<int> numbers) {
    std::vector<int> evenNums;
    for (int number : numbers) {
        if (number % 2 == 0) {
            evenNums.push_back(number);
        }
    }
    std::cout << "Amount of the even numbers: " << evenNums.size() << std::endl;
}

void sizeOfOddNum(const std::vector<int> numbers) {
    std::vector<int> oddNums;
    for (int number : numbers) {
        if (number % 2 != 0) {
            oddNums.push_back(number);
        }
    }
    std::cout << "Amount of the odd numbers: " << oddNums.size() << std::endl;
}

void secLargeNum(std::vector<int>& numbers) {
    //to sort bigger to smaller 
    std::sort(numbers.rbegin(), numbers.rend());

    if (numbers.size() >= 2) {
        std::cout << "The second largest number: " << numbers[1] << std::endl;        
    } else {
        std::cout << "Too few elements contained: " << std::endl;
    }
}


int main() {
    std::vector<int> numbers;    
    int userInput;
    bool running = true;

    // intro
    std::cout << "Give me a hale number to contain in my container\n (Finish to contain: 0 ): \n";
    
    // Loop for userinput untill user clicks 0
    while(running) {

        std::cin >> userInput;

        if (userInput == 0) {
            std::cout << "You have contained all your numbers.\n";
            running = false;
            break;
        } else if (userInput > 0) {
            numbers.push_back(userInput);
        } else {
            // controll invalid input for various data types
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "invalid input!\n" << std::endl;
        }

    }
    std::cout << std::endl;

    allContained(numbers);
    productNum(numbers);
    sizeOfEvenNum(numbers);
    sizeOfOddNum(numbers);
    secLargeNum(numbers);


    std::cout << std::endl;
    std::cout << "Thanks for using!";

    return 0;
}