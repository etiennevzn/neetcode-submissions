class ThroneInheritance {
private:
    unordered_map<string, vector<string>> child;
    unordered_set<string> dead;
    string king;
public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        child[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }

    void getSuccessor(const string& name, vector<string>& order){
        if(!dead.count(name)) order.push_back(name);
        for(const string& children : child[name]){
            getSuccessor(children, order);
        }
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> order;
        getSuccessor(king, order);
        return order;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */