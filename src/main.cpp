#include <iostream>     // cin and cout
#include <fstream>      // file processing
#include <sstream>      // formatted string processing
#include <cstdlib>      // atof and atoi

#include "domesticstudent.hpp"
#include "internationalstudent.hpp"
#include "domesticlist.hpp"
#include "internationallist.hpp"
#include "studentlist.hpp"

// Valid provinces.
std::vector<std::string> validProvinces = {"NL", "PE", "NS", "NB", "QC", "ON", "MB", "SK", "AB", "BC", "YT", "NT", "NU"};

// Valid countries.
std::vector<std::string> validCountries = {"Canada", "China", "India", "Iran", "Korea"};

// [ Function Declaration(s) ]

// Displays application menu.
void displayMenu();

// Populates a given list with domestic student data extracted from a given file.
void populateDomesticList(std::string file, DomesticList& list);

// Populates a given list with international student data extracted from a given file.
void populateInternationalList(std::string file, InternationalList& list);

// Used to aid in assigning students with a unique 8-digit application ID.
int Student::applicationIdTracker = 20210000;

// Linked list to be populated with DomesticStudent objects instantiated with data extracted from "domestic-stu.txt"
DomesticList domesticList;
DomesticList copyOfDomesticList;

// Linked list to be populated with InternationalStudent objects instantiated with data extracted from "international-stu.txt"
InternationalList internationalList;
InternationalList copyOfInternationalList;

int main() {

  // Populate domesticList.
  populateDomesticList("domestic-stu.txt", domesticList);

  // Keep a copy of domesticList.
  copyOfDomesticList = domesticList;

  // Populate internationalList.
  populateInternationalList("international-stu.txt", internationalList);

  // Keep a copy of internationalList.
  copyOfInternationalList = internationalList;

  displayMenu();

  return 0;
}

// [ Function Definition(s) ]

