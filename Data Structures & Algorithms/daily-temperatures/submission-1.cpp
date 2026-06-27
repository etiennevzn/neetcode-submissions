class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> res(temperatures.size(), 0);

        for(int i = 0; i < temperatures.size(); ++i){
            if(!s.empty()){
                while(!s.empty() && temperatures[s.top()] < temperatures[i]){
                    res[s.top()] = i - s.top();
                    s.pop();
                }
            }

            s.push(i);
        }

        return res;
    }
};
