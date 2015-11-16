// Copyright (C) 2015 Ã�goston SasvÃ¡ri
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "css_html_formatting.hpp"

using namespace std;

namespace {

const char T = '"';

}

void style_open (ofstream& o) {

	o << "style = " << T << " " << flush;
}

void style_close (ofstream& o) {

	o << " " << T << flush;
}

void style_background_color (ofstream& o, const string COLOR) {

	o << "background-color:rgb(" << COLOR << ");"<< flush;
}

void style_background_image (ofstream& o, const string IMAGE) {

	o << "background-image: url(" << IMAGE << ");" << flush;
}

void style_background_position (ofstream& o, const string POS) {

	o << "background-position: " << POS << ";" << flush;
}

void style_background_size (ofstream& o, const string POS) {

	o << "background-size: " << POS << ";" << flush;
}

void style_background_repeat (ofstream& o, const string REP) {

	o << "background-repeat: " << REP << ";" << flush;
}

void style_border_color (ofstream& o, const string COLOR) {

	o << "border-color: rgb(" << COLOR << ");" << flush;
}

void style_border_style (ofstream& o, const string STYLE) {

	o << "border-style: " << STYLE << ";" << flush;
}

void style_border_width (ofstream& o, const string WIDTH) {

	o << "border-width: " << WIDTH << ";" << flush;
}

void style_height (ofstream& o, const string HEIGHT) {

	o << "height: " << HEIGHT << ";" << flush;
}

void style_width (ofstream& o, const string WIDTH) {

	o << "width: " << WIDTH << ";" << flush;
}

void style_font_family (ofstream& o, const string FONT) {

	o << "font-family: " << FONT << ";" << flush;
}

void style_font_size (ofstream& o, const string SIZE) {

	o << "font-size: " << SIZE << ";" << flush;
}

void style_font_style (ofstream& o, const string STYLE) {

	o << "font-style: " << STYLE << ";" << flush;
}

void style_font_weight (ofstream& o, const string WEIGHT) {

	o << "font-weight: " << WEIGHT << ";" << flush;
}

void style_list_style_type (ofstream& o, const string STYLE) {

	o << "list-style-type: " << STYLE << ";" << flush;
}

void style_margin_left (ofstream& o, const string MARGIN) {

	o << "margin-left: " << MARGIN << ";" << flush;
}

void style_margin_right (ofstream& o, const string MARGIN) {

	o << "margin-right: " << MARGIN << ";" << flush;
}


void style_line_height (ofstream& o, const string HEIGHT) {

	o << "line-height: " << HEIGHT << ";" << flush;
}

void style_text_color (ofstream& o, const string COLOR) {

	o << "color:rgb(" << COLOR << ");" << flush;
}

void style_text_align (ofstream& o, const string ALIGN) {

	o << "text-align: " << ALIGN << ";" << flush;
}

void style_vertical_align (ofstream& o, const string ALIGN) {

	o << "vertical-align: " << ALIGN << ";" << flush;
}


void style_text_transform (ofstream& o, const string TRANSFORM) {

	o << "text-transform: " << TRANSFORM << ";" << flush;
}

void style_opacity (ofstream& o, const string OP) {

	o << "opacity: " << OP << ";" << flush;
}

void tag_end (ofstream& o) {

	o << " >" << endl;
}

void html_open (ofstream& o) {

	o << "<html> " << endl;
}

void html_close (ofstream& o) {

	o << "</html>" << endl;
}

void head_open (ofstream& o) {

	o << "<head> " << endl;
}

void head_close (ofstream& o) {

	o << "</head>" << endl;
}

//void title (ofstream& o, const string TITLE, const vector <ITEM>& IT, const size_t this_item) {
void title (ofstream& o, const string TITLE, const string NAME) {

	//const string TTL = TITLE + " - " + IT.at (this_item).ITEM_NAME.at(0);
	string TTL = TITLE;

	if (NAME.size() > 0) TTL = TTL + " - " + NAME;

	o << "  <title> " << TTL << " </title>" << endl;
}

void body_open (ofstream& o) {

	o << "<body " << endl;
}

void body_close (ofstream& o) {

	o << "</body>" << endl;
}

void charset (ofstream& o, const string CHARSET) {

	o << "charset = " << T << CHARSET << T << " " << endl;
}

void table_open (ofstream& o, const string ALIGN) {

	o << "<table " << flush;
	o << "cellpadding = " << T << "0" << T << " " << endl;
	o << "cellspacing = " << T << "1" << T << " " << endl;
	o << "align = " 		<< T << ALIGN << T << " " << flush;
}

void table_close (ofstream& o) {

	o << "</table>" << endl;
}

void row_open (ofstream& o) {

	o << "<tr " << flush;
}

void row_close (ofstream& o) {

	o << "</tr>" << endl;
}

void cell_open (ofstream& o) {

	o << "<td " << flush;
}

void cell_close (ofstream& o) {

	o << "</td>" << endl;
}

void image_open (ofstream& o, const string SRC) {

	o << "<img src = " 			<< T << SRC << T << " " << flush;
}

void text_open (ofstream& o) {

	o << "<p " << flush;
}

void text_close (ofstream& o) {

	o << "</p> " << endl;
}

void linebreak (ofstream& o) {

	o << "<br>" << endl;
}

void span_open (ofstream& o) {

	o << "<span " << flush;
}

void span_close (ofstream& o) {

	o << "</span> " << endl;
}

void link_start (ofstream& o) {

	o << "<a " << flush;
}

void link_target (ofstream& o,  const string TARGET) {

	o << "target = " << T << TARGET << T << " " << flush;
}

void link_href (ofstream& o, const string HREF) {

	o << "href = " << T << HREF << T << " >" << flush;
}

void link_title (ofstream& o, const string TITLE) {

	o << TITLE << flush;
}

void link_end (ofstream& o) {

	o << "</a> " << flush;
}

void iframe_open (ofstream& o, const string SRC, const string HEIGHT, const string WIDTH) {

	o << "<iframe src= " << T << SRC << T << flush;
	o << " height = " << HEIGHT << flush;
	o << " width = " << WIDTH << " "<< flush;
}

void iframe_close (ofstream& o) {

	o << "</iframe>" << flush;
}

void meta_open (ofstream& o, const string M) {

	o << "<meta name=" << T <<"Keywords" << T <<" content= "<< T << M << T << endl;
}
