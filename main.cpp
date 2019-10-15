#include <iostream>
#include <vector>
#include <string>
#include "sort.h"
using namespace std;

void test(vector<int>& vi){
    vi[0]=0;
}

int main() {
    vector<int> vi{3,1,2,5,4};
//    sort::bubbleSort(vi);
//    sort::selectSort(vi);
    sort::insertSort(vi);
    for(auto i: vi){
        cout<<i<<" ";
    }
}