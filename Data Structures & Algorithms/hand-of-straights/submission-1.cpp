class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> freq;
        if(hand.size() % groupSize) return false;
        int total = hand.size() / groupSize;

        for(int card : hand){
            freq[card]++;
        }

        sort(hand.begin(), hand.end());

        int groupCount = 0;
        for(int i = 0; i < hand.size(); ++i){
            if(!freq[hand[i]]) continue;
            int obj = hand[i] + groupSize;
            for(int j = hand[i]; j < obj; ++j){
                if(!freq[j]) return false;
                freq[j]--;
            }
            groupCount++;
            if(groupCount == total) return true;
        }

        return false;
    }
};
