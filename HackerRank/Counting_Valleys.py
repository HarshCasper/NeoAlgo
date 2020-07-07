s = input()

count, alt = 0, 0

for i in s:
    if i == "U":
        # This condition will be true only when a person is coming from down and only 1 step away to climb which implies 
        # after this step it will climb the valley.
        if alt == -1:           
            count += 1
            
        alt += 1
    
    else:
        alt -= 1
    
print(count)