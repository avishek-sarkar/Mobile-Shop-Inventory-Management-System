#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

// Configuration constants
#define FILE_MOBILES    "mob.txt"
#define FILE_ADMIN      "admin.txt"
#define FILE_INCOME     "income.txt"
#define FILE_TEMP       "temp.txt"

#define PASSWORD_CASHIER "pass"
#define PASSWORD_ADMIN   "admin"

#define MAX_BRAND_LEN    20
#define MAX_MODEL_LEN    20
#define MAX_NAME_LEN     50
#define MAX_ADDRESS_LEN  100
#define MAX_DATE_LEN     20
#define MAX_PASSWORD_LEN 20
#define INPUT_BUFFER     256

#define LOW_STOCK_THRESHOLD 2 

// Structure definitions (must be before functions that use them)
struct income {
    int income;
    char idate[MAX_DATE_LEN];
    char brand[MAX_BRAND_LEN];
    int id;
} i;
int szi = sizeof(i);

struct sell {
    char bra[MAX_BRAND_LEN];
    char mod[MAX_MODEL_LEN];
    int I_D;
    int quan;
    int sell_price;
    char customer[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    char date[MAX_DATE_LEN];
} c;
long szc = sizeof(c);

struct mobile {
    char mob_brand[MAX_BRAND_LEN];
    int id;
    char mod[MAX_MODEL_LEN];
    int mrp;
    int wholesale_price;
    int quantity;
} s;
long sz = sizeof(s);

// Global file pointers
FILE *fp;
FILE *fi;
FILE *fc;

// Function prototypes
void seller_panel();
void cashier_panel();
void admin_panel();
void admin_display_record();
void display_record();
void insert_record();
void del_record();
void update_record();
void only_quantity();
void update_all();
void sell_status();
void today_sell_status();
void monthly_sell_status();
void sell_product();
void income_status();
void today_income();
void monthly_income();
void search();
void search_by_brand_prefix(const char *prefix, int prefix_len);
void sam();
void app();
void xia();
void oppo();
void vivo();
void nok();
void lg();
void sym();
void search_record();
void search_brand();
void search_price();

// Utility functions
void safe_string_copy(const char *source, char *dest, size_t dest_size) {
    if (source == NULL || dest == NULL || dest_size == 0) return;
    strncpy(dest, source, dest_size - 1);
    dest[dest_size - 1] = '\0';
}

void safe_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    }
}

void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void get_current_date(char *date_buffer, size_t size) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    snprintf(date_buffer, size, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
}

FILE* safe_fopen(const char *filename, const char *mode) {
    FILE *fp = fopen(filename, mode);
    if (fp == NULL) {
        printf("\nError: Cannot open file '%s'\n", filename);
    }
    return fp;
}

void display_mobile_info(struct mobile *m) {
    printf("\nBRAND    : %s", m->mob_brand);
    printf("\nID       : %d", m->id);
    printf("\nMODEL    : %s", m->mod);
    printf("\nPRICE    : %d", m->mrp);
    printf("\nQUANTITY : %d\n", m->quantity);
}

int authenticate_user(const char *expected_password) {
    char pass[MAX_PASSWORD_LEN];
    printf("Enter Your Password: ");
    scanf("%s", pass);
    return (strcmp(expected_password, pass) == 0);
}

void clear_screen_and_wait() {
    fflush(stdout);
    fflush(stdin);
    
    // Try ANSI escape codes first (works in modern terminals)
    printf("\033[2J\033[H");
    fflush(stdout);
    
    // Fallback to system cls
    system("cls");
    fflush(stdout);
}

int is_low_stock(int quantity) {
    return (quantity <= LOW_STOCK_THRESHOLD);
}

void show_low_stock_alert(struct mobile *m) {
    printf("\a");  // System beep
    printf("\n\033[1;31m");  // Red color
    printf("========================================\n");
    printf("*** LOW STOCK ALERT! ***\n");
    printf("========================================\n");
    printf("Brand: %s | Model: %s\n", m->mob_brand, m->mod);
    printf("ID: %d | Quantity: %d\n", m->id, m->quantity);
    printf("Action Required: Restock immediately!\n");
    printf("========================================\n");
    printf("\033[0m");  // Reset color
}

