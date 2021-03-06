// Copyright (C) 2015 Ágoston Sasvári
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "utils.hpp"

using namespace std;

vector <string> read_text_file (const string FN) {

	vector <string> OUT;

	ifstream F;
	F.open (FN.c_str());

	string buf;

	while (getline (F, buf)) OUT.push_back (buf);

	if (OUT.size() == 0) cout << "!    File '" << FN << "' is empty." << endl;
	else cout << "    File '" << FN << "' read." << endl;

	return OUT;
}

bool EVEN (const size_t i) {

	if (i % 2 == 0) return true;
	return false;
}

bool by_TITLE (const LINKS& x, const LINKS& y) {

	return x.TITLE < y.TITLE;
}

bool by_rev_TITLE (const LINKS& x, const LINKS& y) {

	return x.TITLE > y.TITLE;
}

bool by_AGE (const ITEM& x, const ITEM& y) {

	return x.NUMBER < y.NUMBER;
}

bool by_rev_AGE (const ITEM& x, const ITEM& y) {

	return x.NUMBER > y.NUMBER;
}

string uppercase (const string S) {

	string out = S;

	transform (out.begin(), out.end(), out.begin(), ::toupper);

	return out;
}

string lowercase (const string S) {

	string out = S;

	transform (out.begin(), out.end(), out.begin(), ::tolower);

	return out;
}

string sentencecase (const string S) {

	string OUT = lowercase (S);

	ostringstream os;

	os << OUT.at(0) << flush;

	const string FRST = uppercase (os.str());

	OUT.at(0) = FRST.at(0);

	return OUT;
}

string change_space_to_underscore (const string IN) {

	string OUT = IN;

	for (size_t i = 0; i < OUT.size(); i++) if (OUT.at(i) == ' ') OUT.at(i) = '_';

	return OUT;
}

string double_to_string(const double in, const int precision) {

	ostringstream os;

	os << fixed << setprecision (precision) << in << flush;

	return os.str();
}

void dump_multiple_records (const vector <string>& I) {

	if (I.size() == 0) cout << endl;

	for (size_t i = 0; i < I.size(); i++) {

		const bool LAST = i == I.size() - 1;

		cout << I.at(i) << flush;

		if (LAST) cout << endl;
		else cout << ", " << flush;
	}
	return;
}

bool contains (const vector <string>& THIS, const string S) {

	for (size_t i = 0; i < THIS.size(); i++) {

		if (uppercase(THIS.at(i)) == uppercase (S)) return true;
	}

	return false;
}
