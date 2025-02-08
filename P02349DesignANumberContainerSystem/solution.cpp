class NumberContainers {
private:
  map<int, set<int>> indexes;
  unordered_map<int, int> values;

public:
  NumberContainers() {}

  void change(int index, int number) {
    if (values.count(index)) {
      int prevValue = values[index];
      indexes[prevValue].erase(index);
    }
    indexes[number].insert(index);
    values[index] = number;
  }

  int find(int number) {
    if (indexes.count(number)) {
      return indexes[number].empty() ? -1 : *indexes[number].begin();
    }
    return -1;
  }
};
