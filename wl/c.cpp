#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
typedef long long ll;
ll a[N], b[N], c[N];
ll f[N][1000 + 10];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    ll sum = accumulate(a + 1, a + 1 + n, 0ll);
    for (int i = 1; i <= n; i++)
        b[i] -= a[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < c[i]; j++)
            f[i][j] = f[i - 1][j];
        for (int j = c[i]; j <= k; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i - 1][j - c[i]] + b[i]);
        }
    }
    cout << 1500 + sum + max(0ll, f[n][k]) << endl;
    return 0;
}