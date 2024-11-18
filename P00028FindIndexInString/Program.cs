Console.WriteLine(Solution.StrStr("sadbutsad", "sad")); // 0
Console.WriteLine(Solution.StrStr("asadbutsad", "sad")); // 1
Console.WriteLine(Solution.StrStr("asdfasdfasdkjn", "sad")); // -1
Console.WriteLine(Solution.StrStr("asada", "sada")); // -1

public class Solution
{
	public static int StrStr(string haystack, string needle)
	{
		if (haystack.Length < needle.Length) return -1;

		if (haystack.Length == needle.Length) return haystack == needle ? 0 : -1;

		var ch = haystack.ToCharArray();
		var cn = needle.ToCharArray();


		for (var i = 0; i <= ch.Length - needle.Length; i++)
		{
			var found = true;
			for (var j = i; j - i < needle.Length; j++)
			{
				if (ch[j] != cn[j - i])
				{
					found = false;
					break;
				}
			}
			if (found)
			{
				return i;
			}
		}

		return -1;
	}
}