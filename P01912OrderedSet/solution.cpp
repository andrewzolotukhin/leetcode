class MovieRentingSystem {
public:
  unordered_map<int, unordered_map<int, int>>
      pricesInShop; // [shop][movie] : price
  unordered_map<int, set<pair<int, int>>>
      droppedByMovie;             // [movie] : {price, shop}
  set<array<int, 3>> rentedItems; // {price, shop, movie}
  MovieRentingSystem(int n, vector<vector<int>> &entries) {
    for (auto &e : entries) {
      droppedByMovie[e[1]].insert({e[2], e[0]});
      pricesInShop[e[0]][e[1]] = e[2];
    }
  }
  vector<int> search(int movie) {
    vector<int> res;
    for (auto &[price, shop] : droppedByMovie[movie]) {
      res.push_back(shop);
      if (res.size() == 5)
        break;
    }
    return res;
  }
  void rent(int shop, int movie) {
    int price = pricesInShop[shop][movie];
    droppedByMovie[movie].erase(droppedByMovie[movie].find({price, shop}));
    rentedItems.insert({price, shop, movie});
  }
  void drop(int shop, int movie) {
    int price = pricesInShop[shop][movie];
    rentedItems.erase(rentedItems.find({price, shop, movie}));
    droppedByMovie[movie].insert({price, shop});
  }
  vector<vector<int>> report() {
    vector<vector<int>> res;
    for (auto &[price, shop, movie] : rentedItems) {
      res.push_back({shop, movie});
      if (res.size() == 5)
        break;
    }
    return res;
  }
};
