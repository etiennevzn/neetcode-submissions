class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;

        vector<int> prefixes(n);
        vector<int> sufixes(n);

        prefixes[0] = height[0];
        for(int i = 1; i < n; ++i){
            prefixes[i] = max(height[i], prefixes[i-1]);
        }

        sufixes[n-1] = height[n-1];
        for(int i = n-2; i >= 0; --i){
            sufixes[i] = max(height[i], sufixes[i+1]);
        }

        int res = 0;
        for(int i = 0; i < n; ++i){
            res += min(prefixes[i], sufixes[i]) - height[i];
        }
        return res;
    }
};
