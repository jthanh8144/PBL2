#pragma once
#include <iostream>

using namespace std;

class Account
{
private:
	char ID[15];
	char Pass[25];
public:
	Account();
	Account(char*, char*);
	~Account();
	
	char* getID();
	char* getPass();
};