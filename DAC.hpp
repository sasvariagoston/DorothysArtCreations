// Copyright (C) 2015 Ágoston Sasvári
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

#ifndef DAC_HPP_
#define DAC_HPP_

//#include <vector>

#include "settings.hpp"

using namespace std;

vector <CATEGOTY> return_MAIN_CATEGORIES ();
vector <CATEGOTY> return_SUB_CATEGORIES ();
vector <ITEM> return_ITEMS ();

void return_categories_list (const string METHOD);//ok
vector <ITEM> elements_of_category (const string THIS, const string METHOD);//ok
void associate_items_categories (const string METHOD);//ok
void generate_categories_vector ();//ok

#endif
