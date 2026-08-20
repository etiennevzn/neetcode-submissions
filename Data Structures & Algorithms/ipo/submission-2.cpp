class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> canFinance;
        int numProjects = capital.size();
        int done = 0;

        for(int i = 0; i < numProjects; ++i){
            if(capital[i] <= w){
                canFinance.push(profits[i]);
                capital[i] = INT_MAX;
            }
        }

        while(!canFinance.empty() && done < k){
            int curProfit = canFinance.top();
            canFinance.pop();
            done++;
            w += curProfit;

            for(int i = 0; i < numProjects; ++i){
                if(capital[i] <= w){
                    canFinance.push(profits[i]);
                    capital[i] = INT_MAX;
                }
            }
        }

        return w;
    }
};