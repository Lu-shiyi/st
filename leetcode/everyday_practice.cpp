#include <iostream>
#include <algorithm>

#include "solution.h"

#define TODAY 1212

#if TODAY

bool cmp(int left, int right, int flag)             //用flag来控制摆动的方向
{
    return flag > 0 ? left < right : right < left;
}

int Solution::wiggleMaxLength(vector<int> &nums)
{
    int len = nums.size();
    if (len < 2)
    {
        return len;
    }
    int cnt = 1;
    int res = 1;
    while (cnt < len && nums[cnt] == nums[cnt - 1]) //按给定序列个性化启动摆动检查
    {
        cnt++;
    }
    int flag = nums[cnt - 1] < nums[cnt] ? 1 : -1;
    for (int i = cnt; i < len; i++)
    {
        if (cmp(nums[i - 1], nums[i], flag))
        {
            res++;
            flag *= -1;
        }         //缺省else等价于在摆动异常的情况下选择更优的当前值
    }             //包括在左大判定失败后，说明左小，此时选择更大的右作为当前左值无疑更优
    return res;
}

void test1212()
{
    vector<int> A = {1,2,5,3,2,1};
    Solution S;
    printf("%d \n", S.wiggleMaxLength(A));
}

#else

string Solution::predictPartyVictory(string senate)
{
    int len;
    int flag = 1;
    while (flag && senate.size() > 1)
    { //模拟整个过程直到senate中只含一种字符
        flag = 0;
        char head = senate[0];
        senate.erase(senate.begin()); //获取第一个字符
        len = senate.size();
        for (int i = 0; i < len; i++)
        {
            if (senate[i] != head) //寻找senate中与第一个字符不同的字符
            {
                flag = 1;                          //说明senate中还存在第二种字符
                senate.erase(senate.begin() + i);  //让第一个字符否决它
                senate += head == 'R' ? "R" : "D"; //第一个字符去到字串尾部
                break;
            }
        }
    }
    return senate[0] == 'R' ? "Radiant" : "Dire";
}

void test1211()
{
    Solution S;
    string A = "RD";
    printf(S.predictPartyVictory(A).c_str());
}

bool Solution::lemonadeChange(vector<int> &bills)
{
    int five = 0;
    int ten = 0;
    for (auto i : bills)
    {
        if (i == 5)
        {
            five++;
        }
        else if (i == 10)
        {
            ten++;
            five--;
        }
        else
        {
            if (ten)
            {
                ten--;
                five--;
            }
            else
                five -= 3;
        }
        if (five < 0)
        {
            return false;
        }
    }
    return true;
}

void test1210()
{
    vector<int> A = {5, 5, 10, 10, 20};
    Solution S;
    printf("%s \n", S.lemonadeChange(A) ? "Y" : "N");
}

int Solution::uniquePaths(int m, int n)
{

    // 递归
    // if(m==1||n==1) return 1;
    // return uniquePaths(m-1,n)+uniquePaths(m,n-1);

    // 动态规划
    vector<vector<int>> A(m);
    for (int i = 0; i < m; i++)
    {
        A[i].resize(n);
        A[i][0] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        A[0][i] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            A[i][j] = A[i - 1][j] + A[i][j - 1];
        }
    }
    return A[m - 1][n - 1];
}

void test1209()
{
    Solution S;
    int res = S.uniquePaths(3, 7);
    printf("%d \n", res);
}

int Solution::matrixScore(vector<vector<int>> &A)
{
    int len = A.size();
    int sze = A[0].size();
    int cnt = 0;
    int tmp = 1;
    int res = 0;
    for (int i = 0; i < len; i++)
    { //把第一列都变为1
        if (A[i][0] == 0)
        {
            for (int j = 0; j < sze; j++)
            {
                A[i][j] = (A[i][j]) ? 0 : 1;
            }
        }
    }
    for (int i = 1; i < sze; i++)
    { //每一列尽量多1
        cnt = 0;
        for (int j = 0; j < len; j++)
        {
            if (A[j][i] == 1)
            {
                cnt++;
            }
        }
        if (cnt << 1 < len)
        {
            for (int k = 0; k < len; k++)
            {
                A[k][i] = (A[k][i]) ? 0 : 1;
            }
        }
    }
    for (int i = sze - 1; i >= 0; i--)
    { //计算每一位的和
        for (int j = 0; j < len; j++)
        {
            if (A[j][i] == 1)
            {
                res += tmp;
            }
        }
        tmp *= 2;
    }
    return res;
}

void test1207()
{
    vector<vector<int>> A = {
        {0, 0, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0}};
    Solution S;
    int res = S.matrixScore(A);
    printf("%d \n", res);
}

vector<vector<int>> Solution::generate(int numRows)
{
    vector<vector<int>> res(numRows);
    if (numRows == 0)
    {
        return res;
    }
    res[0].push_back(1);
    for (int i = 1; i < numRows; i++)
    {
        res[i].resize(i + 1);
        res[i][0] = 1; // 每一行两头元素为1
        res[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j]; // 中间元素为其两肩上的和
        }
    }
    return res;
}

void test1206()
{
    Solution S;
    vector<vector<int>> res = S.generate(5);
    for (auto it : res)
    {
        int len = it.size();
        for (int i = 0; i < len; i++)
        {
            printf("%d ", it[i]);
        }
        printf("\n");
    }
}

int Solution::leastInterval(vector<char> &tasks, int n)
{ //O(n)
    int len = tasks.size();
    vector<int> A(26, 0);
    int res = 0;
    int m = 0;
    for (auto i : tasks)
    {
        A[i - 'A']++;
        m = max(m, A[i - 'A']); // 统计出现次数最多的任务。
    }
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    { // 统计最多次数任务有几个。
        if (A[i] == m)
        {
            cnt++;
        }
    }
    return max((m - 1) * (n + 1) + cnt, len);
}

void test1205()
{
    vector<char> A = {'A', 'A', 'A', 'A', 'A',
                      'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    Solution S;
    int res = S.leastInterval(A, 2);
    printf("%d \n", res);
}

bool Solution::isPossible(vector<int> &nums)
{
    unordered_map<int, int> count, tail;
    for (auto i : nums)
    {
        count[i]++;
    }
    for (auto i : nums)
    {
        if (count[i] == 0)
            continue;
        else if (count[i] > 0 && tail[i - 1] > 0)
        {
            count[i]--;
            tail[i - 1]--;
            tail[i]++;
        }
        else if (count[i] > 0 && count[i + 1] > 0 && count[i + 2] > 0)
        {
            count[i]--;
            count[i + 1]--;
            count[i + 2]--;
            tail[i + 2]++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void test1204()
{
    Solution S;
    vector<int> A = {1, 2, 3, 3, 4, 4, 5, 5};
    printf("%s", S.isPossible(A) ? "true" : "false");
}

int Solution::countPrimes(int n)
{ //O(nlogn) Eratosthenes
    int res = 0;
    int temp;
    vector<int> A(n, 1);
    for (int i = 2; i < n; i++)
    {
        if (A[i] == 1)
        {
            res++;
            temp = i;
            while (temp + i < n)
            { //用确定的质数的倍数去更新合数情况
                temp += i;
                A[temp] = 0;
            }
        }
    }
    return res;
}

void test1203()
{
    Solution S;
    int n = 10;
    int res = S.countPrimes(n);
    printf("%d \n", res);
}

#endif

int main()
{
    test1212();
    return 0;
}