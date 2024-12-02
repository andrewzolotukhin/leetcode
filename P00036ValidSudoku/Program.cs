char[][] board = [
	['5', '3', '.', '.', '7', '.', '.', '.', '.'],
	['6', '.', '.', '1', '9', '5', '.', '.', '.'],
	['.', '9', '8', '.', '.', '.', '.', '6', '.'],
	['8', '.', '.', '.', '6', '.', '.', '.', '3'],
	['4', '.', '.', '8', '.', '3', '.', '.', '1'],
	['7', '.', '.', '.', '2', '.', '.', '.', '6'],
	['.', '6', '.', '.', '.', '.', '2', '8', '.'],
	['.', '.', '.', '4', '1', '9', '.', '.', '5'],
	['.', '.', '.', '.', '8', '.', '.', '7', '9']
]; // true

char[][] board2 = [
	['8','3','.','.','7','.','.','.','.'],
	['6','.','.','1','9','5','.','.','.'],
	['.','9','8','.','.','.','.','6','.'],
	['8','.','.','.','6','.','.','.','3'],
	['4','.','.','8','.','3','.','.','1'],
	['7','.','.','.','2','.','.','.','6'],
	['.','6','.','.','.','.','2','8','.'],
	['.','.','.','4','1','9','.','.','5'],
	['.','.','.','.','8','.','.','7','9']
]; // false

char[][] board3 = [
	['.','.','5','.','.','.','.','.','.'],
	['1','.','.','2','.','.','.','.','.'],
	['.','.','6','.','.','3','.','.','.'],
	['8','.','.','.','.','.','.','.','.'],
	['3','.','1','5','2','.','.','.','.'],
	['.','.','.','.','.','.','.','4','.'],
	['.','.','6','.','.','.','.','.','.'],
	['.','.','.','.','.','.','.','9','.'],
	['.','.','.','.','.','.','.','.','.']
]; // false

char[][] board4 = [
	['.','.','.','.','.','.','.','5','.'],
	['.','.','.','.','.','.','.','.','.'],
	['.','.','6','1','.','.','2','.','.'],
	['7','.','.','.','.','.','7','.','.'],
	['.','.','.','.','.','.','.','.','.'],
	['.','.','.','.','.','3','.','.','.'],
	['.','3','.','.','.','5','8','.','.'],
	['.','.','.','2','.','.','.','3','.'],
	['.','.','.','.','.','.','.','.','.']
]; // false

Console.WriteLine(Solution.IsValidSudoku(board4));

public class Solution
{

	private enum Direction
	{
		Bottom,
		Right
	}

	private class SudokuBoardPartLine
	{
		private char[] _values;

		public char[] Values
		{
			get
			{
				return _values.Where(v => v != '.').ToArray();
			}
		}

		public char First => _values[0];
		public char Second => _values[1];
		public char Third => _values[2];

		public bool IsValid
		{
			get
			{
				// check that all non-empty values are unique
				var nonEmptyValues = _values.Where(v => v != '.').ToArray();
				return nonEmptyValues.Length == nonEmptyValues.Distinct().Count();
			}
		}

		public SudokuBoardPartLine(char[] values)
		{
			ArgumentNullException.ThrowIfNull(values);
			if (values.Length != 3)
			{
				throw new ArgumentException("The values array must have 3 elements.");
			}
			_values = values;
		}
	}

	private class SudokuBoardPart
	{
		private bool? _isValid = null;

		public char[] Values
		{
			get
			{
				// return all values in the board part
				// that are not empty
				return new char[] {
					_rows[0].First, _rows[0].Second, _rows[0].Third,
					_rows[1].First, _rows[1].Second, _rows[1].Third,
					_rows[2].First, _rows[2].Second, _rows[2].Third
				}.Where(v => v != '.').ToArray();
			}
		}

		public Dictionary<Direction, SudokuBoardPart> Neighbors { get; private set; } = new();

		public SudokuBoardPart AddNeighbor(Direction direction, SudokuBoardPart neighbor)
		{
			ArgumentNullException.ThrowIfNull(neighbor);
			Neighbors[direction] = neighbor;
			return this;
		}

		public char[] GetNeighborValues(Direction direction, int index)
		{
			return !Neighbors.ContainsKey(direction) ? ([]) : [
				.. (direction == Direction.Bottom ? Neighbors[direction].Columns[index].Values : Neighbors[direction].Rows[index].Values),
				.. Neighbors[direction].GetNeighborValues(direction, index)];
		}

