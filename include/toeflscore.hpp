#ifndef _TOEFL_SCORE_H_
#define _TOEFL_SCORE_H_

#include <ostream>

/*
 * ----------------------------------------
 *                                        -
 * ToeflScore Class                       -
 *                                        -
 * ----------------------------------------
 *
 * Represents the various scores that make
 * up an overall TOEFL exam score.
 */

class ToeflScore {
    public:
        // [ Constructor(s) ]

        ToeflScore();
        ToeflScore(int readingScore, int listeningScore, int speakingScore, int writingScore);

        // [ Destructor(s) ]

        ~ToeflScore();

        // [ Getter(s) ]

        int getReadingScore();
        int getListeningScore();
        int getSpeakingScore();
        int getWritingScore();
        int getTotalScore();

        // [ Setter(s) ]

        void setReadingScore(int readingScore);
        void setListeningScore(int listeningScore);
        void setSpeakingScore(int speakingScore);
        void setWritingScore(int writingScore);

        // [ Operator Overload(s) ]

        friend std::ostream& operator<<(std::ostream& output, const ToeflScore& toeflScore);

    private:
        int readingScore;
        int listeningScore;
        int speakingScore;
        int writingScore;
        int totalScore;

        // [ Utility Function(s) ]

        // Updates totalScore every time a setter for readingScore, listeningScore, speakingScore, or writingScore is called.
        void updateTotalScore();
};

#endif