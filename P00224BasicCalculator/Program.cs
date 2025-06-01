var s = new Solution();

var test = (string expression, int expected) =>
{
    var result = s.Calculate(expression);
    if (result != expected)
    {
        Console.WriteLine("Failed: " + expression + " Expected: " + expected + " Got: " + result);
    }
};

test("10+20*2", 50); // 50
test("10+20*2+3", 53); // 53
test("10+20/2+3", 23); // 23
test("(10+20)/2+3", 18); // 18

public class Solution
{
    public int Calculate(string s)
    {
        int len = s.Length, sign = 1, result = 0;
        Stack<int> stack = new();
        for (int i = 0; i < len; i++)
        {
            if (char.IsDigit(s[i]))
            {
                int sum = s[i] - '0';
                while (i + 1 < len && char.IsDigit(s[i + 1]))
                {
                    sum = sum * 10 + s[i + 1] - '0';
                    i++;
                }
                result += sum * sign;
            }
            else if (s[i] == '+')
                sign = 1;
            else if (s[i] == '-')
                sign = -1;
            else if (s[i] == '(')
            {
                stack.Push(result);
                stack.Push(sign);
                result = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                result = result * stack.Pop() + stack.Pop();
            }

        }
        return result;


    }
}

