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
        int i = 0;

        while(k--){
            while(i < numProjects && projects[i].first <= w){
                canFinance.push(projects[i++].second);
            }

            if(canFinance.empty()) break;
            w += canFinance.top();
            canFinance.pop();
        }

        return w;
    }
};