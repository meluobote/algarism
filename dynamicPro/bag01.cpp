/*
 * 描述: 01-背包问题
 *  我们有一个背包，背包总的承载重量是 mkg。现在我们有n个物品，每个物品的重量不等，并且不可分割。
 *  我们现在期望选择几件物品，装载到背包中。在不超过背包所能装载重量的前提下，如何让背包中物品的总重量最大？
 *  假设山洞里共有a,b,c,d ,e这5件宝物（不是5种宝物），它们的重量分别是2,2,6,5,4，它们的价值分别是6,3,5,4,6，现在给你个承重为10的背包, 怎么装背包，可以才能带走最多的财富。
 * 作者：meluobote
 * 日期: 2020/4/21
 */
#include <vector>
#include <iostream>

using namespace std;

void getMaxVal(vector<int> &weights, vector<int> &vals, int bagLoad) {
    int objnum = weights.size();
    vector<vector<int>> dynv(objnum + 1, vector<int>(bagLoad + 1, 0));
    for(int i=1;i<=objnum;i++){
        for(int j=1;j<=bagLoad;j++){
            if(weights[i]>j){
                dynv[i][j]=dynv[i-1][j];
            }else{
                dynv[i][j]=max(dynv[i-1][j], dynv[i-1][j-weights[i]]+vals[i]);
            }
        }
    }
    for(int i=0;i<=objnum;i++){
        for(int j=0;j<=bagLoad;j++){
            cout<<dynv[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    vector<int> weights{2, 2, 6, 5, 4};
    vector<int> vals{6, 3, 5, 4, 6};
    int bagLoad = 10;
    getMaxVal(weights, vals, 10);
}

