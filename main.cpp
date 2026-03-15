#include <iostream>

int numberGame() {

  int levelDifficulty;
  std::cout << "Welcome to the Number Guessing Game!\n"
            << "I'm thinking of a number between 1 and 100.\n"
            << "You have 5 chances to guess the correct number.\n"
            << "\nPlease select the difficulty level:\n"
            << "1. Easy(10 chances)\n"
            << "2. Medium(5 chances)\n"
            << "3. Hard(3 chances)\n"
            << "\nEnter your choice: ";
  std::cin >> levelDifficulty;
  return 0;
}

int main() {

  numberGame();
  return 0;
}
