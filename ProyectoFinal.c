#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_CLIENTES 100
#define MAX_VIAJES 100
#define MAX_NOMBRE 50

#define MAX_NOMBRE 50



char clientes[MAX_CLIENTES][MAX_NOMBRE];
float dinero[MAX_CLIENTES];
char destinos[MAX_VIAJES][MAX_NOMBRE];
int costos[MAX_VIAJES];



int numClientes = 0;
int numViajes = 0;
float Saldo=1000;

int autenticador();
void agregarCliente();
void agregarViaje();
void modificarDatosCliente();
void modificarViaje();
void modificarDineroCliente();
void eliminarCliente();
void eliminarViaje();
void menuAdministrador();
int menuCliente();
int autenticadorCliente();
void contactarProgramador();
void descuentos();

void mostrarDestinos();
void guerrero();
void sonora();
void tlaxcala();
void yucatan();

int main() {
	
    int opcion;

    do {
        printf("\nBienvenido a ConectaBus\n");
        printf("Menú Principal\n");
        printf("1) Administrador\n");
        printf("2) Viajes\n");
        printf("3) Contactar Programadores\n");
        printf("4) Salir\n");
        printf("Seleccione la opcion que desea realizar: ");

        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                   if (autenticador()) {
                    menuAdministrador();
                } else {
                    printf("Demasiados intentos fallidos.\nRegresando al menú principal...\n");
                }
                break;
            case 2:
                if (autenticadorCliente()) {
                menuCliente();
                } else {          
                printf("Lo sentimos, las credenciales no son validas :(\n");
                printf("Regresando al menu principal...\n");
                }
                break;
            case 3:
                contactarProgramador();
                descuentos();
                break;
            case 4:
                printf("Saliendo del programa....");
                break;
            default:
                printf("Opción no válida. Por favor, ingrese una opción válida.\n");
        }
    } while (opcion != 4);
return 0;
}


int autenticador() {
    char usuario[20];
    char contrasena[20];
    char usuarioCorrecto[20];
    char contrasenaCorrecta[20];
    int intentosMax = 3;
    int intentos = 0;

    FILE *archivo = fopen("admin.txt", "a+");
    if (archivo == NULL) {
        printf("Error al abrir el archivo del administrador.\n");
        return 0;
    }

    fscanf(archivo, "%s %s", usuarioCorrecto, contrasenaCorrecta);
    fclose(archivo);

    while (intentos < intentosMax) {
        printf("Ingrese su usuario: ");
        scanf("%s", usuario);
        printf("\nIngrese la contraseña: ");
        scanf("%s", contrasena);

        if (strcmp(usuario, usuarioCorrecto) == 0 && strcmp(contrasena, contrasenaCorrecta) == 0) {
            printf("Autenticación exitosa.\n");
            return 1;
        } else {
            printf("Autenticación fallida. Intentos restantes: %d\n", intentosMax - intentos - 1);
            intentos++;
        }
    }

    printf("Demasiados intentos fallidos. Regresando al menú principal...\n");
    return 0;
}

void agregarCliente() {
    if (numClientes < MAX_CLIENTES) {
        printf("Ingrese el nombre del cliente: ");
        scanf("%s", clientes[numClientes]);
        printf("Ingrese el dinero del cliente: ");
        scanf("%d", &dinero[numClientes]);
        numClientes++;
        printf("Cliente agregado exitosamente.\n");

        char respuesta;
        printf("¿Desea agregar otro cliente? (S para Sí, cualquier otra tecla para No): ");
        scanf(" %c", &respuesta);
        if (respuesta != 'S' && respuesta != 's') {
            return; 
        }
    } else {
        printf("No se puede agregar más clientes. Límite alcanzado (100).\n");
    }
}

