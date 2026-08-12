class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> direIdx;
        queue<int> radiantIdx;
        int n = senate.size();

        for(int i = 0; i < n; ++i){
            if(senate[i] == 'R'){
                radiantIdx.push(i);
            }else{
                direIdx.push(i);
            }
        }

        while(!direIdx.empty() && !radiantIdx.empty()){
            int dire = direIdx.front(); direIdx.pop();
            int radiant = radiantIdx.front(); radiantIdx.pop();

            if(dire < radiant){
                direIdx.push(dire + n);
            }else{
                radiantIdx.push(radiant + n);
            }
        }

        return direIdx.empty() ? "Radiant" : "Dire";
    }
};