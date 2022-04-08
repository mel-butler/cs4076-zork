#include "wordle.h"

Wordle::Wordle()
{
    allowed_guesses(":/text/wordle_words");
    solutionWord = "death";
    game_won = false;
}


void Wordle::allowed_guesses(string fileName)
{
    fstream newfile;
    newfile.open(fileName,ios::in);
    if (newfile.is_open()) {
        string tp;
        int i=0;
        while (getline(newfile, tp)) {
            *(guess_words + i) = tp;
            i++;
        }
        newfile.close();
    }
}

int Wordle::arraySize()
{
    return sizeof(guess_words)/sizeof(guess_words[0]);
}



bool Wordle::check_if_occurs(const string &guess)
{
    bool occurs = false;
    for (int i = 0; i < arraySize(); i++)
    {
        if (*(guess_words + i) == guess)
        {
            occurs = true;
        }
    }
    return occurs;
}


//g green y yellow
vector<string> Wordle::checkLetter(const string &guess)
{
    string solution = "death";
    char preventDuplication='0';
    vector<string> letterColour(static_cast<int>(guess.size()));
    for(int i=0;i<5;i++){
        letterColour.at(i) = " - ";
    }
    for(int i=0;i<static_cast<int>(guess.size());i++){
        for(int j = 0; j < static_cast<int>(solution.size()); j++)
            if(guess.at(i) == solution.at(j)){
                if (guess.at(i) == solution.at(i)){
                    letterColour.at(i) = " G ";
                    solution.at(i) = preventDuplication;
                    break;
                }else{
                    letterColour.at(i) = " Y ";
                    solution.at(j) = preventDuplication;
                    break;
                }
            }
    }
    return letterColour;
}


bool Wordle::check_if_correct(const vector<string> &letterColour)
{
    bool check = true;
    for(int i=0;i<5;i++){
        if(letterColour.at(i) != " G "){
            check = false;
        }
    }
    return check;
}


string Wordle::play(const string &guess)
{
    vector<string>letterColour;

    if(guess.length()>5 || guess.length()<5){
        output = "incorrect length\n"
                 "hint: five letter word";
        return output;
    }else if(!check_if_occurs(guess)){
        output = "incorrect password\n"
                 "hint: five letter word";
        return output;
    }else{
        letterColour = checkLetter(guess);
        if(check_if_correct(letterColour)){
            game_won = true;

            return output;
        }else{
            return "please re-verify identity";
        }
        output = "";
        for(int i=0;i<5;i++){
            output = output + letterColour.at(i);
        }
        output = solutionWord + "\n" + "please try again";
        return output;
    }

}
