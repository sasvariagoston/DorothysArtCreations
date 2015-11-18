// Copyright (C) 2015 Ágoston Sasvári
// All rights reserved.
// This code is published under the GNU Lesser General Public License.

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "DAC.hpp"
#include "data_io.hpp"
#include "html.hpp"
#include "settings.hpp"
#include "utils.hpp"

using namespace std;

namespace {

const char T = '"';

}

vector <size_t> set_categories_vector (const size_t P1, const size_t P2, const size_t P3, const size_t P4) {

	vector <size_t> GEOMETRY;

	if (P1 > 0) GEOMETRY.push_back (P1);
	if (P2 > 0) GEOMETRY.push_back (P2);
	if (P3 > 0) GEOMETRY.push_back (P3);
	if (P4 > 0) GEOMETRY.push_back (P4);

	return GEOMETRY;
}

vector <size_t> set_cells_geometry_3_element (const size_t N) {

	vector <size_t> OUT;

	for (size_t i = 3; i < N; i+=3) OUT.push_back (3);

	OUT.push_back (3);

	return OUT;
}

vector <size_t> set_cells_geometry (const size_t N) {

	if (N == 1) 		return set_categories_vector (1, 0, 0, 0);
	else if (N == 2) 	return set_categories_vector (2, 0, 0, 0);
	else if (N == 3) 	return set_categories_vector (2, 1, 0, 0);
	else if (N == 4) 	return set_categories_vector (2, 2, 0, 0);
	else if (N == 5) 	return set_categories_vector (3, 2, 0, 0);
	else if (N == 6) 	return set_categories_vector (3, 3, 0, 0);
	else if (N == 7) 	return set_categories_vector (3, 2, 2, 0);
	else if (N == 8) 	return set_categories_vector (3, 3, 2, 0);
	else if (N == 9) 	return set_categories_vector (3, 3, 3, 0);
	else if (N == 10) 	return set_categories_vector (2, 2, 3, 3);
	else if (N == 11) 	return set_categories_vector (2, 3, 3, 3);
	else if (N == 12) 	return set_categories_vector (3, 3, 3, 3);
	else if (N == 13) 	return set_categories_vector (3, 3, 3, 4);
	else if (N == 14) 	return set_categories_vector (3, 3, 4, 4);
	else if (N == 15) 	return set_categories_vector (3, 4, 4, 4);
	else   				return set_categories_vector (4, 4, 4, 4);
}

vector <LINKS> generate_header_links () {

	vector <LINKS> OUT;

	const size_t i = return_ITEMS().size();

	LINKS buf;

	buf.TITLE = "START PAGE";
	buf.TARGET = "_self";
	buf.HREF = "index.html";
	OUT.push_back (buf);

	buf.TITLE = "ABOUT ME";
	buf.TARGET = "_self";
	buf.HREF = "about.html";
	OUT.push_back (buf);

	buf.TITLE = "MY EVENTS";
	buf.TARGET = "_self";
	buf.HREF = "my_events.html";
	OUT.push_back (buf);

	stringstream ss;
	ss << "PRODUCTS (" << i << ")" << flush;
	buf.TITLE = ss.str();
	buf.TARGET = "_self";
	buf.HREF = "products.html";
	OUT.push_back (buf);

	buf.TITLE = "FEEDBACK";
	buf.TARGET = "_self";
	buf.HREF = "feedback.html";
	OUT.push_back (buf);

	buf.TITLE = "CONTACT";
	buf.TARGET = "_self";
	buf.HREF = "contact.html";
	OUT.push_back (buf);

	return OUT;
}

void tracking_code (ofstream& o) {

	o << endl;
	o << "<script>" << endl;
	o << "(function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){ " << endl;
	o << "	(i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o), " << endl;
	o << "	m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m) " << endl;
	o << "})(window,document,'script','//www.google-analytics.com/analytics.js','ga'); " << endl;
	o << "ga('create', 'UA-60833615-1', 'auto'); " << endl;
	o << "ga('send', 'pageview'); " << endl;
	o << "</script> " << endl;
	o << endl;
}

