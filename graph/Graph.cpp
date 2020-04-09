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
                prev[t] = next;
                break;
            }
            if (!is_visted[son]) {
                prev[son] = next;
                descent.push(son);
                is_visted[son] = true;
            }
        }
    }
    if (prev[t] != -1) {
        printRoute(prev, s, t);
    } else {
        cout << "No route is finded" << endl;
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

void Graph::printRoute(vector<int> &prev, int s, int v) {
    if (prev[v] != -1 && s != v) {
        printRoute(prev, s, prev[v]);
    }
    cout << v << " ";
}
/*
 * �������
 *      s: ���ĸ��ڵ㿪ʼ����
 *      t��Ҫ���ҵ�Ԫ��
 * ����ֵ
 *      false  û�ҵ�
 *      true  �ҵ���
 */
bool Graph::dfsRecur(vector<bool> &is_visted, int s,  int t){
    if(s==t){
        return true;
    }else{
        for(int descent: this->vfl[s]){
            if(!is_visted[descent]){
                is_visted[descent]=true;
                if(dfsRecur(is_visted, descent, t)){
                    this->dfsroute.push_back(descent);
                    return true;
                }
            }
        }
    }
    return false;
}

/*
 * dfs ���õݹ�ķ�ʽ
 */
void Graph::dfs(int s, int t) {
    if (s == t) {
        return;
    }
    this->dfsroute.clear();
    vector<bool> is_visted(vfl.size());
    is_visted[s] = true;
    if(dfsRecur(is_visted, s, t)){
        this->dfsroute.push_back(s);
    }else{
        cout<<"no route is finding";
    }
}

/*
 * dfs ����ջ�ķ�ʽ
 */
//void Graph::dfsWithStack(int s, int t) {
//
//}
