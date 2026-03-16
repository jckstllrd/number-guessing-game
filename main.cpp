#include <cstdlib>
#include <iostream>

void getResults(int secret, int guess) { std::cout << "not quite the results"; }

int numberGame() {
  int secretNum = rand() % 101;
  std::cout << secretNum;
  int numOfGuesses;
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
  if (levelDifficulty == 1) {
    numOfGuesses = 10;
    std::cout << "Great! You have selected the Easy difficulty level.\nLet's "
                 "start the game!";
    while (numOfGuesses > 0) {
      int guess;
      std::cout << "Enter your guess: ";
      std::cin >> guess;
      getResults(secretNum, guess);
      numOfGuesses--;
    }
  } else if (levelDifficulty == 2) {
    numOfGuesses = 5;
    std::cout << "Great! You have selected the Medium difficulty level.\nLet's "
                 "start the game!";
    while (numOfGuesses > 0) {
      int guess;
      std::cout << "Enter your guess: ";
      std::cin >> guess;
      getResults(secretNum, guess);
      numOfGuesses--;
    }
  } else if (levelDifficulty == 3) {
    numOfGuesses = 3;
    std::cout << "Great! You have selected the Hard difficulty level.\nLet's "
                 "start the game!";
    while (numOfGuesses > 0) {
      int guess;
      std::cout << "Enter your guess: ";
      std::cin >> guess;
      getResults(secretNum, guess);
      numOfGuesses--;
    }
  }
  return 0;
}

int main() {

  numberGame();
  return 0;
}
