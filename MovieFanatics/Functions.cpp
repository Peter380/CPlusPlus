#include "Functions.h"
#include <string>
#include <iostream>

char transformToUpperCase(char userInput){
	if (islower(userInput) != 0)
		userInput = toupper(userInput);
	return userInput;
}
char displayMenu(){
	
		char selection{};
		std::cout << "===========================================================\n" << std::endl;
		
		// Menu
		std::cout << "A - Add a movie to the movie collection" << std::endl;
		std::cout << "D - Display all movies in the movie collection" << std::endl;
		std::cout << "I - Increment the watched count for a movie" << std::endl;
		std::cout << "E - Erase a movie" << std::endl;
		std::cout << "Q - Quit" << std::endl;
		
		std::cout << "\nPlease type in the letter of one of the following options: ";
		std::cin >> selection;
		selection = transformToUpperCase(selection);
		return selection;
}
void addMovie(Movies &myMovieList){
	std::string name{};
	int rating{};
	int timesWatched{};
	
	std::cout << "\nWhich movie do you want to add? : ";
	std::cin.ignore(100,'\n'); //get rid of any \n so that getline does work
	std::getline(std::cin, name);
	
	//Rating input
	bool validInput{false};
	do{
		std::cout << "\nHow do you rate the movie? (From 0 to 10) ";
		std::cin >> rating;
		rating = catchCinError(rating);
		
		if(rating >= 0 && rating <=10)
			validInput = true;
		else
			std::cout << "\nNumber is not between 0 and 10. Please try again";
	
	} while(validInput == false);
	
	//Times Watched input
	validInput = false;
	do{
		std::cout << "\nHow do many times have you watched to movie? ";
		std::cin >> timesWatched;
		timesWatched = catchCinError(timesWatched);
		
		if(timesWatched >= 0)
			validInput = true;
		else
			std::cout << "\nNumber is below zero. Please try again";
	
	} while(validInput == false);
	
	myMovieList.addMovie(name, rating, timesWatched);
}
int catchCinError(int userInput){
	
	// Check if a letter is entered
	bool addNumberDone{false};
	do {
		if (!std::cin.fail()){
			addNumberDone = true;
		}else {
			std::cin.clear();
			std::cin.sync();
			std::cout << "\nNot a number - please try again: ";
			std::cin >> userInput;
		}
	} while (addNumberDone == false);
	
	return userInput;
}
void displayMovies(Movies &myMovieList){
	myMovieList.displayMovies();
}
void incrementWatchedCount(Movies &myMovieList){
	std::cout << "Which movie have you watched? ";
	
	std::string name{};
	
	std::cin.ignore(100,'\n');
	std::getline(std::cin, name);
	
	myMovieList.movieWatched(name);
}
void eraseMovie(Movies &myMovieList){
	std::cout << "Which movie do you want do erase? ";
	
	std::string name{};
	
	std::cin.ignore(100, '\n');
	std::getline(std::cin, name);
	
	myMovieList.eraseMovie(name);
}