string generate_tag (const ITEM& IT) {

	string OUT = IT.ITEM_NAME.at(0);

	for (size_t i = 0; i < OUT.size(); i++) {

		if (OUT.at(i) == ' ') OUT.at(i) = ',';
	}
	for (size_t i = 0; i < IT.MAIN_CATEGORY.size(); i++) {

		OUT = OUT + ", " + IT.MAIN_CATEGORY.at(i);
	}
	for (size_t i = 0; i < IT.SUB_CATEGORY.size(); i++) {

		OUT = OUT + ", " + IT.SUB_CATEGORY.at(i);
	}
	for (size_t i = 0; i < IT.PROPERTIES.size(); i++) {

		OUT = OUT + ", " + IT.PROPERTIES.at(i);
	}
	return OUT;
}



void generate_html_head (ofstream& o, const string MODE, const vector <ITEM>& IT, const size_t this_item) {

	const bool E =  MODE == "ELEMENT";

	const string T = return_HTML_HEAD_TITLE();

	html_open (o);
	head_open (o);

	//title (o, T);
	if (this_item < 999) title (o, T, IT.at(this_item).ITEM_NAME.at(0));
	//if (this_item < 999) tags (o, IT, this_item);

	string PATH = "";
	if (E) PATH = "../";

	const string ICONNAME = PATH + "icon.ico";

	icon (o, ICONNAME);

	tracking_code (o);
	head_close (o);
}

void format_header_jpg (ofstream& o) {

	style_open (o);
	style_border_color (o, return_HEADER_jpg_border_color());
	style_border_style (o, return_HEADER_border_style());
	style_border_width (o, return_HEADER_border_width());
	style_background_color (o, return_HEADER_jpg_border_color());
	style_height (o, "4%");
	style_width (o, "100%");
	style_text_align(o, "right");
	style_close (o);
	tag_end (o);
}

void format_header_table (ofstream& o) {

	style_open (o);
	style_border_color (o, return_HEADER_border_color());
	style_border_style (o, return_HEADER_border_style());
	style_border_width (o, return_HEADER_border_width());
	style_background_color (o, return_HEADER_background_color());
	style_height (o, "4%");
	style_width (o, "100%");
	style_close (o);
	tag_end (o);
}

void format_header_link_style (ofstream& o, const double REL_LINK_W) {

	const double W = 0.7 * REL_LINK_W;

	stringstream ss;
	ss << W << flush;
	const string WIDTH = ss.str() + "%";

	style_open (o);
	style_width (o, WIDTH);
	style_font_family 	(o, return_HEADER_link_font_family());
	style_font_size 	(o, return_HEADER_link_font_size());
	style_font_weight 	(o, return_HEADER_link_font_weight());
	style_text_align 	(o, return_HEADER_link_text_align());
	style_vertical_align(o, return_HEADER_link_text_vertical_align());
	style_close (o);
	tag_end (o);
}

size_t return_header_links_chars (const vector <LINKS>& HEADER) {

	size_t OUT = 0;

	for (size_t i = 0; i < HEADER.size(); i++) OUT = OUT + HEADER.at(i).TITLE.size();

	return OUT;
}

void generate_header_and_links (ofstream& o, const string FN, const string MODE, const vector <LINKS>& HEADER) {

	const bool E = MODE == "ELEMENT";

	string PATH = "";
	if (E) PATH = "../";

	table_open (o, "center");
	format_header_jpg (o);
	cell_open (o);
	tag_end(o);

	image_open(o, PATH + "bg2.jpg");

	style_height (o, "100%");
	style_width (o, "100%");
	tag_end(o);

	cell_close(o);
	table_close(o);


	table_open (o, "center");
	format_header_table (o);

	//const size_t HEADER_LINK_CHARS = return_header_links_chars (HEADER);

	for (size_t i = 0; i < HEADER.size(); i++) {

		//double REL_LINK_W = (100 * HEADER.at(i).TITLE.size()) / HEADER_LINK_CHARS;

		const bool ACT = uppercase (FN+".html") == uppercase (HEADER.at(i).HREF);

		cell_open (o);
		format_header_link_style (o, 16.5);

		if (ACT) {

			text_open (o);
			style_open (o);
			style_text_color (o, return_HEADER_active_link_color());
			style_close (o);
			tag_end (o);

			o << " " << HEADER.at(i).TITLE << " " << flush;
			text_close(o);
		}
		else {

			link_start (o);
			style_open (o);
			style_text_color (o, return_HEADER_passive_link_color());
			style_close (o);

			link_target (o, HEADER.at(i).TARGET);
			link_href (o, PATH + HEADER.at(i).HREF);
			link_title (o, HEADER.at(i).TITLE);
			link_end (o);
		}
		cell_close(o);
	}
	table_close(o);
}

