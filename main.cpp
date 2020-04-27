#include <vector>
#include <iostream>
#include<forward_list>
#include <queue>
using namespace std;
void print(vector<int>& v){
    for(auto e:v){
        cout<<e<<" ";
    }
    cout<<endl;
}

int main() {
//    vector<forward_list<int>> vf(3);
    vector<pair<int,int>> vp;
    vp.emplace_back(1,2);
    vp.push_back(pair<int, int>(3,2));
    vp.push_back(pair<int, int>(4,2));
    vp.push_back(pair<int, int>(2,2));
    for(auto p: vp){
        cout<<p.first<<" "<<p.second<<endl;d
    }

}