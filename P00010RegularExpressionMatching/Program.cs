using P00010RegularExpressionMatching;

Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaa", "aaa")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaa", "a*")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaabb", "aaab*")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaabb", "a*b*")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaabb", ".*")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaabb", "a*.*")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aa", "a*")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("a", ".")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aasdjkfnsakjdfnks", ".*")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("mississippi", "mis*is*ip*.")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aab", "c*a*b")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaa", "ab*ac*a")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaa", "ab*a*c*a")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("a", "ab*")); // True
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("mississippi", "mis*is*p*.")); // False
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaa", "aab")); // False
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaa", "b")); // False
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaabb", "a*k*")); // False
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaa", "b*")); // False
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaa", "ab*a")); // False
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("ab", ".*c")); // False
Console.WriteLine(P00010_RegularExpressionMatching.IsMatch("aaaaaaaaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*")); // False
