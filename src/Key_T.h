#pragma once

#include <iostream>
#include <string>

template <typename N, typename A>
struct Key_T {
  N note;
  A accidental;

  Key_T() = default;
  Key_T(N, A);

  bool operator==(const Key_T &) const;
};

template <typename N, typename A>
struct KeyHash {
  size_t operator()(Key_T<N, A> const &key) const {
    size_t h1 = std::hash<unsigned int>{}(static_cast<unsigned int>(key.note));
    size_t h2 =
        std::hash<unsigned int>{}(static_cast<unsigned int>(key.accidental));
    return h1 ^ (h2 << 1);
  }
};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "Key_T.cpp"
#endif
