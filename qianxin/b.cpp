#include <bits/stdc++.h>
using namespace std;

struct po
{
    int x, y;
};
vector<po> v;
int main()
{
    scanf("[");
    char ch;
    int val, i = 0;
    while (scanf("%d%c", &val, &ch))
    {
        v.push_back({i++, val});
        if (ch == ']')
            break;
    }
    int num = v.size();
    int mx = 0;
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            mx = max(mx, abs(v[i].x - v[j].x) * min(v[i].y, v[j].y));
        }
    }
    cout << mx << endl;
    return 0;
}