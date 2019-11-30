
#include <iostream>
using namespace std;

#define LIMIT (5U)
#define AREA(l,b) (l*b)

void startFunc();
void exitFunc();
#pragma startup startFunc
#pragma exit exitFunc

void startFunc()
{
    cout << "Start of the main function" << endl;
}
void exitFunc()
{
    cout << "Exit of the main function" << endl;
}

int main()
{

    for (int i = 0; i < LIMIT; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    int area = AREA(10,20);
    cout << "Area: " << area << endl;

#undef LIMIT

    return 0;
}
