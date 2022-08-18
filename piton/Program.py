def from_roman(num):
    roman_numerals = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
    result = 0
    for i,c in enumerate(num):
        if (i+1) == len(num) or roman_numerals[c] >= roman_numerals[num[i+1]]:
            result += roman_numerals[c]
        else:
            result -= roman_numerals[c]
    return result

print(str(from_roman("IVCM")))

#############################################

n = 4
a = [] 
for i in range(n):
  a.append([])
  a[i].append(1)
  for j in range(1, i):
    a[i].append(a[i - 1][j - 1] + a[i - 1][j])
  if(n != 0):
    a[i].append(1)
for i in range(n):
  print(" " * (n - i), end = " ", sep = " ")
  for j in range(0, i + 1):
    print('{0:0}'.format(a[i][j]), end = " ", sep = " ")
  print()

###########################################################

def reverse_integer(x):
  sign = -1 if x < 0 else 1
  x *= sign

  # Remove leading zero in the reversed integer
  while x:
    if x % 10 == 0:
      x /= 10
    else:
      break

    # string manipulation
  x = str(x)
  lst = list(x)  # list('234') returns ['2', '3', '4']
  lst.reverse()
  x = "".join(lst)
  x = int(x)
  return sign*x
    
print(reverse_integer(234))
#####################################
def Prime(n):  
    for i in range(2,n//2+1):  
        if(n%i==0):  
            return(0)  
    return(1)  
  
i=2 
lst=[] 
while(1):  
    if(Prime(i)):  
        lst.append(i) 
        if(len(lst)==80): 
            break 
    i+=1 
print("First 80 Prime numbers are:",end="") 
print(*lst) 

#################################################

from string import punctuation

s = "treee read feed twice four five"
c = 0
x = s.split()
t = s
print(len(s))

for i in x:
    if len(i) == 4:
      s = s.replace(i, "****")
      c+=1
print(c) 
print(s)



#######################################################################

def count_upper_case_letters(str_obj):
    count = 0
    for elem in str_obj:
        if elem.isupper():
            count += 1
    return count
r = input("Escribe la oracion para contar las letras mayusculas: ")
count = count_upper_case_letters(r)
print(count)

#######################################################

def replaceSpace():
  line = "  sdefrtgyhujimko,l       edrfgtyhujik ftgujik  gthyujik"
  for i in range(0,len(line)): 
    for i in range(0,len(line)):
      line = line.replace("  ", " ")
  print(line)

replaceSpace()

##############################################

def removeVowels():
  word = "beatttles"
  import collections
  vowels = ('a', 'e', 'i', 'o', 'u')
  mrw = str(collections.Counter(word).most_common(1)[0][0])
  for i in word:
    if i in vowels:
      word = word.replace(i, mrw)
  print(word) 

removeVowels()

##############################################

def indWords():

  s = input("write a sentence: ")
  x = s.split()
  for i in x:
    print(i)

indWords()