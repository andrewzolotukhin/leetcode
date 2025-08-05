public
class Cashier {
private
  int _sales = 0;
private
  Dictionary<int, int> _productIdToIndex = new ();
private
  readonly int[] _prices;
private
  readonly int _n;
private
  readonly int _discount;
public
  Cashier(int n, int discount, int[] products, int[] prices) {
    for (int i = 0; i < products.Length; i++) {
      _productIdToIndex[products[i]] = i;
    }
    _prices = prices;
    _n = n;
    _discount = discount;
  }

public
  double GetBill(int[] product, int[] amount) {
    _sales++;
    double bill = 0;
    for (int i = 0; i < product.Length; i++) {
      var id = _productIdToIndex[product[i]];
      bill += _prices[id] * amount[i];
    }

    if (_sales % _n == 0) {
      bill *= ((100.0 - _discount) / 100.0);
    }
    return bill;
  }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj.GetBill(product,amount);
 */
