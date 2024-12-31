using System.Net;
using System.Numerics;
// Console.WriteLine(Solution.Subtract("1234", "456").ToString()); // 778
// Console.WriteLine(Solution.Subtract("11233", "4443").ToString()); // 6790
// Console.WriteLine(Solution.Subtract("11233984234253425234523452353242342342342323", "444353453453453453423434534252345243").ToString()); // 11233983789899971781069998929807808089997080n
// Console.WriteLine(Solution.Subtract("0", "0").ToString());
// Console.WriteLine(Solution.Multiply("123", "456"));
// Console.WriteLine(Solution.Multiply("999", "99900"));
// Console.WriteLine(Solution.Sum("1999999999999999998".AsSpan(), "999999999999999999".AsSpan()).ToString());
// Console.WriteLine(Solution.Sum("99".AsSpan(), "1".AsSpan()).ToString());
// Console.WriteLine(Solution.Sum("98".AsSpan(), "1".AsSpan()).ToString());
// Console.WriteLine(Solution.Sum("100".AsSpan(), "101".AsSpan()).ToString());
// Console.WriteLine(Solution.Multiply("11111111111111111111111111111111", "33333333333333333333333333333333"));
// Console.WriteLine(Solution.Multiply("111", "333"));
// Console.WriteLine(Solution.Multiply("111123123123123", "2"));
// Console.WriteLine(Solution.Multiply("1112312312312", "2245"));
// Console.WriteLine(Solution.Sum("1111111111111111", "1111111111111111").ToString());
// Console.WriteLine(Solution.Multiply("10", "11").ToString());
// Console.WriteLine(Solution.Multiply("10", "10").ToString());
// Console.WriteLine(Solution.Multiply("10", "100").ToString());
// Console.WriteLine(Solution.Subtract("0", "0").ToString());
// Console.WriteLine(Solution.Sum("13063209214306350000000000000000", "282551189817126300000000").ToString());

for (var i = 0; i < 1000; i++)
	for (var j = 0; j < 1000; j++)
	{
		var a = i.ToString();
		var b = j.ToString();
		Console.WriteLine($"{a} * {b}");
		var r1 = Solution.Multiply(a, b);
		var r2 = (BigInteger.Parse(a) * BigInteger.Parse(b)).ToString();
		Console.WriteLine($"{((r1 == r2) ? "OK" : "FAIL")} {a} * {b} = {r1} == {r2}");
	}

// now let's test Multiply method against the built-in multiplication
// of the big arithmetic library. We will use the BigInteger class
// from System.Numerics namespace. Pickup a 100 random pairs of numbers
// of random length between 1 and 1000 and multiply them using both
// methods. If the results are the same, we will print "OK" otherwise
// we will print "FAIL". Let's see the code:
//

var random = new Random();

for (var i = 0; i < 1000; i++)
{
	var a = new string(Enumerable.Range(0, random.Next(1, 1000)).Select(_ => (char)('0' + random.Next(0, 10))).ToArray());
	var b = new string(Enumerable.Range(0, random.Next(1, 1000)).Select(_ => (char)('0' + random.Next(0, 10))).ToArray());

	Console.WriteLine($"{a} * {b}");
	var r1 = Solution.Multiply(a, b);
	var r2 = (BigInteger.Parse(a) * BigInteger.Parse(b)).ToString();
	Console.WriteLine($"{((r1 == r2) ? "OK" : "FAIL")} {a} * {b} = {r1} == {r2}");
}

// Console.WriteLine(Solution.Add("1", "99"));
// Console.WriteLine(Solution.Add("68", "77"));

// Console.WriteLine(Solution.Multiply("1", "99"));
// Console.WriteLine(Solution.Multiply("68", "77"));

// do the same for Sum
// for (var i = 0; i < 1_000_000; i++)
// {
// 	var a = new string(Enumerable.Range(0, random.Next(1, 1000)).Select(_ => (char)('0' + random.Next(0, 10))).ToArray());
// 	var b = new string(Enumerable.Range(0, random.Next(1, 1000)).Select(_ => (char)('0' + random.Next(0, 10))).ToArray());

// 	Console.WriteLine($"{a} + {b}");
// 	var r1 = Solution.Add(a, b).ToString();
// 	var r2 = (BigInteger.Parse(a) + BigInteger.Parse(b)).ToString();
// 	Console.WriteLine($"{((r1 == r2) ? "OK" : "FAIL")} {a} + {b} = {r1} == {r2}");
// 	if (i % 1000 == 0)
// 	{
// 		Console.Error.WriteLine(i);
// 	}
// }

