#include <string>
#include <iostream>
#include "Note.h"

using std::string;
using std::ostream;

Note parse_note(string str) {
  if (str.empty()) {
    return Note::None;
  }

  switch (toupper(str[0])) {
    case 'A':
      return Note::A;
    case 'B':
      return Note::B;
    case 'C':
      return Note::C;
    case 'D':
      return Note::D;
    case 'E':
      return Note::E;
    case 'F':
      return Note::F;
    case 'G':
      return Note::G;
    default:
      return Note::Invalid;
  }
}

ostream& operator<<(ostream& o, const Note& note) {
  switch (note) {
    case Note::A:
      o << "A";
      break;
    case Note::B:
      o << "B";
      break;
    case Note::C:
      o << "C";
      break;
    case Note::D:
      o << "D";
      break;
    case Note::E:
      o << "E";
      break;
    case Note::F:
      o << "F";
      break;
    case Note::G:
      o << "G";
      break;
    default:
      o << "";
      break;
  }
  return o;
};
