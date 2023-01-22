#pragma once

#include <map>
#include <vector>

#include "Note.h"

struct Scale {
  static std::map<std::pair<Note, Accidental>, unsigned int> degree;
  static std::map<unsigned int, std::pair<Note, Accidental> > default_name;
  static std::map<unsigned int, unsigned int> sharps_per_key;
  static std::map<unsigned int, unsigned int> flats_per_key;
  static std::vector<Note> sharps_order;
  static std::vector<Note> flats_order;
};