#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>

using namespace std;

namespace StringUtils {
string& ltrim(string& str, const string& chars = "\t\n\v\f\r ") {
  str.erase(0, str.find_first_not_of(chars));
  return str;
}

string& rtrim(string& str, const string& chars = "\t\n\v\f\r ") {
  str.erase(str.find_last_not_of(chars) + 1);
  return str;
}

string& trim(string& str, const string& chars = "\t\n\v\f\r ") {
  return ltrim(rtrim(str, chars), chars);
}

vector<string> split(string& str, const string& delimiter) {
  vector<string> substrings;

  string token;
  size_t position{0};

  while ((position = str.find(delimiter)) != string::npos) {
    token = str.substr(0, position);
    substrings.push_back(token);
    str.erase(0, position + delimiter.length());
  }
  token = str.substr(0, position);
  substrings.push_back(token);

  return substrings;
}
}  // namespace StringUtils

#endif
