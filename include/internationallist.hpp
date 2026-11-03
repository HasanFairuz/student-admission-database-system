#ifndef _INTERNATIONAL_LIST_H_
#define _INTERNATIONAL_LIST_H_

#include "internationalstudent.hpp"

/*
 * ---------------------------------------------
 *                                             -
 * Singly Linked List Class - International    -
 *                                             -
 * ---------------------------------------------
 *
 * Singly linked list class to act as a
 * container for InternationalStudent class
 * objects.
 */

class InternationalList {
    public:
        // [ Constructor(s) ]

        // Main constructor.
        InternationalList();

        // [ Destructor(s) ]

        // Main destructor.
        ~InternationalList();

        // [ Getter(s) ]

        // Get size.
        int getSize();

        // Get head.
        InternationalStudent* getHead();

        // Get tail.
        InternationalStudent* getTail();

        // [ Function(s) ]

        // Adds a new InternationalStudent object into the list while maintaining overall sort order.
        void push(std::string firstName, std::string lastName, std::string country, float CGPA, int researchScore, ToeflScore toeflScore);

        // Prints all the international students in the list.
        void print();

        // Prints all international students that match user-inputted applicationID.
        void searchApplicationID(int applicationID);

        // Prints all international students that match user-inputted CGPA.
        void searchCGPA(float CGPA);

        // Prints all international students that match user-inputted researchScore.
        void searchResearchScore(int researchScore);

        // Prints all international students that match user-inputted firstName and lastName.
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
        InternationalStudent* head;

        // Pointer to the tail of the list.
        InternationalStudent* tail;

        // [ Utility Function(s) ]

        // Sorts list with overall sorting scheme.
        void sort();
};

#endif