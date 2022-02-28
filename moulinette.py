
from itertools import permutations
import os
import time
import subprocess
 
# Get all permutations of [1, 2, 3]
WARNING = '\033[93m'
ENDC = '\033[0m'
OKBLUE = '\033[94m'
perm = permutations([5, 6, 7, 10, 1])
string = ""
output = ""
badsort = 0
goodsort = 0
percent = 0
total = 0
maxInstruction = 0 
# Print the obtained permutations
for i in list(perm):
    length = 12
    for e in i:
        string += str(e) + " "
    print ("TEST : " + string)
    time.sleep(.2)
    os.system("./push_swap "+string)
    output = subprocess.check_output("./push_swap "+string+" | wc -l", shell=True)
    output = int(output)
    output = output
    if output > maxInstruction:
        maxInstruction = output 
    if length >= output:
        print(OKBLUE + "[*] Good sort" + ENDC)
        goodsort += 1
    else:
        print (WARNING + "[-] Bad Sort" + ENDC)
        badsort += 1
    print ("Number of insturction is " + str(output))
   
    time.sleep(.2)
    string = ""

total = (badsort + goodsort)
percent = (float(goodsort) / total) * 100

print ("\n")           
print ("Bad sort  : " + str(badsort))
print ("Good Sort : " + str(goodsort))
print ("The Max Number Instruction is "+str(maxInstruction))
print ("Sort Power is " + str(round(percent,2)) + "%")

