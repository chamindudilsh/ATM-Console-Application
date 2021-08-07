#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <winver.h>
#include <iomanip> // used for text align
#include <stdlib.h>
/*
*Username : Chamindu/chamindu/Dilshan/dilshan
*PIN : 6356
*Amount must be higher than RS.100.00 & below RS.150000.00 for Withdraw
*/
using namespace std;

    string usr;
    int pin;
    double amount;
    char confirm;
    string try_confirm;

void bank()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h,14); // yellow color
    cout << "" << endl;
    cout << "================================================================================";
    cout << "--------------------------------------------------------------------------------";
    SetConsoleTextAttribute(h,15); // white color
    //cout << setw (45);
    cout << "                                 BANK OF CEYLON" << endl;
    //cout << setw (0);
    SetConsoleTextAttribute(h,14); // yellow color
    cout << "--------------------------------------------------------------------------------";
    cout << "================================================================================";
    cout << "" << endl;
}

void visit()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(h,14); // yellow color
    cout << "" << endl;
    cout << "================================================================================";
    cout << "--------------------------------------------------------------------------------";
    SetConsoleTextAttribute(h,15); // white color
    cout << "                                 VISIT US AGAIN!" << endl;
    SetConsoleTextAttribute(h,14); // yellow color
    cout << "--------------------------------------------------------------------------------";
    cout << "================================================================================";
    cout << "" << endl;
    SetConsoleTextAttribute(h,7); // light grey
}

void DoProgress( char label[], int step, int total )
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    //progress width
    const int pwidth = 72;

    //minus label len
    int width = pwidth - strlen( label );
    int pos = ( step * width ) / total ;


    int percent = ( step * 100 ) / total;

    //set green text color, only on Windows
    SetConsoleTextAttribute(h,10); // light green
    printf( "%s[", label );

    //fill progress bar with =
    for ( int i = 0; i < pos; i++ )  printf( "%c", '=' );

    //fill progress bar with spaces
    printf( "% *c", width - pos + 1, ']' );
    printf( " %3d%%\r", percent );

    //reset text color, only on Windows
    SetConsoleTextAttribute(h,15); // white color
}

void Progressbar()
{
    int total = 1000;
    int step = 0;

    while ( step < total )
    {
        //do some action
        ::Sleep( 0.5 );

        step+=1;

        DoProgress( "Processing: ", step, total );
    }

    printf( "\n" );

}

void tryagain_usr()
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    system("CLS");
    bank();
    SetConsoleTextAttribute(h,15); // white color
    cout << "Enter Your Username : ";
    cin >> usr;

if (usr == "chamindu" || usr == "Chamindu" || usr == "dilshan" || usr == "Dilshan")
{
    cout << "" << endl;
    cout << "Welcome Mr/Mrs." << usr << endl;
    cout << "Enter Your PIN Number : ";
    cin >> pin;
    if (pin == 6356)
    {
    cout << "" << endl;
    cout << "Enter the Amount of money you need : ";
    cin >> amount;
        if (amount > 100.00 && amount < 150000.00)
        {
            cout << "" << endl;
            cout << "You are about to withdraw RS." << amount << ".00, Are you Sure? (Y/N)";
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y')
            {
                cout << "" << endl;
                Progressbar();
                cout << "" << endl;
                cout << "" << endl;
                cout << "Thank You!" << endl;
                cout << "" << endl;
                cout << "Mr/Mrs." << usr << ", You have received RS." << amount << ".00" << endl;
                //visit();
            }
            else if (confirm == 'N' || confirm == 'n')
            {
                cout << "" << endl;
                cout << "Withdrawal Process Canceled By User!" << endl;
                visit();
            }
            else
            {
                cout << "" << endl;
                SetConsoleTextAttribute(h,12); // red color
                cout << "Unspecified Input!" << endl;
                cout << "Terminating Process!" << endl;
                //visit();
            }
        }
        else if (amount < 100.00)
        {
            cout << "" << endl;
            SetConsoleTextAttribute(h,12); // red color
            cout << "You can't withdraw below than RS.100.00 in ATM!" << endl;
            cout << "Please Try again with a different amount!" << endl;
            //visit();
        }
        else
        {
            cout << "" << endl;
            SetConsoleTextAttribute(h,12); // red color
            cout << "You Don't Have enough money in your account to withdraw RS."<< amount << ".00" << endl;
            cout << "Please check your Balance & Try again!" << endl;
            //visit();
        }
    }
    else if (pin == 6536)
    {
        cout << "" << endl;
        cout << "In case of Emergency, press Alarm!" << endl;
        //visit();
    }
    else
    {
        SetConsoleTextAttribute(h,12); // red color
        cout << "" << endl;
        cout << "Incorrect PIN Number!" << endl;
        SetConsoleTextAttribute(h,15); // white color
        //visit();
    }
}
else if (usr == "/about" || usr == "--about")
{
    cout << "" << endl;
    cout << "This ATM Machine Algorithm is created by Chamindu Dilshan" << endl;
    cout << "All Rights Reserved ®" << endl;
    SetConsoleTextAttribute(h,14); // yellow color
    cout << "" << endl;
    cout << "================================================================================";
    cout << "--------------------------------------------------------------------------------";
    SetConsoleTextAttribute(h,15); // white color
    cout << "                               CHAMINDU DILSHAN" << endl;
    SetConsoleTextAttribute(h,14); // yellow color
    cout << "--------------------------------------------------------------------------------";
    cout << "================================================================================";
    SetConsoleTextAttribute(h,15); // white color
    cout << "" << endl;
}
else if (usr == "/help" || usr == "--help")
{
    cout << "" << endl;
    cout << "Username : Chamindu/chamindu/Dilshan/dilshan" << endl;
    cout << "PIN : 6356" << endl;
    cout << "Amount must be Rs.100.00-150000.00" << endl;
    cout << "" << endl;
}
else
{
    SetConsoleTextAttribute(h,12); // red color
    cout << "" << endl;
    cout << "Incorrect Username!\n" << endl;
    cout << "Please Try again!" << endl;
    cout << "" << endl;
    SetConsoleTextAttribute(h,15); // white color
    cout << "Do You Want to try again? (Y/N)";
    cin >> try_confirm;
    if (try_confirm == "Y" || try_confirm == "y" || try_confirm == "yes")
    {
        tryagain_usr();
    }
}
}

