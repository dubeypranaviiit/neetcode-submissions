class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        int l1=0;
        int l2=0;
        string s="";
        while(l1<n1 && l2<n2){
          s+=word1[l1++];
          s+=word2[l2++];
        }
        while(l1<n1 ){
          s+=word1[l1++];
        }
         while(l2<n2){
          s+=word2[l2++];
        }
         return s;
    }
};