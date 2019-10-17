def insertion_sort(values):
    """Function to sort a list using Insertion Sort method"""
    for position in range(1, len(values)):
    	key = values[position]
    	position_aux = position

    	while position_aux > 0 and key < values[position_aux - 1]:
    		values[position_aux] = values[position_aux - 1]
    		position_aux -= 1

    	values[position_aux] = key

    return(values)

input_values = list(map(int, input("Enter the unsorted list: ").split()))

# Function call
result = insertion_sort(input_values)

print("Sorted List: {}".format(result))
