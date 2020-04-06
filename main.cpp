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
    vector<forward_list<int>> vf(3);
    queue<int> q;
    q.push(3);
    q.push(1);
    q.push(2);
//    q.pop();
    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;
}