vector <LINKS> convert_items_to_links (const vector <ITEM>& IT, const string MODE) {

	vector <LINKS> OUT;

	if (IT.size() == 0) {

		cout << "!   Something wrong - you try to convert an empty spreadsheet." << endl;
		return OUT;
	}

	const string IF = return_ITEMS_FOLDER ();
	const string HF = return_ELEMENT_HTML_FOLDER ();
	const string TH = return_THUMBNAIL_FOLDER();

	stringstream ss;
	ss << '/' << flush;
	const string B = ss.str();

	const bool E =  MODE == "ELEMENT";
	const bool I =  MODE == "INDEX";


	size_t LIST_END = IT.size();
	if (E) LIST_END = IT.at(0).IMAGE.size();

	for (size_t i = 0; i < LIST_END; i++) {

		LINKS buf;

		if 		(I) buf.TITLE = uppercase (IT.at(i).ITEM_NAME.at(0));
		else if (E) buf.TITLE = IT.at(0).ITEM_NAME.at(0);
		else 		buf.TITLE = IT.at(i).ITEM_NAME.at(0);

		if 		(I) buf.HREF = lowercase (IT.at(i).FOLDER_NAME.at(0)) + ".html";
		else if (E) buf.HREF = "../" + IF + B + IT.at(0).FOLDER_NAME.at(0) + B + IT.at(0).IMAGE.at(i);
		else 		buf.HREF = HF + B + lowercase (IT.at(i).FOLDER_NAME.at(0)) + ".html";

		if (E) 		buf.TARGET = "_blank";
		else 		buf.TARGET = "_parent";

		if 		(I) buf.IMAGE = lowercase (IT.at(i).IMAGE.at(0)) + ".jpg";
		else if (E) buf.IMAGE = "../" + IF + B + IT.at(0).FOLDER_NAME.at(0) + B + IT.at(0).IMAGE.at(i);
		else 		buf.IMAGE = TH + B + IT.at(i).FOLDER_NAME.at(0) + ".jpg";

		//else 		buf.IMAGE = IF + B + IT.at(i).FOLDER_NAME.at(0) + B + IT.at(i).IMAGE.at(0);


		//if 		(I) buf.IMAGE = lowercase (IT.at(i).IMAGE.at(0)) + ".jpg";
		//else if (E) buf.IMAGE = "../" + IF + B + IT.at(0).FOLDER_NAME.at(0) + B + IT.at(0).IMAGE.at(i);
		//else 		buf.IMAGE = IF + B + IT.at(i).FOLDER_NAME.at(0) + B + IT.at(i).IMAGE.at(0);

		OUT.push_back (buf);
	}
	return OUT;
}

vector <LINKS> convert_categories_to_links () {

	vector <LINKS> OUT;

	vector <CATEGOTY> CAT = return_MAIN_CATEGORIES();

	for (size_t i = 0; i < CAT.size(); i++) {

		LINKS buf;

		stringstream ss;
		ss << CAT.at(i).ELEMENT.size() << flush;

		const string N = CAT.at(i).CATEGORY_NAME;

		buf.TITLE = N + " (" + ss.str() + ")";
		buf.HREF = lowercase (N) + ".html";
		buf.TARGET = "_self";
		buf.IMAGE = lowercase (N) + ".jpg";

		OUT.push_back(buf);
	}
	return OUT;
}

