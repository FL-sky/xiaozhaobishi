#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return int整型
     */
    int minCnt(string s)
    {
        // write code here
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            cnt += s[i] == '1';
        }
        return max(0, cnt - 1);
    }
};

int main()
{

    return 0;
}