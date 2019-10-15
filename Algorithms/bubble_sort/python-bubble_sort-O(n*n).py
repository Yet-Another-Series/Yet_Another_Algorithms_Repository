def bubble_sort(list): # sort in place and return it
    l = len(list)

    for i in range(l):
        swapped_el = False

        for j in range(0, l-i-1):
            if list[j] > list[j+1]:
                list[j], list[j+1] = list[j+1], list[j]
                swapped_el = True

        if not swapped_el:
            break
    return list

list = input('Enter a list of numbers separated by spaces: ').split()  
list = [int(x) for x in list]
print('Sorted list: {}'.format(bubble_sort(list)))
