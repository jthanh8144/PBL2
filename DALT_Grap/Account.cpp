#include "Account.h"

Account::Account()
{
	strcpy_s(ID, "");
	strcpy_s(Pass, "");
}

Account::Account(char* ID, char* Pass)
{
	strcpy_s(this->ID, 15, ID);
	strcpy_s(this->Pass, 25, Pass);
}

Account::~Account()
{

}

char* Account::getID()
{
	char *id = this->ID;
	for (int i = 0; i < strlen(id); i++) {
		if (id[i] == ' ') {
			id[i] = '\0';
			break;
		}
	}
	return id;
}

char* Account::getPass()
{
	char *pass = this->Pass;
	for (int i = 0; i < strlen(pass); i++) {
		if (pass[i] == ' ') {
			pass[i] = '\0';
			break;
		}
	}
	return pass;
}