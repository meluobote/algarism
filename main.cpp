#include <iostream>
#include <vector>
#include "sort.h"
using namespace std;


int main() {
    vector<int> vi{2,1,3,23,21,25,57,36,35};
//    vector<int> vi{2,1,3};
//    vector<int> vi{3};
//    sort::bubbleSort(vi);
//    sort::selectSort(vi);
//    sort::insertSort(vi);
//    sort::MaxPileSort(vi);
//    sort::quickSort(vi,0,vi.size()-1);
//    sort::countSort(vi);
//    vector<int> vi={19, 15, 27, 13, 25};
    sort::regdexSort(vi, 2);
    for(auto i: vi){
        cout<<i<<" ";
    }
}