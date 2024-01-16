#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "printResult.h"
#include "Quiz.h"
using namespace std;

int main(int argc, char const *argv[])
{
    int numCorrect {0}, numWrong {0};                     // stores the number of questions answered correctly / incorrectly
    int scoreVal {0};                                     // used to add / subtract score
    string userInput;                                     // used to take input from user

    ifstream database;      // attributes needed for reading file used in command line argument
    vector<string> databaseVector;
    string line;

    database.open(argv[1]);     // opens .txt file
    if (database.is_open())
    {
        while (!database.eof())     // reads .txt file until the end of the file is reached
        {
            getline (database, line);
            if (line[line.length() - 1] == '\r')        // used to fix newline character depending on OS
                { line.erase(line.length() - 1); }
            databaseVector.push_back(line);     // stores each line within the .txt vector
        }
    }

    for (auto& l : databaseVector)      // Assumes lines in .txt file start w/ 'Q: ' or 'A: ' for simplicity
        { l.erase(0,3); }

    database.close();       // closes database.txt
    
    vector<Quiz> quizVector;   // vector to store every question-answer pair

    for (long unsigned int i = 0; i < databaseVector.size(); i += 2)        // stores each question / answer pair at single indexes within a new vector
    {
        Quiz questionAnswerPair (databaseVector[i], databaseVector[i + 1]);
        quizVector.push_back(questionAnswerPair);
    }

    srand(unsigned(time(0)));   // initializes random number generator to the current runtime value
    random_shuffle (quizVector.begin(), quizVector.end());  // randomizes questions stored in quizVector

    for (long unsigned int i = 0; i < quizVector.size(); i++)    // loop to prompt the quiz until all questions are answered
    {
        Quiz quiz;      // instance of class Quiz

        quiz = quizVector.at(i);    // calls instances of class Quiz at the given index in quizVector

        cout << quiz.getQuestion() << endl;     // question

        cout << "Type in your answer: ";        // answer
        getline(cin >> ws, userInput);

        if (userInput == quiz.getAnswer())     // if user input is the correct answer
        {
            numCorrect += 1;
            quiz.updateScore(scoreVal = 1);

            cout << "Correct!" << endl;
            cout << "Current score: " << quiz.getScore() << endl << endl;
        }
        else                                    // if user input is incorrect
        {
            numWrong += 1;
            quiz.updateScore(scoreVal = -1);

            cout << "Wrong! Correct answer: " << quiz.getAnswer() << endl;
            cout << "Current score: " << quiz.getScore() << endl << endl;
        }
    }

    cout << printResult(quizVector.size(), numCorrect, numWrong);        // prints results

    return 0;
}