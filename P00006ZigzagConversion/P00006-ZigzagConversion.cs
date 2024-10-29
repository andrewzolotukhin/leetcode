using System;

namespace P00006ZigzagConversion;

public class P00006_ZigzagConversion
{
	public static string Convert(string s, int numRows)
	{
		if (numRows >= s.Length || s.Length <= 2 || numRows <= 1) return s;

		// Console.WriteLine(s);
		var numCols = numRows * System.Convert.ToInt32(Math.Ceiling(s.Length / (2.0 * numRows - 1)));
		// Console.WriteLine(numCols);
		char[,] cells = new char[numRows, numCols];

		var row = 0;
		var col = 0;
		var goingDown = false;
		for (var i = 0; i < s.Length; i++)
		{
			if (row == 0 || row == numRows - 1)
			{
				goingDown = !goingDown;
			}

			if (goingDown)
			{
				// Console.WriteLine($"{row + 1} {col} {s[i]}");
				cells[row++, col] = s[i];
			}
			else
			{
				// Console.WriteLine($"{row - 1} {col + 1} {s[i]}");
				cells[row--, col++] = s[i];
			}
		}

		var resultArr = new char[s.Length];
		var curr = 0;

		for (var i = 0; i < numRows; i++)
			for (var j = 0; j < numCols; j++)
			{
				if (cells[i, j] != 0)
				{
					resultArr[curr++] = cells[i, j];
				}
			}

		return string.Join(string.Empty, resultArr);
	}
}
