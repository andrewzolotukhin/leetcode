using System;

namespace P00009PalindromeNumber;

public class P00009_PalindromeNumber
{
	public static bool IsPalindrome(int x)
	{
		if (x < 0) return false;
		if (x == 0) return true;
		var s = x.ToString();

		for (var i = 0; i < s.Length / 2; i++)
		{
			if (s[i] != s[s.Length - i - 1]) return false;
		}

		return true;
	}
}
