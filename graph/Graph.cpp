//
// Created by meluobote on 2020/4/6.
//

#include "Graph.h"
#include <array>
#include <queue>
#include <iostream>

using namespace std;

Graph::Graph(int v)
        : vfl(v) {

}

void Graph::addEdge(int s, int t) {
    vfl[s].push_front(t);
    vfl[t].push_front(s);
}

void Graph::bfs(int s, int t) {
    vector<bool> is_visted(this->vfl.size());
    queue<int> descent;
    vector<int> prev(this->vfl.size(), -1);

    is_visted[s] = true;
    descent.push(s);
    while (!descent.empty()) {
        int next = descent.front();
        descent.pop();
        for (int son: vfl[next]) {
            if (son == t) {
                prev[t]=next;
                break;
            }
            if (!is_visted[son]) {
                prev[son] = next;
                descent.push(son);
                is_visted[son]=true;
            }
        }
    }
    if(prev[t]!=-1){
        printRoute(prev, s, t);
    }else{
        cout<<"No route is finded"<<endl;
    }
}

//void Graph::printRoute(vector<int>& prev, int s, int v) {
//    int tmp=v;
//    cout<<"route: "<<v<<" ";
//    while(prev[tmp]!=-1){
//        cout<<prev[tmp]<<" ";
//        tmp=prev[tmp];
//    }
//    cout<<endl;
//}

void Graph::printRoute(vector<int>& prev, int s, int v) {
    if(prev[v]!=-1 && s!=v){
        printRoute(prev, s, prev[v]);
    }
    cout<<v<<" ";
}

void Graph::dfs(int s, int t) {

}
