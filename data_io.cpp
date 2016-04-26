// Copyright (C) 2015 Ágoston Sasvári
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

#include <fstream>
#include <iostream>
//#include <string>
#include <sstream>
#include <stdlib.h>
//#include <vector>

#include "DAC.hpp"
#include "data_io.hpp"
#include "utils.hpp"

using namespace std;

namespace {

string MASTER_FILE_NAME;

vector <vector <string> > TABLE;

vector <size_t> ALLOWED_CELL_DATA_NUMBER;

const string SEP =";";

const string NUMBERS = "0123456789";

const string LINK_TITLE = "[ BUY ME HERE ]";

}

enum CELLS {
	ITEM_NAME,
	MAIN_CATEGORY,
	SUB_CATEGORY,
	PROPERTIES,
	AVAILABLE,
	ORDER,
	PRICE,
	SHIPPING,
	LINK,
	IMAGE,
	PAYPAL,
	SIZE
};

bool return_MASTER_FILE_NAME (const vector <string>& ARG_V) {

	if (ARG_V.size() == 0) {

		cout << "!     No master spreadsheet defined." << endl;
		return false;
	}

	if (ARG_V.size() > 1) {

		cout << "!     More than 1 argument." << endl;
		return false;
	}

	const string A1 = ARG_V.at(0);
	ifstream MF;
	MF.open (A1.c_str());

	if (MF.is_open()) {

		cout << "    Master file '" << A1 << "' has been found." << endl;
		MASTER_FILE_NAME = A1;
		return true;
	}
	else {

		cout << "!    Cannot open master file '" << A1 << "'." << endl;
		return false;
	}
}

void line_to_table (const string& line, const size_t row_counter) {

	vector <string> row;

	istringstream iss (line);

	string cell;

	while (getline (iss, cell, '\t')) row.push_back (cell);

	TABLE.push_back (row);
}

/*
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
*/

bool read_MASTER_FILE () {

	ifstream MF;
	MF.open (MASTER_FILE_NAME.c_str());

	string buf;
	size_t counter = 0;

	while (getline (MF, buf)) {

		counter++;

		if (buf.size() > 0) {

			line_to_table (buf + '\t', counter);
		}
		else cout << "!    Line " << counter << " is empty." << endl;
	}
	if (TABLE.size() > 0) {

		cout << "    " << TABLE.size() << " rows found in '" << MASTER_FILE_NAME << "' master file." << endl;
		return true;
	}
	else {

		cout << "!   " << MASTER_FILE_NAME << " is empty." << endl;
		return false;
	}
}

void define_allowed_cell_data_number () {

	for (size_t i = 0; i < SIZE; i++) ALLOWED_CELL_DATA_NUMBER.push_back (0);

	ALLOWED_CELL_DATA_NUMBER.at(ITEM_NAME) = 1;
	ALLOWED_CELL_DATA_NUMBER.at(MAIN_CATEGORY) = 999;
	ALLOWED_CELL_DATA_NUMBER.at(SUB_CATEGORY) = 999;
	ALLOWED_CELL_DATA_NUMBER.at(PROPERTIES) = 999;
	ALLOWED_CELL_DATA_NUMBER.at(AVAILABLE) = 1;
	ALLOWED_CELL_DATA_NUMBER.at(ORDER) = 1;
	ALLOWED_CELL_DATA_NUMBER.at(PRICE) = 999;
	ALLOWED_CELL_DATA_NUMBER.at(SHIPPING) = 999;
	ALLOWED_CELL_DATA_NUMBER.at(LINK) = 999;
	ALLOWED_CELL_DATA_NUMBER.at(IMAGE) = 0;
	ALLOWED_CELL_DATA_NUMBER.at(PAYPAL) = 999;
}

vector <string> split_cell_content (const string s) {

	vector <string> OUT;

	if (s.size() == 0) return OUT;

	istringstream iss (s + SEP);

	string cell_element;

	while (getline (iss, cell_element, ';')) {

		if (cell_element.size() > 0) OUT.push_back (cell_element);
	}
	return OUT;
}

