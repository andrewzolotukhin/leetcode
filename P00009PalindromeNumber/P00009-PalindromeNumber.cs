using System;

namespace P00009PalindromeNumber;

public class P00009_PalindromeNumber
{
	public static bool IsPalindrome(int x)
	{
		if (x < 0) return false;
		if (x == 0) return true;
		// version with conversion to string
		var s = x.ToString();

		for (var i = 0; i < s.Length / 2; i++)
		{
			if (s[i] != s[s.Length - i - 1]) return false;
		}

		return true;


		// version without converting to string

		// var digits = new byte[10];
		// int divider = 1000000000;
		// int k = x;
		// var i = 0;
		// while (divider > 0)
		// {
		// 	digits[i] = (byte)(k / divider);
		// 	if (digits[i] > 0)
		// 	{
		// 		k -= digits[i] * divider;
		// 	}
		// 	i++;
		// 	divider /= 10;
		// }

		// var nonZeroDigits = digits.SkipWhile(t => t == 0).ToArray();

		// if (nonZeroDigits.Length == 0) return true;

		// for (i = 0; i < nonZeroDigits.Length / 2; i++)
		// {
		// 	if (nonZeroDigits[i] != nonZeroDigits[nonZeroDigits.Length - i - 1]) return false;
		// }

		// return true;
	}
}
