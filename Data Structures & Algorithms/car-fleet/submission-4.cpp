class Solution {
private:
    double computeTime(pair<int,int> carInfo, int target){
        int distance = target - carInfo.first;
        return (double)distance / carInfo.second;
    }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        stack<double> s;

        for(int i = 0; i < position.size(); ++i){
            cars.push_back({position[i], speed[i]});
        }

        std::sort(cars.rbegin(), cars.rend());

        for(int i = 0; i < cars.size(); ++i){
            double time = computeTime(cars[i], target);
            if(!s.empty()){
                if(s.top() < time){
                    s.push(time);
                } 
            }else{
                s.push(time);
            }
        }

        return s.size();
    }
};
