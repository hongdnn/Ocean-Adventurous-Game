#include "Player.h"

Player::Player() {
	name = "";
	age = 0;
	phone = "";
}

void Player::SetName(string n) {
	name = n;
}

void Player::SetAge(int a) {
	age = a;
}

void Player::SetPhone(string p) {
	phone = p;
}
string Player::GetName() {
	return name;
}
string Player::GetPhone() {
	return phone;
}
int Player::GetAge() {
	return age;
}

void Player::print() {
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Phone: " << phone << endl;
}

