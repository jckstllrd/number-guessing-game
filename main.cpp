#include <cstdlib>
#include <iostream>
#include <string>

void getResults(int secret, int guess) { std::cout << "not quite the results"; }

void startLevel(int level, int secret) {
  std::string levelName =
      (level == 1) ? "Easy" : ((level == 2) ? "Medium" : "Hard");
  int guesses = (levelName == "Easy") ? 10 : ((levelName == "Medium") ? 5 : 3);

  std::cout << "Great! You have selected the " << levelName
            << " difficulty level.\nLet's "
               "start the game!";
  while (guesses > 0) {
    int guess;
    std::cout << "Enter your guess: ";
    std::cin >> guess;
    getResults(secret, guess);
    guesses--;
  }
}

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

  startLevel(levelDifficulty, secretNum);

  return 0;
}

int main() {

  numberGame();
  return 0;
}
