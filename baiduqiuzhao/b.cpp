#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> ji, ou;
struct po
{
    int x, y;
};
vector<po> ans;
void getans(vector<int> &x, vector<int> &y)
{
    int i = 0;
    int l = min(x.size(), y.size());
    for (i = 0; i < l; i++)
    {
        ans.push_back({x[i], y[i]});
    }
    while (i + 1 < x.size())
    {
        ans.push_back({x[i], x[i + 1]});
        i += 2;
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
    {
        printf("%d %d\n", ans[i].x, ans[i].y);
    }
}
int main()
{
    int n, k;
    cin >> n >> k;
    int hf = 0, dz = 0;
    for (int i = 0, x; i < n; i++)
    {
        cin >> x;
        if (x & 1)
        {
            ji.push_back(x);
        }
        else
        {
            ou.push_back(x);
        }
    }
    if (k & 1)
    {
        getans(ji, ou);
    }
    else
    {
        getans(ou, ji);
    }
    return 0;
}