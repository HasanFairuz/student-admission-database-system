#include "student.hpp"

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

// [ Constructor(s) ]

Student::Student(std::string firstName, std::string lastName, float CGPA, int researchScore)
: firstName(firstName), lastName(lastName), CGPA(CGPA), researchScore(researchScore), applicationId(++applicationIdTracker - 1) {
    // Note that applicationId is initialized with (++applicationIdTracker - 1) in the initialization list.
    // This is meant to provide a unique applicationId to each Student.
    // One is subtracted from appicationIdTracker since application IDs start from 20210000.
}

// [ Destructor(s) ]

Student::~Student() {

}

// [ Getter(s) ]

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

float Student::getCGPA() const {
    return CGPA;
}

int Student::getResearchScore() const {
    return researchScore;
}

int Student::getApplicationId() const {
    return applicationId;
}

// [ Setter(s) ]

void Student::setFirstName(std::string firstName) {
    this->firstName = firstName;
}

void Student::setLastName(std::string lastName) {
    this->lastName = lastName;
}

void Student::setCGPA(float CGPA) {
    this->CGPA = CGPA;
}

void Student::setResearchScore(int researchScore) {
    this->researchScore = researchScore;
}

void Student::setApplicationId(int applicationId) {
    this->applicationId = applicationId;
}

// [ Operator Overload(s) ]

std::ostream& operator<<(std::ostream& output, const Student& student) {
    output << "Student(" << "applicationID=" << student.getApplicationId() << ", "
                                 << "firstName=" << student.getFirstName() << ", "
                                 << "lastName=" << student.getLastName() << ", "
                                 << "CGPA=" << std::fixed << std::setprecision(1) << student.getCGPA() << ", "    // fixed and setprecision(1) used to display CGPAs to the tenth (e.g. 3.0 instead of 3).
                                 << "researchScore=" << student.getResearchScore() << ')';

    return output;
}

// [ Friend Function(s) ]

// Compares the value of CGPA of two given Student objects; 0 is returned if they are equal, -1 is returned if student2's is higher, and 1 is returned if the opposite.
int compareCGPA(const Student& student1, const Student& student2) {
    if(student1.CGPA == student2.CGPA) {
        return 0;
    } else if(student1.CGPA < student2.CGPA) {
        return -1;
    }

    return 1;
}

// Compares the value of researchScore of two given Student objects; 0 is returned if they are equal, -1 is returned if student2's is higher, and 1 is returned if the opposite.
int compareResearchScore(const Student& student1, const Student& student2) {
    if(student1.researchScore == student2.researchScore) {
        return 0;
    } else if(student1.researchScore < student2.researchScore) {
        return -1;
    }

    return 1;
}