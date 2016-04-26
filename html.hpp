// Copyright (C) 2015 Ágoston Sasvári
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

#ifndef HTML_HPP_
#define HTML_HPP_

//#include <fstream>
#include <iostream>

#include "css_html_formatting.hpp"

//string analyze_text (const string S, const string MODE);

vector <size_t> set_categories_vector (const size_t P1, const size_t P2, const size_t P3, const size_t P4);
vector <size_t> set_cells_geometry_3_element (const size_t N) ;
vector <size_t> set_cells_geometry (const size_t N);

vector <LINKS> generate_header_links ();

void tracking_code (ofstream& o);

string generate_tag (const ITEM& IT);

//void tags (ofstream&o, const vector <ITEM>& IT, const size_t this_item);
//void icon (ofstream& o, const string MODE);

void generate_html_head (ofstream& o, const string MODE, const vector <ITEM>& IT, const size_t this_item) ;

void format_header_jpg (ofstream& o);
void format_header_table (ofstream& o);
void format_header_link_style (ofstream& o, const double REL_LINK_W) ;

size_t return_header_links_chars (const vector <LINKS>& HEADER);
void generate_header_and_links (ofstream& o, const string FN, const string MODE, const vector <LINKS>& HEADER);

vector <LINKS> convert_items_to_links (const vector <ITEM>& IT, const string MODE);
vector <LINKS> convert_categories_to_links ();

vector <LINKS> generate_elements_to_dump (const string MODE, const vector <ITEM>& IT, const size_t this_item) ;

size_t return_ROWS_number (const string MODE, const vector <LINKS>& M, const vector <size_t>& CG);

string return_cell_height (const string MODE, const size_t ROWS);

string return_categories_element_table_width (const string MODE);

void categories_element_table_style (ofstream& o, const string MODE, const string CH);

size_t return_COLUMNS_number (const string MODE, const vector <size_t> GC, const size_t ROWS);

string return_cell_width (const string MODE, const vector <size_t> CG, const size_t ROW);

void background_image_for_element_in_categories_table (ofstream& o, const string MODE, const LINKS& M) ;

void style_for_element_in_categories_table (ofstream& o, const string CW);

void link_of_item (ofstream& o, const string MODE, const vector <LINKS>& M, const size_t which_link, const string CW, const string CH);

void generate_categories_element_table (ofstream& o, const string MODE, const string FN, const vector <LINKS>& TO_DUMP);

void list_properties_style (ofstream& o);
void list_cost_style (ofstream& o);
//void list_string (ofstream& o, const string S, const string FONT, const string SIZE, const string ALIGN, const string LH);
void list_price (ofstream& o, const string PROPERTY, const vector <string>& CONTENT);
void list_elements_vector (ofstream& o, const string PROPERTY, const vector <string>& CONTENT);

void element_properties_style (ofstream& o) ;

void list_elements_bool (ofstream& o, const string ELEMENT, const bool STATUS);
void list_element_properties (ofstream& o, const ITEM& IT) ;
string main_table_border_color (const string MODE) ;
string main_table_border_style (const string MODE);
string main_table_border_width (const string MODE);
string main_table_background_color (const string MODE) ;
void main_table_style (ofstream& o, const string MODE) ;

string generate_frame_border_width (const string MODE);

void generate_main_table_content_with_frame (ofstream& o, const string FN, const string MODE);
void generate_main_table_content_no_frame (ofstream& o, const string MODE);

//void dump_string (ofstream& o, const string TEXT, const string FONT, const string SIZE, const string ALIGN, const string LH);
//void write (ofstream& o, const string S, const string FONT, const string SIZE, const string ALIGN, const string LH);

void contact_details (ofstream& o) ;
void feedbacks (ofstream& o);
void about (ofstream& o);

void generate_page_main_table (ofstream& o, const string FN, const string MODE, const vector <ITEM>& IT, const size_t this_item);

string return_html_background_color (const string MODE) ;

string return_html_path (const string FN, const string MODE) ;
void generate_html (const string FN, const string MODE, const vector <LINKS>& HEADER, const vector <ITEM>& IT, const size_t this_item) ;

void generate_pages ();
#endif
