// See https://aka.ms/new-console-template for more information

using System.Diagnostics;

List<(string s1, string s2, bool result)> tests = [
  ("great", "rgeat", true),
  ("abcde", "caebd", false),
  ("abcdefghijklmnopq", "efghijklmnopqcadb", false),
  ("a", "a", true)
];

foreach (var (s1, s2, expected) in tests)
{
  // measure time
  var sw = new Stopwatch();
  sw.Start();
  var actual = new Solution().IsScramble(s1, s2);
  sw.Stop();
  if (actual != expected)
  {
    Console.BackgroundColor = ConsoleColor.Red;
  }
  Console.WriteLine($"{s1}, {s2} => {actual} (expected: {expected}): {sw.ElapsedMilliseconds}ms");
  Console.ResetColor();
}

public class Solution
{
  private Dictionary<(string s1, string s2), bool> memo = new();
  private bool CanScramble(string s1, string s2)
  {
    var key = (s1, s2);
    if (memo.ContainsKey(key))
    {
      return memo[key];
    }

    if (s1 == s2)
    {
      memo[key] = true;
      return true;
    }

    if (s1.Length != s2.Length)
    {
      memo[key] = false;
      return false;
    }

    if (s1.Length == 1)
    {
      memo[key] = s1 == s2;
      return s1 == s2;
    }

    for (int i = 1; i < s1.Length; i++)
    {
      if (CanScramble(s1.Substring(0, i), s2.Substring(0, i)) && CanScramble(s1.Substring(i), s2.Substring(i)))
      {
        memo[key] = true;
        return true;
      }

      if (CanScramble(s1.Substring(0, i), s2.Substring(s2.Length - i)) && CanScramble(s1.Substring(i), s2.Substring(0, s2.Length - i)))
      {
        memo[key] = true;
        return true;
      }
    }

    memo[key] = false;

    return false;
  }
  public bool IsScramble(string s1, string s2)
  {
    Dictionary<char, int> s1Count = new();
    Dictionary<char, int> s2Count = new();
    foreach (var c in s1)
    {
      if (!s1Count.ContainsKey(c))
      {
        s1Count[c] = 0;
      }
      s1Count[c]++;
    }
    foreach (var c in s2)
    {
      if (!s2Count.ContainsKey(c))
      {
        s2Count[c] = 0;
      }
      s2Count[c]++;
    }
    if (s1Count.Count != s2Count.Count)
    {
      return false;
    }
    foreach (var (k, v) in s1Count)
    {
      if (!s2Count.ContainsKey(k) || s2Count[k] != v)
      {
        return false;
      }
    }
    return CanScramble(s1, s2);
  }
}
