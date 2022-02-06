#include "Movies.h"
#include <string>
#include <iostream>

//Constructor
Movies::Movies()
{
}

//Destructor
Movies::~Movies()
{
}

//Private Methods
bool Movies::isMovieInCollection(std::string nameToFind){
	bool movieInCollection{false};
	
	for(const auto &curMovie : movies){
		if(curMovie.getMovieName() == nameToFind)
			movieInCollection = true;
	}
	return movieInCollection;
}

//Public Methods
void Movies::addMovie(std::string name, int rating, int timesWatched){
	if(isMovieInCollection(name) == true)
		std::cout << "\nThe movie \"" << name << "\" is already in the movie collection" << std::endl;
	else{
		Movie newMovie{name, rating, timesWatched};
		movies.push_back(newMovie);
		std::cout << "\nThe movie \"" << name << "\" has been added" << std::endl;
	}
}
void Movies::movieWatched(std::string nameMovie){
	if(isMovieInCollection(nameMovie) == false)
		std::cout << "\nThe movie \"" << nameMovie << "\" is not in the movie collection" << std::endl;
	else{
		int updatedTimesWatched{};
		for(size_t i{}; i < movies.size(); ++i){
			if(movies.at(i).getMovieName() == nameMovie){
				movies.at(i).incrementTimesWatched();
				updatedTimesWatched = movies.at(i).getMovieTimesWatched();
			}
		}
		std::cout << "\nThe watched count of \"" << nameMovie << "\" has been incremented by one. It is now " << updatedTimesWatched << std::endl;
	}
}
void Movies::displayMovies() const{
	if(movies.size() == 0)
		std::cout << "\nThe movie list is empty" << std::endl;
	else{
		std::cout << "\n======================" << std::endl;
		
		for(const auto &curMovie : movies){
			std::cout << "Movie name: " << curMovie.getMovieName() << std::endl;
			std::cout << "Movie rating: " << curMovie.getMovieRating() << std::endl;
			std::cout << "How many times watched: " << curMovie.getMovieTimesWatched() << std::endl;
			std::cout << "======================" << std::endl;
			
		}
	}
}
void Movies::eraseMovie(std::string nameMovie){
	if(isMovieInCollection(nameMovie) == false)
		std::cout << "\nThe movie \"" << nameMovie << "\" is not in the movie collection" << std::endl;
	else{
		for(size_t i{}; i < movies.size(); ++i){
			if(movies.at(i).getMovieName() == nameMovie){
				movies.erase(movies.begin() + i);
			}
		}
		std::cout << "\nThe movie \"" << nameMovie << "\" has been erased" << std::endl;
	}
}
