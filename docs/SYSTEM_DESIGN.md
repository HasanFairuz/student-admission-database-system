# System Design

## Main components

| Class | Responsibility |
|---|---|
| `Student` | Common applicant fields and application-ID tracking |
| `DomesticStudent` | Domestic applicant with province |
| `InternationalStudent` | International applicant with country and TOEFL score |
| `ToeflScore` | Four TOEFL section scores and updated total |
| `DomesticList` | Singly linked list for domestic applicants |
| `InternationalList` | Singly linked list for international applicants |
| `StudentList` | Combined applicant linked list and searches |

`main.cpp` reads two input files and exposes operations via terminal menus. Student types inherit from `Student`; the international type contains a `ToeflScore`. Linked lists hold head, tail, size and `next` links rather than using `std::list`.

## Input format

- `data/domestic-stu.txt`: first name, last name, province, CGPA, research score.
- `data/international-stu.txt`: first name, last name, country, CGPA, research score, reading, listening, speaking, writing.

A header row is present in each supplied file. The source uses fixed relative filenames, so the working directory matters.

## Application behavior

Users choose domestic, international, or merged operations. List management includes searches, insertion, deletion, printing, and ranking. International TOEFL eligibility is evaluated when records are loaded, before subsequent merged-list operations. The implementation is a console demonstration and does not persist interactive changes back to disk.
