//
// Created by meluobote on 2019/10/15.
//

#include "sort.h"
#include <iostream>
using namespace std;
/*冒泡排序*/
void sort::bubbleSort(vector<int>& vi){
    for(unsigned long long i=vi.size()-2;i>=0;i--){
        for(unsigned long long j=0;j<=i;j++){
            if(vi[j]>vi[j+1]){
                vi[j]=vi[j]+vi[j+1]-(vi[j+1]=vi[j]);
            }
        }
    }
}

/* 选择排序 */
void sort::selectSort(vector<int>& vi){
    unsigned long long minIdx;
    for(unsigned long long i=0;i<vi.size()-1;i++){
        minIdx=i+1;
        for(unsigned long long j=i+2;j<vi.size();j++){
            if(vi[minIdx]>vi[j]){
                minIdx=j;
            }
        }
        if(vi[i]>vi[minIdx]){
            vi[i]=vi[i]+vi[minIdx]-(vi[minIdx]=vi[i]);
        }
    }
}
/* 插入排序 */
void sort::insertSort(vector<int>& vi){
    for(unsigned long long i=1;i<vi.size();i++){
        int tmp=vi[i];
        unsigned long long j=i-1;   //已排好序的部分最后一个元素
        while(j>=0 && vi[j]>tmp){
            vi[j+1]=vi[j];
            j--;
        }
        vi[j+1]=tmp;
    }
}

/* 最大堆排序 */
void sort::MaxPileSort(vector<int>& vi){
    for(int  i= static_cast<int >(vi.size()-1); i>=0;i--){
        createMaxPile(vi, static_cast<int>(vi.size()-1), i);
    }

    for(int i=static_cast<int >(vi.size()-1);i>0;i--){
        vi[0]=vi[i]+vi[0] - (vi[i]=vi[0]);
        createMaxPile(vi, i-1, 0);
    }
}

// 索引位置i的左右子树都满足最大堆只有i需要判定时用的函数
void sort::createMaxPile(vector<int>& vi,int lastIdx, int i){
    int subMaxIdx;
    int left=2*i+1;
    int right=2*i+2;
    if(left> lastIdx){
        return;
    }else if(left == lastIdx){
        subMaxIdx=left;
    }else{
        subMaxIdx = vi[left]>vi[right]?left:right;
    }

    if(vi[i]<vi[subMaxIdx]){
        vi[i]=vi[i]+vi[subMaxIdx] - (vi[subMaxIdx]=vi[i]);
        createMaxPile(vi, lastIdx, subMaxIdx);
    }
}
/* 快速排序 */
void sort::quickSort(vector<int>& vi, int start, int end){
    if(start>=end)
        return;
    int tmp=vi[start];
    int left=start;
    int right=end;
    while(left<right){
        while(left<right && vi[right]>=tmp) right--;
        if(left<right){
            vi[left]=vi[right];
            left++;
        }
        while(left<right && vi[left]<=tmp) left++;
        if(left<right){
            vi[right]=vi[left];
            right--;
        }
    }
    vi[right]=tmp;
    quickSort(vi,start, right-1);
    quickSort(vi, right+1, end);
}

/*计数排序  假设数字的范围是 [0, 9]*/
void sort::countSort(vector<int>& v){
    vector<int> val(10, 0);
    for(auto& i:v){
        val[i]++;
    }
    for(int i=1;i<static_cast<int>(val.size());i++){
        val[i]+=val[i-1];
    }
    vector<int> vcp=v;
    for(int j=static_cast<int>(v.size()-1);j>=0;j--){
        v[val[vcp[j]]-1]=vcp[j];
        val[vcp[j]]-=1;
    }
}