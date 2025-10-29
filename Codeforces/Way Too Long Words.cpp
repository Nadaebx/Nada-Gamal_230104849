// https://codeforces.com/problemset/problem/71/A
#include <iostream>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    string text[n];
    for (int i = 0; i < n; i++)
    {
        cin >> text[i];
    }

    for (int i = 0; i < n; i++)
    {

        string result = "";
        if (text[i].length() > 10)
        {
            result = text[i][0] + to_string(text[i].length() - 2) + text[i][text[i].length() - 1];
        }
        else
        {
            result = text[i];
        }
        cout << result << endl;
    }

    puts("");
    return 0;
}