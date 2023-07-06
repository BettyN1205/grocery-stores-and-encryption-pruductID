#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)
#include <time.h>


#define CATEGORY_NUM 12

int i, j, k;

struct PRODUCT {
    char pName[50];
    char pCategory[20];
    char manufacturer[30];
    double cost;
    double price;
    int quantity;
    char purchased_date[11];
    char production_date[11];
    char expiry_date[11];
    int store_code;
    char currency[5];
    char* barcode;
};

struct CATEGORY {
    char cate_name[20];
    char cate_code;
};

char* encrypt_names(char* strf1);
char* encrupt_category(char* s, int k);
char* encrypt_prices(double* prices);
char* encrypt_integer(int* integer);
char* encrypt_date(char* s);
char* encrypt_4digit(int num);
char* encrypt_word(char* s, int k1, int k2);
char* connection(char* str1, char* str2, char* str3, char* str4, char* str5, char* str6, char* str7, char* str8, char* str9, char* str10, char* str11);


void creat_barcode(struct PRODUCT* pc, int y);
void print_product(struct PRODUCT* p, int x);
double checkPromotion(struct PRODUCT* product);

int main() {

    int action;
    int PRODUCT_NUM = 36;

    int check_sale;

    char search_item[50] = "";

    int cNumber_change = 0;
    int pNumber_change = 0;

    char* paymentMethod1 = "CreditCard";
    char* paymentMethod2 = "Cash";
    char* paymentMethod3 = "Debit";
    char* paymentMethod4 = "ApplePay";

    double total_amount = 0.0;
    double total_return = 0.0;


    struct CATEGORY* categories = (struct CATEGORY*)malloc(CATEGORY_NUM * sizeof(struct CATEGORY));
    strcpy(categories[0].cate_name, "Meat"); categories[0].cate_code = 'A';
    strcpy(categories[1].cate_name, "Deli"); categories[1].cate_code = 'B';
    strcpy(categories[2].cate_name, "Pharmacy"); categories[2].cate_code = 'C';
    strcpy(categories[3].cate_name, "Seafood"); categories[3].cate_code = 'D';
    strcpy(categories[4].cate_name, "Beverage"); categories[4].cate_code = 'E';
    strcpy(categories[5].cate_name, "Canned"); categories[5].cate_code = 'F';
    strcpy(categories[6].cate_name, "Jarred"); categories[6].cate_code = 'G';
    strcpy(categories[7].cate_name, "DryFood"); categories[7].cate_code = 'H';
    strcpy(categories[8].cate_name, "Dairy"); categories[8].cate_code = 'I';
    strcpy(categories[9].cate_name, "Bakery"); categories[9].cate_code = 'J';
    strcpy(categories[10].cate_name, "PersonalCare"); categories[10].cate_code = 'K';
    strcpy(categories[11].cate_name, "PaperGoods"); categories[11].cate_code = 'L';

    struct PRODUCT* product = (struct PRODUCT*)malloc(PRODUCT_NUM * sizeof(struct PRODUCT));

    strcpy(product[0].pName, "Beef");
    strcpy(product[0].pCategory, "Meat");
    strcpy(product[0].manufacturer, "ABCBeefCampany");
    product[0].cost = 10.0;
    product[0].price = 15.0;
    product[0].quantity = 100;
    strcpy(product[0].purchased_date, "2023-03-29");
    strcpy(product[0].production_date, "2021-12-01");
    strcpy(product[0].expiry_date, "2023-12-31");
    product[0].store_code = 1234;
    strcpy(product[0].currency, "CAD");

    strcpy(product[1].pName, "Turkey");
    strcpy(product[1].pCategory, "Deli");
    strcpy(product[1].manufacturer, "ABCTurkeyCompany");
    product[1].cost = 8.0;
    product[1].price = 12.0;
    product[1].quantity = 80;
    strcpy(product[1].purchased_date, "2023-03-29");
    strcpy(product[1].production_date, "2022-01-14");
    strcpy(product[1].expiry_date, "2024-01-31");
    product[1].store_code = 1234;
    strcpy(product[1].currency, "CAD");

    strcpy(product[2].pName, "Ibuprofen");
    strcpy(product[2].pCategory, "Pharmacy");
    strcpy(product[2].manufacturer, "ABCPharmaCompany");
    product[2].cost = 2.0;
    product[2].price = 5.0;
    product[2].quantity = 200;
    strcpy(product[2].purchased_date, "2023-03-29");
    strcpy(product[2].production_date, "2023-03-20");
    strcpy(product[2].expiry_date, "2025-03-31");
    product[2].store_code = 1234;
    strcpy(product[2].currency, "CAD");

    strcpy(product[3].pName, "Salmon");
    strcpy(product[3].pCategory, "Seafood");
    strcpy(product[3].manufacturer, "ABCSalmonCompany");
    product[3].cost = 15.0;
    product[3].price = 20.0;
    product[3].quantity = 50;
    strcpy(product[3].purchased_date, "2023-03-29");
    strcpy(product[3].production_date, "2023-03-25");
    strcpy(product[3].expiry_date, "2023-03-31");
    product[3].store_code = 1234;
    strcpy(product[3].currency, "CAD");

    strcpy(product[4].pName, "Soda");
    strcpy(product[4].pCategory, "Beverage");
    strcpy(product[4].manufacturer, "ABCBeverageCompany");
    product[4].cost = 1.5;
    product[4].price = 3.0;
    product[4].quantity = 150;
    strcpy(product[4].purchased_date, "2023-03-29");
    strcpy(product[4].production_date, "2023-03-27");
    strcpy(product[4].expiry_date, "2024-03-31");
    product[4].store_code = 1234;
    strcpy(product[4].currency, "CAD");

    strcpy(product[5].pName, "CannedTomatoes");
    strcpy(product[5].pCategory, "Canned");
    strcpy(product[5].manufacturer, "ABCCannedFoods");
    product[5].cost = 1.0;
    product[5].price = 2.0;
    product[5].quantity = 200;
    strcpy(product[5].purchased_date, "2023-03-29");
    strcpy(product[5].production_date, "2023-03-28");
    strcpy(product[5].expiry_date, "2025-03-31");
    product[5].store_code = 1234;
    strcpy(product[5].currency, "CAD");

    strcpy(product[6].pName, "StrawberryJam");
    strcpy(product[6].pCategory, "Jarred");
    strcpy(product[6].manufacturer, "ABCFoodCompany");
    product[6].cost = 2.0;
    product[6].price = 4.0;
    product[6].quantity = 100;
    strcpy(product[6].purchased_date, "2023-03-29");
    strcpy(product[6].production_date, "2023-03-27");
    strcpy(product[6].expiry_date, "2024-12-31");
    product[6].store_code = 1234;
    strcpy(product[6].currency, "CAD");

    strcpy(product[7].pName, "PennePasta");
    strcpy(product[7].pCategory, "DryFood");
    strcpy(product[7].manufacturer, "NourishFoodsInc.");
    product[7].cost = 1.5;
    product[7].price = 3.0;
    product[7].quantity = 150;
    strcpy(product[7].purchased_date, "2023-03-29");
    strcpy(product[7].production_date, "2023-03-26");
    strcpy(product[7].expiry_date, "2025-06-30");
    product[7].store_code = 1234;
    strcpy(product[7].currency, "CAD");

    strcpy(product[8].pName, "CheeseWedge");
    strcpy(product[8].pCategory, "Dairy");
    strcpy(product[8].manufacturer, "DairyDelightsInc.");
    product[8].cost = 2.5;
    product[8].price = 5.0;
    product[8].quantity = 80;
    strcpy(product[8].purchased_date, "2023-03-29");
    strcpy(product[8].production_date, "2023-03-25");
    strcpy(product[8].expiry_date, "2023-09-30");
    product[8].store_code = 1234;
    strcpy(product[8].currency, "CAD");

    strcpy(product[9].pName, "Croissant");
    strcpy(product[9].pCategory, "Bakery");
    strcpy(product[9].manufacturer, "BakeryCo.");
    product[9].cost = 1.0;
    product[9].price = 2.5;
    product[9].quantity = 120;
    strcpy(product[9].purchased_date, "2023-03-29");
    strcpy(product[9].production_date, "2023-03-28");
    strcpy(product[9].expiry_date, "2023-03-30");
    product[9].store_code = 1234;
    strcpy(product[9].currency, "CAD");

    strcpy(product[10].pName, "Toothbrush");
    strcpy(product[10].pCategory, "PersonalCare");
    strcpy(product[10].manufacturer, "CareCo.");
    product[10].cost = 2.0;
    product[10].price = 3.99;
    product[10].quantity = 200;
    strcpy(product[10].purchased_date, "2023-03-29");
    strcpy(product[10].production_date, "2023-03-20");
    strcpy(product[10].expiry_date, "2024-03-20");
    product[10].store_code = 1234;
    strcpy(product[10].currency, "CAD");

    strcpy(product[11].pName, "ToiletPaper");
    strcpy(product[11].pCategory, "PaperGoods");
    strcpy(product[11].manufacturer, "PaperCo.");
    product[11].cost = 0.5;
    product[11].price = 1.0;
    product[11].quantity = 500;
    strcpy(product[11].purchased_date, "2023-03-29");
    strcpy(product[11].production_date, "2023-03-15");
    strcpy(product[11].expiry_date, "2025-03-15");
    product[11].store_code = 1234;
    strcpy(product[11].currency, "CAD");

    strcpy(product[12].pName, "PorkChop");
    strcpy(product[12].pCategory, "Meat");
    strcpy(product[12].manufacturer, "MeatPro");
    product[12].cost = 3.5;
    product[12].price = 5.0;
    product[12].quantity = 50;
    strcpy(product[12].purchased_date, "2023-03-28");
    strcpy(product[12].production_date, "2023-03-25");
    strcpy(product[12].expiry_date, "2023-04-03");
    product[12].store_code = 5678;
    strcpy(product[12].currency, "CAD");

    strcpy(product[13].pName, "Salami");
    strcpy(product[13].pCategory, "Deli");
    strcpy(product[13].manufacturer, "ItalianDeliCo.");
    product[13].cost = 2.0;
    product[13].price = 3.5;
    product[13].quantity = 80;
    strcpy(product[13].purchased_date, "2023-03-27");
    strcpy(product[13].production_date, "2023-03-25");
    strcpy(product[13].expiry_date, "2023-04-01");
    product[13].store_code = 5678;
    strcpy(product[13].currency, "CAD");

    strcpy(product[14].pName, "PainReliefPills");
    strcpy(product[14].pCategory, "Pharmacy");
    strcpy(product[14].manufacturer, "PharmaCareInc.");
    product[14].cost = 1.0;
    product[14].price = 2.5;
    product[14].quantity = 120;
    strcpy(product[14].purchased_date, "2023-03-28");
    strcpy(product[14].production_date, "2023-03-20");
    strcpy(product[14].expiry_date, "2024-03-20");
    product[14].store_code = 5678;
    strcpy(product[14].currency, "CAD");

    strcpy(product[15].pName, "FreshSalmonFillet");
    strcpy(product[15].pCategory, "Seafood");
    strcpy(product[15].manufacturer, "OceanHarvestFisheries");
    product[15].cost = 8.0;
    product[15].price = 12.0;
    product[15].quantity = 50;
    strcpy(product[15].purchased_date, "2023-03-25");
    strcpy(product[15].production_date, "2023-03-24");
    strcpy(product[15].expiry_date, "2023-03-28");
    product[15].store_code = 1234;
    strcpy(product[15].currency, "CAD");

    strcpy(product[16].pName, "SparklingWater");
    strcpy(product[16].pCategory, "Beverage");
    strcpy(product[16].manufacturer, "GoodDrinkCo.");
    product[16].cost = 1.0;
    product[16].price = 2.5;
    product[16].quantity = 200;
    strcpy(product[16].purchased_date, "2023-03-25");
    strcpy(product[16].production_date, "2023-03-20");
    strcpy(product[16].expiry_date, "2024-03-31");
    product[16].store_code = 1234;
    strcpy(product[16].currency, "CAD");

    strcpy(product[17].pName, "CannedPeaches");
    strcpy(product[17].pCategory, "Canned");
    strcpy(product[17].manufacturer, "SunshineFarms");
    product[17].cost = 1.5;
    product[17].price = 3.0;
    product[17].quantity = 150;
    strcpy(product[17].purchased_date, "2023-03-23");
    strcpy(product[17].production_date, "2023-03-18");
    strcpy(product[17].expiry_date, "2025-03-31");
    product[17].store_code = 1234;
    strcpy(product[17].currency, "CAD");

    strcpy(product[18].pName, "JarredPickles");
    strcpy(product[18].pCategory, "Jarred");
    strcpy(product[18].manufacturer, "FreshPickleCo.");
    product[18].cost = 2.0;
    product[18].price = 4.5;
    product[18].quantity = 100;
    strcpy(product[18].purchased_date, "2023-03-22");
    strcpy(product[18].production_date, "2023-03-17");
    strcpy(product[18].expiry_date, "2024-06-30");
    product[18].store_code = 1234;
    strcpy(product[18].currency, "CAD");

    strcpy(product[19].pName, "GranolaBars");
    strcpy(product[19].pCategory, "DryFood");
    strcpy(product[19].manufacturer, "HealthFirst");
    product[19].cost = 1.5;
    product[19].price = 3.0;
    product[19].quantity = 100;
    strcpy(product[19].purchased_date, "2023-03-21");
    strcpy(product[19].production_date, "2023-03-15");
    strcpy(product[19].expiry_date, "2023-12-31");
    product[19].store_code = 1234;
    strcpy(product[19].currency, "CAD");

    strcpy(product[20].pName, "LambCream");
    strcpy(product[20].pCategory, "Dairy");
    strcpy(product[20].manufacturer, "HealthyCows");
    product[20].cost = 2.0;
    product[20].price = 4.0;
    product[20].quantity = 50;
    strcpy(product[20].purchased_date, "2023-03-20");
    strcpy(product[20].production_date, "2023-03-15");
    strcpy(product[20].expiry_date, "2023-04-05");
    product[20].store_code = 1234;
    strcpy(product[20].currency, "CAD");

    strcpy(product[21].pName, "Bread");
    strcpy(product[21].pCategory, "Bakery");
    strcpy(product[21].manufacturer, "BakeCo");
    product[21].cost = 1.5;
    product[21].price = 2.5;
    product[21].quantity = 50;
    strcpy(product[21].purchased_date, "2023-03-25");
    strcpy(product[21].production_date, "2023-03-24");
    strcpy(product[21].expiry_date, "2023-03-28");
    product[21].store_code = 5678;
    strcpy(product[21].currency, "CAD");

    strcpy(product[22].pName, "Shampoo");
    strcpy(product[22].pCategory, "PersonalCare");
    strcpy(product[22].manufacturer, "FreshTeeth");
    product[22].cost = 0.5;
    product[22].price = 1.5;
    product[22].quantity = 100;
    strcpy(product[22].purchased_date, "2023-03-26");
    strcpy(product[22].production_date, "2023-03-20");
    strcpy(product[22].expiry_date, "2024-03-20");
    product[22].store_code = 5678;
    strcpy(product[22].currency, "CAD");

    strcpy(product[23].pName, "Tissue");
    strcpy(product[23].pCategory, "PaperGoods");
    strcpy(product[23].manufacturer, "SoftTissue");
    product[23].cost = 0.2;
    product[23].price = 0.5;
    product[23].quantity = 200;
    strcpy(product[23].purchased_date, "2023-03-27");
    strcpy(product[23].production_date, "2023-03-20");
    strcpy(product[23].expiry_date, "2024-03-20");
    product[23].store_code = 5678;
    strcpy(product[23].currency, "CAD");

    strcpy(product[24].pName, "Duck");
    strcpy(product[24].pCategory, "Meat");
    strcpy(product[24].manufacturer, "FarmFresh");
    product[24].cost = 3.5;
    product[24].price = 5.0;
    product[24].quantity = 50;
    strcpy(product[24].purchased_date, "2023-03-28");
    strcpy(product[24].production_date, "2023-03-22");
    strcpy(product[24].expiry_date, "2023-03-30");
    product[24].store_code = 5678;
    strcpy(product[24].currency, "CAD");

    strcpy(product[25].pName, "RoastBeef");
    strcpy(product[25].pCategory, "Deli");
    strcpy(product[25].manufacturer, "ArtisanMeats");
    product[25].cost = 2.0;
    product[25].price = 4.5;
    product[25].quantity = 30;
    strcpy(product[25].purchased_date, "2023-03-26");
    strcpy(product[25].production_date, "2023-03-20");
    strcpy(product[25].expiry_date, "2023-03-31");
    product[25].store_code = 5678;
    strcpy(product[25].currency, "CAD");

    strcpy(product[26].pName, "Aspirin");
    strcpy(product[26].pCategory, "Pharmacy");
    strcpy(product[26].manufacturer, "WellnessMeds");
    product[26].cost = 0.05;
    product[26].price = 0.2;
    product[26].quantity = 100;
    strcpy(product[26].purchased_date, "2023-03-27");
    strcpy(product[26].production_date, "2023-03-20");
    strcpy(product[26].expiry_date, "2024-03-20");
    product[26].store_code = 5678;
    strcpy(product[26].currency, "CAD");

    strcpy(product[27].pName, "Shellfish");
    strcpy(product[27].pCategory, "Seafood");
    strcpy(product[27].manufacturer, "OceanCatch");
    product[27].cost = 2.5;
    product[27].price = 4.0;
    product[27].quantity = 20;
    strcpy(product[27].purchased_date, "2023-03-24");
    strcpy(product[27].production_date, "2023-03-18");
    strcpy(product[27].expiry_date, "2023-03-29");
    product[27].store_code = 5678;
    strcpy(product[27].currency, "CAD");

    strcpy(product[28].pName, "OrangeJuice");
    strcpy(product[28].pCategory, "Beverage");
    strcpy(product[28].manufacturer, "FreshJuiceCo");
    product[28].cost = 1.0;
    product[28].price = 2.0;
    product[28].quantity = 60;
    strcpy(product[28].purchased_date, "2023-03-26");
    strcpy(product[28].production_date, "2023-03-20");
    strcpy(product[28].expiry_date, "2023-03-31");
    product[28].store_code = 5678;
    strcpy(product[28].currency, "CAD");

    strcpy(product[29].pName, "OionSoup");
    strcpy(product[29].pCategory, "Canned");
    strcpy(product[29].manufacturer, "Campbell's");
    product[29].cost = 1.0;
    product[29].price = 2.5;
    product[29].quantity = 40;
    strcpy(product[29].purchased_date, "2023-03-25");
    strcpy(product[29].production_date, "2023-03-15");
    strcpy(product[29].expiry_date, "2024-03-15");
    product[29].store_code = 5678;
    strcpy(product[29].currency, "CAD");

    strcpy(product[30].pName, "PickleSpears");
    strcpy(product[30].pCategory, "Jarred");
    strcpy(product[30].manufacturer, "KosherPickles");
    product[30].cost = 1.5;
    product[30].price = 3.0;
    product[30].quantity = 25;
    strcpy(product[30].purchased_date, "2023-03-27");
    strcpy(product[30].production_date, "2023-03-20");
    strcpy(product[30].expiry_date, "2024-03-20");
    product[30].store_code = 5678;
    strcpy(product[30].currency, "CAD");

    strcpy(product[31].pName, "Rice");
    strcpy(product[31].pCategory, "DryFood");
    strcpy(product[31].manufacturer, "UncleBen's");
    product[31].cost = 2.0;
    product[31].price = 4.0;
    product[31].quantity = 50;
    strcpy(product[31].purchased_date, "2023-03-24");
    strcpy(product[31].production_date, "2023-03-15");
    strcpy(product[31].expiry_date, "2024-03-15");
    product[31].store_code = 5678;
    strcpy(product[31].currency, "CAD");

    strcpy(product[32].pName, "CheddarCheese");
    strcpy(product[32].pCategory, "Dairy");
    strcpy(product[32].manufacturer, "Kraft");
    product[32].cost = 2.5;
    product[32].price = 5.0;
    product[32].quantity = 30;
    strcpy(product[32].purchased_date, "2023-03-28");
    strcpy(product[32].production_date, "2023-03-20");
    strcpy(product[32].expiry_date, "2023-04-01");
    product[32].store_code = 5678;
    strcpy(product[32].currency, "CAD");

    strcpy(product[33].pName, "RoundCake");
    strcpy(product[33].pCategory, "Bakery");
    strcpy(product[33].manufacturer, "FrenchBakery");
    product[33].cost = 1.0;
    product[33].price = 2.5;
    product[33].quantity = 20;
    strcpy(product[33].purchased_date, "2023-03-26");
    strcpy(product[33].production_date, "2023-03-20");
    strcpy(product[33].expiry_date, "2023-03-31");
    product[33].store_code = 5678;
    strcpy(product[33].currency, "CAD");

    // Product 35
    strcpy(product[34].pName, "BodyWash");
    strcpy(product[34].pCategory, "PersonalCare");
    strcpy(product[34].manufacturer, "Colgate");
    product[34].cost = 1.5;
    product[34].price = 3.0;
    product[34].quantity = 100;
    strcpy(product[34].purchased_date, "2023-03-23");
    strcpy(product[34].production_date, "2022-12-01");
    strcpy(product[34].expiry_date, "2024-12-01");
    product[34].store_code = 5678;
    strcpy(product[34].currency, "CAD");

    // Product 36
    strcpy(product[35].pName, "PaperTowels");
    strcpy(product[35].pCategory, "PaperGoods");
    strcpy(product[35].manufacturer, "Bounty");
    product[35].cost = 2.0;
    product[35].price = 4.5;
    product[35].quantity = 80;
    strcpy(product[35].purchased_date, "2023-03-27");
    strcpy(product[35].production_date, "2023-03-15");
    strcpy(product[35].expiry_date, "2024-03-15");
    product[35].store_code = 5678;
    strcpy(product[35].currency, "CAD");

    creat_barcode(product, PRODUCT_NUM);

   printf("---------Menu:-----------------------------------------------\n");
    printf("|        1. View products\n|        2. Search and view a product's price\n|        3. View categories\n|        4.Print the receipt\n|        5.Add products  \n");
    printf("-------------------------------------------------------------\n");

    printf("Welcome to the inventory system! \nPlease choose an action(1~5)");
    scanf("%d", &action);
    printf("\n");

    switch (action) {
    case 1:
        print_product(product, PRODUCT_NUM);
        break;

    case 2:
       
        printf("Enter the product name to search for: \n");
        scanf("%s", search_item);
        int found = 0;
        for (i = 0; i < PRODUCT_NUM; i++) {
            if (strcmp(product[i].pName, search_item) == 0) {
                printf("%s:\n", product[i].pName);
                printf("Cost: %.2lf,Price:%.2lf", product[i].cost, product[i].price);

                printf(" Gross profit margin:%.2lf %%", ((product[i].price - product[i].cost) / product[i].price) * 100);
                found = 1;
            }
        }
        if (!found) {
            printf("Can not find.\n");
        }
        break;
        
         case 3:
        for (i = 0; i < CATEGORY_NUM + cNumber_change; i++) {
            printf("Category %d:\n", i + 1);
            printf("Name: %s  ", categories[i].cate_name);
            printf("Code: %c\n", categories[i].cate_code);
        }
        break;

    case 4:
        //promotion jugement and receipt print

        printf("\n-------------------receipt part A---------------------\n");
        printf("Date:%s\n", product[0].purchased_date);
        printf("|         You purchased : Beef,Turkey,Ibuprofen,Salmon,Soda,CannedTomatoes,StrawberryJam,PennePasta,CheeseWedge,Croissant,Toothbrush,ToiletPaper\n");

        char* purchased_items[12] = { "Beef","Turkey","Ibuprofen","Salmon","Soda","CannedTomatoes","StrawberryJam","PennePasta","CheeseWedge","Croissant","Toothbrush","ToiletPaper" };
        for (i = 0; i < 12; i++) {
            struct PRODUCT* selected_product = NULL;
            for (int j = 0; j < PRODUCT_NUM; j++) {
                if (strcmp(product[j].pName, purchased_items[i]) == 0) {
                    selected_product = &product[j];
                    break;
                }
            }
            if (selected_product == NULL) {
                printf("|         Cannot find product %s\n", purchased_items[i]);
                continue;
            }
            double purchased_price = checkPromotion(selected_product);
            total_amount += purchased_price;
        }

        printf("\n-----------------------------------\n");
        printf("|         The total_amount you have to pay is %.3lf", total_amount);
        printf("\n-----------------------------------\n");


        //return items recipt

        printf("\n-------------------receipt part B---------------------\n");
        printf("|         You want to return Ibuprofen,SourCream,GranolaBars\n");
        char* returned_items[3] = { "Ibuprofen", "SourCream", "GranolaBars" };
        for (i = 0; i < 3; i++) {
            struct PRODUCT* r_product = NULL;
            for (int k = 0; k < PRODUCT_NUM; k++) {
                if (strcmp(product[k].pName, returned_items[i]) == 0) {
                    r_product = &product[k];
                    break;
                }
            }
            if (r_product == NULL) {
                printf("Cannot find product %s\n", returned_items[i]);
                continue;
            }
            double discounted_price = checkPromotion(r_product);
            total_return += discounted_price;
        }
        printf("\n-----------------------------------\n");
        printf("|         The total_amount of your return is %.3lf", total_return);
        printf("\n-----------------------------------\n");

        printf("|         The balance is %.3lf\n", total_amount - total_return);
        printf("|         The payment Method is %s\n", paymentMethod1);
        printf("|         @@ 5300 No. 3 Rd, Richmond, BC V6X 2X9@@ (%d) @@\n", product[0].store_code);

        break;


    case 5:
        struct PRODUCT* temp = (struct PRODUCT*)malloc(PRODUCT_NUM * sizeof(struct PRODUCT));
        memcpy(temp, product, PRODUCT_NUM * sizeof(struct PRODUCT));
        printf("\nHow many items do you want add?\n");
        scanf("%d", &pNumber_change);
        struct PRODUCT* new_products = (struct PRODUCT*)malloc(pNumber_change * sizeof(struct PRODUCT));
        for (i = 0; i < pNumber_change; i++) {
            printf("Enter product name: ");
            scanf("%s", new_products[i].pName);
            printf("Enter product category: ");
            scanf("%s", new_products[i].pCategory);
            printf("Enter manufacturer: ");
            scanf("%s", new_products[i].manufacturer);
            printf("Enter cost: ");
            scanf("%lf", &new_products[i].cost);
            printf("Enter price: ");
            scanf("%lf", &new_products[i].price);
            printf("Enter quantity: ");
            scanf("%d", &new_products[i].quantity);
            printf("Enter purchased date (YYYY-MM-DD): ");
            scanf("%s", new_products[i].purchased_date);
            printf("Enter production date (YYYY-MM-DD): ");
            scanf("%s", new_products[i].production_date);
            printf("Enter expiry date (YYYY-MM-DD): ");
            scanf("%s", new_products[i].expiry_date);
            printf("Enter store code: ");
            scanf("%d", &new_products[i].store_code);
            printf("Enter currency: ");
            scanf("%s", new_products[i].currency);
        }
        //encrpy to get barcode
        creat_barcode(new_products, pNumber_change);
        // Reallocate memory for the products array to include the new products
        struct PRODUCT* product = (struct PRODUCT*)realloc(product, (PRODUCT_NUM + pNumber_change) * sizeof(struct PRODUCT));
        if (product == NULL) {
            printf("Error: Failed to reallocate memory.\n");
            return 1;
        }
        // Copy the new products to the end of the product
        memcpy(product, temp, PRODUCT_NUM * sizeof(struct PRODUCT));
        memcpy(product + PRODUCT_NUM, new_products, pNumber_change * sizeof(struct PRODUCT));
        PRODUCT_NUM += pNumber_change;
        printf("\nThe new inventory has created:\n");
        print_product(product, PRODUCT_NUM);
        free(temp);
        free(new_products);

        break;

   

    default:
        printf("Action error\n");

    }

    free(product);
    free(categories);

    return 0;
}


