class DSU {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int n) : parent(n), rank(n, 1){
        for(int i = 0; i < n; ++i){
            parent[i] = i;
        }
    }

    int find(int n){
        if(parent[n] != n){
            parent[n] = find(parent[n]);
        }
        return parent[n];
    }

    bool unionSet(int a, int b){
        int pa = find(a), pb = find(b);
        if(pa == pb) return false;

        if(rank[pa] < rank[pb]){
            parent[pa] = pb;
            rank[pb] += rank[pa];
        }else{
            parent[pb] = pa;
            rank[pa] += rank[pb];
        }

        return true;
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU dsu(n);
        unordered_map<string, int> eToA;

        for(int i = 0; i < accounts.size(); ++i){
            const auto& acc = accounts[i];
            for(int j = 1; j < acc.size(); ++j){
                if(eToA.count(acc[j])){
                    dsu.unionSet(eToA[acc[j]], i);
                }else{
                    eToA[acc[j]] = i;
                }
            }
        }

        unordered_map<int, vector<string>> aToE;
        for(auto& [email, acc] : eToA){
            aToE[dsu.find(acc)].push_back(email);
        }
        
        vector<vector<string>> res;
        for(auto& [acc, emails] : aToE){
            vector<string> account;
            sort(emails.begin(), emails.end());
            account.push_back(accounts[acc][0]);
            for(auto& email : emails){
                account.push_back(email);
            }
            res.push_back(account);
        }

        return res;
    }
};