int get_positive_integer(const char *prompt) {
    int value;
    while(1) {
        printf("%s", prompt);
        if(scanf("%d", &value) == 1 && value > 0) {
            return value;
        }
        printf("\nError: Please enter a positive number!\n");
        fflush(stdin);
    }
}

int get_non_negative_integer(const char *prompt) {
    int value;
    while(1) {
        printf("%s", prompt);
        if(scanf("%d", &value) == 1 && value >= 0) {
            return value;
        }
        printf("\nError: Please enter a non-negative number!\n");
        fflush(stdin);
    }
}

void seller_panel() {
    int ch;
    while(1) {
        printf("\n\t\t\t1. All Products..\n");
        printf("\n\t\t\t2. Search for Mobile..\n");
        printf("\n\t\t\t0. Main Menu..\n");
        printf("\nEnter Your Choice :");
        scanf("%d",&ch);

        switch(ch) {
            case 1:
                display_record();
                break;
            case 2:
                search();
                break;
            case 0:
                clear_screen_and_wait();
                return;
            default:
                printf("\nWrong Choice..!!!!..\n\n");
        }

        printf("\nEnter any key to continue......\n");
        getch();
    }
}

void cashier_panel() {
    int ch;
    
    if(!authenticate_user(PASSWORD_CASHIER)) {
        printf("\nWrong Password!\n");
        return;
    }
    
    while(1) {
        printf("\n\t\t\t1. All Products..\n");
        printf("\n\t\t\t2. Search for Mobile..\n");
        printf("\n\t\t\t3. Sell Mobile..\n");
        printf("\n\t\t\t0. Main Menu..\n");
        printf("\nEnter Your Choice :");
        scanf("%d",&ch);

        switch(ch) {
            case 1:
                display_record();
                break;
            case 2:
                search();
                break;
            case 3:
                sell_product();
                break;
            case 0:
                clear_screen_and_wait();
                return;
            default:
                printf("\nWrong Choice..!!!!..\n\n");
        }

        printf("\nEnter any key to continue......\n");
        getch();
    }
}

void admin_panel() {
    int ch;
    
    if(!authenticate_user(PASSWORD_ADMIN)) {
        printf("\nWrong Password!\n");
        return;
    }

    while(1) {
        printf("\n\t\t\t[1]. Add Mobile..\n\n");
        printf("\t\t\t[2]. Update Record..\n\n");
        printf("\t\t\t[3]. Delete Record..\n\n");
        printf("\t\t\t[4]. All Products..\n\n");
        printf("\t\t\t[5]. Search For Mobile..\n\n");
        printf("\t\t\t[6]. Income Status..\n\n");
        printf("\t\t\t[7]. Sell Status..\n\n");
        printf("\t\t\t[8]. Sell Products..\n\n");
        printf("\t\t\t[0]. Main Menu..\n\n");

        printf("Enter Your Choice : ");
        scanf("%d",&ch);
        
        switch(ch) {
            case 1:
                insert_record();
                break;
            case 2:
                update_record();
                break;
            case 3:
                del_record();
                break;
            case 4:
                admin_display_record();
                break;
            case 5:
                search();
                break;
            case 6:
                income_status();
                break;
            case 7:
                sell_status();
                break;
            case 8:
                sell_product();
                break;
            case 0:
                clear_screen_and_wait();
                return;
            default:
                printf("Wrong Choice !!!!..\n\n");
        }
        
        printf("\n\nPress any key................\n");
        getch();
    }
}

