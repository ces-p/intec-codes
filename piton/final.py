# def anagramas():
#     lista_palabras = ["Alegan", "Truco", "Arbol", "Angela", "Riesgo","Trueno", "Pezcado","Sergio"]
#     sorteado = False
#     while not sorteado:
#         sorteado = True
#         for i in range(len(lista_palabras)-1):
#             if lista_palabras[i] > lista_palabras[i+1]:
#                 sorteado = False
#                 lista_palabras[i], lista_palabras[i+1] = lista_palabras[i+1], lista_palabras[i]
#     print(str(lista_palabras))
# anagramas()

# def busqueda_binaria(Listy, objetivo): 
#     menor = 0
#     mayor = sum(1 for int in Listy)
#     while menor < mayor:   
#         x = menor + (mayor - menor) // 2
#         val = Listy[x]
#         if objetivo == val:
#             return x
#         elif objetivo > val:
#             if menor == x: 
#                 return -1          
#             menor = x
#         elif objetivo < val:
#             mayor = x
    
# print(str(busqueda_binaria([1,2,3,4,5,6,7], 3)))

# def busqueda():
#     s = str(input("escriba la cadena que desea encontrar: "))
#     T = input("esribe la lista: ").split(',')
#     for i in range(len(T)):
#         if str(T[i]) == str(s):
#             print(str(i))
# busqueda()

# def permutaciones():
#     a = "utube"
#     b = "youtube"
#     if sorted(a) == sorted(b):
#         print("True")
#     else:
#         print("False")
# permutaciones()

def esSubstring(): 
    x = int(input())
    s1 = []
    s2 = []
    for i in range(x):
       s = input().split(" ")
    for i in range(len(s)):
        if(i%2 != 0):
            s1.append(s[i])
        if(i%2 == 0):
            s2.append(s[i])
    for j in range(len(s1)):
        if(len(s1) != len(s2)):
            print("no")
        elif(s1[j] in 2*s2[j]):
            print("si")
        else:
            print("no")

esSubstring()