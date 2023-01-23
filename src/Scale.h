#pragma once

#include <unordered_map>

#include "Accidental.h"
#include "Key_T.h"
#include "Note.h"

std::unordered_map<Key_T<Note, Accidental>, unsigned int,
                   KeyHash<Note, Accidental> >
    degree = {{Key_T(Note::A, Accidental::Natural), 0},
              {Key_T(Note::A, Accidental::Sharp), 1},
              {Key_T(Note::B, Accidental::Flat), 1},
              {Key_T(Note::B, Accidental::Natural), 2},
              {Key_T(Note::B, Accidental::Sharp), 3},
              {Key_T(Note::C, Accidental::Flat), 2},
              {Key_T(Note::C, Accidental::Natural), 3},
              {Key_T(Note::C, Accidental::Sharp), 4},
              {Key_T(Note::D, Accidental::Flat), 4},
              {Key_T(Note::D, Accidental::Natural), 5},
              {Key_T(Note::D, Accidental::Sharp), 6},
              {Key_T(Note::E, Accidental::Flat), 6},
              {Key_T(Note::E, Accidental::Natural), 7},
              {Key_T(Note::E, Accidental::Sharp), 8},
              {Key_T(Note::F, Accidental::Flat), 7},
              {Key_T(Note::F, Accidental::Natural), 8},
              {Key_T(Note::F, Accidental::Sharp), 9},
              {Key_T(Note::G, Accidental::Flat), 9},
              {Key_T(Note::G, Accidental::Natural), 10},
              {Key_T(Note::G, Accidental::Sharp), 11},
              {Key_T(Note::A, Accidental::Flat), 11}};

std::unordered_map<unsigned int, Key_T<Note, Accidental> > default_name = {
    {0, Key_T(Note::A, Accidental::Natural)},
    {1, Key_T(Note::B, Accidental::Flat)},
    {2, Key_T(Note::B, Accidental::Natural)},
    {3, Key_T(Note::C, Accidental::Natural)},
    {4, Key_T(Note::C, Accidental::Sharp)},
    {5, Key_T(Note::D, Accidental::Natural)},
    {6, Key_T(Note::E, Accidental::Flat)},
    {7, Key_T(Note::E, Accidental::Natural)},
    {8, Key_T(Note::F, Accidental::Natural)},
    {9, Key_T(Note::F, Accidental::Sharp)},
    {10, Key_T(Note::G, Accidental::Natural)},
    {11, Key_T(Note::A, Accidental::Flat)}};
