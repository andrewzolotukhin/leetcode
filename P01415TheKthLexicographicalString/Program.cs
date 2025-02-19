
var sol = new Solution();

Console.WriteLine(sol.GetHappyString(1, 3) == "c");
Console.WriteLine(sol.GetHappyString(1, 4) == "");
Console.WriteLine(sol.GetHappyString(3, 9) == "cab");

public class Solution
{
  private static bool Construct(Span<char> result, int index, ref int iteration, int targetIteration)
  {
    if (index > result.Length)
    {
      return false;
    }

    char[] letters = { 'a', 'b', 'c' };
    Dictionary<char, int> letterIndex = new() { { 'a', 0 }, { 'b', 1 }, { 'c', 2 } };

    for (int i = 0; i < letters.Length; i++)
    {
      if (index > 0 && letters[i] == result[index - 1])
      {
        continue;
      }

      result[index] = letters[i];

      if (index == result.Length - 1)
      {
        iteration++;
        if (iteration == targetIteration)
        {
          return true;
        }
        if (iteration > targetIteration)
        {
          return false;
        }
      }
      else
      {
        if (Construct(result, index + 1, ref iteration, targetIteration))
        {
          return true;
        }
      }
    }

    return false;
  }

  public string GetHappyString(int n, int k)
  {
    Span<char> result = stackalloc char[n];
    int iteration = 0;

    if (Construct(result, 0, ref iteration, k))
    {
      return new string(result);
    }

    return string.Empty;
  }
}
