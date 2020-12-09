#include <iostream>
#include <algorithm>

#include "solution.h"

#define TODAY 1209

#if TODAY

int Solution::uniquePaths(int m, int n){

    // 递归
    // if(m==1||n==1) return 1;
    // return uniquePaths(m-1,n)+uniquePaths(m,n-1);

    // 动态规划
    vector<vector<int>> A(m);
    for(int i=0;i<m;i++){
        A[i].resize(n);
        A[i][0]=1;
    }
    for(int i=0;i<n;i++){
        A[0][i]=1;
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            A[i][j] = A[i-1][j]+A[i][j-1];
        }
    }
    return A[m-1][n-1];
}

void test1209(){
    Solution S;
    int res = S.uniquePaths(3,7);
    printf("%d \n", res);
}

#else

int Solution::matrixScore(vector<vector<int>>& A){
    int len = A.size();
    int sze = A[0].size();
    int cnt = 0;
    int tmp = 1;
    int res = 0;
    for(int i=0;i<len;i++){    //把第一列都变为1
        if(A[i][0]==0){
            for(int j=0;j<sze;j++){
                A[i][j] = (A[i][j])?0:1;
            }
        }
    }
    for(int i=1;i<sze;i++){   //每一列尽量多1
        cnt = 0;
        for(int j=0;j<len;j++){
            if(A[j][i]==1){
                cnt++;
            }
        }
        if(cnt<<1 < len){
            for(int k=0;k<len;k++){
                A[k][i] = (A[k][i])?0:1;
            }
        }
    }
    for(int i=sze-1;i>=0;i--){     //计算每一位的和
        for(int j=0;j<len;j++){
            if(A[j][i]==1){
                res+=tmp;
            }
        }
        tmp*=2;
    }
    return res;
}

void test1207(){
    vector<vector<int>> A = {
        {0,0,1,1},
        {1,0,1,0},
        {1,1,0,0}
    };
    Solution S;
    int res = S.matrixScore(A);
    printf("%d \n", res);
}

vector<vector<int>> Solution::generate(int numRows){
    vector<vector<int>> res(numRows);
    if(numRows==0){
        return res;
    }
    res[0].push_back(1);
    for(int i=1;i<numRows;i++){
        res[i].resize(i+1);
        res[i][0] = 1;                           // 每一行两头元素为1
        res[i][i] = 1;
        for(int j=1;j<i;j++){
            res[i][j]=res[i-1][j-1]+res[i-1][j]; // 中间元素为其两肩上的和
        }
    }
    return res;
}

void test1206(){
    Solution S;
    vector<vector<int>> res = S.generate(5);
    for(auto it : res){
        int len = it.size();
        for(int i=0;i<len;i++){
            printf("%d ",it[i]);
        }
        printf("\n");
    }
}

int Solution::leastInterval
    (vector<char>& tasks, int n){   //O(n)
    int len = tasks.size();
    vector<int> A(26,0);
    int res = 0;
    int m = 0;
    for(auto i : tasks){
        A[i-'A']++;
        m=max(m,A[i-'A']);          // 统计出现次数最多的任务。
    }
    int cnt = 0;
    for(int i=0;i<26;i++){          // 统计最多次数任务有几个。
        if(A[i]==m){
            cnt++;
        }
    }
    return max((m-1)*(n+1) + cnt,len);
}

void test1205(){
   vector<char> A = {'A','A','A','A','A',
   'A','B','C','D','E','F','G'};
   Solution S;
   int res = S.leastInterval(A,2);
   printf("%d \n", res);
}

bool Solution::isPossible(vector<int>& nums){
    unordered_map<int, int> count, tail;
    for(auto i : nums){
        count[i]++;
    }
    for(auto i : nums){
        if(count[i] == 0) continue;
        else if(count[i]>0&&tail[i-1]>0){
            count[i]--; 
            tail[i-1]--; 
            tail[i]++;
        }else if(count[i]>0&&count[i+1]>0&&count[i+2]>0){
            count[i]--;
            count[i+1]--;
            count[i+2]--;
            tail[i+2]++;
        }else{
            return false;
        }
    }
    return true;
}

void test1204(){
    Solution S;
    vector<int> A = {1,2,3,3,4,4,5,5};
    printf("%s", S.isPossible(A) ? "true" : "false");
}

int Solution::countPrimes(int n){ //O(nlogn) Eratosthenes
    int res=0;
    int temp;
    vector<int> A(n,1);
    for(int i=2;i<n;i++){
        if(A[i]==1){
            res++;
            temp=i;
            while(temp+i<n){      //用确定的质数的倍数去更新合数情况
                temp += i;
                A[temp]=0;
            }
        }
    }
    return res;
}

void test1203(){
    Solution S;
    int n = 10;
    int res = S.countPrimes(n);
    printf("%d \n", res);
}

#endif

int main(){
    test1209();
    return 0;
}