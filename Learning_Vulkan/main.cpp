

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "first_app.h"

int main() {

	lve::FirstApp app{};


	try {
		app.Run();
	}
	catch (const std::exception &e){
		std::cerr << e.what() << "\n";
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}