// do the same for Subtract, but we need to make sure that a >= b, not only by length, but also by value
// for (var i = 0; i < 1_000_000; i++)
// {
// 	var a = new string(Enumerable.Range(0, random.Next(1, 1000)).Select(_ => (char)('0' + random.Next(0, 10))).SkipWhile(t => t == '0').ToArray());
// 	var b = new string(Enumerable.Range(0, random.Next(1, 1000)).Select(_ => (char)('0' + random.Next(0, 10))).SkipWhile(t => t == '0').ToArray());
// 	// let's make sure that the numbers are not starting with 0
// 	if (a.Length == 0) a = "0";
// 	if (b.Length == 0) b = "0";

// 	if (BigInteger.Parse(a) < BigInteger.Parse(b))
// 	{
// 		(b, a) = (a, b);
// 	}

// 	Console.WriteLine($"{a} - {b}");
// 	var r1 = Solution.Subtract(a, b).ToString();
// 	var r2 = (BigInteger.Parse(a) - BigInteger.Parse(b)).ToString();
// 	Console.WriteLine($"{((r1 == r2) ? "OK" : "FAIL")} {a} - {b} = {r1} == {r2}");
// 	if (i % 1000 == 0)
// 	{
// 		Console.Error.WriteLine(i);
// 	}
// }

public class Solution
{
	private const long BASE = 10;

	public static Span<long> Sum(ReadOnlySpan<long> a, ReadOnlySpan<long> b)
	{
		if (a.Length != b.Length || a.Length < 1)
		{
			throw new ArgumentOutOfRangeException("a and b must have the same positive size");
		}

		var result = new long[a.Length + 1];

		for (var i = 0; i < a.Length; i++)
		{
			result[i + 1] = a[i] + b[i];
		}

		return result.AsSpan();
	}

	private static long[] ReadNumFromStr(string s)
	{
		var result = new long[s.Length];
		for (var i = 0; i < s.Length; i++)
		{
			result[i] = s[i] - '0';
		}

		return result;
	}

	private static string FromBaseToDecimal(ReadOnlySpan<long> num)
	{
		var result = new char[num.Length];
		for (var i = 0; i < num.Length; i++)
		{
			result[i] = (char)(num[i] + '0');
		}

		return new string(result);
	}

	private static Span<long> Normalize(ReadOnlySpan<long> num)
	{
		var result = new long[num.Length];
		var lastSignificant = num.Length - 1;
		for (var i = num.Length - 1; i > 0; i--)
		{
			if (result[i] + num[i] >= BASE)
			{
				result[i - 1] += (result[i] + num[i]) / BASE;
				result[i] = (result[i] + num[i]) % BASE;
				lastSignificant = i - 1;
			}
			else
			{
				result[i] += num[i];
				if (result[i] > 0)
				{
					lastSignificant = i;
				}
			}
		}

		if (result[0] >= BASE)
		{
			throw new OverflowException("Number is excessively big");
		}

		return result.AsSpan(lastSignificant);
	}

	private static string PadZerosLeft(string s, int targetLength)
	{
		if (s.Length >= targetLength) return s;
		var n = targetLength - s.Length;
		return new string('0', n) + s;
	}

	public static string Add(string num1, string num2)
	{
		if (num1.Length < num2.Length) return Add(num2, num1);
		num2 = PadZerosLeft(num2, num1.Length);
		var n1 = ReadNumFromStr(num1).AsSpan();
		var n2 = ReadNumFromStr(num2).AsSpan();
		var res = Sum(n1, n2);
		var resNormalized = Normalize(res);

		var resStr = FromBaseToDecimal(resNormalized);

		return resStr;
	}

	public static Span<long> MultiplyTrivial(ReadOnlySpan<long> a, ReadOnlySpan<long> b)
	{
		if (a.Length != b.Length || a.Length < 1)
		{
			throw new ArgumentOutOfRangeException("a and b must have the same positive size");
		}
		var result = new long[2 * a.Length];

		for (var i = 0; i < a.Length; i++)
		{
			for (var j = 0; j < a.Length; j++)
			{
				result[i + j + 1] += a[i] * b[j];
			}
		}

		return result.AsSpan();
	}

	public static string Multiply(string num1, string num2)
	{
		if (num1.Length < num2.Length) return Multiply(num2, num1);
		num2 = PadZerosLeft(num2, num1.Length);
		var n1 = ReadNumFromStr(num1).AsSpan();
		var n2 = ReadNumFromStr(num2).AsSpan();
		var res = MultiplyTrivial(n1, n2);
		var resNormalized = Normalize(res);

		var resStr = FromBaseToDecimal(resNormalized);

		return resStr;
	}
}