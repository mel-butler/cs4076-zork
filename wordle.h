#ifndef WORDLE_H
#define WORDLE_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;

class Wordle
{
public:
    Wordle();
    void allowed_guesses(string fileName);
    void solution(string fileName);
    bool check_if_occurs(const string &guess);
    bool check_if_correct(const vector<string> &letterColour);
    string play(const string &guess);
    string printNextLine();
    bool game_won;
private:
    vector<string> checkLetter(const string &guess);
    string output;
    string solutionWord;
    string guess_words[12957];
    int arraySize();
};

#endif // WORDLE_H
