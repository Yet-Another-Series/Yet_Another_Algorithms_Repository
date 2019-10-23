def KMP(inputString, pattern): 
    patternLength = len(pattern) 
    inputTextLength = len(inputString) 
    existingMatchedString = [0]*patternLength 
    j = 0
	
    computeExistingMatchedString(pattern, patternLength, existingMatchedString) 
  
    i = 0
    while i < inputTextLength: 
        if pattern[j] == inputString[i]: 
            i += 1
            j += 1
  
        if j == patternLength: 
            print "Found pattern at index " + str(i-j) 
            j = existingMatchedString[j-1] 
  
        # mismatch after j matches 
        elif i < inputTextLength and pattern[j] != inputString[i]: 
            # Do not match existingMatchedString[0..existingMatchedString[j-1]] characters, 
            # they will match anyway 
            if j != 0: 
                j = existingMatchedString[j-1] 
            else: 
                i += 1
  
def computeExistingMatchedString(pattern, patternLength, existingMatchedString): 
    len = 0
    existingMatchedString[0]
    i = 1
    while i < patternLength: 
        if pattern[i]== pattern[len]: 
            len += 1
            existingMatchedString[i] = len
            i += 1
        else: 
            if len != 0: 
                len = existingMatchedString[len-1] 
            else: 
                existingMatchedString[i] = 0
                i += 1