//functions

//encryption method 1 for #1, and #3. names
char* encrypt_names(char* strf1) {
    int sumf1 = 0;
    char* pf1 = strf1;
    while (*pf1 != '\0') {
        sumf1 += *pf1 - 'A' + 1; // 将字母转换为对应数字并相加
        pf1++;
    }
    while (sumf1 >= 10) { // 如果和大于等于10，继续拆分和并相加
        int digit_sumf1 = 0;
        while (sumf1 != 0) {
            digit_sumf1 += sumf1 % 10;
            sumf1 /= 10;
        }
        sumf1 = digit_sumf1;
    }
    char* resultf1 = (char*)malloc(sizeof(char) * 3); // 分配3个字节的空间，包括2位数字和1个结束符
    sprintf(resultf1, "%02d", sumf1); // 将结果格式化为2位数字字符串
    //printf("1加密结果：%s\n",resultf1);
    return resultf1;
}

//encryption method 2 for #2. category
char* encrupt_category(char* s2, int k2) {
    char* result2 = malloc(strlen(s2) + 1); // 分配足够的空间来存放加密后的字符串
    int len2 = strlen(s2);
    for (int i = 0; i < len2; i++) {
        result2[i] = s2[i] ^ k2;
    }
    result2[len2] = '\0'; // 加上字符串结束符
    //printf("2加密结果：%s\n",result2);
    return result2;
}



