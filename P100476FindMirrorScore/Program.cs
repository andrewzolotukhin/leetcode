public class Solution {
    public long CalculateScore(string s) {
        long result = 0;
        var freq = new Dictionary<char, List<int>>();

        for (int i = 0; i < s.Length; i++) {
            char inversed = (char)('z' - s[i] + 'a');
            if (freq.ContainsKey(inversed)) {
                freq[inversed].Add(i);
            } else {
                freq[inversed] = new List<int> { i };
            }
        }

        var marked = new bool[s.Length];

        for (int i = 0; i < s.Length; i++) {
            if (marked[i] || !freq.ContainsKey(s[i]))
                continue;

            var positions = freq[s[i]];
            if (positions.Count == 0)
                continue;

            int currentEnd = positions.Count - 1;
            while (currentEnd >= 0 && (positions[currentEnd] >= i || marked[positions[currentEnd]])) {
                currentEnd--;
            }

            if (currentEnd < 0)
                continue;

            marked[i] = true;
            marked[positions[currentEnd]] = true;
            result += (i - positions[currentEnd]);
            positions.RemoveAt(currentEnd);
        }

        return result;
    }
}