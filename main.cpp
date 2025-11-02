#include "main.h"

#include <fstream>
#include <iostream>

using namespace  std;

int main (){

    const string path = "..\\disks\\disco1.img";

    ifstream FAT16Disk(path,ios::binary);
    if (!FAT16Disk.is_open()) {
        cout << "Erro ao Abrir o arquivo";
        return 1;
    }

    BootSector bootSector;
    if (!readBootSector(FAT16Disk, bootSector)) {
        cout << "Falha ao ler Boot Sector.\n";
        return 1;
    }

    int option;
    while (option != 0) {
        evokeMenu();
        cin >> option;
        switch (option) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                printBootInfo(bootSector);
                break;
            case 0:
                return 0;
            default:
                cout << "Digite uma opcao valida" << endl;
        }
    }

    return 0;
}

// functions
bool readBootSector(ifstream& img, BootSector& boot) {
    img.seekg(0, ios::beg);
    img.read(reinterpret_cast<char*>(&boot), sizeof(BootSector));
    return !img.fail();
}
void printBootInfo(const BootSector& boot) {
    cout << "=== Boot Sector Info ===" << endl;
    cout << "OEM Name: " << boot.OEMName<< endl;
    cout << "Bytes por setor: " << boot.bytesPerSector << endl;
    cout << "Setores por cluster: " << (int)boot.sectorsPerCluster << endl;
    cout << "Setores reservados: " << boot.reservedSectors << endl;
    cout << "Num. FATs: " << (int)boot.numFATs << endl;
    cout << "Entradas raiz: " << boot.rootEntries << endl;
    // cout << "Small Number of Sectors: " << boot.totalSectors16 << endl;
    // cout << "Media Descriptor: " << (int)boot.mediaDescriptor << endl;
    // cout << "Large Number of Sectors: " << boot.totalSectors32 << endl;
    cout << "Tamanho da FAT (setores): " << boot.FATSize << endl;
}
void evokeMenu() {
    cout << endl << "Menu" << endl;
    cout << "1 - Listar o conteudo do disco" << endl;
    cout << "2 - Listar o conteudo de um arquivo" << endl;
    cout << "3 - Exibir os atributos de um arquivo" << endl;
    cout << "4 - Renomear um arquivo" << endl;
    cout << "5 - Apagar/remover um arquivo" << endl;
    cout << "6 - Inserir/criar um novo arquivo	" << endl;
    cout << "7 - Ler Boot Sector" << endl;
    cout << "0 - Sair" << endl;
}