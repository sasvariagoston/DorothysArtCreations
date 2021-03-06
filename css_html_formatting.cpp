// Copyright (C) 2015 Ã�goston SasvÃ¡ri
// All rights reserved.
// This code is published under the GNU Lesser General Public License.


#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

#include "css_html_formatting.hpp"
#include "utils.hpp"

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

void style_background_attachment (ofstream& o, const string ATT) {

	o << "background-attachment: " << ATT << ";" << flush;
}

void style_background_repeat (ofstream& o, const string REP) {

	o << "background-repeat: " << REP << ";" << flush;
}

void style_border_collapse (ofstream& o, const string COLLAPSE) {

	o << "border-collapse: " << COLLAPSE << ";" << flush;
}

void style_border_color (ofstream& o, const string COLOR) {

	o << "border-color: rgb(" << COLOR << ");" << flush;
}

void style_border_bottom_color (ofstream& o, const string COLOR) {

	o << "border-bottom-color: rgb(" << COLOR << ");" << flush;
}

void style_border_style (ofstream& o, const string STYLE) {

	o << "border-style: " << STYLE << ";" << flush;
}

void style_border_bottom_style (ofstream& o, const string STYLE) {

	o << "border-bottom-style: " << STYLE << ";" << flush;
}

void style_border_width (ofstream& o, const string WIDTH) {

	o << "border-width: " << WIDTH << ";" << flush;
}

