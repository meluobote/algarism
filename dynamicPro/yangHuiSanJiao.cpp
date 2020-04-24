/*
 * 描述: 杨辉三角
 * 作者：meluobote
 * 日期: 2020/4/23
 */

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

void yangHui(vector<vector<int>> v) {
    int high = v.size();
    int lastRowLen = v[v.size() - 1].size();
    vector<vector<int>> res(high, vector<int>(lastRowLen - 1, 0));
    res[0][0] = v[0][0];

    for (int i = 1; i < high; i++) {
        int rowSize = v[i].size();
        for (int j = 0; j < rowSize; j++) {
            if (j == 0) {
                res[i][j] = res[i - 1][j] + v[i][j];
            } else if (j == rowSize - 1) {
                res[i][j] = res[i - 1][j - 1] + v[i][j];
            } else {
                res[i][j] = min(res[i - 1][j], res[i - 1][j - 1]) + v[i][j];
            }
        }
    }

    int minIdx = 0;
    int minLen = res[high - 1][0];
    for (int i = 1; i < lastRowLen; i++) {
        if (res[high - 1][i] < minLen) {
            minIdx = i;
            minLen = res[high - i][i];
        }
    }
    cout << "minLen: " << minLen << endl;
    cout << "path: " << v[high - 1][minIdx] << " ";
    for (int row = high - 2; row >= 0; row--) {
        int rowsize = v[row].size();
        if (minIdx == 0) {
            minIdx = 0;
        } else if (minIdx == rowsize - 1) {
            minIdx = rowsize - 2;
        } else {
            if (res[row][minIdx] > res[row][minIdx - 1]) {
                minIdx = minIdx - 1;
            }
        }
        cout << v[row][minIdx] << " ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> v{{5},
                          {7, 8},
                          {3, 2, 4},
                          {9, 4, 6, 1},
                          {7, 2, 9, 4, 5}};
    yangHui(v);
}

