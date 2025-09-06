
#include <iostream>
#include"clsLoginScreen.h"
using namespace std;
int main()
{

    /*while (clsLoginScreen::ShowLoginScreen())
    {

    }*/

    while (true)
    {
        if (!clsLoginScreen::ShowLoginScreen())
        {
            false;
        }

    }

    system("pause>0");

    return 0;

}


