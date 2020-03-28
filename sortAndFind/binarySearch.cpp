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
void print(vector<int>& v){
    for(auto e:v){
        cout<<e<<" ";
    }
    cout<<endl;
}

//没有重复元素的二分查找 - 递归实现
int binarySearch_noReapeat1(vector<int>& v, int st, int end, int val){
    if(st==end){
        if(v[st]==val){
            return st;
        }
        return -1;
    }else if( st>end){
        return -1;
    }
    int mid=st+(end-st)/2;
    if(v[mid]==val){
        return mid;
    }else if(v[mid]<val){
        return binarySearch_noReapeat1(v, mid+1, end, val);
    }else{
        return binarySearch_noReapeat1(v, st, mid-1);
    }
    return -1;
}
//没有重复元素的二分查找 - 非递归实现
void binarySearch_noReapeat2(vector<int>& v){

}


int main() {
    vector<int> v1{1,3,5,7,9};

}
