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
void optimalMatricsMultiply(vector<pair<int,int>> vp){
    int mszie=vp.size();
    vector<vector<int>> dp(vp.size(),vector<int>(vp.size(), 0));
}

int main() {
    vector<pair<int,int>> vp{{30,35},{35,15},{15,5},{5,10},{10,20},{20,25}};

}