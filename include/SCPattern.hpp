#ifndef STITCH_CROSS_PATTERN
#define STITCH_CROSS_PATTERN

#include "main.hpp"
#include <iostream>
#include <fstream>

#define PERFECT_FRAME_RATE 60

namespace SCP_space {
	class SCPattern {
        private:
            int h, v;
            int **m_colors;
            int **m_filled;
		public:
			SCPattern(int,int);
			~SCPattern();
			void Init(std::ifstream &);
			sf::Vector2i Get_Size ();
			void Print ();
			void End();
		};
	}
#endif