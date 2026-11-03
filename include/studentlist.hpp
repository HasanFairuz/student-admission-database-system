#ifndef _STUDENT_LIST_H_
#define _STUDENT_LIST_H_

#include "student.hpp"

/*
 * ---------------------------------------------
 *                                             -
 * Singly Linked List Class - Student          -
 *                                             -
 * ---------------------------------------------
 *
 * Singly linked list class to act as a
 * container for Student class
 * objects.
 */

class StudentList {
    public:
        // [ Constructor(s) ]

        // Main constructor.
        StudentList();

        // [ Destructor(s) ]

        // Main destructor.
        ~StudentList();

        // [ Getter(s) ]

        // Get size.
        int getSize();

        // Get head.
        Student* getHead();

        // Get tail.
        Student* getTail();

        // [ Function(s) ]

        // Adds a new Student object into the list while maintaining overall sort order.
        void push(Student* student);

        // Prints all the students in the list.
        void print();

        // Prints all students that match user-inputted applicationID.
        void searchApplicationID(int applicationID);

        // Prints all students that match user-inputted CGPA.
        void searchCGPA(float CGPA);

        // Prints all students that match user-inputted researchScore.
        void searchResearchScore(int researchScore);

        // Prints all students that match user-inputted firstName and lastName.
        void searchFullName(std::string firstName, std::string lastName);

        // Removes all students that match user-inputted firstName and lastName.
        void remove(std::string firstName, std::string lastName);

        // Removes head and tail nodes.
        void removeEnds();

        // Prints all students that satisfy user-inputted CGPA and researchScore thresholds.
        void searchAdmitted(float CGPA_threshold, int researchScore_threshold);

    private:
        // [ Member Field(s) ]

        // Number of elements in the list.
        int size;

        // Pointer to the head of the list.
        Student* head;

        // Pointer to the tail of the list.
        Student* tail;

        // [ Utility Function(s) ]

        // Sorts list with overall sorting scheme.
        void sort();
};

#endif