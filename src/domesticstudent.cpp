#include "domesticstudent.hpp"

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

// [ Constructor(s) ]

DomesticStudent::DomesticStudent(std::string firstName, std::string lastName, std::string province, float CGPA, int researchScore)
: Student(firstName, lastName, CGPA, researchScore), province(province) {

}

// [ Destructor(s) ]

DomesticStudent::~DomesticStudent() {

}

// [ Getter(s) ]
std::string DomesticStudent::getProvince() {
    return province;
}

// [ Setter(s) ]

void DomesticStudent::setProvince(std::string province) {
    this->province = province;
}

// [ Friend Function(s) ]

// Compares the string value of province of two given DomesticStudent objects; 0 is returned if they are equal, -1 is returned if domesticStudent2's province comes alphabetically later, and 1 is returned if the opposite.
int compareProvince(const DomesticStudent& domesticStudent1, const DomesticStudent& domesticStudent2) {
    // Use of to_lower_copy() function from the Boost library to convert all characters of a given province to lower case.
    // Promotes consistent and accurate comparisons between two provinces.
    const std::string lowerCase_domesticStudent1_province = boost::algorithm::to_lower_copy(domesticStudent1.province);
    const std::string lowerCase_domesticStudent2_province = boost::algorithm::to_lower_copy(domesticStudent2.province);

    if(lowerCase_domesticStudent1_province == lowerCase_domesticStudent2_province) {
        return 0;
    } else if(lowerCase_domesticStudent1_province < lowerCase_domesticStudent2_province) {
        return -1;
    }

    return 1;
}

// [ Operator Overload(s) ]

std::ostream& operator<<(std::ostream& output, const DomesticStudent& domesticStudent) {
    output << "DomesticStudent(" << "applicationID=" << domesticStudent.getApplicationId() << ", "
                                 << "firstName=" << domesticStudent.getFirstName() << ", "
                                 << "lastName=" << domesticStudent.getLastName() << ", "
                                 << "province=" << domesticStudent.province << ", "
                                 << "CGPA=" << std::fixed << std::setprecision(1) << domesticStudent.getCGPA() << ", "    // fixed and setprecision(1) used to display CGPAs to the tenth (e.g. 3.0 instead of 3).
                                 << "researchScore=" << domesticStudent.getResearchScore() << ')';

    return output;
}