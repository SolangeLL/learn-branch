#include "Guesser.hpp"

int main(void)
{
    Guesser guesser;

    while (guesser.IsRunning())
    {
        std::string guess = guesser.GetUserInput();
        int difference = guesser.CompareUserAnswer(guess);
        bool isWinning = guesser.IsWinCondition(difference);

        if (isWinning)
            guesser.WinGame();
        else if (guesser.NoLifeRemaining())
            guesser.LoseGame();
    }
    
    return SUCCESS;
}