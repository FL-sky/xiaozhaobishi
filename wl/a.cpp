#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return int整型
     */
    int sum;
    map<int, int> mp;
    void dfs(TreeNode *u, int dep)
    {
        if (u == NULL)
        {
            return;
        }
        mp[dep]++;
        sum++;
        dfs(u->left, dep + 1);
        dfs(u->right, dep + 1);
    }
    int numOfNode(TreeNode *root)
    {
        sum = 0;
        dfs(root, 0);
        int p2 = 1;
        int s2 = 0;
        for (int i = 0; i < mp.size(); i++)
        {
            if (mp[i] != p2)
            {
                break;
            }
            s2 += p2;
            p2 = p2 * 2;
        }
        return sum - s2;
    }
};

int main()
{
    return 0;
}