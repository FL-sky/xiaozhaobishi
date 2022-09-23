#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-6;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        ll a, b;
        cin >> a >> b;
        ll gd = gcd(a, b);
        a /= gd;
        b /= gd;
        ll lga = log2(a) + eps;
        ll lgb = log2(b) + eps;
        if ((1ll << lga) != a || (1ll << lgb) != b)
        {
            puts("-1");
            continue;
        }
        double d = log2(1.0 * b / a);
        ll dis = abs(d) + eps;
        cout << dis / 3 + (dis % 3 != 0) << endl;
    }
    return 0;
}