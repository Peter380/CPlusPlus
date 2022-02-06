#include "Movies.h"
#include "Functions.h"
#include <iostream>

int main(){
	
	Movies myMovieList;
	
	std::cout << "Welcome to Movie Fanatics!" << std::endl;
	
	char selection{};
	do {
		
		selection = displayMenu();
		
		switch (selection){
			
			// Add movie
			case 'A': {
				addMovie(myMovieList);
			} break;
			
			// Display movies
			case 'D': {
				displayMovies(myMovieList);
			} break;
			
			// Increment watched count
			case 'I': {
				incrementWatchedCount(myMovieList);
			} break;
			
			// Erase movie
			case 'E': {
				eraseMovie(myMovieList);
			} break;
			
			
			// Quit
			case 'Q': std::cout << "\nGoodbye" << std::endl; break;
			
			default: std::cout << "\nUnknown selection, please try again." << std::endl;
		}
	} while (selection != 'Q');
	system("pause");
	return 0;
}