#pragma once
#ifndef SVG_H_INCLUDED
#define SVG_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <math.h>


using namespace std;

void
svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_line(double x, double y, double width,
    double height, string stroke) {
    //   std::cout<<"<line x1 = '"<<x<<"' y1 = '"<<y<<" x2 = '"<<width<<"' y2 ='"<<
          // height << "' style = "<<
           //""stroke:rgb(255, 0, 0); stroke - width:2" / >\n";
    cout << "<line x1 = '" << x << "' y1 = '" << y
        << "' x2 = '" << width << "' y2 = '" << height << "' stroke = '" <<
        stroke << "' />";
}
       

void
svg_end() {
    cout << "</svg>\n";
}
void svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>";
}

void svg_rect(double x, double y, double width,
    double height, string stroke, string fill) {
    cout << "<rect x='" << x << "' y='" << y
        << "' width='" << width << "' height='" << height << "' stroke='" <<
        stroke << "' fill='" << fill << "' />";
}

void
show_histogram_svg(const vector<size_t>& bins) {
    size_t max_val;
    max_val = bins[0];
    for (const auto& x : bins) {
        if (x > max_val) {
            max_val = x;
        }
    }
    string fill;
    const auto offsetx = 10;
    const auto offsety = 10;
    const auto IMAGE_WIDTH = 400;
    const auto IMAGE_HEIGHT = 290;
    const auto TEXT_X_POS = 20;
    const auto TEXT_Y_POS = 20;
    const auto BLOCK_UPPER_CORNER_X_POS = 50;
    const auto BLOCK_UPPER_CORNER_Y_POS = 0;
    const auto BLOCK_HEIGHT = 20;
    const auto BLOCK_WIDTH = IMAGE_WIDTH - offsetx - BLOCK_UPPER_CORNER_X_POS - 2 - TEXT_X_POS;
    svg_begin(400, 300);
    svg_line(offsetx, offsety, offsetx, bins.size() * BLOCK_HEIGHT + offsety, "black");
    svg_line(IMAGE_WIDTH - offsetx, offsety, 
        IMAGE_WIDTH - offsetx, bins.size() * BLOCK_HEIGHT + offsety, "black");
    svg_line(offsetx, offsety, IMAGE_WIDTH - offsetx, 
        offsety, "black");
  //  svg_line(offsetx, IMAGE_HEIGHT - offsety, IMAGE_WIDTH - offsetx,
   //     IMAGE_HEIGHT - offsety, "black");
    svg_line(offsetx,  bins.size()*BLOCK_HEIGHT + offsety, IMAGE_WIDTH - offsetx,
        bins.size() * BLOCK_HEIGHT + offsety, "black");
    double initpos = offsety + TEXT_Y_POS - 5; double block_width;
    svg_line(BLOCK_UPPER_CORNER_X_POS + offsetx, offsety,
       BLOCK_UPPER_CORNER_X_POS + offsetx, 
        bins.size() * BLOCK_HEIGHT + offsety, "black");
    double initblockpos = BLOCK_UPPER_CORNER_Y_POS + offsety; size_t k = 0;
        for (size_t elem : bins) {
          
            block_width = ((double)BLOCK_WIDTH
               // - offsetx
     // - BLOCK_UPPER_CORNER_X_POS - 2
                ) * (static_cast<double>(elem) / max_val);
       
            svg_text(offsetx + TEXT_X_POS, initpos, to_string(elem));
    
            svg_rect(BLOCK_UPPER_CORNER_X_POS + offsetx, initblockpos,
                block_width, BLOCK_HEIGHT, "red", 
                std::move(
                      std::string("#") + 
                to_string(abs((int)(((double)rand() / RAND_MAX) * 8 + 1)))
                  + to_string(abs((int)(((double)rand() / RAND_MAX) * 8 + 1)))
                     + to_string(abs((int)(((double)rand() / RAND_MAX) * 8 + 1)))
                   + to_string(abs((int)(((double)rand() / RAND_MAX) * 8 + 1)))
                 + to_string(abs((int)(((double)rand() / RAND_MAX) * 8 + 1)))
               + to_string(abs((int)(((double)rand() / RAND_MAX) * 8 + 1)))
                )
                );
            initpos += BLOCK_HEIGHT; initblockpos += BLOCK_HEIGHT;
        }
    
    svg_end();
}


#endif
