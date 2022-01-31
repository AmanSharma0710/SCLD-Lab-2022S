#include<bits/stdc++.h>
using namespace std;

const int INPUTS = 5;

bool expression(vector<int> &v){
    bool v1 = v[0] | v[1] | v[4];
    bool w = v[2];
    bool x = v[0] | v[3];
    bool y = v[1] | v[2];
    bool z = v[3] | v[4];
    return (v1 & w & x & y & z);
}

void recurr(vector<int> v, int i){
    if(i==INPUTS){
        if(expression(v)){
            for(int j=0;j<INPUTS;j++){
                if(v[j]){
                    cout<<(char)(j+'A');
                }
            }
            cout<<endl;
        }
        return;
    }
    recurr(v, i+1);
    v[i] = 1;
    recurr(v, i+1);
    return;
}

int main(){
    vector<int> v(INPUTS, 0);
    for(int i=0; i<INPUTS; i++){
       cout<<(char)('A'+i)<<" ";
    }
    cout<<"output"<<endl;
    recurr(v, 0);
}