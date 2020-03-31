/*
 * 描述: 查找到，然后返回在升序数组中的索引位置; 如果找不到，返回-1.
 *  1)  简单的二分查找： 没有重复元素的有序数组
 *  2) 二叉查找应用之求一个数的平方根
 *  3) 二叉查找的变形（有序数组中有重复值）
 *      a, 第一个等于给定值的元素
 *      b, 最后一个等于给定值的元素
 *      c, 第一个大于等于给定值的元素
 *      d, 最后一个小于等于给定值的元素
 *  4) 循环数组中二叉查找
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
                right=mid-1;
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
                left=mid+1;
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
        if (val <= v[mid]) {
            if(mid==0 || v[mid-1]<val)
                return mid;
            else{
                right=mid-1;
            }
        }else {
            left=mid+1;
        }
    }
    return -1;
}

// 二叉变形：d, 最后一个小于等于给定值的元素
int binarySearch_lastLeEqVal(vector<int> &v, int val) {
    int left = 0;
    int right = v.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);  //这里注意>>运算符优先级比+低， 需加上括号
        if (val >= v[mid]) {
            if(mid==v.size()-1 || v[mid+1]>val)
                return mid;
            else{
                left=mid+1; //此时结果肯定在mid后面
            }
        }else {
            right = mid - 1;
        }
    }

    return -1;
}

//循环数组中的二叉查找
//目前不考虑存在重复元素的问题
int binarySearch_cycleArray(vector<int>& v, int val){
    if(v[v.size()-1]==val){
        return v.size()-1;
    }else if(v[0]==val){
        return 0;
    }
    int lastEle=v[v.size()-1];
    int firstEle=v[0];

    int left=0;
    int right=v.size()-1;
    int mid{};
    while(left<=right){
        mid=left+((right-left)>>1);
        if(v[mid]==val){
            return mid;
            //如果0~n-1刚好是升序的
        }else if(firstEle<lastEle){

            if(v[mid]<val){
                left=mid+1;
            }else{
                right=mid-1;
            }
            //如果是非常规的
        }else{
            //mid在尾结点的左边
            if(v[mid]>v[0]){
                //根据val和mid的大小关系，在mid左边1种情况，mid右边两种情况，故取左边的情况作为if判断的条件
                if(val<v[mid]&&val>v[0]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            // mid在尾结点的右边
            }else{
                //根据val和mid的大小关系，在mid左边2种情况，mid右边1种情况，故取右边边的情况作为if判断的条件
                if(val>v[mid]&&val<lastEle){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
    }

    return -1;
}
int main() {
    vector<int> v{8,9,12,3, 5,6,7};
//    mySqrt(2, 3);
//    cout<<"first idx:"<<binarySearch_firstEqVal(v, 2);
//    cout<<"last idx: "<<binarySearch_lastEqVal(v, 2);
//    cout<<"firstGtEqVal: "<<binarySearch_firstGtEqVal(v, 4)<<endl;
//    cout<<"firstGtEqVal: "<<binarySearch_firstGtEqVal(v, 6)<<endl;
//    cout<<"lastLeEqVal: "<<binarySearch_lastLeEqVal(v, 6);
//    cout<<"lastLeEqVal: "<<binarySearch_lastLeEqVal(v, 12);
//    cout<<"lastLeEqVal: "<<binarySearch_lastLeEqVal(v, -2);
    cout<<"cycleBinarySearch: "<<binarySearch_cycleArray(v, 8)<<endl;
    cout<<"cycleBinarySearch: "<<binarySearch_cycleArray(v, 7)<<endl;
    cout<<"cycleBinarySearch: "<<binarySearch_cycleArray(v, 9)<<endl;
    cout<<"cycleBinarySearch: "<<binarySearch_cycleArray(v, 10)<<endl;
    cout<<"cycleBinarySearch: "<<binarySearch_cycleArray(v, 3)<<endl;
    cout<<"cycleBinarySearch: "<<binarySearch_cycleArray(v, 5)<<endl;
    cout<<"cycleBinarySearch: "<<binarySearch_cycleArray(v, 4)<<endl;
    cout<<"cycleBinarySearch: "<<binarySearch_cycleArray(v, 11)<<endl;
}
