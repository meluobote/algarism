//
// Created by meluobote on 2019/10/22.
//

#include "CutRod.h"

CutRod::CutRod(const map<int, int> tab)
:tab(tab)
{
    best_solution.insert({0,0});
}

int CutRod::getMaxProfit(int len){
    if(len<=0){
        return 0;
    }else if(this->best_solution[len]>0){
        return this->best_solution[len];
    }

    int maxProfit{};
    int tmp{};
    for(int i=1;i<=len; i++){
        if(this->tab.count(i) == 0){
            continue;
        }
        tmp = this->tab.at(i) + getMaxProfit(len - i);
        if(tmp>maxProfit)
            maxProfit=tmp;
    }

    this->best_solution[len] = maxProfit;
    return maxProfit;
}