vector <LINKS> generate_elements_to_dump (const string MODE, const vector <ITEM>& IT, const size_t this_item) {

	vector <ITEM> FROM_THIS;

	const bool E =  MODE == "ELEMENT";
	const bool IC = MODE == "INDEX_CONTENT";
	const bool CC = MODE == "CATEGORY_CONTENT";
	const bool PC = MODE == "PRODUCTS_CONTENT";

	if (IC || PC || CC) FROM_THIS = IT;

	if (E) FROM_THIS.push_back (IT.at(this_item));

	//stable_sort (M.begin(), M.end(), by_rev_TITLE);

	if (PC || IC || CC) stable_sort (FROM_THIS.begin(), FROM_THIS.end(), by_rev_AGE);

	return convert_items_to_links (FROM_THIS, MODE );
}

size_t return_ROWS_number (const string MODE, const vector <LINKS>& M, const vector <size_t>& CG) {

	const bool IC = MODE == "INDEX_CONTENT";

	if (IC)	return M.size();

	return CG.size();
}

string return_cell_height (const string MODE, const size_t ROWS) {

	const bool E =  MODE == "ELEMENT";
	const bool I =  MODE == "INDEX";

	if (I || E) return double_to_string (100.0 / ROWS, 0) + "%";

	return "300px";
}

string return_categories_element_table_width (const string MODE) {

	const bool E =  MODE == "ELEMENT";
	const bool I =  MODE == "INDEX";
	const bool CC = MODE == "CATEGORY_CONTENT";
	const bool PC = MODE == "PRODUCTS_CONTENT";

	if (I || E) return "100%";

	if (PC || CC) return "900px";

	return "300px";
}

void categories_element_table_style (ofstream& o, const string MODE, const string CH) {

	const string TW = return_categories_element_table_width (MODE);

	style_open (o);
	style_height(o, CH);
	style_width(o, TW);
	style_close (o);
	tag_end (o);
}

size_t return_COLUMNS_number (const string MODE, const vector <size_t> GC, const size_t ROWS) {

	const bool E =  MODE == "ELEMENT";
	const bool I =  MODE == "INDEX";
	const bool CC = MODE == "CATEGORY_CONTENT";
	const bool PC = MODE == "PRODUCTS_CONTENT";

	if (PC || I || E) return GC.at (ROWS);

	if (CC) return 3;

	return 1;
}

string return_cell_width (const string MODE, const vector <size_t> CG, const size_t ROW) {

	const bool E =  MODE == "ELEMENT";
	const bool I =  MODE == "INDEX";

	if (I || E) {

		const size_t CELLS_NUMBER = CG.at (ROW);
		return double_to_string (100 / CELLS_NUMBER, 0) + "%" ;
	}
	return "300px";
}

void background_image_for_element_in_categories_table (ofstream& o, const string MODE, const LINKS& M) {

	const bool E = MODE == "ELEMENT";

	if (E) 	style_background_image( o, M.HREF);
	else  style_background_image(o, M.IMAGE);
}

void style_for_element_in_categories_table (ofstream& o, const string CW) {

	style_open (o);
	style_width (o, CW);
	style_background_position (o, "center center");
	style_background_repeat(o, "no-repeat");
	style_background_size (o, "cover");
	style_font_family (o, "Verdana");
	style_font_size (o, "11");
	style_font_weight (o, "bold");
	style_text_align (o, "center");
}

void link_of_item (ofstream& o, const string MODE, const vector <LINKS>& M, const size_t which_link, const string CW, const string CH) {

	const bool I =  MODE == "INDEX";
	const bool E =  MODE == "ELEMENT";

	link_start (o);

	if (I || E) {

		style_open (o);
		style_text_color (o, return_WHITE());
		style_opacity(o, "0.6");
		style_font_size (o, "22");
		style_close (o);

		link_target (o, M.at(which_link).TARGET);
		link_href (o, M.at(which_link).HREF);

		if (I) link_title (o, M.at(which_link).TITLE);
		else link_title (o, "VIEW");
	}
	else {

		link_target (o, M.at(which_link).TARGET);
		link_href (o, M.at(which_link).HREF);

		image_open (o, M.at(which_link).IMAGE);
		style_open (o);
		style_width (o, CW);
		style_height(o, CH);
		style_opacity(o, "0");
		style_close (o);
	}
	link_end (o);
}

