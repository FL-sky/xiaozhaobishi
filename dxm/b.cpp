#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int mz[N][N];
int n, m, k, x;

bool dfs(int a, int b, int sc)
{
    if (a == n && b == m)
    {
        return sc == x;
    }
    if (a + 1 <= n)
        if (dfs(a + 1, b, sc + mz[a + 1][b]))
            return true;
    if (b + 1 <= m)
        if (dfs(a, b + 1, sc + mz[a][b + 1]))
            return true;
    return false;
}
int main()
{
    int T;
    cin >> T;
    while (T-- > 0)
    {
        cin >> n >> m >> k >> x;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                cin >> mz[i][j];
        }
        bool rt = dfs(1, 1, mz[1][1]);
        cout << (rt ? "yes" : "no") << endl;
    }
    return 0;
}