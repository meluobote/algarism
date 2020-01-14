//
// Created by meluobote on 2019/12/16.
//
#include <vector>
#include <iostream>
using namespace std;

int getLongestLenOfIncreasingSequ(vector<int>& v){
    int max=0;
    vector<int> vidx(v.size());
    cout<<"vidxsize: "<<vidx.size()<<endl;
    for(int i=0;i<vidx.size();i++){
        vidx[i]=1;
    }
    for(int i=1;i<vidx.size();i++){
        for(int j=0;j<i;j++){
            if(v[i]>v[j] && vidx[i]<=vidx[j]){
                vidx[i]=vidx[j]+1;
                if(max<vidx[i]){
                    max=vidx[i];
                }
            }
        }
    }
    cout<<"vidx: ";
    for(int i=0;i<vidx.size();i++){
        cout<<vidx[i]<<" ";
    }
    cout<<endl;
    return max;
}

int main(){
    vector<int> v{10, 22, 9, 33, 21, 50, 41, 60};
    cout<<"max: "<<getLongestLenOfIncreasingSequ(v)<<endl;
    return 0;
}
