#include "include/SCPattern.hpp"

namespace SCP_space {
	SCPattern::SCPattern(int h, int v):
		h(h), v(v), m_colors(nullptr), m_filled(nullptr) {
			m_colors = new int *[h];
			m_filled = new int *[h];
			for (int i = 0; i < h; i++){
				m_colors[i] = new int[v];
				m_filled[i] = new int[v];
			}
		}

	SCPattern::~SCPattern(){
		for (int i = 0; i < h; i++){
			delete []m_colors[i];
			delete []m_filled[i];
		}
		delete []m_colors;
		delete []m_filled;
	}

	void SCPattern::Init(std::ifstream & file) {
		std::cout << h << " " << v << std::endl;
		for (int i = 0; i < h; i++){
			for (int j = 0; j < v; j++){
				file >> m_filled[i][j];
			}
		}
		std::string line;
		std::getline(file, line);
		std::getline(file, line);
		for (int i = 0; i < h; i++){
			for (int j = 0; j < v; j++){
				file >> m_colors[i][j];
			}
		}
	}

	sf::Vector2i SCPattern::Get_Size() {
		return sf::Vector2i(h,v);
	}
	
	void SCPattern::Print (){
		for (int i = 0; i < h; i++){
			for (int j = 0; j < v; j++){
				std::cout << m_filled[i][j] << " ";
			} std::cout << std::endl;
		}
		std::cout << "#" << std::endl;
		for (int i = 0; i < h; i++){
			for (int j = 0; j < v; j++){
				std::cout << m_colors[i][j] << " ";
			}std::cout << std::endl;
		}
	}
}