bool check_master_cell_data_number () {

	define_allowed_cell_data_number ();

	size_t error = 0;

	for (size_t i = 0; i < TABLE.size(); i++) {
		for (size_t j = 0; j < TABLE.at(i).size(); j++) {

			const string CELL = TABLE.at(i).at(j);

			const vector <string> SPLITTED_CELL = split_cell_content (CELL);

			const size_t S = SPLITTED_CELL.size();
			const size_t A = ALLOWED_CELL_DATA_NUMBER.at(j);

			const bool MORE = S > A;

			if (MORE) {

				cout << "!   More data (" << S << ") in row " << i+1 << ", column " << j+1 << " then expected (" << A << ")." << endl;
				error++;
			}

			const bool LESS = ((S < A || S == 0) && A < 900 && A > 0);

			if (LESS) {

				cout << "!   Less data (" << S << ") in row " << i+1 << ", column " << j+1 << " then expected (" << A << ")." << endl;
				error++;
			}
		}
	}
	if (error > 0) return false;
	return true;
}

bool check_duplicate_names () {

	size_t error = 0;

	for (size_t i = 0; i < TABLE.size(); i++) {
		for (size_t j = i; j < TABLE.size(); j++) {

			const string N1 = TABLE.at(i).at(0);
			const string N2 = TABLE.at(j).at(0);

			if (i != j && N1 == N2) {

				error++;
				cout << "!   Item in row "<< i+1 << " has the same name as in row " << j+1 << " (" << N1 << ")." << endl;
			}
		}
	}
	if (error > 0) return false;
	return true;
}

void check_unwanted_folders () {

	const vector <ITEM> I = return_ITEMS();

	const string FN = "folders.lst";

	string CMD = "dir " + return_ITEMS_FOLDER() + " >> " + FN;
	int RES = system (CMD.c_str());

	vector <string> IT_FOLD;
	vector <string> F;
	string buf;

	ifstream DRLST;
	DRLST.open (FN.c_str());

	while (getline (DRLST, buf)) IT_FOLD.push_back (buf);

	IT_FOLD.erase (IT_FOLD.begin(), IT_FOLD.begin() + 7);
	IT_FOLD.erase (IT_FOLD.end()- 2, IT_FOLD.end());

	for (size_t i = 0; i < IT_FOLD.size(); i++) {

		if (IT_FOLD.at(i).at(22) == 'D') {

			IT_FOLD.at(i).erase (0, 36);

			F.push_back (IT_FOLD.at(i));
		}
	}
	for (size_t i = 0; i < F.size(); i++) {

		bool FOLDER_ON_LIST = false;

		for (size_t j = 0; j < I.size(); j++) {

			if (uppercase (F.at(i)) == uppercase (I.at(j).FOLDER_NAME.at(0))) FOLDER_ON_LIST = true;
		}
		if (! FOLDER_ON_LIST) cout << "!   folder'" << F.at(i) << "' is not on your list." << endl;
	}
	DRLST.close();

	CMD = "del " + FN;
	RES = system (CMD.c_str());
}

bool check_thumbnails () {

	const vector <ITEM> I = return_ITEMS();

	size_t error = 0;

	for (size_t i = 0; i < I.size(); i++) {

		const string TH = I.at(i).THUMBNAIL;

		ifstream T;

		T.open(TH.c_str());

		if (! T.is_open()) {

			cout << "!   ERROR - cannot find the '" << TH << "' thumbnail file." << endl;
			error++;
		}
	}
	if (error > 0) return false;

	cout << "    Thumbnails of each elements were found." << endl;

	return true;
}

bool check_folders_exist () {

	const vector <ITEM> I = return_ITEMS();

	size_t error = 0;

	const string IF = return_ITEMS_FOLDER();

	for (size_t i = 0; i < I.size(); i++) {

		const string DIR = IF + '\\' + I.at(i).FOLDER_NAME.at(0);

		const string CMD = "cd " + DIR;

		const int RES = system (CMD.c_str());

		if (RES) {

			cout << "!   ERROR - cannot find the '" << DIR << "' folder." << endl;
			error++;
		}
	}
	if (error > 0) return false;

	cout << "    Folders of each elements were found." << endl;

	return true;
}

