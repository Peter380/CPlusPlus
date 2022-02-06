#ifndef MOVIES_H_
#define MOVIES_H_

#include <vector>
#include "Movie.h"

class Movies
{
private:
	std::vector<Movie> movies;
	bool isMovieInCollection(std::string nameToFind);
	
public:
	//Constructor
	Movies();
	
	//Destructor
	~Movies();
	
	//Methods
	void addMovie(std::string nameVal = "None", int rating = 0, int timesWatched = 0);
	void movieWatched(std::string nameMovie);
	void displayMovies() const;
	void eraseMovie(std::string nameMovie);

};

#endif // MOVIES_H_
