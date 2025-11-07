#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>   // For string formatting
#include <iomanip> // For setprecision

using namespace std;

// --- 1. Data Classes ---

class Movie {
public:
    string title;
    Movie(string t = "") : title(t) {}
};

class TimeSlot {
public:
    string id;
    string time;
    bool isVipOnly;
    TimeSlot(string i = "", string t = "", bool vip = false) 
        : id(i), time(t), isVipOnly(vip) {}
};

class Customer {
public:
    string type;
    double price;
    Customer(string t = "", double p = 0.0) : type(t), price(p) {}
};

class Screen {
public:
    int screenNumber;
    int maxSeats;
    Screen(int num = 0, int seats = 0) : screenNumber(num), maxSeats(seats) {}
};

// --- 2. The "Linking" Class ---

class Show {
public:
    Movie* movie;
    Screen* screen;
    TimeSlot* timeSlot;

    Show(Movie* m, Screen* s, TimeSlot* ts) 
        : movie(m), screen(s), timeSlot(ts) {}
};

// --- 3. The "Container" Class ---

class Theater {
public:
    string name;
    map<int, Screen> screens; // Maps screen number to Screen object
    vector<Show> shows;

    Theater(string n = "") : name(n) {}

    void addScreen(const Screen& screen) {
        screens[screen.screenNumber] = screen;
    }

    // Helper to get a pointer to a managed screen
    Screen* getScreen(int screenNumber) {
        if (screens.find(screenNumber) != screens.end()) {
            return &screens.at(screenNumber);
        }
        return nullptr;
    }

    void addShow(const Show& show) {
        shows.push_back(show);
    }

    // Check for Error 1: Does this theater play this movie at all?
    bool playsMovie(const string& movieTitle) {
        for (const auto& show : shows) {
            if (show.movie->title == movieTitle) {
                return true;
            }
        }
        return false;
    }

    // Check for Error 3: Find the specific show for this movie AND time.
    Show* findShow(const string& movieTitle, const string& timeSlotId) {
        for (auto& show : shows) {
            if (show.movie->title == movieTitle && show.timeSlot->id == timeSlotId) {
                return &show;
            }
        }
        return nullptr;
    }
};

// --- 4. The "Service" Class ---

class BookingSystem {
private:
    map<string, Theater> theaters;
    map<string, Movie> movies;
    map<string, TimeSlot> timeSlots;
    map<string, Customer> customerTypes;

public:
    // Constructor seeds all the data from the problem description
    BookingSystem() {
        // Seed Customer Types and Prices 
        customerTypes["VIP"] = Customer("VIP", 12.50);
        customerTypes["Guest"] = Customer("Guest", 15.00);

        // Seed Time Slots 
        timeSlots["T1"] = TimeSlot("T1", "10 AM", false);
        timeSlots["T2"] = TimeSlot("T2", "1 PM", false);
        timeSlots["T3"] = TimeSlot("T3", "4 PM", false);
        timeSlots["T4"] = TimeSlot("T4", "8 PM", false);
        timeSlots["T5"] = TimeSlot("T5", "11 PM", true); // VIP only

        // Seed Movies 
        movies["Cold Pursuit"] = Movie("Cold Pursuit");
        movies["Spiderman"] = Movie("Spiderman");
        movies["Robin Hood"] = Movie("Robin Hood");

        // --- Configure AMC-Dinein ---
        Theater amc("AMC-Dinein");
        amc.addScreen(Screen(1, 45)); // [cite: 19]
        amc.addScreen(Screen(2, 60)); // [cite: 21]

        // Add AMC shows 
        amc.addShow(Show(&movies["Cold Pursuit"], amc.getScreen(1), &timeSlots["T1"]));
        amc.addShow(Show(&movies["Cold Pursuit"], amc.getScreen(1), &timeSlots["T5"]));
        amc.addShow(Show(&movies["Cold Pursuit"], amc.getScreen(2), &timeSlots["T2"]));
        amc.addShow(Show(&movies["Cold Pursuit"], amc.getScreen(2), &timeSlots["T3"]));
        amc.addShow(Show(&movies["Spiderman"], amc.getScreen(1), &timeSlots["T2"]));
        amc.addShow(Show(&movies["Spiderman"], amc.getScreen(1), &timeSlots["T3"]));
        amc.addShow(Show(&movies["Spiderman"], amc.getScreen(1), &timeSlots["T4"]));
        amc.addShow(Show(&movies["Spiderman"], amc.getScreen(2), &timeSlots["T1"]));
        amc.addShow(Show(&movies["Spiderman"], amc.getScreen(2), &timeSlots["T4"]));

        theaters[amc.name] = amc;

        // --- Configure Jordon ---
        Theater jordon("Jordon");
        jordon.addScreen(Screen(1, 80)); // [cite: 23]
        jordon.addScreen(Screen(2, 15)); // [cite: 25]

        // Add Jordon shows 
        jordon.addShow(Show(&movies["Robin Hood"], jordon.getScreen(1), &timeSlots["T1"]));
        jordon.addShow(Show(&movies["Robin Hood"], jordon.getScreen(1), &timeSlots["T2"]));
        jordon.addShow(Show(&movies["Robin Hood"], jordon.getScreen(2), &timeSlots["T4"]));
        jordon.addShow(Show(&movies["Robin Hood"], jordon.getScreen(2), &timeSlots["T5"]));
        jordon.addShow(Show(&movies["Cold Pursuit"], jordon.getScreen(1), &timeSlots["T3"]));
        jordon.addShow(Show(&movies["Cold Pursuit"], jordon.getScreen(1), &timeSlots["T4"]));
        jordon.addShow(Show(&movies["Cold Pursuit"], jordon.getScreen(1), &timeSlots["T5"]));
        jordon.addShow(Show(&movies["Cold Pursuit"], jordon.getScreen(2), &timeSlots["T1"]));
        jordon.addShow(Show(&movies["Cold Pursuit"], jordon.getScreen(2), &timeSlots["T2"]));
        
        theaters[jordon.name] = jordon;
    }

