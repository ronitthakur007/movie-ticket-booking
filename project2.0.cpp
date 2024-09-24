#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include <iostream>
#include <iomanip>
#include<windows.h>
using namespace std;
const int Row=5;
const int Col=10;

class Movie {
public:
    string title;
    int duration; // duration in minutes
    string genre;

    Movie(string t, int d, string g) : title(t), duration(d), genre(g) {}
};

class Showtime {
public:
    Movie movie;
    string time;
    int availableSeats;

    Showtime(Movie m, string t, int seats) : movie(m), time(t), availableSeats(seats) {}
};

class BookingSystem {
private:
    vector<Movie> movies;
    vector<Showtime> showtimes;

public:
    void addMovie(Movie movie) {
        movies.push_back(movie);
    }

    void addShowtime(Showtime showtime) {
        showtimes.push_back(showtime);
    }

    void displayMovies() {
        cout << "Available Movies:\n";
        for (size_t i = 0; i < movies.size(); ++i) {
            cout << i + 1 << ". " << movies[i].title << " (" << movies[i].genre << ", " << movies[i].duration << " mins)" << endl;
        }
    }

    void displayShowtimes(int movieIndex) {
        cout << "Showtimes for " << movies[movieIndex].title << ":\n";
        for (size_t i = 0; i < showtimes.size(); ++i) {
            if (showtimes[i].movie.title == movies[movieIndex].title) {
                cout << i + 1 << ". " << showtimes[i].time << " - " << showtimes[i].availableSeats << " seats available" << endl;
            }
        }
    }

//    void bookTicket(int showtimeIndex, int seats) {
//        if (showtimeIndex < 0 || showtimeIndex >= showtimes.size()) {
//            cout << "Invalid showtime index." << endl;
//            return;
//        }
//
//        if (showtimes[showtimeIndex].availableSeats < seats) {
//            cout << "Not enough available seats." << endl;
//            return;
//        }
//
//        showtimes[showtimeIndex].availableSeats -= seats;
//        cout << "Successfully booked " << seats << " seats for " << showtimes[showtimeIndex].movie.title << " at " 
//             << showtimes[showtimeIndex].time << "." << endl;
//    }
display(bool seats[Row][Col]){
 	cout<<"  ";
 	for(int i=1; i<=Col; i++){
 	cout<<setw(3)<<i;
	 }
	 cout<<endl;
	for(int i=0; i<Row; i++){
	cout<<static_cast<char>('A'+i)<<" ";
	for(int j=0; j<Col;j++){
	if(seats[i][j]){
		cout<<setw(3)<<"X";
	}
	else{
		cout<<setw(3)<<"-";
	}
	}
	cout<<endl;
	}}
	
	void reservation(bool seats[Row][Col], char row, int col){
	if(seats[row-'A'][col-1]){
		cout<<"Seat is already reserved"<<endl;
	}
	else{
		seats[row-'A'][col-1]=true;
		cout<<"You have reserved seat successfuly"<<endl;
	}
}
    int getMovieCount() const {
        return movies.size();
    }

    int getShowtimeCount() const {
        return showtimes.size();
    }

    const Movie& getMovie(int index) const {
        return movies.at(index);
    }

    const Showtime& getShowtime(int index) const {
        return showtimes.at(index);
    }
};

int getValidatedInput(int min, int max) {
    int input;
    while (true) {
        cin >> input;
        if (cin.fail() || input < min || input > max) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        }
    }
}


int main() {
    BookingSystem bookingSystem;
    bool seats[Row][Col]={false};

char row;
int col;

    // Add Movies
    Movie movie1("Vivah", 136, "Sad");
    Movie movie2("Dilwale Dulhaniya Le Jayenge", 148, "Drama");
    Movie movie3("Hera Pheri", 169, "Comedy");

    bookingSystem.addMovie(movie1);
    bookingSystem.addMovie(movie2);
    bookingSystem.addMovie(movie3);

    // Add Showtimes
     
    Showtime showtime1(movie1, "10:00 AM", 100);
    Showtime showtime2(movie1, "2:00 PM", 100);
    Showtime showtime3(movie2, "1:00 PM", 80);
    Showtime showtime4(movie3, "4:00 PM", 60);

    bookingSystem.addShowtime(showtime1);
    bookingSystem.addShowtime(showtime2);
    bookingSystem.addShowtime(showtime3);
    bookingSystem.addShowtime(showtime4);

    int choice, movieIndex, showtimeIndex, xseats;

    while (true) {
    //	system("cls");
        cout << "\n1. Display Movies\n2. Book Ticket\n3. Exit\nEnter your choice: ";
        choice = getValidatedInput(1, 3);

        switch (choice) {
            case 1:
                bookingSystem.displayMovies();
                break;
            case 2:
                bookingSystem.displayMovies();
                cout << "Select a movie by entering its number: ";
                movieIndex = getValidatedInput(1, bookingSystem.getMovieCount()) - 1;
                bookingSystem.displayShowtimes(movieIndex);
                cout << "Select a showtime by entering its number: "<<endl;
                showtimeIndex = getValidatedInput(1, bookingSystem.getShowtimeCount()) - 1;
//                cout << "Enter number of seats: ";
//                seats = getValidatedInput(1, bookingSystem.getShowtime(showtimeIndex).availableSeats);
//                bookingSystem.bookTicket(showtimeIndex, seats);
                bookingSystem.display(seats);
                while(true){
	cout<<"Enter Row (A-E): " ; cin>>row;
	cout<<"Enter Column (1-10): "; cin>>col;
	if(row<'A'|| row>'E' && col<1||col>10){
		cout<<"Enter valid Row or Column"<<endl;
		continue;
	}
	bookingSystem.reservation(seats,row,col);
	bookingSystem.display(seats);

		char choice;
	cout<<"Do you want to book more seats (Y/N)"; cin>>choice;
		if(choice!='Y' && choice!='y'){
			break;
		}	}
                break;
            case 3:
            	
                cout << "Thank you for using the booking system. Goodbye!" << endl;
                Sleep(10000);
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
    }
    return 0;
}

