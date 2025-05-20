public class Solution {
    private int varCount = 0;
    private Dictionary<string, int> vars = [];
    private int LookupVar(string name, bool noCreate = false) {
        if(vars.ContainsKey(name)) return vars[name];
        if(noCreate) return -1;
        return vars[name] = varCount++;
    }
    private double? GetPath(int current, int end, List<(int index, double dist)>[] adj, double curr, HashSet<int> visited) {
        if(visited.Contains(current)) return null;
        if(end == current) return curr;
        visited.Add(current);
        var neighbors = adj[current];

        foreach((int index, double dist) in neighbors) {
            var res = GetPath(index, end, adj, curr*dist, visited);
            if(res is not null) return res;
        }
        visited.Remove(current);
        return null;
    }
    public double[] CalcEquation(IList<IList<string>> equations, double[] values, IList<IList<string>> queries) {
        /*
            a/b = 2
            b/c = 3
            c/d = 5
            a/c = 6
            b/a = 0.5
            a/d = (a/b) * (b/c) * (c/d) = (a/c) * (c/d) = a/d
        */
        foreach(var eq in equations) {
          LookupVar(eq[0]);
          LookupVar(eq[1]);  
        }

        var adj = new List<(int index, double dist)>[varCount];

        for(int i = 0 ; i < varCount; i++) {
            adj[i] = new();
        }

        int index = 0;
        foreach(var eq in equations) {
            var f = LookupVar(eq[0]);
            var s = LookupVar(eq[1]);
            var val = values[index++];
            adj[f].Add((s, val));
            adj[s].Add((f, 1/val));
        }

        List<double> ans = [];
        foreach(var query in queries) {
            var f = LookupVar(query[0], true);
            var s = LookupVar(query[1], true);
            if(f == -1 || s == -1) {
                ans.Add(-1.0);
                continue;
            }
            if(f == s) {
                ans.Add(1.0);
                continue;
            }
            ans.Add(GetPath(f, s, adj, 1.0, [])??-1.0);
        }

        return ans.ToArray();
    }
}