void agregarViaje() {
    if (numViajes < MAX_VIAJES) {
        printf("Ingrese el destino del viaje: ");
        scanf("%s", destinos[numViajes]);
        printf("Ingrese el costo del viaje: ");
        scanf("%d", &costos[numViajes]);
        numViajes++;
        printf("Viaje agregado exitosamente.\n");

        char respuesta;
        printf("¿Desea agregar otro viaje? (S para Sí, cualquier otra tecla para No): ");
        scanf(" %c", &respuesta);
        if (respuesta != 'S' && respuesta != 's') {
            return; 
        }
    } else {
        printf("No se puede agregar más viajes. Límite alcanzado (100).\n");
    }
}

void modificarDatosCliente() {
    if (numClientes > 0) {
        char nombre[MAX_NOMBRE];
        printf("Nombre del cliente a modificar: ");
        scanf("%s", nombre);

        for (int i = 0; i < numClientes; i++) {
            if (strcmp(clientes[i], nombre) == 0) {
                printf("Nuevo dinero para %s: ", nombre);
                scanf("%d", &dinero[i]);
                printf("Datos de cliente modificados con éxito.\n");
                return;
            }
        }

        printf("Cliente no encontrado.\n");
    } else {
        printf("No hay clientes para modificar.\n");
    }
}

void modificarViaje() {
    if (numViajes > 0) {
        char viaje[MAX_NOMBRE];
        printf("Destino del viaje a modificar: ");
        scanf("%s", viaje);

        for (int i = 0; i < numViajes; i++) {
            if (strcmp(destinos[i], viaje) == 0) {
                printf("Nuevo costo para el viaje a %s: ", viaje);
                scanf("%d", &costos[i]);
                printf("Datos de viaje modificados con éxito.\n");
                return;
            }
        }

        printf("Viaje no encontrado.\n");
    } else {
        printf("No hay viajes para modificar.\n");
    }
}

void modificarDineroCliente() {
    if (numClientes > 0) {
        char nombre[MAX_NOMBRE];
        printf("Nombre del cliente para modificar dinero: ");
        scanf("%s", nombre);

        for (int i = 0; i < numClientes; i++) {
            if (strcmp(clientes[i], nombre) == 0) {
                printf("Nuevo dinero para %s: ", nombre);
                scanf("%d", &dinero[i]);
                printf("Dinero de cliente modificado con éxito.\n");
                return;
            }
        }

        printf("Cliente no encontrado.\n");
    } else {
        printf("No hay clientes para modificar dinero.\n");
    }
}

void eliminarCliente() {
    if (numClientes > 0) {
        char nombre[MAX_NOMBRE];
        printf("Nombre del cliente a eliminar: ");
        scanf("%s", nombre);

        for (int i = 0; i < numClientes; i++) {
            if (strcmp(clientes[i], nombre) == 0) {
                for (int j = i; j < numClientes - 1; j++) {
                    strcpy(clientes[j], clientes[j + 1]);
                    dinero[j] = dinero[j + 1];
                }
                numClientes--;
                printf("Cliente eliminado con éxito.\n");
                return;
            }
        }

        printf("Cliente no encontrado.\n");
    } else {
        printf("No hay clientes para eliminar.\n");
    }
}

void eliminarViaje() {
    if (numViajes > 0) {
        char destino[MAX_NOMBRE];
        printf("Destino del viaje a eliminar: ");
        scanf("%s", destino);

        for (int i = 0; i < numViajes; i++) {
            if (strcmp(destinos[i], destino) == 0) {
                for (int j = i; j < numViajes - 1; j++) {
                    strcpy(destinos[j], destinos[j + 1]);
                    costos[j] = costos[j + 1];
                }
                numViajes--;
                printf("Viaje eliminado con éxito.\n");
                return;
            }
        }

        printf("Viaje no encontrado.\n");
    } else {
        printf("No hay viajes para eliminar.\n");
    }
}

void menuAdministrador() {
    int opc;
    do {
        printf("Menú del administrador\n");
        printf("1. Añadir clientes\n2. Añadir Viajes\n3. Modificar datos de clientes\n4. Modificar viaje del autobús\n5. Modificar dinero de cliente\n6. Eliminar cliente\n7. Eliminar viaje\n8. Salir\n");
        scanf("%d", &opc);

        switch(opc){
            case 1:
                agregarCliente();
                break;
            case 2:
                agregarViaje();
                break;
            case 3:
                modificarDatosCliente();
                break;
            case 4:
                modificarViaje();
                break;
            case 5:
                modificarDineroCliente();
                break;
            case 6:
                eliminarCliente();
                break;
            case 7:
                eliminarViaje();
                break;
                case 8:
                printf("Saliendo del programa...\n");
                return;
            default:
                printf("Opción no válida.\n");
        }
    } while (1); 

}

