#ifndef _DOMESTIC_STUDENT_H_
#define _DOMESTIC_STUDENT_H_

#include "student.hpp"

/*
 * ----------------------------------------
 *                                        -
 * DomesticStudent Class                  -
 *                                        -
 * ----------------------------------------
 *
 * Represents a domestic student applying
 * to SFU's graduate school. Derived class
 * of the Student class.
 */

class DomesticStudent : public Student {
    public:
        // [ Constructor(s) ]

        DomesticStudent(std::string firstName, std::string lastName, std::string province, float CGPA, int researchScore);

        // [ Destructor(s) ]

        ~DomesticStudent();

        // [ Getter(s) ]

        std::string getProvince();

        // [ Setter(s) ]

        void setProvince(std::string province);

        // [ Friend Function(s) ]

        // Compares the string value of province of two given DomesticStudent objects; 0 is returned if they are equal, -1 is returned if domesticStudent2's province comes alphabetically later, and 1 is returned if the opposite.
        friend int compareProvince(const DomesticStudent& domesticStudent1, const DomesticStudent& domesticStudent2);

        // [ Operator Overload(s) ]

        friend std::ostream& operator<<(std::ostream& output, const DomesticStudent& domesticStudent);

        // Pointer to next DomesticStudent node.
        DomesticStudent* next;

    private:
        std::string province;
};

#endif