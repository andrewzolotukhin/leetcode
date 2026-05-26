class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> c1(26,0), c2(26,0);
        for (auto &ch: word){
            if(ch>='a' && ch<='z'){
                int i = ch - 'a';
                c1[i]++;
            } else {
                int i = ch - 'A';
                c2[i]++;
            }
        }
        int ans = 0;
        for (int i = 0; i<26;i++){
            if(c1[i]&&c2[i]){
                ans++;
            }
        }
        return ans;
    }
};