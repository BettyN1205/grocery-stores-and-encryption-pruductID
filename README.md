# grocery-stores-and-encryption-pruductID

designing an application for grocery stores and their inventories. Including adding products, managing inventory, generating encryption ids for products, and printing shopping receipts (including return function)

---------Menu:-----------------------------------------------

    1. View products
    2. Search and view a product's price
    3. View categories
    4. Print the receipt
    5. Add products
    
-------------------------------------------------------------

The original requirements are as follows：
In this activity, you are designing an application for grocery stores and their inventories.

The items depending on their type are divided into the following categories:

Group A: Meat

Group B: Deli

Group C: Pharmacy

Group D: Seafood

Group E: Beverage

Group F: Canned

Group G: Jarred

Group H: Dry Food

Group I: Dairy

Group J: Bakery

Group K: Personal Care

Group L: Paper Goods

Your store must have at least 3 items in each category.

Your application as the first step needs to collect the following information before importing the items to the store:

1. The name of the product

2. The Category

3. The Company/Manufacturer name

4. The purchased price (What company has paid to buy this product)

5. The sale price (What customers will pay to buy this product)

6. The quantity of the purchased items

7. The date of the purchased items

8. The date of the production

9. The expiry date of the product

10. Store Code (a 4-digit number)

11. The currency of the country


12. Items will go on sale on different dates depending on their categories.

Your application is responsible to use encryption method 1 for #1, and #3. (You have to define the suitable encryption method.)

Your application is responsible to use encryption method 2 for #2. (You have to define the suitable encryption method.)

Your application is responsible to use encryption method 3 for #4, and #5. (You have to define the suitable encryption method.)

Your application is responsible to use encryption method 4 for #6. (You have to define the suitable encryption method.)

Your application is responsible to use encryption method 5 for #7, #8, and #9. (You have to define the suitable encryption method.)

Your application is responsible to use encryption method 6 for #10. (You have to define the suitable encryption method.)

Your application is responsible to use encryption method 7 for #11. (You have to define the suitable encryption method.)


The output of the encryptions will generate a number that will be known as the barcode of that specific item in this store.

Before selecting and implementing your encryption methods, you have to answer the following questions:

- Will all the generated barcodes have the same number of digits?

- How should we deal with barcodes that have different numbers of digits?

- Do you need to define decryption?

- Is there any other questions, aspects, complications, simplifications, etc. that I need to think about in advance?

Items will go on sale on different dates depending on their categories.

Group A, B, C, and D follow the following rules:

- Items will go on a 10% promotion when the date passes 50% of the durable life period - Yellow Tag

- Items will go on a 25% promotion when the date passes 65% of the durable life period - Green Tag

- Items will go on a 50% promotion when the date passes 75% of the durable life period - Red Tag

- Items will go on a 95% promotion when the date passes 95% of the durable life period - Star Tag and Final Sale (Bring Me Home Today!)

- Items with less than one day of their durable life period must be removed from the shelves and storage to be removed from the inventory

Group E, F, G, and H follow the following rules:

- Items will go on a 10% promotion when the date passes 60% of the durable life period - Yellow Tag

- Items will go on a 25% promotion when the date passes 70% of the durable life period - Green Tag

- Items will go on a 50% promotion when the date passes 80% of the durable life period - Red Tag

- Items will go on a 95% promotion when the date passes 95% of the durable life period - Star Tag and Final Sale (Bring Me Home Today!)

- Items with less than one day of their durable life period must be removed from the shelves and storage to be removed from the inventory


Groups I, J, and K follow the following rules:

- Items will go on a 10% promotion when the date passes 40% of the durable life period - Yellow Tag

- Items will go on a 25% promotion when the date passes 50% of the durable life period - Green Tag

- Items will go on a 50% promotion when the date passes 60% of the durable life period - Red Tag

- Items will go on a 95% promotion when the date passes 95% of the durable life period - Star Tag (Bring Me Home Today!)

- Items with less than one day of their durable life period must be removed from the shelves and storage to be removed from the inventory

Group L follows the following rules:

- Items will go on a 10% promotion when the date passes 70% of the durable life period - Yellow Tag

- Items will go on a 25% promotion when the date passes 80% of the durable life period - Green Tag

- Items will go on a 50% promotion when the date passes 90% of the durable life period - Red Tag

- Items will go on a 95% promotion when the date passes 95% of the durable life period - Star Tag and Final Sale (Bring Me Home Today!)

- Items with less than one day of their durable life period must be removed from the shelves and storage to be removed from the inventory

The output of your program will be a printed receipt that shows a list of 12 items (one item from each category), 8 items with the regular price, and 4 items on sale that a customer bought also the customer has 3 items to return from three different categories.

A receipt needs to include the following information on it:

- The price of each item that has a regular price

- If the price is reduced the reduction amount and sales percentage will be printed on the lines below the regular price; therefore the customer will see the regular price, the sales price, the reduced amount, and the sales percentage

- Each item has a unique barcode
- The date and the time of the purchase
- The store number along with the address of the store
- The final Balance
- The payment method

As per our discussion in class, your code needs to ask the following question from the user at the very beginning:
"Would you like to import any item to your store?"
The answer to this question is YES/NO.
If YES, there will be 12 steps to collect the information related to that specific item being imported to the store to fill in and then, the program will proceed with the following steps.
If No, 30 items (3*10, 3 items in each category) have already existed in our store and the program will proceed with the following steps.

Memory management, allocating, and deallocating memory are one of the most important aspects to be considered in this project.

Regarding the promotions tags available in different colors, your application must be able to generate a list of items with the proper color of the tag that depends on the percentage of the promotion.
