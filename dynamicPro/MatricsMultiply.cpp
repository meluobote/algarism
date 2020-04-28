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

void optimalMatricsMultiply(vector<pair<int, int>> vp) {
    int szie = vp.size();
    vector<vector<int>> dp(vp.size(), vector<int>(vp.size(), 0));
    for (int i = 0; i < size; i++) {
        dp[i][i] = 0;
    }
    for (int len = 1; len <= size - 1; len++) {
        for (int i = 0; i < size - len; i++) {
            m[i][i + len] = INT_MAX;
            for (int j = 0; j < len; j++) {
                int count=m[i][i+j]+m[i+j+1][i+len]+vp[i].first*vp[i+j].second*vp[i+len].second;
                if(count<)
            }
        }
    }
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size - i; j++) {

        }
    }
}

int main() {
    vector<pair<int, int>> vp{{30, 35},
                              {35, 15},
                              {15, 5},
                              {5,  10},
                              {10, 20},
                              {20, 25}};

}