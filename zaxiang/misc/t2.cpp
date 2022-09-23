#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
double num[10];
bool flag;
bool dfs(int x)
{
    if (x == 1)
    {
        if (fabs(num[0] - 24) < 1e-2)
            return true;
        else
            return false;
    }
    double a, b;
    for (int i = 0; i < x; i++)
    {
        for (int j = i + 1; j < x; j++)
        {
            a = num[i];
            b = num[j];
            num[j] = num[x - 1]; // x表示运算的次数，也用来确定区间，
            //每次x-1，同时区间缩小，num[0]作为运算的结果
            num[i] = a + b;
            if (dfs(x - 1))
                return true;
            num[i] = a - b;
            if (dfs(x - 1))
                return true;
            num[i] = b - a;
            if (dfs(x - 1))
                return true;
            num[i] = a * b;
            if (dfs(x - 1))
                return true;
            if (b != 0)
                num[i] = a / b;
            if (dfs(x - 1))
                return true; //除法分母不为0
            if (a != 0)
                num[i] = b / a;
            if (dfs(x - 1))
                return true;
            num[i] = a; //回溯
            num[j] = b;
        }
    }
    return false;
}
int main0()
{
    int t;
    cin >> t;
    while (t--)
    {
        flag = false;
        for (int i = 0; i < 4; i++)
            cin >> num[i];
        if (dfs(4))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}

int main()
{
    int t;
    flag = false;
    num[0] = 1;
    num[1] = 1;
    num[2] = 2;
    num[3] = 7;
    if (dfs(4))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}