#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
const int N = 1e5 + 5;
ll val[N];
struct po
{
    int cnt, pos;
};
int main()
{
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        ll cnt = 0;
        while (val[i] && val[i] % 10 == 0)
        {
            ++cnt;
            val[i] /= 10;
        }
        ans += i * cnt * (n + 1 - i);
    }
    map<int, int> mp;
    vector<po> d2, d5;
    for (int i = 1; i <= n; i++)
    {
        map<int, int> tm;
        while (val[i] % 2 == 0)
        {
            tm[2]++;
            val[i] /= 2;
        }
        if (d5.size())
        {
            for (auto it : d5)
            {
                ans += it.pos * cnt * (n + 1 - i);
            }
        }
        while (val[i] % 5 == 0)
        {
            tm[5]++;
            val[i] /= 5;
        }

        mp[2] += tm[2];
        mp[5] += tm[5];
        int mi = min(mp[2], mp[5]);
        if (mi > 0)
        {
            ans += mi * (n + 1 - i);
            mp[2] -= mi;
            mp[5] -= mi;
        }
    }
    cout << ans << endl;
    return 0;
}