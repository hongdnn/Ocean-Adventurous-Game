#include "Pirate.h"

Pirate::Pirate() :Location('X')
{
    met = false;
}

void Pirate::SetMet(bool f) {
    met = f;
}

bool Pirate::GetMet() {
    return met;
}

void Pirate::draw() {
    if (met) {
        cout << symbol;
    }
    else {
        cout << ".";
    }
}

int Pirate::visit(Player& p) {
    if (!visited) {
        met = true;
        cout << "You unexpectedly meet a pirate ship! Solve this challenge to escape!" << endl;
        // check result of the challenge
        bool result;
        
        // the game randomly selects a type of question
        int questionType = (1 + rand()) % 2;
        
        // first type of question
        if (questionType == 0) {
            // random 2 numbers from 0 to 9
            int num1 = (1 + rand()) % 10;
            int num2 = (1 + rand()) % 10;
            // answer from the player
            int answer;
            while(true) {
                cout << "Question:" << endl;
                cout << "Enter result of " << num1 << " multiply to " << num2 << endl;
                cin >> answer;
                
                // check if input is invalid
                if (cin.fail()) {
                    cout << "Please input a number" << endl << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    result = false;
                }
                // otherwise, check answer
                else {
                    result = answer == num1 * num2;
                    break;
                }
            }
        }
        // second type of question
        else {
            // answer from the player
            string answer;
            // random a number from 2 to 9
            int x = (rand() % 8) + 2;
            // random an answer (maybe true or false) by adding 0 or 1 here
            int randomAnswer = x + (1 + rand()) % 2;
            do {
                cout << "Question:" << endl;
                cout << "x(x-1) = " << x * (x - 1) << endl;
                cout << "x = " << randomAnswer << endl;
                cout << "Is it correct? (Input a or b)" << endl;
                cout << "a. Yes" << endl;
                cout << "b. No" << endl;
                cin >> answer;

                // Check if input is invalid
                if (answer != "a" && answer != "b") {
                    cout << "Invalid input." << endl << endl;
                }
            } while (answer != "a" && answer != "b");
            // otherwise, check answer
            result = (answer == "a" && x == randomAnswer) || (answer == "b" && x != randomAnswer);
        }
        
        //check result
        if (result) {
            cout << "Correct answer! You are save!" << endl << endl;
        }
        else {
            cout << "Wrong answer! You lose all current resources!" << endl << endl;
            return -2;
        }
    }
    return 0;
}