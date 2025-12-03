#include <iostream>

using namespace std;

int main()
{
    string userInput;
    int value;
    cin>>userInput;

    if(int(userInput[0]) >= 97 && int(userInput[0] <= 122)){    //if low case
        value = int(userInput[0]) - 32;
        userInput[0] = char(value);
    }
    cout<<userInput;
    return 0;
}