class MyCalendar {
private:
    vector<pair<int,int>> calendar;
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        pair<int,int> event(startTime, endTime);

        if(calendar.empty()){
            calendar.push_back(event);
            return true;
        }

        auto it = lower_bound(calendar.begin(), calendar.end(), event, [](const pair<int,int>& a, const pair<int,int>& b){
            return a.first < b.first;
        }
        );

        if(it == calendar.end()){
            if(calendar.back().second > startTime){
                return false;
            }
            calendar.push_back(event);
            return true;
        }

        const pair<int,int>& superior = *it;
        if(superior.first < endTime) return false;
    
        if(it - 1 >= calendar.begin()){
            const pair<int,int>& inferior = *(it - 1);
            if(inferior.second > startTime) return false;
        }

        calendar.insert(it, event);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */