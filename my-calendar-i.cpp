
// question link - https://leetcode.com/problems/my-calendar-i


class MyCalendar {
public:
    unordered_map<int, int> umap;
    bool flag = false;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {   
        flag = false;
        for (auto it: umap) {
            if(start > it.second){
                continue;
            } else {
                if (start < it.first) {
                    if(end <= it.first){
                        continue;
                    } else {
                        flag = true;
                    }
                } else {
                    flag = true;
                }
            }
        }    
        
        if (flag) return false;
        umap.insert({start, end-1});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */