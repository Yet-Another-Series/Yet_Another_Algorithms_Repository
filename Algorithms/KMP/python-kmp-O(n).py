text = "aabaxbaaa"
pattern = "bax"

# Length of longest suffix ending at i that is also a prefix
def getLPSArray(pattern):
    j = 0
    i = 1
    LPS = [0]*len(pattern)
    while (i<len(pattern)):
        if (pattern[i] == pattern[j]):
            j += 1
            LPS[i] = j
            i += 1
        else:
            if (j == 0):
                LPS[i] = 0
                i += 1
            else:
                j = LPS[j-1]
    return LPS

# Returns The Location of pat(pattern) in the text
def KMP(text,pattern):
    l1 = len(text)
    l2 = len(pattern)
    i = 0
    j = 0
    k = 0
    LPS = getLPSArray(pattern)
    while (i < l1):
        if (text[i] == pattern[j]):
            i += 1
            j += 1
        else:
            if (j == 0):
                i += 1
            else:
                j = LPS[j-1]
        if (j == l2):
            return i-j
    return -1

location = KMP(text,pattern)
print(location)
