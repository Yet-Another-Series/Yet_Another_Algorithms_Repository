def selection_sort(values):
    """Function to sort a list using Selection Sort method"""
    for position in range(0, len(values)):
    	current_key = values[position]
    	position_aux = position

    	position_smaller = position
    	for position_aux in range(position + 1, len(values)):
    		if values[position_aux] < values[position_smaller]:
    			position_smaller = position_aux

    	values[position] = values[position_smaller]
    	values[position_smaller] = current_key

    return(values)

input_values = list(map(int, input("Enter the unsorted list: ").split()))

# Function call
result = selection_sort(input_values)

print("Sorted List: {}".format(result))
