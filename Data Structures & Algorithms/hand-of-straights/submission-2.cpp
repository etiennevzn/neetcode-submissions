class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> freq;
        if(hand.size() % groupSize) return false;

        for(int card : hand) freq[card]++;

        sort(hand.begin(), hand.end());

        for(int i = 0; i < hand.size(); ++i){
            if(!freq[hand[i]]) continue;
            for(int j = hand[i]; j < hand[i] + groupSize; ++j){
                if(!freq[j]) return false;
                freq[j]--;
            }
        }

        return true;
    }
};
