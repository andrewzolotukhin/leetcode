Solution.LetterCombinations("23");
Console.WriteLine("==================");
Solution.LetterCombinations("");
Console.WriteLine("==================");
Solution.LetterCombinations("2");
Console.WriteLine("==================");
Solution.LetterCombinations("3");
Console.WriteLine("==================");
Solution.LetterCombinations("4");
Console.WriteLine("==================");
Solution.LetterCombinations("9");
Console.WriteLine("==================");
Solution.LetterCombinations("92");
Console.WriteLine("==================");
Solution.LetterCombinations("922");
Console.WriteLine("==================");
Solution.LetterCombinations("9999");

public class Solution
{
	public static IList<string> LetterCombinations(string digits)
	{
		if (string.IsNullOrWhiteSpace(digits)) return [];
		var map = new Dictionary<char, char[]> {
	    {'2', "abc".ToCharArray()},
	    {'3', "def".ToCharArray()},
	    {'4', "ghi".ToCharArray()},
	    {'5', "jkl".ToCharArray()},
	    {'6', "mno".ToCharArray()},
	    {'7', "pqrs".ToCharArray()},
	    {'8', "tuv".ToCharArray()},
	    {'9', "wxyz".ToCharArray()}
	};

		var result = new List<string>();
		char[] state = new char[digits.Length];

		for (var j = 0; j < state.Length; j++)
		{
			state[j] = map[digits[j]][0];
		}

		var i = 0;

		while (i < state.Length && state[state.Length - 1] <= map[digits[state.Length - 1]][map[digits[state.Length - 1]].Length - 1])
		{
			// Console.WriteLine(new string(state));
			result.Add(new string(state));
			var digit = digits[i];
			var ca = map[digit];
			var cmax = ca[ca.Length - 1];

			if (state[i] == cmax)
			{
				for (var j = i; j >= 0; j--)
				{
					state[j] = map[digits[j]][0];
				}
				if (i >= state.Length - 1)
				{
					break;
				}

				var k = i + 1;
				if (k > state.Length - 1)
				{
					break;
				}

				while (k < state.Length && state[k] == map[digits[k]][map[digits[k]].Length - 1])
				{
					state[k] = map[digits[k]][0];
					k++;
				}

				if (k >= state.Length)
				{
					break;
				}

				state[k]++;

				i = 0;
			}
			else
			{
				state[i]++;
			}
		}


		return result;
	}
}