int menuCliente(){
    int opc;
    FILE *archivo = fopen("descuentoEstudiante.txt", "r");  
    FILE *archivo1 = fopen("descuentoMaestro.txt", "r");
    FILE *archivo2 = fopen("descuentoClienteFrec.txt", "r");
    do
    {

    printf("\nBienvenido este es el menu cliente\n");
    FILE *archivoDest;
    archivoDest = fopen("destinos.txt", "r");
    FILE *archivosNinos;
    archivosNinos = fopen("destinosNinos.txt", "r");
    FILE *archivosHorarios;
    archivosHorarios = fopen("horarios.txt", "r");
    mostrarDestinos(archivoDest, archivosNinos, archivosHorarios);
    printf("Elija algun destino:\n");
    fclose(archivosNinos);
    fscanf(stdin, "%d", &opc);
    fclose(archivoDest);
    switch(opc)
    {
        case 1:
        guerrero(archivo, archivo1, archivo2);
        break;

        case 2:
        sonora(archivo, archivo1, archivo2);
        break;

        case 3:
        tlaxcala(archivo, archivo1, archivo2);
        break;

        case 4:
        yucatan(archivo, archivo1, archivo2);
        break;
        
        default:
        printf("Opcion invalida");
        break;
    }
    }while(opc!=4);

    fclose(archivo);
    fclose(archivo1);
    fclose(archivo2);

    return 0;
}

void guerrero(FILE *archivo, FILE *archivo1, FILE *archivo2)
{
    char caracteres[30];
    char caracteres1[30];
    char caracteres2[30];
    char caracteresUsuario[30];
    char nombreCliente[20];

    char op;
    float cupon;
    float precioCupon;
    float precioDesc;
    float preciosF;
    int boletosA;
    int boletosN;
    float preciosA, preciosN, preciosT;
    int boletosTotales=0;
    float dineroFaltante;
    float saldoEpico;


   do
   {
    printf("Cuantos boletos de niño serian:\n");
    scanf("%i",&boletosN);
    printf("Cuantos boletos de adulto serian:\n");
    scanf("%i",&boletosA);
    boletosTotales= boletosN + boletosA;
    if(boletosTotales>4)
    {
        printf("El limite de boletos por persona son 4, escoga otra cantidad\n");
    }else{
        do
        {
        printf("¿Cuenta con algun codigo de descuento? (S/N)\n");
        scanf(" %c",&op);
        if(op=='N')
        {
            preciosA=boletosA*300;
            preciosN=boletosN*240;
            preciosF=preciosA+preciosN;
            printf("El precio final seria de: %.2f\n", preciosF);
 

        }else {
            fgets(caracteres, 30, archivo);
            fgets(caracteres1, 30, archivo1);
            fgets(caracteres2, 30, archivo2);
            printf("Ingrese su codigo de descuento:\n");
            fscanf(stdin, "%s", caracteresUsuario);
            if (strcmp(caracteresUsuario, caracteres) == 0)
            {
                cupon=.5;
            }else if (strcmp(caracteresUsuario, caracteres1) == 0)
            {
                cupon=.25;
            }else if (strcmp(caracteresUsuario, caracteres2) == 0)
            {
                cupon=.3;
            }else{
                printf("Codigo incorrecto\n");
                continue;
            } 
                    preciosA = boletosA * 300;
                    preciosN = boletosN * 240;
                    preciosT = preciosA + preciosN;
                    precioCupon = cupon * preciosT;
                    precioDesc = preciosT - precioCupon;
                    printf("El precio final seria de: %.2f\n", precioDesc);
            
        }
        }while(op!='S' && op!='N');

        if(precioDesc>Saldo || preciosF>Saldo)
        {

            printf("Saldo Insuficiente\n");
            printf("Ingrese la cantidad faltante:\n");
            scanf("%f",&dineroFaltante);
            saldoEpico=Saldo+dineroFaltante;
            if(precioDesc>saldoEpico || preciosF>saldoEpico)
            {
                printf("Cuota no cubierta :C\n");
            }else if (precioDesc<saldoEpico || preciosF<saldoEpico)
            {
                printf("¿A nombre de quien quedara el boleto?:\n");
                scanf(" %s",nombreCliente);
                printf("===Ticket de Compra===\n");
                printf("--Cliente: %s--\n",nombreCliente);
                printf("--Destino: Guerrero--\n");
                printf("--Salida: Tasqueña--\n");
                printf("--Horario: 16:30--\n");
            }
            
        }else{
                printf("¿A nombre de quien quedara el boleto?:\n");
                scanf(" %s",nombreCliente);
                printf("===Ticket de Compra===\n");
                printf("--Cliente: %s--\n",nombreCliente);
                printf("--Destino: Guerrero--\n");
                printf("--Salida: Tasqueña--\n");
                printf("--Horario: 16:30--\n");
        }
    }

   }while(boletosTotales>4);

}

