#include <iostream>
using namespace std;

bool playAgain()
{
    bool endFunc = false;
    do {
        cout << "Do you want to Play Again??" << endl;
        cout << "	Write Y => Yes	N => No	" << endl;
        char userResponse;
        cin >> userResponse;
        userResponse = toupper(userResponse);
        if (userResponse == 'Y')
        {
            system("cls");
            return true;
        }
        else if (userResponse == 'N')
        {
            cout << "See You Soon!!" << endl;
            return false;
        }
        else
        {
            cout << "Invalid Input" << endl; endFunc = true;
        }
    } while (endFunc);
}

int main(void)
{
    do
    {
        cout << "------------------Welcome to our Game-----------------" << endl ;
        int sysNum = rand()%200;
        int userNum; bool toContinue = true;
        cout << "         The Number ranges between 0 and 200          " << endl << endl;
        do
        {
            cout << "Enter a number: ";
            cin >> userNum;
            //Check the User Guess Correct
            if (userNum == sysNum)
            {
                cout << "Correct Answer" << endl;
                //To exit from the current game
                toContinue = false;
            }
            //Check the number in the range
            else if (userNum < 0)
                cout << "Out of RANGE.." ;
            else if (userNum > 200)
                cout << "Out of RANGE..";
            //Check the number is higher of lower
            else if (userNum > sysNum)
                cout << "Too HIGH..";
            else if (userNum < sysNum)
                cout << "Too LOW..";
            if (toContinue)
                cout << "Try Again!!" << endl;
        } while (toContinue);

    } while (playAgain());

    system("pause>0");
    return 0;
}
