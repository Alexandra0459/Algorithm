class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return 0;
        }
        int minPrice = prices[0];
        int maxProfit = 0;
        vector<int> dpFirst(prices.size(), 0);
        
        for(int i=0; i<prices.size(); i++){
            if(prices[i]<minPrice){
                minPrice = prices[i];
            }else if(prices[i]-minPrice>maxProfit){
                maxProfit = prices[i]-minPrice;
            }
            dpFirst[i] = maxProfit;
        }
        
        maxProfit = 0;
        int maxPrice = prices[prices.size()-1];
        int tempProfit = 0;
        for(int i=prices.size()-1; i>=0; i--){
            if(prices[i]>maxPrice){
                maxPrice = prices[i];
            }else if(maxPrice-prices[i]>maxProfit){
                maxProfit = maxPrice-prices[i];
            }
            if(i!=0 && maxProfit+dpFirst[i]>tempProfit){
                tempProfit = maxProfit+dpFirst[i-1];
            }else if(i==0 && maxProfit>tempProfit){
                tempProfit = maxProfit;
            }
        }
        return tempProfit;
    }
};