//encryption method 3 for #4, and #5. prices
char* encrypt_prices(double* pricesf3) {
    *pricesf3 += 3.14;
    char* resultf3 = malloc(20 * sizeof(char));
    sprintf(resultf3, "%.2f", *pricesf3);
    //printf("3加密结果：%s\n",resultf3);
    return resultf3;
}



//encryption method 4 for #6. integer
char* encrypt_integer(int* integerf4) {
    *integerf4 ^= 2022;
    char* resultf4 = malloc(20 * sizeof(char));
    sprintf(resultf4, "%d", *integerf4);
    //printf("4加密结果：%s\n",resultf4);
    return resultf4;
}



//encryption method 5 for #7, #8, and #9.date
char* encrypt_date(char* sf5) {
    char* resultf5 = malloc(strlen(sf5) + 1); // 分配足够的空间来存放加密后的字符串
    int lenf5 = strlen(sf5);
    for (int i = 0; i < lenf5; i++) {
        switch (sf5[i]) {
        case '0': resultf5[i] = 'a'; break;
        case '1': resultf5[i] = 'b'; break;
        case '2': resultf5[i] = 'c'; break;
        case '3': resultf5[i] = 'd'; break;
        case '4': resultf5[i] = 'e'; break;
        case '5': resultf5[i] = 'f'; break;
        case '6': resultf5[i] = 'g'; break;
        case '7': resultf5[i] = 'h'; break;
        case '8': resultf5[i] = 'i'; break;
        case '9': resultf5[i] = 'j'; break;
        default: resultf5[i] = sf5[i]; break; // 如果不是特定字符，则不进行替换
        }
    }
    resultf5[lenf5] = '\0'; // 加上字符串结束符
    // printf("加密结果：%s\n",resultf5);
    return resultf5;
}