// Displays application menu.
void displayMenu() {
  while(true) {
    std::cout << std::endl;
    std::cout << "SELECT STUDENT TYPE:" << std::endl;
    std::cout << "1. DOMESTIC" << std::endl;
    std::cout << "2. INTERNATIONAL" << std::endl;
    std::cout << "3. MERGED" << std::endl;
    std::cout << "4. EXIT" << std::endl;
    std::cout << "> ";

    int typeInput;

    std::cin >> typeInput;

    while(std::cin.fail() || typeInput < 1 || typeInput > 4) {
        std::cout << "ENTER A VALID OPTION (1 - 4) > ";
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cin >> typeInput;
    }

    if(typeInput == 1) {
      while(true) {
        std::cout << std::endl;
        std::cout << "(DOMESTIC) PICK OPERATION:" << std::endl;
        std::cout << "1. SEARCH FOR applicationID" << std::endl;
        std::cout << "2. SEARCH FOR CGPA" << std::endl;
        std::cout << "3. SEARCH FOR researchScore" << std::endl;
        std::cout << "4. SEARCH FOR firstName AND lastName" << std::endl;
        std::cout << "5. CREATE NEW DomesticStudent NODE" << std::endl;
        std::cout << "6. REMOVE DomesticStudent NODE" << std::endl;
        std::cout << "7. REMOVE head AND tail NODES" << std::endl;
        std::cout << "8. PRINT domesticList" << std::endl;
        std::cout << "9. BACK TO STUDENT TYPE SELECTION" << std::endl;
        std::cout << "> ";

        int domesticOperationInput;

        std::cin >> domesticOperationInput;

        while(std::cin.fail() || domesticOperationInput < 1 || domesticOperationInput > 9) {
            std::cout << "ENTER A VALID OPTION (1 - 9) > ";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> domesticOperationInput;
        }

        if(domesticOperationInput == 1) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR applicationID STARTED ..." << std::endl;
          std::cout << "ENTER AN EIGHT DIGIT applicationID IN THE FORMAT (2021####): ";

          int searchApplicationID;

          std::cin >> searchApplicationID;

          while(std::cin.fail() || searchApplicationID < 20210000 || searchApplicationID > 20219999) {
              std::cout << "ERROR: ENTER AN EIGHT DIGIT applicationID IN THE FORMAT (2021####): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> searchApplicationID;
          }

          std::cout << "SEARCH RESULTS FOR applicationID " << searchApplicationID << ":" << std::endl;
          domesticList.searchApplicationID(searchApplicationID);
        } else if(domesticOperationInput == 2) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR CGPA STARTED ..." << std::endl;
          std::cout << "ENTER A CGPA (0 TO 4.3): ";

          float searchCGPA;

          std::cin >> searchCGPA;

          while(std::cin.fail() || searchCGPA < 0 || searchCGPA > 4.3F) {
              std::cout << "ERROR: ENTER A CGPA (0 TO 4.3): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> searchCGPA;
          }

          std:: cout << "SEARCH RESULTS FOR CGPA " << searchCGPA << ":" << std::endl;
          domesticList.searchCGPA(searchCGPA);
        } else if(domesticOperationInput == 3) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR researchScore STARTED ..." << std::endl;
          std::cout << "ENTER A researchScore (0 - 100): ";

          int searchResearchScore;

          std::cin >> searchResearchScore;

          while(std::cin.fail() || searchResearchScore < 0 || searchResearchScore > 100) {
              std::cout << "ERROR: ENTER A researchScore (0 - 100): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> searchResearchScore;
          }

          std:: cout << "SEARCH RESULTS FOR researchScore " << searchResearchScore << ":" << std::endl;
          domesticList.searchResearchScore(searchResearchScore);
        } else if(domesticOperationInput == 4) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR firstName AND lastName STARTED ..." << std::endl;

          std::string searchFirstName;
          std::string searchLastName;

          std::cout << "ENTER A firstName: ";

          std::cin >> searchFirstName;

          std::cout << "ENTER a lastName: ";

          std::cin >> searchLastName;

          std:: cout << "SEARCH RESULTS FOR " << searchFirstName << " " << searchLastName << ":" << std::endl;
          domesticList.searchFullName(searchFirstName, searchLastName);
        } else if(domesticOperationInput == 5) {
          std::cout << std::endl;
          std::cout << "CREATION FOR DomesticStudent NODE STARTED ..." << std::endl;

          std::string createFirstName;
          std::string createLastName;
          std::string createProvince;
          float createCGPA;
          int createResearchScore;

          std::cout << "ENTER A firstName: ";
          std::cin >> createFirstName;

          std::cout << "ENTER a lastName: ";
          std::cin >> createLastName;

          std::cout << "ENTER a province (NL, PE, NS, NB, QC, ON, MB, SK, AB, BC, YT, NT, NU): ";
          std::cin >> createProvince;

          bool isValidProvince = false;

          for(int i = 0; i < 13; i++) {
            if(boost::algorithm::to_lower_copy(createProvince) == boost::algorithm::to_lower_copy(validProvinces[i])) {
              isValidProvince = true;
            }
          }

          while(isValidProvince == false) {
            std::cout << "ENTER a valid province (NL, PE, NS, NB, QC, ON, MB, SK, AB, BC, YT, NT, NU): ";
            std::cin >> createProvince;

            for(int i = 0; i < 13; i++) {
              if(boost::algorithm::to_lower_copy(createProvince) == boost::algorithm::to_lower_copy(validProvinces[i])) {
                isValidProvince = true;
              }
            }
          }

          std::cout << "ENTER A CGPA (0 TO 4.3): ";
          std::cin >> createCGPA;

          while(std::cin.fail() || createCGPA < 0 || createCGPA > 4.3F) {
              std::cout << "ERROR: ENTER A CGPA (0 TO 4.3): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> createCGPA;
          }

          createCGPA = float(int(createCGPA * 10 + 0.5)) / 10;

          std::cout << "ENTER A researchScore (0 - 100): ";
          std::cin >> createResearchScore;

          while(std::cin.fail() || createResearchScore < 0 || createResearchScore > 100) {
              std::cout << "ERROR: ENTER A researchScore (0 - 100): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> createResearchScore;
          }

          domesticList.push(createFirstName, createLastName, createProvince, createCGPA, createResearchScore);
        } else if(domesticOperationInput == 6) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR firstName AND lastName TO REMOVE STARTED ..." << std::endl;

          std::string removeFirstName;
          std::string removeLastName;

          std::cout << "ENTER A firstName: ";
          std::cin >> removeFirstName;

          std::cout << "ENTER a lastName: ";
          std::cin >> removeLastName;

          domesticList.remove(removeFirstName, removeLastName);
        } else if(domesticOperationInput == 7) {
          std::cout << std::endl;
          std::cout << "REMOVAL OF head AND TAIL NODES STARTED ..." << std::endl;

          domesticList.removeEnds();
        } else if(domesticOperationInput == 8) {
          std::cout << std::endl;
          std::cout << "PRINTING OF domesticList STARTED ..." << std::endl;

          domesticList.print();
        } else if(domesticOperationInput == 9) {
          break;
        }
      }
    } else if(typeInput == 2) {
      while(true) {
        std::cout << std::endl;
        std::cout << "(INTERNATIONAL) PICK OPERATION:" << std::endl;
        std::cout << "1. SEARCH FOR applicationID" << std::endl;
        std::cout << "2. SEARCH FOR CGPA" << std::endl;
        std::cout << "3. SEARCH FOR researchScore" << std::endl;
        std::cout << "4. SEARCH FOR firstName AND lastName" << std::endl;
        std::cout << "5. CREATE NEW InternationalStudent NODE" << std::endl;
        std::cout << "6. REMOVE InternationalStudent NODE" << std::endl;
        std::cout << "7. REMOVE head AND tail NODES" << std::endl;
        std::cout << "8. PRINT internationaList" << std::endl;
        std::cout << "9. BACK TO STUDENT TYPE SELECTION" << std::endl;
        std::cout << "> ";

        int internationalOperationInput;

        std::cin >> internationalOperationInput;

        while(std::cin.fail() || internationalOperationInput < 1 || internationalOperationInput > 9) {
            std::cout << "ENTER A VALID OPTION (1 - 9) > ";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> internationalOperationInput;
        }

        if(internationalOperationInput == 1) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR applicationID STARTED ..." << std::endl;
          std::cout << "ENTER AN EIGHT DIGIT applicationID IN THE FORMAT (2021####): ";

          int searchApplicationID;

          std::cin >> searchApplicationID;

          while(std::cin.fail() || searchApplicationID < 20210000 || searchApplicationID > 20219999) {
              std::cout << "ERROR: ENTER AN EIGHT DIGIT applicationID IN THE FORMAT (2021####): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> searchApplicationID;
          }

          std::cout << "SEARCH RESULTS FOR applicationID " << searchApplicationID << ":" << std::endl;
          internationalList.searchApplicationID(searchApplicationID);
        } else if(internationalOperationInput == 2) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR CGPA STARTED ..." << std::endl;
          std::cout << "ENTER A CGPA IN THE FORMAT (#.#): ";

          float searchCGPA;

          std::cin >> searchCGPA;

          while(std::cin.fail() || searchCGPA < 0 || searchCGPA > 4.3F) {
              std::cout << "ERROR: ENTER A CGPA (0 TO 4.3): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> searchCGPA;
          }

          std:: cout << "SEARCH RESULTS FOR CGPA " << searchCGPA << ":" << std::endl;
          internationalList.searchCGPA(searchCGPA);
        } else if(internationalOperationInput == 3) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR researchScore STARTED ..." << std::endl;
          std::cout << "ENTER A researchScore (0 - 100): ";

          int searchResearchScore;

          std::cin >> searchResearchScore;

          while(std::cin.fail() || searchResearchScore < 0 || searchResearchScore > 100) {
              std::cout << "ERROR: ENTER A researchScore (0 - 100): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> searchResearchScore;
          }

          std:: cout << "SEARCH RESULTS FOR researchScore " << searchResearchScore << ":" << std::endl;
          internationalList.searchResearchScore(searchResearchScore);
        } else if(internationalOperationInput == 4) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR firstName AND lastName STARTED ..." << std::endl;

          std::string searchFirstName;
          std::string searchLastName;

          std::cout << "ENTER A firstName: ";

          std::cin >> searchFirstName;

          std::cout << "ENTER a lastName: ";

          std::cin >> searchLastName;

          std:: cout << "SEARCH RESULTS FOR " << searchFirstName << " " << searchLastName << ":" << std::endl;
          internationalList.searchFullName(searchFirstName, searchLastName);
        } else if(internationalOperationInput == 5) {
          std::cout << std::endl;
          std::cout << "CREATION FOR InternationalStudent NODE STARTED ..." << std::endl;

          std::string createFirstName;
          std::string createLastName;
          std::string createCountry;
          float createCGPA;
          int createResearchScore;

          std::cout << "ENTER A firstName: ";
          std::cin >> createFirstName;

          std::cout << "ENTER a lastName: ";
          std::cin >> createLastName;

          std::cout << "ENTER a country: ";
          std::cin >> createCountry;


          bool isValidCountry = false;

          for(int i = 0; i < 5; i++) {
            if(boost::algorithm::to_lower_copy(createCountry) == boost::algorithm::to_lower_copy(validCountries[i])) {
              isValidCountry = true;
            }
          }

          while(isValidCountry == false) {
            std::cout << "ENTER a valid country (Canada, China, India, Iran, Korea): ";
            std::cin >> createCountry;

            for(int i = 0; i < 5; i++) {
              if(boost::algorithm::to_lower_copy(createCountry) == boost::algorithm::to_lower_copy(validCountries[i])) {
                isValidCountry = true;
              }
            }
          }

          std::cout << "ENTER A CGPA (0 TO 4.3): ";
          std::cin >> createCGPA;

          while(std::cin.fail() || createCGPA < 0 || createCGPA > 4.3F) {
              std::cout << "ERROR: ENTER A CGPA (0 TO 4.3): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> createCGPA;
          }

          createCGPA = float(int(createCGPA * 10 + 0.5)) / 10;

          std::cout << "ENTER A researchScore (0 - 100): ";
          std::cin >> createResearchScore;

          while(std::cin.fail() || createResearchScore < 0 || createResearchScore > 100) {
              std::cout << "ERROR: ENTER A researchScore (0 - 100): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> createResearchScore;
          }

          int createReadingScore;
          int createListeningScore;
          int createSpeakingScore;
          int createWritingScore;
          int totalScore;

          std::cout << "ENTER TOEFL readingScore (0 - 30): ";
          std::cin >> createReadingScore;

          while(std::cin.fail() || createReadingScore < 0 || createReadingScore > 30) {
              std::cout << "ERROR: ENTER TOEFL readingScore (0 - 30): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> createReadingScore;
          }

          std::cout << "ENTER TOEFL listeningScore (0 - 30): ";
          std::cin >> createListeningScore;

          while(std::cin.fail() || createListeningScore < 0 || createListeningScore > 30) {
              std::cout << "ERROR: ENTER TOEFL listeningScore (0 - 30): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> createListeningScore;
          }

          std::cout << "ENTER TOEFL speakingScore (0 - 30): ";
          std::cin >> createSpeakingScore;

          while(std::cin.fail() || createSpeakingScore < 0 || createSpeakingScore > 30) {
              std::cout << "ERROR: ENTER TOEFL speakingScore (0 - 30): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> createSpeakingScore;
          }

          std::cout << "ENTER TOEFL writingScore (0 - 30): ";
          std::cin >> createWritingScore;

          while(std::cin.fail() || createWritingScore < 0 || createWritingScore > 30) {
              std::cout << "ERROR: ENTER TOEFL writingScore (0 - 30): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> createWritingScore;
          }

          totalScore = createReadingScore + createListeningScore + createSpeakingScore + createWritingScore;

          if(createReadingScore < 20 || createListeningScore < 20 || createSpeakingScore < 20 || createWritingScore < 20  || totalScore < 93) {

          } else {
            ToeflScore createToeflScore(createReadingScore, createListeningScore, createSpeakingScore, createWritingScore);

            internationalList.push(createFirstName, createLastName, createCountry, createCGPA, createResearchScore, createToeflScore);
          }
        } else if(internationalOperationInput == 6) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR firstName AND lastName TO REMOVE STARTED ..." << std::endl;

          std::string removeFirstName;
          std::string removeLastName;

          std::cout << "ENTER A firstName: ";
          std::cin >> removeFirstName;

          std::cout << "ENTER a lastName: ";
          std::cin >> removeLastName;

          internationalList.remove(removeFirstName, removeLastName);
        } else if(internationalOperationInput == 7) {
          std::cout << std::endl;
          std::cout << "REMOVAL OF head AND TAIL NODES STARTED ..." << std::endl;

          internationalList.removeEnds();
        } else if(internationalOperationInput == 8) {
          std::cout << std::endl;
          std::cout << "PRINTING OF internationalList STARTED ..." << std::endl;

          internationalList.print();
        } else if(internationalOperationInput == 9) {
          break;
        }
      }
    } else if(typeInput == 3) {
      StudentList studentList;

      DomesticStudent* domesticCurrent = domesticList.getHead();

      while(domesticCurrent != NULL) {
        std::string newFirstName = domesticCurrent->getFirstName();
        std::string newLastName = domesticCurrent->getLastName();
        float newCGPA = domesticCurrent->getCGPA();
        int newResearchScore = domesticCurrent->getResearchScore();

        try {
          Student* newStudent = new Student(newFirstName, newLastName, newCGPA, newResearchScore);
          studentList.push(newStudent);
        } catch(const std::bad_alloc &e) {
          std::cout << "Memory allocation failed: " << e.what() << std::endl;
          exit(1);
        }

        domesticCurrent = domesticCurrent->next;
      }

      InternationalStudent* internationalCurrent = internationalList.getHead();

      while(internationalCurrent != NULL) {
        std::string newFirstName = internationalCurrent->getFirstName();
        std::string newLastName = internationalCurrent->getLastName();
        float newCGPA = internationalCurrent->getCGPA();
        int newResearchScore = internationalCurrent->getResearchScore();

        try {
          Student* newStudent = new Student(newFirstName, newLastName, newCGPA, newResearchScore);
          studentList.push(newStudent);
        } catch(const std::bad_alloc &e) {
          std::cout << "Memory allocation failed: " << e.what() << std::endl;
        }

        internationalCurrent = internationalCurrent->next;
      }

      while(true) {
        std::cout << std::endl;
        std::cout << "(MERGED) PICK OPERATION:" << std::endl;
        std::cout << "1. SEARCH FOR applicationID" << std::endl;
        std::cout << "2. SEARCH FOR CGPA" << std::endl;
        std::cout << "3. SEARCH FOR researchScore" << std::endl;
        std::cout << "4. SEARCH FOR firstName AND lastName" << std::endl;
        std::cout << "5. CREATE NEW Student NODE" << std::endl;
        std::cout << "6. REMOVE Student NODE" << std::endl;
        std::cout << "7. REMOVE head AND tail NODES" << std::endl;
        std::cout << "8. PRINT studentList" << std::endl;
        std::cout << "9. PRINT ADMITTED STUDENTS" << std::endl;
        std::cout << "0. EXIT" << std::endl;
        std::cout << "> ";

        int studentOperationInput;

        std::cin >> studentOperationInput;

        while(std::cin.fail() || studentOperationInput < 0 || studentOperationInput > 9) {
            std::cout << "ENTER A VALID OPTION (0 - 9) > ";
            std::cin.clear();
            std::cin.ignore(256,'\n');
            std::cin >> studentOperationInput;
        }

        if(studentOperationInput == 1) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR applicationID STARTED ..." << std::endl;
          std::cout << "ENTER AN EIGHT DIGIT applicationID IN THE FORMAT (2021####): ";

          int searchApplicationID;

          std::cin >> searchApplicationID;

          while(std::cin.fail() || searchApplicationID < 20210000 || searchApplicationID > 20219999) {
              std::cout << "ERROR: ENTER AN EIGHT DIGIT applicationID IN THE FORMAT (2021####): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> searchApplicationID;
          }

          std::cout << "SEARCH RESULTS FOR applicationID " << searchApplicationID << ":" << std::endl;
          studentList.searchApplicationID(searchApplicationID);
        } else if(studentOperationInput == 2) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR CGPA STARTED ..." << std::endl;
          std::cout << "ENTER A CGPA IN THE FORMAT (#.#): ";

          float searchCGPA;

          std::cin >> searchCGPA;

          while(std::cin.fail() || searchCGPA < 0 || searchCGPA > 4.3F) {
              std::cout << "ERROR: ENTER A CGPA (0 TO 4.3): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> searchCGPA;
          }

          std:: cout << "SEARCH RESULTS FOR CGPA " << searchCGPA << ":" << std::endl;
          studentList.searchCGPA(searchCGPA);
        } else if(studentOperationInput == 3) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR researchScore STARTED ..." << std::endl;
          std::cout << "ENTER A researchScore (0 - 100): ";

          int searchResearchScore;

          std::cin >> searchResearchScore;

          while(std::cin.fail() || searchResearchScore < 0 || searchResearchScore > 100) {
              std::cout << "ERROR: ENTER A researchScore (0 - 100): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> searchResearchScore;
          }

          std:: cout << "SEARCH RESULTS FOR researchScore " << searchResearchScore << ":" << std::endl;
          studentList.searchResearchScore(searchResearchScore);
       } else if(studentOperationInput == 4) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR firstName AND lastName STARTED ..." << std::endl;

          std::string searchFirstName;
          std::string searchLastName;

          std::cout << "ENTER A firstName: ";

          std::cin >> searchFirstName;

          std::cout << "ENTER a lastName: ";

          std::cin >> searchLastName;

          std:: cout << "SEARCH RESULTS FOR " << searchFirstName << " " << searchLastName << ":" << std::endl;
          studentList.searchFullName(searchFirstName, searchLastName);
        } else if(studentOperationInput == 5) {
          std::cout << std::endl;
          std::cout << "CREATION FOR Student NODE STARTED ..." << std::endl;

          std::string createFirstName;
          std::string createLastName;
          float createCGPA;
          int createResearchScore;

          std::cout << "ENTER A firstName: ";
          std::cin >> createFirstName;

          std::cout << "ENTER a lastName: ";
          std::cin >> createLastName;

          std::cout << "ENTER A CGPA (0 TO 4.3): ";
          std::cin >> createCGPA;

          while(std::cin.fail() || createCGPA < 0 || createCGPA > 4.3F) {
              std::cout << "ERROR: ENTER A CGPA (0 TO 4.3): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> createCGPA;
          }

          createCGPA = float(int(createCGPA * 10 + 0.5)) / 10;

          std::cout << "ENTER A researchScore (0 - 100): ";
          std::cin >> createResearchScore;

          while(std::cin.fail() || createResearchScore < 0 || createResearchScore > 100) {
              std::cout << "ERROR: ENTER A researchScore (0 - 100): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> createResearchScore;
          }

          try {
            Student* newStudent = new Student(createFirstName, createLastName, createCGPA, createResearchScore);
            studentList.push(newStudent);
          } catch(const std::bad_alloc &e) {
            std::cout << "Memory allocation failed: " << e.what() << std::endl;
          }
        } else if(studentOperationInput == 6) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR firstName AND lastName TO REMOVE STARTED ..." << std::endl;

          std::string removeFirstName;
          std::string removeLastName;

          std::cout << "ENTER A firstName: ";
          std::cin >> removeFirstName;

          std::cout << "ENTER a lastName: ";
          std::cin >> removeLastName;

          studentList.remove(removeFirstName, removeLastName);
        } else if(studentOperationInput == 7) {
          std::cout << std::endl;
          std::cout << "REMOVAL OF head AND TAIL NODES STARTED ..." << std::endl;

          studentList.removeEnds();
        } else if(studentOperationInput == 8) {
          std::cout << std::endl;
          std::cout << "PRINTING OF studentList STARTED ..." << std::endl;

          studentList.print();
        } else if(studentOperationInput == 9) {
          std::cout << std::endl;
          std::cout << "SEARCH FOR ADMITTED STUDENTS STARTED ..." << std::endl;

          float CGPA_threshold;
          int researchScore_threshold;

          std::cout << "ENTER A CGPA THRESHOLD (0 TO 4.3): ";

          std::cin >> CGPA_threshold;

          while(std::cin.fail() || CGPA_threshold < 0 || CGPA_threshold > 4.3F) {
              std::cout << "ERROR: ENTER A CGPA THRESHOLD (0 TO 4.3): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> CGPA_threshold;
          }

          CGPA_threshold = float(int(CGPA_threshold * 10 + 0.5)) / 10;

          std::cout << "ENTER A researchScore THRESHOLD (0 TO 100): ";

          std::cin >> researchScore_threshold;

          while(std::cin.fail() || researchScore_threshold < 0 || researchScore_threshold > 100) {
              std::cout << "ERROR: ENTER A researchScore THRESHOLD (0 TO 100): ";
              std::cin.clear();
              std::cin.ignore(256,'\n');
              std::cin >> researchScore_threshold;
          }

          std::cout << std::endl << "SEARCH RESULTS FOR CGPA threshold of " << CGPA_threshold << " and researchScore threshold of " << researchScore_threshold << ":" << std::endl;
          studentList.searchAdmitted(CGPA_threshold, researchScore_threshold);
        } else if(studentOperationInput == 0) {
            std::cout << "EXITING ..." << std::endl;
            return;
        }
      }
    } else if(typeInput == 4) {
      std::cout << "EXITING ..." << std::endl;
      return;
    }
  }
}

