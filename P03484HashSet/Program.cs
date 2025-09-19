public class Spreadsheet {
    private Dictionary<string, int> _cells = new();
    public Spreadsheet(int rows) {
    }
    
    public void SetCell(string cell, int value) {
        if(_cells.ContainsKey(cell)) {
            _cells[cell] = value;
        } else {
            _cells.Add(cell, value);
        }
    }
    
    public void ResetCell(string cell) {
        SetCell(cell, 0);
    }

    private int GetPartValue(string part) {
        if(part[0] >= 'A' && part[0] <= 'Z') {
            if(_cells.ContainsKey(part)) {
                return _cells[part];
            }
            return 0;
        }

        int.TryParse(part, out int v);
        return v;
    }
    
    public int GetValue(string formula) {
        var r = formula.Substring(1);
        var parts = r.Split('+');
        return GetPartValue(parts[0]) + GetPartValue(parts[1]);
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet obj = new Spreadsheet(rows);
 * obj.SetCell(cell,value);
 * obj.ResetCell(cell);
 * int param_3 = obj.GetValue(formula);
 */
