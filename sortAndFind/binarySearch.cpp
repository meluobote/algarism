/*
 * 描述: 查找到，然后返回在升序数组中的索引位置; 如果找不到，返回-1.
 *  1)  简单的二分查找： 没有重复元素的有序数组
 * 作者：meluobote
 * 日期: 2020/3/28
 */
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

void print(vector<int> &v) {
    for (auto e:v) {
        cout << e << " ";
    }
    cout << endl;
}

//没有重复元素的二分查找 - 递归实现
int binarySearch_noReapeat1(vector<int> &v, int st, int end, int val) {
    if (st == end) {
        if (v[st] == val) {
            return st;
        }
        return -1;
    } else if (st > end) {
        return -1;
    }
    int mid = st + (end - st) / 2;
    if (v[mid] == val) {
        return mid;
    } else if (v[mid] < val) {
        return binarySearch_noReapeat1(v, mid + 1, end, val);
    } else {
        return binarySearch_noReapeat1(v, st, mid - 1, val);
    }
    return -1;
}

//没有重复元素的二分查找 - 非递归实现
int binarySearch_noReapeat2(vector<int> &v, int val) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);  //这里注意>>运算符优先级比+低， 需加上括号
        if (val == v[mid]) {
            return mid;
        } else if (val > v[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}


int main() {
    vector<int> v{1, 3};
    cout << binarySearch_noReapeat2(v, 1) << endl;
    cout << binarySearch_noReapeat2(v, 3) << endl;
//    cout<<((2+3)>>1)<<endl;
}
