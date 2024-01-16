#ifndef QUIZ_H_
#define QUIZ_H_
#include <string>

#include "printResult.h"

class Quiz
{
    private:
        std::string question {""}, answer {""};  // private member variables w/ default initialization
        static int score;
    public:
        Quiz() = default;       // default constructor
        Quiz(std::string q, std::string a) : question{q}, answer{a} {}  // constructor w/ user-initialized values

        friend std::string printResult(int, int, int);  // allows printResult.h to access private members

        std::string getQuestion();      // accessor function prototypes
        std::string getAnswer();
        static int getScore();

        static void updateScore(int);   // function to update score
};

#endif