//encryption method 6 for #10. a 4 - digit number
char* encrypt_4digit(int numf6) {
    int a6, b6, c6, d6;
    a6 = numf6 / 1000;
    b6 = numf6 % 1000 / 100;
    c6 = numf6 % 100 / 10;
    d6 = numf6 % 10;
    a6 = (a6 + 5) % 10;
    b6 = (b6 + 5) % 10;
    c6 = (c6 + 5) % 10;
    d6 = (d6 + 5) % 10;
    char* resultf6 = malloc(5 * sizeof(char));
    sprintf(resultf6, "%d%d%d%d", d6, c6, b6, a6);
    //printf("6加密结果：%s\n",resultf6);
    return resultf6;
}

//encryption method 7 for #11 word
char* encrypt_word(char* sf7, int k7, int k7a) {
    char* resultf7 = malloc(strlen(sf7) + 1); // 分配足够的空间来存放加密后的字符串
    int lenf7 = strlen(sf7);
    for (int i = 0; i < lenf7; i++) {
        resultf7[i] = (sf7[i] + k7a);
    }
    resultf7[lenf7] = '\0'; // 加上字符串结束符
    //printf("7加密结果：%s\n",resultf7);
    return resultf7;
}

//connect

char* connection(char* strf1, char* strf2, char* strf3, char* strf4, char* strf5, char* strf6, char* strf7, char* strf8, char* strf9, char* strf10, char* strf11) {
    char* resultco = (char*)malloc(strlen(strf1) + strlen(strf2) + strlen(strf3) + strlen(strf4) + strlen(strf5) + strlen(strf6) + strlen(strf7) + strlen(strf8) + strlen(strf9) + strlen(strf10) + strlen(strf11) + 1);
    strcpy(resultco, strf1);
    strcat(resultco, strf2);
    strcat(resultco, strf3);
    strcat(resultco, strf4);
    strcat(resultco, strf5);
    strcat(resultco, strf6);
    strcat(resultco, strf7);
    strcat(resultco, strf8);
    strcat(resultco, strf9);
    strcat(resultco, strf10);
    strcat(resultco, strf11);
    //printf("connection加密结果：%s\n",resultco);
    return resultco;

}


