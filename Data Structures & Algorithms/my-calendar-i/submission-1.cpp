class MyCalendar {
private:
    set<pair<int,int>> calendar;
public:
    MyCalendar() {}
    
    bool book(int startTime, int endTime) {
        pair<int,int> event(startTime, endTime);

        if(calendar.empty()){
            calendar.insert(event);
            return true;
        }

        auto it = lower_bound(calendar.begin(), calendar.end(), event);

        if(it != calendar.end() && it->first < endTime) return false;
        if(it != calendar.begin() && prev(it)->second > startTime) return false;

        calendar.insert(event);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */