/* Movie Ticket Booking System
OODP Mini Project / 1st year Semester-2 / CSE-BD / Z-1 section
Adityasankar Sengupta RA2211027010053
Harshit Rustagi RA2211027010010
Aditya Singh Khichi RA2211027010063
Ayush Panwar RA2211027010041
*/
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

class Movie {
private:
    string title;
    int duration; // in minutes
    float ticket_price;
    int total_seats;
    int booked_seats;

public:
    Movie(string t, int d, float tp, int ts) {
        title = t;
        duration = d;
        ticket_price = tp;
        total_seats = ts;
        booked_seats = 0;
    }

    // Getters and Setters
    string getTitle() const { return title; }
    void setTitle(string t) { title = t; }

    int getDuration() const { return duration; }
    void setDuration(int d) { duration = d; }

    float getTicketPrice() const { return ticket_price; }
    void setTicketPrice(float tp) { ticket_price = tp; }

    int getTotalSeats() const { return total_seats; }
    void setTotalSeats(int ts) { total_seats = ts; }

    int getBookedSeats() const { return booked_seats; }
    void setBookedSeats(int bs) { booked_seats = bs; }

    int getAvailableSeats() const {
        return total_seats - booked_seats;
    }

    void bookTickets(int num_tickets) {
        if (num_tickets <= 0) {
            throw invalid_argument("Invalid number of tickets. Please enter a positive number.");
        }
        if (num_tickets > getAvailableSeats()) {
            throw invalid_argument("Not enough available seats. Please choose a lower number of tickets.");
        }
        booked_seats += num_tickets;
    }

    float calculateCost(int num_tickets) const {
        return num_tickets * ticket_price;
    }
};

class User {
private:
    string username;
    string password;

public:
    User(string uname, string pwd) {
        username = uname;
        password = pwd;
    }

    // Getters and Setters
    string getUsername() const { return username; }
    void setUsername(string uname) { username = uname; }

    string getPassword() const { return password; }
    void setPassword(string pwd) { password = pwd; }
};
int main() {
    cout<< "\n                 MOVIE TICKET BOOKING PORTAL"<<endl;

        // Create a user account
    User user("john", "password");

    // Prompt user to log in
    string uname, pwd;
    while (true) {
        cout << "\nPlease log in to continue." << endl;
        cout << "Username: ";
        cin >> uname;
        cout << "Password: ";
        cin >> pwd;

        if (uname == user.getUsername() && pwd == user.getPassword()) {
            break;
        } else {
            cout << "Invalid login details. Please try again." << endl;
        }
    }
    
    string name;
    cout<<"\n Please enter your name: ";
    cin >> name;
    
    vector<Movie> movies;
    movies.push_back(Movie("Avengers: Endgame", 181, 280, 100));
    movies.push_back(Movie("Mission Impossible 7", 140, 220, 80));
    movies.push_back(Movie("Top Gun: Maverick", 125, 245, 120));
    movies.push_back(Movie("Spiderman: Across the Spiderverse", 115, 250, 120));

    while (true) {
        // Display available movies
        cout << "------------------------" << endl;
        cout << "Available movies: " << endl;
        for (int i = 0; i < movies.size(); i++) {
            cout << i+1 << ". " << movies[i].getTitle() << endl;
        }
        cout << "0. Exit" << endl;
        cout << "------------------------" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 0) {
            break;
        }
        if (choice < 1 || choice > movies.size()) {
            cout << "Invalid choice. Please enter a number between 1 and " << movies.size() << endl;
            continue;
        }

        Movie& selected_movie = movies[choice-1];

        while (true) {
            // Display selected movie details
            cout << "------------------------" << endl;
            cout << "Movie: " << selected_movie.getTitle() << endl;
            cout << "Duration: " << selected_movie.getDuration() << " minutes" << endl;
            cout << "Ticket price: " << selected_movie.getTicketPrice() << " Rupees" << endl;
            cout << "Available seats: " << selected_movie.getAvailableSeats() << endl;
            cout << "------------------------" << endl;

            int num_tickets;
            cout << "Enter number of tickets to book (0 to cancel): ";
            cin >> num_tickets;
            if (num_tickets == 0) {
                break;
            }
            try {
            selected_movie.bookTickets(num_tickets);
            float cost = selected_movie.calculateCost(num_tickets);
            cout << "Thank you " << name <<" Your tickets have been booked successfully!" << endl;
            cout << "Total cost: " << cost << " Rupees" << endl;
        }
        catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }
    }
}

return 0;
}
