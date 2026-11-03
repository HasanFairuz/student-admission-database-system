#include "domesticlist.hpp"

/*
 * ----------------------------------------
 *                                        -
 * Singly Linked List Class - Domestic    -
 *                                        -
 * ----------------------------------------
 *
 * Singly linked list class to act as a
 * container for DomesticStudent class
 * objects.
 */

// [ Constructor(s) ]

// Main constructor.
DomesticList::DomesticList() {
    size = 0;
    head = NULL;
    tail = NULL;
}

// [ Destructor(s) ]

// Main destructor.
DomesticList::~DomesticList() {

}

// [ Getter(s) ]

// Get size.
int DomesticList::getSize() {
    return size;
}

// Get head.
DomesticStudent* DomesticList::getHead() {
    return head;
}

// Get tail.
DomesticStudent* DomesticList::getTail() {
    return tail;
}

// [ Function(s) ]

// Adds a new DomesticStudent object into the list while maintaining overall sort
// order.
void DomesticList::push(std::string firstName, std::string lastName, std::string province, float CGPA, int researchScore) {
    try {
        // Dynamically allocate a new DomesticStudent object.
        DomesticStudent* newDomesticStudent = new DomesticStudent(firstName, lastName, province, CGPA, researchScore);
        newDomesticStudent->next = NULL;

        // If list is empty, make the new node the head node;
        // if not, add the new node to end.
        if(head == NULL) {
            head = newDomesticStudent;
            tail = newDomesticStudent;
        } else {
            tail->next = newDomesticStudent;
            tail = newDomesticStudent;
            sort();
        }

        size++;
    } catch(const std::bad_alloc& e) {
        std::cout << "Memory allocation failed: " << e.what() << std::endl;
        exit(1);
    }
}

// Prints all the domestic students in the list.
void DomesticList::print() {
    DomesticStudent* current = head;

    if(head == NULL) {
        std::cout << "List of domestic students is empty." << std::endl;
        exit(1);
    }

    while(current != NULL) {
        std::cout << *current << std::endl;
        current = current->next;
    }
}

// Prints all domestic students that match user-inputted applicationID.
void DomesticList::searchApplicationID(int applicationID) {
    if(head == NULL) {
        std::cout << "List of domestic students is empty." << std::endl;
    } else {
        bool atLeastOneFound = false;

        DomesticStudent* current = head;

        while(current != NULL) {
            if(applicationID == current->getApplicationId()) {
                atLeastOneFound = true;

                std::cout << *current << std::endl;
            }

            current = current->next;
        }

        if(atLeastOneFound == false) {
            std::cout << "No match found." << std::endl;
        }
    }
}

// Prints all domestic students that match user-inputted CGPA.
void DomesticList::searchCGPA(float CGPA) {
    if(head == NULL) {
        std::cout << "List of domestic students is empty." << std::endl;
    } else {
        bool atLeastOneFound = false;

        DomesticStudent* current = head;

        while(current != NULL) {
            if(CGPA == current->getCGPA()) {
                atLeastOneFound = true;

                std::cout << *current << std::endl;
            }

            current = current->next;
        }

        if(atLeastOneFound == false) {
            std::cout << "No match found." << std::endl;
        }
    }
}

// Prints all domestic students that match user-inputted researchScore.
void DomesticList::searchResearchScore(int researchScore) {
    if(head == NULL) {
        std::cout << "List of domestic students is empty." << std::endl;
    } else {
        bool atLeastOneFound = false;

        DomesticStudent* current = head;

        while(current != NULL) {
            if(researchScore == current->getResearchScore()) {
                atLeastOneFound = true;

                std::cout << *current << std::endl;
            }

            current = current->next;
        }

        if(atLeastOneFound == false) {
            std::cout << "No match found." << std::endl;
        }
    }
}

// Prints all domestic students that match user-inputted firstName and lastName.
void DomesticList::searchFullName(std::string firstName, std::string lastName) {
    if(head == NULL) {
        std::cout << "List of domestic students is empty." << std::endl;
    } else {
        bool atLeastOneFound = false;

        DomesticStudent* current = head;

        while(current != NULL) {
            if(boost::algorithm::to_lower_copy(firstName) == boost::algorithm::to_lower_copy(current->getFirstName())
               &&
               boost::algorithm::to_lower_copy(lastName) == boost::algorithm::to_lower_copy(current->getLastName())) {

                atLeastOneFound = true;

                std::cout << *current << std::endl;
            }

            current = current->next;
        }

        if(atLeastOneFound == false) {
            std::cout << "No match found." << std::endl;
        }
    }
}

