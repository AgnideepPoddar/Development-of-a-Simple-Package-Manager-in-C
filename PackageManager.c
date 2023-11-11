#include <stdio.h>
#include <string.h>

#define MAX_PACKAGES 100

struct Package {
    char name[50];
    int installed;
};

struct PackageManager {
    struct Package packages[MAX_PACKAGES];
    int numPackages;
};

void initializePackageManager(struct PackageManager *pm) {
    pm->numPackages = 0;
}

void installPackage(struct PackageManager *pm, const char *name) {
    if (pm->numPackages >= MAX_PACKAGES) {
        printf("Package manager is full. Cannot install more packages.\n");
        return;
    }

    for (int i = 0; i < pm->numPackages; i++) {
        if (strcmp(pm->packages[i].name, name) == 0) {
            printf("%s is already installed.\n", name);
            return;
        }
    }

    strcpy(pm->packages[pm->numPackages].name, name);
    pm->packages[pm->numPackages].installed = 1;
    pm->numPackages++;
    printf("%s has been installed.\n", name);
}

void removePackage(struct PackageManager *pm, const char *name) {
    for (int i = 0; i < pm->numPackages; i++) {
        if (strcmp(pm->packages[i].name, name) == 0) {
            pm->packages[i].installed = 0;
            printf("%s has been removed.\n", name);
            return;
        }
    }

    printf("%s is not installed.\n", name);
}

void listPackages(struct PackageManager *pm) {
    printf("Installed packages:\n");
    for (int i = 0; i < pm->numPackages; i++) {
        if (pm->packages[i].installed) {
            printf("%s\n", pm->packages[i].name);
        }
    }
}

int main() {
    struct PackageManager pm;
    initializePackageManager(&pm);

    while (1) {
        printf("\nOptions:\n");
        printf("1. Install Package\n");
        printf("2. Remove Package\n");
        printf("3. List Installed Packages\n");
        printf("4. Exit\n");

        int choice;
        char packageName[50];
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the package name: ");
                scanf("%s", packageName);
                installPackage(&pm, packageName);
                break;
            case 2:
                printf("Enter the package name: ");
                scanf("%s", packageName);
                removePackage(&pm, packageName);
                break;
            case 3:
                listPackages(&pm);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
