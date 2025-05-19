public class Solution {
    private bool HasCycle(int node, Dictionary<int, List<int>> adj, Dictionary<int, bool> visited) {
        if(visited.ContainsKey(node)) return true;
        if(!adj.ContainsKey(node)) return false;
        visited[node] = true;
        foreach(var c in adj[node]) {
            if(HasCycle(c, adj, visited)) return true;
        }
        return false;
    }
    public bool CanFinish(int numCourses, int[][] prerequisites) {
        Dictionary<int, List<int>> adj = [];
        for(int i = 0 ; i < numCourses; i++) {
            if(!adj.ContainsKey(i)) adj[i] = [];
        }

        int[] inbound = new int[numCourses];

        for(int i = 0 ; i < prerequisites.Length; i++) {
            adj[prerequisites[i][1]].Add(prerequisites[i][0]);
            inbound[prerequisites[i][0]]++;
        }

        Queue<int> queue = new Queue<int>();
     
        for(int i = 0 ; i < numCourses ; i++)
        {
            if(inbound[i] == 0)
            {
               queue.Enqueue(i);
            }
        }

        int nodeCount = queue.Count;
        while(queue.Count != 0)
        {
            int t = queue.Dequeue();
            foreach(int i in adj[t])
            {
                if(--inbound[i] == 0)
                {
                    queue.Enqueue(i);
                    nodeCount++;
                }
            }
        }
        
        return nodeCount == numCourses;
    }
}
