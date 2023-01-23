#pragma once

enum class Note { None, A, B, C, D, E, F, G, Invalid };

Note parse_note(std::string);
std::ostream &operator<<(std::ostream &, const Note &);
