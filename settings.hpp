// Copyright (C) 2015 Ágoston Sasvári
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include <string>
#include <vector>

using namespace std;

namespace {

const string ITEMS_FOLDER = "items";
const string ELEMENT_HTML_FOLDER = "html";
const string THUMBNAIL_FOLDER = "thumbnails";

const string FILE_FOR_DIR_LIST = "dir.lst";
const string HTML_HEAD_TITLE = "Dorothy's Art Creations";

const string PINK1 = "247, 237, 244";
const string PINK2 = "235, 213, 231";
const string PINK3 = "216, 179, 209";
const string PINK4 = "187, 128, 175";
const string PINK5 = "144, 030, 120";

const string BLACK = "0, 0, 0";
const string WHITE = "255, 255, 255";

}

struct ITEM {

	//from master spreadsheet
	size_t 			NUMBER;
	vector <string> ITEM_NAME;
	vector <string> MAIN_CATEGORY;
	vector <string> SUB_CATEGORY;
	vector <string> PROPERTIES;
	bool 			AVAILABLE;
	bool 			ORDER;
	vector <string> PRICE;
	vector <string> SHIPPING;
	vector <string> LINK;
	vector <string> IMAGE;

	//others
	vector <string> FOLDER_NAME;
	string THUMBNAIL;
};

struct LINKS {

	string TITLE;
	string TARGET;
	string HREF;
	string IMAGE;
};

struct CATEGOTY {

	string CATEGORY_NAME;
	vector <ITEM> ELEMENT;
};

string return_ITEMS_FOLDER ();
string return_ELEMENT_HTML_FOLDER ();
string return_THUMBNAIL_FOLDER ();
string return_FILE_FOR_DIR_LIST ();
string return_HTML_HEAD_TITLE ();

string return_PINK1 ();
string return_PINK2 ();
string return_PINK3 ();
string return_PINK4 ();
string return_PINK5 ();
string return_WHITE ();
string return_BLACK ();

string return_HEADER_background_color ();
string return_HEADER_jpg_border_color ();
string return_HEADER_border_color ();
string return_HEADER_border_style ();
string return_HEADER_border_width ();
string return_HEADER_link_font_family ();
string return_HEADER_link_font_size ();
string return_HEADER_link_font_weight ();
string return_HEADER_link_text_align ();
string return_HEADER_link_text_vertical_align ();
string return_HEADER_active_link_color ();
string return_HEADER_passive_link_color ();

string return_INDEX_main_table_border_color ();
string return_INDEX_main_table_border_stlye ();
string return_INDEX_main_table_border_width ();
string return_INDEX_main_table_background_color ();

string return_CATEGORY_main_table_border_color ();
string return_CATEGORY_main_table_border_style ();
string return_CATEGORY_main_table_border_width ();
string return_CATEGORY_main_table_background_color ();
string return_CATEGORY_iframe_border_width ();

string return_PRODUCTS_main_table_border_color ();
string return_PRODUCTS_main_table_border_style ();
string return_PRODUCTS_main_table_border_width ();
string return_PRODUCTS_main_table_background_color ();
string return_PRODUCTS_iframe_border_width ();

string return_ELEMENT_main_table_border_color ();
string return_ELEMENT_main_table_border_style ();
string return_ELEMENT_main_table_border_width ();
string return_ELEMENT_main_table_background_color ();

string return_ELEMENT_properties_table_background_color ();

string return_ELEMENT_properties_title_font_family ();
string return_ELEMENT_properties_title_font_color ();
string return_ELEMENT_properties_title_font_size ();
string return_ELEMENT_properties_title_font_weight ();
string return_ELEMENT_properties_title_text_align ();

string return_ELEMENT_properties_font_family ();
string return_ELEMENT_properties_font_color ();
string return_ELEMENT_properties_font_size ();
string return_ELEMENT_properties_font_weight ();
string return_ELEMENT_properties_text_align ();

string return_ELEMENT_properties_element_font_family ();
string return_ELEMENT_properties_element_font_color ();
string return_ELEMENT_properties_element_font_size ();
string return_ELEMENT_properties_element_font_weight ();
string return_ELEMENT_properties_element_text_align ();
string return_ELEMENT_properties_element_list_bullet ();

string return_CONTACT_font_family();
string return_CONTACT_font_size();
string return_CONTACT_font_weight();
string return_CONTACT_text_align();
string return_CONTACT_text_vertical_align();

#endif /* SETTINGS_HPP_ */
