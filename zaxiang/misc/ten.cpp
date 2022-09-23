#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6;
const int N = 1e3 + 3;
int dp[N][N];
int idx = 0;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @param k int整型
     * @return int整型
     */

    int dfs(int n, int k)
    {
        if (2 * k > n || n < 2 || k < 1)
            return 0;
        if (dp[n][k] != -1)
            return dp[n][k];
        if (k == 1)
            return 26;
        int rt = 0;
        // rt = dfs(n - 1, k);
        for (int i = n - 2; 2 * (k - 1) <= i; i--)
        {
            rt = rt + dfs(i, k - 1) * 25;
            rt = rt % mod;
        }
        return dp[n][k] = rt;
    }
    int numsOfStrings(int n, int k)
    {
        // write code here
        if (idx == 0)
            memset(dp, -1, sizeof(dp));
        idx = 1;
        dp[2][1] = 26;
        return dfs(n, k);
    }
};

int main()
{
    Solution sl;
    int n, k;
    while (cin >> n >> k)
    {
        cout << sl.numsOfStrings(n, k) << endl;
    }
    return 0;
}