void generate_categories_element_table (ofstream& o, const string MODE, const string FN, const vector <LINKS>& TO_DUMP) {

	const bool E =  MODE == "ELEMENT";
	const bool I =  MODE == "INDEX";
	const bool CC = MODE == "CATEGORY_CONTENT";
	const bool PC = MODE == "PRODUCTS_CONTENT";

	vector <LINKS> M = TO_DUMP;
	if (I) stable_sort (M.begin(), M.end(), by_rev_TITLE);

	vector <size_t> CG;
	if (I  ||  E) CG = set_cells_geometry (TO_DUMP.size());
	if (PC || CC) CG = set_cells_geometry_3_element (TO_DUMP.size());

	const size_t ROWS = return_ROWS_number (MODE, M, CG);

	size_t COUNTER = 0;

	for (size_t i = 0; i < ROWS; i++) {

		table_open (o, "center");
		const string CH = return_cell_height (MODE, ROWS);

		categories_element_table_style (o, MODE, CH);
		row_open(o);
		tag_end(o);

		const size_t COLUMNS = return_COLUMNS_number (MODE, CG, i);

		for (size_t j = 0; j < COLUMNS; j++) {

			const bool EMPTY = COUNTER > M.size() - 1;

			cell_open (o);

			const string CW = return_cell_width (MODE, CG, i);

			style_for_element_in_categories_table (o, CW);

			if (! EMPTY) background_image_for_element_in_categories_table (o, MODE, M.at(COUNTER));

			style_close (o);
			tag_end (o);

			if (! EMPTY) link_of_item (o, MODE, M, COUNTER, CW, CH);

			cell_close(o);

			COUNTER++;
		}
		row_close(o);
		table_close (o);
	}
}

void list_properties_style (ofstream& o) {

	style_open (o);
	style_margin_left (o, "20px");
	style_line_height (o, return_ROW_HEIGHT());
	style_font_family (o, return_ELEMENT_properties_font_family ());
	style_text_color (o, return_ELEMENT_properties_font_color ());
	style_font_size (o, return_ELEMENT_properties_font_size ());
	style_font_weight (o, return_ELEMENT_properties_font_weight ());
	style_text_align (o, return_ELEMENT_properties_text_align ());
	style_close (o);
	tag_end(o);
}


void list_elements_vector (ofstream& o, const string PROPERTY, const vector <string>& CONTENT) {

	text_open (o);
	list_properties_style (o);
	o << PROPERTY << endl;
	text_close (o);

	for (size_t i = 0; i < CONTENT.size(); i++) {

		const string FONT = return_ELEMENT_properties_element_font_family ();
		const string SIZE = return_ELEMENT_properties_element_font_size ();
		const string ALIGN = return_ELEMENT_properties_element_text_align ();
		const string LINEHEIGHT = return_ROW_HEIGHT();

		write (o, "- " + CONTENT.at(i), FONT, SIZE, ALIGN, LINEHEIGHT);
	}
	//linebreak(o);
}

void element_properties_style (ofstream& o) {

	style_open (o);
	style_line_height (o, return_ROW_HEIGHT());
	style_font_family (o, return_ELEMENT_properties_title_font_family ());
	style_text_color (o, return_ELEMENT_properties_title_font_color());
	style_font_size (o, return_ELEMENT_properties_title_font_size ());
	style_font_weight (o, return_ELEMENT_properties_title_font_weight ());
	style_text_align (o, return_ELEMENT_properties_title_text_align ());
	style_close (o);
	tag_end(o);
}

void list_elements_bool (ofstream& o, const string ELEMENT, const bool STATUS) {

	text_open (o);
	list_properties_style (o);
	o << ELEMENT << endl;
	text_close (o);

	const string FONT = return_ELEMENT_properties_element_font_family ();
	const string SIZE = return_ELEMENT_properties_element_font_size ();
	const string ALIGN = return_ELEMENT_properties_element_text_align ();
	const string LINEHEIGHT = return_ROW_HEIGHT();

	string S = "No";
	if (STATUS) S = "Yes";

	write (o, "- " + S, FONT, SIZE, ALIGN, LINEHEIGHT);

	//linebreak(o);
}