// Populates a given list with domestic student data extracted from a given file.
void populateDomesticList(std::string file, DomesticList& list) {
  // Read file and exit application if file is unable to be read
  std::string line;
  std::ifstream domesticStudentsData(file);

  if(!domesticStudentsData.is_open()) {
    std::cout << "ERROR: Unable to open " << '\"' << file << "\"." << std::endl;

    return;
  }

  // Read/bypass first line of file as it is not data
  getline(domesticStudentsData, line);

  // Extract data from each line (with the help of istringstream)
  // Assume the format of the file is perfect and there is no need to handle errors and exceptions
  while(getline(domesticStudentsData, line)) {
    std::istringstream ss(line);

    // Counter to check if all variables hold data.
    int validCounter = 0;

    // Variables to hold data to be passed in constructing a DomesticStudent object
    std::string firstName;
    std::string lastName;
    std::string province;
    float CGPA;
    int researchScore;

    // Variables to hold extracted CGPA and researchScore data as strings
    std::string s_CGPA;
    std::string s_researchScore;

    // Extract firstName
    getline(ss, firstName, ',');
    if(firstName.length() > 0) {
      validCounter++;
    }

    // Extract lastName
    getline(ss, lastName, ',');
    if(lastName.length() > 0) {
      validCounter++;
    }

    // Extract province
    getline(ss, province, ',');
    if(province.length() > 0) {
      validCounter++;
    }

    bool isValidProvince = false;

    for(int i = 0; i < 13; i++) {
      if(province == validProvinces[i]) {
        isValidProvince = true;
      }
    }

    if(isValidProvince == false) {
      std::cout << "ERROR: " << province << " is not a valid province." << std::endl;
      exit(1);
    }

    // Extract CGPA
    getline(ss, s_CGPA, ',');
    if(s_CGPA.length() > 0) {
      validCounter++;
      CGPA = float(int(atof(s_CGPA.c_str()) * 10 + 0.5)) / 10;
    }

    // Extract researchScore
    getline(ss, s_researchScore, ',');
    if(s_researchScore.length() > 0) {
      validCounter++;
      researchScore = atoi(s_researchScore.c_str());
    }

    if(validCounter != 5) {
      std::cout << "ERROR: An input field of \"domestic-stu.txt\" is missing data." << std::endl;
      exit(1);
    }

    // Add domestic student to list.
    list.push(firstName, lastName, province, CGPA, researchScore);
  }

  // Close file
  domesticStudentsData.close();
}

