#include <iostream>
using namespace std;

int main() {
    // buffer on stack
    unsigned char buf[sizeof(int) * 2];

    // placement new in buf
    int *pInt = new (buf) int(3);
    int *qInt = new (buf + sizeof(int)) int(5);

    int *pBuf = (int *)(buf + 0);
    int *qBuf = (int *)(buf + sizeof(int));

    cout << "Buf addr               Int Addr" << endl;
    cout << pBuf << "               " << pInt << endl;
    cout << qBuf << "               " << qInt << endl;

    cout << "-------------------------------" << endl;
    cout << "1st Int                2nd Int" << endl;
    cout << *pBuf << "                      " << *qBuf << endl;

    return 0;
}