#include "Quiz.h"
int Quiz::score {0};

std::string Quiz::getQuestion()     // accessor function definitions
    { return question; }
std::string Quiz::getAnswer() 
    { return answer; }
int Quiz::getScore() 
    { return score; }

void Quiz::updateScore(int val)
{
    score += val;

    if (score <= 0)     // sets score to 0 if score is negative
        {score = 0;}
}