bool string_to_bool (const string& S) {

	const string ST = uppercase (S);

	if (ST == "YES" || ST == "Y") return true;

	return false;
}

vector <string> generate_folder_name (vector <string> ITEM_NAME) {

	vector <string> OUT = ITEM_NAME;

	for (size_t i = 0; i < ITEM_NAME.size(); i++) {

		OUT.at(i) = lowercase (OUT.at(i));

		OUT.at(i) = change_space_to_underscore (OUT.at(i));
	}
	return OUT;
}

vector <ITEM> convert_table_to_items () {

	vector <ITEM> OUT;

	vector <size_t> A = ALLOWED_CELL_DATA_NUMBER;

	const string TH = return_THUMBNAIL_FOLDER();

	for (size_t i = 0; i < TABLE.size(); i++) {

		ITEM buf;

		buf.NUMBER = i+1;

		if (A.at(ITEM_NAME) > 0) 	buf.ITEM_NAME = 	split_cell_content (TABLE.at(i).at(ITEM_NAME));
		if (A.at(MAIN_CATEGORY) > 0)buf.MAIN_CATEGORY = split_cell_content (TABLE.at(i).at(MAIN_CATEGORY));
		if (A.at(SUB_CATEGORY) > 0) buf.SUB_CATEGORY = 	split_cell_content (TABLE.at(i).at(SUB_CATEGORY));
		if (A.at(PROPERTIES) > 0) 	buf.PROPERTIES = 	split_cell_content (TABLE.at(i).at(PROPERTIES));
		if (A.at(AVAILABLE) > 0) 	buf.AVAILABLE = 	string_to_bool (TABLE.at(i).at(AVAILABLE));
		if (A.at(ORDER) > 0) 		buf.ORDER = 		string_to_bool (TABLE.at(i).at(ORDER));
		if (A.at(PRICE) > 0)		buf.PRICE = 		split_cell_content (TABLE.at(i).at(PRICE));
		if (A.at(SHIPPING) > 0) 	buf.SHIPPING = 		split_cell_content (TABLE.at(i).at(SHIPPING));
		if (A.at(LINK) > 0) 		buf.LINK = 			split_cell_content (TABLE.at(i).at(LINK));
		if (A.at(IMAGE) > 0) 		buf.IMAGE = 		split_cell_content (TABLE.at(i).at(IMAGE));
		if (A.at(PAYPAL) > 0) 		buf.PAYPAL = 		split_cell_content (TABLE.at(i).at(PAYPAL));

		buf.FOLDER_NAME = generate_folder_name (buf.ITEM_NAME);

		buf.THUMBNAIL = TH + '\\' + buf.FOLDER_NAME.at(0) + ".jpg";

		OUT.push_back (buf);
	}
	return OUT;
}

vector <string> tidy_item_shipping (const vector <string>& IN) {

	vector <string> OUT = IN;

	OUT.at(0) = OUT.at(0) + " (for UK)";
	OUT.at(1) = OUT.at(1) + " (for Europe)";
	OUT.at(2) = OUT.at(2) + " (for the rest of the world)";

	return OUT;
}

vector <string> tidy_properties (const vector <string> IN, const bool HAND_PAINTED) {

	vector <string> OUT = IN;

	OUT.push_back("All items presented here are unique and hand made");

	OUT.push_back("Because the preparation method and the used material, colour and shape of the final product may vary");

	OUT.push_back("Extra care is taken to deliver as similar product comparing to the displayed one as possible");

	string TXT = "The item should be dispatched within ";

	if (HAND_PAINTED) TXT = TXT + "5";
	else TXT = TXT + "3";

	OUT.push_back(TXT +" working days");

	OUT.push_back("If you have any question please feel free to contact me");

	return OUT;
}

