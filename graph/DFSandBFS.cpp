/*
 * 描述: 广度优先搜索和深度优先搜索
 * 作者：meluobote
 * 日期: 2020/4/6
 */
#include "Graph.h"


int main() {
    /*
     * 建图
     */
    Graph graph(8);
    graph.addEdge(0,1);
    graph.addEdge(0,3);
    graph.addEdge(1,2);
    graph.addEdge(1,4);
    graph.addEdge(3,4);
    graph.addEdge(2,5);
    graph.addEdge(4,5);
    graph.addEdge(4,6);
    graph.addEdge(5,7);
    graph.addEdge(6,7);

    //广度优先搜索
    graph.bfs(0,7);

}