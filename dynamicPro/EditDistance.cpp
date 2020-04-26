/*
 * 描述:
 *  编辑距离：将一个字符串转化成另一个字符串，需要的最少编辑操作次数（比如增加一个字符、删除一个字符、替换一个字符）。
 *  编辑距离越大，说明两个字符串的相似程度越小
 *  莱文斯坦距离（Levenshtein distance）和最长公共子串长度（Longest common substring length）。其中，莱文斯坦距离允许增加、删除、替换字符这三个编辑操作，最长公共子串长度只允许增加、删除字符这两个编辑操作。
 *
 * 作者：meluobote
 * 日期: 2020/4/26
 */
#include <vector>
#include <iostream>
#include <string>

using namespace std;
/*
 * 莱文斯坦距离计算
 */
void levenshteinDistance(string src, string dst){
    int len_src=src.size();
    int len_dst=dst.size();
    vector<vector<int>> dyn(len_src+1, vector<int>(len_dst+1, 0));

    for(int i=0;i<=len_src;i++){
        dyn[i][0]=i;
    }
    for(int j=0;j<len_dst;j++){
        dyn[0][j]=j;
    }

    for(int i=1;i<=len_src;i++){
        for(int j=1;j<=len_dst;j++){
            //如果字符相等，那么转换的次数应该和左上角的一致；
            /*
             * 当前行比上一行小:说明编辑距离只能通过增删改三种方式来修改。
             *    当前行比上一行多了一个字母，如果多了这个字母后反而少了一步操作，那么如果多了这个字母反而少了操作，
             *    那么说明加这个字母抵消了之前上一行编辑转换过程中的操作，很明显只能代表新增，因为多一个字母，故抵消了一步的新增操作。
             *    所以可能比上一行小，但只能小于1.
             *    同理当前列比前一列小是因为抵消了src字符串的一个删除操作，少删除一步。
             */
            /*
             * 根据上面的结论： 如果某个位置两个箱等， 那么三种操作中左上角的一定<=左边和上面的操作的。
             * 因为： 左边代表的是新增一个字母来让他们相等，  左边+1代表编辑距离
             *      上边代表的是删除一个字母来让他们相等，  上边+1代表编辑距离
         *      加上上面的结论可知，左上角的结论一定是最优的(说明： 最优不一定只有一个)
             */
            if(src[i]==dst[j]){
                dyn[i][j]=dyn[i-1][j-1];
            }else{
                int i_upd=dyn[i-1][j-1]+1;  //修改
                int i_ins=dyn[i][j-1]+1;  //插入,针对左边匹配后，插入一个字母
                int i_del=dyn[i-1][j]+1;  //删除：上边已经匹配了，当前行又追加了一个，再删除这个就可以匹配上了。
                dyn[i][j]= min(min(i_upd, i_ins), i_del);
            }

        }
    }
    cout<<"edit distance is "<<dyn[len_src][len_dst]<<endl;
}

int main() {
    string src="mtacnu";
    string dst="mitcmu";
    levenshteinDistance(src, dst);
}