string tidy_item_name (const string IN) {

	string OUT = IN;

	bool HAS_END_NUMBER = false;

	for (size_t i = 0; i < NUMBERS.size(); i++) {

		if (NUMBERS.at(i) == OUT.at(OUT.size() - 1)) HAS_END_NUMBER = true;
	}
	if (HAS_END_NUMBER) OUT.erase(OUT.end()-2, OUT.end());

	return OUT;
}

string tidy_link (const string IN) {

	if (IN.size() == 0) return IN;

	stringstream ss;

	ss << "{" << IN << "{}*" << LINK_TITLE << "*}" << flush;

	return ss.str();
}

vector <ITEM> tidy_items () {

	vector <ITEM> OUT = return_ITEMS();

	for (size_t i = 0; i < OUT.size(); i++) {

		for (size_t j = 0; j < OUT.at(i).ITEM_NAME.size(); j++) {

			OUT.at(i).ITEM_NAME.at(j) = tidy_item_name (OUT.at(i).ITEM_NAME.at(j));
		}

		bool HAND_PAINTED = false;

		for (size_t j = 0; j < OUT.at(i).MAIN_CATEGORY.size(); j++) {

			if (uppercase(OUT.at(i).MAIN_CATEGORY.at(j)) == "HAND-PAINTED") HAND_PAINTED = true;
		}

		for (size_t j = 0; j < OUT.at(i).SUB_CATEGORY.size(); j++) {

			if (uppercase(OUT.at(i).SUB_CATEGORY.at(j)) == "HAND-PAINTED") HAND_PAINTED = true;
		}

		OUT.at(i).PROPERTIES = tidy_properties (OUT.at(i).PROPERTIES, HAND_PAINTED);

		for (size_t j = 0; j < OUT.at(i).LINK.size(); j++) {

			OUT.at(i).LINK.at(j) = tidy_link (OUT.at(i).LINK.at(j));
		}

		const size_t S = OUT.at(i).SHIPPING.size();

		//if (S > 0) OUT.at(i).SHIPPING = tidy_item_shipping (OUT.at(i).SHIPPING);
	}
	return OUT;
}

vector <ITEM> extract_items_pictures_name () {

	vector <ITEM> OUT = return_ITEMS();

	const string IF = return_ITEMS_FOLDER();

	for (size_t i = 0; i < OUT.size(); i++) {

		const string FN = IF + '\\' + OUT.at(i).FOLDER_NAME.at(0);

		dir_item_folder_content (FN);

		OUT.at(i).IMAGE = extract_jpg_files (FN);
	}

	return OUT;
}

 void dir_item_folder_content (const string FN) {

	const string DL = return_FILE_FOR_DIR_LIST();

	const string CMD = "dir " + FN + " >> " + DL;
	const int RES = system (CMD.c_str());

	if (RES) {

		cout << "!   ERROR - cannot find the '" << FN << "' folder." << endl;
		return;
	}
	else {

		string CMD2 = "del " + DL;
		int RES2 = system (CMD2.c_str());

		CMD2 = "dir " + FN + " >> " + DL;
		RES2 = system (CMD2.c_str());

		return;
	}
}

vector <string> extract_jpg_files (const string FN) {

	const string DL = return_FILE_FOR_DIR_LIST();

	ifstream DRLST;
	DRLST.open (DL.c_str());

	vector <string> JPG;
	string buf;

	while (getline (DRLST, buf)) JPG.push_back (buf);

	JPG.erase (JPG.begin(), JPG.begin() + 7);
	JPG.erase (JPG.end()- 2, JPG.end());

	for (size_t i = 0; i < JPG.size(); i++) JPG.at(i) = JPG.at(i).erase (0, 36);

	if (JPG.size() == 0) cout << "!     No jpg files in '" << FN << "' folder." << endl;
	else cout << "    " << JPG.size() << " jpg files were found in '" << FN << "' folder." << endl;

	return JPG;
}

vector <vector <string> > return_TABLE () {

	return TABLE;
}
