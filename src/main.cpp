#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "./lib/Color.h"
#include "./lib/StringUtils.h"
#include "./model/Database.h"

using namespace std;

using namespace Color;
using namespace StringUtils;

int main(int argc, char** argv) {
  if (argc < 2) {
    cout << tcolor("Missing database filename", RED);
    return 1;
  }

  ifstream database_file(argv[1]);
  if (!database_file.good()) {
    cout << tcolor("No database file was found with the provided filename", RED) << endl;
    database_file.close();
    return 1;
  }

  Database database;
  Term* term;

  vector<string> pair;
  long weight;
  string value;

  string line;
  getline(database_file, line);
  while (getline(database_file, line)) {
    trim(line);
    pair = split(line, "\t");

    weight = atol(pair[0].c_str());
    value = pair[1];

    term = new Term();
    term->weight = weight;
    term->value = value;

    database.add_term(term);
  }
  database_file.close();

  cout << ">>> Type a word and hit ENTER or <ctrl>+d to quit: ";
  string query;
  while (getline(cin, query)) {
    auto terms{database.find_terms(query)};

    for (size_t i = 0; i < terms.size(); i++)
      cout << terms[i]->value << endl;

    cout << ">>> Type a word and hit ENTER or <ctrl>+d to quit: ";
  }

  return 0;
}
