#include <iostream>
#include"clsMainScreen.h"
#include"clsLoginScreen.h"
#include"clsAddNewUserScreen.h"



int main()
{
	

	while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen()) {
			break;
		}

	}
}