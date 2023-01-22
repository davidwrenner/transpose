
#include "Note.h"

#include <string>

using std::ostream;
using std::string;

Note parse_note(string str) {
  if (str.empty()) {
    return Note::Invalid;
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

Accidental parse_accidental(string str) {
  if (str.empty()) {
    return Accidental::Invalid;
  } else if (str.size() == 1) {
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
