package edu.umg;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        // HASHMAP
        HashMap<Integer, Estudiante> estudiantes = new HashMap<>();

        // SCANNER
        Scanner scanner = new Scanner(System.in);

        System.out.println("=================================");
        System.out.println("Nombre: Emily Monterroso");
        System.out.println("Carné: 9941-24-1489");
        System.out.println("=================================");

        // CARGAR CSV
        cargarCSV(estudiantes);

        int opcion;

        do {

            System.out.println("\n========== MENU ==========");
            System.out.println("1. Mostrar estudiantes");
            System.out.println("2. Buscar estudiante");
            System.out.println("3. Eliminar estudiante");
            System.out.println("4. Mostrar estadisticas");
            System.out.println("5. Salir");
            System.out.print("Seleccione una opcion: ");

            opcion = scanner.nextInt();

            switch (opcion) {

                case 1:

                    mostrarEstudiantes(estudiantes);
                    break;

                case 2:

                    buscarEstudiante(estudiantes, scanner);
                    break;

                case 3:

                    eliminarEstudiante(estudiantes, scanner);
                    break;

                case 4:

                    mostrarEstadisticas(estudiantes);
                    break;

                case 5:

                    System.out.println("Saliendo del programa...");
                    break;

                default:

                    System.out.println("Opcion invalida.");
            }

        } while (opcion != 5);

        scanner.close();
    }

    public static void cargarCSV(HashMap<Integer, Estudiante> estudiantes) {

        String archivo = "estudiantes.csv";

        try {

            BufferedReader br = new BufferedReader(
                    new FileReader(archivo)
            );

            String linea;

            br.readLine();

            while ((linea = br.readLine()) != null) {

                String[] datos = linea.split(",");

                int id = Integer.parseInt(datos[0]);
                String nombre = datos[1];
                String carrera = datos[2];
                int semestre = Integer.parseInt(datos[3]);
                double gpa = Double.parseDouble(datos[4]);
                int skillScore = Integer.parseInt(datos[5]);

                if (!estudiantes.containsKey(id)) {

                    Estudiante estudiante = new Estudiante(
                            id,
                            nombre,
                            carrera,
                            semestre,
                            gpa,
                            skillScore
                    );

                    estudiantes.put(id, estudiante);

                } else {

                    System.out.println(
                            "ID duplicado encontrado: " + id
                    );
                }
            }

            br.close();

            System.out.println("\nCSV cargado correctamente.");

        } catch (IOException e) {

            System.out.println("Error al leer el archivo CSV.");
            System.out.println(e.getMessage());
        }
    }


    public static void mostrarEstudiantes(
            HashMap<Integer, Estudiante> estudiantes) {

        System.out.println("\n=== ESTUDIANTES ===");

        for (Integer key : estudiantes.keySet()) {

            System.out.println("----------------------");
            System.out.println(estudiantes.get(key));
        }
    }


    public static void buscarEstudiante(
            HashMap<Integer, Estudiante> estudiantes,
            Scanner scanner) {

        System.out.print("Ingrese ID a buscar: ");

        int id = scanner.nextInt();

        if (estudiantes.containsKey(id)) {

            System.out.println("\n=== ESTUDIANTE ENCONTRADO ===");
            System.out.println(estudiantes.get(id));

        } else {

            System.out.println("ESTUDIANTE NO ENCONTRADO.");
        }
    }

    public static void eliminarEstudiante(
            HashMap<Integer, Estudiante> estudiantes,
            Scanner scanner) {

        System.out.print("Ingrese ID a eliminar: ");

        int id = scanner.nextInt();

        if (estudiantes.containsKey(id)) {

            estudiantes.remove(id);

            System.out.println("Estudiante eliminado.");

        } else {

            System.out.println("No existe estudiante.");
        }
    }


    public static void mostrarEstadisticas(
            HashMap<Integer, Estudiante> estudiantes) {

        System.out.println("\n=== ESTADISTICAS ===");

        System.out.println(
                "Total estudiantes: " + estudiantes.size()
        );

        System.out.println(
                "Estructura utilizada: HashMap<Integer, Estudiante>"
        );
    }
}
