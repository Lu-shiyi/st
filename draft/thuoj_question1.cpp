#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_prime(int x)
{
    if (x == 2 || x == 3)
        return true;
    if (x % 6 != 1 && x % 6 != 5)
        return false;
    for (int i = 5; i <= sqrt(x); i += 6)
        if (x % i == 0 || x % (i + 2) == 0)
            return false;
    return true;
}

int main()
{
    int x;
    cin>>x;
    int left = x;
    int right = x + 1;
    int res = 0;
    int cnt = 0;
    while(true){
        left *= 10;
        right *= 10;
        left += pow(10,cnt);
        if(cnt==0){
            left --;
        }
        for(int i = left+1;i<right;i++){
            if(is_prime(i)){
                cout<<i<<endl;
                return 0;
            }
        }
        cnt++;
    }
    return 0;
}