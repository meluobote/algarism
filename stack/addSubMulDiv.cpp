/*
 * 描述: 加减乘除运算解析的题目集合
 * 作者：meluobote
 * 日期: 2020/1/15
 */
/*
 * 1、华为面试题
 * 有字符串表示的一个四则运算表达式，要求计算出该表达式的正确数值。四则运算即：加减乘除，
 * 另外该表达式中的数字只能是1位（数值范围0~9），
 * 运算不用括号。另若有不能整除的情况，按向下取整处理，eg: 8/3得出值为2。
 * 举例：字符串"8+7*2-9/3"，计算出其值为19。
 */
#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <stack>
using namespace std;
/*
 * 思路: 加
 */
int huaWeiInterview(string s){
    if(s.empty()){
        return 0;
    }else if(s.size()==1){
        return s[0]-'0';
    }
    string s1='+'+s;
    cout<<"s1: "<<s1<<endl;
    int ret=0;

    char prevMulDiv;  //存储乘法前的符号
    int tmpmd{}; //存储临时的乘除运算结果

    for(int i=0;i<s1.size();){
        if(i+2 < s1.size() && (s1[i+2]=='*' || s1[i+2]=='/')){
            tmpmd=s1[i+1]-'0';;
            prevMulDiv=s1[i];
            i+=2;
            while(i<s1.size()){
                if(s1[i]=='*'){
                    //乘法
                    tmpmd*=s1[i+1]-'0';
                }else if(s1[i]=='/'){
                    //除法
                    tmpmd/=s1[i+1]-'0';
                }else{
                    break;
                }
                i+=2;
            }
            if(prevMulDiv == '+'){
                ret+=tmpmd;
            }else{
                ret-=tmpmd;
            }

        }else if(s1[i]=='+'){
            ret+=s1[i+1]-'0';
            i+=2;
        }else if(s1[i]=='-'){
            ret-=s1[i+1]-'0';
            i+=2;
        }
        cout<<ret<<endl;
    }
    return ret;
}


int main(){
//    string s="8+7*2-9/3";
//    cout<<huaWeiInterview(s);
    random_device rd;
    cout<<rd()<<" "<<rd()<<endl;
    cout<<rd()<<" "<<rd()<<endl;

    vector<int> v{1,2,3,4,5};
    random_shuffle(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<(abs(-3)>2)<<endl;
    return 0;
}
