#include <iostream>
using namespace std;

int g1 = 0,s1 = 0,k1 = 0;
int g2 = 0,s2 = 0,k2 = 0;
int g3 = 0,s3 = 0,k3 = 0;

int change(int &t, int r){
    int up = 0;
    up = t/r;
    if(up*r>t) up--;
    t %= r;
    return up;
}

void standard(int &g, int &s, int &k){
    s += change(k,29);
    g += change(s,17);
}


int main(){
    scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
    int p = g1*17*29 + s1*29 + k1;
    int a = g2*17*29 + s2*29 + k2;
    if(a>p){
        k3 = a - p;
        standard(g3,s3,k3);
        printf("%d.%d.%d",g3,s3,k3);
    }else{
        k3 = p - a;
        standard(g3,s3,k3);
        printf("-%d.%d.%d",g3,s3,k3);
    }
    return 0;
}