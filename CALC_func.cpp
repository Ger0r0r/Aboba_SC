#include "include/CALC_func.hpp"

#define GREY_CONSTANT 200

namespace CALC_FUNC {
	
	void CLC_set_lines(int v, int h, sf::VertexArray &arr_h_black, sf::VertexArray &arr_h_grey, sf::VertexArray &arr_v_black, sf::VertexArray &arr_v_grey) {
        int index = 0;

        for (int i = 0; i <= v; i++){
            // horizontal lines
            if ((i == 0) || i % 10 == 0) {
                // black lines
                index = 2*i/10;

                arr_h_black[index].color = sf::Color(0,0,0);
                arr_h_black[index+1].color = sf::Color(0,0,0);
                arr_h_black[index].position = sf::Vector2f(TAB_SPACE,TAB_SPACE+10*i);
                arr_h_black[index+1].position = sf::Vector2f(TAB_SPACE+10*h,TAB_SPACE+10*i);
            } else {
                // grey lines
                index = (i-1-i/10)*2;

                arr_h_grey[index].color = sf::Color(GREY_CONSTANT,GREY_CONSTANT,GREY_CONSTANT);
                arr_h_grey[index+1].color = sf::Color(GREY_CONSTANT,GREY_CONSTANT,GREY_CONSTANT);
                arr_h_grey[index].position = sf::Vector2f(TAB_SPACE,TAB_SPACE+10*i);
                arr_h_grey[index+1].position = sf::Vector2f(TAB_SPACE+10*h,TAB_SPACE+10*i);
            }
        }

        for (int i = 0; i <= h; i++){
            // vertical lines
            if ((i == 0) || i % 10 == 0) {
                // black lines
                index = 2*i/10;

                arr_v_black[index].color = sf::Color(0,0,0);
                arr_v_black[index+1].color = sf::Color(0,0,0);
                arr_v_black[index].position = sf::Vector2f(TAB_SPACE+10*i,TAB_SPACE);
                arr_v_black[index+1].position = sf::Vector2f(TAB_SPACE+10*i,TAB_SPACE+10*v);
            } else {
                // grey lines
                index = (i-1-i/10)*2;

                arr_v_grey[index].color = sf::Color(GREY_CONSTANT,GREY_CONSTANT,GREY_CONSTANT);
                arr_v_grey[index+1].color = sf::Color(GREY_CONSTANT,GREY_CONSTANT,GREY_CONSTANT);
                arr_v_grey[index].position = sf::Vector2f(TAB_SPACE+10*i,TAB_SPACE);
                arr_v_grey[index+1].position = sf::Vector2f(TAB_SPACE+10*i,TAB_SPACE+10*v);
            }
        }
    }
};