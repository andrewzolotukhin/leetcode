/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public IList<int> subordinates;
}
*/

class Solution {
    private Dictionary<int, Employee> map = new();
    private Employee Find(Employee e, int id) {
        if(e is null) return null;
        if(e.id == id) return e;
        foreach(var s in e.subordinates) {
            var r = Find(map[s], id);
            if(r is not null) return r;
        }
        return null;
    }
    private int Sum(Employee e) {
        if(e is null) return 0;
        int ans =  e.importance;
        foreach(var s in e.subordinates) {
            ans += Sum(map[s]);
        }
        return ans;
    }
    public int GetImportance(IList<Employee> employees, int id) {
        Employee f = null;
        foreach(var e in employees) map.Add(e.id, e);
        foreach(var e in employees) {
            f = Find(e, id);
            if(f is not null) break;
        }

        if(f is null) return 0;

        return Sum(f);
    }
}