// Populates a given list with international student data extracted from a given file.
void populateInternationalList(std::string file, InternationalList& list) {
  // Read file and exit application if file is unable to be read
  std::string line;
  std::ifstream internationalStudentsData(file);

  if(!internationalStudentsData.is_open()) {

    std::cout << "ERROR: Unable to open " << '\"' << file << '\"' << std::endl;

    return;
  }

  // Read/bypass first line of fileas it is not data
  getline(internationalStudentsData, line);

  // Extract data from each line (with the help of istringstream)
  // Assume the format of the file is perfect and there is no need to handle errors and exceptions
  int inputFieldNumber = 1;

  while(getline(internationalStudentsData, line)) {
    std::istringstream ss(line);

    // Counter to check if all variables hold data.
    int validCounter = 0;

    // Variables to hold data to be passed in constructing a DomesticStudent object
    std::string firstName;
    std::string lastName;
    std::string country;
    float CGPA;
    int researchScore;
    int readingScore;
    int listeningScore;
    int speakingScore;
    int writingScore;
    int totalScore;

    // Variables to hold extracted CGPA and researchScore data as strings
    std::string s_CGPA;
    std::string s_researchScore;
    std::string s_readingScore;
    std::string s_listeningScore;
    std::string s_speakingScore;
    std::string s_writingScore;

    // Extract firstName
    getline(ss, firstName, ',');
    if(firstName.length() > 0) {
      validCounter++;
    }

    // Extract lastName
    getline(ss, lastName, ',');
    if(lastName.length() > 0) {
      validCounter++;
    }

    // Extract country
    getline(ss, country, ',');
    if(country.length() > 0) {
      validCounter++;
    }

    // Extract CGPA
    getline(ss, s_CGPA, ',');
    if(s_CGPA.length() > 0) {
      validCounter++;
      CGPA = float(int(atof(s_CGPA.c_str()) * 10 + 0.5)) / 10;
    }

    // Extract researchScore
    getline(ss, s_researchScore, ',');
    if(s_researchScore.length() > 0) {
      validCounter++;
      researchScore = atoi(s_researchScore.c_str());
    }

    // Extract readingScore
    getline(ss, s_readingScore, ',');
    if(s_readingScore.length() > 0) {
      validCounter++;
      readingScore = atoi(s_readingScore.c_str());
    }

    // Extract listeningScore
    getline(ss, s_listeningScore, ',');
    if(s_listeningScore.length() > 0) {
      validCounter++;
      listeningScore = atoi(s_listeningScore.c_str());
    }

    // Extract speakingScore
    getline(ss, s_speakingScore, ',');
    if(s_speakingScore.length() > 0) {
      validCounter++;
      speakingScore = atoi(s_speakingScore.c_str());
    }

    // Extract writingScore
    getline(ss, s_writingScore, ',');
    if(s_writingScore.length() > 0) {
      validCounter++;
      writingScore = atoi(s_writingScore.c_str());
    }

    if(validCounter != 9) {
      std::cout << "ERROR: An input field of \"international-stu.txt\" is missing data." << std::endl;
      exit(1);
    }

    // Country input robust testing.
    bool validInitialCountry = false;

    for(int i = 0; i < 5; i++) {
      if(country == validCountries[i]) {
        validInitialCountry = true;
      }
    }

    if(validInitialCountry == true) {

    } else {
      // Country input standardization.
      std::vector<char> tempInput;
      std::string tempCountry = boost::algorithm::to_lower_copy(country);

      for(int i = 0; i < tempCountry.length(); i++) {
          tempInput.push_back(tempCountry[i]);
      }

      int indexOfLowestCharacter;

      for(int i = 0; i < tempInput.size(); i++) {
        indexOfLowestCharacter = i;

        for(int j = i + 1; j < tempInput.size(); j++) {
          if(tempInput[indexOfLowestCharacter] > tempInput[j]) {
            indexOfLowestCharacter = j;
          }
        }

        char temp = tempInput[i];
        tempInput[i] = tempInput[indexOfLowestCharacter];
        tempInput[indexOfLowestCharacter] = temp;
      }

      // Compare standardized country input with valid countries.
      bool validCountryFound = false;

      for(int i = 0; i < 5; i++) {
        std::vector<char> tempValid;
        std::string tempValidCountry = boost::algorithm::to_lower_copy(validCountries[i]);

        for(int k = 0; k < tempValidCountry.length(); k++) {
          tempValid.push_back(tempValidCountry[k]);
        }

        int indexOfValidLowestCharacter;

        for(int s = 0; s < tempValid.size(); s++) {
          indexOfValidLowestCharacter = s;

          for(int j = s + 1; j < tempValid.size(); j++) {
            if(tempValid[indexOfValidLowestCharacter] > tempValid[j]) {
              indexOfValidLowestCharacter = j;
            }
          }

          char temp = tempValid[s];
          tempValid[s] = tempValid[indexOfValidLowestCharacter];
          tempValid[indexOfValidLowestCharacter] = temp;
        }

        if(tempInput == tempValid) {
          country = validCountries[i];
          std::cout << "TYPO DETECTED FOR INPUT FIELD " << inputFieldNumber << " in \"international-stu.txt\": " << tempCountry << " auto-corrected to " << country << "." << std::endl;

          validCountryFound = true;
          break;
        }
      }

      if(validCountryFound == false) {
        std::cout << "ERROR: An input field of \"international-stu.txt\" contains an invalid country." << std::endl;
        exit(1);
      }
    }


    // Calculate total score of Toefl results
    totalScore = readingScore + listeningScore + speakingScore + writingScore;

    // Construct ToeflScore object if toefl score requirements are met
    if(readingScore < 20 || listeningScore < 20 || speakingScore < 20 || writingScore < 20 || totalScore < 93) {

    } else {
      ToeflScore toeflScore(readingScore, listeningScore, speakingScore, writingScore);
      list.push(firstName, lastName, country, CGPA, researchScore, toeflScore);
    }

    inputFieldNumber++;
  }

  internationalStudentsData.close();
}