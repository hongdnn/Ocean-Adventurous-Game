#pragma once
#include <iostream>
#include <string>

using namespace std;
class Player {
private:
	string name;
	int age;
	string phone;
public:
	Player();
	void SetName(string n);
	void SetAge(int a);
	void SetPhone(string p);
	string GetName();
	int GetAge();
	string GetPhone();
	void print();
};