// Copyright (C) 2015 Ágoston Sasvári
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

#ifndef CSS_HTML_FORMATTING_HPP_
#define CSS_HTML_FORMATTING_HPP_

#include <iostream>

using namespace std;

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
void style_margin_right (ofstream& o, const string MARGIN);

void style_line_height (ofstream& o, const string HEIGHT);
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

void title (ofstream& o, const string TITLE, const string NAME);

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

#endif /* CSS_HTML_FORMATTING_HPP_ */
