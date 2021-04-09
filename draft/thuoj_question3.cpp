#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,p;
vector<int> A;
vector<int> B;

void show(int *res)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d",res[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
}

void p1(int *res){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i;j++){
            res[i+j-1] += A[i-1]*B[j-1];
        }
    }
    show(res);
}

void p2(int *res){
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            res[i-j-1] += A[i-1]*B[j-1];
        }
    }
    show(res);
}

void p3(int *res){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n/i;j++){
            res[i*j-1] += A[i-1]*B[j-1];
        }
    }
    show(res);
}

void p4(int *res){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i%j==0){
                res[i/j-1] += A[i-1]*B[j-1];
            }
        }
    }
    show(res);
}

void p5(int *res){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            res[i/j-1] += A[i-1]*B[j-1];
        }
    }
    show(res);
}

void p6(int *res){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            res[(i&j) - 1] += A[i-1]*B[j-1];
        }
    }
    show(res);
}

void p7(int *res){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            res[(i|j) - 1] += A[i-1]*B[j-1];
        }
    }
    show(res);
}

void p8(int *res){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            res[(i^j) - 1] += A[i-1]*B[j-1];
        }
    }
    show(res);
}

void p9(int *res){
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            res[j - 1] += A[i-1]*B[j-1];
        }
    }
    for(int j=2;j<=n;j++){
        for(int i=1;i<j;i++){
            res [i-1] += A[i-1]*B[j-1];
        }
    }
    for(int i =1;i<=n;i++){
        res[i-1] += A[i-1]*B[i-1];
    }
    show(res);    
}

void p10(int *res){
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            res[i - 1] += A[i-1]*B[j-1];
        }
    }
    for(int j=2;j<=n;j++){
        for(int i=1;i<j;i++){
            res [j-1] += A[i-1]*B[j-1];
        }
    }
    for(int i =1;i<=n;i++){
        res[i-1] += A[i-1]*B[i-1];
    }
    show(res);     
}

int main(){
    scanf("%d %d",&n, &p);
    int *res = new int [n];
    for(int i=0;i<n;i++){
        res[i]=0;
    }
    int temp;
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        A.push_back(temp);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        B.push_back(temp);
    }
    switch (p)
    {
    case 1:
        p1(res);
        break;
    case 2:
        p2(res);
        break;
    case 3:
        p3(res);
        break;
    case 4:
        p4(res);
        break;
    case 5:
        p5(res);
        break;
    case 6:
        p6(res);
        break;
    case 7:
        p7(res);
        break;
    case 8:
        p8(res);
        break;
    case 9:
        p9(res);
        break;
    case 10:
        p10(res);
        break;
    default:
        break;
    }
    return 0;

}