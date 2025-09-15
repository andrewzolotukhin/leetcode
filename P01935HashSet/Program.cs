public class Solution {
    public int CanBeTypedWords(string text, string brokenLetters) {
        bool[] a = new bool[26];
        foreach(var c in brokenLetters){
            a[c-'a']= true;
        }

        int ans = 0;
        foreach(var w in text.Split(' ')) {
            var isOk = true;
            foreach(var c in w){
                if(a[c-'a']){
                    isOk = false;
                    break;
                }
            }
            if(isOk) ans++;
        }

        return ans;
    }
}
