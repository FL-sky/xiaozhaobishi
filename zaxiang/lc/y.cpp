#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100 + 10;
int a[N][N];

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int x = 0, y = 0;
    map<char, vector<int>> mp;
    mp['W'] = {-1, 0};
    mp['A'] = {0, -1};
    mp['S'] = {1, 0};
    mp['D'] = {0, 1};
    int cl = 1;
    a[0][0] = 1;
    int rt = -1;
    for (int i = 0, up = s.length(); i < up; i++)
    {
        int nx = x + mp[s[i]][0], ny = y + mp[s[i]][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            x = nx, y = ny;
            if (a[x][y] == 0)
            {
                if (++cl >= n * m)
                {
                    rt = i + 1;
                }
            }
            a[x][y] = 1;
        }
    }
    if (rt >= 0)
    {
        cout << "Yes" << endl
             << rt << endl;
    }
    else
    {
        cout << "No" << endl
             << n * m - cl << endl;
    }
    return 0;
}