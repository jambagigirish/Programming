class Solution {
public:
    int romanToInt(string s) {
        int res =0;
        unordered_map<char,int> mp = {{'I',1},{'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
        
        stack<char> st;
        
        int i=0;
        int len = s.length();
        
        while(i<len){
            if(st.empty()){
                st.push(s[i]);
            }
            else{
                if(mp[st.top()] >= mp[s[i]])
                {
                    while(st.size()>0 && mp[st.top()] <= mp[s[i]]){
                        res= res+ mp[st.top()];
                        st.pop();
                    }
                    st.push(s[i]);
                }
                else{
                    res = res + mp[s[i]] -mp[st.top()];
                    st.pop();
                }
            }
            i++;
        }
        
        while(st.size()>0){
            res = res + mp[st.top()];
            st.pop();  
        }
        
        return res;
    }
};