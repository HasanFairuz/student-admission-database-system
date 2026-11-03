# Testing and Limitations

## Verification status

The repository includes historical C++ code and coursework input examples, but no self-contained unit-test suite or test transcript was provided. Running or compiling the program is not equivalent to validating all requested behaviors.

## Known engineering limitations

- The source relies on Boost's case-insensitive string helper and the presence of two input files at specific relative paths.
- Linked-list management uses raw pointers and manual deletion; ownership deserves careful scrutiny in particular around list copies, merge operations, empty lists, and pointer updates.
- The original list destructors are empty; there is no general RAII ownership model for allocated nodes.
- Input parsing depends on the legacy program's CSV-style assumptions rather than a dedicated CSV parser.
- Sorting performs nested-list comparisons, limiting scalability.
- Applicant records and ranking criteria are simplified as part of an academic exercise, not real admissions policy.
- Sample data files contain applicant-like names and should be treated only as supplied coursework examples.

## Suggested future regression cases

1. Empty, singleton, and multi-node list search/insertion/deletion.
2. Removal of a matching head and tail and consecutive matching nodes.
3. Ordering ties for research score, CGPA, and domestic/international rank.
4. Invalid records, missing fields, malformed numeric values and case variations.
5. TOEFL boundary thresholds and country typo correction.
6. Multiple menu interactions, merged-list operations and memory sanitizer checks.

Do not claim these tests passed unless actually executed and reviewed.
