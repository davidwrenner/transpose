#pragma once
#include <iostream>
#include <string>

#include "Accidental.h"
#include "Key_T.h"
#include "Note.h"

struct Chord {
  Note note;
  Accidental accidental;
  std::string suffix;
  Chord(Note, Accidental, std::string);
  Chord(std::string);
};

std::ostream &operator<<(std::ostream &, const Chord &);
