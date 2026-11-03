#include "toeflscore.hpp"

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

// [ Constructor(s) ]

ToeflScore::ToeflScore()
: readingScore(0), listeningScore(0), speakingScore(0), writingScore(0), totalScore(0) {
    // A default constructor for the ToeflScore class is needed as one of the member fields of the InternationalStudent class
    // is of ToeflScore.
}

ToeflScore::ToeflScore(int readingScore, int listeningScore, int speakingScore, int writingScore)
: readingScore(readingScore), listeningScore(listeningScore), speakingScore(speakingScore), writingScore(writingScore) {
    updateTotalScore();
}

// [ Destructor(s) ]

ToeflScore::~ToeflScore() {

}

// [ Getter(s) ]

int ToeflScore::getReadingScore() {
    return readingScore;
}

int ToeflScore::getListeningScore() {
    return listeningScore;
}

int ToeflScore::getSpeakingScore() {
    return speakingScore;
}

int ToeflScore::getWritingScore() {
    return writingScore;
}

int ToeflScore::getTotalScore() {
    return totalScore;
}

// [ Setter(s) ]

void ToeflScore::setReadingScore(int readingScore) {
    this->readingScore = readingScore;

    // updateTotalScore() is called everytime the value of readingScore detects a change attempt to automate updates to totalScore.
    updateTotalScore();
}

void ToeflScore::setListeningScore(int listeningScore) {
    this->listeningScore = listeningScore;

    // updateTotalScore() is called everytime the value of listeningScore detects a change attempt to automate updates to totalScore.
    updateTotalScore();
}

void ToeflScore::setSpeakingScore(int speakingScore) {
    this->speakingScore = speakingScore;

    // updateTotalScore() is called everytime the value of speakingScore detects a change attempt to automate updates to totalScore.
    updateTotalScore();
}

void ToeflScore::setWritingScore(int writingScore) {
    this->writingScore = writingScore;

    // updateTotalScore() is called everytime the value of writingScore detects a change attempt to automate updates to totalScore.
    updateTotalScore();
}


// [ Operator Overload(s) ]

std::ostream& operator<<(std::ostream& output, const ToeflScore& toeflScore) {
    output << "ToeflScore(" << "readingScore=" << toeflScore.readingScore << ", "
                            << "listeningScore=" << toeflScore.listeningScore << ", "
                            << "speakingScore=" << toeflScore.speakingScore << ", "
                            << "writingScore=" << toeflScore.writingScore << ", "
                            << "totalScore=" << toeflScore.totalScore << ')';

    return output;
}

//  [ Utility Function(s) ]

// Updates totalScore every time a setter for readingScore, listeningScore, speakingScore, or writingScore is called.
void ToeflScore::updateTotalScore() {
    totalScore = readingScore + listeningScore + speakingScore + writingScore;
}