#include <iostream>
using namespace std;

bool calculateAgain()
{
    bool endFunc = false;
    do {
        cout << "Do you want to Calculate Again??" << endl;
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
    bool programContinue;
    do
    {
        cout << "-------------- Welcome to My Simple Calculator ----------" << endl;
        int input[2]; char operation;
        cout << "Enter first input : ";
        cin >> input[0];
        cout << "Enter the operation : ";
        cin >> operation;
        cout << "Enter second input : ";
        cin >> input[1];

        switch (operation)
        {
        case '+':cout << input[0] << " + " << input[1] << " = " << input[0] + input[1] << endl; break;
        case '-':cout << input[0] << " - " << input[1] << " = " << input[0] - input[1] << endl; break;
        case '*':cout << input[0] << " * " << input[1] << " = " << input[0] * input[1] << endl; break;
        case '/':cout << input[0] << " / " << input[1] << " = " << (float)input[0] / input[1] << endl; break;
        default:
            cout << "Wrong Operation Symbol...." << endl;
        }

    } while (calculateAgain());
    system("pause>0");
    return 0;
}
