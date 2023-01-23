
#include "Accidental.h"

#include <iostream>
#include <string>

using std::ostream;
using std::string;

Accidental parse_accidental(string str) {
  if (str.size() <= 1) {
    return Accidental::Natural;
  }

  switch (str[1]) {
    case '#':
      return Accidental::Sharp;
    case 'b':
      return Accidental::Flat;
    default:
      return Accidental::Natural;
  }
}

ostream& operator<<(ostream& o, const Accidental& accidental) {
  switch (accidental) {
    case Accidental::Flat:
      o << "♭";
      break;
    case Accidental::Sharp:
      o << "♯";
      break;
    default:
      o << "";
      break;
  }
  return o;
}
