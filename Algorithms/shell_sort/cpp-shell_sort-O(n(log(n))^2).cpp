#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <vector>

// This defines element data type.
using element_type = std::uint64_t;

///

using array_type = std::vector<element_type>;

array_type arr {};
array_type arr_gaps {};

template <typename InsertIt>
InsertIt gap_sequence(InsertIt it, element_type n)
{
    // For demonstration purposes, the following gap sequence is hard-coded:
    //
    //   4^k + 3 * 2^(k-1) + 1, prefixed with 1
    //
    // Credit: Sedgewick, 1982
    // Worst-case complexity: O(n^(4/3))

    element_type k { 0 };
    if (n > k) {
        *it++ = 1;
    }

    element_type next { 0 };
    for (k = 1; next < n; ++k) {
        // Use exponentiation trick: 4^k = (2^2)^k = 2^(2k) = 1 << (2k)
        next = (1 << (2 * k))
            + 3 * (1 << (k - 1))
            + 1;

        if (next < n) {
            *it++ = next;
        }
    }

    // Return iterator behind the last inserted element.
    return it;
}

void gapped_insert_sort(array_type& A, element_type gap)
{
    const array_type::iterator begin { A.begin() + gap };
    const array_type::iterator end { A.end() };

    array_type::iterator i, j;
    element_type temp;

    // The first gap elements A[0..(gap-1)] are already in gapped order.
    // Keep adding one more element until the whole array is sorted.
    for (i = begin; i != end; ++i) {
        // Save A[i] and make a hole at the position i.
        temp = *i;

        // Shift earlier gap-sorted elements up until the correct location for
        // A[i] is found.
        for (j = i; j >= begin && *(j - gap) > temp; std::advance(j, -gap)) {
            *j = *(j - gap);
        }

        // Put temp (the original A[i]) in its correct location.
        *j = temp;
    }
}

void shell_sort(array_type& A, array_type& gaps)
{
    using namespace std::placeholders;

    if (A.empty()) {
        // Trivial case.
        return;
    }

    // Manufacture a gap sequence of elements strictly lower than N.
    gap_sequence(std::back_inserter(gaps), A.size());

    // Enumerate the gap sequence in reverse (largest to smallest element).
    // Perform gapped insert sort for each gap.
    std::for_each(gaps.rbegin(), gaps.rend(), std::bind(gapped_insert_sort, std::ref(A), _1));
}

int main()
{
    // Read array size.
    std::size_t N {};
    std::cerr << "Enter number of elements of array : ";
    std::cin >> N;

    // Allocate memory dynamically.
    arr.resize(N);

    // Read array contents.
    std::cerr << std::endl
              << "Enter elements of array : ";
    std::for_each(arr.begin(), arr.end(),
        [&](element_type& val) {
            std::cin >> val;
        });

    // Sort the array.
    shell_sort(arr, arr_gaps);

    // Print the sorted array.
    std::for_each(arr.begin(), arr.end(),
        [](element_type val) {
            std::cerr << val << ' ';
        });
    std::cerr << std::endl;

    return 0;
}

