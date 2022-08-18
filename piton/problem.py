# def remove_duplicates(L): ####### 10.2
#     y = list(set(L))
#     print(str(y))

# remove_duplicates([43, 21, 1, 2, 2, 3, 4, 5, 5])

# def remove_duplicates2(L): ####### 10.3
#     sorted = False

#     while not sorted:
#         sorted = True
#         for i in range(len(L)-1):
#             if L[i] > L[i+1]:
#                 sorted = False
#                 L[i], L[i+1] = L[i+1], L[i]

#     y = list(set(L))
#     print(str(y))

# remove_duplicates2([4, 7, 36, 1, 2, 2, 3, 4, 5, 5])

# def binary_search(array, target): ####### 10.9
#     lower = 0
#     upper = len(array)
#     while lower < upper:   
#         x = lower + (upper - lower) // 2
#         val = array[x]
#         if target == val:
#             return x
#         elif target > val:
#             if lower == x:   
#                 break        
#             lower = x
#         elif target < val:
#             upper = x


# print(binary_search([1,2,3,4,5,6,7], 3))

# # la respuesta para la 10.5 es ins sort y la prueba esta en el codigo de abajo
# # def ins_sort(k):
# #     for i in range(1,3):    
# #         j = i                    
# #         temp = k[j]             
# #         while j > 0 and temp < k[j-1]: 
# #             k[j] = k[j-1] 
# #             j=j-1 
# #         k[j] = temp
# #     return k

# # print(ins_sort([47, 3, 21, 32, 56, 92]))


# def binary_search2(array, target): ####### 10.11
#     array = array[::-1]
#     lower = 0
#     upper = len(array)
#     while lower < upper:   
#         x = lower + (upper - lower) // 2
#         val = array[x]
#         if target == val:
#             return x
#         elif target > val:
#             if lower == x:   
#                 break        
#             lower = x
#         elif target < val:
#             upper = x


# print(binary_search2([9,8,7,6,5,4,3,2,1], 3))

# def bubbleSort():
#     day =   [0,2,1,0]
#     month = [7,4,9,1]
#     year =  [0,0,1,0]
#     sorted = False
#     while not sorted:
#         sorted = True
#         for i in range(len(day)-1):
#             if day[i] > day[i+1]:
#                 sorted = False
#                 year[i], year[i+1] = year[i+1], year[i]
#                 month[i], month[i+1] = month[i+1], month[i]
#                 day[i], day[i+1] = day[i+1], day[i]
#     sorted2 = False
#     while not sorted2:
#         sorted2 = True
#         for i in range(len(month)-1):
#             if month[i] > month[i+1]:
#                 sorted2 = False
#                 year[i], year[i+1] = year[i+1], year[i]
#                 month[i], month[i+1] = month[i+1], month[i]
#                 day[i], day[i+1] = day[i+1], day[i]
#     sorted3 = False
#     while not sorted3:
#         sorted3 = True
#         for i in range(len(year)-1):
#             if year[i] > year[i+1]:
#                 sorted3 = False
#                 year[i], year[i+1] = year[i+1], year[i]
#                 month[i], month[i+1] = month[i+1], month[i]
#                 day[i], day[i+1] = day[i+1], day[i]
#     for x in range(len(year)):
#         print(str(day[x])+str(month[x])+str(year[x]))
# bubbleSort()

# def tenTwo(a):
#     n = len(a)
#     sorted = False
#     while not sorted:
#         sorted = True
#         for i in range(len(a)-1):
#             if a[i] > a[i+1]:
#                 sorted = False
#                 a[i], a[i+1] = a[i+1], a[i]
#     print((sum(a[n//2-1:n//2+1])/2.0, a[n//2])[n % 2] if n else None)
# tenTwo([1,3,2,4,5])

# def tenOne():
#     source = [4,2,1,10,5,3,100]
#     for i in range(len(source)):
#         mini = min(source[i:]) 
#         min_index = source[i:].index(mini) 
#         source[i + min_index] = source[i] 
#         source[i] = mini                  
#     print(str(source))
# tenOne()

# def sequentialSearch(alist, item):
#     pos = 0
#     found = False

#     while pos < len(alist) and not found:
#         if alist[pos] == item:
#             found = True
#         else:
#             pos = pos + 1

#     return found

# def binSearch(list, target):
#     list.sort()
#     return binSearchHelper(list, target, 0, len(list) - 1)

# def binSearchHelper(list, target, left, right):
#     if left > right:
#         return False

