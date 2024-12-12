/*
Uppgift 3 (G - 20 poäng)

Skriv ett program som implementerar ett enkelt bokningssystem för ett företag med följande klassdesign: 

Klasser: 

    Bokning (Booking) 
        Attribut: 
            bokningsID
            kundNamn
            kontaktInfo
            datum
            status (bekräftad/väntande/avbokad)
    BokningsHanterare (BookingManager) 
        Metoder: 
            skapaBokning()
            taBortBokning()
            sökBokning()
            visaAllaBokningar()

Skapa ett huvudprogram som demonstrerar funktionaliteten i bokningssystemet genom interaktioner mellan klasser. Programmet ska inte använda inmatning från konsolen (cin). I stället ska de bokningsobjekt som krävs för att visa systemets funktioner skapas direkt i huvudprogrammet.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <compare>
#include <ctime>

enum STATUS {
	NONE = 0,
	CONFIRMED,
	PENDING,
	CANCELLED,
};

// printout lookup table for STATUS enum
static const char * status_table[] = {
	"NONE", 
	"CONFIRMED", 
	"PENDING", 
	"CANCELLED",
};

class Booking {
public:
	Booking(unsigned int id, std::string &customer_name, std::string &contact_info, enum STATUS status) {
		this->id = id;
		this->customer_name = customer_name;
		this->contact_info = contact_info;
		time(&this->timestamp);
		this->status = status;
	}
	
	Booking(unsigned int id, const char * customer_name, const char * contact_info, enum STATUS status) {
		this->id = id;
		this->customer_name = std::string(customer_name);
		this->contact_info = std::string(contact_info);
		time(&this->timestamp);
		this->status = status;
	}
	
	~Booking() {
	}
	
	void print() {
		std::cout << "Booking Info:" << std::endl;
		std::cout << "\tID            : " << this->id << std::endl;
		std::cout << "\tCustomer Name : " << this->customer_name << std::endl;
		std::cout << "\tContact Info  : " << this->contact_info << std::endl;
		// cheeky escape code since ctime adds a newline char and i dont want to use C's snprintf
		std::cout << "\tDatetime      : " << ctime(&this->timestamp) << "\033[F" << std::endl;
		std::cout << "\tStatus        : " << status_table[this->status] << std::endl;
		std::cout << std::endl;
	}
	
	// yes the data is public - no point in having it be private
	unsigned int id;
	std::string customer_name;
	std::string contact_info;
	time_t timestamp; // date + time
	enum STATUS status;
};

class BookingManager {
public:
	BookingManager(size_t capacity = 32) {
		rolling_id = 0;
		bookings.reserve(capacity);
	}
	
	~BookingManager() {
		bookings.clear();
	}
	
	unsigned int createBooking(std::string customer_name, std::string contact_info) {
		// pre-increment rolling id to make sure it can never be 0!!!
		const unsigned int id = ++rolling_id;
		Booking booking(id, customer_name, contact_info, PENDING);
		bookings.emplace_back(booking);
		return id;
	}
	
	int removeBooking(unsigned int id) {
		// simple linear search on vector - were not using a hashmap with id as key tho
		// note that i dont delete the booking. the removal clearly means to cancel it.
		const int size = bookings.size();
		for(int i = 0; i < size; i++) {
			if(bookings[i].id == id) {
				// bookings.erase(bookings.begin() + i);
				bookings[i].status = CANCELLED;
				return 1;
			}
		}
		return 0;
	}
	
	Booking * searchBooking(std::string customer_name) {
		// simple linear search on vector
		const int size = bookings.size();
		for(int i = 0; i < size; i++) {
			if(bookings[i].customer_name == customer_name) {
				return (Booking*)&bookings[i];
			}
		}
		return NULL;
	}
	
	void showAllBookings() {
		// dump them out to terminal
		std::cout << "Show All Bookings:" << std::endl;
		const int size = bookings.size();
		for(int i = 0; i < size; i++) {
			bookings[i].print();
		}
		std::cout << std::endl;
	}
	
	unsigned int rolling_id;
	std::vector<Booking> bookings;
};

int main() {
	std::cout << " === Uppgift 3 - Carl Blumenthal ===" << std::endl;
	
	BookingManager bookingManager(8);
	
	bookingManager.createBooking("Manfred Beguili", "manfredi@beguili.it");
	bookingManager.createBooking("Coca Cola Man", "the@pepsi.com");
	bookingManager.createBooking("Guitar Kotou", "+88(0)71234923");
	bookingManager.createBooking("Cat", "The Window");
	
	Booking * query = bookingManager.searchBooking("Cat");
	if(query != NULL) {
		bookingManager.removeBooking(query->id);
	}
	
	bookingManager.showAllBookings();
	
	return 0;
}
