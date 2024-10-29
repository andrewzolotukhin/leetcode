using P00008StringToInteger;


Console.WriteLine(P00008_StringToInteger.MyAtoi("1")); // 1
Console.WriteLine(P00008_StringToInteger.MyAtoi("-1")); // -1
Console.WriteLine(P00008_StringToInteger.MyAtoi("12345")); // 12345
Console.WriteLine(P00008_StringToInteger.MyAtoi("-10000")); // -10000
Console.WriteLine(P00008_StringToInteger.MyAtoi("-+10000")); // 0
Console.WriteLine(P00008_StringToInteger.MyAtoi("-100k00")); // -100
Console.WriteLine(P00008_StringToInteger.MyAtoi("+100k00")); // 100
Console.WriteLine(P00008_StringToInteger.MyAtoi("   +100k00")); // 100
Console.WriteLine(P00008_StringToInteger.MyAtoi($"{int.MaxValue}")); // -2147483647
Console.WriteLine(P00008_StringToInteger.MyAtoi($"{int.MinValue}")); // -2147483648
Console.WriteLine(P00008_StringToInteger.MyAtoi("-2147483648")); // -2147483648
Console.WriteLine(P00008_StringToInteger.MyAtoi("-2147483649")); // -2147483648
Console.WriteLine(P00008_StringToInteger.MyAtoi("2147483647")); // 2147483647
Console.WriteLine(P00008_StringToInteger.MyAtoi("2147483648")); // 2147483647
Console.WriteLine(P00008_StringToInteger.MyAtoi("02147483647")); // 2147483647
Console.WriteLine(P00008_StringToInteger.MyAtoi("02147483648")); // 2147483647
Console.WriteLine(P00008_StringToInteger.MyAtoi("021474836471")); // 2147483647
Console.WriteLine(P00008_StringToInteger.MyAtoi("021474836481")); // 2147483647
Console.WriteLine(P00008_StringToInteger.MyAtoi("-02147483648")); // -2147483648
Console.WriteLine(P00008_StringToInteger.MyAtoi("-02147483649")); // -2147483648
Console.WriteLine(P00008_StringToInteger.MyAtoi("-021474836471")); // -2147483648
Console.WriteLine(P00008_StringToInteger.MyAtoi("-021474836491")); // -2147483648
Console.WriteLine(P00008_StringToInteger.MyAtoi("2147483646")); // 2147483646
Console.WriteLine(P00008_StringToInteger.MyAtoi("1234567890123456789012345678901234567890"));