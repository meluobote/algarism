/* 创建一个堆、以及如何用堆来排序，动态获取第k大的元素
 * 描述:
 * 作者：meluobote
 * 日期: 2020/4/2
 */
#include <vector>
#include <iostream>

using namespace std;

void print(vector<int> &v) {
    for (auto e:v) {
        cout << e << " ";
    }
    cout << endl;
}

/*
 * 第一个元素的索引是0，那么左子元素2*i+1, 2*i+2;  父元素: (k-1)/2
 */
void makePile_downToUp(vector<int> &v, int idx) {
    int size = v.size();
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int tmp{};
    if (left > size - 1) {
        return;
    } else if (left == size - 1) {
        if (v[left] > v[idx]) {
            tmp = v[left];
            v[left] = v[idx];
            v[idx] = tmp;
            return;
        }
    } else {
        if (v[left] < v[right] && v[idx] < v[right]) {
            tmp = v[right];
            v[right] = v[idx];
            v[idx] = tmp;
            makePile_downToUp(v, right);
        } else if (v[left] >= v[right] && v[idx] < v[left]) {
            tmp = v[left];
            v[left] = v[idx];
            v[idx] = tmp;
            makePile_downToUp(v, left);
        }
    }
}

void makePileUpToDown(vector<int>& v, int idx){
    // idx: 要插入堆中的元素的下标
    int parent=(idx-1)>>1;
    int tmp{};
    if(v[parent]<v[idx]){
        tmp=v[parent];
        v[parent]=v[idx];
        v[idx]=tmp;
        makePileUpToDown(v, parent);
    }
}

/*
 * 创建堆
 */
void makePile(vector<int> &v) {
    //方法一： 自底向上
//    for (int i = v.size() - 1; i >= 0; i--) {
//        makePile_downToUp(v, i);
//    }

    //方法二： 将第一个元素看作已经建好的堆，后面的元素逐个插入堆中
    for(int size=2;size<=v.size();size++){
        //size=2时，代表插入数组中的第二个元素
        makePileUpToDown(v, size-1);
    }
}

// 删除堆顶元素
void deletePileTop(vector<int>& v){
    if(v.size()<2)
        return;
    int lastIdx=v.size()-1;
    int tmp{};

    v[0]=v[lastIdx];
    v.pop_back();
    makePile_downToUp(v, 0);
}
// 往堆中插入元素
void pileInsertEle(vector<int>& v, int val){
    v.push_back(val);
    makePileUpToDown(v, v.size()-1);
}
int main() {
    vector<int> v{1,2,3,6,5,4};
    makePile(v);
    print(v);
    deletePileTop(v);
    print(v);
    pileInsertEle(v, 10);
    print(v);
}