class Solution {
private:
  bool canFit(vector<int> &skill, vector<int> &mana, long long st, int j,
              long long val) {
    int n = skill.size();
    long long prev = st + skill[0] * mana[j];
    long long curr = val;
    for (int i = 0; i < n; i++) {
      if (curr < prev)
        return false;
      if (i != n - 1) {
        prev += skill[i + 1] * mana[j];
      }
      curr += skill[i] * mana[j + 1];
      // cout << prev << " - " << curr << '\n';
    }
    return curr >= prev;
  }

public:
  long long minTime(vector<int> &skill, vector<int> &mana) {
    int n = skill.size();
    int m = mana.size();
    long long mst = 0;
    long long met = 0;

    long long allSkills = 0;
    for (int i = 0; i < n; i++) {
      allSkills += skill[i];
    }

    met = allSkills * mana[0];

    for (int j = 1; j < m; j++) {
      long long l = mst;
      long long r = met;

      while (l < r) {

        long long mid = (l + r) / 2;
        // cout << l << ' ' << r << ' ' << mid << endl;
        if (canFit(skill, mana, mst, j - 1, mid)) {
          //    cout << mid << " yes" << '\n';
          r = mid;
        } else {
          //    cout << mid << " no, met: " << met << '\n';
          l = mid + 1;
        }
      }

      mst = l;
      met = mst + allSkills * mana[j];
      //   cout << "mst: " << mst << ", met: " << met << endl;

      // if(j == m - 1) return met;
    }
    return met;
  }
};
