class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;

        for(int a : asteroids){
            while(a < 0 && !stack.empty() && stack.back() > 0){
                int diff = a + stack.back();
                if(diff < 0){
                    stack.pop_back();
                }else if(diff > 0){
                    a = 0;
                }else{
                    stack.pop_back();
                    a = 0;
                }
            }

            if(a != 0){
                stack.push_back(a);
            }
        }

        return stack;
    }
};