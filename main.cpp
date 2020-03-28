#include <vector>
#include <iostream>

using namespace std;
void print(vector<int>& v){
    for(auto e:v){
        cout<<e<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> v{3,2,1,5,6,4,5,2};

}