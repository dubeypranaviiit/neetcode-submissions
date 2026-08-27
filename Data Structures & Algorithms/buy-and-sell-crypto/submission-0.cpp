class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prev=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>=prev){
                ans=max(ans,prices[i]-prev);
            }
            prev=min(prev,prices[i]);
        }
        return ans==INT_MAX ?0:ans;
    }
};
