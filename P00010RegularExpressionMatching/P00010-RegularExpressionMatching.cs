using System.Security.Cryptography.X509Certificates;

namespace P00010RegularExpressionMatching;

public class P00010_RegularExpressionMatching
{

	internal class Operation
	{
		public bool IsRepeat { get; init; }
		public char? Char { get; init; }
	}

	internal class MatchResult
	{
		public string? RemainingString { get; init; }
		public bool IsMatch { get; init; }
	}

	private static List<Operation> Parse(string pattern)
	{
		var result = new List<Operation>();
		if (pattern.Length == 0) return result;
		var index = 0;

		while (index < pattern.Length)
		{
			if (index + 1 < pattern.Length && pattern[index + 1] == '*')
			{
				result.Add(new Operation { IsRepeat = true, Char = pattern[index] == '.' ? null : pattern[index] });
				index += 2;
				continue;
			}

			result.Add(new Operation { IsRepeat = false, Char = pattern[index] == '.' ? null : pattern[index] });
			index++;
		}

		return result;
	}

	private static IEnumerable<Operation> Optimize(IEnumerable<Operation> ops)
	{
		Operation? previous = null;

		foreach (var op in ops)
		{
			if (previous is not null)
			{
				if (previous.IsRepeat && op.IsRepeat && previous.Char == op.Char) continue;
				yield return previous;
			}

			previous = op;
		}

		if (previous is not null) yield return previous;
	}

	static IEnumerable<MatchResult> GetMatches(string s, Operation operation)
	{
		if (operation.IsRepeat)
		{

			if (s == string.Empty)
			{
				yield return new MatchResult
				{
					IsMatch = true,
					RemainingString = ""
				};
			}
			if (operation.Char is null)
			{
				for (var i = 0; i <= s.Length; i++)
				{
					yield return new MatchResult
					{
						IsMatch = true,
						RemainingString = s[i..]
					};
				}
			}
			else
			{
				yield return new MatchResult
				{
					IsMatch = true,
					RemainingString = s
				};
				var i = 0;
				while (i < s.Length && s[i] == operation.Char)
				{
					yield return new MatchResult
					{
						IsMatch = true,
						RemainingString = s[++i..]
					};
				}
			}
		}
		else
		{
			yield return new MatchResult
			{
				IsMatch = (s.Length > 0) && (operation.Char == null || operation.Char == s[0]),
				RemainingString = s.Length > 0 ? s[1..] : ""
			};
		}
	}

	static bool Walk(string s, List<Operation> operations, int operationIndex = 0)
	{
		var matches = GetMatches(s, operations[operationIndex]).Where(t => t.IsMatch).Select(t => t.RemainingString).ToList();

		// Console.WriteLine($"{operationIndex} {s}");

		if (operationIndex + 1 < operations.Count)
		{
			foreach (var match in matches)
			{
				if (Walk(match!, operations, operationIndex + 1))
				{
					// Console.WriteLine($"{operationIndex} {match} matches!");
					return true;
				}
			}
			return false;
		}

		return matches.Any(string.IsNullOrEmpty);
	}

	public static bool IsMatch(string s, string p)
	{
		var operations = Optimize(Parse(p)).ToList();
		var result = Walk(s, operations);

		return result;
	}
}