void insert_record() {
    fp = safe_fopen(FILE_MOBILES, "ab+");
    if(fp == NULL) return;

    printf("\nEnter the Mobile brand : ");
    fflush(stdin);
    safe_input(s.mob_brand, MAX_BRAND_LEN);
    to_lowercase(s.mob_brand);
    
    printf("\nEnter Mobile Id : ");
    scanf("%d",&s.id);
    
    // Check for duplicate ID
    rewind(fp);
    struct mobile temp;
    while(fread(&temp, sz, 1, fp) == 1) {
        if(temp.id == s.id) {
            printf("\nError: Mobile with ID %d already exists!\n\n", s.id);
            fclose(fp);
            return;
        }
    }
    
    printf("\nEnter Model : ");
    fflush(stdin);
    safe_input(s.mod, MAX_MODEL_LEN);
    
    s.wholesale_price = get_positive_integer("\nEnter Wholesell Price : ");
    s.mrp = get_positive_integer("\nEnter MRP : ");
    s.quantity = get_non_negative_integer("\nEnter quantity of the mobile : ");

    fwrite(&s,sz,1,fp);
    printf("\n\nRecorded Successfully.........\n\n");
    fclose(fp);
}

void update_record() {
    int ch;
    
    while(1) {
        printf("\n\t\t\t[1]. Update Only Quantity..\n\n");
        printf("\t\t\t[2]. Update All..\n\n");
        printf("\t\t\t[0]. Main Menu\n\n");

        printf("Enter Your Choice : ");
        scanf("%d",&ch);

        switch(ch) {
            case 1:
                only_quantity();
                break;
            case 2:
                update_all();
                break;
            case 0:
                return;
            default:
                printf("\n\nWrong Choice !!!...\n\n");
        }

        printf("\nPress any key to continue....\n\n");
        getch();
    }
}

void only_quantity() {
    int I_D, p = 0;
    
    I_D = get_positive_integer("\nENTER ID : ");
    
    fp = safe_fopen(FILE_MOBILES, "rb+");
    if(fp == NULL) return;

    while(fread(&s,sz,1,fp) == 1) {
        if(I_D == s.id) {
            char v;
            display_mobile_info(&s);
            
            printf("\n\nAre you sure (Y/N)? ");
            v = getch();
            
            if(v == 'y' || v == 'Y') {
                s.quantity = get_non_negative_integer("\n\nEnter New Quantity : ");
                fseek(fp,-sz,1);
                fwrite(&s,sz,1,fp);
                printf("\n\nUpdated Successfully...\n\n");
            }
            else {
                printf("\n\nUpdate cancelled.\n\n");
            }
            p++;
            break;
        }
    }
    
    fclose(fp);
    if(p == 0)
        printf("\nThe mobile cannot be found!!!!....\n");
}

void update_all() {
    int I_D, p = 0;
    
    I_D = get_positive_integer("\nENTER ID : ");
    
    fp = safe_fopen(FILE_MOBILES, "rb+");
    if(fp == NULL) return;

    while(fread(&s,sz,1,fp) == 1) {
        if(I_D == s.id) {
            char v;
            display_mobile_info(&s);
            
            printf("\n\nAre you sure (Y/N)? ");
            v = getch();
            
            if(v == 'y' || v == 'Y') {
                printf("\n\nENTER NEW BRAND : ");
                fflush(stdin);
                safe_input(s.mob_brand, MAX_BRAND_LEN);
                to_lowercase(s.mob_brand);
                
                s.id = get_positive_integer("\nENTER NEW ID : ");
                
                printf("\nENTER NEW MODEL : ");
                fflush(stdin);
                safe_input(s.mod, MAX_MODEL_LEN);
                
                s.wholesale_price = get_positive_integer("\nENTER NEW  WHOLESALE PRICE : ");
                s.mrp = get_positive_integer("\nENTER NEW MRP : ");
                s.quantity = get_non_negative_integer("\nENTER NEW QUANTITY : ");
                
                fseek(fp,-sz,1);
                fwrite(&s,sz,1,fp);
                printf("\n\nUpdated Successfully...\n\n");
                p++;
                break;
            }
            else {
                printf("\n\nUpdate cancelled.\n\n");
                break;
            }
        }
    }
    
    fclose(fp);
    if(p == 0)
        printf("\nThe mobile cannot be found!!!!....\n");
}

