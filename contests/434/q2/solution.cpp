#include <bits/stdc++.h>
#include <functional>
#include <sstream>
using namespace std;

class Solution {
private:
  vector<string> getTokens(string &input) {
    vector<string> uniqueStrings;
    istringstream stream(input);
    string word;

    while (stream >> word) {
      uniqueStrings.push_back(word);
    }

    auto res = vector<string>(uniqueStrings.begin(), uniqueStrings.end());

    sort(res.begin(), res.end(), greater<>());
    return res;
  }

public:
  vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events) {
    sort(events.begin(), events.end(),
         [](const vector<string> &a, const vector<string> &b) {
           if (a[1] != b[1]) {
             return stoi(a[1]) < stoi(b[1]);
           }

           return a[0] > b[0];
         });

    vector<int> mentions(numberOfUsers, 0);
    vector<int> offlineUntil(numberOfUsers, -1);

    for (int i = 0; i < events.size(); i++) {
      auto event = events[i];
      auto type = event[0];
      auto timestamp = stoi(event[1]);
      auto tokens = getTokens(event[2]);

      if (type == "MESSAGE") {
        for (auto token : tokens) {
          if (token == "ALL") {
            for (int j = 0; j < numberOfUsers; j++) {
              mentions[j]++;
            }
            break;
          }
          if (token == "HERE") {
            for (int j = 0; j < numberOfUsers; j++) {
              if (offlineUntil[j] <= timestamp) {
                mentions[j]++;
              }
            }
          } else {
            // replace "id" with ""
            auto s = stoi(token.substr(2));
            mentions[s]++;
          }
        }
      } else if (type == "OFFLINE") {
        auto s = stoi(event[2]);
        offlineUntil[s] = timestamp + 60;
      }
    }

    return mentions;
  }
};

int main() {
  int n, e;

  cin >> n >> e;

  vector<vector<string>> events;

  while (e--) {
    vector<string> event;

    string type, timestamp, recipients;

    getline(cin >> ws, type);
    getline(cin >> ws, timestamp);
    getline(cin >> ws, recipients);

    event.push_back(type);
    event.push_back(timestamp);
    event.push_back(recipients);

    events.push_back(event);
  }

  vector<int> result = Solution().countMentions(n, events);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << '\n';
  }
}
