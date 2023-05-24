#include <stdio.h>
#include <string.h>

// Structure representant un ordinateur
typedef struct {
    int serialNumber;
    char name[50];
    int RAM;
    char GPU[50];
    char CPU[50];
    char storage[50];
} Computer;

// Fonction pour ajouter un nouvel ordinateur
void addComputer(Computer* computers, int* count) {
    Computer newComputer;
    printf("Numero de serie : ");
    scanf_s("%d", &newComputer.serialNumber);
    printf("Nom de l'ordinateur : ");
    scanf_s("%s", newComputer.name, sizeof(newComputer.name));
    printf("RAM : ");
    scanf_s("%d", &newComputer.RAM);
    printf("GPU : ");
    scanf_s("%s", &newComputer.GPU, sizeof(newComputer.GPU));
    printf("CPU : ");
    scanf_s("%s", &newComputer.CPU, sizeof(newComputer.CPU));
    printf("Stockage : ");
    scanf_s("%s", &newComputer.storage, sizeof(newComputer.storage));
    computers[*count] = newComputer;
    (*count)++;
    printf("Nouvel ordinateur ajoute avec succes.\n");
}

// Fonction pour consulter les details d'un ordinateur
void displayComputer(const Computer* computer) {
    printf("Numero de serie : %d\n", computer->serialNumber);
    printf("Nom : %s\n", computer->name);
    printf("RAM : %d\n", computer->RAM);
    printf("GPU : %s\n", computer->GPU);
    printf("CPU : %s\n", computer->CPU);
    printf("Stockage : %s\n", computer->storage);
}

// Fonction pour rechercher les ordinateurs en fonction du nom, du GPU, du CPU ou du stockage
void searchComputers(const Computer* computers, int count, const char* searchTerm, int searchOption) {
    int totalCount = 0;
    for (int i = 0; i < count; i++) {
        if (searchOption == 1 && strcmp(computers[i].name, searchTerm) == 0) {
            displayComputer(&computers[i]);
            totalCount++;
        }
        else if (searchOption == 2 && strcmp(computers[i].GPU, searchTerm) == 0) {
            displayComputer(&computers[i]);
            totalCount++;
        }
        else if (searchOption == 3 && strcmp(computers[i].CPU, searchTerm) == 0) {
            displayComputer(&computers[i]);
            totalCount++;
        }
        else if (searchOption == 4 && strcmp(computers[i].storage, searchTerm) == 0) {
            displayComputer(&computers[i]);
            totalCount++;
        }
    }
    printf("Nombre d'ordinateurs correspondant a la recherche : %d\n", totalCount);
}

// Fonction pour consulter le nombre d'ordinateurs presents dans le stock en fonction du nom de l'ordinateur, GPU, CPU ou stockage
void countComputers(const Computer* computers, int count) {
    int searchOption;
    printf("Rechercher par :\n");
    printf("1. Nom de l'ordinateur\n");
    printf("2. GPU\n");
    printf("3. CPU\n");
    printf("4. Stockage\n");
    printf("Choix : ");
    scanf_s("%d", &searchOption, sizeof(searchOption));

    char searchTerm[50];
    printf("Terme de recherche : ");
    scanf_s("%s", searchTerm, sizeof(searchTerm));

    searchComputers(computers, count, searchTerm, searchOption);
}

int main() {
    // Declaration et initialisation des variables
    Computer computers[100];
    int count = 0;
    int choice;

    do {
        // Menu principal
        printf("\n--- Gestion des ordinateurs ---\n");
        printf("1. Ajouter un nouvel ordinateur\n");
        printf("2. Consulter les details d'un ordinateur\n");
        printf("3. Consulter le nombre d'ordinateurs par nom, GPU, CPU ou stockage\n");
        printf("4. Quitter\n");
        printf("Choix : ");
        scanf_s("%d", &choice, sizeof(choice));

        switch (choice) {
        case 1:
            addComputer(computers, &count);
            break;
        case 2: {
            int serialNumber;
            printf("Numero de serie de l'ordinateur : ");
            scanf_s("%d", &serialNumber);
            int found = 0;
            for (int i = 0; i < count; i++) {
                if (computers[i].serialNumber == serialNumber) {
                    displayComputer(&computers[i]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Ordinateur non trouve avec le numero de serie %d.\n", serialNumber);
            }
            break;
        }
        case 3:
            countComputers(computers, count);
            break;
        case 4:
            printf("Au revoir !\n");
            break;
        default:
            printf("Choix invalide.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}
