//
// SubSequence: 相对顺序一致， 但是可以不连续
//
#include <vector>
#include <string>
#include <iostream>
#include <memory.h>

using namespace std;

int getLongestCommonSubSequence(string s1, string s2){
    cout<<"len(s1): "<<s1.length()<<" "<<"len(s2): "<<s2.length()<<endl;
    int problemArray[s1.length()+1][s2.length()+1];
    for(int i=0;i<s1.length()+1;i++) {
        for (int j = 0; j < s2.length() + 1; j++) {
            if (i == 0 || j == 0) {
                problemArray[i][j] = 0;
            }else{
                if (s1[i-1] == s2[j-1]) {
                    problemArray[i][j] = problemArray[i - 1][j - 1] + 1;
                } else {
                    problemArray[i][j] = max(problemArray[i - 1][j], problemArray[i][j - 1]);
                }
            }

            cout<<problemArray[i][j]<<" ";
        }
        cout<<"\n";
    }

    int len_s1=s1.length();
    int len_s2=s2.length();
    string s;
    for(int i=len_s1, j=len_s2;;){

        cout<<"tmp: i: "<<i<<"j: "<<j<<" ,[i][j]: "<<problemArray[i][j]<<" ,[i-1][j]: "<<problemArray[i-1][j]<<" ,[i][j-1]: "<<problemArray[i][j-1]<<endl;
        if(problemArray[i][j]==problemArray[i][j-1]){
            j--;
        }else if(problemArray[i][j]==problemArray[i-1][j]){
            i--;
        }else if(problemArray[i][j]=problemArray[i-1][j-1]+1){
            s.push_back(s1[i-1]);
            i--;
            j--;
        }
        if(problemArray[i][j]==0){
            break;
         }
    }
    cout<<"string s:"<<s<<endl;
//    for(auto it=s.rbegin();it!=s.rend();it++){
//        cout<< *it <<endl;
//    }

    return problemArray[s1.length()][s2.length()];
}
int main(){
    string s1{"abcdefg"};
    string s2{"abxdfg"};
    cout<<getLongestCommonSubSequence(s1, s2)<<endl;
return 0;
}

