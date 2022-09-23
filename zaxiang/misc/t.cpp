#include <bits/stdc++.h>
using namespace std;

unordered_map<int, bool> mark[16];

void merge(int status1, int status2)
{
    int status = (status1 | status2);
    for (auto &x : mark[status1])
    {
        for (auto &y : mark[status2])
        {
            mark[status][x.first + y.first] = true;
            mark[status][abs(x.first - y.first)] = true;
            mark[status][x.first * y.first] = true;
            if (y.first > 0 && x.first % y.first == 0)
                mark[status][x.first / y.first] = true;
            if (x.first > 0 && y.first % x.first == 0)
                mark[status][y.first / x.first] = true;
        }
    }
}

bool damage(vector<int> &power)
{
    for (int i = 0; i < 16; i++)
        mark[i].clear();
    // 1 nums
    for (int i = 0; i < 4; i++)
        mark[1 << i][power[i]] = true;
    // 2 nums
    for (int i = 0; i < 4; i++)
        for (int j = i + 1; j < 4; j++)
            merge(1 << i, 1 << j);
    // 3 nums
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                if (i != j && j != k && k != i)
                    merge((1 << i) | (1 << j), 1 << k);
    // 4 nums
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                for (int t = 0; t < 4; t++)
                    if (i != j && i != k && i != t && j != k && j != t && k != t)
                    {
                        merge((1 << i) | (1 << j), (1 << k) | (1 << t));
                        merge((1 << i) | (1 << j) | (1 << k), 1 << t);
                    }
    return mark[15].count(24) > 0;
}

// 本地测试：
int main()
{
    vector<int> power({1, 1, 2, 7});
    cout << damage(power) << endl;
}