// Removes all domestic students that match user-inputted firstName and lastName.
void DomesticList::remove(std::string firstName, std::string lastName) {
    DomesticStudent* current = head;
    DomesticStudent* lag = head;
    bool atLeastOneFound = false;

    if (current == NULL) {
        std::cout << "List of domestic students is empty." << std::endl;
    } else{
        while(current != NULL) {
            firstName = boost::algorithm::to_lower_copy(firstName);
            lastName = boost::algorithm::to_lower_copy(lastName);
            std::string currentFirstName = boost::algorithm::to_lower_copy(current->getFirstName());
            std::string currentLastName = boost::algorithm::to_lower_copy(current->getLastName());

            if (current == head) {
                if(currentFirstName == firstName && currentLastName == lastName) {
                    std::cout << current->getApplicationId() << " " << current->getFirstName() << " " << current->getLastName() << " has been removed." << std::endl;

                    head = current->next;
                    delete current;
                    current = head;
                    lag = head;

                    atLeastOneFound = true;
                    size--;
                }

                current = current->next;
            } else if(current == tail) {
                if(currentFirstName == firstName && currentLastName == lastName) {
                    std::cout << current->getApplicationId() << " " << current->getFirstName() << " " << current->getLastName() << " has been removed." << std::endl;

                    tail = lag;
                    tail->next = NULL;
                    delete current;
                    current = NULL;

                    atLeastOneFound = true;
                    size--;
                } else {
                    current = current->next;
                    lag = lag->next;
                }

            } else{
                if(currentFirstName == firstName && currentLastName == lastName) {
                    std::cout << current->getApplicationId() << " " << current->getFirstName() << " " << current->getLastName() << " has been removed." << std::endl;

                    lag->next = NULL;
                    lag->next = current->next;
                    delete current;
                    current = lag->next;

                    atLeastOneFound = true;
                    size--;
                } else {
                    lag = lag->next;
                    current = current->next;
                }
            }
        }
    }

    if(atLeastOneFound == false) {
        std::cout << firstName << " " << lastName << " does not exist." << std::endl;
    }
}

// Removes head and tail nodes.
void DomesticList::removeEnds() {
    if(head == NULL) {
        std::cout << "List of domestic students is empty." << std::endl;
    } else {
        if(size == 1) {
            DomesticStudent* headAndTail = head;
            std::cout << "(head & tail) " << headAndTail->getApplicationId() << " " << headAndTail->getFirstName() << " " <<  headAndTail->getLastName() << " has been removed." << std::endl;

            delete headAndTail;

            head = NULL;
            tail = NULL;

            size--;
        } else if(size == 2) {
            DomesticStudent* tempHead = head;
            std::cout << "(head) " << tempHead->getApplicationId() << " " << tempHead->getFirstName() << " " << tempHead->getLastName() << " has been removed." << std::endl;

            delete tempHead;
            head = NULL;

            DomesticStudent* tempTail = tail;
            std::cout << "(tail) " << tempTail->getApplicationId() << " " << tempTail->getFirstName() << " " << tempTail->getLastName() << " has been removed." << std::endl;

            delete tempTail;
            tail = NULL;

            size -= 2;
        } else {
            DomesticStudent* tempHead = head;
            std::cout << "(head) " << tempHead->getApplicationId() << " " << tempHead->getFirstName() << " " << tempHead->getLastName() << " has been removed." << std::endl;

            head = tempHead->next;
            delete tempHead;

            DomesticStudent* tempTail = head;

            while(tempTail->next->next != NULL) {
                tempTail = tempTail->next;
            }

            std::cout << "(tail) " << tempTail->next->getApplicationId() << " " << tempTail->next->getFirstName() << " " << tempTail->next->getLastName() << " has been removed." << std::endl;

            tail = tempTail;
            delete tail->next;
            tail->next = NULL;

            size -= 2;
        }
    }
}

// [ Utility Function(s) ]

// Sorts list with overall sorting scheme.
void DomesticList::sort() {

    DomesticStudent* pointerToHighestOverall = NULL;

    DomesticStudent* traverse = head;
    DomesticStudent* current = NULL;

    // Data to swap.
    int tempApplicationID;
    std::string tempFirstName;
    std::string tempLastName;
    std::string tempProvince;
    float tempCGPA;
    int tempResearchScore;

    if(head == NULL) {
        return;
    } else {
        while(traverse != NULL) {
            pointerToHighestOverall = traverse;
            current = traverse->next;

            while(current != NULL) {
                if(compareResearchScore(*traverse, *current) == -1) {
                    pointerToHighestOverall = current;
                } else if(compareResearchScore(*traverse, *current) == 0) {
                    if(compareCGPA(*traverse, *current) == -1) {
                        pointerToHighestOverall = current;
                    } else if(compareCGPA(*traverse, *current) == 0) {
                        if(compareProvince(*traverse, *current) == 1) {
                            pointerToHighestOverall = current;
                        }
                    }
                }

                // Iterate inner-level node.
                current = current->next;
            }

            // Swap.
            tempApplicationID = traverse->getApplicationId();
            tempFirstName = traverse->getFirstName();
            tempLastName = traverse->getLastName();
            tempProvince = traverse->getProvince();
            tempCGPA = traverse->getCGPA();
            tempResearchScore = traverse->getResearchScore();

            traverse->setApplicationId(pointerToHighestOverall->getApplicationId());
            traverse->setFirstName(pointerToHighestOverall->getFirstName());
            traverse->setLastName(pointerToHighestOverall->getLastName());
            traverse->setProvince(pointerToHighestOverall->getProvince());
            traverse->setCGPA(pointerToHighestOverall->getCGPA());
            traverse->setResearchScore(pointerToHighestOverall->getResearchScore());

            pointerToHighestOverall->setApplicationId(tempApplicationID);
            pointerToHighestOverall->setFirstName(tempFirstName);
            pointerToHighestOverall->setLastName(tempLastName);
            pointerToHighestOverall->setProvince(tempProvince);
            pointerToHighestOverall->setCGPA(tempCGPA);
            pointerToHighestOverall->setResearchScore(tempResearchScore);

            // Iterate outer-level node.
            traverse = traverse->next;
        }
    }
}