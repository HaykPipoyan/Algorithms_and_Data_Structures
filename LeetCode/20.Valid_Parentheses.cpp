class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ')' && s[i] != '}' && s[i] != ']'){
                st.push(s[i]);
                continue;
            }
            if(!st.empty()){
                if((s[i] == ')' && st.top() == '(' )|| (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[')){
                    st.pop();
                    continue;
                }
            }
            return false;               
        }
        
        return st.empty();
    }
};