		public bool IsValid
		{
			get
			{
				if (_isValid.HasValue)
				{
					return _isValid.Value;
				}

				var selfValid = _rows.All(r => r.IsValid) && _columns.All(c => c.IsValid) && Values.Length == Values.Distinct().Count();
				if (!selfValid)
				{
					_isValid = false;
					return false;
				}

				var allNeighbors = Neighbors.Where(n => n.Value != null);
				var neighborsValid = allNeighbors.All(n => n.Value.IsValid);

				if (!neighborsValid)
				{
					_isValid = false;
					return false;
				}

				var cols = Enumerable.Range(0, 3).Select<int, char[]>(i => [
					.. Columns[i].Values,
					.. GetNeighborValues(Direction.Bottom, i),
				]);

				var rows = Enumerable.Range(0, 3).Select<int, char[]>(i => [
					.. Rows[i].Values,
					.. GetNeighborValues(Direction.Right, i),
				]);

				var allRowsAndColsHaveDistinctValues = rows.All(r => r.Length == r.Distinct().Count()) && cols.All(c => c.Length == c.Distinct().Count());

				if (!allRowsAndColsHaveDistinctValues)
				{
					_isValid = false;
					return false;
				}

				_isValid = true;
				return true;
			}
		}

		private SudokuBoardPartLine[] _rows = new SudokuBoardPartLine[3];
		private SudokuBoardPartLine[] _columns = new SudokuBoardPartLine[3];

		public SudokuBoardPartLine[] Rows => _rows;
		public SudokuBoardPartLine[] Columns => _columns;


		public SudokuBoardPart(char[][] values)
		{
			ArgumentNullException.ThrowIfNull(values);

			if (values.Length != 3)
			{
				throw new ArgumentException("The values array must have 3 elements.");
			}

			foreach (var row in values)
			{
				if (row.Length != 3)
				{
					throw new ArgumentException("Each row must have 3 elements.");
				}
			}

			_rows[0] = new([values[0][0], values[0][1], values[0][2]]);
			_rows[1] = new([values[1][0], values[1][1], values[1][2]]);
			_rows[2] = new([values[2][0], values[2][1], values[2][2]]);

			_columns[0] = new([values[0][0], values[1][0], values[2][0]]);
			_columns[1] = new([values[0][1], values[1][1], values[2][1]]);
			_columns[2] = new([values[0][2], values[1][2], values[2][2]]);
		}
	}

	public static bool IsValidSudoku(char[][] board)
	{
		var boardPart1 = new SudokuBoardPart(board[..3].Select(r => r[..3]).ToArray());
		var boardPart2 = new SudokuBoardPart(board[..3].Select(r => r[3..6]).ToArray());
		var boardPart3 = new SudokuBoardPart(board[..3].Select(r => r[6..9]).ToArray());
		var boardPart4 = new SudokuBoardPart(board[3..6].Select(r => r[..3]).ToArray());
		var boardPart5 = new SudokuBoardPart(board[3..6].Select(r => r[3..6]).ToArray());
		var boardPart6 = new SudokuBoardPart(board[3..6].Select(r => r[6..9]).ToArray());
		var boardPart7 = new SudokuBoardPart(board[6..9].Select(r => r[..3]).ToArray());
		var boardPart8 = new SudokuBoardPart(board[6..9].Select(r => r[3..6]).ToArray());
		var boardPart9 = new SudokuBoardPart(board[6..9].Select(r => r[6..9]).ToArray());
		boardPart1.AddNeighbor(Direction.Right, boardPart2);
		boardPart1.AddNeighbor(Direction.Bottom, boardPart4);
		boardPart2.AddNeighbor(Direction.Right, boardPart3);
		boardPart2.AddNeighbor(Direction.Bottom, boardPart5);
		boardPart3.AddNeighbor(Direction.Bottom, boardPart6);
		boardPart4.AddNeighbor(Direction.Right, boardPart5);
		boardPart4.AddNeighbor(Direction.Bottom, boardPart7);
		boardPart5.AddNeighbor(Direction.Right, boardPart6);
		boardPart5.AddNeighbor(Direction.Bottom, boardPart8);
		boardPart6.AddNeighbor(Direction.Bottom, boardPart9);
		boardPart7.AddNeighbor(Direction.Right, boardPart8);
		boardPart8.AddNeighbor(Direction.Right, boardPart9);

		return boardPart1.IsValid;
	}
}