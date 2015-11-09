// Copyright (C) 2015 Ágoston Sasvári
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

#ifndef DATA_IO_HPP_
#define DATA_IO_HPP_

#include <string>
#include <vector>

#include "settings.hpp"

using namespace std;

bool return_MASTER_FILE_NAME (const vector <string>& ARG_V);//ok

vector <string> split_cell_content (const string s);//ok
void line_to_table (const string& line, const size_t row_counter);//ok
vector <string> read_text_file (const string FN);
bool read_MASTER_FILE ();//ok

void define_allowed_cell_data_number ();//ok
bool check_master_cell_data_number ();//ok
bool check_duplicate_names ();//ok
void check_unwanted_folders ();
bool check_thumbnails ();
bool check_folders_exist ();//ok

bool string_to_bool (const string& S);//ok
vector <string> generate_folder_name (vector <string> ITEM_NAME); //ok
vector <ITEM> convert_table_to_items ();

vector <string> tidy_item_shipping (const vector <string>& IN);//ok
string tidy_item_name (const string IN);//ok
vector <ITEM> tidy_items ();

vector <ITEM> extract_items_pictures_name ();
void dir_item_folder_content (const string FN);
vector <string> extract_jpg_files (const string FN);

vector <vector <string> > return_TABLE ();

#endif /* DATA_IO_HPP_ */
