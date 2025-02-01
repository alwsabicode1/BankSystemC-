#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include"clsDate.h"
#include"clsUtil.h"


using namespace std;

class clsScreen
{
protected:
    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {
        cout << clsUtil::Tabs(3)<<"__________________________________\n";
        cout << "\n"<<clsUtil::Tabs(6) << Title;
        if (SubTitle != "")
        {
            cout << "\n "<< clsUtil::Tabs(6) << SubTitle;
        }
        cout <<"\n" << clsUtil::Tabs(6) << "__________________________________\n\n";
        cout << "\n" << clsUtil::Tabs(6)<<"User : " << CurrentUser.UserName << "\n";
        cout << "\n" << clsUtil::Tabs(6)<<"Date : " << clsDate::DateToString(clsDate()) << "\n";

    }
   

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {

        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }

};

