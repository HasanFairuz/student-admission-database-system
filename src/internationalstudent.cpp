#include "internationalstudent.hpp"

/*
 * ----------------------------------------
 *                                        -
 * InternationalStudent Class             -
 *                                        -
 * ----------------------------------------
 *
 * Represents an international student app-
 * lying to SFU's graduate school. Derived
 * class of the Student class.
 */

// [ Constructor(s) ]

InternationalStudent::InternationalStudent(std::string firstName, std::string lastName, std::string country, float CGPA, int researchScore)
: Student(firstName, lastName, CGPA, researchScore), country(country) {

}

// [ Destructor(s) ]

InternationalStudent::~InternationalStudent() {

}

// [ Getter(s) ]

std::string InternationalStudent::getCountry() {
    return country;
}

ToeflScore InternationalStudent::getToeflScore() {
    return toeflScore;
}

// [ Setter(s) ]

void InternationalStudent::setCountry(std::string country) {
    this->country = country;
}

void InternationalStudent::setToeflScore(ToeflScore toeflScore) {
    this->toeflScore = toeflScore;
}

// [ Friend Function(s) ]

// Compares the string value of country of two given InternationalStudent objects; 0 is returned if they are equal, -1 is returned if internationalStudent2's country comes alphabetically later, and 1 is returned if the opposite.
int compareCountry(const InternationalStudent& internationalStudent1, const InternationalStudent& internationalStudent2) {
    // Use of to_lower_copy() function from the Boost library to convert all characters of a given country to lower case.
    // Promotes consistent and accurate comparisons between two countries.
    const std::string lowerCase_internationalStudent1_country = boost::algorithm::to_lower_copy(internationalStudent1.country);
    const std::string lowerCase_internationalStudent2_country = boost::algorithm::to_lower_copy(internationalStudent2.country);

    if(lowerCase_internationalStudent1_country == lowerCase_internationalStudent2_country) {
        return 0;
    } else if(lowerCase_internationalStudent1_country < lowerCase_internationalStudent2_country) {
        return -1;
    }

    return 1;
}

// [ Function(s) ]

// Updates the readingScore held in toeflScore.
void InternationalStudent::updateReadingScore(int readingScore) {
    toeflScore.setReadingScore(readingScore);
}

// Updates the listeningScore held in toeflScore.
void InternationalStudent::updateListeningScore(int listeningScore) {
    toeflScore.setListeningScore(listeningScore);
}

// Updates the speakingScore held in toeflScore.
void InternationalStudent::updateSpeakingScore(int speakingScore) {
    toeflScore.setSpeakingScore(speakingScore);
}

// Updates the writingScore held in toeflScore.
void InternationalStudent::updateWritingScore(int writingScore) {
    toeflScore.setWritingScore(writingScore);
}


// [ Operator Overload(s) ]

std::ostream& operator<<(std::ostream& output, const InternationalStudent& internationalStudent) {
    output << "InternationalStudent(" << "applicationID=" << internationalStudent.getApplicationId() << ", "
                                      << "firstName=" << internationalStudent.getFirstName() << ", "
                                      << "lastName=" << internationalStudent.getLastName() << ", "
                                      << "country=" << internationalStudent.country << ", "
                                      << "CGPA=" << std::fixed << std::setprecision(1) << internationalStudent.getCGPA() << ", "    // fixed and setprecision(1) used to display CGPAs to the tenth (e.g. 3.0 instead of 3).
                                      << "researchScore=" << internationalStudent.getResearchScore() << ", "
                                      << "toeflScore=" << internationalStudent.toeflScore << ')';

    return output;
}