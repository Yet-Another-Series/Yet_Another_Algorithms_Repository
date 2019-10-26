#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;
    cout << "Enter first string." << endl;
    cin >> s1;
    cout << "Enter second string." << endl;
    cin >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if(s1.size() == s2.size())
    {
        int n = s1.size();
        while(n != 0)
        {
            if(s1[n] != s2[n])
            {
                break;
            }
            n--;
        }
        if(n == 0)
        {
            cout << "The strings are anagrams." << endl;
        }
        else
        {
            cout << "The strings are not anagrams." << endl;
        }
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
    }

    return 0;
}
