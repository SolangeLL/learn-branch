#include "Guesser.hpp"
#include <iostream>
#include <cstdlib>
#include <random>

Guesser::Guesser(
    int numberLives,
    unsigned int min,
    unsigned int max
) : m_numberLives(numberLives),
    m_min(min),
    m_max(max)
{
    std::random_device rd;
    std::mt19937 range(rd());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1,10);

    m_numberToGuess = dist(rd);
    std::cout << "================ GUESSING GAME ================" << std::endl;
    std::cout << "Bienvenue au jeu où tu dois deviner le nombre ? (j'avais pas de nom)" << std::endl;
    std::cout << "La valeur se trouve entre " << m_min << " et " << m_max << "\n" << std::endl;
}

std::string Guesser::GetUserInput(void) const
{
    std::string userGuess("");
    std::cout << "Nombre de vie(s): " << m_numberLives << std::endl;
    std::cout << "Entre ton nombre: ";
    std::cin >> userGuess;
    return userGuess;
}

int Guesser::CompareUserAnswer(const std::string &guess)
{
    m_numberLives--;
    return std::stoi(guess) - m_numberToGuess;
}

void Guesser::WinGame(void)
{
    std::cout << "Bravo gg t'as gagné 67" << std::endl;
    m_isRunning = false;
}

void Guesser::LoseGame(void)
{
    std::cout << "Gros nullos loser t'as perdu" << std::endl;
    m_isRunning = false;
}

bool Guesser::IsWinCondition(int value) const
{
    if (value > 0)
        std::cout << "C'est trop haut\n" << std::endl;
    else if (value < 0)
        std::cout << "C'est trop bas\n" << std::endl;
    else
        return true;
    return false;
}

bool Guesser::IsRunning(void) const
{
    return m_isRunning;
}

bool Guesser::NoLifeRemaining(void) const
{
    return m_numberLives == 0;
}