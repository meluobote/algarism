//
// 斐波那契数列求解
//
#include <iostream>
#include <vector>

using namespace std;
static vector<int> resv{0, 1};
int calcdfibonacci(int n) {

    if(n<resv.size()){
        return resv[n];
    }
    int fibonaccin_1= calcdfibonacci(n-1);
    int fibonacci_2= calcdfibonacci(n-2);
    resv.push_back(fibonacci_2);
    return fibonacci_2+fibonaccin_1;
}

int main() {
    cout<<"fibonacci: "<<calcdfibonacci(8)<<"\n";
    for(auto i: resv){
        cout<<i<<" ";
    }
    cout<<"\n";
}
