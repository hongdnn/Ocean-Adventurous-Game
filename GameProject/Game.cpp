#include "Game.h"
#include "Treasure.h"
#include "Gold.h"
#include "Diamond.h"
#include "Island.h"
#include "StormArea.h"
#include "Pirate.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

Game::Game()
{
	world = nullptr;
	rows = 0;
	cols = 0;
	playerRow = 0;
	playerCol = 0;
}

vector<int> Game::setUpGame()
{
	playerRow = 0;
	playerCol = 0;
    
    //count the number of resources
    int golds = 0;
    int diamonds = 0;
    int treasures = 0;
    int islands = 0;
    
	string fileName = "gamedata.txt";
	ifstream inputFile(fileName);

	if (inputFile.is_open()) {
		inputFile >> rows >> cols;
        // check invalid rows and columns
        if(rows <= 0 || cols <= 0) {
            return {-1};
        }

		string word;
		world = new Location * *[rows];

		for (int i = 0; i < rows; i++) {
			world[i] = new Location * [cols];
			for (int j = 0; j < cols; j++) {
				inputFile >> word;
				if (i == 0 && j == 0) {
					world[i][j] = new Location();
					continue;
				}
				if (word == "gold") {
					world[i][j] = new Gold();
                    golds++;
				}
				else if (word == "diamond") {
					world[i][j] = new Diamond();
                    diamonds++;
				}
				else if (word == "treasure") {
					world[i][j] = new Treasure();
                    treasures++;
				}
				else if (word == "island") {
					world[i][j] = new Island();
                    islands++;
				}
				else if (word == "storm") {
					world[i][j] = new StormArea();
				}
                else if (word == "pirate") {
                    world[i][j] = new Pirate();
                }
				else {
					world[i][j] = new Location();
				}
				
			}
		}
		

		world[playerRow][playerCol]->visit(p);

	}
    // check invalid number of resources
    if(treasures != 1 || islands != 1 || golds < 1 || diamonds < 1) {
        return {-1};
    }
    // otherwise, return number of golds and diamonds in the sea
    return {golds, diamonds};
}

void Game::drawGame()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (i == playerRow && j == playerCol) {
				cout << "P";
			}
			else {
				world[i][j]->draw();
			}
		}
		cout << endl;
	}
}

void Game::playGame()
{
    
	string input;
	int position;
    
    // resources collected by the player
	int golds = 0;
	int diamonds = 0;
	int island = 0;
	int treasure = 0;
    
    // resources in the sea
    int goldsInSea = 0;
    int diamondsInSea = 0;
    
    // check if user fail the challenge of the StormArea
	bool shipIssue = false;
    
	vector<int> setupResult = setUpGame();
    // invalid number of resources in gamedata file
    if(setupResult[0] == -1) {
        cout << "Some quantity of resources are not correct in setup file." << endl;
        cout << "Must have only 1 treasure, 1 island, at least 1 gold and at least 1 diamond." << endl;
        return;
    }
    
    goldsInSea = setupResult[0];
    diamondsInSea = setupResult[1];
    
	while (true) {
        system("cls");
        cout << "Exploring the sea! Find the treasure, lost people on an island, at least 1 gold and 1 diamond." << endl;
        cout << "Then return to the harbour(where you begin) to win the game." << endl;
        cout << "Watch out the Storm Area(@) and Pirate Ship(X)" << endl << endl;
		drawGame();
        // show current quantity of collected resources
		cout << "Treasure($): " << treasure << "; Island(+): " << island << "; Diamonds(*): " << diamonds << "; Golds(#): " << golds << endl;
        
        do {
            cout << "What direction do you want to move (u, d, l, r)?";
            cin >> input;
            if(input != "u" && input != "d" && input != "l" && input != "r") {
                cout << "Invalid input." << endl << endl;
            }
        }
        while(input != "u" && input != "d" && input != "l" && input != "r");
		int newRow = playerRow;
		int newCol = playerCol;
		

		if (input == "u") newRow--;
		else if (input == "d") newRow++;
		else if (input == "l") newCol--;
		else if (input == "r") newCol++;

		if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
			playerRow = newRow;
			playerCol = newCol;
            
            // only trigger specific locations if the ship doesn't have issue from the StormArea
			if (!shipIssue) {
				position = world[playerRow][playerCol]->visit(p);

				switch (position)
				{
				case 1:
					golds += 1;
                    goldsInSea -= 1;
					break;
				case 2:
					diamonds += 1;
                    diamondsInSea -= 1;
					break;
				case 3:
					island = 1;
					break;
				case 4:
					treasure = 1;
					break;
				case -1:
                    // the ship has issue from StormArea
					shipIssue = true;
					break;
                case -2:
                    // failed the challenge of Pirate and there isn't any 1 of these 3 resources in the sea
                    if(treasure == 1 || goldsInSea == 0 || diamondsInSea == 0) {
                        cout << "There isn't any resources out there for you. Try again next time!" << endl;
                        return;
                    }
                    // otherwise, lose resources and continue
                    golds = 0;
                    diamonds = 0;
                    break;
				default:
					break;
				}

				if (playerRow == 0 && playerCol == 0) {
					if (treasure == 1 && island == 1 && diamonds >= 1 && golds >= 1) {
						cout << "You are the winner!" << endl;
						cout << "Your result:" << endl;
						cout << "Found out mysterious treasure" << endl;
                        cout << "Rescued lost people in the island" << endl;
						cout << "Number of diamonds collected: " << diamonds << endl;
						cout << "Number of golds collected: " << golds << endl;
						break;
					}
				}
			}
            // if the ship had issue but it came back to the harbour
			else if (playerRow == 0 && playerCol == 0) {
				shipIssue = false;
                // in case player collects enough to win the game
                if (treasure == 1 && island == 1 && diamonds >= 1 && golds >= 1) {
                    cout << "You are the winner!" << endl;
                    cout << "Your result:" << endl;
                    cout << "Found out mysterious treasure" << endl;
                    cout << "Rescued lost people in the island" << endl;
                    cout << "Number of diamonds collected: " << diamonds << endl;
                    cout << "Number of golds collected: " << golds << endl;
                    break;
                }
                // otherwise, fix the ship to continue the game
				cout << "Your ship is fixed and ready to go!" << endl;
			}
		}
        // check if the ship go out of the limited area of the game
		else {
			cout << "Can't move outside" << endl;
		}

		cout << endl << "Press any key to continue . . ." << endl;
		cin.ignore();
		cin.get();
	}
}

Game::~Game()
{
}

