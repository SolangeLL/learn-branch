#include <string>

#define SUCCESS 67

class Guesser
{
public:
    Guesser(
        int numberLives = 3,
        unsigned int max = 1,
        unsigned int min = 10);
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
    const unsigned int m_min;
    const unsigned int m_max;
    bool m_isRunning = true;
};
