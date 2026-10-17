class ThroneInheritance {
private:
    unordered_map<string, vector<string>> child;
    unordered_map<string, bool> alive;
    string king;
public:
    ThroneInheritance(string kingName) {
        king = kingName;
        alive[king] = true;
    }
    
    void birth(string parentName, string childName) {
        alive[childName] = true;
        child[parentName].push_back(childName);
    }
    
    void death(string name) {
        alive[name] = false;
    }

    void getSuccessor(const string& name, vector<string>& order){
        if(alive[name]) order.push_back(name);
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