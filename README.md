# Student Admission Database System

**C++ | Object-oriented programming | Singly linked lists | File I/O | Applicant ranking**

An academic C++ console application developed for **ENSC 251** at Simon Fraser University. The project models graduate applicant records, maintains separate domestic and international applicant lists, and provides search, insertion, removal, ranking, and admissions-threshold operations. This is a historical student project, not a production admissions system.

## Architecture and data structures

![Class diagram showing inheritance and linked-list containers](media/1%20Student_Admission_Class_Diagram_Square.jpg)

*Class diagram (selected members and relationships; simplified for presentation).*

The `Student` base class stores applicant names, CGPA, research score, and an application identifier. `DomesticStudent` adds a province; `InternationalStudent` adds a country and a `ToeflScore` object. Separate `DomesticList` and `InternationalList` classes manage linked lists; `StudentList` represents the merged candidate collection.

![Domestic, international and merged singly linked list diagram](media/2%20Student_Admission_Linked_List_Diagram_Square.jpg)

*Illustrative linked-list structure and ranking; example applicant records are not a captured program execution.*

![Illustration of insertion sorting and middle-node removal](media/3%20Student_Admission_Insertion_Deletion_Example_Square.jpg)

*Illustrative list insertion, sorting, and deletion sequence.*

For implementation details see [System Design](docs/SYSTEM_DESIGN.md) and [Algorithms and Complexity](docs/ALGORITHMS_AND_COMPLEXITY.md).

## Implemented operations

- Load domestic and international applicant records from text files and assign application IDs.
- Search applicant records by application ID, CGPA, research score, or case-insensitive full name.
- Append, sort, remove by full name, and perform head/tail removal on applicant lists.
- Merge qualifying applicants into a combined list ordered primarily by research score and CGPA.
- Filter and print applicants against admission thresholds; apply TOEFL score requirements to international applicants.
- Validate selected inputs and provide interactive console menus.

The original coursework requirements and this historical implementation are distinct: see [Testing and Limitations](docs/TESTING_AND_LIMITATIONS.md) for gaps and caveats.

## Build and run

**Requirements:** a C++11-capable compiler, GNU Make, and Boost headers (`boost/algorithm/string.hpp`). On Linux, install your distribution's `g++`, `make`, and Boost development packages.

```bash
make
make run
```

The executable is `admission-system`. `make run` executes it from `data/`, where the original program expects `domestic-stu.txt` and `international-stu.txt` to be in its working directory. To run manually:

```bash
cd data
../admission-system
```

On Windows, a MinGW/MSYS2 environment with GNU Make, GCC, and Boost headers can be used. Compile output and runtime results depend on the installed toolchain.

## Repository layout

```text
student-admission-database-system/
├── README.md
├── Makefile
├── .gitignore
├── src/             # Eight original C++ translation units
├── include/         # Seven original class headers
├── data/            # Supplied coursework sample records
├── docs/            # Architecture, algorithms, testing notes
└── media/           # Three explanatory diagrams
```

## Scope and provenance

This repository preserves the supplied project implementation with its original algorithms and interfaces. The provided course assignment PDF is reference material and is not redistributed here. The example student records are coursework input data; **they are not intended to represent actual admissions decisions**. The diagrams are illustrative. No automated unit-test suite was supplied with these source files.

## Portfolio

**Hasan Fairuz** — Mechatronic Systems Engineering

[Engineering Portfolio](https://hasanfairuz.com/) · [GitHub Profile](https://github.com/HasanFairuz)
