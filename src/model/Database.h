#include <bits/stdc++.h>

#include <string>
#include <vector>

#include "./Term.h"

using namespace std;

using terms_type = vector<Term*>;

class Database {
 private:
  terms_type terms;

 public:
  terms_type get_terms() {
    return this->terms;
  }
  void add_term(Term* term) {
    terms.push_back(term);
  }
  terms_type find_terms(string& query) {
    transform(query.begin(), query.end(), query.begin(), ::tolower);

    terms_type matchs;
    Term* term;
    string term_value;

    for (size_t i = 0; i < terms.size(); i++) {
      term = terms[i];

      term_value = term->value;
      transform(term_value.begin(), term_value.end(), term_value.begin(), ::tolower);

      if (term_value.find(query) == 0)
        matchs.push_back(term);
    }

    return matchs;
  }
};
