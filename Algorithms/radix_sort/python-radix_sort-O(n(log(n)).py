def radix_sort(input_list):
    '''
    This function will take list as input and return sorted list
    to understand this algorithm graphically kindly visit http://btechsmartclass.com/data_structures/radix-sort.html#targetText=Radix%20sort%20algorithm%20requires%20the,is%20sorted%20with%203%20passes.
    '''
    #finding length of maximum number in the list
    len_max_num=len(str(max(input_list)))
    len_list=len(input_list)
    index=0

    '''
    Define 10 key value buckets, each representing a bucket for each digit from 0 to 9. 
    '''
    countainer_dict={'0':[], '1':[], '2':[], '3':[], '4':[], '5':[], '6':[], '7':[], '8':[], '9':[]}

    output_list=input_list.copy()

    while(index!=len_max_num):
        #Insert each number into their respective queue based on the least significant digit
        for item in output_list:
            if (index+1)>len(str(item)):
                countainer_dict['0'].append(item)
            else:
                countainer_dict[str(item)[-(index+1)]].append(item)
    
        #group all the items in the buckets
        output_list=countainer_dict['0']+countainer_dict['1']+countainer_dict['2']+countainer_dict['3']+countainer_dict['4']+countainer_dict['5']+countainer_dict['6']+countainer_dict['7']+countainer_dict['8']+countainer_dict['9']
        countainer_dict={'0':[], '1':[], '2':[], '3':[], '4':[], '5':[], '6':[], '7':[], '8':[], '9':[]}
        index+=1

    return output_list


inp_list=[10000, 10, 12, 1, 100, 800, 6]

output=radix_sort(inp_list)
print(output)