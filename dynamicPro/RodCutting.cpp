//
// Created by meluobote on 2019/12/23.
//
#include <map>
#include <vector>
#include <iostream>
using namespace std;

void cutRod(vector<int>& values, vector<int>& stategy, vector<int>& prices, int rod_len){
    for(int i=1;i<=rod_len;i++){
        int maxnum= -1;
        for(int j=1;j<=i;j++){
            if(maxnum< (prices[j] + values[i-j])){
                maxnum = prices[j] + values[i-j];
                stategy[i]=j;
            }
        }
        values[i] = maxnum;
    }
    values[rod_len]
}

int main(){
//    vector<int> prices{0,1,5,8,9,10,17,17,20,24,30}; //共11个长度，包括长度0
//    int max_len=10;
//    #define LEN 7
//
//    vector<int> values(max_len);
//    values[0]=0;
//    vector<int> stategy(max_len);
//
//    cutRod(values, stategy, prices, LEN);
//    cout<<values[LEN]<<" "<<stategy[LEN]<<endl;
//
//    int len=LEN;
//    cout<<"stategy: ";
//    while(len>0){
//        cout<<stategy[len]<<" ";
//        len=len - stategy[len];
//    }
//    cout<<"\n";

    vector<int> vi;
    vi[10]=100;
    cout<<vi.size()<<endl;
    cout<<vi[10]<<endl;

    return 0;
}