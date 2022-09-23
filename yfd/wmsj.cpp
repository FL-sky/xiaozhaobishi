#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param s string字符串 第一个整数
     * @param t string字符串 第二个整数
     * @return string字符串
     */
    string solve(string s, string t)
    {
        string res;
        // write code here
        int ls = s.length(), lt = t.length();
        vector<int> ans(ls + lt);

        vector<int> a(ls), b(lt);
        for (int i = 0; i < ls; i++)
        {
            a[i] = s[ls - 1 - i] - '0';
        }
        for (int i = 0; i < lt; i++)
        {
            b[i] = t[lt - 1 - i] - '0';
        }
        for (int i = 0; i < ls; i++)
        {
            for (int j = 0; j < lt; j++)
            {
                ans[i + j] += s[i] * t[j];
            }
        }
        for (int i = 0, up = ans.size(); i < up; i++)
        {
            if (ans[i] > 9)
            {
                ans[i + 1] += ans[i] / 10;
                ans[i] %= 10;
            }
        }
        while (ans.size() > 0 && 0 == *ans.rbegin())
        {
            ans.pop_back();
        }
        //
        res = "";
        for (int i = 0, up = ans.size(); i < up; i++)
        {
            res += char(ans[up - 1 - i] + '0');
        }
        return res;
    }
};

int main()
{
    return 0;
}