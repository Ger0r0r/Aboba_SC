#include "include/main.hpp"
#include "include/TApplication.hpp"
#include <iostream>
#include "include/SCPattern.hpp"
#include <fstream>

int main(int argc, char *argv[]) {

	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " *test_file*\n"; 
		return 0;
	}
	
	int h,v;
	std::ifstream file (argv[1]);
	file >> v >> h;

	SCP_space::SCPattern Chart(h,v);
	Chart.Init(file); 
	SFML_W::TApplication Application;

	Application.Init();
	Application.Run(Chart);
	Application.End();

	return 0;
}