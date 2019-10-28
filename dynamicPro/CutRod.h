//
// Created by meluobote on 2019/10/22.
//

#ifndef ALGARISM_CUTROD_H
#define ALGARISM_CUTROD_H

#include <map>
#include <set>
#include <vector>
using namespace std;

class CutRod {
private:
    const map<int, int> tab;     //不同长度对应的价格方案

    /*
     * 记录不同的长度对应的最大的收入，和最好的一种或几种解决方案，解决方案
     */
    map<int, pair<int,vector<set<int>> >> solutions;

    //过度的变量
    map<int, int> best_solution;
public:
    CutRod(const map<int, int> tab);

    /* 获取长度为len时的最大收入 */
    int getMaxProfit(int len);
};


#endif //ALGARISM_CUTROD_H
