string = input()
n = len(string)
count = 1
def checker(i):
    if i>len(string):print(count)
    if string[i] != string[i+1] :
        count += 1
    else:
            
        return checker(i+1)
    
for i in range(n):
    if string[i] == string[i+1] :
        count = 1


        