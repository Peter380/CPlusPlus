#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <string>
#include "Movies.h"

//Function prototypes
char transformToUpperCase(char);
char displayMenu();
void addMovie(Movies &myMovieList);
int catchCinError(int userInput);
void displayMovies(Movies &myMovieList);
void incrementWatchedCount(Movies &myMovieList);
void eraseMovie(Movies &myMovieList);

#endif // MOVIE_H_