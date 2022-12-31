/*
Name: Shrey Priteshkumar Patel
Date of completion: 11/12/2021

I confirm that I am the only author of this file 
and the content was created entirely by me.
*/
#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"

namespace sdds {
    size_t CustomerOrder::m_widthField = 0;

    CustomerOrder::CustomerOrder(const std::string& str) {
        if (!str.empty()) {
            Utilities token;
            char delim{ token.getDelimiter() };
            size_t begin_pos{ 0 }, end_pos{ 0 };
            bool condition{ false };

            end_pos = str.find(delim);
            m_name = str.substr(0, end_pos);

            begin_pos = end_pos + 1;
            end_pos = str.find(delim, begin_pos);
            m_product = token.extractToken(str, begin_pos, condition);
            if (condition) {
                m_cntItem = std::count(str.begin(), str.end(), token.getDelimiter()) - 1;
                if (m_cntItem > 0) {
                    m_lstItem = new Item * [m_cntItem];
                    for (size_t i = 0u; i < m_cntItem; ++i) {
                        begin_pos = end_pos + 1;
                        end_pos = str.find(delim, begin_pos);
                        m_lstItem[i] = new Item(token.extractToken(str, begin_pos, condition));
                    }
                }
            }
            m_widthField = m_widthField < token.getFieldWidth() ? token.getFieldWidth() : m_widthField;
        }
    }
    CustomerOrder::CustomerOrder(const CustomerOrder&) {
        throw std::string("Making copies is not !");
    }
    CustomerOrder::CustomerOrder(CustomerOrder&& co) noexcept {
        *this = std::move(co);
    }
    CustomerOrder& CustomerOrder::operator=(CustomerOrder&& co) noexcept {
        if (this != &co) {
            if (m_lstItem) {
                for (size_t i = 0u; i < m_cntItem; i++) {
                    delete m_lstItem[i];
                }
                delete[] m_lstItem;
            }
            m_name = co.m_name;
            m_product = co.m_product;
            m_cntItem = co.m_cntItem;
            m_lstItem = co.m_lstItem;
            m_widthField = co.m_widthField;

            co.m_name = "";
            co.m_product = "";
            co.m_cntItem = 0u;
            co.m_lstItem = nullptr;
        }
        return *this;
    }
    CustomerOrder::~CustomerOrder() {
        for (auto i = 0u; i < m_cntItem; i++) {
            delete m_lstItem[i];
        }
        delete[] m_lstItem;
        m_lstItem = nullptr;
    }
    bool CustomerOrder::isFilled() const {
        bool allFilled{ true };
        for (size_t i = 0; i < m_cntItem; i++) {
            if (!m_lstItem[i]->m_isFilled) {
                allFilled = false;
            }
        }
        return allFilled;
    }
    bool CustomerOrder::isItemFilled(const std::string& itemName) const {
        bool allFilled{ true };
        for (size_t i = 0; i < m_cntItem; i++) {
            if (m_lstItem[i]->m_itemName == itemName && !m_lstItem[i]->m_isFilled) {
                allFilled = false;
            }
        }
        return allFilled;
    }
    void CustomerOrder::fillItem(Station& station, std::ostream& os) {
        for (size_t i = 0u; i < m_cntItem; i++) {
            if (station.getItemName() == m_lstItem[i]->m_itemName) {
                if (station.getQuantity() > 0) {
                    station.updateQuantity();
                    m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                    m_lstItem[i]->m_isFilled = true;
                    os << "    Filled " << m_name << ", "
                        << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                }
                else {
                    os << "    Unable to fill " << m_name << ", "
                        << m_product << " [" << m_lstItem[i]->m_itemName << "]" << std::endl;
                }
            }
        }
    }
    void CustomerOrder::display(std::ostream& os) const {
        os << m_name << " - " << m_product << std::endl;
        for (size_t i = 0u; i < m_cntItem; i++) {
            os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber << "] "
                << std::setw(m_widthField) << std::setfill(' ') << std::left << m_lstItem[i]->m_itemName << " - "
                << (m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED") << std::endl;
        }
    }
}
