#include "Guesser.hpp"
#include <iostream>

int main(void)
{
    Guesser guesser;

    while (guesser.IsRunning())
    {
        std::string guess = guesser.GetUserInput();
        int difference = 0;
        bool isWinning = false;

        try
        {
            difference = guesser.CompareUserAnswer(guess);
            isWinning = guesser.IsWinCondition(difference);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Entrez une commande valide. nullos salopiiiiot" << std::endl;
        }

        if (isWinning)
            guesser.WinGame();
        else if (guesser.NoLifeRemaining())
            guesser.LoseGame();
    }

    return SUCCESS;
}