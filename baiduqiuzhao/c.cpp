#include <bits/stdc++.h>
using namespace std;
const int N = 2000 + 2;
typedef long long ll;
const ll mod = 1e9 + 7;
ll f[N][N];
ll lieji[N], lieou[N];
void init()
{
    f[1][1] = f[1][2] = f[1][3] = 1;
    lieji[1] = lieji[2] = lieji[3] = 1;
    f[1][1] = f[2][1] = f[3][1] = 1;
    for (int i = 4; i < N; i++)
    {
        f[1][i] = f[1][i - 1] + f[1][i - 2];
        if (f[1][i] >= mod)
            f[1][i] %= mod;
        f[i][1] = lieji[i] = f[1][i];
    }
    for (int i = 2; i < N; i++)
    {
        ll hangji = 1, hangou = 0;
        for (int j = 2; j < N; j++)
        {
            ll rt = 0;
            if (j & 1)
            {
                rt += lieou[j];
                rt += hangou;
            }
            else
            {
                rt += lieji[j];
                rt += hangji;
            }
            f[i][j] = rt % mod;
            if (j & 1)
            {
                lieji[j] += f[i][j];
                hangji += f[i][j];
            }
            else
            {
                lieou[j] += f[i][j];
                hangou += f[i][j];
            }
        }
    }
}
int main()
{
    init();
    int T;
    cin >> T;
    int n, m;
    memset(f, -1, sizeof(f));
    f[1][1] = 1;
    while (T-- > 0)
    {
        cin >> n >> m;
        cout << f[n][m] << endl;
    }
    return 0;
}