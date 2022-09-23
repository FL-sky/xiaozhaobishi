#include <bits/stdc++.h>
using namespace std;
const int N = 2e2 + 2;
string mz[N][N];
int n, m, q;
bool isin(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
int main()
{
    cin >> n >> m >> q;
    int t, x, y;
    string name;
    while (q-- > 0)
    {
        cin >> t >> x >> y;
        if (t == 1)
        {
            cin >> name;
            if (isin(x, y) && mz[x][y].length() == 0)
            {
                mz[x][y] = name;
            }
        }
        else
        {
            if (isin(x, y))
            {
                mz[x][y] = "";
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j > 1)
                cout << ' ';
            if (mz[i][j].length())
            {
                cout << mz[i][j];
            }
            else
            {
                cout << "NULL";
            }
        }
        cout << endl;
    }
    return 0;
}