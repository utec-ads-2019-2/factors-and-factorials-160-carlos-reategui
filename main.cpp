#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    std::vector<unsigned int> primeNumbers = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
                                              71, 73, 79, 83, 89, 97};
    std::pair<unsigned int, unsigned int> primeCount[primeNumbers.size()];
    for (unsigned long i = 0; i < primeNumbers.size(); ++i) primeCount[i].first = primeNumbers[i];
    unsigned int number;
    while (std::cin >> number) {
        if (number == 0) break;
        for (unsigned long i = 0; i < primeNumbers.size(); ++i) primeCount[i].second = 0;
        for (unsigned int i = 2; i <= number; ++i) {
            unsigned int copyOfi = i, indexOfPrimeNumber = 0;
            while (copyOfi != 1) {
                if (copyOfi % primeCount[indexOfPrimeNumber].first == 0) {
                    ++primeCount[indexOfPrimeNumber].second;
                    copyOfi /= primeCount[indexOfPrimeNumber].first;
                } else ++indexOfPrimeNumber;
            }
        }
        unsigned int indexOfMax = 0;
        for (unsigned long i = 0; i < primeNumbers.size(); i++) if (primeCount[i].second != 0) indexOfMax = i;
        std::cout << std::setw(3) << number; std::cout << "! =";
        for (unsigned long i = 0; i <= indexOfMax; ++i) {
            if (i % 15 == 0 and i > 0) std::cout << std::endl << "      ";
            std::cout << std::setw(3) << primeCount[i].second;
        }
        std::cout << std::endl;
    }
    return 0;
}