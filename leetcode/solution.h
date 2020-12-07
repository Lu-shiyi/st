#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
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
    bool isPossible(vector<int>& nums);

    /*************************************************************** 
     * Day:    1205
     * Desription: task scheduler
     ***************************************************************/
    int leastInterval(vector<char>& tasks, int n);
    
    /*************************************************************** 
     * Day:    1206
     * Desription: Pascal's triangle
     ***************************************************************/
    vector<vector<int>> generate(int numRows);

    /*************************************************************** 
     * Day:    1207
     * Desription: Score After Flipping Matrix
     ***************************************************************/
    int matrixScore(vector<vector<int>>& A);
};

