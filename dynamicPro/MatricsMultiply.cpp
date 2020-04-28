/*
 * 描述: 多个矩阵连乘，怎样计算可以使得乘法的次数最少。
 * 比如: 有A1,A2,A3三个矩阵，分别10*100， 100*5， 5*50
 * 如果(A1*A2)*A3 那么10*100*5+10*5*50=7500, 如果A1*(A2*A3)，那么100*5*50+10*100*50=75000 乘法发生次数相差10倍。
 * 作者：meluobote
 * 日期: 2020/4/27
 */

#include <vector>
#include <iostream>

using namespace std;

void printStrategy(vector<vector<int>>& strategy, vector<pair<int, int>>& vp, int i, int j) {
    //strategy的行数和列数相等
    if(i==j){
        cout<<"A"<<i;
    }else{
        cout<<"(";
        printStrategy(strategy, vp, i, strategy[i][j]);
        printStrategy(strategy, vp, strategy[i][j]+1,j);
        cout<<")";
    }
}

void optimalMatricsMultiply(vector<pair<int, int>>& vp) {
    int size = vp.size();
    vector<vector<int>> dp(vp.size(), vector<int>(vp.size(), 0));
    vector<vector<int>> strategy(vp.size(), vector<int>(vp.size(), 0));
    for (int i = 0; i < size; i++) {
        dp[i][i] = 0;
    }
    for (int len = 1; len <= size - 1; len++) {
        for (int i = 0; i < size - len; i++) {
            dp[i][i + len] = INT_MAX;
            for (int j = 0; j < len; j++) {
                int count = dp[i][i + j] + dp[i + j + 1][i + len] + vp[i].first * vp[i + j].second * vp[i + len].second;
                if (count < dp[i][i + len]) {
                    dp[i][i + len] = count;
                    strategy[i][i + len] = i + j;
                }
            }
        }
    }
    cout << "min count: " << dp[0][size - 1] << endl;
//    for(int i=0;i<strategy.size();i++){
//        for(int j=0;j<strategy.size();j++){
//            cout<<strategy[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    printStrategy(strategy, vp, 0, size-1);
}

int main() {
    vector<pair<int, int>> vp{{30, 35},
                              {35, 15},
                              {15, 5},
                              {5,  10},
                              {10, 20},
                              {20, 25}};
    optimalMatricsMultiply(vp);
}