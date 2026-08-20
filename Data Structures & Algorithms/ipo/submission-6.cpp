class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> canFinance;
        int numProjects = capital.size();

        vector<pair<int,int>> projects;
        for(int i = 0; i < numProjects; ++i){
            projects.emplace_back(capital[i], profits[i]);
        }

        sort(projects.begin(), projects.end());
        int i = 0, done = 0;

        while(done < k){
            while(i < numProjects && projects[i].first <= w){
                canFinance.push(projects[i++].second);
            }

            if(canFinance.empty()) break;
            int curProfit = canFinance.top();
            canFinance.pop();
            w += curProfit;
            done++;
        }

        return w;
    }
};