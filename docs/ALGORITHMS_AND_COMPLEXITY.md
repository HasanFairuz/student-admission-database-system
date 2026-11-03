# Algorithms and Complexity

The linked-list implementation uses head/tail pointers and traversal. Insertion appends a node and then sorts the populated list with nested traversal rather than inserting it directly into the correct position. The implementation therefore differs from an optimal sorted insertion approach.

| Operation | Expected asymptotic work for n nodes |
|---|---|
| Append to an empty list | O(1) |
| Append and re-sort nonempty list | O(n²) |
| Linear search (ID, score, name) | O(n) |
| Remove matching record(s) by full name | O(n) for a traversal |
| Print list | O(n) |
| Re-sort existing list | O(n²) |

For the combined list, repeated calls to `StudentList::push` can lead to more work than a linear merge of two already sorted lists. Complexity and edge cases should be assessed against the exact source and build before relying on production-scale behavior.

The supplied `Big_O(1).txt` is an annotated coursework analysis document. It was used as reference, but omitted from the publication because this document provides a concise source-oriented summary.
