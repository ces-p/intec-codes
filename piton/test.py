def sort():
    a = [int(x) for x in input("esribe la lista: ").split()]
    menos = []
    mas = []
    igual = []
    if len(a) > 1:
        pivot = int(input("escribe el pivot: "))
        for x in a:
            if x < pivot:
                menos.append(x)
            elif x == pivot:
                igual.append(x)   
            elif x > pivot:
                mas.append(x)
        return menos+igual+mas  
    
    else:  
        return a

print(str(sort()))