void sonora(FILE *archivo, FILE *archivo1, FILE *archivo2)
{
    char caracteres[30];
    char caracteres1[30];
    char caracteres2[30];
    char caracteresUsuario[30];
    char nombreCliente[20];

    char op;
    float cupon;
    float precioCupon;
    float precioDesc;
    float preciosF;
    int boletosA;
    int boletosN;
    float preciosA, preciosN, preciosT;
    int boletosTotales=0;
    float dineroFaltante;
    float saldoEpico;

   do
   {
    printf("Cuantos boletos de niño serian:\n");
    scanf("%i",&boletosN);
    printf("Cuantos boletos de adulto serian:\n");
    scanf("%i",&boletosA);
    boletosTotales= boletosN + boletosA;
    if(boletosTotales>4)
    {
        printf("El limite de boletos por persona son 4, escoga otra cantidad\n");
    }else{
        do
        {
        printf("¿Cuenta con algun codigo de descuento? (S/N)\n");
        scanf(" %c",&op);
        if(op=='N')
        {
            preciosA=boletosA*2000;
            preciosN=boletosN*1600;
            preciosF=preciosA+preciosN;
            printf("El precio final seria de: %.2f\n", preciosF);
 

        }else {
            fgets(caracteres, 30, archivo);
            fgets(caracteres1, 30, archivo1);
            fgets(caracteres2, 30, archivo2);
            printf("Ingrese su codigo de descuento:\n");
            fscanf(stdin, "%s", caracteresUsuario);
            if (strcmp(caracteresUsuario, caracteres) == 0)
            {
                cupon=.5;

            }else if (strcmp(caracteresUsuario, caracteres1) == 0)
            {
                cupon=.25;

            }else if (strcmp(caracteresUsuario, caracteres2) == 0)
            {
                cupon=.3;
            }else{
                printf("Codigo incorrecto\n");
                continue;
            } 
                preciosA=boletosA*2000;
                preciosN=boletosN*1600;
                preciosT=preciosA+preciosN;
                precioCupon=(cupon)*(preciosT);
                precioDesc=preciosT-precioCupon;
                printf("El precio final seria de: %.2f\n", precioDesc);
        }
        }while(op!='N' && op !='S');

        if(precioDesc>Saldo || preciosF>Saldo)
        {

            printf("Saldo Insuficiente\n");
            printf("Ingrese la cantidad faltante:\n");
            scanf("%f",&dineroFaltante);
            saldoEpico=Saldo+dineroFaltante;
            if(precioDesc>saldoEpico || preciosF>saldoEpico)
            {
                printf("Cuota no cubierta :C\n");
            }else if (precioDesc<saldoEpico || preciosF<saldoEpico)
            {
                printf("¿A nombre de quien quedara el boleto?:\n");
                scanf(" %s",nombreCliente);
                printf("===Ticket de Compra===\n");
                printf("--Cliente: %s--\n",nombreCliente);
                printf("--Destino: Sonora--\n");
                printf("--Salida: TAPO--\n");
                printf("--Horario: 8:00--\n");
            }
            
        }else{
                printf("¿A nombre de quien quedara el boleto?:\n");
                scanf(" %s",nombreCliente);
                printf("===Ticket de Compra===\n");
                printf("--Cliente: %s--\n",nombreCliente);
                printf("--Destino: Sonora--\n");
                printf("--Salida: TAPO--\n");
                printf("--Horario: 8:00--\n");
        }
    }

   }while(boletosTotales>4);

}

