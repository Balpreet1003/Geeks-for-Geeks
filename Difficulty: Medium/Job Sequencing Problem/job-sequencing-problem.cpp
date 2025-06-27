class Solution {
public:
    vector<int> jobSequencing(vector<int> &a, vector<int> &b) {
        int n = a.size();
        vector<pair<int, int>> jobs; // {profit, deadline}
        for (int i = 0; i < n; i++) {
            jobs.push_back({b[i], a[i]});
        }

        // Sort jobs in descending order of profit
        sort(jobs.rbegin(), jobs.rend());

        int max_deadline = *max_element(a.begin(), a.end());
        vector<int> slot(max_deadline + 1, -1); // -1 means free

        int count = 0, profit = 0;

        for (auto &job : jobs) {
            int jobProfit = job.first;
            int deadline = job.second;

            // Find a free slot from deadline down to 1
            for (int t = deadline; t > 0; t--) {
                if (slot[t] == -1) {
                    slot[t] = 1; // Mark slot as occupied
                    count++;
                    profit += jobProfit;
                    break;
                }
            }
        }

        return {count, profit};
    }
};