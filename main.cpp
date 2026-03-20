#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

class GameController {

public:
  int initialiseGame() {
    int userChoice;

    std::cout << "Welcome to the Number Guessing Game!\n\nPlease select one of "
                 "the options below:\n1.Start Game\n2. Highscores\n3. "
                 "Settings\n4. Exit\n";
    std::cin >> userChoice;

    if (userChoice == 1) {
      startGame();
    }

    return 0;
  }

  void startGame() {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 100);
    int secretNum = distrib(gen);
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
  }

  void getResults(int secret, int guess, int *pGuesses) {
    std::string relativeDiff =
        (guess == secret) ? "exact"
                          : ((guess < secret) ? "greater than" : "less than");

    if (relativeDiff == "exact") {
      std::cout << "Congratulations! You guessed the correct number with only "
                << *pGuesses << " attempts left.";
      *pGuesses = 0;
    } else {
      std::cout << "Incorrect! The number is " << relativeDiff << " " << guess
                << "\n";
    }
  }

  void startLevel(int level, int secret) {
    std::string levelName =
        (level == 1) ? "Easy" : ((level == 2) ? "Medium" : "Hard");
    int guesses =
        (levelName == "Easy") ? 10 : ((levelName == "Medium") ? 5 : 3);

    std::cout << "Great! You have selected the " << levelName
              << " difficulty level.\nLet's "
                 "start the game!\n";
    while (guesses > 0) {
      int guess;
      std::cout << "\nEnter your guess: ";
      std::cin >> guess;
      getResults(secret, guess, &guesses);
      guesses--;
    }
  }
};

int main() {

  auto start = std::chrono::high_resolution_clock::now();

  GameController gc;

  gc.initialiseGame();

  auto stop = std::chrono::high_resolution_clock::now();

  auto duration =
      std::chrono::duration_cast<std::chrono::seconds>(stop - start);
  std::cout << "\nIt has taken you " << duration.count()
            << " seconds to guess what the secret number was!" << std::endl;

  std::ofstream MyFile("filename.txt");

  MyFile << "Files can be tricky, but it is fun enough!";

  MyFile.close();

  return 0;
}
