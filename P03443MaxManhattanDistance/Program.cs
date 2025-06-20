public class Solution {
    public int MaxDistance(string s, int k) {
        int cx = 0, cy = 0, cnt = 0;
        int ans = 0;
        Dictionary<char, int> freq = [];
        freq['N'] = 0; freq['S'] = 0; freq['E'] = 0; freq['W'] = 0;
        foreach(char c in s) {
            freq[c]++;
            if(c == 'N') cy--;
            if(c == 'S') cy++;
            if(c == 'W') cx--;
            if(c == 'E') cx++;
            int maxChange = Math.Min(cnt, k);

            cnt++;
            ans = Math.Max(ans, Math.Min(cnt, Math.Abs(cx) + Math.Abs(cy) + 2*maxChange));
        }

        return ans;
    }
}
