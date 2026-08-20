class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> canFinance;
        int numProjects = capital.size();
        int done = 0;
        if(*min_element(capital.begin(), capital.end()) > w) return w;

        while(done < k){
            for(int i = 0; i < numProjects; ++i){
                if(capital[i] <= w){
                    canFinance.push(profits[i]);
                    capital[i] = INT_MAX;
                }
            }

            int curProfit = canFinance.top();
            canFinance.pop();
            done++;
            w += curProfit;
        }

        return w;
    }
};