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
  cout << tcolor("Welcome to autocomplete. Please await while the data is validated", BLUE) << endl
       << endl;

  if (argc < 2) {
    cout << tcolor("Missing database filename", RED) << endl;
    return 1;
  }

  ifstream database_file(argv[1]);
  if (!database_file.good()) {
    cout << tcolor("No database file was found with the provided filename", RED) << endl;
    database_file.close();
    return 1;
  }

  cout << tcolor("Reading database file. Please wait", BLUE) << endl;
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
  cout << tcolor("Database file succesfully read!", GREEN) << endl
       << endl;

  cout << ">>> Type a word and hit ENTER or <ctrl>+d to quit: ";
  string query;
  while (getline(cin, query)) {
    auto terms{database.find_terms(query)};

    for (size_t i = 0; i < terms.size(); i++)
      cout << terms[i]->value << endl;

    cout << endl
         << endl;
    cout << ">>> Type a word and hit ENTER or <ctrl>+d to quit: ";
  }

  return 0;
}
