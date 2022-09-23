#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 4;

struct po
{
    int a, b, c, d;
    void input()
    {
        cin >> a >> b >> c >> d;
    }
} dt[N];
struct point
{
    int x, y;
    point(int x = -1, int y = -1) : x(x), y(y) {}
    bool operator<(const point &b) const
    {
        if (x == b.x)
        {
            return y < b.y;
        }
        return x < b.x;
    }
    bool operator==(const point &b) const
    {
        return x == b.x && y == b.y;
    }
};
point xj(po A, po B)
{
    point rt;
    if (A.b == A.d)
    { // heng
        if (B.b == B.d)
        {
            return rt;
        }
    }
    else
    { // shu
        if (B.a == B.c)
        {
            return rt;
        }
        swap(A, B);
    }
    if (B.b <= A.b && B.d >= A.b)
    {
        if (A.a <= B.a && A.c >= B.a)
        {
            return point(B.a, A.b);
        }
    }
    return rt;
}
int n;
bool pointin(point A)
{
    for (int i = 0; i < n; i++)
    {
        if (A.x > dt[i].a && A.x < dt[i].c && A.y > dt[i].b && A.y < dt[i].d)
            return true;
    }
    return false;
}
bool pointin2(point A)
{
    for (int i = 0; i < n; i++)
    {
        if (A.x >= dt[i].a && A.x <= dt[i].c && A.y >= dt[i].b && A.y <= dt[i].d)
            return true;
    }
    return false;
}
int main()
{
    cin >> n;
    vector<vector<po>> v;
    set<point> st;
    for (int i = 0; i < n; i++)
    {
        dt[i].input();
        int a = dt[i].a, b = dt[i].b, c = dt[i].c, d = dt[i].d;
        vector<po> tv;
        tv.push_back({a, b, c, b});
        tv.push_back({c, b, c, d});
        tv.push_back({a, d, c, d});
        tv.push_back({a, b, a, d});
        v.push_back(tv);
        st.insert(point(a, b));
        st.insert(point(a, d));
        st.insert(point(c, b));
        st.insert(point(c, d));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int p = 0; p < 4; p++)
            {
                for (int q = 0; q < 4; q++)
                {
                    point jd = xj(v[i][p], v[j][q]);
                    if (jd.x > 0)
                    {
                        st.insert(jd);
                    }
                }
            }
        }
    }
    int dir[4][2] = {1, 1, 1, -1, -1, -1, -1, 1};
    point t[4];
    int in2[4];
    for (auto it = st.begin(), ij = it; it != st.end(); it = ij)
    {
        ++ij;
        point tp = *it;
        if (pointin(tp))
        {
            st.erase(it);
            continue;
        }
        for (int i = 0; i < 4; i++)
        {
            t[i] = tp;
            t[i].x += dir[i][0], t[i].y += dir[i][1];
            in2[i] = pointin2(t[i]);
        }
        int sum = accumulate(in2, in2 + 4, 0);
        if (sum == 4)
            st.erase(it);
        else if (sum == 2)
        {
            if (!(in2[0] && in2[2] || in2[1] && in2[3]))
                st.erase(it);
        }
    }
    for (auto it = st.begin(); it != st.end(); it++)
        cout << it->x << " " << it->y << endl;
    return 0;
}