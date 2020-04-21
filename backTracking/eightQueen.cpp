/*
 * 描述: 八皇后问题解决
 * 作者：meluobote
 * 日期: 2020/4/21
 */
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int totalCount=0;

void printQueens(vector<int> &res) {
    cout<<"==========================================";
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (res[i] == j) {
                cout << "*";
            } else {
                cout << "#";
            }
        }
        cout << endl;
    }
}

bool is_Ok(vector<int> res, int row, int colu) {
    int valColu = colu-1;
    //检查左上角
    for (int i = row - 1; i >= 0 && valColu >= 0; i--, valColu--) {
        if (res[i] == valColu) {
            return false;
        }
    }
    //检查上方
    for (int i = row - 1; i >= 0; i--) {
        if (res[i] == colu) {
            return false;
        }
    }
    valColu = colu+1;
    //检查右上角
    for (int i = row - 1; i >= 0 && valColu < 8; i--, valColu++) {
        if (res[i] == valColu) {
            return false;
        }
    }
    return true;
}

void calcQueen(vector<int> &res, int row) {

    if (row == 8) {
        printQueens(res);
        totalCount++;
        return;
    }
    for (int colu = 0; colu < 8; colu++) {
        if (is_Ok(res, row, colu)) {
            res[row] = colu;
            calcQueen(res, row + 1);
            res[row] = -1;
        }
    }
}


int main() {
    vector<int> res(8, -1);
    calcQueen(res, 0);
    cout<<"总攻找到: "<<totalCount<<"个"<<endl;
//可以得到总攻92中
}
