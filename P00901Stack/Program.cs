public
class StockSpanner {
private
  Stack<(int val, int count)> _stack = new ();

public
  StockSpanner() {}

public
  int Next(int price) {
    int ans = 1;
    while (_stack.Count > 0 && _stack.Peek().val <= price) {
      ans += _stack.Pop().count;
    }
    _stack.Push((price, ans));
    return ans;
  }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.Next(price);
 */
