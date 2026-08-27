class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> records;
        for(const string& op : operations){
            if(op == "+"){
                int tmp = records.top();
                records.pop();
                int newRecord = tmp + records.top();
                records.push(tmp);
                records.push(newRecord);
            }else if(op == "D"){
                records.push(2 * records.top());
            }else if(op == "C"){
                records.pop();
            }else{
                records.push(stoi(op));
            }
        }

        int res = 0;
        while(!records.empty()){
            res += records.top();
            records.pop();
        }

        return res;
    }
};