#include <utility>
#include <iostream>
#include "Workstation.h"
namespace sdds {  
    std::deque<CustomerOrder> pending;
    std::deque<CustomerOrder> completed;
    std::deque<CustomerOrder> incomplete;
   
    void Workstation::fill(std::ostream& os) {
        if(!m_orders.empty()) { m_orders.front().fillItem(*this, os); }
    }

    bool Workstation::attemptToMoveOrder(){
        bool value = false;
        if(!m_orders.empty()) {
            if(m_orders.front().isItemFilled(getItemName()) || !getQuantity()) {
                if(m_pNextStation) {
                    *m_pNextStation += std::move(m_orders.front());
                    m_orders.pop_front();
                }
                else{
                    if(m_orders.front().isFilled()) {
                        completed.push_back(std::move(m_orders.front()));
                        m_orders.pop_front();
                    }
                    else {
                        incomplete.push_back(std::move(m_orders.front()));
                        m_orders.pop_front();
                    }
                }
                value = true;
            }
        }
        return value;
    }

    Workstation* Workstation::getNextStation() const {
        return m_pNextStation;
    }
    void Workstation::setNextStation(Workstation* station) {
        m_pNextStation = station;
    }

    Workstation& Workstation::operator+=(CustomerOrder&& newOrder) {
        m_orders.push_back(std::move(newOrder));
        return *this;
    }

    void Workstation::display(std::ostream& os) const {
        if(m_pNextStation) os << getItemName() << " --> " << m_pNextStation->getItemName();
        else os << getItemName() << " --> End of Line";
        os << std::endl;
    }

}
