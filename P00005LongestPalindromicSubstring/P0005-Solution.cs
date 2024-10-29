using System.Data;

namespace P00005LongestPalindromicSubstring;

public static class P0005_Solution
{
	public static string LongestPalindrome(string s)
	{
		if (s.Length <= 1) return s;

		if (s.Length == 2)
		{
			return s[0] == s[1] ? s : s[0].ToString();
		}

		var getLongestPalindromeBounds = (int start, int end) =>
		{
			if (s[start] != s[end])
			{
				return new { start, end = start };
			}

			var size = 0;
			while (start - size >= 0 && end + size <= s.Length - 1 && s[start - size] == s[end + size])
			{
				size++;
			}

			return new { start = start - size + 1, end = end + size - 1 };
		};

		var maxSizeStart = 0;
		var maxSizeEnd = 0;

		for (var i = 0; i < s.Length - 1; i++)
		{
			var res1 = getLongestPalindromeBounds(i, i);
			// Console.WriteLine($"{s} {i} {i} {res1.start} {res1.end}");
			var res2 = getLongestPalindromeBounds(i, i + 1);
			// Console.WriteLine($"{s} {i} {i + 1} {res2.start} {res2.end}");

			var res = (res1.end - res1.start > res2.end - res2.start) ? res1 : res2;

			if (res.end - res.start > maxSizeEnd - maxSizeStart)
			{
				maxSizeStart = res.start;
				maxSizeEnd = res.end;
			}
		}

		return s.Substring(maxSizeStart, maxSizeEnd - maxSizeStart + 1);
	}
}
