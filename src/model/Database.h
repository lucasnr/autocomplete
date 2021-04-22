#include <bits/stdc++.h>

#include <string>
#include <vector>

#include "./Term.h"

using namespace std;

using terms_type = vector<Term*>;

class Database {
 private:
  terms_type terms;
  void sort_by_weight(terms_type terms) {
    sort(terms.begin(), terms.end(), [](Term* a, Term* b) { return a->weight < b->weight; });
  }

 public:
  terms_type get_terms() {
    return this->terms;
  }
  void add_term(Term* term) {
    transform(term->value.begin(), term->value.end(), term->value.begin(), ::tolower);
    terms.push_back(term);
  }
  terms_type find_terms(string& query) {
    transform(query.begin(), query.end(), query.begin(), ::tolower);

    terms_type matchs;
    Term* term;
    string term_value;

    for (size_t i = 0; i < terms.size(); i++) {
      term = terms[i];
      if (term->value.find(query) == 0)
        matchs.push_back(term);
    }

    sort_by_weight(matchs);
    return matchs;
  }
};
