#pragma once

#include <iostream>
#include <map>
#include <string>

enum class Note { None, A, B, C, D, E, F, G, Invalid };
enum class Accidental { Sharp, Flat, Natural, Invalid };

Note parse_note(std::string);
Accidental parse_accidental(std::string);
std::ostream &operator<<(std::ostream &, const Note &);
std::ostream &operator<<(std::ostream &, const Accidental &);
