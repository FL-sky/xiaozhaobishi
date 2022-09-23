#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int N = 5e4 + 4;
const int inf = 1e9;
struct po
{
    int x, y;
    po(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator<(const po &b) const
    {
        if (x == b.x)
        {
            return y < b.y;
        }
        return x < b.x;
    }
    bool operator==(const po &b) const
    {
        return x == b.x && y == b.y;
    }
};
struct Dat
{
    vector<po> v;
    int n, m;
    void input()
    {
        int mix, miy, mxx, mxy;
        mix = miy = inf;
        mxx = mxy = -inf;
        int tp;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> tp;
                if (tp)
                {
                    v.push_back(po(i, j));
                    mix = min(mix, i);
                    miy = min(miy, j);
                    mxx = max(mxx, i);
                    mxy = max(mxy, j);
                }
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            v[i].x -= mix;
            v[i].y -= miy;
        }
        n = mxx - mix;
        m = mxy - miy;
    }
    void sort_()
    {
        sort(v.begin(), v.end());
    }
    void xuanzhuan()
    {
        for (int i = 0; i < v.size(); i++)
        {
            po tp = v[i];
            v[i].x = tp.y;
            v[i].y = n - tp.x;
        }
        swap(n, m);
    }
    void shangxian()
    {
        for (int i = 0; i < v.size(); i++)
        {
            v[i].x = n - v[i].x;
        }
    }
    void zuoyou()
    {
        for (int i = 0; i < v.size(); i++)
        {
            v[i].y = m - v[i].x;
        }
    }
};
Dat ck;
int fin = 0;
void dfs(int xz, int sx, int zy, Dat dt)
{
    if (fin)
        return;
    dt.sort_();
    if (ck.v == dt.v)
    {
        fin = 1;
        return;
    }
    if (xz <= 0 && sx <= 0 && zy <= 0)
        return;
    Dat tmp = dt;
    if (xz > 0)
    {
        dt.xuanzhuan();
        dfs(xz - 1, sx, zy, dt);
    }
    if (sx > 0)
    {
        dt = tmp;
        dt.shangxian();
        dfs(xz, sx - 1, zy, dt);
    }
    if (zy > 0)
    {
        dt = tmp;
        dt.zuoyou();
        dfs(xz, sx, zy - 1, dt);
    }
}
int main()
{
    int T;
    cin >> T;

    Dat A;
    ck.input();
    ck.sort_();
    for (int i = 1; i < T; i++)
    {
        A.input();
        if (A.v.size() != ck.v.size())
        {
            cout << "false" << endl;
            continue;
        }
        if (min(A.n, A.m) != min(ck.n, ck.m) || max(A.n, A.m) != max(ck.n, ck.m))
        {
            cout << "false" << endl;
            continue;
        }
        fin = 0;
        dfs(4, 2, 2, A);
        cout << (fin ? "true" : "false") << endl;
    }
    return 0;
}