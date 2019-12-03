#include <iostream>
#include <cstring>
using namespace std;

class String {
    private:
        char *s;
        int size;
    public:
        String(const char *str = NULL); //constructor
        
        ~String(){
            delete[] s;
        }

        String(const String &); // Copy Constructor

        void print() {
            cout << s << endl;
        }

        void change(const char *); // Function to change
};

String::String(const char *str) {
    size = strlen(str);
    s = new char[size + 1];
    strcpy(s, str);
}

void String::change(const char *str) {
    delete[] s;
    size = strlen(str);
    s = new char[size + 1];
    strcpy(s, str);
}

String::String(const String& old_str) {
    size = old_str.size;
    s = new char[size];
    strcpy(s,old_str.s);
}

int main() {
    String str1("TestTheCode");
    String str2 = str1;

    str1.print();
    str2.print();

    str2.change("CodeToTest");

    str1.print();
    str2.print();
    /*
        If we remove the copy-constructor definition
        Output:- might have differnce, leads to abnormal termination.
        Verify without, user defined copy-constructor
    */
    return 0;
}