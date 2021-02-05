int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto n : nums){
            freq[n]++;
		}
        
        int res = 0;
        for (auto iter : freq) {
            if (freq.find(iter.first+1) != freq.end()){
                res = max(res, iter.second + freq[iter.first+1]);
            }
        }
        return res;
    }