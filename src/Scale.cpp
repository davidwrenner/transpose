

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

// degree => num sharps
map<unsigned int, unsigned int> Scale::sharps_per_key = {
    {3, 0},   // CMaj
    {10, 1},  // G
    {5, 2},   // D
    {0, 3},   // A
    {7, 4},   // E
    {2, 5},   // B
    {9, 6},   // F#
    {4, 7}    // C#
};

// degree => num flats
map<unsigned int, unsigned int> Scale::flats_per_key = {
    {3, 0},   // CMaj
    {8, 1},   // F
    {1, 2},   // Bb
    {6, 3},   // Eb
    {11, 4},  // Ab
    {4, 5},   // Db
    {9, 6},   // Gb
    {2, 7}    // Cb
};

vector<Note> Scale::sharps_order = {Note::F, Note::C, Note::G, Note::D,
                                    Note::A, Note::E, Note::B};

vector<Note> Scale::flats_order = {Note::B, Note::E, Note::A, Note::D,
                                   Note::G, Note::C, Note::F};