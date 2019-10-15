//
// Created by meluobote on 2019/10/15.
//

#ifndef ALGARISM_SORT_H
#define ALGARISM_SORT_H

#include <vector>
using namespace std;

class sort {
private:
    static void createMaxPile(vector<int>& vi,int lastIdx, int i);
public:
    static void bubbleSort(vector<int>& vi);
    static void selectSort(vector<int>& vi);
    static  void insertSort(vector<int>& vi);
    static void MaxPileSort(vector<int>& vi);
};


#endif //ALGARISM_SORT_H
