#ifndef _DOMESTIC_LIST_H_
#define _DOMESTIC_LIST_H_

#include "domesticstudent.hpp"

/*
 * ----------------------------------------
 *                                        -
 * Singly Linked List Class - Domestic    -
 *                                        -
 * ----------------------------------------
 *
 * Singly linked list class to act as a
 * container for DomesticStudent class
 * objects.
 */

class DomesticList {
    public:
        // [ Constructor(s) ]

        // Main constructor.
        DomesticList();

        // [ Destructor(s) ]

        // Main destructor.
        ~DomesticList();

        // [ Getter(s) ]

        // Get size.
        int getSize();

        // Get head.
        DomesticStudent* getHead();

        // Get tail.
        DomesticStudent* getTail();

        // [ Function(s) ]

        // Adds a new DomesticStudent object into the list while maintaining overall sort order.
        void push(std::string firstName, std::string lastName, std::string province, float CGPA, int researchScore);

        // Prints all the domestic students in the list.
        void print();

        // Prints all domestic students that match user-inputted applicationID.
        void searchApplicationID(int applicationID);

        // Prints all domestic students that match user-inputted CGPA.
        void searchCGPA(float CGPA);

        // Prints all domestic students that match user-inputted researchScore.
        void searchResearchScore(int researchScore);

        // Prints all domestic students that match user-inputted firstName and lastName.
        void searchFullName(std::string firstName, std::string lastName);

        // Removes all domestic students that match user-inputted firstName and lastName.
        void remove(std::string firstName, std::string lastName);

        // Removes head and tail nodes.
        void removeEnds();

    private:
        // [ Member Field(s) ]

        // Number of elements in the list.
        int size;

        // Pointer to the head of the list.
        DomesticStudent* head;

        // Pointer to the tail of the list.
        DomesticStudent* tail;

        // [ Utility Function(s) ]

        // Sorts list with overall sorting scheme.
        void sort();
};

#endif