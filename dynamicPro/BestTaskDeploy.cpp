/*
 * 问题描述： 一个人要在0点-11点之间做任务， 每个任务包含一段时间，完成后有一定的金币奖励。 不可以同时做两个任务，问最多赚多少钱
 *  说明：某点开始和某点结束的位置旁边的两个任务可以同时做。
 *  0~11见有8个任务，如下
 *  任务编号    开始时间    终止时间    金币奖励
 *  1           1       4           5
 *  2           3       5           1
 *  3           0       6           8
*   4           4       7           4
 *  5           3       8           6
 *  6           5       9           3
 *  7           6       10          2
 *  8           8       11          4
 */
#include <iostream>
#include <vector>

using namespace std;

class Task {
private:
    int xh;
    int starttime;
    int endtime;
    int reward;
public:
    Task(int xh, int starttime, int endtime, int reward)
            : xh(xh), starttime(starttime), endtime(endtime), reward(reward) {}

    //将this的起始时间和other的终止时间作比较， 如果 >=, 那么返回true;
    bool operator>=(Task other) {
        return this->starttime >= other.getEndtime();
    }

    int getXh() const {
        return xh;
    }

    int getStarttime() const {
        return starttime;
    }

    int getEndtime() const {
        return endtime;
    }

    int getReward() const {
        return reward;
    }
};

/*
 * task的xh-1对应于其存储的vt中的位置
 */
int prev(vector<Task> vt, int xh) {
    for (int i = xh - 2; i >= 0; i--) {
        if (vt[xh - 1] >= vt[i]) {  //如果cur的起始时间 >= vt[i]的终止时间
            return i + 1;
        }
    }
    return -1;
}

/*
 * 写递归分治处理
 * 前xh个任务中的最优解
 */
vector<int> bestOpt;  //设置初始的参照任务0，奖励为0
int start(vector<Task>& vt, int xh,vector<int>& stragety) {
    if (xh < 0)
        return 0;
    if (bestOpt[xh] >= 0)
        return bestOpt[xh];

    int noXhBestOpt = start(vt, xh - 1, stragety);
    int prevBestOpt{};
    int prevTaskXh;
    int haveXhBestOpt;
    if ((prevTaskXh = prev(vt, xh)) < 0) {
        prevBestOpt = 0;
    } else {
        prevBestOpt = start(vt, prevTaskXh, stragety);
    }
    cout << "xh: " << xh << " prevTaskXh: " << prevTaskXh << endl;
    haveXhBestOpt = vt[xh - 1].getReward() + prevBestOpt;
    if(noXhBestOpt>haveXhBestOpt){
        bestOpt[xh]=noXhBestOpt;
    }else{
        bestOpt[xh]=haveXhBestOpt;
        stragety.push_back(xh);
    }
    return bestOpt[xh];
}

int main() {
    /*
     *  任务编号    开始时间    终止时间    金币奖励
     *  1           1       4           5
     *  2           3       5           1
     *  3           0       6           8
     *  4           4       7           4
     *  5           3       8           6
     *  6           5       9           3
     *  7           6       10          2
     *  8           8       11          4
     */
    vector<Task> vt;
    vector<int> stragety{}; //存储最佳策略的任务号
    vt.push_back(Task(1, 1, 4, 5));
    vt.push_back(Task(2, 3, 5, 1));
    vt.push_back(Task(3, 0, 6, 8));
    vt.push_back(Task(4, 4, 7, 4));
    vt.push_back(Task(5, 3, 8, 6));
    vt.push_back(Task(6, 5, 9, 3));
    vt.push_back(Task(7, 6, 10, 2));
    vt.push_back(Task(8, 8, 11, 4));
//    for(int i=0;i<vt.size();i++){
//        cout<<(int)vt[i].getXh()<<" "<<(int)vt[i].getStarttime()<<" "<<(int)vt[i].getEndtime()<<" "<<(int)vt[i].getReward()<<endl;
//    }

    bestOpt.resize(vt.size() + 1);
    bestOpt[0] = 0;
    for (int i = 1; i < bestOpt.size(); i++) {
        bestOpt[i] = -1;
    }

    cout << start(vt, 8, stragety) << endl;
    for(int i=0;i<stragety.size();i++){
        cout<<stragety[i]<<" ";
    }
    cout<<"\n";
//    for(int i=0;i<bestOpt.size();i++){
//        cout<<bestOpt[i]<<" ";
//    }
//    cout<<(vt[2]>=vt[1])<<" "<<(vt[2]>=vt[0])<<endl;
}
/*
 * 1    5
*   2   5
 *  3
 */
