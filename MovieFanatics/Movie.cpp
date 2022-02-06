#include "Movie.h"

//Constructor
Movie::Movie(std::string nameVal, int ratingVal, int timesWatchedVal)
	: name{nameVal}, rating{ratingVal}, timesWatched{timesWatchedVal}
{
}

//Destructor
Movie::~Movie()
{
}

//Methods
std::string Movie::getMovieName() const{
	return name;
}
int Movie::getMovieRating() const{
	return rating;
}
int Movie::getMovieTimesWatched() const{
	return timesWatched;
}
void Movie::incrementTimesWatched(){
	++timesWatched;
}

