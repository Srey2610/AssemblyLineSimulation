/*
Name: Shrey Priteshkumar Patel
Date of completion: 11/12/2021

I confirm that I am the only author of this file 
and the content was created entirely by me.
*/
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include <iostream>
#include <string>
#include <algorithm>

namespace sdds{
	typedef std::string string;
	class Utilities {
		size_t m_widthField{ 1 }; 
		static char m_delimiter; 
	public:
		void setFieldWidth(size_t newWidth); 
		size_t getFieldWidth() const; 
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(char newDelimiter); 
		static char getDelimiter(); 
	};
}
#endif