void list_element_properties (ofstream& o, const ITEM& IT) {

	text_open (o);
	element_properties_style (o);
	linebreak(o);
	o << IT.ITEM_NAME.at(0) << endl;
	text_close (o);

	if (IT.PROPERTIES.size() > 0) {

		linebreak(o);
		list_elements_vector (o, "PROPERTIES", IT.PROPERTIES);
	}
	linebreak(o);
	list_elements_bool (o, "AVAILABLE", IT.AVAILABLE);

	linebreak(o);
	list_elements_bool (o, "ORDER", IT.ORDER);

	if (IT.PRICE.size() > 0) {

		linebreak(o);
		list_elements_vector (o, "PRICE", IT.PRICE);
	}

	if (IT.SHIPPING.size() > 0) {

		linebreak(o);
		list_elements_vector (o, "SHIPPING", IT.SHIPPING);
	}
}

string main_table_border_color (const string MODE) {

	if 		(MODE == "INDEX") 		return return_INDEX_main_table_border_color ();
	else if (MODE == "CATEGORY") 	return return_CATEGORY_main_table_border_color ();
	else if (MODE == "PRODUCTS") 	return return_PRODUCTS_main_table_border_color ();
	else if (MODE == "ELEMENT") 	return return_ELEMENT_main_table_border_color ();
	else {
		cout << "!   Mode '" << MODE << "' is incorrect while generating table border color." << endl;
		return return_BLACK();
	}
}

string main_table_border_style (const string MODE) {

	if 		(MODE == "INDEX") 		return return_INDEX_main_table_border_stlye ();
	else if (MODE == "CATEGORY") 	return return_CATEGORY_main_table_border_style ();
	else if (MODE == "PRODUCTS") 	return return_PRODUCTS_main_table_border_style ();
	else if (MODE == "ELEMENT") 	return return_ELEMENT_main_table_border_style ();
	else {
		cout << "!   Mode '" << MODE << "' is incorrect while generating table border style." << endl;
		return "solid";
	}
}

string main_table_border_width (const string MODE) {

	if 		(MODE == "INDEX") 		return return_INDEX_main_table_border_width ();
	else if (MODE == "CATEGORY") 	return return_CATEGORY_main_table_border_width ();
	else if (MODE == "PRODUCTS") 	return return_PRODUCTS_main_table_border_width ();
	else if (MODE == "ELEMENT") 	return return_ELEMENT_main_table_border_width ();
	else {
		cout << "!   Mode '" << MODE << "' is incorrect while generating table border width." << endl;
		return "0px";
	}
}

string main_table_background_color (const string MODE) {

	if 		(MODE == "INDEX") 		return return_INDEX_main_table_background_color ();
	else if (MODE == "CATEGORY") 	return return_CATEGORY_main_table_background_color ();
	else if (MODE == "PRODUCTS") 	return return_PRODUCTS_main_table_background_color ();
	else if (MODE == "ELEMENT") 	return return_ELEMENT_main_table_background_color ();
	else {
		cout << "!   Mode '" << MODE << "' is incorrect while generating table background color." << endl;
		return return_WHITE();
	}
}

void main_table_style (ofstream& o, const string MODE) {

	style_open (o);
	style_border_color (o, main_table_border_color (MODE));
	style_border_style (o, main_table_border_style (MODE));
	style_border_width (o, main_table_border_width (MODE));
	style_background_color (o, main_table_background_color (MODE));
	style_height (o, "91.5%");
	style_width (o, "100%");
	style_close (o);
	tag_end (o);
}

string generate_frame_border_width (const string MODE) {

	if (MODE == "CATEGORY") 		return return_CATEGORY_iframe_border_width ();
	else if (MODE == "PRODUCTS") 	return return_PRODUCTS_iframe_border_width ();
	else {
		cout << "!   Mode '" << MODE << "' is incorrect while generating iframe border width." << endl;
		return "0px";
	}
}

