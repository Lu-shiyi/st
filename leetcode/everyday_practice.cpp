#include <iostream>
#include <vector>

#include "solution.h"

using namespace std;

#define TODAY 1023

#if TODAY

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

void test1023(){
    Solution S;
    int n = 10;
    int res = S.countPrimes(n);
    printf("%d \n", res);
}
#else

#endif



int main(){
    test1023();
    return 0;
}