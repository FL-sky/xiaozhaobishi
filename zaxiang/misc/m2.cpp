#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
ll a[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[0] = -1;
    a[n + 1] = -1;
    int r = n - 1;
    while (r > 0 && a[r] > a[r + 1])
        --r;
    ll sum = 0;
    if (r <= 0)
    {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 2; i < r; i++)
    {
        if (a[i] <= a[i - 1])
        {
            sum += a[i - 1] - a[i] + 1;
            a[i] = a[i - 1] + 1;
        }
    }
    //
    ll tp = 0;
    //同增
    {
        ll tb[] = {a[r - 1], a[r], a[r + 1]};
        if (tb[1] <= tb[0])
        {
            tp += tb[1 - 1] - tb[1] + 1;
            tb[1] = tb[0] + 1;
        }
        if (tb[2] <= tb[1])
        {
            tp += tb[2 - 1] - tb[2] + 1;
            tb[2] = tb[1] + 1;
        }
    }
    ll tt = tp;
    //同减
    {
        tp = 0;
        ll tb[] = {a[r - 1], a[r], a[r + 1]};
        if (tb[1] >= tb[0])
        {
            tp += abs(tb[1 - 1] - tb[1]) + 1;
            tb[1] = tb[0] - 1;
        }
        if (tb[2] >= tb[1])
        {
            tp += abs(tb[2 - 1] - tb[2]) + 1;
            tb[2] = tb[1] + 1;
        }
        tt = min(tt, tp);
    }
    //^
    {
        tp = 0;
        ll tb[] = {a[r - 1], a[r], a[r + 1]};
        if (!(tb[1] > tb[0] && tb[1] > tb[2]))
        {
            tp = max(tb[0], tb[1]) + 1 - tb[1];
        }
        tt = min(tt, tp);
    }
    cout << sum + tt << endl;
    return 0;
}