#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

// This defines element data type.
using element_type = std::uint64_t;

// This defines element bit (binary digit) count.
static constexpr int ELEMENT_DIGITS = 64;

///

using array_type = std::vector<element_type>;

array_type arr {};
array_type arr_aux {};

array_type& radixSort(array_type& A, array_type& B) {
    element_type mask {1};

    // Iterate from the least significant bit to the most significant bit.
    // Update the bit mask as we go.
    for (int digit = 0; digit < ELEMENT_DIGITS; ++digit, mask <<= 1) {
        // In each cycle, we copy array from A to B.
        B.clear();

        // Scan source array two times: first for 0, then for 1.
        // Move items with the matching digits into their corresponding bucket.
        std::copy_if(A.begin(), A.end(), std::back_inserter(B),
                [&](const element_type val) {
                    return (val & mask) == 0;
                });
        std::copy_if(A.begin(), A.end(), std::back_inserter(B),
                [&](const element_type val) {
                    return (val & mask) > 0;
                });

        // At this point, the target array becomes the new source array.
        std::swap(A, B);
    }

    // Return whichever of the two arrays becomes source at the end.
    return A;
}

int main() {
    // Read array size.
    std::size_t N {};
    std::cerr << "Enter number of elements of array : ";
    std::cin >> N;

    // Allocate memory dynamically.
    arr.resize(N);
    arr_aux.reserve(N);

    // Read array contents.
    std::cerr << std::endl << "Enter elements of array : ";
    std::for_each(arr.begin(), arr.end(),
            [&](element_type& val) {
                std::cin >> val;
            });

    // Sort the array.
    const array_type& arr_out { radixSort(arr, arr_aux) };

    // Print the sorted array.
    std::for_each(arr_out.begin(), arr_out.end(),
            [](element_type val) {
                std::cerr << val << ' ';
            });
    std::cerr << std::endl;

    return 0;
}

