#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
#include<vector>
class clsListCurrencyExchangeScreen:protected clsScreen
{
private:
    static void _PrintCurrencyExchangeRecordLine(clsCurrency CurrencyExchag)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left <<CurrencyExchag.Country();
        cout << "| " << setw(8) << left << CurrencyExchag.CurrencyCode();
        cout << "| " << setw(45) << left << CurrencyExchag.CurrencyName();
        cout << "| " << setw(10) << left << CurrencyExchag.Rate();
     

    }


public:
    static void ShowListCurrencyExchangeScreen(){
        vector <clsCurrency> vCurrency = clsCurrency::GetCurrenciesList();

        string Title = "\t  Currencies List Screen";

        string SubTitle = "\t    (" + to_string(vCurrency.size()) + ") Currencies(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(8) << "Code";
        cout << "| " << left << setw(45) << "Name";
        cout << "| " << left << setw(10) << "Rate/(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vCurrency.size() == 0)
            cout << "\t\t\t\tNo Currencies  Available In the System!";
        else

            for (clsCurrency CurrencyExchange : vCurrency)
            {

                _PrintCurrencyExchangeRecordLine(CurrencyExchange);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
    }
	
};