void tlaxcala(FILE *archivo, FILE *archivo1, FILE *archivo2)
{
    char caracteres[30];
    char caracteres1[30];
    char caracteres2[30];
    char caracteresUsuario[30];
    char nombreCliente[20];

    char op;
    float cupon;
    float precioCupon;
    float precioDesc;
    float preciosF;
    int boletosA;
    int boletosN;
    float preciosA, preciosN, preciosT;
    int boletosTotales=0;
    float dineroFaltante;
    float saldoEpico;

   do
   {
    printf("Cuantos boletos de niño serian:\n");
    scanf("%i",&boletosN);
    printf("Cuantos boletos de adulto serian:\n");
    scanf("%i",&boletosA);
    boletosTotales= boletosN + boletosA;
    if(boletosTotales>4)
    {
        printf("El limite de boletos por persona son 4, escoga otra cantidad\n");
    }else{
        do
        {
        printf("¿Cuenta con algun codigo de descuento? (S/N)\n");
        scanf(" %c",&op);
        if(op=='N')
        {
            preciosA=boletosA*100;
            preciosN=boletosN*80;
            preciosF=preciosA+preciosN;
            printf("El precio final seria de: %.2f\n", preciosF);
 

        }else {
            fgets(caracteres, 30, archivo);
            fgets(caracteres1, 30, archivo1);
            fgets(caracteres2, 30, archivo2);
            printf("Ingrese su codigo de descuento:\n");
            fscanf(stdin, "%s", caracteresUsuario);
            if (strcmp(caracteresUsuario, caracteres) == 0)
            {
                cupon=.5;

            }else if (strcmp(caracteresUsuario, caracteres1) == 0)
            {
                cupon=.25;

            }else if (strcmp(caracteresUsuario, caracteres2) == 0)
            {
                cupon=.3;

            }else{
                printf("Codigo incorrecto\n");
                continue;
            } 
                preciosA=boletosA*100;
                preciosN=boletosN*80;
                preciosT=preciosA+preciosN;
                precioCupon=(cupon)*(preciosT);
                precioDesc=preciosT-precioCupon;
                printf("El precio final seria de: %.2f\n", precioDesc);
        }
        }while(op!='N' && op !='S');

        if(precioDesc>Saldo || preciosF>Saldo)
        {

            printf("Saldo Insuficiente\n");
            printf("Ingrese la cantidad faltante:\n");
            scanf("%f",&dineroFaltante);
            saldoEpico=Saldo+dineroFaltante;
            if(precioDesc>saldoEpico || preciosF>saldoEpico)
            {
                printf("Cuota no cubierta :C\n");
            }else if (precioDesc<saldoEpico || preciosF<saldoEpico)
            {
                printf("¿A nombre de quien quedara el boleto?:\n");
                scanf(" %s",nombreCliente);
                printf("===Ticket de Compra===\n");
                printf("--Cliente: %s--\n",nombreCliente);
                printf("--Destino: Tlaxcala--\n");
                printf("--Salida: Tasqueña--\n");
                printf("--Horario: 12:00--\n");
            }
            
        }else{
                printf("¿A nombre de quien quedara el boleto?:\n");
                scanf(" %s",nombreCliente);
                printf("===Ticket de Compra===\n");
                printf("--Cliente: %s--\n",nombreCliente);
                printf("--Destino: Tlaxcala--\n");
                printf("--Salida: Tasqueña--\n");
                printf("--Horario: 12:00--\n");
        }
    }

   }while(boletosTotales>4);

}

