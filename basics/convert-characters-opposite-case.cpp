
// ASCII values: 
// A - Z = 65 to 90
// a - z = 97 to 122
/**
 * 1. Take one string of any length and calculate its length.
 * 2. Scan string character by character and keep checking  the index .
 *      If character in a index is in lower case, then subtract 32 to convert 
 *      it in upper case, else add 32 to convert it in lower case.
 * 3. Print the final string.
*/

#include <iostream>
#include <string>

using namespace std;

void convertOpposite(string &str)
{
    int len = str.length();
    // Conversion according to ASCII values
    for(int i=0; i < len; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            //convert lowercase to uppercase
            str[i] -= 32;
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            //convert uppercase to lowercase
            str[i] += 32;
        }
        else
        {
            // Ignore other characters
        }
    }
}

int main()
{
    string str = "Test The Code";

    convertOpposite(str);

    cout << "Output: " << str << endl;

    return 0;
}

//Time complexity O(n)
