//
// Created by meluobote on 2019/10/15.
//

#include "sort.h"
#include <iostream>
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
