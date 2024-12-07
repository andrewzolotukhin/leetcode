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
Console.WriteLine(Solution.Multiply("10", "100").ToString());
// Console.WriteLine(Solution.Subtract("0", "0").ToString());

// for (var i = 0; i < 1000; i++)
// 	for (var j = 0; j < 1000; j++)
// 	{
// 		var a = i.ToString();
// 		var b = j.ToString();
// 		Console.WriteLine($"{a} * {b}");
// 		var r1 = Solution.Multiply(a, b);
// 		var r2 = (BigInteger.Parse(a) * BigInteger.Parse(b)).ToString();
// 		Console.WriteLine($"{((r1 == r2) ? "OK" : "FAIL")} {a} * {b} = {r1} == {r2}");
// 	}

// now let's test Multiply method against the built-in multiplication
// of the big arithmetic library. We will use the BigInteger class
// from System.Numerics namespace. Pickup a 100 random pairs of numbers
// of random length between 1 and 1000 and multiply them using both
// methods. If the results are the same, we will print "OK" otherwise
// we will print "FAIL". Let's see the code:
//

// var random = new Random();
// for (var i = 0; i < 100; i++)
// {
// 	var a = new string(Enumerable.Range(0, random.Next(1, 1000)).Select(_ => (char)('0' + random.Next(0, 10))).ToArray());
// 	var b = new string(Enumerable.Range(0, random.Next(1, 1000)).Select(_ => (char)('0' + random.Next(0, 10))).ToArray());
// 	// let's make sure that the numbers are not starting with 0
// 	while (a[0] == '0') a = a[1..];
// 	while (b[0] == '0') b = b[1..];
// 	if (a.Length == 0) a = "0";
// 	if (b.Length == 0) b = "0";

// 	Console.WriteLine($"{a} * {b}");
// 	var r1 = Solution.Multiply(a, b);
// 	var r2 = (BigInteger.Parse(a) * BigInteger.Parse(b)).ToString();
// 	Console.WriteLine($"{((r1 == r2) ? "OK" : "FAIL")} {a} * {b} = {r1} == {r2}");
// }


// do the same for Sum
// for (var i = 0; i < 1_000_000; i++)
// {
// 	var a = new string(Enumerable.Range(0, random.Next(1, 1000)).Select(_ => (char)('0' + random.Next(0, 10))).SkipWhile(t => t == '0').ToArray());
// 	var b = new string(Enumerable.Range(0, random.Next(1, 1000)).Select(_ => (char)('0' + random.Next(0, 10))).SkipWhile(t => t == '0').ToArray());
// 	// let's make sure that the numbers are not starting with 0
// 	if (a.Length == 0) a = "0";
// 	if (b.Length == 0) b = "0";

