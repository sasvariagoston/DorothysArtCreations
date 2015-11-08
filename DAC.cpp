// Copyright (C) 2015 Ágoston Sasvári
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

//#include <algorithm>
//#include <fstream>
#include <iostream>
//#include <limits>
//#include <math.h>
//#include <string>
//#include <sstream>
//#include <vector>

#include "data_io.hpp"
#include "debug.hpp"
#include "html.hpp"
#include "utils.hpp"
//#include "settings.hpp"

using namespace std;

namespace {

vector <string> MAIN_CAT_NAME;
vector <string> SUB_CAT_NAME;

vector <CATEGOTY> MAIN_CATEGORY;
vector <CATEGOTY> SUB_CATEGORY;

vector <ITEM> ITEMS;

}

vector <CATEGOTY> return_MAIN_CATEGORIES () {

	return MAIN_CATEGORY;
}

vector <CATEGOTY> return_SUB_CATEGORIES () {

	return SUB_CATEGORY;
}

vector <ITEM> return_ITEMS () {

	return ITEMS;
}

void return_categories_list (const string METHOD) {

	const vector <ITEM> I = return_ITEMS ();

	for (size_t i = 0; i < I.size(); i++) {

		vector <string> C = I.at(i).MAIN_CATEGORY;
		if (METHOD == "SUB") C = I.at(i).SUB_CATEGORY;

		for (size_t j = 0; j < C.size(); j++) {

			CATEGOTY buf;

			const string M = C.at(j);

			if (METHOD == "MAIN" && ! contains (MAIN_CAT_NAME, M)) MAIN_CAT_NAME.push_back (uppercase(M));
			if (METHOD == "SUB"  && ! contains (SUB_CAT_NAME, M)) SUB_CAT_NAME.push_back (uppercase(M));
		}
	}
}

vector <ITEM> elements_of_category (const string THIS, const string METHOD) {

	const vector <ITEM> I = return_ITEMS ();

	vector <ITEM> OUT;

	for (size_t i = 0; i < I.size(); i++) {

		vector <string> CAT = I.at(i).MAIN_CATEGORY;
		if (METHOD == "SUB") CAT = I.at(i).SUB_CATEGORY;

		size_t counter = 0;

		for (size_t j = 0; j < CAT.size(); j++) {

			const string C = CAT.at(j);

			if (uppercase(C) == uppercase(THIS)) counter++;
		}
		if (counter > 0) OUT.push_back (I.at(i));
	}
	return OUT;
}

void associate_items_categories (const string METHOD) {

	vector <CATEGOTY> C;

	vector <string> CAT = MAIN_CAT_NAME;
	if (METHOD == "SUB") CAT = SUB_CAT_NAME;

	for (size_t i = 0; i < CAT.size(); i++) {

		CATEGOTY buf;

		buf.CATEGORY_NAME = CAT.at(i);

		buf.ELEMENT = elements_of_category (CAT.at(i), METHOD);

		cout << "    Category '" << CAT.at(i) << "' was fond in " << buf.ELEMENT.size() << " elements." << endl;

		C.push_back (buf);
	}
	if (METHOD == "MAIN") MAIN_CATEGORY = C;
	else SUB_CATEGORY = C;
}

void generate_categories_vector () {

	const vector <ITEM> I = return_ITEMS ();

	vector <CATEGOTY> MAIN_CATEGORY;

	return_categories_list ("MAIN");
	return_categories_list ("SUB");

	associate_items_categories ("MAIN");
	associate_items_categories ("SUB");
}

int main (int argc, char *argv[]) {

	vector <string> ARG_V = vector<string>(argv+1, argv+argc);

	if (! return_MASTER_FILE_NAME (ARG_V)) return 100;//ok

	if (! read_MASTER_FILE ()) return 101;//ok

	if (! check_master_cell_data_number ()) return 102;//ok

	if (! check_duplicate_names ()) return 103;

	//dbg_TABLE ();

	ITEMS = convert_table_to_items ();//ok

	check_unwanted_folders ();

	if (! check_folders_exist ()) return 104;//ok

	if (! check_thumbnails ()) return 105;//ok

	ITEMS = tidy_items ();//ok

	ITEMS = extract_items_pictures_name ();//ok

	generate_categories_vector ();//ok

	//dbg_I_vctr (ITEMS);

	//dbg_categories_list ();

	generate_pages ();

	cout << "DONE." << endl;
}
