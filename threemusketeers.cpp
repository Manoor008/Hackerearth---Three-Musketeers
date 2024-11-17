#include <bits/stdc++.h>
using namespace std;

vector<string> subset(string s)
{
    vector<string> pulp;
    for (int i = 0; i < pow(2, s.size()); i++)
    {
        int copy = i;
        string sim;
        int a = 0;
        while (copy != 0)
        {
            if (copy & 1)
            {
                sim.push_back(s[a]);
            }
            copy = copy >> 1;
            a++;
        }
        pulp.push_back(sim);
    }
    return pulp;
}

long long int nc3(int n)
{
    if (n < 3)
    {
        return 0LL;
    }
    return 1LL * n * (n - 1) * (n - 2) / 6;
}

int isVowel(char s)
{
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
    {
        return 1;
    }
    return 0;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<string, int> answerYay;
        vector<set<char>> v1(n);
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++)
            {
                if (isVowel(s[j]))
                {
                    v1[i].insert(s[j]);
                }
            }
            string pip;
            for (auto c : v1[i])
            {
                pip.push_back(c);
            }
            vector<string> g1 = subset(pip);
            for (auto pp : g1)
            {
                // cout << pp << endl;
                answerYay[pp]++;
            }
        }
        long long int summer = 0;
        for (auto &queen : answerYay)
        {
            // cout << queen.first << " " << queen.second << endl;
            if (queen.first.size() != 0)
            {
                if (queen.first.size() & 1)
                {
                    summer += nc3(queen.second);
                }
                else
                {
                    summer -= nc3(queen.second);
                }
            }
        }
        cout << summer << endl;
        // cout << endl;
        // cout << endl;
        // cout << endl;
        // cout << endl;
        // cout << endl;
    }
}