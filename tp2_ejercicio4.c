#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estructura para representar una PC
struct compu {
    float velocidad;    // entre 1 y 3 GHz
    int anio;           // entre 2015 y 2023
    int cantidad;       // entre 1 y 8
    char *tipo_cpu;     // valores del arreglo tipos
}typedef computadora;

// Arreglo de tipos de procesador
char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
int n = 5; //dimension del arreglo

//prototipo de funciones
int numero_aleatorio(int min, int max); 
computadora crear_pc_aleatoria();
void imprimir_pc(struct compu pc);
struct compu pc_mas_vieja(struct compu pcs[n]);
struct compu pc_mayor_velocidad(struct compu pcs[n]);

int main(){
    srand(time(NULL)); 
    //creo arreglo de estructura para guardar las características de 5 PC. 
    computadora pcs[n]; 

    //cargo aleatorio de PCs
    for(int i = 0;i < n; i++){
        pcs[i] = crear_pc_aleatoria(); 
    }

    printf("///LISTA DE PCS///\n");
    for (int i = 0; i < n; i++) {
        printf("PC %d:\n", i + 1);
        imprimir_pc(pcs[i]);
    }

    // Encontrar y mostrar la PC más vieja
    printf("PC más vieja:\n");
    struct compu pc_vieja = pc_mas_vieja(pcs);
    imprimir_pc(pc_vieja);

    // Encontrar y mostrar la PC con mayor velocidad
    printf("PC con mayor velocidad:\n");
    struct compu pc_veloz = pc_mayor_velocidad(pcs);
    imprimir_pc(pc_veloz);
    
    return 0; 
}

//funciones

// Función para generar un número aleatorio en un rango dado
int numero_aleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

computadora crear_pc_aleatoria() {
    computadora pc;
    pc.velocidad = numero_aleatorio(1, 3); // entre 1 y 3 GHz
    pc.anio = numero_aleatorio(2015, 2023); // entre 2015 y 2023
    pc.cantidad = numero_aleatorio(1, 8);   // entre 1 y 8
    pc.tipo_cpu = tipos[numero_aleatorio(0, 5)]; // seleccionar un tipo de procesador aleatorio
    return pc;
}

// Función para imprimir los detalles de una PC
void imprimir_pc(struct compu pc) {
    printf("Velocidad: %.2f GHz\n", pc.velocidad);
    printf("Año de fabricación: %d\n", pc.anio);
    printf("Cantidad de núcleos: %d\n", pc.cantidad);
    printf("Tipo de procesador: %s\n", pc.tipo_cpu);
    printf("\n");
}

// Función para encontrar la PC más vieja
struct compu pc_mas_vieja(struct compu pcs[n]) {
    struct compu mas_vieja = pcs[0];
    for (int i = 1; i < n; i++) {
        if (pcs[i].anio < mas_vieja.anio) {
            mas_vieja = pcs[i];
        }
    }
    return mas_vieja;
}

// Función para encontrar la PC con mayor velocidad
struct compu pc_mayor_velocidad(struct compu pcs[n]) {
    struct compu mayor_velocidad = pcs[0];
    for (int i = 1; i < n; i++) {
        if (pcs[i].velocidad > mayor_velocidad.velocidad) {
            mayor_velocidad = pcs[i];
        }
    }
    return mayor_velocidad;
}