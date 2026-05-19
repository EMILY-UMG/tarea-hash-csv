# Tarea Hash CSV

## Estudiante
Emily Monterroso

## Carné
9941-24-1489

---

# Descripción

Proyecto desarrollado en C++ y Java para la carga masiva de estudiantes desde un archivo CSV utilizando estructuras hash.

El proyecto incluye:

- Implementación manual de tabla hash en C++
- Resolución de colisiones mediante Separate Chaining
- Uso de HashMap en Java
- Lectura de archivos CSV
- Búsqueda y eliminación de estudiantes
- Estadísticas de carga y colisiones

---

# Estructura del proyecto

tarea-hash-csv/
│
├── cpp-hash/
│   ├── main.cpp
│   └── estudiantes.csv
│
├── java-hashmap/
│   ├── Main.java
│   ├── Estudiante.java
│   └── estudiantes.csv
│
├── evidencias/
│   └── evidencia.pdf
│
└── README.md

---

# Requisitos

## C++

- CLion o compilador compatible con C++11 o superior

## Java

- IntelliJ IDEA
- JDK 17 o superior

---

# Ejecución en C++

1. Abrir la carpeta `cpp-hash` en CLion.
2. Verificar que `estudiantes.csv` esté en la carpeta principal.
3. Ejecutar `main.cpp`.

---

# Ejecución en Java

1. Abrir la carpeta `java-hashmap` en IntelliJ IDEA.
2. Verificar que `estudiantes.csv` esté en la carpeta principal.
3. Ejecutar `Main.java`.

---

# Funcionalidades implementadas

## C++

- Lectura de archivo CSV
- Tabla hash manual
- Separate Chaining
- Inserción de estudiantes
- Búsqueda por student_id
- Eliminación por student_id
- Validación de duplicados
- Estadísticas de colisiones
- Factor de carga
- Visualización por buckets

## Java

- Lectura de archivo CSV
- Uso de HashMap<Integer, Estudiante>
- Inserción de estudiantes
- Validación de duplicados
- Búsqueda por student_id
- Eliminación por student_id
- Conteo total de estudiantes

---

# Comparación entre C++ y Java

En C++ fue necesario implementar manualmente
la tabla hash utilizando arreglos, nodos y listas enlazadas.

En Java, HashMap ya proporciona una implementación optimizada,
permitiendo trabajar con tablas hash de forma más sencilla y abstracta.