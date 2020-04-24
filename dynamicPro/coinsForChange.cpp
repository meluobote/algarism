/*
 * 描述: 硬币找零问题
 *  如果我们的零钱可用的有1、2、5、9、10。我们找零18元时，贪心算法的策略是：10+5+2+1，四种，但是明明可以用两个9元的啊。
 * 作者：meluobote
 * 日期: 2020/4/24
 */


#include <vector>
#include <iostream>
using namespace std;

void coinsForChange(vector<int>& coins, int& change){
    vector<int> res(change+1, 0); //不找零时需要的硬币数
    vector<int> strategy(change+1, 0);
        //给i块钱找零时，第一次该拿多少硬币,这里直接存储coin的价值不是该价值对应在coins中的索引
    for(int i=1;i<=change;i++){

    }
}

int main() {
    vector<int> coins{1,2,5,9,10};
    int change=18;

    coinsForChange(coins, change);
}