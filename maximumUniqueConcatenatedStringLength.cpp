class Solution {
public:

    int Func(vector<string> &v,int i,string s) {
        if(i == v.size()) {
            int freq[26] = {0};
            for(int k = 0 ; k < s.length() ; k++) {
                if(freq[s[k] - 'a'] == 1) return 0;
                freq[s[k]-'a']++;
            }
            return s.length();
        }

        int op1,op2;
        op1= op2 = INT_MIN;

         if(s.length() + v[i].length() <= 26) {
             op1  = Func(v,i+1,s+v[i]);
         }

         op2 = Func(v,i+1,s);
        return max(op1,op2);
    }
    int maxLength(vector<string>& arr) {
        return Func(arr,0,"");
    }
};