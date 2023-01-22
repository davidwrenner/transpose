#pragma once
#include <iostream>
#include <string>

#include "Note.h"


struct Chord {
  Note note;
  Accidental accidental;
  std::string suffix;
  Chord(Note, Accidental, std::string);
  Chord(std::string);
};

std::ostream &operator<<(std::ostream &, const Chord &);
