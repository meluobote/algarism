//
// Created by meluobote on 2020/4/6.
//

#ifndef ALGARISM_GRAPH_H
#define ALGARISM_GRAPH_H

#include <vector>
#include <forward_list>
using namespace std;
// 无向图
//  广度优先搜索BFS  和 深度优先搜索DFS搜索
class Graph {
private:
    std::vector<std::forward_list<int>> vfl;

public:
    Graph(int v);
    void addEdge(int s, int t);
    void bfs(int s, int t); //广度优先搜索
    void printRoute(vector<int>& prev, int s, int v);
    void dfs(int s, int t); //深度优先搜索
};


#endif //ALGARISM_GRAPH_H
