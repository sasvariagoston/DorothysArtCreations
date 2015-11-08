// Copyright (C) 2015 Ágoston Sasvári
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

#ifndef HTML_HPP_
#define HTML_HPP_

//#include <fstream>
#include <iostream>

void style_open (ofstream& o);
void style_close (ofstream& o);

void style_background_color (ofstream& o, const string COLOR);
void style_background_image (ofstream& o, const string IMAGE);
void style_background_position (ofstream& o, const string POS);
void style_background_size (ofstream& o, const string POS);
void style_background_repeat (ofstream& o, const string REP);

void style_border_color (ofstream& o, const string COLOR);
void style_border_style (ofstream& o, const string STYLE);
void style_border_width (ofstream& o, const string WIDTH);

void style_height (ofstream& o, const string HEIGHT);
void style_width (ofstream& o, const string WIDTH);

void style_font_family (ofstream& o, const string FONT);
void style_font_size (ofstream& o, const string SIZE);
void style_font_style (ofstream& o, const string STYLE);
void style_font_weight (ofstream& o, const string WEIGHT);

void style_list_style_type (ofstream& o, const string STYLE);

void style_margin_left (ofstream& o, const string MARGIN);

void style_text_color (ofstream& o, const string COLOR);
void style_text_align (ofstream& o, const string ALIGN);

void style_vertical_align (ofstream& o, const string ALIGN);

void style_text_transform (ofstream& o, const string TRANSFORM);

void style_opacity (ofstream& o, const string OP);

void tag_end (ofstream& o);

void html_open (ofstream& o);
void html_close (ofstream& o);

void head_open (ofstream& o);
void head_close (ofstream& o);

void title (ofstream& o, const string TITLE, const vector <ITEM>& IT, const size_t this_item);

void body_open (ofstream& o);
void body_close (ofstream& o);

void charset (ofstream& o, const string CHARSET);

void table_open (ofstream& o, const string ALIGN);
void table_close (ofstream& o);
void row_open (ofstream& o);
void row_close (ofstream& o);
void cell_open (ofstream& o);
void cell_close (ofstream& o);

void image_open (ofstream& o, const string SRC);

string analyze_bold_text (const string S);
string analyze_italic_text (const string S);

void text_open (ofstream& o);
void text_close (ofstream& o);
void linebreak (ofstream& o);

void span_open (ofstream& o);
void span_close (ofstream& o);

void link_start (ofstream& o);
void link_target (ofstream& o,  const string TARGET);
void link_href (ofstream& o, const string HREF);
void link_title (ofstream& o, const string TITLE);
void link_end (ofstream& o);

void iframe_open (ofstream& o, const string SRC, const string HEIGHT, const string WIDTH);
void iframe_close (ofstream& o);
void meta_open (ofstream& o, const string M);

vector <size_t> set_categories_vector (const size_t P1, const size_t P2, const size_t P3, const size_t P4);
vector <size_t> set_cells_geometry_3_element (const size_t N) ;
vector <size_t> set_cells_geometry (const size_t N);

vector <LINKS> generate_header_links ();

void tracking_code (ofstream& o);

string generate_tag (const ITEM& IT);

void tags (ofstream&o, const vector <ITEM>& IT, const size_t this_item);
void icon (ofstream& o, const string MODE);

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
void list_string (ofstream& o, const string S, const string FONT, const string SIZE, const string ALIGN);
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

void write (ofstream& o, const string S, const string FONT, const string SIZE, const string ALIGN);

void contact_details (ofstream& o) ;
void feedbacks (ofstream& o);

void generate_page_main_table (ofstream& o, const string FN, const string MODE, const vector <ITEM>& IT, const size_t this_item);

string return_html_background_color (const string MODE) ;

string return_html_path (const string FN, const string MODE) ;
void generate_html (const string FN, const string MODE, const vector <LINKS>& HEADER, const vector <ITEM>& IT, const size_t this_item) ;

void generate_pages ();
#endif
