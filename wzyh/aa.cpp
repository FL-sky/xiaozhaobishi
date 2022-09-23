#include <bits/stdc++.h>
using namespace std;
string ans = "";

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    // string ans="";
    int cnt = 0;
    vector<string> t;
    for (auto it = v.rbegin(); it != v.rend(); it++)
    {
        t.push_back(to_string(*it));
        if (++cnt >= 3)
            break;
    }
    sort(t.begin(), t.end());
    string tp;
    do
    {
        tp = t[0] + t[1] + t[2];
        if (ans < tp)
            ans = tp;
    } while (next_permutation(t.begin(), t.end()));
    cout << ans << endl;
    return 0;
}