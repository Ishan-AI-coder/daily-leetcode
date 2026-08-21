class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {

        sort(prices.rbegin(), prices.rend());
        sort(discounts.rbegin(), discounts.rend());

        double min_price = 0;

        int size = min(prices.size(), discounts.size());
        for(int i = 0; i < size; i++)
        {
            min_price += (prices[i] * (100 - discounts[i])) / 100.0;
        }
        for(int i = size; i < prices.size(); i++)
        {
            min_price += prices[i];
        }

        return min_price;
    }
};