void yucatan(FILE *archivo, FILE *archivo1, FILE *archivo2)
{
    char caracteres[30];
    char caracteres1[30];
    char caracteres2[30];
    char caracteresUsuario[30];
    char nombreCliente[20];

    char op;
    float cupon;
    float precioCupon;
    float precioDesc;
    float preciosF;
    int boletosA;
    int boletosN;
    float preciosA, preciosN, preciosT;
    int boletosTotales=0;
    float dineroFaltante;
    float saldoEpico;

   do
   {
    printf("Cuantos boletos de niño serian:\n");
    scanf("%i",&boletosN);
    printf("Cuantos boletos de adulto serian:\n");
    scanf("%i",&boletosA);
    boletosTotales= boletosN + boletosA;
    if(boletosTotales>4)
    {
        printf("El limite de boletos por persona son 4, escoga otra cantidad\n");
    }else{
        do
        {
        printf("¿Cuenta con algun codigo de descuento? (S/N)\n");
        scanf(" %c",&op);
        if(op=='N')
        {
            preciosA=boletosA*500;
            preciosN=boletosN*400;
            preciosF=preciosA+preciosN;
            printf("El precio final seria de: %.2f\n", preciosF);
 

        }else {
            fgets(caracteres, 30, archivo);
            fgets(caracteres1, 30, archivo1);
            fgets(caracteres2, 30, archivo2);
            printf("Ingrese su codigo de descuento:\n");
            fscanf(stdin, "%s", caracteresUsuario);
            if (strcmp(caracteresUsuario, caracteres) == 0)
            {
                cupon=.5;

            }else if (strcmp(caracteresUsuario, caracteres1) == 0)
            {
                cupon=.25;

            }else if (strcmp(caracteresUsuario, caracteres2) == 0)
            {
                cupon=.3;

            }else{
                printf("Codigo incorrecto\n");
                continue;
            } 
                preciosA=boletosA*500;
                preciosN=boletosN*400;
                preciosT=preciosA+preciosN;
                precioCupon=(cupon)*(preciosT);
                precioDesc=preciosT-precioCupon;
                printf("El precio final seria de: %.2f\n", precioDesc);
        }
        }while(op!='N' && op !='S');

        if(precioDesc>Saldo || preciosF>Saldo)
        {

            printf("Saldo Insuficiente\n");
            printf("Ingrese la cantidad faltante:\n");
            scanf("%f",&dineroFaltante);
            saldoEpico=Saldo+dineroFaltante;
            if(precioDesc>saldoEpico || preciosF>saldoEpico)
            {
                printf("Cuota no cubierta :C\n");
            }else if (precioDesc<saldoEpico || preciosF<saldoEpico)
            {
                printf("¿A nombre de quien quedara el boleto?:\n");
                scanf(" %s",nombreCliente);
                printf("===Ticket de Compra===\n");
                printf("--Cliente: %s--\n",nombreCliente);
                printf("--Destino: Yucatan--\n");
                printf("--Salida: TAPO--\n");
                printf("--Horario: 21:00--\n");
            }
            
        }else{
                printf("¿A nombre de quien quedara el boleto?:\n");
                scanf(" %s",nombreCliente);
                printf("===Ticket de Compra===\n");
                printf("--Cliente: %s--\n",nombreCliente);
                printf("--Destino: Yucatan--\n");
                printf("--Salida: TAPO--\n");
                printf("--Horario: 21:00--\n");
        }
    }

   }while(boletosTotales>4);

}


