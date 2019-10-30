#include <bits/stdc++.h>

using namespace std;

int main()
{
    int f = 1;
    string s1, s2;
    int c[26] = {0};
    cout << "Enter two strings" << endl;
    cin >> s1 >> s2;
    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    for(int i = 0; i < s1.length(); i++)
    {
        c[s1[i] - 97]++;
    }
    for(int j = 0; j < s2.length(); j++)
    {
        c[s2[j] - 97]--;
    }
    for(int k = 0; k < 26; k++)
    {
        if(c[k] != 0)
        {
            f = 0;
            break;
        }
    }
    if(f == 1)
    {
        cout << "Both strings are anagrams." << endl;
    }
    else
    {
        cout << "The strings are not anagrams." << endl;
    }
    return 0;
}
