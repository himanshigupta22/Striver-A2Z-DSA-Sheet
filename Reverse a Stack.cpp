class Solution{
public:
    void Reverse(stack<int> &st){
        if(st.empty()){
            return;
        }
        int temp = st.top();
        st.pop();
        Reverse(st);
        insertAtBottom(st, temp);
    }
    void insertAtBottom(stack<int> &st, int temp){
        if(st.empty()){
            st.push(temp);
            return;
        }
        int top = st.top();
        st.pop();
        insertAtBottom(st, temp);
        st.push(top);
    }
};