void print_product(struct PRODUCT* p, int x) {
    for (i = 0; i < x; i++) {
        printf("Product name: %s\n", p[i].pName);
        printf("Product category: %s\n", p[i].pCategory);
        printf("Manufacturer: %s\n", p[i].manufacturer);
        printf("Cost: %.2lf\n", p[i].cost);
        printf("Price: %.2lf\n", p[i].price);
        printf("Quantity: %d\n", p[i].quantity);
        printf("Purchased date: %s\n", p[i].purchased_date);
        printf("pion date: %s\n", p[i].production_date);
        printf("Expiry date: %s\n", p[i].expiry_date);
        printf("Store code: %d\n", p[i].store_code);
        printf("Currency: %s\n", p[i].currency);
        printf("Barcode: %s\n", p[i].barcode);
        printf("\n");
    }
}

void creat_barcode(struct PRODUCT* pc, int y) {
    for (int i = 0; i < y; i++) {
        // create a copy of the product struct
        struct PRODUCT pc_copy;
        memcpy(&pc_copy, pc, sizeof(struct PRODUCT));
        // encrypt fields and create barcode for the copy
        char* s1 = encrypt_names(pc_copy.pName);
        char* s2 = encrupt_category(pc_copy.pCategory, 3);
        char* s3 = encrypt_names(pc_copy.manufacturer);
        char* s4 = encrypt_prices(&pc_copy.cost);
        char* s5 = encrypt_prices(&pc_copy.price);
        char* s6 = encrypt_integer(&pc_copy.quantity);
        char* s7 = encrypt_date(pc_copy.purchased_date);
        char* s8 = encrypt_date(pc_copy.production_date);
        char* s9 = encrypt_date(pc_copy.expiry_date);
        char* s10 = encrypt_4digit(pc_copy.store_code);
        char* s11 = encrypt_word(pc_copy.currency, 7, 9);
        char* result = connection(s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11);

        // allocate memory for the barcode and copy it to the original struct
        pc[i].barcode = (char*)malloc(strlen(result) + 1);
        strcpy(pc[i].barcode, result);

        free(result);
        free(s1);
        free(s2);
        free(s3);
        free(s4);
        free(s5);
        free(s6);
        free(s7);
        free(s8);
        free(s9);
        free(s10);
        free(s11);
    }
}


