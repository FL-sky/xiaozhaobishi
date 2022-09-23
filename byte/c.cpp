#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
const double eps = 1e-6;
int a[N];
int p[N], q[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    p[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        p[i] = max(p[i - 1] + a[i], a[i]);
    }
    q[n] = a[n];
    for (int i = n - 1; i > 0; i--)
    {
        q[i] = max(q[i + 1] + a[i], a[i]);
    }
    int mx = a[1];
    for (int i = 1; i <= n; i++)
    {
        mx = max(mx, p[i] + q[i] - a[i]);
        mx = max(mx, p[i]);
        mx = max(mx, q[i]);
        mx = max(mx, a[i]);
    }
    //
    int left = a[1];
    int lxs = left;
    for (int i = 2; i <= n; i++)
    {
        mx = max(mx, lxs + q[i]);
        left = a[i] + max(0, left);
        lxs = max(lxs, left);
    }

    //
    //
    int right = a[n];
    int rxs = right;
    for (int i = n - 1; i > 0; i--)
    {
        mx = max(mx, rxs + p[i]);
        right = a[i] + max(0, right);
        rxs = max(rxs, right);
    }

    //
    cout << mx << endl;
    return 0;
}