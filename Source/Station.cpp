/*
Name: Shrey Priteshkumar Patel
Date of completion: 11/12/2021

I confirm that I am the only author of this file 
and the content was created entirely by me.
*/

#include "Station.h"
#include "Utilities.h"

namespace sdds {
    size_t Station::m_widthField = 0;
    size_t Station::id_generator = 0;

    Station::Station(const string& str) {
        Utilities token;
        size_t next_pos{ 0 };
        bool more{ false };

        if (!str.empty()) {
            m_name = token.extractToken(str, next_pos, more);
            if (more) {
                m_SerialNo = std::stoi(token.extractToken(str, next_pos, more));
            }
            if (more) {
                m_numStock = std::stoi(token.extractToken(str, next_pos, more));
            }
            if (m_widthField < token.getFieldWidth()) {
                m_widthField = token.getFieldWidth();
            }
            if (more) {
                m_description = token.extractToken(str, next_pos, more);
            }
        }
        m_id = ++id_generator;
    }
    const string& Station::getItemName() const {
        return m_name;
    }
    size_t Station::getNextSerialNumber() {
        return m_SerialNo++;
    }
    size_t Station::getQuantity() const {
        return m_numStock;
    }
    void Station::updateQuantity() {
        m_numStock = m_numStock < 0 ? 0 : m_numStock - 1;
    }
    void Station::display(std::ostream& os, bool full) const {
        os << '[' << std::setw(3) << std::setfill('0') << std::right << m_id;
        os << "] Item: " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_name;
        os << " [" << std::setw(6) << std::setfill('0') << std::right << m_SerialNo << "]";
        os<< std::setfill(' ') << std::left;
        if (full) {
            os << " Quantity: " << std::setw(m_widthField) << m_numStock
                << " Description: " << m_description;
        }
        os << std::endl;
    }
}