double checkPromotion(struct PRODUCT* product) {
    // Calculate the expiration date in days
    struct tm production_time = { 0 };
    strptime(product->production_date, "%Y-%m-%d", &production_time);
    time_t production_timestamp = mktime(&production_time);

    struct tm expiry_time = { 0 };
    strptime(product->expiry_date, "%Y-%m-%d", &expiry_time);
    time_t expiry_timestamp = mktime(&expiry_time);

    struct tm purchased_time = { 0 };
    strptime(product->purchased_date, "%Y-%m-%d", &purchased_time);
    time_t purchased_timestamp = mktime(&purchased_time);

    double expiration_days = difftime(expiry_timestamp, production_timestamp) / 86400.0;
    double remaining_days = difftime(expiry_timestamp, purchased_timestamp) / 86400.0;
    double elapsed_days = difftime(purchased_timestamp, production_timestamp) / 86400.0;

    // Check the promotion based on the elapsed days and expiration days
    //and print receipt A part

    double yellow_tag_price = 0.0;
    double green_tag_price = 0.0;
    double red_tag_price = 0.0;
    double star_tag_price = 0.0;
    double no_discount_price = 0.0;
    double sumF = 0.0;

    if (
        (strcmp(product->pCategory, "Meat") == 0) ||
        (strcmp(product->pCategory, "Deli") == 0) ||
        (strcmp(product->pCategory, "Pharmacy") == 0) ||
        (strcmp(product->pCategory, "Seafood") == 0)
        )
    {
        if (elapsed_days > expiration_days * 0.5 && elapsed_days < expiration_days * 0.65) {
            yellow_tag_price = product->price * 0.9;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s,\nOriginal Price: %.3lf,\non sale at Yellow Tag Price: %.3lf\n", product->pName, product->price, yellow_tag_price);
            printf("You get 10 percentage off and saved $%.3lf\n", ((product->price) - (yellow_tag_price)));
        }
        else if (elapsed_days >= expiration_days * 0.65 && elapsed_days < expiration_days * 0.75) {
            green_tag_price = product->price * 0.75;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s,\nOriginal Price: %.3lf,\non sale at Green Tag Price: %.3lf\n", product->pName, product->price, green_tag_price);
            printf("You get 25 percentage off and saved $%.3lf\n", ((product->price) - (green_tag_price)));
        }
        else if (elapsed_days >= expiration_days * 0.75 && elapsed_days < expiration_days * 0.95) {
            red_tag_price = product->price * 0.5;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s, \nOriginal Price: %.3lf, \non sale at Red Tag Price: %.3lf\n", product->pName, product->price, red_tag_price);
            printf("You get 50 percentage off and saved $%.3lf\n", ((product->price) - (red_tag_price)));
        }
        else if (elapsed_days >= expiration_days * 0.95 && remaining_days > 1) {
            star_tag_price = product->price * 0.05;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s, \nOriginal Price: %.3lf, \nis on sale at Star Tag Price: %.3lf\n", product->pName, product->price, star_tag_price);
            printf("You get 95 percentage off and saved $%.3lf\n", ((product->price) - (star_tag_price)));
        }
        else if (remaining_days == 1) {
            printf("\nProduct Name: %s will be removed from inventory\n", product->pName);
        }
        else if (elapsed_days < expiration_days * 0.5) {
            no_discount_price = product->price;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s, \nPrice: %.3lf\n", product->pName, no_discount_price);
        }
    }

    else if (
        (strcmp(product->pCategory, "Beverage") == 0) ||
        (strcmp(product->pCategory, "Canned") == 0) ||
        (strcmp(product->pCategory, "Jarred") == 0) ||
        (strcmp(product->pCategory, "DryFood") == 0)
        )
    {
        if (elapsed_days > expiration_days * 0.6 && elapsed_days < expiration_days * 0.7) {
            yellow_tag_price = product->price * 0.9;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s,\nOriginal Price: %.3lf,\non sale at Yellow Tag Price: %.3lf\n", product->pName, product->price, yellow_tag_price);
            printf("You get 10 percentage off and saved $%.3lf\n", ((product->price) - (yellow_tag_price)));
        }
        else if (elapsed_days >= expiration_days * 0.7 && elapsed_days < expiration_days * 0.8) {
            green_tag_price = product->price * 0.75;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s,\nOriginal Price: %.3lf,\non sale at Green Tag Price: %.3lf\n", product->pName, product->price, green_tag_price);
            printf("You get 25 percentage off and saved $%.3lf\n", ((product->price) - (green_tag_price)));
        }
        else if (elapsed_days >= expiration_days * 0.8 && elapsed_days < expiration_days * 0.95) {
            red_tag_price = product->price * 0.5;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s, \nOriginal Price: %.3lf, \non sale at Red Tag Price: %.3lf\n", product->pName, product->price, red_tag_price);
            printf("You get 50 percentage off and saved $%.3lf\n", ((product->price) - (red_tag_price)));
        }
        else if (elapsed_days >= expiration_days * 0.95 && remaining_days > 1) {
            star_tag_price = product->price * 0.05;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s, \nOriginal Price: %.3lf, \nis on sale at Star Tag Price: %.3lf\n", product->pName, product->price, star_tag_price);
            printf("You get 95 percentage off and saved $%.3lf\n", ((product->price) - (star_tag_price)));
        }
        else if (remaining_days == 1) {
            printf("\nProduct Name: %s will be removed from inventory\n", product->pName);
        }
        else if (elapsed_days < expiration_days * 0.5) {
            no_discount_price = product->price;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s, \nPrice: %.3lf\n", product->pName, no_discount_price);
        }
    }

    else if (
        (strcmp(product->pCategory, "Dairy") == 0) ||
        (strcmp(product->pCategory, "Bakery") == 0) ||
        (strcmp(product->pCategory, "PersonalCare") == 0)
        )
    {
        if (elapsed_days > expiration_days * 0.4 && elapsed_days < expiration_days * 0.5) {
            yellow_tag_price = product->price * 0.9;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s,\nOriginal Price: %.3lf,\non sale at Yellow Tag Price: %.3lf\n", product->pName, product->price, yellow_tag_price);
            printf("You get 10 percentage off and saved $%.3lf\n", ((product->price) - (yellow_tag_price)));
        }
        else if (elapsed_days >= expiration_days * 0.5 && elapsed_days < expiration_days * 0.6) {
            green_tag_price = product->price * 0.75;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s,\nOriginal Price: %.3lf,\non sale at Green Tag Price: %.3lf\n", product->pName, product->price, green_tag_price);
            printf("You get 25 percentage off and saved $%.3lf\n", ((product->price) - (green_tag_price)));
        }
        else if (elapsed_days >= expiration_days * 0.6 && elapsed_days < expiration_days * 0.95) {
            red_tag_price = product->price * 0.5;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s, \nOriginal Price: %.3lf, \non sale at Red Tag Price: %.3lf\n", product->pName, product->price, red_tag_price);
            printf("You get 50 percentage off and saved $%.3lf\n", ((product->price) - (red_tag_price)));
        }
        else if (elapsed_days >= expiration_days * 0.95 && remaining_days > 1) {
            star_tag_price = product->price * 0.05;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s, \nOriginal Price: %.3lf, \nis on sale at Star Tag Price: %.3lf\n", product->pName, product->price, star_tag_price);
            printf("You get 95 percentage off and saved $%.3lf\n", ((product->price) - (star_tag_price)));
        }
        else if (remaining_days == 1) {
            printf("\nProduct Name: %s will be removed from inventory\n", product->pName);
        }
        else if (elapsed_days < expiration_days * 0.5) {
            no_discount_price = product->price;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s, \nPrice: %.3lf\n", product->pName, no_discount_price);
        }
    }

    else if (
        (strcmp(product->pCategory, "PaperGoods") == 0)
        )
    {
        if (elapsed_days > expiration_days * 0.7 && elapsed_days < expiration_days * 0.8) {
            yellow_tag_price = product->price * 0.9;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s,\nOriginal Price: %.3lf,\non sale at Yellow Tag Price: %.3lf\n", product->pName, product->price, yellow_tag_price);
            printf("You get 10 percentage off and saved $%.3lf\n", ((product->price) - (yellow_tag_price)));
        }
        else if (elapsed_days >= expiration_days * 0.8 && elapsed_days < expiration_days * 0.9) {
            green_tag_price = product->price * 0.75;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s,\nOriginal Price: %.3lf,\non sale at Green Tag Price: %.3lf\n", product->pName, product->price, green_tag_price);
            printf("You get 25 percentage off and saved $%.3lf\n", ((product->price) - (green_tag_price)));
        }
        else if (elapsed_days >= expiration_days * 0.9 && elapsed_days < expiration_days * 0.95) {
            red_tag_price = product->price * 0.5;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s, \nOriginal Price: %.3lf, \non sale at Red Tag Price: %.3lf\n", product->pName, product->price, red_tag_price);
            printf("You get 50 percentage off and saved $%.3lf\n", ((product->price) - (red_tag_price)));
        }
        else if (elapsed_days >= expiration_days * 0.95 && remaining_days > 1) {
            star_tag_price = product->price * 0.05;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s, \nOriginal Price: %.3lf, \nis on sale at Star Tag Price: %.3lf\n", product->pName, product->price, star_tag_price);
            printf("You get 95 percentage off and saved $%.3lf\n", ((product->price) - (star_tag_price)));
        }
        else if (remaining_days == 1) {
            printf("\nProduct Name: %s will be removed from inventory\n", product->pName);
        }
        else if (elapsed_days < expiration_days * 0.5) {
            no_discount_price = product->price;
            printf("\nproduct code: %s \n", product->barcode);
            printf("Product Name: %s, \nPrice: %.3lf\n", product->pName, no_discount_price);
        }
    }

    sumF = yellow_tag_price + green_tag_price + red_tag_price + star_tag_price + no_discount_price + sumF;
    return sumF;
}




