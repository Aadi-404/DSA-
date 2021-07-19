class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.length();
        if(!n)return "";
        vector<int> count (26,0);
        for(int i=0;i<n;i++){
            count[s[i] -'a']++;
        }
        int max_count = 0;
        int max_char ;
        for(int i=0;i<26;i++){
            if(count[i]>max_count){
                max_count = count[i];
                max_char = 'a' + i;
                }
        }
        if(max_count > (n+1)/2){return "";}
        string ans (n,' ');
        int idx = 0;
        while(max_count){
            ans[idx] = max_char;
            idx +=2;
            max_count--;
        }
        count[max_char - 'a'] = 0;
        for(int i =0;i<26;i++){
            while(count[i]>0){
                if(idx>=n)idx = 1;
                ans[idx]= 'a' + i;
                idx +=2;
                count[i]--;
            }
        }
        return ans;
        
    }
};