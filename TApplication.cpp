#include "include/TApplication.hpp"
#include <iostream>

namespace SFML_W{

	sf::Vector2i screen(1000,1000);
	const float zoom_factor = 1.05;
	float zoom = 1.f;

	TApplication::TApplication():
		Window(nullptr) {
	}
		
	TApplication::~TApplication() {
		
	}
		
	void TApplication::Init() {
		Window = new sf::RenderWindow(sf::VideoMode(screen.x, screen.y), "AbObA");
		Window->clear(sf::Color::White);
	}
		
	void TApplication::Run(SCP_space::SCPattern &Chart) {

		int h,v;
		
		sf::Vector2i scheme_size = Chart.Get_Size();
		h = scheme_size.x;
		v = scheme_size.y;

		sf::View view(sf::Vector2f(0.f,0.f),sf::Vector2f(screen.x, screen.y));

		Chart.Print();
		sf::VertexArray Lines_hb(sf::Lines, (int)(v%10) ? (2*(v/10+2)) : (2*(v/10+1)));
		sf::VertexArray Lines_hg(sf::Lines, (int)(v%10) ? (2*(v/10*9+v%10-1)) : (2*(v/10*9)));
		sf::VertexArray Lines_vb(sf::Lines, (int)(h%10) ? (2*(h/10+2)) : (2*(h/10+1)));
		sf::VertexArray Lines_vg(sf::Lines, (int)(h%10) ? (2*(h/10*9+h%10-1)) : (2*(h/10*9)));

		Chart.Print();
		std::cout << ((int)(v%10) ? (2*(v/10+2)) : (2*(v/10+1))) << std::endl;
		std::cout << ((int)(v%10) ? (2*(v/10*9+v%10-1)) : (2*(v/10*9))) << std::endl;
		std::cout << ((int)(h%10) ? (2*(h/10+2)) : (2*(h/10+1))) << std::endl;
		std::cout << ((int)(h%10) ? (2*(h/10*9+h%10-1)) : (2*(h/10*9))) << std::endl;

		Chart.Print();
		CALC_FUNC::CLC_set_lines(v, h, Lines_hb, Lines_hg, Lines_vb, Lines_vg);

		Chart.Print();
		sf::Clock clock;
		Window->setFramerateLimit(PERFECT_FRAME_RATE);
		while (Window->isOpen()) {

			float current_time = clock.restart().asSeconds();
			float current_fps = 1/current_time;

			std::cout << zoom << "\t\t" << current_fps << std::endl;

			sf::Event event;
			while (Window->pollEvent(event)) {
				switch (event.type){
				case sf::Event::Closed:
					Window->close();
					break;
				
				case sf::Event::MouseWheelScrolled:
					if (event.mouseWheelScroll.delta >= 1) {
						zoom *= zoom_factor;
						view.zoom(1.f * zoom_factor);
					}
					if (event.mouseWheelScroll.delta <= -1) {
						zoom /= zoom_factor;
						view.zoom(1.f / zoom_factor);
					}
					break;
				default:
					break;
				}
			}
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) view.move(sf::Vector2f(0,-10));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) view.move(sf::Vector2f(10,0));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) view.move(sf::Vector2f(-10,0));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) view.move(sf::Vector2f(0,10));

			Window->setView(view);
			Window->clear(sf::Color::White);
			Window->draw(Lines_hg);
			Window->draw(Lines_vg);
			Window->draw(Lines_hb);
			Window->draw(Lines_vb);
			Window->display();
		}

		Chart.Print();
		return;
	}

	void TApplication::End() {
		if (Window != nullptr)
			delete Window;
	}


}