class Solution {
public:
    
    void solve(string ip,string op,vector<string>& res){
        if(ip.length() == 0){
            res.push_back(op);
            return;
        }
        
        if(islower(ip[0])){
            string op1 = op+char(toupper(ip[0]));
            string op2 = op+ip[0];
            ip.erase(ip.begin());
            
            solve(ip, op1, res);
            solve(ip, op2, res);
        }
        else if(isupper(ip[0])){
            string op3 = op+char(tolower(ip[0]));
            string op4 = op+ip[0];
            ip.erase(ip.begin());
            
            solve(ip, op3, res);
            solve(ip, op4, res);
        }
        else{
            string op5 = op+char(ip[0]);
            ip.erase(ip.begin());
            solve(ip, op5, res);
        }
         
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        string op ="";
        solve(S,op,res);
        
        return res;
    }
};