void del_record() {
    FILE *ft;
    int id, flag = 0;
    
    printf("Enter the id : ");
    scanf("%d",&id);
    
    fp = safe_fopen(FILE_MOBILES, "rb");
    ft = safe_fopen(FILE_TEMP, "wb");
    
    if(fp == NULL || ft == NULL) {
        if(fp) fclose(fp);
        if(ft) fclose(ft);
        return;
    }

    while(fread(&s,sz,1,fp) == 1) {
        if(id == s.id) {
            flag = 1;
        }
        else {
            fwrite(&s,sz,1,ft);
        }
    }
    
    fclose(fp);
    fclose(ft);
    
    remove(FILE_MOBILES);
    rename(FILE_TEMP, FILE_MOBILES);
    
    if(flag == 0) {
        printf("The record cannot be found !!!!\n");
    }
    else {
        printf("The record deleted successfully\n");
    }
}

void admin_display_record() {
    fp = safe_fopen(FILE_MOBILES, "rb");
    if(fp == NULL) return;

    printf("\t\t\t\t*******All products details*******\n\n");
    printf("%-15s %-14s %-15s %-20s %-10s %s\n\n","BRAND","ID","MODEL","WHOLESALEPRICE","MRP","QUANTITY");

    while(fread(&s,sz,1,fp) == 1) {
        if(is_low_stock(s.quantity)) {
            printf("\033[1;31m");
        }
        printf("%-17s%-15d%-17s%-19d%-15d%d",s.mob_brand,s.id,s.mod,s.wholesale_price,s.mrp,s.quantity);
        if(is_low_stock(s.quantity)) {
            printf(" ** LOW STOCK **");
            printf("\033[0m");
        }
        printf("\n");
    }
    
    fclose(fp);
}

void display_record() {
    fp = safe_fopen(FILE_MOBILES, "rb");
    if(fp == NULL) return;

    printf("\t\t\t\t*******All products details*******\n\n");
    printf("%-15s %-14s %-15s %-10s %s\n\n","BRAND","ID","MODEL","MRP","QUANTITY");

    while(fread(&s,sz,1,fp) == 1) {
        if(is_low_stock(s.quantity)) {
            printf("\033[1;31m");
        }
        printf("%-17s%-15d%-17s%-15d%d",s.mob_brand,s.id,s.mod,s.mrp,s.quantity);
        if(is_low_stock(s.quantity)) {
            printf(" ** LOW STOCK **");
            printf("\033[0m");
        }
        printf("\n");
    }
    
    fclose(fp);
}

void sell_status() {
    int ch;
    
    while(1) {
        printf("\n\t\t\t[1]. Todays Sell status !!!...\n\n");
        printf("\t\t\t[2]. Monthly Sell Status...\n\n");
        printf("\t\t\t[0]. Main Menu..\n\n");
        printf("Enter Your Choice :");
        scanf("%d",&ch);

        switch(ch) {
            case 1:
                today_sell_status();
                break;
            case 2:
                monthly_sell_status();
                break;
            case 0:
                return;
            default:
                printf("\n\nWrong Choice..\n\n");
        }
        printf("Press any key to continue....\n\n");
        getch();
    }
}

void today_sell_status() {
    char my_date[MAX_DATE_LEN];
    int p = 0;
    
    fc = safe_fopen(FILE_ADMIN, "rb+");
    if(fc==NULL) return;
    
    get_current_date(my_date, MAX_DATE_LEN);

    while(fread(&c,szc,1,fc)== 1) {
        if(c.date[0] == my_date[0] && c.date[1] == my_date[1]) {
            printf("BRAND : %s\n",c.bra);
            printf("MODEL : %s\n",c.mod);
            printf("ID : %d\n",c.I_D);
            printf("QUANTITY : %d\n",c.quan);
            printf("TOTAL PRICE : %d\n",c.sell_price);
            printf("DATE : %s\n",c.date);
            printf("NAME OF THE CUSTOMER : %s\n",c.customer);
            printf("ADDRESS OF THE CUSTOMER : %s\n\n\n",c.address);
            p++;
        }
    }

    if(p == 0) {
        printf("NO SELL !!!...\n\n");
    }

    fclose(fc);
}

