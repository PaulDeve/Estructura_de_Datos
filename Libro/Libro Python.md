# 📘 Índice

## I. Fundamentos del Lenguaje Python
- [I. Tipos de Datos, Variables y Constantes](#i-tipos-de-datos-variables-y-constantes)
- [II. Entrada y Salida de Datos](#ii-entrada-y-salida-de-datos)
- [III. Operadores](#iii-operadores)
- [IV. Estructuras de Control](#iv-estructuras-de-control)
- [V. Funciones](#v-funciones)

## II. Estructuras de Datos Lineales
- [VI. Listas (Lists)](#vi-listas-lists)
- [VII. Tuplas (Tuples)](#vii-tuplas-tuples)
- [VIII. Conjuntos (Sets)](#viii-conjuntos-sets)
- [IX. Diccionarios (Dictionaries)](#ix-diccionarios-dictionaries)
- [X. Pilas (Stacks)](#x-pilas-stacks)
- [XI. Colas (Queues)](#xi-colas-queues)
- [XII. Listas por Comprensión](#xii-listas-por-comprensión)

## III. Algoritmos y Estructuras Avanzadas
- [XIII. Recursión](#xiii-recursión)
- [XIV. Manipulación de Archivos](#xiv-manipulación-de-archivos)
- [XV. Programación Orientada a Objetos (POO)](#xv-programación-orientada-a-objetos-poo)
- [XVI. Árboles Binarios](#xvi-árboles-binarios)
- [XVII. Algoritmos de Búsqueda y Ordenamiento](#xvii-algoritmos-de-búsqueda-y-ordenamiento)

## IV. Buenas Prácticas y Aplicaciones
- [XVIII. Librerías Estándar en Python](#xviii-librerías-estándar-en-python)
- [XIX. Buenas Prácticas de Programación](#xix-buenas-prácticas-de-programación)
- [XX. Proyecto Final: Sistema de Gestión de Estudiantes](#xx-proyecto-final-sistema-de-gestión-de-estudiantes)



### I. Tipos de Datos, Variables y Constantes

En Python, los **tipos de datos** definen la naturaleza del valor que una variable puede almacenar. Python es un lenguaje de **tipado dinámico**, lo que significa que no es necesario declarar el tipo de variable; el intérprete lo detecta automáticamente.

Los **tipos primitivos** incluyen:

- `int`: números enteros  
- `float`: números decimales  
- `str`: cadenas de texto  
- `bool`: valores booleanos (True/False)

Las **variables** son identificadores que almacenan información. No requieren declaración previa ni tipo explícito.

Las **constantes**, aunque no existen como tal en Python, se definen por convención escribiendo el nombre en mayúsculas (ej. `PI = 3.14`).

**Piensa en esto:** * *

---

**Ejemplo:**
```python
entero = 10
flotante = 3.14
cadena = "Hola mundo"
booleano = True
```

**Explicación paso a paso:**

1. Se asignan distintos valores a variables.

2. El tipo se infiere automáticamente.

3. Python no requiere punto y coma ni tipo explícito.

***Resultado esperado en pantalla:***
```python
Hola Mundo

```
>***Nota: Python detecta automáticamente el tipo de datos, por lo tanto no requiere declarar el tipo explícitamente. ***

***Ideas Clave***
- Python es de tipado dinámico: no requiere declarar el tipo.

- Los nombres en mayúsculas se usan para simular constantes.

- Las variables pueden cambiar de tipo durante la ejecución.
  
**Practica 1**

> *Guardar tu nombre, edad y si eres estudiante.*

```python
nombre = "Ana"
edad = 21
es_estudiante = True
print(nombre, edad, es_estudiante)
```
**Practica 2**

> *Mostrar el tipo de cada variable usando type().*

```python
x = 7
y = 3.5
z = "Texto"
print(type(x), type(y), type(z))
```
**Conclusión**
Los tipos de datos, variables y constantes son la base de cualquier programa. En Python, esta base es flexible y muy accesible, lo que permite desarrollar de forma rápida y eficiente.

**Puntos Clave**
- Python permite programar sin preocuparse del tipo de dato desde el inicio.

- La claridad en nombres y valores hace más mantenible el código.

- Las constantes no existen como palabra clave, pero se simulan con mayúsculas.

**Reflexión Final**
Entender cómo se definen y usan los datos es entender cómo vive y se comporta la información dentro de un programa.
> *La flexibilidad de Python permite que los programadores se enfoquen en resolver problemas sin preocuparse por la sintaxis compleja de otros lenguajes.entrada y salida de datos (I/O) en Python permite que el usuario se comunique con el programa. La entrada se realiza comúnmente a través del teclado con input() y la salida a través de print().*

Estas funciones son esenciales para interactuar con el usuario, mostrar resultados o recibir instrucciones durante la ejecución del programa.

---

### II. Entrada y Salida de Datos
La entrada y salida de datos (I/O) en Python permite que el usuario se comunique con el programa. La entrada se realiza comúnmente a través del teclado con input() y la salida a través de print().

Estas funciones son esenciales para interactuar con el usuario, mostrar resultados o recibir instrucciones durante la ejecución del programa.

**Piensa en esto:** *Sin entrada ni salida, un programa es una caja cerrada. La comunicación con el usuario es el alma de las aplicaciones interactivas.*

**Ejemplo:**
```python
nombre = input("¿Cómo te llamas?: ")
print("Hola", nombre)

```

**Explicación paso a paso:**
input() detiene el programa y espera a que el usuario escriba algo.

Lo ingresado se guarda en la variable nombre.

print() se usa para mostrar el saludo por pantalla.

***Resultado esperado en pantalla:***
```python
¿Cómo te llamas?: Ana
Hola Ana

```
>***Nota: input() siempre devuelve una cadena. Convierte si necesitas otro tipo con int(), float(), etc.***


***Ideas Clave***
input() siempre devuelve una cadena (string), aunque se ingrese un número.

Es necesario convertir los datos si se requiere otro tipo (por ejemplo, int(input())).

print() puede mostrar variables, texto y resultados de expresiones.

print() admite múltiples argumentos separados por comas.

**Practica 1**

> *Pedir al usuario dos números y mostrar su suma.*

```python
a = int(input("Ingrese el primer número: "))
b = int(input("Ingrese el segundo número: "))
print("La suma es:", a + b)

```
**Practica 2**

> *Leer una edad y verificar si es mayor de edad.*

```python
edad = int(input("Ingrese su edad: "))
if edad >= 18:
    print("Mayor de edad")
else:
    print("Menor de edad")

```
**Conclusión**
El uso de input() y print() permite desarrollar programas interactivos. Aprender a gestionar adecuadamente la entrada y salida de datos es clave para cualquier aplicación que involucre al usuario.

**Puntos Clave**
input() siempre devuelve una cadena.

Se requiere conversión de tipos si se necesitan enteros o flotantes.

print() es muy versátil y permite mostrar múltiples valores.

**Reflexión Final**
Entrada y salida es la puerta de comunicación entre el usuario y el programa. Dominarla permite construir software que responde, pregunta y se adapta.

> *La flexibilidad de Python permite que los programadores se enfoquen en resolver problemas sin preocuparse por la sintaxis compleja de otros lenguajes.*

---

### III. Operadores

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**


---

### IV. Estructuras de Control

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**


---

### V. Funciones

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**


---

### VI. Listas (Lists)

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**


---

### VII. Tuplas (Tuples)

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**



**Puntos Clave**

**Reflexión Final**

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**


---

### IX. Diccionarios (Dictionaries)


**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**

### X. Pilas (Stacks)

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**

### XI. Colas (Queues)

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**

### XII. Listas por Comprensión

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**

### XIII. Recursión

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**

### XIV. Manipulación de Archivos

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**

### XV. Programación Orientada a Objetos (POO)

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**

### XVI. Árboles Binarios

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**

### XVII. Algoritmos de Búsqueda y Ordenamiento

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**

### XVIII. Librerías Estándar en Python

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**

### XIX. Buenas Prácticas de Programación

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**

### XX. Proyecto Final: Sistema de Gestión de Estudiantes

**Piensa en esto:** * *

**Ejemplo:**
```python

```

**Explicación paso a paso:**

***Resultado esperado en pantalla:***
```python


```
>***Nota: ***

***Ideas Clave***

**Practica 1**

> * *

```python

```
**Practica 2**

> * *

```python

```
**Conclusión**

**Puntos Clave**

**Reflexión Final**