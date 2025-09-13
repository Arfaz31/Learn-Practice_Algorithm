
#include <bits/stdc++.h>
using namespace std;

bool isPileOfWord(string a, string b)
{
    if (a.size() != b.size())
        return false;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    return a == b;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        if (isPileOfWord(a, b))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

// with frequency array

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         string s1, s2;
//         cin >> s1 >> s2;
//         int freq1[26] = {0};
//         int freq2[26] = {0};
//         bool isEqual = false;
//         if (s1.length() != s2.length())
//         {
//             cout << "NO" << endl;
//         }
//         else
//         {
//             for (int i = 0; i < s1.length(); i++)
//             {
//                 freq1[s1[i] - 'a']++;
//                 freq2[s2[i] - 'a']++;
//             }
//             for (int i = 0; i < 26; i++)
//             {
//                 if (freq1[i] != freq2[i])
//                 {
//                     isEqual = false;
//                     break;
//                 }
//                 else
//                 {
//                     isEqual = true;
//                 }
//             }
//             if (isEqual)
//             {
//                 cout << "YES" << endl;
//             }
//             else
//             {
//                 cout << "NO" << endl;
//             }
//         }
//     }
//     return 0;
// }