#include<bits/stdc++.h>
using namespace std;

const int INPUTS = 5;

bool expression(vector<int> &v){
    bool x = v[0] | v[1];
    bool y = v[2] ^ v[4];
    bool z = v[0] ^ v[2];
    z = !z;
    bool w = (!v[3]) | v[4];
    bool l = (!v[1]) | (v[0] & v[3]);
    return (x & y & z & w & l);
}

void recurr(vector<int> v, int i){
    if(i==INPUTS){
        for(int j=0; j<INPUTS; j++){
            cout<<v[j]<<" ";
        }
        cout<<expression(v)<<endl;
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