#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>                           // string
#include <iostream>                         // cout
#include <ostream>                          // overloading << operator
#include <vector>                           // vector
#include <iomanip>                          // fixed and setprecision

#include <boost/algorithm/string.hpp>       // boost::algorithm::to_lower_copy

/*
 * ----------------------------------------
 *                                        -
 * Student Class                          -
 *                                        -
 * ----------------------------------------
 *
 * Represents a student applying to SFU's
 * graduate school. Base class of Domestic
 * Student class and InternationalStudent
 * class.
 */

class Student {
    public:
        // [ Constructor(s) ]

        Student(std::string firstName, std::string lastName, float CGPA, int researchScore);

        // [ Destructor(s) ]

        ~Student();

        // [ Getter(s) ]

        std::string getFirstName() const;
        std::string getLastName() const;
        float getCGPA() const;
        int getResearchScore() const;
        int getApplicationId() const;

        // [ Setter(s) ]

        void setFirstName(std::string firstName);
        void setLastName(std::string lastName);
        void setCGPA(float CGPA);
        void setResearchScore(int researchScore);
        void setApplicationId(int applicationId);

        // [ Operator Overload(s) ]

        friend std::ostream& operator<<(std::ostream& output, const Student& student);

        // [ Friend Function(s) ]

        // Compares the value of CGPA of two given Student objects; 0 is returned if they are equal, -1 is returned if student2's is higher, and 1 is returned if the opposite.
        friend int compareCGPA(const Student& student1, const Student& student2);

        // Compares the value of researchScore of two given Student objects; 0 is returned if they are equal, -1 is returned if student2's is higher, and 1 is returned if the opposite.
        friend int compareResearchScore(const Student& student1, const Student& student2);

        // Pointer to next Student node.
        Student* next;

    private:
        std::string firstName;
        std::string lastName;
        float CGPA;
        int researchScore;
        int applicationId;
        static int applicationIdTracker; // Incremented everytime Student class's constructor is called (instantiated) and used to provide unique application IDs to students applying to SFU's graduate school.
};

#endif