
namespace P00007ReverseInteger;

public class P00007_ReverseInteger
{
	public static int Reverse(int x)
	{
		var isNegative = x < 0;
		// Console.WriteLine(x);
		var reversed = string.Join("", x.ToString().Reverse()).ToString().Replace("-", "");
		// Console.WriteLine(reversed);
		char[] maxInt = (isNegative ? int.MaxValue : int.MinValue).ToString().Replace("-", "").ToCharArray();
		// Console.WriteLine(string.Join("", maxInt));
		if (reversed.Length > 10) return 0;
		if (reversed.Length == 10)
		{
			for (var i = 0; i < reversed.Length; i++)
			{
				// Console.WriteLine($"{reversed[i]} {maxInt[i]}");
				if (reversed[i] > maxInt[i]) return 0;
				if (reversed[i] < maxInt[i]) break;
			}
		}

		return (isNegative ? -1 : 1) * Convert.ToInt32(reversed);
	}
}