#     middle = (left + right)//2
#     if list[middle] == target:
#         return True
#     elif list[middle] > target:
#         return binSearchHelper(list, target, left, middle - 1)
#     else:
#         return binSearchHelper(list, target, middle + 1, right)

# import random
# import time
# list_sizes = [2000, 500]
# for size in list_sizes:
#     list = []
#     for x in range(size):
#         list.append(random.randint(1,2000))

#     sequential_search_start_time = time.time()
#     sequentialSearch(list,-1)
#     sequential_search_end_time = time.time()
#     print("Time taken by linear search is = ",(sequential_search_end_time-sequential_search_start_time))

#     binary_search_start_time = time.time()
#     binSearch(list,-1)
#     binary_search_end_time = time.time()
#     print("Time taken by binary search is = ",(binary_search_end_time-binary_search_start_time))

#     print("\n")

# def diezSiete():
#     nombre =   ["pedro","juan","andres","tulio"]
#     ventas = [700,400,900,100]
#     anti =  [0,0,1,0]
#     sorted = False
#     while not sorted:
#         sorted = True
#         for i in range(len(ventas)-1):
#             if ventas[i] > ventas[i+1]:
#                 sorted = False
#                 ventas[i], ventas[i+1] = ventas[i+1], ventas[i]
#                 nombre[i], nombre[i+1] = nombre[i+1], nombre[i]
#                 anti[i], anti[i+1] = anti[i+1], anti[i]
        
#     for x in range(len(ventas)):
#         print("nombre: "+str(nombre[x])+"   ventas: "+str(ventas[x])+"  años de antiguedad: "+str(anti[x]))
# diezSiete()

def bubble(L): 
    sorted = False
    while not sorted:
        sorted = True
        for i in range(len(L)-1):
            if L[i] > L[i+1]:
                sorted = False
                L[i], L[i+1] = L[i+1], L[i]
 
def shellSort(arr):
    gap = len(arr) // 2 
    while gap > 0:
        i = 0
        j = gap
        while j < len(arr):   
            if arr[i] >arr[j]:
                arr[i],arr[j] = arr[j],arr[i]  
            i += 1
            j += 1
            k = i
            while k - gap > -1:
                if arr[k - gap] > arr[k]:
                    arr[k-gap],arr[k] = arr[k],arr[k-gap]
                k -= 1
        gap //= 2

def binSearch(list, target):
    list.sort()
    return binSearchHelper(list, target, 0, len(list) - 1)

def binSearchHelper(list, target, left, right):
    if left > right:
        return False

    middle = (left + right)//2
    if list[middle] == target:
        return True
    elif list[middle] > target:
        return binSearchHelper(list, target, left, middle - 1)
    else:
        return binSearchHelper(list, target, middle + 1, right)

import random
import time
array1 = []
array2 = []
for x in range(1,1000):
    array1.append(random.randint(1,2000))

binary_search_start_time = time.time()
binSearch(array1,-1)
binary_search_end_time = time.time()
print("Time taken by binary search is = ",(binary_search_end_time-binary_search_start_time))
print("\n")
bubble_start_time = time.time()
bubble(array1)
bubble_end_time = time.time()
print("Time taken to sort by bubble sort = ",(bubble_end_time-bubble_start_time))

shell_start_time = time.time()
shellSort(array1)
shell_end_time = time.time()
print("Time taken to sort by shell sort = ",(shell_end_time-shell_start_time))

start_time = time.time()
bubble(array1)
array1 = array1[::-1]
bubble(array1)
end_time = time.time()
print("Time taken to sort an inverse sorted list by bubble sort = ",(end_time-start_time))

print("\n")

for x in range(1,1000):
    array2.append(random.randint(1,2000))

bubble_start_time = time.time()
bubble(array2)
bubble_end_time = time.time()
print("Time taken to sort by bubble sort = ",(bubble_end_time-bubble_start_time))

shell_start_time = time.time()
shellSort(array2)
shell_end_time = time.time()
print("Time taken to sort by shell sort = ",(shell_end_time-shell_start_time))

start_time = time.time()
shellSort(array2)
array2 = array2[::-1]
shellSort(array2)
end_time = time.time()
print("Time taken to sort an inverse sorted list with shell sort = ",(end_time-start_time))

print("\n")

start_time = time.time()
shellSort(array2)
bubble(array2)
end_time = time.time()
print("Time taken to sort twice = ",(end_time-start_time))

print("\n")
