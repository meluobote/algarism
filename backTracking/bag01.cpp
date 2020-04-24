/*
 * 描述: 简单背包问题，计算最大重量即可。
 * 作者：meluobote
 * 日期: 2020/4/23
 */
#include <vector>
#include <iostream>
using namespace std;

/*
 * idx: 当前算到了哪个物体
 * curWeight: 算到当前物体前时，背包已有的重量
 */
void maxWeightBag(vector<int>& weights,int idx, int curWeight, int& bagLoad, int& maxWeight)
{
    if(curWeight==bagLoad || idx==weights.size()){
        if(curWeight>maxWeight){
            maxWeight=curWeight;
        }
        return;
    }
    maxWeightBag(weights, idx+1, curWeight, bagLoad, maxWeight);
    if(curWeight+weights[idx] <= bagLoad){
        maxWeightBag(weights, idx+1, curWeight+weights[idx], bagLoad, maxWeight);
    }
}

/*
 * 上面的方法，有可能出现重复，比如: idx=m是，curWeight的组成是前m-1个物品组成的，可能存在多种情况，此时在计算是没有必要的
 * 因此，有下面的改进。
 */
void maxWeightBag2(vector<int>& weights,int idx, int curWeight, int& bagLoad, int& maxWeight, vector<vector<bool>>& midStatusStorage)
{
    if(curWeight==bagLoad || idx==weights.size()){
        if(curWeight>maxWeight){
            maxWeight=curWeight;
        }
        return;
    }
    if(midStatusStorage[idx][curWeight]){
        return;
    }
    midStatusStorage[idx][curWeight]=true;
    maxWeightBag(weights, idx+1, curWeight, bagLoad, maxWeight);
    if(curWeight+weights[idx] <= bagLoad){
        maxWeightBag(weights, idx+1, curWeight+weights[idx], bagLoad, maxWeight);
    }
}

int main() {
    vector<int> weights{2, 2, 6, 5, 4};
    int bagLoad = 16;
    int maxWeight=-1;
//    maxWeightBag(weights, 0, 0, bagLoad, maxWeight);
//    cout<<"max: "<<maxWeight<<endl;

    vector<vector<bool>> midStatusStorage(weights.size(), vector<bool>(bagLoad+1, false));
    maxWeightBag2(weights, 0, 0, bagLoad, maxWeight, midStatusStorage);
    cout<<"max: "<<maxWeight<<endl;
}