/*
 * 描述: 二叉树按层遍历实现（1） 队列实现
 * 作者：meluobote
 * 日期: 2020/4/1
 */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*
 * 简单的树结构定义（数据存储不是void*类型， 也不能自定义比较方式）
 */
typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} node_t;

/*
 *1、vector是一个完全二叉堆
 * 2、idx为head节点中数据对应在v中的索引
 */
void createTree(vector<int> &v, node_t *head, int idx) {
    int size = v.size();
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left > size - 1) {
        head->left = nullptr;
        head->right = nullptr;
        return;
    } else if (left == size - 1) {
        head->right = nullptr;
        node_t *leftNode = new Node;
        leftNode->data = v[left];
        head->left = leftNode;
        return;
    } else {
        node_t *leftNode = new Node;
        leftNode->data = v[left];
        head->left = leftNode;
        node_t *rightNode = new Node;
        rightNode->data = v[right];
        head->right = rightNode;
        createTree(v, leftNode, left);
        createTree(v, rightNode, right);
    }
}

void deleteTree(node_t *root) {
    if (root == nullptr)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}
/*
 * 树按层遍历： 打印为一行
 */
void traverseByLayer(node_t *root) {
    queue<node_t *> qn;
    qn.push(root);
    while (!qn.empty()) {
        node_t *tmp = qn.front();
        qn.pop();
        cout << tmp->data << " ";
        if (tmp->left != nullptr) {
            qn.push(tmp->left);
        }
        if (tmp->right != nullptr) {
            qn.push(tmp->right);
        }
    }
}

int main() {
    vector<int> v{9, 8, 7, 6, 5, 4, 3, 1, 2};
    node_t *root = new Node;
    root->data = v[0];
    createTree(v, root, 0);
    traverseByLayer(root);
    deleteTree(root);
}