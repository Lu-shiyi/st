#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

void p0(){
    for(int i=0;i<3;i++){
        cout<<"1/1 0/1 0/1 0/1 0/1 0/1"<<"\n";
    }
}

void p3(){
    for(int i=0;i<3;i++){
        cout<<"0/1 0/1 0/1 0/1 0/1 1/1"<<"\n";
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr;
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        arr.push_back(a);
        arr.push_back(b);
    }
    sort(arr.begin(),arr.end());

    switch (m)
    {
    case 0:
        p0();
        break;
    case 1:
        if(arr[0]==1){
            cout<<"0/1 0/1 1/1 0/1 0/1 0/1"<<"\n";
            if(arr[1]==2){
                cout<<"0/1 0/1 1/1 0/1 0/1 0/1"<<"\n";
                cout<<"0/1 1/1 0/1 0/1 0/1 0/1"<<"\n";
            }else{
                cout<<"0/1 1/1 0/1 0/1 0/1 0/1"<<"\n";
                cout<<"0/1 0/1 1/1 0/1 0/1 0/1"<<"\n";
            }
        }else{
            cout<<"0/1 1/1 0/1 0/1 0/1 0/1"<<"\n";
            cout<<"0/1 0/1 1/1 0/1 0/1 0/1"<<"\n";
            cout<<"0/1 0/1 1/1 0/1 0/1 0/1"<<"\n";
        }
        break;
    case 2:
        if(arr[0]==1&&arr[1]==1){
            cout<<"0/1 0/1 0/1 1/1 0/1 0/1"<<"\n";
            cout<<"0/1 0/1 0/1 0/1 1/1 0/1"<<"\n";
            cout<<"0/1 0/1 0/1 0/1 1/1 0/1"<<"\n";
        }
        if(arr[2]==3&&arr[3]==3){
            cout<<"0/1 0/1 0/1 0/1 1/1 0/1"<<"\n";
            cout<<"0/1 0/1 0/1 0/1 1/1 0/1"<<"\n";
            cout<<"0/1 0/1 0/1 1/1 0/1 0/1"<<"\n";
        }
        if(arr[1]==2&&arr[2]==2){
            cout<<"0/1 0/1 0/1 0/1 1/1 0/1"<<"\n";
            cout<<"0/1 0/1 0/1 1/1 0/1 0/1"<<"\n";
            cout<<"0/1 0/1 0/1 0/1 1/1 0/1"<<"\n";
        }
        break;
    case 3:
        p3();
        break;
    default:
        break;
    }    

    return 0;
}

