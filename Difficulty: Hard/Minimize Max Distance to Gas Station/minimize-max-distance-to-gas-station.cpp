class Solution {
    bool is_possible(vector<int>& stations, double dis, int k) {
        int cnt = 0;
        for(int i = 1; i < stations.size(); i++) {
            cnt += (int)((stations[i] - stations[i-1]) / dis);
        }
        return cnt <= k;
    }
public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        double low = 0, high = stations.back() - stations.front();
        double eps = 1e-6;
        while(high - low > eps) {
            double mid = (low + high) / 2;
            if(is_possible(stations, mid, k)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return high;
    }
};