//
// Created by meluobote on 2019/12/23.
//
#include <map>
#include <vector>
#include <iostream>
using namespace std;

int cutRod(vector<int>& values, vector<int>& stategy, vector<int>& prices, int rod_len){
    if(rod_len<=0){
        return prices[0];
    }else if(rod_len==1){
        return prices[1];
    }else{}

    int allowed_max_rod_len = prices.size();

    for(int i=1;i<rod_len;i++){
        int max = -1;
        for(int j=1;j<=i;j++){
            if(max<prices[j] + values[rod_len-j]){
                max = prices[j] + values[rod_len-j];
                stategy[i]=prices[j];
            }
        }
        values[i] = max;
    }
}

int main(){
    vector<int> prices{0,1,5,8,9,10,17,17,20,24,30}; //共11个长度，包括长度0
    int rod_len=10;

    vector<int> values(rod_len);
    vector<int> stategy(rod_len);


    cout<<prices[11];

    return 0;
}