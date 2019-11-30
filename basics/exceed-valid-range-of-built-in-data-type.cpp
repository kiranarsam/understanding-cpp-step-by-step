
#include <iostream>

using namespace std;

int main()
{
    int count = 10;

    // signed char - if won't specify anything before char
    for(char a = 125; count; a++, count--)
    {
        cout << " " << (int)a ;
    }

    cout << endl;
    count = 11;
    // signed char - if won't specify anything before char
    for(char a = 225; count; a++, count--)
    {
        cout << " " << (int)a ;
    }

    cout << endl;
    count = 11;
    // unsigned char => 0 - 255, just verify 
    for(unsigned char a = 125; count; a++, count--)
    {
        cout << " " << (int)a ;
    }
    cout << endl;
        count = 11;
    // unsigned char => 0 - 255
    for(unsigned char a = 250; count; a++, count--)
    {
        cout << " " << (unsigned short int)a ;
    }
    cout << endl;

    // this bool, block of code will run infinite loop which prints 1.
    // So, bool range is either 0 or 1
    bool isHappy = true;
    for(isHappy = 1; isHappy <= 5; isHappy++)
    {
        cout << " " << isHappy;
    }
    cout << endl;

}