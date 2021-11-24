#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty) {
// Print welcome message to the terminal
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty << " secure server room.";
    std::cout << "\nYou need to enter the correct codes to continue.\n\n";
}

bool PlayGame(int Difficulty) {
    PrintIntroduction(Difficulty);

    //Declare 3 number code
    const int CodeA = rand() % (Difficulty * 2) + 1;
    const int CodeB = rand() % (Difficulty * 2) + 1;
    const int CodeC = rand() % (Difficulty * 2) + 1;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and products to the terminal
    std::cout << "\nThere are 3 numbers in the code";
    std::cout << "\nThe summation of the codes is: " << CodeSum;
    std::cout << "\nThe product of the codes is: " << CodeProduct;

    // store player's guess
    int GuessA, GuessB, GuessC;
    std::cout << "\n\nEnter your guess: \n";
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct  = GuessA * GuessB * GuessC;

    // check if player's guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "\nYou have correctly gained access to secure server room level " << Difficulty << ".";
        return true;
    } else {
        std::cout << "\nYour guess was incorrect! Try again.";
        return false;
    }
}

int main() {
    srand(time(NULL));

    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    // loop while all levels are complete
    while (LevelDifficulty <= MaxDifficulty) {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete) {
            ++LevelDifficulty;
        }
    }

    std::cout << "\nCongratulations you have sucessfully broken into all secure server rooms!\n";
    return 0;
}