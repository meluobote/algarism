#include <iostream>
#include <vector>
#include "sort.h"
using namespace std;


int main() {
    vector<int> vi{3,1,2,5,4,9,6,7,3,8,2,1,3};
//    vector<int> vi{3};
//    sort::bubbleSort(vi);
//    sort::selectSort(vi);
//    sort::insertSort(vi);
//    sort::MaxPileSort(vi);
//    sort::quickSort(vi,0,vi.size()-1);
    sort::countSort(vi);
    for(auto i: vi){
        cout<<i<<" ";
    }
}