    // Main booking logic method
    string processBooking(const string& theaterName, const string& movieName, 
                          const string& timeSlotId, int numTickets, const string& customerType) {

        // Get the theater. (Assuming valid theater name as per error logic)
        Theater& theater = theaters.at(theaterName);

        // --- CHECK 1: Error 1 ---
        // Movie not screened at this theater 
        if (!theater.playsMovie(movieName)) {
            return "1";
        }

        // --- CHECK 2: Error 3 (Invalid slot) ---
        // Find the specific show for this movie and time slot 
        Show* show = theater.findShow(movieName, timeSlotId);

        if (show == nullptr) {
            // --- CHECK 2a: Error 5 (VIP/T5/Wrong Movie/Theater) ---
            // This is an invalid slot, but check if it's the special case
            // for a VIP trying to book T5 
            if (customerType == "VIP" && timeSlotId == "T5") {
                return "5";
            }
            // Otherwise, it's a standard Error 3
            return "3";
        }

        // --- CHECK 3: Error 4 (Guest on VIP slot) ---
        // Guest customer trying to book a VIP-only slot 
        if (customerType == "Guest" && show->timeSlot->isVipOnly) {
            return "4";
        }

        // --- CHECK 4: Error 2 (Not enough seats) ---
        // Requested tickets exceed screen capacity 
        if (numTickets > show->screen->maxSeats) {
            // --- CHECK 4a: Error 5 (VIP/T5/Too many tickets) ---
            // Check for the other Error 5 special case 
            if (customerType == "VIP" && show->timeSlot->id == "T5") {
                return "5";
            }
            // Otherwise, it's a standard Error 2
            return "2";
        }

        // --- SUCCESS ---
        // All checks passed. Calculate the price.
        double pricePerTicket = customerTypes.at(customerType).price;
        double totalPrice = numTickets * pricePerTicket;

        // Format to 2 decimal places 
        stringstream ss;
        ss << fixed << setprecision(2) << totalPrice;
        return ss.str();
    }
};

// --- Main function to run test cases ---
int main() {
    BookingSystem system;

    // Test Case 1: 
    // Input: AMC-Dinein Spiderman T4 5 Guest
    // Output: 75.00
    cout << "Test Case 1: " 
         << system.processBooking("AMC-Dinein", "Spiderman", "T4", 5, "Guest") 
         << endl;

    // Test Case 2: 
    // Input: Jordon Robin Hood T3 5 VIP
    // Output: 3
    cout << "Test Case 2: " 
         << system.processBooking("Jordon", "Robin Hood", "T3", 5, "VIP") 
         << endl;

    return 0;
}