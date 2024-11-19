
using System.Reflection.Metadata.Ecma335;

var test = (int d, int i) =>
{
	var r = Solution.Divide(d, i);
	int t;
	try
	{
		t = i == 0 ? 0 : Math.DivRem(d, i).Quotient;
	}
	catch (OverflowException)
	{
		t = int.MaxValue;
	}
	Console.WriteLine($"{d} / {i} = {r} // {(r != t ? "!!!!!" : "")} {t}");
};

test(100, 100);
test(100, 10);
test(-100, 100);
test(-100, 10);
test(100, -100);
test(100, -10);
test(100, 1);
test(100, -1);
test(int.MaxValue, 0);
test(int.MinValue, 0);
test(int.MaxValue, 1);
test(int.MinValue, 1);
test(int.MaxValue, -1);
test(int.MinValue, -1);
test(int.MinValue, int.MaxValue);
test(int.MaxValue, int.MinValue);
test(234455344, 3433);
test(234455344, -3433);
test(-234455344, -3433);
test(-234455344, 3433);
test(0, 0);
test(-2147483648, 2);
test(-2147483648, 4);
test(-1658356636, -1639504005);

public class Solution
{
	public static int Divide(int dividend, int divisor)
	{
		if (dividend == 0) return 0;
		if (dividend == divisor) return 1;
		if (dividend == int.MinValue && divisor == -1) return int.MaxValue;
		if (divisor == 1) return dividend;
		if (divisor == -1) return -dividend;
		if (divisor == int.MinValue) return 0;

		var isDividentNegative = dividend < 0;
		var isDivisorNegative = divisor < 0;
		var isResultNegative = isDividentNegative ^ isDivisorNegative;
		if (divisor == 0) return isResultNegative ? int.MinValue : int.MaxValue;


		Func<int, uint> touint = (int input) => (uint)((input < 0 ? (~input) : input) & 0x7FFFFFFF) + (uint)((input < 0) ? 1 : 0);

		var d = touint(dividend);
		var r = touint(divisor);

		uint result = 0;
		uint m, k;
		int i = 0;

		while (d >= r)
		{
			m = r;
			k = 1;
			i = 0;
			while (m <= d && m <= 0x70000000)
			{
				m <<= 1;
				k <<= 1;
				i++;
			}

			if (k >> 1 > 0)
			{
				result += k >> 1;
				d -= m >> 1;
			}
			else
			{
				d -= r;
				result++;
			}

		}

		return (int)result * (isResultNegative ? -1 : 1);
	}
}