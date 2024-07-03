### Explanation of the Solution

The "Allocate Minimum Number of Pages" problem can be solved using a combination of binary search and a greedy approach. Here's a step-by-step explanation:

1. **Problem Understanding**:
   - We are given an array of books, each with a certain number of pages.
   - We need to allocate these books to a given number of students such that the maximum number of pages assigned to any student is minimized.
   - Each student must be assigned at least one book, and books are allocated in a contiguous manner.

2. **Binary Search Setup**:
   - **Lower Bound** (`low`): The minimum possible value for the maximum pages any student has to read is the maximum number of pages in a single book. This is because every student must read at least one book.
   - **Upper Bound** (`high`): The maximum possible value is the total sum of all pages, which would be the case if only one student is assigned all the books.

3. **Feasibility Function**:
   - We create a helper function (`isPossible`) to check if it is possible to allocate books such that the maximum number of pages assigned to any student does not exceed a given value (`curr_min`).
   - This function iterates over the books and keeps a running sum of pages for the current student. If adding another book would exceed `curr_min`, we allocate the next student and reset the running sum.
   - If we end up needing more students than available, the function returns `false`.

4. **Binary Search Execution**:
   - We perform binary search on the range from `low` to `high`.
   - For each midpoint (`mid`) value, we use the feasibility function to check if it's possible to allocate books with that maximum number of pages. If feasible, we adjust the upper bound to `mid - 1` to try for a lower value. If not feasible, we adjust the lower bound to `mid + 1`.
   - The lowest value of `mid` for which the allocation is possible will be our answer.

### Summary

- **Binary Search**: We search for the minimum feasible maximum pages using binary search.
- **Feasibility Check**: The helper function checks if a given maximum page allocation is possible with the given number of students.
- **Optimization**: The solution ensures that we find the optimal (minimum possible maximum) page allocation.

This approach is efficient and ensures that the allocation of books minimizes the maximum pages assigned to any student.