void generate_main_table_content_with_frame (ofstream& o, const string FN, const string MODE) {

	const bool C =  MODE == "CATEGORY";
	const bool P =  MODE == "PRODUCTS";
	const bool I = MODE == "INDEX";

	if (I) iframe_open (o, "index_content.html"          , "100%", "330px");
	if (P) iframe_open (o, "products_content.html"       , "100%", "100%");
	if (C) iframe_open (o, lowercase (FN+"_content.html"), "100%", "100%");

	style_open (o);
	style_border_width (o, "0px");
	style_close (o);
	tag_end(o);
	iframe_close(o);
}

void generate_main_table_content_no_frame (ofstream& o, const string MODE) {

	const bool E =  MODE == "ELEMENT";

	style_open (o);
	style_width (o, "320px");
	if (E) {

		style_background_color (o, return_ELEMENT_properties_table_background_color());
		style_vertical_align(o, "top");
	}
	style_close (o);
	tag_end (o);
}

//style_line_height (o, return_ROW_HEIGHT());

void contact_details (ofstream& o) {

	vector <string> C = read_text_file ("contact.txt");

	if (C.size() == 0) return;

	for (size_t i = 0; i < C.size(); i++) {

		write (o, C.at(i), "Verdana", "14", "center", "150%");
	}
}

void feedbacks (ofstream& o) {

	vector <string> F = read_text_file ("feedback.txt");

	if (F.size() == 0) return;

	write (o, "", "Verdana", "14", "left", "150%");

	for (size_t i = 0; i < F.size(); i++) {

		write (o, F.at(i), "Verdana", "14", "justify", "150%");
	}
}

void events (ofstream& o) {

	vector <string> E = read_text_file ("events.txt");

	if (E.size() == 0) return;

	write (o, "", "Verdana", "14", "left", "150%");

	for (size_t i = 0; i < E.size(); i++) {

		write (o, E.at(i), "Verdana", "14", "justify", "150%");
	}

	linebreak(o);
	image_open (o, "2015_11_wenue_cymru_1.jpg");
	tag_end(o);
	linebreak(o);
	linebreak(o);
	image_open (o, "2015_11_wenue_cymru_2.jpg");
	tag_end(o);
}

void about (ofstream& o) {

	vector <string> AB = read_text_file ("about.txt");

	if (AB.size() == 0) return;

	write (o, "", "Verdana", "14", "justify", "150%");

	for (size_t i = 0; i < AB.size(); i++) {

		write (o, AB.at(i), "Verdana", "14", "justify", "150%");
	}
}

void generate_page_main_table (ofstream& o, const string FN, const string MODE, const vector <ITEM>& IT, const size_t this_item) {

	const bool I =  MODE == "INDEX";
	const bool A =  MODE == "ABOUT";
	const bool C =  MODE == "CATEGORY";
	const bool P =  MODE == "PRODUCTS";
	const bool E =  MODE == "ELEMENT";
	const bool IC = MODE == "INDEX_CONTENT";
	const bool CC = MODE == "CATEGORY_CONTENT";
	const bool PC = MODE == "PRODUCTS_CONTENT";
	const bool CT = MODE == "CONTACT";
	const bool EV = MODE == "MY_EVENTS";
	const bool FB = MODE == "FEEDBACK";

	if (A ||I || C || P || E || CT || EV || FB) {

		table_open (o, "center");
		main_table_style (o, MODE);

		if (A || CT || EV || FB) {

			cell_open (o);
			tag_end(o);
			cell_close(o);
		}

		cell_open (o);
		style_open(o);
		if (CT) style_vertical_align(o, "middle");
		if (FB || EV) style_vertical_align(o, "top");

		if (A || CT || EV || FB) style_width(o, "700px");

		//style_line_height (o, return_ROW_HEIGHT());

		style_close(o);
		tag_end (o);

		if (A) about (o);

		if (CT) contact_details (o);
		if (FB) feedbacks (o);
		if (EV) events (o);
	}

	if (I || IC || CC || PC || E) {

		vector <LINKS> L;

		if (I) L = convert_categories_to_links ();
		else L = generate_elements_to_dump (MODE, IT, this_item);

		generate_categories_element_table (o, MODE, FN, L);
	}

	if (A ||I || C || P || E || CT || EV || FB) {

		if (P || C) generate_main_table_content_with_frame (o, FN, MODE);

		cell_close(o);

		if (A || CT || EV || FB) {

			cell_open (o);
			tag_end(o);
			cell_close(o);
		}

		if (I  || E) {

			cell_open (o);
			generate_main_table_content_no_frame (o, MODE);

			if (E) list_element_properties (o, IT.at(this_item));

			if (I) generate_main_table_content_with_frame (o, FN, MODE);
			cell_close(o);
		}
		table_close(o);
	}
}

