//
// Created by meluobote on 2019/10/15.
//

#include "sort.h"
#include <iostream>
/*ð������*/
void sort::bubbleSort(vector<int>& vi){
    for(unsigned long long i=vi.size()-2;i>=0;i--){
        for(unsigned long long j=0;j<=i;j++){
            if(vi[j]>vi[j+1]){
                vi[j]=vi[j]+vi[j+1]-(vi[j+1]=vi[j]);
            }
        }
    }
}

/* ѡ������ */
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
/* �������� */
void sort::insertSort(vector<int>& vi){
    for(unsigned long long i=1;i<vi.size();i++){
        int tmp=vi[i];
        unsigned long long j=i-1;   //���ź���Ĳ������һ��Ԫ��
        while(j>=0 && vi[j]>tmp){
            vi[j+1]=vi[j];
            j--;
        }
        vi[j+1]=tmp;
    }
}

/* �������� */
void sort::myMaxPileSort(vector<int>& vi){
    for(uint64_t  i=vi.size()-1; i>=0;i--){
        createMaxPile(vi, vi.size()-1, i);
    }

    for(uint64_t i=vi.size()-1;i>0;i--){
        vi[0]=vi[i]+vi[0] - (vi[i]=vi[0]);
        createMaxPile(vi, i-1, 0);
    }
}

// ����λ��i��������������������ֻ��i��Ҫ�ж�ʱ�õĺ���
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