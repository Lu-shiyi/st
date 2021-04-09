#include <iostream>
#include <vector>
using namespace std;

int A,B;

int main(){
    cin>>A>>B;
    int C = A + B;
    C = C<0? -C:C;
    vector<int> res;
    vector<char> ans;
    do{
        res.push_back(C%10);
        C/=10;
    }while(C!=0);
    int s = res.size();
    int count = 0;
    for(int i=0;i<s;i++){
        if(count==3){
            count=0;
            ans.push_back(',');
        }
        ans.push_back('0'+res[i]);
        count++;
    }
    if(A+B<0) ans.push_back('-');
    int len = ans.size();
    for(int i=len-1;i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}