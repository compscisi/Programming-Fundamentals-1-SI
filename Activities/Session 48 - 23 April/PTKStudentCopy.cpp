//The following program skeleton, when complete, asks the user to enter these data
//about his or her favorite movie :
//	Name of movie
//	Name of the movie’s director
//	Name of the movie’s producer
//	The year the movie was released
//Complete the program by declaring the structure that holds this data, defining a
//structure variable, and writing the individual statements necessary.

//NOTE: This is the one students worked out in session

#include <iostream>
#include <string>
using namespace std;
// Write the structure declaration here to hold the movie data.
struct MovieData
{
	string movieName;
	string movieDir;
	string moviePro;
	string movieRel;
};

int main()
{
	// define the structure variable here.
	MovieData movie;


	cout << "Enter the following data about your\n";
	cout << "favorite movie.\n";
	cout << "Name: ";
	cin >> movie.movieName;

	// Write a statement here that lets the user enter the
	// name of a favorite movie. Store the name in the
	// structure variable.
	cout << "Director: ";
	cin >> movie.movieDir;
	// Write a statement here that lets the user enter the
	// name of the movie's director. Store the name in the
	// structure variable.
	cout << "Producer: ";
	cin >> movie.moviePro;
	// Write a statement here that lets the user enter the
	// name of the movie's producer. Store the name in the
	// structure variable.
	cout << "Year of release: ";
	cin >> movie.movieRel;
	// Write a statement here that lets the user enter the
	// year the movie was released. Store the year in the
	// structure variable.
	cout << "Here is data on your favorite movie:\n";
	// Write statements here that display the data.
	cout << movie.movieName;
	cout << movie.movieDir;
	cout << movie.moviePro;
	cout << movie.movieRel;
	// just entered into the structure variable.
	return 0;
}
