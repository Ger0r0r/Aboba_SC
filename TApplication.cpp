#include "include/TApplication.hpp"
#include <iostream>

namespace SFML_W{
	TApplication::TApplication():
		Window(nullptr) {
	}
		
	TApplication::~TApplication() {
		
	}
		
	void TApplication::Init() {
		Window = new sf::RenderWindow(sf::VideoMode(1000, 1000), "AbObA");
		Window->clear(sf::Color::White);
	}
		
	void TApplication::Run(SCP_space::SCPattern Chart) {

		int h,v;
		Chart.Get_Size(h,v);
		sf::VertexArray Lines_hb(sf::Lines, (int)(v%10) ? (2*(v/10+2)) : (2*(v/10+1)));
		sf::VertexArray Lines_hg(sf::Lines, (int)(v%10) ? (2*(v/10*9+v%10-1)) : (2*(v/10*9)));
		sf::VertexArray Lines_vb(sf::Lines, (int)(h%10) ? (2*(h/10+2)) : (2*(h/10+1)));
		sf::VertexArray Lines_vg(sf::Lines, (int)(h%10) ? (2*(h/10*9+h%10-1)) : (2*(h/10*9)));

		CALC_FUNC::CLC_set_lines(v, h, Lines_hb, Lines_hg, Lines_vb, Lines_vg);

		sf::Clock clock;
		Window->setFramerateLimit(PERFECT_FRAME_RATE);
		while (Window->isOpen()) {

			float current_time = clock.restart().asSeconds();
			float current_fps = 1/current_time;

			std::cout << current_fps << std::endl;

			sf::Event event;
			while (Window->pollEvent(event)) {
				if (event.type == sf::Event::Closed)
                	Window->close();
			}
			
			Window->clear(sf::Color::White);
			Window->draw(Lines_hg);
			Window->draw(Lines_vg);
			Window->draw(Lines_hb);
			Window->draw(Lines_vb);
			Window->display();
		}

	}

	void TApplication::End() {
		if (Window != nullptr)
			delete Window;
	}


}