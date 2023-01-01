/*
Name: Shrey Priteshkumar Patel
Date of completion: 11/12/2021

I confirm that I am the only author of this file 
and the content was created entirely by me.
*/
#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H
#include <vector>
#include "Workstation.h"
namespace sdds {  
    class LineManager {
        std::vector<Workstation*> activeLine;
        size_t m_cntCustomerOrder{ 0u };
        Workstation* m_firstStation{ nullptr };
    public:
        LineManager(const std::string& file, const std::vector<Workstation*>& stations);
        void linkStations();
        bool run(std::ostream& os);
        void display(std::ostream& os) const;
    };
}
#endif