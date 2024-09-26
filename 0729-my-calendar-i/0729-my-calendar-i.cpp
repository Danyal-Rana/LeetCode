class MyCalendar {
private:
    vector<pair<int, int>> st; // To store the intervals

    // Function to check if a new event can be inserted without overlap
    bool canInsert(int s, int e) {
        for (auto it : st) {
            int l = it.first; // Start of the existing interval
            int r = it.second; // End of the existing interval
            // Check if there's any overlap
            if (s < r && e > l) {
                return false; // There is an overlap
            }
        }
        return true; // No overlap
    }

public:
    // Constructor
    MyCalendar() { }

    // Function to book a new event
    bool book(int start, int end) {
        if (canInsert(start, end)) { // Check if we can insert the new interval
            st.push_back({start, end}); // Add the new interval
            return true; // Successful booking
        }
        return false; // Overlap detected, cannot book
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */