#ifndef _INTERNATIONAL_STUDENT_H_
#define _INTERNATIONAL_STUDENT_H_

#include "student.hpp"
#include "toeflscore.hpp"

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

class InternationalStudent : public Student {
    public:
        // [ Constructor(s) ]

        InternationalStudent(std::string firstName, std::string lastName, std::string country, float CGPA, int researchScore);

        // [ Destructor(s) ]

        ~InternationalStudent();

        // [ Getter(s) ]

        std::string getCountry();
        ToeflScore getToeflScore();

        // [ Setter(s) ]

        void setCountry(std::string country);
        void setToeflScore(ToeflScore toeflScore);

        // [ Friend Function(s) ]

        // Compares the string value of country of two given InternationalStudent objects; 0 is returned if they are equal, -1 is returned if internationalStudent2's country comes alphabetically later, and 1 is returned if the opposite.
        friend int compareCountry(const InternationalStudent& internationalStudent1, const InternationalStudent& internationalStudent2);

        // [ Function(s) ]

        // Updates the readingScore held in toeflScore.
        void updateReadingScore(int readingScore);

        // Updates the listeningScore held in toeflScore.
        void updateListeningScore(int listeningScore);

        // Updates the speakingScore held in toeflScore.
        void updateSpeakingScore(int speakingScore);

        // Updates the writingScore held in toeflScore.
        void updateWritingScore(int writingScore);

        // [ Operator Overload(s) ]

        friend std::ostream& operator<<(std::ostream& output, const InternationalStudent& internationalStudent);

        // Pointer to next InternationalStudent node.
        InternationalStudent* next;

    private:
        std::string country;
        ToeflScore toeflScore;
};

#endif