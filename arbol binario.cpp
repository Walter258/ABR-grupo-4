Algoritmo Insertar(raiz, nombre)
    Si raiz = -1 Entonces
        Crear nuevo nodo con nombre
        Retornar �ndice del nodo
    FinSi

    Si nombre < Arbol[raiz].nombre Entonces
        Arbol[raiz].izq ? Insertar(Arbol[raiz].izq, nombre)
    Sino Si nombre > Arbol[raiz].nombre Entonces
        Arbol[raiz].der ? Insertar(Arbol[raiz].der, nombre)
    Sino
        Escribir "Nombre duplicado"
    FinSi

    Retornar raiz
FinAlgoritmo
