class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> freq;
        if(hand.size() % groupSize) return false;

        for(int num : hand) freq[num]++;

        for(int num : hand){
            int start = num;
            while(freq[start - 1]) start--;
            while(start <= num){
                while(freq[start] > 0){
                    for(int i = start; i < start + groupSize; ++i){
                        if(!freq[i]) return false;
                        freq[i]--;
                    }
                }
                start++;
            }
        }

        return true;
    }
};
