#ifndef APPLICATION_TYPE_HEADER
#define APPLICATION_TYPE_HEADER

#include "main.hpp"
#include "SCPattern.hpp"
#include "CALC_func.hpp"

namespace SFML_W {
	class TApplication {
		protected:
			sf::RenderWindow *Window;
		public:
			TApplication();
			~TApplication();
			void Init();
			void Run(SCP_space::SCPattern&);
			void End();
	};	
};
#endif