#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
	int i = 0, j = nums.size() - 1;

	if (j == -1)
	{
		return {-1, -1};
	}

	if (j == 0)
	{
		if (nums[0] == target)
		{
			return {0, 0};
		}
		else
		{
			return {-1, -1};
		}
	}

	while (i < j)
	{
		// cout << i << " " << j << endl;
		int k = (j - i) / 2;
		if (k == 0)
			k = 1;
		if (nums[i + k] >= target)
		{
			j -= k;
		}
		else
		{
			i += k;
		}
	}

	int l = (i >= 0 && nums[i] == target) ? i : i + 1;

	if (nums.size() <= l || nums[l] != target)
	{
		return {-1, -1};
	}

	i = l;
	j = nums.size() - 1;

	while (i < j)
	{
		// cout << i << "/" << j << endl;
		int k = (j - i) / 2;
		if (k == 0)
			k = 1;
		if (nums[i + k] > target)
		{
			j -= k;
		}
		else
		{
			i += k;
		}
	}

	if (j > nums.size() - 1)
	{
		if (nums[nums.size() - 1] == target)
		{
			j = nums.size() - 1;
		}
		else
		{
			return {-1, -1};
		}
	}

	return {l, i};
}

int main()
{
	vector<vector<int>> vectors;
	string line;

	while (true)
	{
		getline(cin, line);

		if (line.empty())
		{
			break;
		}

		istringstream iss(line);

		vector<int> v;

		int number;

		while (iss >> number)
		{
			v.push_back(number);
		}

		vectors.push_back(v);
	}

	int lI, fI, t;

	for (vector<int> v : vectors)
	{
		lI = v[v.size() - 1];
		v.pop_back();
		fI = v[v.size() - 1];
		v.pop_back();
		t = v[v.size() - 1];
		v.pop_back();

		vector<int> res = searchRange(v, t);

		if (res[0] == fI && res[1] == lI)
		{
			cout << "TRUE";
		}
		else
		{
			cout << "FALSE " << res[0] << " " << res[1];
		}
		cout << endl;
	}

	return 0;
}
