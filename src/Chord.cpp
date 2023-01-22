#include "Chord.h"

#include <string>

#include "Note.h"

using std::ostream;
using std::string;

Chord::Chord(Note n, Accidental a, string suffix)
    : note(n), accidental(a), suffix(suffix) {}

Chord::Chord(string str) {
  Note note = parse_note(str);
  Accidental accidental = parse_accidental(str);
  unsigned int suffix_start_idx =
      accidental == Accidental::Flat || accidental == Accidental::Sharp ? 2 : 1;
  string suffix = str.substr(suffix_start_idx);

  this->note = note;
  this->accidental = accidental;
  this->suffix = suffix;
}

ostream& operator<<(ostream& o, const Chord& chord) {
  o << chord.note << chord.accidental << chord.suffix << " ";
  return o;
};
