namespace P00008StringToInteger;

public class P00008_StringToInteger
{
	public static int MyAtoi(string s)
	{
		var trimmed = s.Trim();
		var result = 0;
		var isPositive = true;

		if (trimmed.Length == 0) return result;

		if (trimmed[0] == '-') isPositive = false;

		if (trimmed[0] == '-' || trimmed[0] == '+') trimmed = trimmed.Substring(1);

		if (trimmed.Length == 0) return result;

		trimmed = trimmed.TrimStart('0');

		if (trimmed.Length == 0) return result;

		var i = 0;
		char[] chars = new char[20];


		for (i = 0; i < trimmed.Length && i <= 11; i++)
		{
			if (!char.IsNumber(trimmed[i])) break;
			chars[i] = trimmed[i];
		}

		if (i - 1 > 9)
		{
			return isPositive ? int.MaxValue : int.MinValue;
		}

		for (int j = i - 1, m = 1; j >= 0; j--, m *= 10)
		{
			if (j == 9 && chars[0] > '2')
			{
				return isPositive ? int.MaxValue : int.MinValue;
			}

			if (int.MaxValue - result < m * (chars[j] - 0x30))
			{
				return isPositive ? int.MaxValue : int.MinValue;
			}


			result += m * (chars[j] - 0x30);
		}

		return (isPositive ? 1 : -1) * result;
	}
}
