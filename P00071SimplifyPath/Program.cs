using System.Text;

var sol = new Solution();

Console.WriteLine(sol.SimplifyPath("/home/") == "/home" ); // "/home"
Console.WriteLine(sol.SimplifyPath("/home//foo") == "/home/foo" ); // "/home/foo"
Console.WriteLine(sol.SimplifyPath("/home/user/Documents/../Pictures") == "/home/user/Pictures" ); // "/home/user/Pictures"
Console.WriteLine(sol.SimplifyPath("/../") == "/" ); // "/"
Console.WriteLine(sol.SimplifyPath("/.../a/../b/c/../d/./") == "/.../b/d" ); // "/.../b/d"


public class Solution {
    public string SimplifyPath(string path) {
      var parts = path.Split('/', System.StringSplitOptions.RemoveEmptyEntries);

      Stack<string> stack = new Stack<string>();

      foreach(var part in parts) {
        if(part == "..") {
          if(stack.Count > 0) {
            stack.Pop();
          }
        } else if(part != ".") {
          stack.Push(part);
        }
      }

      StringBuilder sb = new StringBuilder();

      while(stack.Count > 0) {
        sb.Insert(0, stack.Pop());
        sb.Insert(0, "/");
      }

      return sb.Length == 0 ? "/" : sb.ToString();
    }
}
