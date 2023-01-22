#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../libs/argparse/argparse.hpp"
#include "Chord.h"
#include "Scale.h"
#include "Util.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::make_pair;
using std::pair;
using std::runtime_error;
using std::string;
using std::vector;

void print_info_message() {
  cout << "INPUT OPTIONS:" << endl;
  cout << "- Major: A" << endl;
  cout << "- Minor: Am" << endl;
  cout << "- Sharp: A#" << endl;
  cout << "- Flat: Ab" << endl;
  cout << "- Diminished: Ad" << endl;
  cout << "- Augmented: A+" << endl;
  cout << endl;
  cout << "EXAMPLE:" << endl;
  cout << "> F#m G# C#m" << endl;
  cout << "> +3" << endl;
  cout << "Am B Em" << endl;
  cout << endl;
}

void parse_args(int argc, char* argv[]) {
  argparse::ArgumentParser program("transpose");
  program.add_argument("--info")
      .help("show input options and examples")
      .default_value(false)
      .implicit_value(true);

  try {
    program.parse_args(argc, argv);
  } catch (const runtime_error& err) {
    cerr << err.what() << endl;
    cerr << program;
    std::exit(ARG_PARSE_ERROR);
  }

  if (program["--info"] == true) {
    cout << program << endl;
    print_info_message();
  }
}

string prompt_for_input() {
  string input;
  cout << "> ";
  getline(cin, input);
  return input;
}

int get_input(vector<Chord>& chords) {
  string chord_str;
  string input_line;

  while (true) {
    input_line = prompt_for_input();

    if (!input_line.size()) {
      continue;
    }

    char* p;
    long str_as_l = strtol(input_line.c_str(), &p, 10);
    if (*p == 0) {
      return static_cast<int>(str_as_l);
    }

    istringstream iss(input_line);
    while (iss >> chord_str) {
      if (chord_str == "q") {
        std::exit(QUIT_INPUT_RECEIVED);
      }
      chords.push_back(Chord(chord_str));
    }
  }
}

bool validate(vector<Chord>& chords) {
  for (Chord c : chords) {
    if (c.note == Note::Invalid)
      return false;
    else if (c.accidental == Accidental::Invalid)
      return false;
  }
  return true;
}

void transpose(vector<Chord>& chords, int distance) {
  for (unsigned long i = 0; i < chords.size(); ++i) {
    Chord old_chord = chords[i];
    int curr_degree =
        Scale::degree[make_pair(old_chord.note, old_chord.accidental)];
    while (curr_degree + distance < 0) {
      curr_degree += MOD;
    }
    int new_degree = (curr_degree + distance) % MOD;
    pair<Note, Accidental> new_chord = Scale::default_name[new_degree];

    chords[i] = Chord(new_chord.first, new_chord.second, old_chord.suffix);
  }
}

void print(vector<Chord>& chords) {
  for (Chord c : chords) {
    cout << c;
  }
  cout << endl;
}

int main(int argc, char* argv[]) {
  parse_args(argc, argv);
  vector<Chord> chords;
  int transpose_distance = get_input(chords);

  if (!validate(chords)) {
    return INVALID_CHORD_INPUT;
  }

  transpose(chords, transpose_distance);
  print(chords);

  return SUCCESS;
}
