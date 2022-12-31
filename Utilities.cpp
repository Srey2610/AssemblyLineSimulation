/*
Name: Shrey Priteshkumar Patel
Date of completion: 11/12/2021

I confirm that I am the only author of this file 
and the content was created entirely by me.
*/

#include "Utilities.h"

namespace sdds {
	char Utilities::m_delimiter = ','; 

	void Utilities::setFieldWidth(size_t newWidth) {
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const {
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
		string token{};
		size_t f_pos = next_pos;
		next_pos = str.find(m_delimiter, f_pos);

		
		if (f_pos == next_pos) {
			more = false;
			throw "No token found!";
		}
		else if (next_pos == string::npos) {
			token = str.substr(f_pos);
			m_widthField = std::max(token.length(), m_widthField);
			more = false;
		}
		else if (next_pos != string::npos) { 
			token = str.substr(f_pos, next_pos - f_pos);
			m_widthField = std::max(token.length(), m_widthField);
			more = true;
		}
		next_pos++;
		return token;
	}
	void Utilities::setDelimiter(char newDelimiter) {
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter() {
		return m_delimiter;
	}
}
