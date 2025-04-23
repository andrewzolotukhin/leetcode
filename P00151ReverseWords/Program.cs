public class Solution {
    public string ReverseWords(string s) {
        var splitted = s.Split(' ', StringSplitOptions.RemoveEmptyEntries).ToList();
        splitted.Reverse();
        return string.Join(' ', splitted);
    }
}
