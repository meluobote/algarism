#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <cmath>
#include <map>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
void printVec(vector<int>& vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end(), greater<int>());
        int count=nums.size();
        for(int i=0;i<count-k;i++){
            nums[0]=nums[nums.size()-1]+nums[0]-(nums[nums.size()-1]=nums[0]);
            nums.pop_back();
            make_heap(nums.begin(), nums.end(), greater<int>());
            printVec(nums);
        }
        return nums[0];
    }

int main() {
    vector<int> nums{3,2,1,5,6,4};
//    int ret=findKthLargest(nums, 2);
//    cout<<"kth: "<<ret<<endl;
    int mid=nums.size()/2;
    vector<int> v1(nums.begin(),nums.begin());
    printVec(v1);
    cout<<"不能打印中文吗?"<<endl;
}