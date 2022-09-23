#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 2;
typedef long long ll;
const ll mod = 1e9 + 7;
ll f[N][N];
ll dfs(int x, int y)
{
    if (f[x][y] != -1)
        return f[x][y];
    ll rt = 0;
    for (int i = 1; i < x; i += 2)
    {
        rt += dfs(x - i, y);
    }
    for (int i = 1; i < y; i += 2)
    {
        rt += dfs(x, y - i);
    }
    return f[x][y] = rt % mod;
}
int main()
{
    int T;
    cin >> T;
    int n, m;
    memset(f, -1, sizeof(f));
    f[1][1] = 1;
    while (T-- > 0)
    {
        cin >> n >> m;
        cout << dfs(n, m) << endl;
    }
    return 0;
}