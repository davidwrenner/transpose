#pragma once

#include <string>

enum class Accidental { Sharp, Flat, Natural, Invalid };

Accidental parse_accidental(std::string);
std::ostream &operator<<(std::ostream &, const Accidental &);
