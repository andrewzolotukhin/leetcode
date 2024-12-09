// Console.WriteLine(Solution.IsMatch("aa", "*")); // True
// Console.WriteLine(
//   Solution.IsMatch(
//     "babbbbaabababaabbababaababaabbaabababbaaababbababaaaaaabbabaaaabababbabbababbbaaaababbbabbbbbbbbbbaabbb",
//     "b**bb**a**bba*b**a*bbb**aba***babbb*aa****aabb*bbb***a"
//  )
// );
// Console.WriteLine(
//   Solution.IsMatch(
//     "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb",
//     "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb"
//  )
// );

Console.WriteLine(Solution.IsMatch("", "******")); // True
Console.WriteLine(Solution.IsMatch("babaabbbbbaaaaabbaababbaaaaaaabbaabaabbbabbaabbbbb", "*ba**bbbb")); // True
Console.WriteLine(Solution.IsMatch("abczzzde", "*abc???de*")); // True
Console.WriteLine(Solution.IsMatch("abczzzdeabcde", "*abc???de*")); // True
Console.WriteLine(Solution.IsMatch("abbaaabbbbaababbabbaabaabbbaabaaaaaaaaabbaaaabababbba", "****a")); // True
Console.WriteLine(Solution.IsMatch("abefcdgiescdfimde", "ab*cd?i*de")); // True
Console.WriteLine(Solution.IsMatch("abcabczzzde", "*abc???de*")); // True
Console.WriteLine(Solution.IsMatch("aaa", "aa?")); // True
Console.WriteLine(Solution.IsMatch("aaasdfsd", "aa*")); // True
Console.WriteLine(Solution.IsMatch("aaasdfsdbbaacc", "aa*bb??cc")); // True
Console.WriteLine(Solution.IsMatch("aaa", "aa")); // False
Console.WriteLine(Solution.IsMatch("aba", "*aa")); // False
Console.WriteLine(Solution.IsMatch("acdcb", "a*c?b")); // False
Console.WriteLine(Solution.IsMatch("bbb", "?b")); // False

public class Solution
{
	public static bool IsMatch(string s, string p)
	{
		while (p.IndexOf("**") != -1)
		{
			p = p.Replace("**", "*");
		}
		var dp = new bool[p.Length + 1, s.Length + 1];

		dp[0, 0] = true;
		if (p.Length > 0 && p[0] == '*')
		{
			dp[1, 0] = true;
		}

		for (var i = 1; i <= p.Length; i++)
			for (var j = 1; j <= s.Length; j++)
			{
				if (p[i - 1] == s[j - 1] || p[i - 1] == '?')
				{
					dp[i, j] = dp[i - 1, j - 1];
				}
				if (p[i - 1] == '*')
				{
					dp[i, j] = dp[i - 1, j] || dp[i, j - 1];
				}
			}

		return dp[p.Length, s.Length];
	}
}