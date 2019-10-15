#include <iostream>
#include <vector>
#include <string>
#include "sort.h"
using namespace std;

void test(vector<int>& vi){
    vi[0]=0;
}

int main() {
    vector<int> vi{3,1,2,5,4,9,6,7,3,8};
//    sort::bubbleSort(vi);
//    sort::selectSort(vi);
//    sort::insertSort(vi);
    sort::myMaxPileSort(vi);
    for(auto i: vi){
        cout<<i<<" ";
    }
}