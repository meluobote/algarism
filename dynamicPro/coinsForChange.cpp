/*
 * 描述: 硬币找零问题
 *  如果我们的零钱可用的有1、2、5、9、10。我们找零18元时，贪心算法的策略是：10+5+2+1，四种，但是明明可以用两个9元的啊。
 * 作者：meluobote
 * 日期: 2020/4/24
 */

#include <vector>
#include <iostream>

using namespace std;

void coinsForChange(vector<int> &coins, int &change) {
    vector<int> res(change + 1, INT_MAX);
    res[0] = 0;  //不找零时需要的硬币数
    vector<int> strategy(change + 1, -1); //-1，代表对应索引的零钱数无法找零。
    strategy[0]=0;
    //给i块钱找零时，第一次该拿多少硬币,这里直接存储coin的价值不是该价值对应在coins中的索引
    for (int i = 1; i <= change; i++) {
        for (int j = 0; j < coins.size(); j++) {
            if (coins[j] <= i && strategy[i-coins[j]]!=-1 && res[i] > (1 + res[i - coins[j]])) {
                //硬币面值需要比零钱小， 找完这个面值的零钱后剩余的面值也应该是能找零钱的
                //能够有更少的硬币数才更新策略
                res[i] = 1 + res[i - coins[j]];
                strategy[i] = coins[j];
            } else if (coins[j] > i) {  //假设coins中硬币的顺序是按升序排的
                break;
            }
        }
    }
    cout<<"strategy: ";
    for(int i=0;i<strategy.size();i++){
        cout<<strategy[i]<<" ";
    }
    cout<<endl;
    //打印选择的硬币方案
    int change2 = change;
    if (strategy[change2] == -1) {
        cout << "no way";
    } else {
        cout << "strategy is : ";
        while (change2 > 0) {
            cout << strategy[change2] << " ";
            change2 = change2 - strategy[change2];
        }
        cout << endl;
    }
    //打印硬币数
    cout<<"coin number is "<<res[change]<<endl;
}

int main() {
//    vector<int> coins{1, 2, 5, 9, 10};
//    int change = 18;
    vector<int> coins{2, 3, 5};
    int change = 6;
    coinsForChange(coins, change);
}