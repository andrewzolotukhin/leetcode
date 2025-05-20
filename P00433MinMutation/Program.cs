public class Solution {
    HashSet<string> bank = new();
    Dictionary<string, string[]> validMutations = [];
    static char[] genes = ['A', 'C', 'G', 'T'];

    private string[] generateMutations(string gene) {
        if(validMutations.ContainsKey(gene)) return validMutations[gene];
        List<string> ans = [];

        var bankFromSpan = bank.GetAlternateLookup<ReadOnlySpan<char>>();

        Span<char> span = stackalloc char[gene.Length];
        gene.AsSpan().CopyTo(span);

        //Console.WriteLine($"{gene}:");

        for(int i = 0 ; i < span.Length; i++) {
            char init = span[i];
            for(int j = 0; j < genes.Length; j++) {
                if(init==genes[j]) continue;
                span[i] = genes[j];
                if(bankFromSpan.Contains(span)) {
                    //Console.WriteLine($" - {span}");
                    ans.Add(new string(span));
                }
                span[i] = init;
            }
        }

        return validMutations[gene] = ans.ToArray();
    }

    public int MinMutation(string startGene, string endGene, string[] bank) {
        foreach(var b in bank) {
            this.bank.Add(b);
        }
        

        var pq = new Queue<(string, int)>();

        HashSet<string> visited = [startGene];
        pq.Enqueue((startGene, 0));
        visited.Add(startGene);

        while(pq.Count > 0) {
            (string g, int length) = pq.Dequeue();
            if(g == endGene) {
                return length;
            }

            foreach(var m in generateMutations(g).Where(t => !visited.Contains(t))) {
                visited.Add(m);
                pq.Enqueue((m, length + 1));
            }
        }

        return -1;
    }
}
