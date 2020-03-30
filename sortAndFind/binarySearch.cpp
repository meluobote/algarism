/*
 * 描述: 查找到，然后返回在升序数组中的索引位置; 如果找不到，返回-1.
 *  1)  简单的二分查找： 没有重复元素的有序数组
 *  2) 二叉查找应用之求一个数的平方根
 *  3) 二叉查找的变形（有序数组中有重复值）
 *      a, 第一个等于给定值的元素
 *      b, 最后一个等于给定值的元素
 *      c, 第一个大于等于给定值的元素
 *      d, 最后一个小于等于给定值的元素
 *
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

/*求一个数的平方根，精确到小数点后n位
 *  说明：
 *      1、下面的解法并没有考虑4舍5入的问题，只是保证了误差不会大于小数点后n-1位再加个1.
 *      2、 double类型只能保留到小数点后6位，因此不支持更大的位数
 *      3、 只写了num>1的情况，<1类似就不写了
 */
void mySqrt(int num, int precion){
    if(num>1){
        double low=1;
        double high=num;
        double jd=pow(10, -precion);
        double mid{};
        while(high-low>=jd){
            mid=low+(high-low)/2;
            if(pow(mid, 2)>=num){
                high=mid;
            }else{
                low=mid;
            }
        }
        cout<<"sqrt: "<<mid<<endl;
    }
}
// 二分查找变形 a, 第一个等于给定值的元素
int binarySearch_firstEqVal(vector<int> &v, int val) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);  //这里注意>>运算符优先级比+低， 需加上括号
        if (val == v[mid]) {
            if(mid==0 || (mid>0&&v[mid-1]!=val))
                return mid;
            else{
                right=right-1;
            }
        } else if (val > v[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}
// 二分查找变形 b, 最后一个等于给定值的元素
int binarySearch_lastEqVal(vector<int> &v, int val) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);  //这里注意>>运算符优先级比+低， 需加上括号
        if (val == v[mid]) {
            if(mid==v.size()-1 || v[mid+1]!=val)
                return mid;
            else{
                left=left+1;
            }
        } else if (val > v[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

// 二分查找变形 c, 第一个大于等于给定值的元素
int binarySearch_firstGtEqVal(vector<int> &v, int val) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);  //这里注意>>运算符优先级比+低， 需加上括号
        if (val >= v[mid]) {
            if(mid==v.size()-1 || v[mid+1]!=val)
                return mid;
            else{
                left=left+1;
            }
        } else if (val > v[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> v{1, 2,2,2,2,10};
//    mySqrt(2, 3);
//    cout<<"first idx:"<<binarySearch_firstEqVal(v, 2);
    cout<<"last idx: "<<binarySearch_lastEqVal(v, 2);
}
