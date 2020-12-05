#include <iostream>
#include <algorithm>

#include "solution.h"

#define TODAY 1205

#if TODAY

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

#else

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
    test1205();
    return 0;
}