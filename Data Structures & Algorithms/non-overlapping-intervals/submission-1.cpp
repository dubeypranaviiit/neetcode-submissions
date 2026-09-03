class Solution {
public:
//   count number of  non overlapping interval  and then 
//  size- non overlapping interval
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int last=INT_MIN;
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
         int n=intervals.size(); 
         int nonOverlapping=0;  
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=last){
                nonOverlapping++;
                last=intervals[i][1];
            }
        }
        return n-nonOverlapping;
    }
};
