public class Solution {
    public int LengthOfLastWord(string s) {
        var res = s.Split(' ', StringSplitOptions.RemoveEmptyEntries).ToList();
        if(res.Count == 0) return 0;
        return res[^1].Length;
    }
}