void monthly_sell_status() {
    char my_date[MAX_DATE_LEN];
    int p = 0;
    
    fc = safe_fopen(FILE_ADMIN, "rb+");
    if(fc==NULL) return;
    
    get_current_date(my_date, MAX_DATE_LEN);

    while(fread(&c,szc,1,fc)== 1) {
        if(c.date[3] == my_date[3] && c.date[4] == my_date[4]) {
            printf("BRAND : %s\n",c.bra);
            printf("MODEL : %s\n",c.mod);
            printf("ID : %d\n",c.I_D);
            printf("QUANTITY : %d\n",c.quan);
            printf("TOTAL PRICE : %d\n",c.sell_price);
            printf("DATE : %s\n",c.date);
            printf("NAME OF THE CUSTOMER : %s\n",c.customer);
            printf("ADDRESS OF THE CUSTOMER : %s\n\n\n",c.address);
            p++;
        }
    }

    if(p == 0) {
        printf("NO SELL !!!...\n\n");
    }

    fclose(fc);
}

void sell_product(){
    int I_D, quantity, total_price, p = 0;
    char customer[MAX_NAME_LEN];
    char address[MAX_ADDRESS_LEN];
    char my_date[MAX_DATE_LEN];
    char v;

    I_D = get_positive_integer("Enter Mobile ID :");

    fp = safe_fopen(FILE_MOBILES, "rb+");
    fc = safe_fopen(FILE_ADMIN, "ab+");
    fi = safe_fopen(FILE_INCOME, "ab+");
    
    if(fp == NULL || fc == NULL || fi == NULL) {
        if(fp) fclose(fp);
        if(fc) fclose(fc);
        if(fi) fclose(fi);
        return;
    }

    while(fread(&s,sz,1,fp) == 1){
        if(I_D == s.id){
            display_mobile_info(&s);
            
            printf("\n\nAre you sure? Press Y for yes: ");
            v = getch();
            
            if(v == 'y' || v == 'Y'){
                if(s.quantity >= 1){
                    quantity = get_positive_integer("\n\nEnter Mobile Quantity :");

                    if(quantity <= s.quantity){
                        total_price = get_positive_integer("\n\nEnter Total Price :");

                        printf("\n\nEnter Customer Name :");
                        fflush(stdin);
                        safe_input(customer, MAX_NAME_LEN);

                        printf("\n\nEnter Customer Address : ");
                        fflush(stdin);
                        safe_input(address, MAX_ADDRESS_LEN);

                        // Record sell information
                        safe_string_copy(s.mob_brand, c.bra, MAX_BRAND_LEN);
                        safe_string_copy(s.mod, c.mod, MAX_MODEL_LEN);
                        c.I_D = s.id;
                        c.quan = quantity;
                        c.sell_price = total_price;
                        safe_string_copy(customer, c.customer, MAX_NAME_LEN);
                        safe_string_copy(address, c.address, MAX_ADDRESS_LEN);

                        get_current_date(my_date, MAX_DATE_LEN);
                        safe_string_copy(my_date, c.date, MAX_DATE_LEN);

                        // Update inventory
                        s.quantity = s.quantity - quantity;
                        fseek(fp,-sz,1);
                        fwrite(&s,sz,1,fp);

                        // Check for low stock after sale
                        if(is_low_stock(s.quantity)) {
                            show_low_stock_alert(&s);
                        }

                        // Record income
                        i.income = total_price - (quantity * s.wholesale_price);
                        safe_string_copy(my_date, i.idate, MAX_DATE_LEN);
                        i.id = I_D;
                        safe_string_copy(s.mob_brand, i.brand, MAX_BRAND_LEN);

                        fwrite(&i,szi,1,fi);
                        fwrite(&c,szc,1,fc);
                        
                        printf("\n\nRecorded Successfully.........\n\n");
                    }
                    else{
                        printf("\n\nSorry, We Have Only %d piece....\n\n",s.quantity);
                    }
                }
                else{
                    printf("\n\nStock Out.!!!!...");
                }
            }
            else{
                return;
            }
            p++;
            break;
        }
    }

    if(p==0){
        printf("\n\nThe Mobile Cannot be Found !!!!...");
    }

    fclose(fp);
    fclose(fc);
    fclose(fi);
}

