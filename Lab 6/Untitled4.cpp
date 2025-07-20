#include <iostream>
using namespace std;

int findcommon(string s1, int n1, string s2, int n2)
{
    int alpha1[26] = { 0 };
    int alpha2[26] = { 0 };
    int i, count = 0;

    for (i = 0; i < n1; i++)
        alpha1[s1[i] - 'a']++;

    for (i = 0; i < n2; i++)
        alpha2[s2[i] - 'a']++;

    for (i = 0; i < 26; i++)
        count += (min(alpha1[i], alpha2[i]));

    return count;
}

int main()
{
    string s1 = "convention", s2 = "competitive";
    int n1 = s1.length(), n2 = s2.length();
    cout << findcommon(s1, n1, s2, n2);

    return 0;
}
