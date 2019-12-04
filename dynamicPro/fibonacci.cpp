//
// 斐波那契数列求解
//
#include <iostream>
#include <vector>

using namespace std;

int calcdfibonacci(int n) {
    static vector<int> resv{0, 1};
    if(n<resv.size()){
        return resv[n];
    }
    int fibonaccin_1= calcdfibonacci(n-1);
    int fibonacci_2= calcdfibonacci(n-2);
    int ret=fibonaccin_1+fibonacci_2;
    resv.push_back(ret);
    return ret;
}

int main() {
    cout<<"fibonacci: "<<calcdfibonacci(8)<<"\n";
//    for(auto i: resv){
//        cout<<i<<" ";
//    }
//    cout<<"\n";
}
