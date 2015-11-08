// Copyright (C) 2015 Ágoston Sasvári
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

#ifndef HTML_HPP_
#define HTML_HPP_

//#include <fstream>
#include <iostream>

void set_categories (const size_t N);

vector <size_t> set_categories_vector (const size_t P1, const size_t P2, const size_t P3, const size_t P4);
vector <size_t> set_cells_geometry (const size_t N);

/*

void generate_main_links ();
void set_categories_vector (const size_t P1, const size_t P2, const size_t P3, const size_t P4);

void set_items_to_dump_for_categories ();
void set_element_images_to_dump (const ITEM ELEMENT);
void set_items_to_dump (const string MODE);
void set_products_vector ();


bool generate_cells_in_categories_row ();
*/

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
void title (ofstream& o, const string TITLE);

void body_open (ofstream& o);
void body_close (ofstream& o);

void meta_open (ofstream& o);

void charset (ofstream& o, const string CHARSET);

void table_open (ofstream& o, const string ALIGN);
void table_close (ofstream& o);
void row_open (ofstream& o);
void row_close (ofstream& o);
void cell_open (ofstream& o);
void cell_close (ofstream& o);

void image_open (ofstream& o, const string SRC);
void opacity  (ofstream& o, const string OP);

void font (ofstream& o, const string COLOR, const string FACE, const string SIZE);
void text (ofstream& o, const string TEXT, const bool BOLD, const bool ITALIC);
void list_open (ofstream& o);
void list_close (ofstream& o);
void linebreak (ofstream& o);

void span_open (ofstream& o);
void span_close (ofstream& o);
void link_start (ofstream& o);
void link_target (ofstream& o, const string TARGET);
void link_href (ofstream& o, const string HREF);
void link_title (ofstream& o, const string TITLE);
void link_end (ofstream& o);
void text_open (ofstream& o);
void text_close (ofstream& o);
void iframe_open (ofstream& o, const string SRC, const string HEIGHT, const string WIDTH);
void iframe_close (ofstream& o);

void meta_open (ofstream& o, const string M);

bool by_TITLE (const LINKS& x, const LINKS& y);
bool by_rev_TITLE  (const LINKS& x, const LINKS& y);

bool by_AGE (const ITEM& x, const ITEM& y);
bool by_rev_AGE (const ITEM& x, const ITEM& y);

void list_properties_style (ofstream& o);
void list_properties_element_style (ofstream& o);
void list_elements_vector (ofstream& o, const string PROPERTY, const vector <string>& CONTENT);
void element_properties_style (ofstream& o);
void list_elements_bool (ofstream& o, const string ELEMENT, const bool STATUS);
void list_element_properties (ofstream& o, const ITEM& IT);

string main_table_border_color (const string MODE);
string main_table_border_style (const string MODE);
string main_table_border_width (const string MODE);
string main_table_background_color (const string MODE);
void main_table_style (ofstream& o, const string MODE);

string generate_frame_border_width (const string MODE);
void generate_main_table_content_with_frame (ofstream& o, const string FN, const string MODE);
void generate_main_table_content_no_frame (ofstream& o, const string MODE);

void generate_page_main_table (ofstream& o, const string FN, const string MODE, const vector <ITEM>& IT, const size_t this_item);
string return_html_background_color (const string MODE);
string return_html_path (const string FN, const string MODE);
void generate_html (const string FN, const string MODE, const vector <LINKS>& HEADER, const vector <ITEM>& IT, const size_t this_item) ;
void generate_pages ();

#endif
