// Copyright (C) 2015 Ágoston Sasvári
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

#ifndef UTILS_HPP_
#define UTILS_HPP_

#include "settings.hpp"

bool EVEN (const size_t i);

bool by_TITLE (const LINKS& x, const LINKS& y);
bool by_rev_TITLE (const LINKS& x, const LINKS& y);
bool by_AGE (const ITEM& x, const ITEM& y);
bool by_rev_AGE (const ITEM& x, const ITEM& y);

string uppercase (const string S);
string lowercase (const string S);
string sentencecase (const string S);

string change_space_to_underscore (const string IN); //ok

string double_to_string(const double in, const int precision);

void dump_multiple_records (const vector <string>& I);

bool contains (const vector <string>& THIS, const string S);

#endif /* UTILS_HPP_ */
