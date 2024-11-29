#include <iostream>
#include <string>

class Solution
{
public:
	std::string countAndSay(int n)
	{
		std::string s = "1";
		if (n == 1)
			return s;
		n--;
		s = "11";
		while (--n)
		{
			std::string res = "";
			int i = 0;
			char c = '0';
			for (i = 0; i < s.size() - 1; i++)
			{
				c++;
				if (s[i] != s[i + 1])
				{
					res += c;
					res += s[i];
					c = '0';
				}
			}
			res += c + 1;
			res += s[i];
			s = res;
		}
		return s;
	}
};

int main()
{
	int n;
	std::cin >> n;
	Solution s;
	std::cout << s.countAndSay(n) << std::endl;
	return 0;
}
