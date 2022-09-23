#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const ll mod = 1e9 + 7;
// int a[N];
ll fpow(ll a, ll x)
{
    ll rt = 1;
    while (x)
    {
        if (x & 1)
            rt = rt * a % mod;
        x = x >> 1;
        a = a * a % mod;
    }
    return rt;
}
int main()
{
    int n;
    cin >> n;
    int jo[2] = {0, 0};
    for (int i = 0, t; i < n; i++)
    {
        cin >> t;
        jo[t & 1]++;
    }

    ll r = fpow(2, jo[0]);
    if (jo[0] < 2)
    {
        r = 0;
    }
    else
    {
        r -= jo[0] + 1;
    }
    ll ans = r;
    ll l = fpow(2, jo[1]);
    if (jo[1] < 2)
    {
        l = 0;
    }
    else
    {
        l = l / 2 - 1;
    }
    ans += l;
    ans = (ans % mod + mod) % mod;
    cout << ans << endl;

    return 0;
}