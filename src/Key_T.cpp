
#include "Key_T.h"

#include <string>

using std::ostream;
using std::string;

template <typename N, typename A>
Key_T<N, A>::Key_T(N note, A accidental) : note(note), accidental(accidental){};

template <typename N, typename A>
bool Key_T<N, A>::operator==(const Key_T& key) const {
  return this->note == key.note && this->accidental == key.accidental;
}
