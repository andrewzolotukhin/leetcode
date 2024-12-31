public class Solution {
    public string RemoveDigit(string number, char digit) {
        List<(string s, int pos)> candidates = new();
        int maxLen = 0;
        for(int i = 0; i < number.Length; i++) {
            if(number[i] == digit) {
                var candidate = (number.Substring(0, i) + ((i + 1 >= number.Length) ? "" : number.Substring(i + 1)),i);
                if(candidate.Item1.Length > maxLen) {
                    maxLen = candidate.Item1.Length;
                    candidates.Clear();
                }
                candidates.Add(candidate);
            }
        }

        candidates.Sort((a, b) => a.s.Length == b.s.Length ? -a.s.CompareTo(b.s) : b.s.Length - a.s.Length);

        return candidates[0].s;
    }
}
