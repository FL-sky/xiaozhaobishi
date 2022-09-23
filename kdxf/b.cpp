#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1.6e4 + 10;

struct po
{
    int x, y;
    bool operator<(const po &b) const
    {
        if (x == b.x)
            return y < b.y;
        return x < b.x;
    }
} v[1024 + 10];
int main()
{
    int L, M;
    cin >> L >> M;
    for (int i = 0, a, b; i < M; i++)
    {
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v, v + M);
    int u = 1, ps = 0, ret = 0;
    while (ps < M && u <= L)
    {
        int mx = 0;
        while (ps < M && v[ps].x <= u)
        {
            mx = max(mx, v[ps].y);
            ps++;
        }
        if (mx <= u - 1)
            break;
        u = mx + 1;
        ret++;
    }
    if (u > L)
        cout << ret << endl;
    else
        puts("fail");
    return 0;
}