// 	Console.WriteLine($"{a} + {b}");
// 	var r1 = Solution.Sum(a, b).ToString();
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
	public static ReadOnlySpan<char> Subtract(ReadOnlySpan<char> a, ReadOnlySpan<char> b, bool keepLeadingZeros = false)
	{
		if (a.Length < b.Length)
		{
			throw new InvalidOperationException("a must be bigger or equal to b");
		}

		char o = (char)0;

		char[] result = new char[a.Length];
		var firstNonZeroResultIndex = 0;

		int i;
		for (i = 0; i < a.Length; i++)
		{
			if (i < b.Length)
			{
				if (a[^(i + 1)] < b[^(i + 1)] + o)
				{
					result[^(i + 1)] = (char)((10 + a[^(i + 1)]) - b[^(i + 1)] - o);
					o = (char)1;
				}
				else
				{
					result[^(i + 1)] = (char)(a[^(i + 1)] - b[^(i + 1)] - o);
					o = (char)0;
				}
			}
			else
			{
				if (a[^(i + 1)] - '0' >= o)
				{
					result[^(i + 1)] = (char)(a[^(i + 1)] - '0' - o);
					o = (char)0;
				}
				else
				{
					result[^(i + 1)] = (char)(10 - a[^(i + 1)] + '0' - o);
				}

				if (result[^(i + 1)] < 0 || result[^(i + 1)] > 9)
				{
					throw new InvalidOperationException("wrong subtraction");
				}
			}
			result[^(i + 1)] += '0';
			if (result[^(i + 1)] != '0') firstNonZeroResultIndex = result.Length - i;
		}
		if (o > 0)
		{
			throw new InvalidOperationException("a must be bigger or equal to b");
		}
		return keepLeadingZeros ? result.AsSpan() : result.AsSpan(Math.Max(firstNonZeroResultIndex - 1, 0));
	}

	public static ReadOnlySpan<char> Sum(ReadOnlySpan<char> a, ReadOnlySpan<char> b, bool keepLeadingZeros = false)
	{
		// if it's small numbers just sum them up
		// don't sure if it's going to be quicker
		// need to test
		if (a.Length <= 16 && b.Length <= 16)
		{
			return (long.Parse(a) + long.Parse(b)).ToString().AsSpan();
		}

		var l = Math.Min(a.Length, b.Length);
		var m = Math.Max(a.Length, b.Length);

		char[] result = new char[m + 1];


		var ci = result.Length - 1;
		var longest = a.Length >= b.Length ? a : b;

		var o = (char)0;

		while (ci > 0)
		{
			if (result.Length - 1 - ci < l)
			{
				result[ci] = (char)(a[a.Length - (result.Length - ci)] - '0' + b[b.Length - (result.Length - ci)] - '0' + o);
				if (result[ci] >= 10)
				{
					o = (char)1;
					result[ci] -= (char)10;
				}
				else
				{
					o = (char)0;
				}
			}
			else
			{
				result[ci] = (char)(result[ci] + o + longest[ci - 1] - '0');
				if (result[ci] >= 10)
				{
					o = (char)1;
					result[ci] -= (char)10;
				}
				else
				{
					o = (char)0;
				}
			}
			result[ci] += '0';
			ci--;
		}
		if (o > 0)
		{
			result[0] = '1';
			return result;
		}

		if (result[0] == 0 && !keepLeadingZeros)
		{
			return result.AsSpan(1);
		}

		return result;

	}

	private static ReadOnlySpan<char> PadLeft(ReadOnlySpan<char> input, int length, char c)
	{
		// if input is smaller than length, pad it with c to have
		// the length of <param name="length"></param>
		if (input.Length >= length) return input;
		var result = new string(c, length - input.Length) + input.ToString();
		return result.AsSpan();
	}
	private static string ShiftLeft(ReadOnlySpan<char> num, int shifts)
	{
		if (num == "0") return "0";
		return num.ToString() + new string('0', shifts);
	}

	public static ReadOnlySpan<char> Mul(ReadOnlySpan<char> sa, ReadOnlySpan<char> sb)
	{
		var a = sa.Length >= sb.Length ? sa : sb;
		var b = sa.Length >= sb.Length ? sb : sa;

		// if (a.Length <= 9 && b.Length <= 9)
		// {
		// 	return (ulong.Parse(a.ToString()) * ulong.Parse(b.ToString())).ToString().AsSpan();
		// }
		if (a.Length <= 1 && b.Length <= 1)
		{
			return (ulong.Parse(a.ToString()) * ulong.Parse(b.ToString())).ToString().AsSpan();
		}

		if (b.Length == 1)
		{
			if (b[0] == '0') return "0".AsSpan();
			if (b[0] == '1') return a;
			ReadOnlySpan<char> res = Sum(a, a);
			for (var i = 1; i < b[0] - '0' - 1; i++)
			{
				res = Sum(res, a);
			}
			return res;
		}

		var maxLen = a.Length;
		if (maxLen % 2 == 1) maxLen++;

		if (b.Length != maxLen)
		{
			b = PadLeft(b, maxLen, '0');
		}

		var halfSize = maxLen / 2;

		var lowA = a[..halfSize];
		var highA = a[halfSize..];

		var lowB = b[..halfSize];
		var highB = b[halfSize..];

		var z0 = Mul(lowA, lowB);
		var z1 = Mul(Sum(lowA, highA, true), Sum(lowB, highB, true));
		var z2 = Mul(highA, highB);

		var p0 = ShiftLeft(z2, 2 * halfSize);
		var s1 = Sum(z2, z0, true);
		var s2 = Subtract(z1, s1, true);
		var p1 = ShiftLeft(s2, halfSize);
		var p2 = Sum(p0, p1, true);

		var result = Sum(p2, z0);

		return result;
	}

	private static void Place(Span<char> result, ReadOnlySpan<char> value, int place)
	{
		if (place - value.Length < 0)
		{
			throw new InvalidOperationException("wrong index to place");
		}
		for (var i = value.Length - 1; i >= 0; i--)
		{
			result[place - i] = value[i - place];
		}
	}

	public static string Multiply(string num1, string num2)
	{
		return Mul(num1, num2).ToString();
	}
}