class MinStack {
public:
    vector<int> min_stck;
    vector<int> stck;
    MinStack() {
    }
    
    void push(int value) {
        stck.push_back(value);
        if(min_stck.empty())
            min_stck.push_back(value);
        else
            min_stck.push_back(min(value,min_stck.back()));
    }
    
    void pop() {
        if(stck.empty())
            return;
        stck.pop_back();
        min_stck.pop_back();
    }
    
    int top() {
        return stck.back(); 
    }
    
    int getMin() {
        return min_stck.back();

    }
};