int main()
{
    setw (80);
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    bank();
    SetConsoleTextAttribute(h,15); // white color
    cout << "Enter Your Username : ";
    cin >> usr;

if (usr == "chamindu" || usr == "Chamindu" || usr == "dilshan" || usr == "Dilshan")
{
    cout << "" << endl;
    cout << "Welcome Mr/Mrs." << usr << endl;
    cout << "Enter Your PIN Number : ";
    cin >> pin;
    if (pin == 6356)
    {
    cout << "" << endl;
    cout << "Enter the Amount of money you need : ";
    cin >> amount;
        if (amount > 100.00 && amount < 150000.00)
        {
            cout << "" << endl;
            cout << "You are about to withdraw RS." << amount << ".00, Are you Sure? (Y/N)";
            cin >> confirm;
            if (confirm == 'Y' || confirm == 'y')
            {
                cout << "" << endl;
                Progressbar();
                cout << "" << endl;
                cout << "" << endl;
                cout << "Thank You!" << endl;
                cout << "" << endl;
                cout << "Mr/Mrs." << usr << ", You have received RS." << amount << ".00" << endl;
                //visit();
            }
            else if (confirm == 'N' || confirm == 'n')
            {
                cout << "" << endl;
                cout << "Withdrawal Process Canceled By User!" << endl;
                visit();
            }
            else
            {
                cout << "" << endl;
                SetConsoleTextAttribute(h,12); // red color
                cout << "Unspecified Input!" << endl;
                cout << "Terminating Process!" << endl;
                //visit();
            }
        }
        else if (amount < 100.00)
        {
            cout << "" << endl;
            SetConsoleTextAttribute(h,12); // red color
            cout << "You can't withdraw below than RS.100.00 in ATM!" << endl;
            cout << "Please Try again with a different amount!" << endl;
            //visit();
        }
        else
        {
            cout << "" << endl;
            SetConsoleTextAttribute(h,12); // red color
            cout << "You Don't Have enough money in your account to withdraw RS."<< amount << ".00" << endl;
            cout << "Please check your Balance & Try again!" << endl;
            //visit();
        }
    }
    else if (pin == 6536)
    {
        cout << "" << endl;
        cout << "In case of Emergency, press Alarm!" << endl;
        //visit();
    }
    else
    {
        SetConsoleTextAttribute(h,12); // red color
        cout << "" << endl;
        cout << "Incorrect PIN Number!" << endl;
        SetConsoleTextAttribute(h,15); // white color
        //visit();
    }
}
else if (usr == "/about" || usr == "--about")
{
    cout << "" << endl;
    cout << "This ATM Machine Algorithm is created by Chamindu Dilshan" << endl;
    cout << "All Rights Reserved ®" << endl;
    SetConsoleTextAttribute(h,14); // yellow color
    cout << "" << endl;
    cout << "================================================================================";
    cout << "--------------------------------------------------------------------------------";
    SetConsoleTextAttribute(h,15); // white color
    cout << "                               CHAMINDU DILSHAN" << endl;
    SetConsoleTextAttribute(h,14); // yellow color
    cout << "--------------------------------------------------------------------------------";
    cout << "================================================================================";
    SetConsoleTextAttribute(h,15); // white color
    cout << "" << endl;
}
else if (usr == "/help" || usr == "--help")
{
    cout << "" << endl;
    cout << "Username : Chamindu/chamindu/Dilshan/dilshan" << endl;
    cout << "PIN : 6356" << endl;
    cout << "Amount must be Rs.100.00-150000.00" << endl;
    cout << "" << endl;
}
else
{
    SetConsoleTextAttribute(h,12); // red color
    cout << "" << endl;
    cout << "Incorrect Username!\n" << endl;
    cout << "Please Try again!" << endl;
    cout << "" << endl;
    SetConsoleTextAttribute(h,15); // white color
    cout << "Do You Want to try again? (Y/N)";
    cin >> try_confirm;
    if (try_confirm == "Y" || try_confirm == "y" || try_confirm == "yes")
    {
        tryagain_usr();
    }
}
    visit();
    cout << "" << endl;
    SetConsoleTextAttribute(h,15); // white color
    //cout << "                           !!! Bank Of Ceylon !!!" << endl;;
    SetConsoleTextAttribute(h,7); // light grey
    cout << "" << endl;

    getch();
    return 0;
}
