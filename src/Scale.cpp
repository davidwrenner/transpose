

#include "Scale.h"

using std::map;
using std::pair;
using std::vector;

map<pair<Note, Accidental>, unsigned int> Scale::degree = {
    {{Note::A, Accidental::Natural}, 0},  {{Note::A, Accidental::Sharp}, 1},
    {{Note::B, Accidental::Flat}, 1},     {{Note::B, Accidental::Natural}, 2},
    {{Note::B, Accidental::Sharp}, 3},    {{Note::C, Accidental::Flat}, 2},
    {{Note::C, Accidental::Natural}, 3},  {{Note::C, Accidental::Sharp}, 4},
    {{Note::D, Accidental::Flat}, 4},     {{Note::D, Accidental::Natural}, 5},
    {{Note::D, Accidental::Sharp}, 6},    {{Note::E, Accidental::Flat}, 6},
    {{Note::E, Accidental::Natural}, 7},  {{Note::E, Accidental::Sharp}, 8},
    {{Note::F, Accidental::Flat}, 7},     {{Note::F, Accidental::Natural}, 8},
    {{Note::F, Accidental::Sharp}, 9},    {{Note::G, Accidental::Flat}, 9},
    {{Note::G, Accidental::Natural}, 10}, {{Note::G, Accidental::Sharp}, 11},
    {{Note::A, Accidental::Flat}, 11}};

map<unsigned int, pair<Note, Accidental> > Scale::default_name = {
    {0, {Note::A, Accidental::Natural}},  {1, {Note::B, Accidental::Flat}},
    {2, {Note::B, Accidental::Natural}},  {3, {Note::C, Accidental::Natural}},
    {4, {Note::C, Accidental::Sharp}},    {5, {Note::D, Accidental::Natural}},
    {6, {Note::E, Accidental::Flat}},     {7, {Note::E, Accidental::Natural}},
    {8, {Note::F, Accidental::Natural}},  {9, {Note::F, Accidental::Sharp}},
    {10, {Note::G, Accidental::Natural}}, {11, {Note::A, Accidental::Flat}}};
