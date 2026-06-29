class Solution {
private:
    float computeTime(pair<int,int> carInfo, int target){
        int distance = target - carInfo.first;
        return (float)distance / carInfo.second;
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        stack<pair<int,int>> s;

        for(int i = 0; i < position.size(); ++i){
            cars.push_back({position[i], speed[i]});
        }

        std::sort(cars.begin(), cars.end());

        for(int i = cars.size()-1; i >= 0; --i){
            if(!s.empty()){
                if(computeTime(s.top(), target) < computeTime(cars[i], target)){
                    s.push(cars[i]);
                } 
            }else{
                s.push(cars[i]);
            }
        }

        return s.size();
    }
};
