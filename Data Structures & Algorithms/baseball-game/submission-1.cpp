class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> records;
        int res = 0;
        for(const string& op : operations){
            if(op == "+"){
                int tmp = records.top();
                records.pop();
                int newRecord = tmp + records.top();
                records.push(tmp);
                records.push(newRecord);
                res += newRecord;
            }else if(op == "D"){
                int newTop = 2 * records.top();
                records.push(newTop);
                res += newTop;
            }else if(op == "C"){
                res -= records.top();
                records.pop();
            }else{
                int newTop = stoi(op);
                records.push(newTop);
                res += newTop;
            }
        }

        return res;
    }
};