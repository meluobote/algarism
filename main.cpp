#include <iostream>
#include <vector>
#include <set>
#include "sort.h"
#include <climits>
#include <cmath>
#include "dynamicPro/CutRod.h"
using namespace std;

int main() {
    map<int, int> tab{{1,1},{2,5},
                      {3,8},{4,9},
                      {5,10},{6,17},
                      {7,17},{8,20},
                      {9,24},{10,30},
    };
    /*
    r 1 D 1 from solution 1 D 1 (no cuts) ;
    r 2 D 5 from solution 2 D 2 (no cuts) ;
    r 3 D 8 from solution 3 D 3 (no cuts) ;
    r 4 D 10 from solution 4 D 2 C 2 ;
    r 5 D 13 from solution 5 D 2 C 3 ;
    r 6 D 17 from solution 6 D 6 (no cuts) ;
    r 7 D 18 from solution 7 D 1 C 6 or 7 D 2 C 2 C 3 ;
    r 8 D 22 from solution 8 D 2 C 6 ;
    r 9 D 25 from solution 9 D 3 C 6 ;
    r 10 D 30 from solution 10 D 10 (no cuts) :  */

    CutRod cr(tab);
//    cout << cr.getMaxProfit(7) << endl;
//    cout << cr.getMaxProfit(8) << endl;
//    cout << cr.getMaxProfit(9) << endl;
//    cout << cr.getMaxProfit(15    ) << endl;
    set<int> v1{1,2,3,4,5};
    set<int> v2{1,2,3,5,4};
    set<int> v3{1,3,2,5,4};
    set<int> v4{3,2,1,5,4};
    set<int> v5{2,1,3,5,4};
//    vector<int> v6{1,2,3,4,5};
    if(v1==v2){
        cout<<"true"<<endl;
    }
        if(v1==v3){
        cout<<"true"<<endl;
    }
            if(v1==v4){
        cout<<"true"<<endl;
    }
                if(v1==v5){
        cout<<"true"<<endl;
    }

}