// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return (double)a.first / a.second > (double)b.first / b.second;
    }
  
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        vector<pair<int, int>> items;
        int n = val.size();
        
        for (int i = 0; i < n; i++) {
            items.push_back({val[i], wt[i]});
        }

        // Sort items by value-to-weight ratio in descending order
        sort(items.begin(), items.end(), cmp);

        double totalValue = 0;

        for (auto x : items) {
            if (capacity == 0) break;

            int take = min(capacity, x.second);
            totalValue += ((double)x.first / x.second) * take;
            capacity -= take;
        }

        return totalValue;
    }
};
