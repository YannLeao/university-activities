b = [1, 2, 3, 4]

# Exercicio 1
def somaLista(a):
    soma = 0
    for i in range(len(a)):
        soma += a[i]
    return soma

print(somaLista(b))

c = [1, 2, 3, 4, 5, 6]

# Exercicio 2
def contaPares(lista):
    contador = 0
    for i in range(len(lista)):
        if lista[i] % 2 == 0:
            contador += 1
    return contador

print(contaPares(c))

# Exercicio 3
def ehMaior(lista):
    return max(lista)

print(ehMaior(c))

# Exercicio 4
def contaMaior(lista, x):
    return len([i for i in lista if i > x])

print(contaMaior(c, 2))

# Exercicio 5
def somaPar(lista):
    return sum([i for i in lista if i % 2 == 0])

print(somaPar(c))

# Exercicio 6
def existeElemeto(lista, x):
    return x in lista

# Exercicio 7
def inverteLista(lista):
    result = []
    for i in range(len(lista)-1,-1, -1):
        result.append(lista[i])
    return result

print(inverteLista(c))

# Exercicio 8
def contaOcorr(lista, x):
    return len([i for i in lista if i == x])

# Exercicio 9
def somaPositivos(lista):
    return sum([i for i in lista if i > 0])

# Exercicio 10
def produtoElem(lista):
    prod = 1
    for i in lista:
        prod *= i
    return prod

# Exercicio 11
def contaVogal(string):
    return len([i for i in string if i.lower() in "aeiou"])

# Exercicio 12
def contaCaracteres(a):
    return len(a)

# Exercicio 13
def palindromo(a):
    a_formatado = a.lower()
    return a_formatado == a_formatado[::-1]

# Exercicio 14
def contCaracteres(string, a):
    return len([i for i in string if i == a])

# Exercicio 15
def substituirCaracteres(list, a, b):
    return list.replace(a, b)

# Exercicio 16
def maiusculasMinusculas(lista):
    maior = 0
    menor = 0

    for i in lista:
        if i.isUpper():
            maior += 1
        elif i.islower():
            menor += 1
    print(f"Maiúscula: {maior} | Minúcula: {menor}")

# Exercicio 17
def removeEspaco(a):
    return a.replace(" ", "")

# Exercicio 18
def primeiroCaractere(a):
    if not a:
        return None
    return a[0]