# Trabajo Practico No. 3 - Estructuras Dinamicas en C++

**Asignatura:** Programacion Avanzada  
**Profesor:** M.Sc. Mauro Baquero-Suarez  
**Programa:** Ingenieria Mecatronica  
**Fecha de Entrega:** 4 de Diciembre de 2025

## Integrantes

- Juan David Jaimes Rebolledo
- Sebastian Camilo Nova Ovallos
- Yeison David Mejia Mosquera

## Descripcion General

Este repositorio contiene la implementacion de 3 ejercicios avanzados sobre estructuras de datos dinamicas en C++. El proyecto demuestra el uso de listas enlazadas simples y dobles para resolver problemas reales de almacenamiento, procesamiento de senales biomedicas y seguimiento de eventos en juegos.

## Estructura del Proyecto

```
TP_03_ED/
├── README.md
├── ejercicio1_listado/         
│   ├── Estudiante.h
│   ├── Estudiante.cpp
│   ├── ListadoEstudiantil.h
│   ├── ListadoEstudiantil.cpp
│   ├── main.cpp
│   └── Makefile
├── ejercicio2_ecg/             
│   ├── SenalECG.h
│   ├── SenalECG.cpp
│   ├── main.cpp
│   ├── Makefile
│   └── ECG.txt
└── ejercicio3_domino_historial/ 
    ├── Ficha.h
    ├── Ficha.cpp
    ├── Jugador.h
    ├── Jugador.cpp
    ├── Movimiento.h
    ├── Movimiento.cpp
    ├── JuegoDomino.h
    ├── JuegoDomino.cpp
    ├── main.cpp
    └── Makefile
```

## Requisitos del Sistema

### Software Necesario
- Compilador C++ compatible con C++11 o superior (g++, clang++, MSVC)
- Make (opcional)
- Git para control de versiones

### Sistemas Operativos Soportados
- Linux (Ubuntu, Debian, Fedora, etc.)
- macOS
- Windows (con MinGW o WSL)

## Compilacion y Ejecucion

### Compilacion en Windows

**Ejercicio 1:**
```cmd
cd ejercicio1_listado
g++ -std=c++11 -Wall -c main.cpp
g++ -std=c++11 -Wall -c Estudiante.cpp
g++ -std=c++11 -Wall -c ListadoEstudiantil.cpp
g++ -std=c++11 -Wall -o listado.exe main.o Estudiante.o ListadoEstudiantil.o
listado.exe
```

**Ejercicio 2:**
```cmd
cd ejercicio2_ecg
g++ -std=c++11 -Wall -c main.cpp
g++ -std=c++11 -Wall -c SenalECG.cpp
g++ -std=c++11 -Wall -o ecg.exe main.o SenalECG.o
ecg.exe
```

**Ejercicio 3:**
```cmd
cd ejercicio3_domino_historial
g++ -std=c++11 -Wall -c main.cpp
g++ -std=c++11 -Wall -c Ficha.cpp
g++ -std=c++11 -Wall -c Jugador.cpp
g++ -std=c++11 -Wall -c Movimiento.cpp
g++ -std=c++11 -Wall -c JuegoDomino.cpp
g++ -std=c++11 -Wall -o domino.exe main.o Ficha.o Jugador.o Movimiento.o JuegoDomino.o
domino.exe
```

### Compilacion en Linux/macOS

Para cada ejercicio:
```bash
cd ejercicioX
make
./ejecutable
```

## Descripcion Detallada de los Ejercicios

### Ejercicio 1: Listado Estudiantil (25%)

**Descripcion:** Sistema de gestion de estudiantes utilizando lista enlazada simple con todas las operaciones basicas y avanzadas.

**Caracteristicas Implementadas:**

**Clase Estudiante:**
- Almacena informacion completa del estudiante
- Campos: nombre completo, ano de nacimiento, numero de identificacion, promedio academico, email
- Metodo `toString()` para formato legible

**Clase ListadoEstudiantil (Lista Enlazada Simple):**
- Constructor que inicializa lista vacia
- Insercion al final de la lista
- Eliminacion por ID especifico
- Busqueda por ID que retorna posicion
- Impresion completa en archivo .txt
- Destructor con liberacion correcta de memoria
- Sobrecarga del operador [] para acceso directo por indice
- Metodo para invertir completamente la lista

**Estructura de Datos:**
```
Nodo -> [Estudiante | siguiente*] -> [Estudiante | siguiente*] -> NULL
```

**Metodologia:**

