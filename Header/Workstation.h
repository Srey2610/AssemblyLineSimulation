#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include <deque>
#include "CustomerOrder.h"
#include "Station.h"

namespace sdds {  
    extern std::deque<CustomerOrder> pending;
    extern std::deque<CustomerOrder> completed;
    extern std::deque<CustomerOrder> incomplete;

    class Workstation: public Station{
        std::deque<CustomerOrder> m_orders;
        Workstation *m_pNextStation{ nullptr };
    public:
        Workstation(const std::string &str):Station(str){};
        void fill(std::ostream& os);
        bool attemptToMoveOrder();
        void setNextStation(Workstation* station);
        Workstation* getNextStation() const;
        void display(std::ostream& os) const;
        Workstation& operator+=(CustomerOrder&& newOrder); 

        //deleted functionalities
        Workstation(const Workstation&) = delete;
        Workstation(Workstation&&)noexcept = delete;
        Workstation&operator=(const Workstation&) = delete;
        Workstation&operator=(Workstation&&)noexcept = delete;
    };
   
}
#endif
