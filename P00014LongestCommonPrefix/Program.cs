
Console.WriteLine(Solution.LongestCommonPrefix(["flower", "flow", "flight"]));
Console.WriteLine(Solution.LongestCommonPrefix(["dog", "racecar", "car"]));
Console.WriteLine(Solution.LongestCommonPrefix(["doge", "doge", "dogeman", "dogeinvalid"]));
Console.WriteLine(Solution.LongestCommonPrefix(["a", "ab"]));
Console.WriteLine(Solution.LongestCommonPrefix(["ab", "ab", "abc"]));


public class Solution
{
	public class Node
	{
		public int Prefix { get; init; } = 0;

		public Dictionary<char, Node> Children { get; private set; } = [];

		public int Occurences { get; set; } = 0;

		public Node AddChild(char c, int prefix)
		{
			var node = new Node { Prefix = prefix };
			Children.Add(c, node);
			return node;
		}

		private Node? FindChild(char c)
		{
			Children.TryGetValue(c, out Node? val);
			return val;
		}

		public bool Insert(string v)
		{
			var result = false;
			if (string.IsNullOrEmpty(v)) return result;
			var childNode = FindChild(v[0]);
			if (childNode is null)
			{
				if (Children.Count == 0) result = true;
				childNode = AddChild(v[0], Prefix + 1);
				childNode.Occurences = Occurences;
			}
			else
			{
				result = true;
			}
			Occurences++;
			childNode.Insert(v[1..]);
			return result;
		}
	};

	public static string LongestCommonPrefix(string[] strs)
	{
		if (strs.Length == 0) return string.Empty;
		var tree = new Node();

		for (var i = 0; i < strs.Length; i++)
		{
			if (!tree.Insert(strs[i])) return string.Empty;
		}

		var resultNode = tree;

		while (resultNode.Children.Count == 1 && resultNode.Occurences == strs.Length)
		{
			resultNode = resultNode.Children.First().Value;
		}

		return resultNode.Prefix == 0 ? string.Empty : strs[0][..resultNode.Prefix];
	}
}