**Insercion al Final:**
Recorre la lista hasta encontrar el ultimo nodo (siguiente == nullptr) y agrega el nuevo nodo ahi. Complejidad: O(n).

**Eliminacion:**
Busca el nodo con el ID especifico. Si es la cabeza, actualiza cabeza. Si esta en medio, ajusta punteros del nodo anterior para saltar el nodo a eliminar. Libera memoria del nodo eliminado. Complejidad: O(n).

**Busqueda:**
Recorre la lista secuencialmente comparando IDs. Retorna la posicion (indice) si encuentra, -1 si no existe. Complejidad: O(n).

**Inversion:**
Usa tres punteros (anterior, actual, siguiente) para invertir todos los enlaces de la lista. Cambia la direccion de cada puntero `siguiente` para que apunte al nodo anterior. Actualiza cabeza al final. Complejidad: O(n).

**Operador []:**
Recorre la lista desde la cabeza hasta el indice deseado. Lanza excepcion si el indice esta fuera de rango. Complejidad: O(n).

**Impresion a Archivo:**
Recorre toda la lista escribiendo cada estudiante formateado en el archivo de texto. Incluye contador de estudiantes y numeracion.

**Ejemplo de Uso:**
```cpp
ListadoEstudiantil listado;
listado.insertar(Estudiante("juan perez", 2000, "1001", 4.2, "juan@email.com"));
int pos = listado.buscar("1001");
Estudiante& est = listado[pos];
listado.eliminar("1001");
listado.invertir();
listado.imprimir("listado_estudiantes.txt");
```

**Complejidades:**
- Insercion: O(n)
- Eliminacion: O(n)
- Busqueda: O(n)
- Acceso por indice: O(n)
- Inversion: O(n)
- Espacio: O(n)

---

### Ejercicio 2: Procesamiento de Senal ECG (50%)

**Descripcion:** Sistema avanzado de procesamiento de senales electrocardiograficas usando lista enlazada doble para permitir recorrido bidireccional durante el filtrado.

**Caracteristicas Implementadas:**

**Clase SenalECG (Lista Enlazada Doble):**
- Constructor que inicializa lista vacia
- Carga de senal desde archivo de texto (tiempo, amplitud)
- Filtro digital pasa bajos usando ecuaciones en diferencias
- Deteccion de picos en senal filtrada
- Calculo de frecuencia cardiaca basada en intervalos entre picos
- Impresion de senal original y filtrada en archivo
- Destructor con liberacion de memoria

**Estructura de Datos:**
```
NULL <- [tiempo|amplitud|amplitudFiltrada|anterior*|siguiente*] <-> ... <-> NULL
```

**Metodologia:**

**Lista Enlazada Doble:**
Cada nodo tiene punteros a nodo anterior y siguiente, permitiendo recorrido en ambas direcciones. Esto es crucial para el filtro que necesita acceder a muestras vecinas.

**Carga desde Archivo:**
Lee linea por linea el archivo ECG.txt extrayendo tiempo y amplitud. Crea nodos nuevos y los enlaza bidireccialmente. Mantiene punteros cabeza y cola para acceso eficiente. Complejidad: O(n).

**Filtro Pasa Bajos:**
Implementa filtro de promedio movil de 5 puntos. Para cada muestra:
- Toma 2 muestras anteriores (usando puntero `anterior`)
- Toma muestra actual
- Toma 2 muestras siguientes (usando puntero `siguiente`)
- Calcula promedio de todas las muestras disponibles

Este filtro suaviza la senal eliminando ruido de alta frecuencia. El uso de lista doble permite acceso eficiente a vecinos. Complejidad: O(n).

**Formula del Filtro:**
```
y[n] = (x[n-2] + x[n-1] + x[n] + x[n+1] + x[n+2]) / 5
```

**Deteccion de Picos:**
Recorre la senal filtrada buscando maximos locales:
- Compara cada punto con sus vecinos inmediatos
- Si valor actual > anterior Y actual > siguiente Y actual > umbral → es pico
- Almacena tiempo del pico en vector

El umbral elimina falsos positivos de ruido residual. Complejidad: O(n).

**Calculo de Frecuencia Cardiaca:**
- Calcula tiempo total entre primer y ultimo pico
- Divide por numero de intervalos (picos - 1)
- Obtiene intervalo promedio entre latidos
- Convierte a latidos por minuto: FC = 60 / intervalo_promedio

