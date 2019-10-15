#include <iostream>
#include <vector>
#include "sort.h"
using namespace std;


int main() {
    vector<int> vi{3,1,2,5,4,9,6,7,3,8};
//    vector<int> vi{3};
//    sort::bubbleSort(vi);
//    sort::selectSort(vi);
//    sort::insertSort(vi);
    sort::MaxPileSort(vi);
    for(auto i: vi){
        cout<<i<<" ";
    }
}