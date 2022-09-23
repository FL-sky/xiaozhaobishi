#include <bits/stdc++.h>
using namespace std;

struct po
{
    string s, t;
    int ls;
    void cg()
    {
        ls = s.length();
        t = s;
        for (int i = ls; i < 8; i++)
        {
            t += *s.rbegin();
        }
    }
    bool operator<(const po &b) const
    {
        return t > b.t;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<po> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].s;
        v[i].cg();
    }
    sort(v.begin(), v.end());
    // string ans="";
    int cnt = 0;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << (*it).s;
        if (++cnt >= 3)
            break;
    }
    return 0;
}