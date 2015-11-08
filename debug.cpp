// Copyright (C) 2015 Ágoston Sasvári
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

#include <iostream>
#include <vector>

#include "DAC.hpp"
#include "data_io.hpp"
#include "settings.hpp"
#include "utils.hpp"

using namespace std;

void dbg_I (const ITEM& I) {

	cout << " ----------------NEW ITEM ---------------- " << endl;

	cout << "  ID            : " << I.NUMBER << endl;

	cout << "  NAME          : " << flush;
	dump_multiple_records (I.ITEM_NAME);

	cout << "  MAIN CATEGORY : " << flush;
	dump_multiple_records (I.MAIN_CATEGORY);

	cout << "  SUB CATEGORY  : " << flush;
	dump_multiple_records (I.SUB_CATEGORY);

	cout << "  PROPERTIES    : " << flush;
	dump_multiple_records (I.PROPERTIES);

	cout << "  AVAILABLE     : " << flush;
	if (I.AVAILABLE == 0) cout << "Not available" << endl;
	else cout << "Available" << endl;

	cout << "  ORDER         : " << flush;
	if (I.ORDER == 0) cout << "Not possible to order" << endl;
	else cout << "Possible to order" << endl;

	cout << "  PRICE         : " << flush;
	dump_multiple_records (I.PRICE);

	cout << "  SHIPPING      : " << flush;
	dump_multiple_records (I.SHIPPING);

	cout << "  ETSY LINK     : " << flush;
	dump_multiple_records (I.LINK );

	cout << "  IMAGE         : " << flush;
	dump_multiple_records (I.IMAGE);

	cout << "  FOLDER_NAME   : " << flush;
	dump_multiple_records (I.FOLDER_NAME);

	//cout << "  IMAGENUMBER   : " << I.IMAGENUMBER << endl;
}

void dbg_I_vctr (const vector <ITEM>& I) {

	for (size_t i = 0; i < I.size(); i++) dbg_I (I.at(i));

	cout << " ---------------- END LIST ---------------- " << endl;
}

void dbg_TABLE () {

	vector <vector <string> > T = return_TABLE ();

	for (size_t i = 0; i < T.size(); i++) {
		for (size_t j = 0; j < T.at(i).size(); j++) {

			if (j < T.at(i).size() - 1) cout << T.at(i).at(j) << '\t' << flush;
			else cout << T.at(i).at(j) << endl;;
		}
	}
}

void dbg_categories_list () {

	const vector <CATEGOTY> M = return_MAIN_CATEGORIES();
	const vector <CATEGOTY> S = return_SUB_CATEGORIES();

	cout << " ---------------- START MAIN CATEGORIES ---------------- " << endl;

	for (size_t i = 0; i < M.size(); i++) {

		cout << "==============================" << endl;
		cout << M.at(i).CATEGORY_NAME << endl;
		cout << "==============================" << endl;
		dbg_I_vctr (M.at(i).ELEMENT);
	}
	cout << " ---------------- END MAIN CATEGORIES ---------------- " << endl << endl << endl;




	cout << " ---------------- START SUB CATEGORIES ---------------- " << endl;

	for (size_t i = 0; i < S.size(); i++) {

		cout << "==============================" << endl;
		cout << S.at(i).CATEGORY_NAME << endl;
		cout << "==============================" << endl;
		dbg_I_vctr (S.at(i).ELEMENT);
	}
	cout << " ---------------- END SUB CATEGORIES ---------------- " << endl;

	return;
}