**Formula:**
```
intervalo = (tiempo_ultimo_pico - tiempo_primer_pico) / (num_picos - 1)
frecuencia = 60 / intervalo  [bpm]
```

**Impresion:**
Genera archivo con tres columnas: tiempo, amplitud original, amplitud filtrada. Incluye lista de picos detectados y frecuencia cardiaca calculada.

**Ventajas de Lista Doble:**
- Acceso eficiente a muestras anteriores y siguientes para filtrado
- No requiere almacenar ventanas separadas
- Navegacion bidireccional natural para procesamiento de senales
- Memoria distribuida dinamicamente

**Formato del Archivo ECG.txt:**
```
amplitud tiempo
5 0.000
6 0.010
8 0.020
...
```

**Ejemplo de Salida:**
```
tiempo  amplitud_original  amplitud_filtrada
0.000   5                  5.67
0.010   6                  6.80
...

picos detectados:
pico 1: 0.090 segundos
pico 2: 0.290 segundos
...

frecuencia cardiaca: 75.5 bpm
```

**Complejidades:**
- Carga: O(n)
- Filtrado: O(n)
- Deteccion de picos: O(n)
- Calculo FC: O(1)
- Espacio: O(n)

---

### Ejercicio 3: Domino con Historial de Movimientos (25%)

**Descripcion:** Extension del juego de domino del TP_02 agregando sistema de historial completo usando lista enlazada para rastrear todos los movimientos de la partida.

**Caracteristicas Implementadas:**

**Nuevas Clases:**

**Clase Movimiento y HistorialMovimientos:**
- Lista enlazada simple para almacenar movimientos
- Cada nodo contiene: nombre jugador, ficha jugada, estado del tablero
- Metodo para agregar movimiento al final
- Metodo para guardar historial completo en archivo
- Destructor que libera toda la memoria

**Modificaciones al Juego Original:**
- Registro automatico de cada movimiento valido
- Captura del estado completo del tablero despues de cada jugada
- Generacion de archivo `historial_domino.txt` al final del juego
- Contador de movimientos totales

**Estructura del Historial:**
```
NodoMovimiento -> [nombreJugador|fichaJugada|estadoTablero|siguiente*] -> ... -> NULL
```

**Metodologia:**

**Registro de Movimientos:**
Cada vez que un jugador coloca una ficha exitosamente:
1. Crea objeto Ficha con los valores jugados
2. Obtiene estado actual completo del tablero como string
3. Crea NodoMovimiento con toda la informacion
4. Agrega al final de la lista historial

**Captura de Estado del Tablero:**
Recorre el vector `mesa` convirtiendo cada ficha a string formato `[X|Y]` y concatenando todas. Ejemplo: `[3|4] [4|5] [5|2] [2|6]`

**Guardado en Archivo:**
Al finalizar el juego (victoria o bloqueo):
- Abre archivo `historial_domino.txt`
- Escribe encabezado con total de movimientos
- Recorre lista enlazada de historial
- Para cada movimiento escribe:
  - Numero de movimiento
  - Nombre del jugador
  - Ficha jugada
  - Estado completo del tablero
- Cierra archivo

**Formato del Archivo de Salida:**
```
historial de movimientos - juego de domino
total de movimientos: 42

movimiento 1:
jugador: jugador 1
ficha jugada: [3|4]
estado del tablero: [3|4]

movimiento 2:
jugador: jugador 2
ficha jugada: [4|5]
estado del tablero: [3|4] [4|5]

...
```

**Ventajas de Lista Enlazada para Historial:**
- Tamano dinamico (no se sabe cuantos movimientos habra)
- Insercion eficiente al final O(1) con puntero cola
- Memoria se asigna solo cuando es necesaria
- Facil recorrido secuencial para escritura
- Liberacion automatica al destruir objeto

**Integracion con Juego Existente:**
El codigo del domino original se mantiene casi identico. Solo se agregan:
- Objeto `HistorialMovimientos historial` en clase JuegoDomino
- Llamada a `historial.agregarMovimiento()` despues de cada jugada valida
- Llamada a `historial.guardarEnArchivo()` en metodo `finalizarJuego()`
- Llamada a `historial.limpiar()` al iniciar nueva partida

**Flujo del Juego:**
```
Inicio -> Distribucion -> Turno 1 -> Registro Movimiento -> 
Turno 2 -> Registro Movimiento -> ... -> Victoria/Bloqueo -> 
Guardar Historial -> Mostrar Estadisticas
```

