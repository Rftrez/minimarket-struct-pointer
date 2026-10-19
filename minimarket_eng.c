#include <stdio.h>
#include <string.h>

// STRUCTS
typedef struct {
    char name[50];
    int price;
    int stock;
} Product;

typedef struct {
    char name[50];
    int points;
} Member;


// DISPLAY PRODUCT CATALOG
void checkProduct(Product db[], int size) {
    printf("\n--- Product Catalog ---\n");

    for (int i = 0; i < size; i++) {
        printf("%d. %s - Rp%d (Stock: %d)\n",
               i + 1, db[i].name, db[i].price, db[i].stock);
    }
}


// DISPLAY MEMBER DATA
void checkMember(Member db[], int size) {
    printf("\n--- Member Data ---\n");

    for (int i = 0; i < size; i++) {
        printf("%d. %s - Points: %d\n",
               i + 1, db[i].name, db[i].points);
    }
}


//CHALLENGE 1: UPDATE PRODUCT PRICE
void updatePrice(Product *p, int newPrice) {
    if (newPrice > 0) {
        p->price = newPrice;
        printf("Product price updated successfully!\n");
    } else {
        printf("Invalid price!\n");
    }
}


//CHALLENGE 2: UPDATE PRODUCT NAME
void updateName(Product *p, char newName[]) {
    strcpy(p->name, newName);
    printf("Product name updated successfully!\n");
}


//CHALLENGE 3: REDEEM POINTS FOR A 10% DISCOUNT
void buyProduct(Product *p, Member *m, int qty) {
    if (qty <= 0) {
        printf("Invalid quantity!\n");
        return;
    }

    if (p->stock < qty) {
        printf("Insufficient stock for %s!\n", p->name);
        return;
    }

    p->stock -= qty;

    int total = p->price * qty;

    printf("\n--- Purchase Details ---\n");
    printf("Product: %s\n", p->name);
    printf("Quantity: %d\n", qty);
    printf("Original total: Rp%d\n", total);

    if (m != NULL && m->points >= 1000) {
        int discount = total / 10;
        total -= discount;
        m->points -= 1000;

        printf("10%% discount: Rp%d\n", discount);
        printf("1000 points redeemed.\n");
    }

    printf("Final total: Rp%d\n", total);

    if (m != NULL && total >= 20000) {
        m->points += 100;
        printf("%s earned 100 points!\n", m->name);
    }

    printf("Transaction successful!\n");
}
int main() {
    // 1. Setup Database
    Product dbProduct[5] = { {"Soap", 5000, 10}, {"Shampoo", 15000, 5}, {"Bread", 12000, 8}, {"Milk", 25000, 15}, {"Coffee", 22000, 20} };
    Member dbMember[2] = { {"Anisa", 500}, {"Budi", 100} };

    printf("=== WELCOME TO THE MINIMARKET ===\n");
    checkProduct(dbProduct, 5);
    checkMember(dbMember, 2);

    // 2. Transaction Simulation
    // REMEMBER! Use the & (Reference) symbol to pass the struct address from the array!
    buyProduct(&dbProduct[3], &dbMember[1], 2); // Budi buys 2 Milk (50k) -> Gets points
    buyProduct(&dbProduct[0], &dbMember[0], 1); // Anisa buys 1 Soap (5k) -> No points
    buyProduct(&dbProduct[2], NULL, 3);         // Non-member buyer buys 3 Bread (36k)

    // 3. Prove that the data has been modified
    printf("\n=== DATA UPDATE AFTER TRANSACTIONS ===");
    checkProduct(dbProduct, 5);
    checkMember(dbMember, 2);

    return 0;
}
