#include <iostream>
#include <string>
#include <sstream>

#include "printResult.h"
#include "Quiz.h"

std::string printResult(int questions, int correct, int wrong)
{
    std::stringstream ss;
    
    ss << "Number of questions: " << questions << std::endl
       << "Number correct answers: " << correct << std::endl
       << "Number wrong answers: " << wrong << std::endl
       << "Final score: " << Quiz::score << std::endl;
    
    return ss.str();        // converts stringstream to string
}