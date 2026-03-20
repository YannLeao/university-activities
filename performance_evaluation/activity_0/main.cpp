#include <iostream>
#include <vector>
#include <limits>

int readInput() {
    int N;

    while (true) {
        std::cout << "Enter an positive integer N: ";
        std::cin >> N;

        if (std::cin.fail()) {
            std::cout << "Error: input must be an integer.\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (N <= 0) {
            std::cout << "Error: number must be a integer greater then 0";
        }

        return N;
    }
}

bool shouldExit() {
    int option;

    while (true) {
        std::cout << "\nEnter 0 to continue or 1 to exit: ";
        std::cin >> option;

        if (std::cin.fail()) {
            std::cout << "Error: input must be an integer (0 or 1).\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (option == 0) return false;
        if (option == 1) return true;

        std::cout << "Invalid option. Please enter 0 or 1.\n";
    }
}

std::vector<int> generatePrimes(int N) {
    std::vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    std::vector<int> primes;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

void printPrimes(const std::vector<int>& primes) {
    if (primes.empty()) {
        std::cout << "No prime numbers found.\n";
        return;
    }

    std::cout << "Prime numbers: ";

    for (size_t i = 0; i < primes.size(); i++) {
        std::cout << primes[i];
        if (i != primes.size() - 1) {
            std::cout << " - ";
        }
    }
    std::cout << std::endl;
}

int main() {
    while (true) {
        int N = readInput();

        std::vector<int> primes = generatePrimes(N);

        std::cout << "\nValue of N: " << N << std::endl;
        printPrimes(primes);
        std::cout << "Total primes: " << primes.size() << std::endl;

        if (shouldExit()) {
            std::cout << "Exiting program\n";
            break;
        }
    }

    return 0;
}