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
    void input()
    {
        cin >> x >> y;
    }
};
//

double getS(po a, po b, po c)
{
    int x1 = b.x - a.x;
    int y1 = b.y - a.y;
    int x2 = c.x - a.x;
    int y2 = c.y - a.y;
    return abs(x1 * y2 - x2 * y1) / 2.0;
}
//
const double eps = 1e-8;
bool isin(po a, po b, po c, po t)
{
    double s = getS(a, b, c);
    double x = getS(a, b, t);
    double y = getS(a, c, t);
    double z = getS(b, c, t);
    if (fabs(s - x - y - z) < eps)
    {
        return true;
    }
    return false;
}
int main()
{
    po a, b, c;
    a.input();
    b.input();
    c.input();
    int K;
    cin >> K;
    po d, e, f;
    vector<vector<po>> dt;
    dt.resize(K);
    double mis = 1e18;
    int pos = -1;
    for (int i = 0; i < K; i++)
    {
        d.input();
        e.input();
        f.input();
        vector<po> v;
        v.push_back(d);
        v.push_back(e);
        v.push_back(f);
        dt[i] = v;
        double mj = getS(d, e, f);
        if (mj > mis + eps)
        {
            continue;
        }
        if (isin(d, e, f, a) && isin(d, e, f, b) && isin(d, e, f, c))
        {
            mis = mj;
            pos = i;
        }
    }
    if (pos >= 0)
    {
        vector<po> &r = dt[pos];
        printf("%d %d %d %d %d %d\n", r[0].x, r[0].y, r[1].x, r[1].y, r[2].x, r[2].y);
    }
    else
    {
        puts("fail");
    }
    return 0;
}