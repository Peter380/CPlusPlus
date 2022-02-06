#ifndef MOVIE_H_
#define MOVIE_H_

#include <string>

class Movie
{
private:
	std::string name;
	int rating;
	int timesWatched;

public:
	//Constructor
	Movie(std::string nameVal = "None", int ratingVal = 0, int timesWatchedVal = 0);
	
	//Destructor
	~Movie();
	
	//Methods
	std::string getMovieName() const;
	int getMovieRating() const;
	int getMovieTimesWatched() const;
	void incrementTimesWatched();
};

#endif // MOVIE_H_
