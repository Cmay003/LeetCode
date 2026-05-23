class Solution {
public:
    int getLeastFrequentDigit(int n) {
        vector<int> arr;
        unordered_map<int,int> mpp;

        while(n > 0){
            int dig = n % 10;
            n /= 10;
            arr.push_back(dig);
        }

        for(int i = 0; i < arr.size(); i++){
            mpp[arr[i]]++;
        }
        
        int ans = 0;
        int minFreq = INT_MAX;

        for (auto &p : mpp) {
            if (p.second < minFreq) {
                minFreq = p.second;
                ans = p.first;
            }
            else if (p.second == minFreq && p.first < ans) {
                ans = p.first;
            }
        }
        return ans;
    }
};
