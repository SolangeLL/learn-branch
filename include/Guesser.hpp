#include <string>

class Guesser
{
public:
    Guesser(int numberLives = 3);
    ~Guesser() = default;

    std::string GetUserInput(void) const;
    int CompareUserAnswer(const std::string &guess);
    void WinGame(void);
    void LoseGame(void);
    bool IsWinCondition(int value) const;
    bool NoLifeRemaining(void) const;

    bool IsRunning(void) const;

private:
    int m_numberLives;
    int m_numberToGuess;
    bool m_isRunning = true;
};
