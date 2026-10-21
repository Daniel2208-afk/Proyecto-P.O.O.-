#include <iostream>
#include <string>
#include <thread>
#include <chrono>
using namespace std;

// ======================================================
// COLORES ANSI
// ======================================================
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define WHITE   "\033[37m"

// ======================================================
// FUNCIONES DE ANIMACION
// ======================================================

void animarTexto(const string& texto, int ms = 20) {
    for (char c : texto) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(ms));
    }
    cout << endl;
}

void pantallaCarga() {
    cout << GREEN << "  Cargando ";
    for (int i = 0; i < 30; i++) {
        cout << "=" << flush;
        this_thread::sleep_for(chrono::milliseconds(30));
    }
    cout << " Listo!" << RESET << endl;
}

void lineaSep() {
    cout << YELLOW << "============================================================" << RESET << endl;
}

void pausar() {
    cout << CYAN << "\n  Presione Enter para continuar..." << RESET;
    cin.ignore();
    cin.get();
}

void mensajeExito(string msg) {
    cout << GREEN << BOLD << "\n  [OK] " << RESET << GREEN << msg << RESET << endl;
}

void mensajeError(string msg) {
    cout << RED << BOLD << "\n  [!]  " << RESET << RED << msg << RESET << endl;
}


// ======================================================
// CLASE PRODUCTO
// ======================================================

class Producto
{
private:
    string id;
    string nombre;
    double precio;
    int stock;

public:

    Producto()
    {
        id = "";
        nombre = "";
        precio = 0;
        stock = 0;
    }

    void setId(string i) { id = i; }
    void setNombre(string n) { nombre = n; }
    void setPrecio(double p) { precio = p; }
    void setStock(int s) { stock = s; }

    string getId() { return id; }
    string getNombre() { return nombre; }
    double getPrecio() { return precio; }
    int getStock() { return stock; }

    void mostrar()
    {
        cout << CYAN << "  ID:     " << RESET << id << endl;
        cout << CYAN << "  Nombre: " << RESET << nombre << endl;
        cout << CYAN << "  Precio: " << RESET << "S/ " << precio << endl;
        cout << CYAN << "  Stock:  " << RESET << stock << endl;
    }
};


// ======================================================
// CLASE LAPTOP
// ======================================================

class Laptop : public Producto
{
private:
    string procesador;
    int ram;
    int almacenamiento;

public:

    Laptop()
    {
        procesador = "";
        ram = 0;
        almacenamiento = 0;
    }

    void setProcesador(string p) { procesador = p; }
    void setRam(int r) { ram = r; }
    void setAlmacenamiento(int a) { almacenamiento = a; }

    string getProcesador() { return procesador; }
    int getRam() { return ram; }
    int getAlmacenamiento() { return almacenamiento; }

    void mostrarLaptop()
    {
        mostrar();
        cout << CYAN << "  Procesador:     " << RESET << procesador << endl;
        cout << CYAN << "  RAM:            " << RESET << ram << " GB" << endl;
        cout << CYAN << "  Almacenamiento: " << RESET << almacenamiento << " GB" << endl;
    }
};


// ======================================================
// CLASE DESKTOP
// ======================================================

class Desktop : public Producto
{
private:
    string procesador;
    int ram;
    string tarjetaGrafica;

public:

    Desktop()
    {
        procesador = "";
        ram = 0;
        tarjetaGrafica = "";
    }

    void setProcesador(string p) { procesador = p; }
    void setRam(int r) { ram = r; }
    void setTarjetaGrafica(string t) { tarjetaGrafica = t; }

    string getProcesador() { return procesador; }
    int getRam() { return ram; }
    string getTarjetaGrafica() { return tarjetaGrafica; }

    void mostrarDesktop()
    {
        mostrar();
        cout << CYAN << "  Procesador:    " << RESET << procesador << endl;
        cout << CYAN << "  RAM:           " << RESET << ram << " GB" << endl;
        cout << CYAN << "  Tarjeta Gfx:   " << RESET << tarjetaGrafica << endl;
    }
};


