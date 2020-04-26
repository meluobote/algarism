//
// Created by meluobote on 2019/12/16.
//  给定一个长度为N的数组，找出一个最长的单调自增子序列（不一定连续，但是顺序不能乱）。
//   例如：给定一个长度为6的数组A{5， 6， 7， 1， 2， 8}，则其最长的单调递增子序列为{5，6，7，8}，长度为4.
//
#include <vector>
#include <iostream>
using namespace std;

void getLongestLenOfIncreasingSequ(vector<int>& v){
    int max=0;
    vector<int> vidx(v.size(), 1);

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
    cout<<"max: "<<max<<endl;
}

int main(){
    vector<int> v{10, 22, 9, 33, 21, 50, 41, 60};
    getLongestLenOfIncreasingSequ(v);
    return 0;
}
