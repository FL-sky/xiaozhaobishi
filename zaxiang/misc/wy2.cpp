#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
int main()
{
    ll n, k, x;
    cin >> n >> k >> x;
    if (n * (n + 1) / 2 > x || k < n)
    {
        puts("-1");
        return 0;
    }
    if (n * (2 * k - (n - 1)) / 2 < x)
    {
        puts("-1");
        return 0;
    }
    bool prt = false;
    // while (n > 0)
    // {
    //     double an = (2.0 * x / n + (n - 1)) / 2 + eps;
    //     ll up = an;
    //     if (fabs(an - up) < eps)
    //     {
    //         if (prt)
    //             putchar(' ');
    //         cout << up;
    //         prt = true;
    //         for (ll i = up - 1, j = 1; j < n; j++, i--)
    //         {
    //             cout << " " << i;
    //         }
    //         return 0;
    //     }
    //     if (prt)
    //         putchar(' ');
    //     cout << up + 1;
    //     //
    //     --n;
    //     x -= up + 1;
    //     //
    //     prt = true;
    // }

    double an = (2.0 * x / n + (n - 1)) / 2 + eps;
    ll up = an;
    if (fabs(an - up) < eps)
    {
        if (prt)
            putchar(' ');
        cout << up;
        prt = true;
        for (ll i = up - 1, j = 1; j < n; j++, i--)
        {
            cout << " " << i;
        }
        return 0;
    }
    ll cha = abs(n * (up + up - (n - 1)) / 2 - x);
    ll m = n;
    for (ll i = 0; i < n; i++)
    {
        ll u = min(k, up + cha);

        if (prt)
            cout << ' ';
        cout << u;
        x -= u;
        //
        k = u - 1;
        up--;
        --m;
        cha = x - m * (up + up - (m - 1)) / 2;
        prt = true;
    }

    return 0;
}