// ======================================================
// CLASE ACCESORIO
// ======================================================

class Accesorio : public Producto
{
private:
    string tipo;
    string compatibilidad;

public:

    Accesorio()
    {
        tipo = "";
        compatibilidad = "";
    }

    void setTipo(string t) { tipo = t; }
    void setCompatibilidad(string c) { compatibilidad = c; }

    string getTipo() { return tipo; }
    string getCompatibilidad() { return compatibilidad; }

    void mostrarAccesorio()
    {
        mostrar();
        cout << CYAN << "  Tipo:           " << RESET << tipo << endl;
        cout << CYAN << "  Compatibilidad: " << RESET << compatibilidad << endl;
    }
};


// ======================================================
// CLASE CLIENTE
// ======================================================

class Cliente
{
private:
    string id;
    string nombre;
    string telefono;
    string correo;

public:

    Cliente()
    {
        id = "";
        nombre = "";
        telefono = "";
        correo = "";
    }

    void setId(string i) { id = i; }
    void setNombre(string n) { nombre = n; }
    void setTelefono(string t) { telefono = t; }
    void setCorreo(string c) { correo = c; }

    string getId() { return id; }
    string getNombre() { return nombre; }
    string getTelefono() { return telefono; }
    string getCorreo() { return correo; }

    void mostrar()
    {
        cout << CYAN << "  ID:       " << RESET << id << endl;
        cout << CYAN << "  Nombre:   " << RESET << nombre << endl;
        cout << CYAN << "  Telefono: " << RESET << telefono << endl;
        cout << CYAN << "  Correo:   " << RESET << correo << endl;
    }
};


// ======================================================
// CLASE EMPLEADO
// ======================================================

class Empleado
{
private:
    string id;
    string nombre;
    string cargo;

public:

    Empleado()
    {
        id = "";
        nombre = "";
        cargo = "";
    }

    void setId(string i) { id = i; }
    void setNombre(string n) { nombre = n; }
    void setCargo(string c) { cargo = c; }

    string getId() { return id; }
    string getNombre() { return nombre; }
    string getCargo() { return cargo; }

    void mostrar()
    {
        cout << CYAN << "  ID:     " << RESET << id << endl;
        cout << CYAN << "  Nombre: " << RESET << nombre << endl;
        cout << CYAN << "  Cargo:  " << RESET << cargo << endl;
    }
};


// ======================================================
// CLASE PROVEEDOR
// ======================================================

class Proveedor
{
private:
    string id;
    string nombre;
    string telefono;

public:

    Proveedor()
    {
        id = "";
        nombre = "";
        telefono = "";
    }

    void setId(string i) { id = i; }
    void setNombre(string n) { nombre = n; }
    void setTelefono(string t) { telefono = t; }

    string getId() { return id; }
    string getNombre() { return nombre; }
    string getTelefono() { return telefono; }

    void mostrar()
    {
        cout << CYAN << "  ID:        " << RESET << id << endl;
        cout << CYAN << "  Proveedor: " << RESET << nombre << endl;
        cout << CYAN << "  Telefono:  " << RESET << telefono << endl;
    }
};


// ======================================================
// CLASE TIENDA
// ======================================================

class Tienda
{
private:
    string nombre;
    string direccion;
    string telefono;

public:

    Tienda()
    {
        nombre = "";
        direccion = "";
        telefono = "";
    }

    void setNombre(string n) { nombre = n; }
    void setDireccion(string d) { direccion = d; }
    void setTelefono(string t) { telefono = t; }

    string getNombre() { return nombre; }
    string getDireccion() { return direccion; }
    string getTelefono() { return telefono; }