**Ejemplo de Uso:**
```cpp
JuegoDomino juego(2);
juego.iniciarPartida();
while (!juego.juegoTerminado()) {
    juego.jugarTurno();  // registra automaticamente en historial
}
juego.finalizarJuego();  // guarda historial_domino.txt
```

**Complejidades:**
- Agregar movimiento: O(1) con puntero cola
- Guardar archivo: O(m) donde m = numero de movimientos
- Espacio: O(m)

**Diferencias con TP_02:**
- TP_02: Solo juega sin registro
- TP_03: Registra todo en lista enlazada y genera archivo de historial completo

---

## Principios de Estructuras de Datos Aplicados

### Listas Enlazadas Simples
- Nodos conectados unidireccionalmente
- Insercion y eliminacion dinamicas
- Recorrido secuencial eficiente
- Memoria no contigua

### Listas Enlazadas Dobles
- Nodos con enlaces bidireccionales
- Acceso a vecinos anterior y siguiente
- Ideal para algoritmos que requieren contexto
- Mayor flexibilidad de navegacion

### Manejo Dinamico de Memoria
- Asignacion con `new` durante ejecucion
- Liberacion con `delete` en destructores
- Prevencion de memory leaks
- Manejo de punteros nulos

### Principios de POO
- Encapsulacion de estructuras de datos
- Interfaces claras y simples
- Destructores automaticos
- Separacion de responsabilidades

## Conceptos Avanzados Implementados

### Procesamiento de Senales Digitales
- Filtros pasa bajos
- Ecuaciones en diferencias
- Deteccion de caracteristicas (picos)
- Analisis de frecuencia

### Estructuras de Datos Dinamicas
- Listas enlazadas simples y dobles
- Insercion/eliminacion dinamica
- Recorrido bidireccional
- Gestion automatica de memoria

### Entrada/Salida de Archivos
- Lectura de archivos de texto
- Escritura formateada
- Manejo de errores de I/O
- Archivos tabulados

## Notas Tecnicas

### Compilacion
- Estandar: C++11 minimo
- Flags: `-std=c++11 -Wall`
- Sin dependencias externas
- Portable entre plataformas

### Archivos Generados

**Ejercicio 1:**
- `listado_estudiantes.txt` - lista completa de estudiantes

**Ejercicio 2:**
- `senal_procesada.txt` - senal original, filtrada, picos y frecuencia cardiaca

**Ejercicio 3:**
- `historial_domino.txt` - historial completo de movimientos del juego

### Manejo de Errores
- Validacion de indices
- Verificacion de archivos
- Excepciones con mensajes claros
- Proteccion contra NULL pointers

## Testing y Validacion

Cada ejercicio incluye casos de prueba en `main.cpp`:
- Operaciones basicas
- Casos extremos
- Validacion de resultados
- Pruebas de memoria (destructores)

## Aplicaciones Practicas

### Ejercicio 1
- Sistemas de gestion academica
- Bases de datos simples
- Sistemas de registro

### Ejercicio 2
- Monitoreo medico en tiempo real
- Procesamiento de bioseñales
- Analisis cardiologico
- Deteccion de arritmias

### Ejercicio 3
- Sistemas de replay en videojuegos
- Auditoria de eventos
- Analisis de partidas
- Logs de actividad

## Problemas Conocidos y Soluciones

### Problema 1: Punteros Dangling
**Solucion:** Inicializar todos los punteros en nullptr y validar antes de usar

### Problema 2: Memory Leaks
**Solucion:** Destructores que recorren y liberan todos los nodos

### Problema 3: Acceso a Indices Invalidos
**Solucion:** Validacion de rangos con excepciones

### Problema 4: Archivo ECG No Existe
**Solucion:** Manejo de excepciones con try-catch

## Mejoras Futuras

- Implementacion de lista circular
- Skip lists para busqueda mas rapida
- Compresion de historial para archivos grandes
- Filtros digitales mas avanzados (Butterworth, Chebyshev)
- Interfaz grafica para visualizacion de senales

## Referencias

- Cormen, T. H., et al. (2009). Introduction to Algorithms (3rd Edition)
- Sedgewick, R. (2011). Algorithms (4th Edition)
- Oppenheim, A. V., & Schafer, R. W. (2009). Discrete-Time Signal Processing
- Stroustrup, B. (2013). The C++ Programming Language (4th Edition)
- cppreference.com - Documentacion de C++


---

**Universidad:** Universidad Nacional de Colombia sede de La Paz    
**Programa:** Ingenieria Mecatronica  
