#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    /*************************************************************** 
     * Day:    1203
     * Description: count primes from [0,n)
     ***************************************************************/
    int countPrimes(int n);

    /*************************************************************** 
     * Day:    1204
     * Desription: split array into consecutive subsequences
     ***************************************************************/
    bool isPossible(vector<int> &nums);

    /*************************************************************** 
     * Day:    1205
     * Desription: task scheduler
     ***************************************************************/
    int leastInterval(vector<char> &tasks, int n);

    /*************************************************************** 
     * Day:    1206
     * Desription: Pascal's triangle
     ***************************************************************/
    vector<vector<int>> generate(int numRows);

    /*************************************************************** 
     * Day:    1207
     * Desription: Score After Flipping Matrix
     ***************************************************************/
    int matrixScore(vector<vector<int>> &A);

    /*************************************************************** 
     * Day:    1209
     * Desription: different paths
     ***************************************************************/
    int uniquePaths(int m, int n);

    /*************************************************************** 
     * Day:    1210
     * Desription: lemonade change
     ***************************************************************/
    bool lemonadeChange(vector<int> &bills);

    /*************************************************************** 
     * Day:    1211
     * Desription: dota2 senate
     ***************************************************************/
    string predictPartyVictory(string senate);    

    /*************************************************************** 
     * Day:    1212
     * Desription: wiggle sequence
     ***************************************************************/
    int wiggleMaxLength(vector<int>& nums);

    /*************************************************************** 
     * Day:    0104
     * Desription: fib number;
     ***************************************************************/
    int fib(int n);
};
