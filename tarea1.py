#Ejercicio1

print("Ejercicio1")

def verificarDiagonales(matriz):
    retornar = True
    for i in range(len(matriz)):
        if matriz[i][i] != matriz[i][len(matriz)- i - 1]:
            retornar = False
    return retornar


mat = [[11, 23, 76, 34,11],
[14,30, 92, 3,101],
[12, 45,58, 92, 22],
[74, 56, 49, 56, 100],
[99, 5, 28, 47, 99]]

print(verificarDiagonales(mat))


#Ejercicio 2

print("Ejercicio 2")
miLista = []

def esCapicua(lista):
    lista1 = []
    n = int(len(lista))
    c = int(len(lista)) - 1
    for i in range(n):
        lista1.append(lista[c])

        c -= 1
    if lista==lista1:
        return True
    else:
        return False;

print(esCapicua(input().split()))


#Ejercicio3

print("Ejercicio 3")

def diferenciaListas(listaA, listaB):
    listaReturn = []
    for i in range(len(listaA)):
        contador = 0
        for j in range(len(listaB)):
            if listaA[i] == listaB[j]:
                contador = 1
            if listaA[i] != listaB[j] and contador == 0:
                listaReturn.append(listaA[i])
                contador = 1
    return listaReturn

def crearList(recorrido):
    ffinalList = ""
    for j in range (recorrido):

        linea1 = input().split()
        linea2 = input().split()
        cant1 = int(linea1[0])
        cant2 = int(linea2[0])

        Lista1 = []
        Lista2 = []
        newList = []

        for i in range(1, cant1 + 1 ):
            Lista1.append(linea1[i])
        for i in range(1, cant2 + 1 ):
            Lista2.append(linea2[i])

        newList = diferenciaListas(Lista1, Lista2)

        finalList = ", ".join(newList)

        ffinalList += finalList + "\n"


    return ffinalList


print(crearList(int(input())))




#Ejercicio4

print("Ejercicio4")

def combrobarPrimos (n):
    resultado = True
    for i in range(2, int(n)):
        if n%i == 0:
            resultado = False
    return resultado            
            


def sumarValores(n):
    valor = 0
    for i in str(n):
        valor += int(i)
    return valor;

def crearCadena (n):
    numero = str(n)

    text1 = 'Números primos entre 1 y ' + numero + ':' + '\n'
    text2 = "Números entre 1 y " + numero + " con suma de dígitos con valor primo: "

    for i in range(1, n):

        if combrobarPrimos(i) == True:
            concatenar = str(i)
            text1 += '--> ' + concatenar + '\n'
            if combrobarPrimos(sumarValores(i)) == True:
                concatenar = str(i)
                text2 += concatenar + ", "

    comma = len(text2)
    print(text1)
    print(text2[0:comma-2])
crearCadena(100)


#Ejercicio5

print("Ejercicio5")

def transformarFuncion (mat):

    dic = {}
    mat[1][2]
    for i in range(len(mat)):
        contadorColuma = 0
        lista = []
        for j in range(len(mat[i])):
            if mat[i][j] != 0:
                tupla = (contadorColuma, mat[i][j])
                lista.append(tupla)
            contadorColuma += 1
            if lista:
                dic[i] = lista
    return dic 
matriz = [[1, 0, 0, 0, 0, 4, 0, 5],
[0, 0, 0, 0, 0, 0, 4, 7],
[2, 2, 0, 0, 9, 0, 1, 0],
[0, 0, 0, 0, 0, 0, 0, 0],
[0, 0, 8, 1, 0, 7, 0, 0],
[0, 0, 0, 0, 0, 0, 0, 0],
[3, 0, 0, 0, 0, 6, 0, 2],
[4, 4, 7, 0, 0, 0, 0, 0],
[0, 9, 0, 8, 0, 7, 0, 6]]

print(transformarFuncion(matriz))
disp = transformarFuncion(matriz)

def sumarValoresMatriz(matriz, parejas):
    suma = 0
    for i in range(len(parejas)):
            if matriz.get(parejas[i][0]) != None:
                for j in range(len(matriz[parejas[i][0]])):
                    if matriz[parejas[i][0]][j][0] == parejas[i][1]:
                        valor  = matriz[parejas[i][0]][j][1]
                        suma += valor
    return suma

print(sumarValoresMatriz(disp, [(0, 0), (8, 3), (3,5), (7, 2), (4, 3), (4,6)]))