void mostrarDestinos(FILE *archivoDest, FILE *archivosNinos, FILE *archivosHorarios) 
{
    char nombre[MAX_NOMBRE];
    char nombreNinos[MAX_NOMBRE];
    char nombreHorarios[MAX_NOMBRE];

    printf("=== Destinos Disponibles ===\n");
    for (int i = 0; i < 4; ++i) 
    {
        fscanf(archivoDest, "%s \n", nombre);
        printf("%d) %s\n", i + 1, nombre);
    }

    printf("=== Precios Ninos ===\n");
    for (int i = 0; i < 4; ++i) 
    {
        fscanf(archivosNinos, "%s\n", nombreNinos);
        printf("%d) %s\n", i + 1, nombreNinos);
    }

     printf("=== Horarios y Salidas ===\n");
    for (int i = 0; i < 4; ++i) 
    {
        fscanf(archivosHorarios, "%s\n", nombreHorarios);
        printf("%d) %s\n", i + 1, nombreHorarios);
    }
    printf("<==========================>\n");


}

int autenticadorCliente(){
    char usuariocliente[20];
    char contrasena[20];
    char usuarioCorrecto[20];
    char contrasenaCorrecta[20];


    FILE *archivo = fopen("cuentaCliente.txt", "a+");
    if (archivo == NULL) {
        printf("Lo sentimos, hubo un error al abrir su cuenta de cliente\n");
        return 0;
    }

    fscanf(archivo, "%s %s", usuarioCorrecto, contrasenaCorrecta);
    fclose(archivo);

    printf("¡Bienvenido! Por favor, introduzca su cuenta de cliente: :)\n");
    printf("Ingrese su usuario: \n");
    scanf("%s", usuariocliente);
    printf("\nIngrese la contraseña: \n");
    scanf("%s", contrasena);

    if (strcmp(usuariocliente, usuarioCorrecto) == 0 && strcmp(contrasena, contrasenaCorrecta) == 0) {

    return 1; 
    } else {
        printf("\n");
    }
    return 0; 
}

void contactarProgramador() {
    FILE *archivo = fopen("programadores.txt", "r");
    if (archivo == NULL) {
        printf("Lo sentimos, hubo un error al abrir el archivo :(\n");
        return;
    }

    char caracteres[50]; 
    caracteres[0] = '\0';

    while (fgets(caracteres, 50, archivo) != NULL) { 
        printf("%s", caracteres); 
    }
    fclose(archivo); 
}


void descuentos() {
    int opc;
    char opcDesc;

    printf("¿Te gustaria obtener algun descuento?\n");
    printf("1) Si\n");
    printf("2) No\n");
    scanf("%d", &opc);

    if (opc == 1) {
        printf("¿Que descuento te gustaria obtener?\n");
        printf("a) Descuento de Estudiante\n");
        printf("b) Descuento de Maestro\n");
        printf("c) Descuento de cliente frecuente\n");
        scanf(" %c", &opcDesc); 

        char caracteres[10];

        switch (opcDesc) {
            case 'a': {
                printf("Codigo de descuento de estudiante:\n");
                FILE *archivo = fopen("descuentoEstudiante.txt", "r");
                if (archivo == NULL) {
                    printf("Lo sentimos, hubo un error al abrir el archivo :(\n");
                    return;
                }

                    while (fgets(caracteres, 10, archivo) != NULL) { 
                   printf("%s", caracteres); 
                    }

                fclose(archivo);
                break;
            }
            case 'b': {
                printf("Codigo de descuento de maestro:\n");
                FILE *archivo1 = fopen("descuentoMaestro.txt", "r");
                if (archivo1 == NULL) {
                    printf("Lo sentimos, hubo un error al abrir el archivo :(\n");
                    return;
                }

                    while (fgets(caracteres, 10, archivo1) != NULL) { 
                   printf("%s", caracteres); 
                    }

                fclose(archivo1);
                break;
            }
            case 'c': {
                printf("Codigo de descuento de cliente frecuente:\n");
                FILE *archivo2 = fopen("descuentoClienteFrec.txt", "r");
                if (archivo2 == NULL) {
                    printf("Lo sentimos, hubo un error al abrir el archivo :(\n");
                    return;
                }

                    while (fgets(caracteres, 10, archivo2) != NULL) { 
                   printf("%s", caracteres); 
                    }

                fclose(archivo2);
                break;
            }
            default:
                printf("Selecciono una opcion no valida...\n");
                break;
        }
    } else {
        printf("Gracias por tu honestidad, hasta luego :)\n");
    }
}