void style_border_bottom_width (ofstream& o, const string WIDTH) {

	o << "border-bottom-width: " << WIDTH << ";" << flush;
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

void style_margin_top (ofstream& o, const string MARGIN) {

	o << "margin-top: " << MARGIN << ";" << flush;
}

void style_margin_bottom (ofstream& o, const string MARGIN) {

	o << "margin-bottom: " << MARGIN << ";" << flush;
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

void style_text_decoration (ofstream& o, const string DEC) {

	o << "text-decoration: " << DEC << ";" << flush;
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

void title (ofstream& o, const string TITLE, const string NAME) {

	string TTL = TITLE;

	if (NAME.size() > 0) TTL = TTL + " - " + NAME;

	o << "  <title> " << TTL << " </title>" << endl;
}

void icon (ofstream& o, const string ICONNAME) {

	o << "<link rel = " << T << " shortcut icon " << T << flush;
	o << " type = " << T << " image/x-icon " << T << flush;
	o << " href = " << T << ICONNAME << T << ">" << flush;
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

void table_open (ofstream& o, const string CELLPADDING, const string CELLSPACING, const string ALIGN) {

	o << "<table " << flush;
	o << "cellpadding = " << T << CELLPADDING << T << " " << endl;
	o << "cellspacing = " << T << CELLSPACING << T << " " << endl;
	o << "align = " << T << ALIGN << T << " " << flush;
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

	o << "<img src = " << T << SRC << T << " " << flush;
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

void list_paypal (ofstream& o, const vector <string>& CONTENT) {

	o << "<div style=" << T << "width:160px;margin:0 auto;" << T << ">" << endl;

	o << "<form action=" << T << "https://www.paypal.com/cgi-bin/webscr" << T << " method=" << T << "post" << T << " target=" << T << "_top" << T << ">" << endl;

	o << "<input type=" << T << "hidden" << T << " name=" << T << "cmd" << T << " value=" << T << "_s-xclick" << T << ">"<< endl;

	o << "<input type=" << T << "hidden" << T << " name=" << T << "hosted_button_id" << T << " value=" << T << CONTENT.at(0) << T << ">"<< endl;

	o << "<input type=" << T << "image" << T << " src=" << T << "https://www.paypalobjects.com/en_US/GB/i/btn/btn_buynowCC_LG.gif" << T << " border=" << T << "0" << T << " name=" << T << "submit" << T << " alt=" << T << "PayPal - The safer, easier way to pay online." << T << ">"<< endl;

	o << "<img alt=" << T  << T << " border=" << T << "0" << T << " src=" << T << "https://www.paypalobjects.com/en_GB/i/scr/pixel.gif" << T << " width=" << T << "1" << T << " height=" << T << "1" << T << ">"<< endl;

	o << "</form>"<< endl;

	o << "</div>"<< endl;
}

string analyze_text (const string S, const string MODE, const string COLOR) {

	/*

	  ~ TEXT ~         -> italic
	 * TEXT *         -> bold
	 # TEXT #         -> insert image
	 { LINK {} TEXT } -> TEXT, pointing to LINK

	 */

	const bool HR1 = MODE == "HREF1";
	const bool HR2 = MODE == "HREF2";
	const bool BLD = MODE == "BOLD";
	const bool ITL = MODE == "ITALIC";
	const bool IMG = MODE == "IMAGE";

	if (!BLD && !ITL && !IMG && !HR1 && !HR2) return S;

	char SEP;
	if (BLD) SEP = '*';
	if (ITL) SEP = '~';
	if (IMG) SEP = '#';
	if (HR1) SEP = '{';
	if (HR2) SEP = '}';

	stringstream oss;
	if (BLD) oss << "<b>" << flush;
	if (ITL) oss << "<i>" << flush;
	if (IMG) oss << "<img src = " << T << flush;
	//if (HR1) oss << "<a style = " << T << " color:rgb("<< COLOR << "); text-decoration: underline; " << T << "target = " << T << "_blank" << T << " href = " << T << flush;
	if (HR2) oss << "" << flush;

	/*

	<a onclick="pageTracker._trackPageview ('

	/download/setup_sg2ps.exe

	');" title="sg2ps setup - self extracting archive" href="

	download/setup_sg2ps.exe

	"><font color="#000000">

	Windows installer

	</a>


	 */

	string OPEN = oss.str();

	stringstream css;
	if (BLD) css << "</b>" << flush;
	if (ITL) css << "</i>" << flush;
	if (IMG) css << T << ">" << flush;
	if (HR1) css << T << ">" << flush;
	if (HR2) css << "</a>" << flush;
	const string CLOSE = css.str();

	string OUT;

	vector <string> row;

	istringstream iss (S);

	string buf;

	while (getline (iss, buf, SEP)) row.push_back (buf);

	for (size_t i = 0; i < row.size(); i++) {

		string CLICK = "";

		const bool FORMAT = (i < row.size() && !EVEN (i));

		bool INS_CLICK = false;

		if (row.at(i).size() > 0) {

			if (row.at(i).at(0) == '!') INS_CLICK = true;
		}

		if (HR1) {

			stringstream hr1ss;
			hr1ss << "<a style = " << T << " color:rgb("<< COLOR << "); text-decoration: underline; " << T << "target = " << T << "_blank" << T << flush;

			if (INS_CLICK) {

				row.at(i).erase (0, 1);

				hr1ss
				<< " onclick=" << T << "pageTracker._trackPageview ('"
				<< row.at(i)
				<< "');" << T << flush;
			}
			hr1ss << " href = " << T << flush;

			OPEN = hr1ss.str();
		}

		if (FORMAT) OUT = OUT + OPEN + CLICK + row.at(i) + CLOSE;
		else OUT = OUT + row.at(i);
	}
	return OUT;
}

void dump_string (ofstream& o, const string TEXT, const string FONT, const string SIZE, const string ALIGN, const string LH, const string COLOR) {

	text_open (o);
	style_open (o);
	style_margin_left (o, "10px");
	style_margin_right (o, "10px");
	style_font_family (o, FONT);
	style_font_size (o, SIZE);
	style_text_align (o, ALIGN);
	style_text_color(o, COLOR);
	style_line_height (o, LH);
	style_close (o);
	tag_end(o);
	o << TEXT << endl;
	text_close (o);
}

void list_string (ofstream& o, const string S, const string FONT, const string SIZE, const string ALIGN, const string LH) {

	const string HEAD = return_LIST_HEAD ();

	text_open (o);

	style_open (o);
	style_margin_left (o, "20px");
	style_margin_right (o, "10px");
	style_line_height (o, LH);
	style_text_color (o, return_ELEMENT_properties_element_font_color ());
	style_text_align (o, ALIGN);
	style_close (o);
	tag_end(o);
	o << HEAD << " " << endl;
	span_open(o);

	style_open (o);
	style_line_height (o, LH);
	style_text_color (o, return_ELEMENT_properties_font_color ());
	style_font_family (o, FONT);
	style_font_size (o, SIZE);
	style_close (o);
	tag_end(o);
	o << S << " " << endl;
	span_close(o);
	text_close(o);
}

void write (ofstream& o, const string S, const string FONT, const string SIZE, const string ALIGN, const string LH, const string COLOR) {

	if (S.size() == 0) {

		linebreak (o);
		return;
	}

	string TEXT = S;

	string FT = FONT;
	if (FONT == "") FT = "inherit";

	string SZ = SIZE;
	if (SIZE == "") SZ = "inherit";

	string AL = ALIGN;
	if (ALIGN == "") AL = "inherit";

	const bool PROCESS_AS_LIST = (S.size() > 2 && S.at(0) == '-' && S.at(1) == ' ');

	if (PROCESS_AS_LIST) TEXT.erase(0, 2);

	TEXT = analyze_text (TEXT, "IMAGE", COLOR);
	TEXT = analyze_text (TEXT, "BOLD", COLOR);
	TEXT = analyze_text (TEXT, "ITALIC", COLOR);
	TEXT = analyze_text (TEXT, "HREF1", COLOR);
	TEXT = analyze_text (TEXT, "HREF2", COLOR);

	if (PROCESS_AS_LIST) list_string (o, TEXT, FONT, SIZE, ALIGN, LH);
	else dump_string (o, TEXT, FONT, SIZE, ALIGN, LH, COLOR);
}
