class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    int lineStart = 0, lineEnd = 0;
    int lineCharCount = words[0].size();
    vector<string> ans;

    for (int i = 1; i < words.size(); i++) {
      int wordCount = lineEnd - lineStart + 1;
      if (lineCharCount + words[i].size() + wordCount > maxWidth) {
        // no more words to this line
        if (lineStart != lineEnd) {
          int fullSpaces = (wordCount > 1)
                               ? ((maxWidth - lineCharCount) / (wordCount - 1))
                               : 0;
          int rem = (wordCount > 1)
                        ? ((maxWidth - lineCharCount) % (wordCount - 1))
                        : 0;
          string line = "";
          for (int j = lineStart; j < lineEnd; j++) {
            line +=
                words[j] + string(fullSpaces + (((rem--) > 0) ? 1 : 0), ' ');
          }
          line += words[lineEnd];
          ans.push_back(line);
        } else {
          string line = words[lineStart] +
                        string(maxWidth - words[lineStart].size(), ' ');
          ans.push_back(line);
        }
        lineStart = i;
        lineEnd = i;
        lineCharCount = words[i].size();
      } else {
        lineCharCount += words[i].size();
        lineEnd++;
      }
    }
    if (lineCharCount > 0) {
      string line = "";
      for (int j = lineStart; j <= lineEnd; j++) {
        line += words[j];
        if (j < lineEnd)
          line += " ";
      }
      if (line.size() < maxWidth)
        line += string(maxWidth - line.size(), ' ');
      ans.push_back(line);
    }
    return ans;
  }
};
