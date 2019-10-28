sentence=input("Enter a sentence: ")
words=sentence.split(" ")
for i in words:
    if (set(i)!=list(i)):
     flag=1
if flag==1:
    print("Not Meta")
else:
    print("Meta")