void income_status() {
    int ch;
    
    while(1) {
        printf("\n\t\t\t[1]. Todays Income Status..\n\n");
        printf("\t\t\t[2]. This Months Income Status..\n\n");
        printf("\t\t\t[0]. Exit..\n\n");
        printf("Enter Your Choice :");
        scanf("%d",&ch);

        switch(ch) {
            case 1:
                today_income();
                break;
            case 2:
                monthly_income();
                break;
            case 0:
                return;
            default:
                printf("Wrong Choice !!!...\n\n");
        }

        printf("\n\nPress any key to continue....\n\n");
        getch();
    }
}

void today_income() {
    char my_date[MAX_DATE_LEN];
    int p = 0, in = 0;
    
    fi = safe_fopen(FILE_INCOME, "rb");
    if(fi == NULL) return;

    get_current_date(my_date, MAX_DATE_LEN);

    while(fread(&i,szi,1,fi) == 1) {
        if(my_date[0] == i.idate[0] && my_date[1] == i.idate[1]) {
            in = in + i.income;
            printf("BRAND : %s\n",i.brand);
            printf("ID : %d\n",i.id);
            printf("INCOME : %d\n",i.income);
            printf("TIME : %s\n\n",i.idate);
            p++;
        }
    }

    printf("\n\nToday Total Income : %d\n",in);

    if(p == 0) {
        printf("\nNO SELL !!!...\n\n");
    }
    
    fclose(fi);
}

void monthly_income() {
    char my_date[MAX_DATE_LEN];
    int p = 0, in = 0;
    
    fi = safe_fopen(FILE_INCOME, "rb");
    if(fi == NULL) return;

    get_current_date(my_date, MAX_DATE_LEN);

    while(fread(&i,szi,1,fi) == 1) {
        if(my_date[3] == i.idate[3] && my_date[4] == i.idate[4]) {
            in = in + i.income;
            printf("BRAND : %s\n",i.brand);
            printf("ID : %d\n",i.id);
            printf("INCOME : %d\n",i.income);
            printf("TIME : %s\n\n",i.idate);
            p++;
        }
    }

    printf("\n\nMonthly Total Income : %d\n",in);

    if(p == 0) {
        printf("\nNO SELL !!!...\n\n");
    }
    
    fclose(fi);
}

void search() {
    int ch;
    
    while(1) {
        printf("\n1.SAMSUNG.\n2.APPLE\n3.VIVO\n4.OPPO\n5.XIAOMI\n6.NOKIA\n7.LG\n8.SYMPHONY\n9.Others\n0.Main Menu\n\n");

        printf("Enter Your Choice : ");
        scanf("%d",&ch);

        switch(ch) {
            case 1:
                sam();
                break;
            case 2:
                app();
                break;
            case 3:
                vivo();
                break;
            case 4:
                oppo();
                break;
            case 5:
                xia();
                break;
            case 6:
                nok();
                break;
            case 7:
                lg();
                break;
            case 8:
                sym();
                break;
            case 9:
                search_record();
                break;
            case 0:
                return;
            default:
                printf("\n\nWrong Choice !!..\n\n");
        }

        printf("\n\nPress Any Key To Continue ......\n\n");
        getch();
    }
}

