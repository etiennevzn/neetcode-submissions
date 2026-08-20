class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> canFinance;
        int numProjects = capital.size();
        int done = 0;

        while(done < k){
            for(int i = 0; i < numProjects; ++i){
                if(capital[i] <= w){
                    canFinance.push(profits[i]);
                    capital[i] = INT_MAX;
                }
            }

            if(canFinance.empty()) break;
            int curProfit = canFinance.top();
            canFinance.pop();
            done++;
            w += curProfit;
        }

        return w;
    }
};