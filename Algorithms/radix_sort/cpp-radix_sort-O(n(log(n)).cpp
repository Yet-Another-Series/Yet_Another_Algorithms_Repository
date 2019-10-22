#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

//templates used to allow most containers to be used, as long as they contain only integral types 
// (short, long, int, etc)
template <typename RandomIterator>
void radixSort(RandomIterator first, RandomIterator last, int bucket_count)
{
	if (first == last)
		return;

	typedef typename std::iterator_traits<RandomIterator>::value_type ValueType;
	static_assert(std::is_integral<ValueType>::value,
		"container can only have integral types ");

	ValueType maxValue = *(std::max_element(first, last));
	ValueType div{};
	std::vector<std::vector<ValueType>> buckets(bucket_count);

	ValueType i = 1;
	while (maxValue != 0)
	{
		// move elements into the correct buckets
		for (RandomIterator iterator = first; iterator != last; ++iterator)
		{
			ValueType num = *iterator;
			if (num < 0)
				throw std::domain_error("container cannot contain negative values ");

			ValueType remainder = (num / i) % 10;
			buckets[remainder].push_back(num);
		}

		// move from bucket to the beginning array
		RandomIterator iterator = first;
		for (auto& bucket : buckets)
		{
			for (auto value : bucket)
			{
				*iterator = value;
				++iterator;
			}
			bucket.clear();
		}

		maxValue /= 10;
		i *= 10;
	}
}

/// <param name="container">The container that contains your list of elements of INTEGRAL TYPE. Can be short, long, int, etc.</param>
/// 
/// Use this function for implementation, the function is overloaded and will use the 
/// correct function definition based on the parameters passed
template <typename IntegralTypeContainer>
void radixSort(IntegralTypeContainer& container, int bucket_count)
{
	radixSort(std::begin(container), std::end(container), bucket_count);
}

template <typename IntegralTypeContainer>
void generateRandomVector(IntegralTypeContainer& input_array, int array_size) {
	for (size_t i = 0; i < array_size; ++i) {
		input_array.push_back(rand() % 10000);
	}
}

template <typename IntegralTypeContainer>
void copyVector(std::vector<IntegralTypeContainer>& array_to_copy, std::vector<IntegralTypeContainer>& array_to_copy_to)
{
	for (auto elem : array_to_copy)
	{
		array_to_copy_to.push_back(elem);
	}
}



int main()
{
	std::vector<unsigned long> unsorted_array;
	std::vector<unsigned long> pre_sorted_array;
	generateRandomVector(unsorted_array, 10);
	copyVector(unsorted_array, pre_sorted_array);
	std::sort(pre_sorted_array.begin(), pre_sorted_array.end());
	radixSort(unsorted_array, 10);

	const bool test_passed = (unsorted_array == pre_sorted_array);
	std::cout << "test " << (test_passed ? "passed\n" : "failed\n");

	return 0;
}