// Generic brand search function
void search_by_brand_prefix(const char *prefix, int prefix_len){
    int p = 0;
    
    fp = safe_fopen(FILE_MOBILES, "rb");
    if(fp == NULL) return;

    while(fread(&s,sz,1,fp) == 1){
        int match = 1;
        for(int j = 0; j < prefix_len; j++){
            if(tolower(s.mob_brand[j]) != tolower(prefix[j])){
                match = 0;
                break;
            }
        }
        
        if(match){
            display_mobile_info(&s);
            p++;
        }
    }

    if(p == 0){
        printf("\n\nThe Mobile Is not Available !!!..\n\n");
    }
    
    fclose(fp);
}

void sam(){ search_by_brand_prefix("sam", 3); }

void app(){ search_by_brand_prefix("app", 3); }

void xia(){ search_by_brand_prefix("xia", 3); }

void oppo(){ search_by_brand_prefix("opp", 3); }

void vivo(){ search_by_brand_prefix("viv", 3); }

void nok(){ search_by_brand_prefix("nok", 3); }

void lg(){ search_by_brand_prefix("lg", 2); }

void sym(){ search_by_brand_prefix("sym", 3); }

void search_record() {
    int c;
    printf("\t\t\t\t*********SEARCH*********\n\n");
    
    while(1) {
        printf("[1]. Search By Brand\n\n");
        printf("[2]. Search By Price Range\n\n");
        printf("[3]. Main Menu\n\n");
        printf("Enter your choice : ");
        scanf("%d",&c);

        switch(c) {
            case 1:
                search_brand();
                break;
            case 2:
                search_price();
                break;
            case 3:
                return;
            default:
                printf("Wrong choice !!!!.....\n");
        }
        printf("\nPress any key to continue...\n\n");
        getch();
    }
}

void search_brand() {
    char b[MAX_BRAND_LEN];
    int p = 0;
    
    printf("Enter Brand : ");
    scanf("%19s",b);
    
    fp = safe_fopen(FILE_MOBILES, "rb+");
    if(fp == NULL) return;

    while(fread(&s,sz,1,fp) == 1) {
        if(s.mob_brand[0] == b[0] && s.mob_brand[1] == b[1]) {
            display_mobile_info(&s);
            p++;
        }
    }
    
    fclose(fp);
    if(p == 0)
        printf("The mobile cannot be found !!!!\n");
}

void search_price() {
    int maxpri, minpri, x = 0;
    
    minpri = get_non_negative_integer("\n\nEnter Minimum price : ");
    maxpri = get_positive_integer("Enter Maximum price : ");
    
    if(minpri > maxpri) {
        printf("\nError: Minimum price cannot be greater than maximum price!\n");
        return;
    }
    
    fp = safe_fopen(FILE_MOBILES, "rb");
    if(fp == NULL) return;

    while(fread(&s,sz,1,fp) == 1) {
        if(s.mrp<=maxpri && s.mrp>=minpri) {
            display_mobile_info(&s);
            x++;
        }
    }
    
    fclose(fp);
    if(x == 0) {
        printf("The mobile cannot be found !!!!\n");
    }
}

int main() {
    int ch;

    while(1) {
        clear_screen_and_wait();

        printf("\t\t\t\t**********************************************\n");
        printf("\t\t\t\t  WELCOME TO OUR MOBILE SHOP MANAGEMENT SYSTEM\n");
        printf("\t\t\t\t**********************************************\n\n");

        printf("\t\t\t\t\t[1]. SELLER\n");
        printf("\n\t\t\t\t\t[2]. CASHIER\n\n");
        printf("\t\t\t\t\t[3]. ADMIN\n\n");
        printf("\t\t\t\t\t[0]. EXIT\n\n");

        printf("Enter your choice : ");
        fflush(stdout);
        scanf("%d",&ch);

        switch(ch) {
            case 1:
                clear_screen_and_wait();
                seller_panel();
                break;
            case 2:
                clear_screen_and_wait();
                cashier_panel();
                break;
            case 3:
                clear_screen_and_wait();
                admin_panel();
                break;
            case 0:
                exit(0);
            default:
                clear_screen_and_wait();
                printf("\n\nWrong Choice!!!......");
        }

        printf("\n\nPress any key................\n");
        getch();
    }
}
