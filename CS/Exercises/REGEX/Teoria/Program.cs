/*Metacaracteres Básicos
 
. (punto): Coincide con cualquier carácter excepto el salto de línea.
Ejemplo: a.b coincidirá con "acb", "a-b", "a*b".

^ (caret): Indica el inicio de la cadena.
Ejemplo: ^abc coincidirá solo si "abc" es al inicio de la cadena.

$ (signo de dólar): Indica el final de la cadena.
Ejemplo: abc$ coincidirá solo si "abc" es al final de la cadena.

* (asterisco): Coincide con 0 o más repeticiones del elemento anterior.
Ejemplo: a*b coincidirá con "b", "ab", "aaab".

+ (más): Coincide con 1 o más repeticiones del elemento anterior.
Ejemplo: a+b coincidirá con "ab", "aab", "aaab".

? (interrogación): Coincide con 0 o 1 repetición del elemento anterior.
Ejemplo: a?b coincidirá con "b" o "ab".

| (barra vertical): Alternativa. Coincide con una u otra expresión.
Ejemplo: a|b coincidirá con "a" o con "b".

[] (corchetes): Define un conjunto de caracteres, como un rango.
Ejemplo: [a-z] coincide con cualquier letra minúscula.
Ejemplo: [aeiou] coincide con cualquier vocal.

() (paréntesis): Agrupa elementos en subexpresiones.
Ejemplo: (abc)+ coincide con "abc", "abcabc", etc.

{} (llaves): Define el número exacto o el rango de repeticiones de un patrón.
Ejemplo: a{2,4} coincidirá con "aa", "aaa", "aaaa".


Metacaracteres para Clases de Caracteres

\d: Coincide con un dígito (equivalente a [0-9]).
Ejemplo: \d{3} coincide con "123", "456", etc.

\D: Coincide con cualquier carácter que no sea un dígito.
Ejemplo: \D coincide con "a", "b", etc.

\w: Coincide con cualquier carácter alfanumérico o un guion bajo (equivalente a [a-zA-Z0-9_]).
Ejemplo: \w+ coincide con palabras como "hello", "abc123".

\W: Coincide con cualquier carácter que no sea alfanumérico ni guion bajo.
Ejemplo: \W+ coincide con caracteres especiales como !, @, #.

\s: Coincide con cualquier espacio en blanco (espacios, tabulaciones, saltos de línea).
Ejemplo: \s+ coincide con uno o más espacios.

\S: Coincide con cualquier carácter que no sea un espacio en blanco.
Ejemplo: \S+ coincide con "abc", "123", etc.



Metacaracteres para Posicionamiento

\b: Coincide con un límite de palabra (inicio o final de una palabra).
Ejemplo: \babc coincidirá con "abc" al inicio de una palabra, pero no en medio de una palabra como "zabc".

\B: Coincide con cualquier lugar que no sea un límite de palabra.
Ejemplo: a\Bb coincidirá con "abb", pero no con "aab".



Metacaracteres para Escapado y Control

\ (barra invertida): Escapa un carácter especial para tratarlo como literal.
Ejemplo: \\ coincide con una barra invertida.
Ejemplo: \. coincide con un punto literal.

\n: Coincide con un salto de línea (nueva línea).
Ejemplo: a\nb coincide con "a", seguido por un salto de línea, y luego "b".

\t: Coincide con una tabulación.
Ejemplo: a\tb coincide con "a", seguido de una tabulación, y luego "b".

\r: Coincide con un retorno de carro (en sistemas antiguos de Windows).
Ejemplo: a\r\nb coincide con un retorno de carro seguido de un salto de línea


Metacaracteres para Grupos y Rango

[^...]: Coincide con cualquier carácter que no esté dentro del conjunto
Ejemplo: [^0-9] coincide con cualquier carácter que no sea un dígito.

(?=...): Aseguramiento hacia adelante (positive lookahead). Coincide solo si la 
subexpresión dentro de (...) puede coincidir a continuación, sin consumir caracteres.
Ejemplo: \d(?=\D) coincidirá con un dígito solo si es seguido por un carácter no numérico.

(?!...): Aseguramiento hacia atrás (negative lookahead). Coincide solo si la subexpresión
dentro de (...) no puede coincidir a continuación.
Ejemplo: \d(?!\d) coincidirá con un dígito solo si no está seguido por otro dígito.*/