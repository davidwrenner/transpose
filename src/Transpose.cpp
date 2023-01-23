#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../libs/argparse/argparse.hpp"
#include "Accidental.h"
#include "Chord.h"
#include "Note.h"
#include "Scale.h"
#include "Util.h"

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::ofstream;
using std::runtime_error;
using std::string;
using std::vector;

string g_input_file = "";
string g_output_file = "";
Key_T<Note, Accidental> g_to_key =
    Key_T(Note::None, Accidental::Natural);
Key_T<Note, Accidental> g_from_key =
    Key_T(Note::None, Accidental::Natural);

void reset_key_globals() {
  g_to_key = Key_T(Note::None, Accidental::Natural);
  g_from_key = Key_T(Note::None, Accidental::Natural);
}

void warn(string str) { cout << "[WARNING]: " << str << endl; }

void fatal(string str) { cout << "[FATAL]: " << str << endl; }

void parse_args(int argc, char* argv[]) {
  argparse::ArgumentParser program("transpose");
  program.add_argument("-f", "--from")
      .help("specify the key of input chords, must be used with --to")
      .default_value<string>("");
  program.add_argument("-i", "--input")
      .help("specify file path containing chord inputs")
      .default_value<string>("");
  program.add_argument("-o", "--output")
      .help("specify file path to write output")
      .default_value<string>("");
  program.add_argument("-t", "--to")
      .help(
          "specify the key in which the output chords will be written, must be "
          "used with --from")
      .default_value<string>("");

  try {
    program.parse_args(argc, argv);
  } catch (const runtime_error& err) {
    cerr << err.what() << endl;
    cerr << program;
    std::exit(ARG_PARSE_ERROR);
  }

  if (program.is_used("--input")) {
    g_input_file = program.get<string>("--input");
    if (g_input_file.empty()) {
      warn("no file path specified with --input");
    }
  }
  if (program.is_used("output")) {
    g_output_file = program.get<string>("--output");
    if (g_output_file.empty()) {
      warn("no file path specified with --output");
    }
  }
  if (program.is_used("--output")) {
    string fp = program.get<string>("--output");
    if (!fp.empty()) {
      g_output_file = fp;
    }
  }
  if (program.is_used("--to")) {
    string to_key = program.get<string>("--to");
    g_to_key = Key_T(parse_note(to_key), parse_accidental(to_key));
    if (g_to_key.note == Note::Invalid || g_to_key.note == Note::None) {
      warn("bad key provided with --to. Reverting to defaults.");
      reset_key_globals();
    }
  }
  if (program.is_used("--from")) {
    string to_key = program.get<string>("--from");
    g_from_key = Key_T(parse_note(to_key), parse_accidental(to_key));
    if (g_from_key.note == Note::Invalid || g_from_key.note == Note::None) {
      warn("bad key provided with --from. Reverting to defaults.");
      reset_key_globals();
    }
  }
  if (program.is_used("--to") ^ program.is_used("--from")) {
    warn("--to must be used with --from. Reverting to defaults.");
    reset_key_globals();
  }
}

string get_line() {
  string input;
  cout << "> ";
  getline(cin, input);
  return input;
}

string get_line(ifstream& ifs) {
  string input;
  getline(ifs, input);
  cout << "> " << input << endl;
  return input;
}

int get_input(vector<Chord>& chords) {
  string chord_str;
  string input_line;
  ifstream ifs;
  bool is_using_file_input = false;

  if (!g_input_file.empty()) {
    ifs.open(g_input_file);
    if (ifs.is_open()) {
      is_using_file_input = true;
    }
  }

  while (true) {
    input_line = is_using_file_input ? get_line(ifs) : get_line();

    if (!input_line.size()) {
      if (g_from_key.note != Note::None && g_to_key.note != Note::None) {
        ifs.close();
        return degree[g_to_key] - degree[g_from_key];
      } else if (ifs.peek() == EOF) {
        warn("did not find transposition distance input in file");
        is_using_file_input = false;
      }
      continue;
    }

    char* p;
    long str_as_l = strtol(input_line.c_str(), &p, 10);
    if (*p == 0) {
      ifs.close();
      return static_cast<int>(str_as_l);
    }

    istringstream iss(input_line);
    while (iss >> chord_str) {
      if (chord_str == QUIT_INPUT) {
        ifs.close();
        std::exit(QUIT_INPUT_RECEIVED);
      }
      chords.push_back(Chord(chord_str));
    }
  }
}

bool validate(vector<Chord>& chords) {
  for (unsigned long i = 0; i < chords.size(); ++i) {
    Chord c = chords[i];
    if (c.note == Note::Invalid || c.accidental == Accidental::Invalid) {
      fatal("bad chord input in position " + std::to_string(i + 1));
      return false;
    }
  }
  return true;
}

void transpose(vector<Chord>& chords, int distance) {
  for (unsigned long i = 0; i < chords.size(); ++i) {
    Chord old_chord = chords[i];
    int curr_degree = degree[Key_T(old_chord.note, old_chord.accidental)];
    while (curr_degree + distance < 0) {
      curr_degree += MOD;
    }
    int new_degree = (curr_degree + distance) % MOD;
    Key_T<Note, Accidental> new_key(default_name[new_degree]);

    chords[i] = Chord(new_key.note, new_key.accidental, old_chord.suffix);
  }
}

void output(vector<Chord>& chords) {
  ofstream ofs;
  if (!g_output_file.empty()) {
    ofs.open(g_output_file);
  }

  for (Chord c : chords) {
    cout << c;
    if (ofs.is_open()) {
      ofs << c;
    }
  }

  cout << endl;
  if (ofs.is_open()) {
    ofs << endl;
    ofs.close();
  }
}

int main(int argc, char* argv[]) {
  parse_args(argc, argv);
  vector<Chord> chords;
  int transpose_distance = get_input(chords);

  if (!validate(chords)) {
    return INVALID_CHORD_INPUT;
  }

  transpose(chords, transpose_distance);
  output(chords);

  return SUCCESS;
}