    void mostrar()
    {
        lineaSep();
        cout << BOLD << YELLOW << "              INFORMACION DE TIENDA" << RESET << endl;
        lineaSep();
        cout << CYAN << "  Nombre:    " << RESET << nombre << endl;
        cout << CYAN << "  Direccion: " << RESET << direccion << endl;
        cout << CYAN << "  Telefono:  " << RESET << telefono << endl;
    }
};


// ======================================================
// PROGRAMA PRINCIPAL
// ======================================================

int main()
{
    // OBJETO TIENDA
    Tienda tienda;
    tienda.setNombre("Lenovo Store");
    tienda.setDireccion("Puno - Peru");
    tienda.setTelefono("+51 999 999 999");

    // OBJETO EMPLEADO
    Empleado empleado;
    empleado.setId("E001");
    empleado.setNombre("Carlos");
    empleado.setCargo("Vendedor");

    // OBJETO PROVEEDOR
    Proveedor proveedor;
    proveedor.setId("P001");
    proveedor.setNombre("Lenovo Peru");
    proveedor.setTelefono("+51 999 999 999");

    // ARRAYS DE OBJETOS
    Laptop laptops[10];
    Desktop desktops[10];
    Accesorio accesorios[10];
    Cliente clientes[10];

    int cantLaptops = 0;
    int cantDesktops = 0;
    int cantAccesorios = 0;
    int cantClientes = 0;

    int opcion;

    // PANTALLA DE INICIO
    system("clear");
    cout << endl;
    lineaSep();
    animarTexto(BOLD + string(BLUE) + "          LENOVO STORE         " + RESET);
    lineaSep();
    pantallaCarga();
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(400));


    // ==================================================
    // MENU PRINCIPAL
    // ==================================================

    do
    {
        system("clear");
        cout << endl;
        lineaSep();
        cout << BOLD << BLUE << "                   LENOVO STORE" << RESET << endl;
        lineaSep();
        cout << YELLOW << "  1." << RESET << " Registrar Laptop" << endl;
        cout << YELLOW << "  2." << RESET << " Registrar Desktop" << endl;
        cout << YELLOW << "  3." << RESET << " Registrar Accesorio" << endl;
        cout << YELLOW << "  4." << RESET << " Registrar Cliente" << endl;
        cout << YELLOW << "  5." << RESET << " Mostrar productos" << endl;
        cout << YELLOW << "  6." << RESET << " Mostrar clientes" << endl;
        cout << YELLOW << "  7." << RESET << " Mostrar empleado" << endl;
        cout << YELLOW << "  8." << RESET << " Mostrar proveedor" << endl;
        cout << YELLOW << "  9." << RESET << " Mostrar tienda" << endl;
        cout << RED    << " 10." << RESET << " Salir" << endl;
        lineaSep();
        cout << GREEN << "  Seleccione: " << RESET;
        cin >> opcion;


        switch(opcion)
        {

        // ==============================================
        // LAPTOP
        // ==============================================

        case 1:
        {
            system("clear");
            lineaSep();
            cout << BOLD << BLUE << "            REGISTRAR LAPTOP" << RESET << endl;
            lineaSep();

            if(cantLaptops < 10)
            {
                string texto;
                double precio;
                int stock, ram, almacenamiento;

                cin.ignore();

                cout << CYAN << "\n  ID: " << RESET;
                getline(cin, texto);
                laptops[cantLaptops].setId(texto);

                cout << CYAN << "  Nombre: " << RESET;
                getline(cin, texto);
                laptops[cantLaptops].setNombre(texto);

                cout << CYAN << "  Precio: " << RESET;
                cin >> precio;
                laptops[cantLaptops].setPrecio(precio);

                cout << CYAN << "  Stock: " << RESET;
                cin >> stock;
                laptops[cantLaptops].setStock(stock);

                cin.ignore();

                cout << CYAN << "  Procesador: " << RESET;
                getline(cin, texto);
                laptops[cantLaptops].setProcesador(texto);

                cout << CYAN << "  RAM (GB): " << RESET;
                cin >> ram;
                laptops[cantLaptops].setRam(ram);

                cout << CYAN << "  Almacenamiento (GB): " << RESET;
                cin >> almacenamiento;
                laptops[cantLaptops].setAlmacenamiento(almacenamiento);

                cantLaptops++;
                mensajeExito("Laptop registrada correctamente.");
            }
            else
            {
                mensajeError("No hay espacio para mas laptops.");
            }

            pausar();
            break;
        }


        // ==============================================
        // DESKTOP
        // ==============================================

        case 2:
        {
            system("clear");
            lineaSep();
            cout << BOLD << BLUE << "            REGISTRAR DESKTOP" << RESET << endl;
            lineaSep();

            if(cantDesktops < 10)
            {
                string texto;
                double precio;
                int stock, ram;

                cin.ignore();

                cout << CYAN << "\n  ID: " << RESET;
                getline(cin, texto);
                desktops[cantDesktops].setId(texto);

                cout << CYAN << "  Nombre: " << RESET;
                getline(cin, texto);
                desktops[cantDesktops].setNombre(texto);

                cout << CYAN << "  Precio: " << RESET;
                cin >> precio;
                desktops[cantDesktops].setPrecio(precio);

                cout << CYAN << "  Stock: " << RESET;
                cin >> stock;
                desktops[cantDesktops].setStock(stock);

                cin.ignore();

                cout << CYAN << "  Procesador: " << RESET;
                getline(cin, texto);
                desktops[cantDesktops].setProcesador(texto);

                cout << CYAN << "  RAM (GB): " << RESET;
                cin >> ram;
                desktops[cantDesktops].setRam(ram);

                cin.ignore();

                cout << CYAN << "  Tarjeta grafica: " << RESET;
                getline(cin, texto);
                desktops[cantDesktops].setTarjetaGrafica(texto);

                cantDesktops++;
                mensajeExito("Desktop registrada correctamente.");
            }
            else
            {
                mensajeError("No hay espacio para mas desktops.");
            }

            pausar();
            break;
        }


        // ==============================================
        // ACCESORIO
        // ==============================================

        case 3:
        {
            system("clear");
            lineaSep();
            cout << BOLD << BLUE << "            REGISTRAR ACCESORIO" << RESET << endl;
            lineaSep();

            if(cantAccesorios < 10)
            {
                string texto;
                double precio;
                int stock;

                cin.ignore();

                cout << CYAN << "\n  ID: " << RESET;
                getline(cin, texto);
                accesorios[cantAccesorios].setId(texto);

                cout << CYAN << "  Nombre: " << RESET;
                getline(cin, texto);
                accesorios[cantAccesorios].setNombre(texto);

                cout << CYAN << "  Precio: " << RESET;
                cin >> precio;
                accesorios[cantAccesorios].setPrecio(precio);

                cout << CYAN << "  Stock: " << RESET;
                cin >> stock;
                accesorios[cantAccesorios].setStock(stock);

                cin.ignore();

                cout << CYAN << "  Tipo: " << RESET;
                getline(cin, texto);
                accesorios[cantAccesorios].setTipo(texto);

                cout << CYAN << "  Compatibilidad: " << RESET;
                getline(cin, texto);
                accesorios[cantAccesorios].setCompatibilidad(texto);

                cantAccesorios++;
                mensajeExito("Accesorio registrado correctamente.");
            }
            else
            {
                mensajeError("No hay espacio para mas accesorios.");
            }

            pausar();
            break;
        }


        // ==============================================
        // CLIENTE
        // ==============================================

        case 4:
        {
            system("clear");
            lineaSep();
            cout << BOLD << BLUE << "            REGISTRAR CLIENTE" << RESET << endl;
            lineaSep();

            if(cantClientes < 10)
            {
                string texto;

                cin.ignore();

                cout << CYAN << "\n  ID: " << RESET;
                getline(cin, texto);
                clientes[cantClientes].setId(texto);

                cout << CYAN << "  Nombre: " << RESET;
                getline(cin, texto);
                clientes[cantClientes].setNombre(texto);

                cout << CYAN << "  Telefono: " << RESET;
                getline(cin, texto);
                clientes[cantClientes].setTelefono(texto);

                cout << CYAN << "  Correo: " << RESET;
                getline(cin, texto);
                clientes[cantClientes].setCorreo(texto);

                cantClientes++;
                mensajeExito("Cliente registrado correctamente.");
            }
            else
            {
                mensajeError("No hay espacio para mas clientes.");
            }

            pausar();
            break;
        }


        // ==============================================
        // MOSTRAR PRODUCTOS
        // ==============================================

        case 5:
        {
            system("clear");
            lineaSep();
            cout << BOLD << BLUE << "              LISTA DE PRODUCTOS" << RESET << endl;
            lineaSep();

            cout << BOLD << YELLOW << "\n  --- LAPTOPS ---" << RESET << endl;
            if(cantLaptops == 0) cout << "  (sin registros)" << endl;
            for(int i = 0; i < cantLaptops; i++)
            {
                cout << YELLOW << "\n  Laptop " << i + 1 << ":" << RESET << endl;
                laptops[i].mostrarLaptop();
            }

            cout << BOLD << YELLOW << "\n  --- DESKTOPS ---" << RESET << endl;
            if(cantDesktops == 0) cout << "  (sin registros)" << endl;
            for(int i = 0; i < cantDesktops; i++)
            {
                cout << YELLOW << "\n  Desktop " << i + 1 << ":" << RESET << endl;
                desktops[i].mostrarDesktop();
            }

            cout << BOLD << YELLOW << "\n  --- ACCESORIOS ---" << RESET << endl;
            if(cantAccesorios == 0) cout << "  (sin registros)" << endl;
            for(int i = 0; i < cantAccesorios; i++)
            {
                cout << YELLOW << "\n  Accesorio " << i + 1 << ":" << RESET << endl;
                accesorios[i].mostrarAccesorio();
            }

            pausar();
            break;
        }


        // ==============================================
        // MOSTRAR CLIENTES
        // ==============================================

        case 6:
        {
            system("clear");
            lineaSep();
            cout << BOLD << BLUE << "              LISTA DE CLIENTES" << RESET << endl;
            lineaSep();

            if(cantClientes == 0) cout << "\n  (sin registros)" << endl;
            for(int i = 0; i < cantClientes; i++)
            {
                cout << YELLOW << "\n  Cliente " << i + 1 << ":" << RESET << endl;
                clientes[i].mostrar();
            }

            pausar();
            break;
        }


        // ==============================================
        // MOSTRAR EMPLEADO
        // ==============================================

        case 7:
        {
            system("clear");
            lineaSep();
            cout << BOLD << BLUE << "              EMPLEADO" << RESET << endl;
            lineaSep();
            cout << endl;
            empleado.mostrar();

            pausar();
            break;
        }


        // ==============================================
        // MOSTRAR PROVEEDOR
        // ==============================================

        case 8:
        {
            system("clear");
            lineaSep();
            cout << BOLD << BLUE << "              PROVEEDOR" << RESET << endl;
            lineaSep();
            cout << endl;
            proveedor.mostrar();

            pausar();
            break;
        }


        // ==============================================
        // MOSTRAR TIENDA
        // ==============================================

        case 9:
        {
            system("clear");
            cout << endl;
            tienda.mostrar();

            pausar();
            break;
        }


        // ==============================================
        // SALIR
        // ==============================================

        case 10:
        {
            system("clear");
            lineaSep();
            animarTexto(GREEN + string(BOLD) + "       Gracias por usar Lenovo Store. Hasta luego!" + RESET);
            lineaSep();
            this_thread::sleep_for(chrono::milliseconds(800));
            break;
        }


        default:
        {
            mensajeError("Opcion incorrecta. Intente de nuevo.");
            pausar();
        }

        }

    } while(opcion != 10);


    return 0;
}