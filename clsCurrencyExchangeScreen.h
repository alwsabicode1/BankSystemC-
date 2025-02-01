#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iomanip>
#include"clsListCurrencyExchangeScreen.h"
#include"clsFindCurrencyExchangeScreen.h"
#include"clsUpdateCurrencyExchangeScreen.h"
#include"clsCurrencyExchangeCalculaterScreen.h"
using namespace std;
class clsCurrencyExchangeScreen:clsScreen
{
private:
    enum enCurrencyExchangeMenueOptions {
        eListCurrency = 1, eFindCurrency = 2,
        eUpdateCurrency = 3, eCurrencyCalculater = 4,  eShowMainMenue = 5

    };

    static short ReadCurrencyExchangeMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5 ? ");
        return Choice;
    }


    static void _ShowListCurrencyExchangeScreen()
    {
        //cout << "\n Deposit Screen will be here.\n";
        clsListCurrencyExchangeScreen::ShowListCurrencyExchangeScreen();
    }

    static void _ShowFindCurrencyexchangeScreen()
    {
        //cout << "\n Withdraw Screen will be here.\n";
        clsFindCurrencyExchangeScreen::ShowFindCurrencyexchangeScreen();
    }

    static void _ShowUpdateCurrencyExchangeScreen()
    {
        // cout << "\n Balances Screen will be here.\n";
        clsUpdateCurrencyExchangeScreen::ShowUpdateCurrencyExchangeScreen();

    }

    static void _ShowCurrencyExchangeCalculaterScreen()
    {
        //cout << "\n Transfer Screen will be here.\n";
        clsCurrencyExchangeCalculaterScreen::ShowCurrencyExchangeCalculaterScreen();


    }


    static void _GoBackToCurrencyExchangeMenue()
    {
        cout << "\n\nPress any key to go back to Currency Exchange Menue...";
        system("pause>0");
        ShowCurrencyExchangeScreen();

    }

    static void _PerformTransactionsMenueOption(enCurrencyExchangeMenueOptions CurrencyExchangeMenueOption)
    {
        switch (CurrencyExchangeMenueOption)
        {
        case enCurrencyExchangeMenueOptions::eListCurrency:
        {
            system("cls");
            _ShowListCurrencyExchangeScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }

        case enCurrencyExchangeMenueOptions::eFindCurrency:
        {
            system("cls");
            _ShowFindCurrencyexchangeScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }


        case enCurrencyExchangeMenueOptions::eUpdateCurrency:
        {
            system("cls");
            _ShowUpdateCurrencyExchangeScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }
       
        case enCurrencyExchangeMenueOptions::eCurrencyCalculater:
        {
            system("cls");
            _ShowCurrencyExchangeCalculaterScreen();
            _GoBackToCurrencyExchangeMenue();
            break;
        }


        case enCurrencyExchangeMenueOptions::eShowMainMenue:
        {

            //do nothing here the main screen will handle it :-) ;

        }
        }


    }



public:
	static void ShowCurrencyExchangeScreen() {

        if (!CheckAccessRights(clsUser::enPermissions::PCurrencyExchange))
        {
            return;// this will exit the function and it will not continue
        }

        system("cls");
        _DrawScreenHeader("   Currency Exchange Main Menue");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t  Currency Exchange Main Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Currency.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculater.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformTransactionsMenueOption((enCurrencyExchangeMenueOptions)ReadCurrencyExchangeMenueOption());
    }         
};