string return_html_background_color (const string MODE) {

	string BGCLR;

	const bool IC = MODE == "INDEX_CONTENT";
	const bool CC = MODE == "CATEGORY_CONTENT";
	const bool PC = MODE == "PRODUCTS_CONTENT";

	if (IC || PC || CC) BGCLR = return_WHITE ();
	else BGCLR = return_PINK1();

	return BGCLR;
}

string return_html_path (const string FN, const string MODE) {

	const bool E = MODE == "ELEMENT";
	const bool CC = MODE == "CATEGORY_CONTENT";

	const string HF = return_ELEMENT_HTML_FOLDER();

	string  FILENAME;

	if (CC)		FILENAME = lowercase (FN) + "_content";
	else if (E)	FILENAME = HF + '/' + lowercase (FN);
	else  		FILENAME = lowercase (FN);

	FILENAME = FILENAME + ".html";

	return FILENAME;
}

void generate_html (const string FN, const string MODE, const vector <LINKS>& HEADER, const vector <ITEM>& IT, const size_t this_item) {

	const bool IC = MODE == "INDEX_CONTENT";
	const bool CC = MODE == "CATEGORY_CONTENT";
	const bool PC = MODE == "PRODUCTS_CONTENT";

	const string FILENAME = return_html_path (FN, MODE);

	cout << "    Generating '" << FILENAME << "' file."<< endl;

	ofstream o;
	o.open (FILENAME.c_str());

	generate_html_head (o, MODE, IT, this_item);
	body_open (o);

	style_open (o);
	style_background_color (o, return_html_background_color (MODE));

	style_text_align (o, "center");
	style_close (o);
	tag_end (o);

	if (!IC && !CC && !PC) generate_header_and_links (o, FN, MODE, HEADER);

	generate_page_main_table (o, FN, MODE, IT, this_item);

	body_close (o);
	html_close (o);
}

void generate_pages () {

	vector <ITEM> dummy;
	vector <LINKS> HEADER = generate_header_links();

	const size_t NO_NUMBER_NEEDED = 999;

	generate_html ("INDEX", "INDEX", HEADER, dummy, NO_NUMBER_NEEDED);
	generate_html ("ABOUT", "ABOUT", HEADER, dummy, NO_NUMBER_NEEDED);
	generate_html ("CONTACT", "CONTACT", HEADER, dummy, NO_NUMBER_NEEDED);
	generate_html ("PRODUCTS", "PRODUCTS", HEADER, dummy, NO_NUMBER_NEEDED);
	generate_html ("MY_EVENTS", "MY_EVENTS", HEADER, dummy, NO_NUMBER_NEEDED);
	generate_html ("FEEDBACK", "FEEDBACK", HEADER, dummy, NO_NUMBER_NEEDED);

	const vector <ITEM> IT = return_ITEMS();

	generate_html ("INDEX_CONTENT", "INDEX_CONTENT", HEADER, IT, NO_NUMBER_NEEDED);
	generate_html ("PRODUCTS_CONTENT", "PRODUCTS_CONTENT", HEADER, IT, NO_NUMBER_NEEDED);

	const vector <CATEGOTY> CAT = return_MAIN_CATEGORIES();

	for (size_t i = 0; i < CAT.size(); i++) {

		generate_html (CAT.at(i).CATEGORY_NAME, "CATEGORY", HEADER, CAT.at(i).ELEMENT, NO_NUMBER_NEEDED);
		generate_html (CAT.at(i).CATEGORY_NAME, "CATEGORY_CONTENT", HEADER, CAT.at(i).ELEMENT, NO_NUMBER_NEEDED);
	}

	for (size_t i = 0; i < IT.size(); i++) {

		generate_html (IT.at(i).FOLDER_NAME.at(0), "ELEMENT", HEADER, IT, i);
	}
}
