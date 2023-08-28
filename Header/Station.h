#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#include <iostream>
#include <iomanip>
#include <string>



namespace sdds {
	typedef std::string string;
	class Station {
		size_t m_id{}; 
		string m_name{}; 
		string m_description{}; 
		size_t m_SerialNo{ 0 }; 
		size_t m_numStock{ 0 }; 
		static size_t m_widthField; 
		static size_t id_generator; 
	public:
		Station(const string& str);
		const string& getItemName() const; 
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif
