
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
test(0, 0);

public class Solution
{
	public static int Divide(int dividend, int divisor)
	{
		if (dividend == 0) return 0;
		if (dividend == divisor) return 1;
		if (divisor == 1) return dividend;
		if (divisor == -1) return dividend switch { int.MaxValue => -int.MaxValue, int.MinValue => int.MaxValue, _ => -dividend };

		var isDividentNegative = dividend < 0;
		var isDivisorNegative = divisor < 0;
		var isResultNegative = isDividentNegative ^ isDivisorNegative;
		if (divisor == 0) return isResultNegative ? int.MinValue : int.MaxValue;

		var result = 0;

		if ((dividend, divisor) is ( < 0, < 0))
		{
			while (dividend <= divisor)
			{
				result++;
				dividend -= divisor;
			}
		}
		else if ((dividend, divisor) is ( < 0, > 0))
		{
			while (dividend <= 0)
			{
				result--;
				dividend += divisor;
			}
			result++;
		}
		else if ((dividend, divisor) is ( > 0, < 0))
		{
			while (dividend >= 0)
			{
				result--;
				dividend += divisor;
			}
			result++;
		}
		else if ((dividend, divisor) is ( > 0, > 0))
		{
			while (dividend >= divisor)
			{
				result++;
				dividend -= divisor;
			}
		}


		return result;
	}
}