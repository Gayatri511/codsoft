#include <iostream>
#include <cstdlib>  
#include <ctime>    
int main() {
    std::srand(std::time(0)); 
    int secretNumber = std::rand() % 100 + 1; 
    int guess;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100. Try to guess it!" << std::endl;

    do {
        std::cout << "Enter your guess: ";
        std::cin >> guess;

        if (guess > secretNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (guess < secretNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << secretNumber << std::endl;
        }
    } while (guess != secretNumber);

    return 0;
}
