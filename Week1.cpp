#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//Written By Hayat Sikandar (for Week 1 task AICP Internship)



// Arrays to store information
string itemCodes[] = {"A1", "A2", "B1", "B2", "B3",
 "C1", "C2", "C3", "D1", "D2", "E1", "E2", "E3",
  "F1", "F2", "G1", "G2"};
string itemDescriptions[] = {"Compact", "Tower", "8 GB", "16 GB",
 "32 GB", "1 TB HDD", "2 TB HDD", "4 TB HDD", "240 GB SSD",
 "480 GB SSD", "1 TB HDD", "2 TB HDD", "4 TB HDD", "DVD/Blu-Ray Player",
 "DVD/Blu-Ray Re-writer", "Standard Version", "Professional Version"};
double itemPrices[] = {75.00, 150.00, 79.99, 149.99, 299.99, 49.99, 89.99,
 129.99, 59.99, 119.99, 49.99, 89.99, 129.99, 50.00, 100.00, 100.00, 175.00};


bool isValidItemCode(const string& code) ;
int main()
 {
    
    double basicComponentsCost = 200.00;

    //Choosing to save initial inputs here
    string chosenCase, chosenRAM, chosenHDD;

   //do while specifically to ensure user sees the text---enters---the program validates input
    do 
    {
        cout << "Choose one case (A1 or A2): ";
        cin >> chosenCase;
    } while (!isValidItemCode(chosenCase));

    do 
    {
        cout << "Choose one RAM (B1 , B2, B3): ";
        cin >> chosenRAM;
    } while (!isValidItemCode(chosenRAM));

    do 
    {
        cout << "Choose one Main Hard Disk Drive (C1): ";
        cin >> chosenHDD;
    } while (!isValidItemCode(chosenHDD));

    // Do they want additional items?
    string additionalItems;
    double additionalItemsCost = 0.0;

    // User input for additional items
    cout << "Do you want to purchase additional items? (Y/N): ";
    cin >> additionalItems;

    // Validate additional items input here
    if (additionalItems == "Y" || additionalItems == "y") 
    {
        string itemCode;
        cout << "Available additional items: D1/240 GB SSD, D2/480 GB SSD, E1/1 TB HDD, E2/2 TB HDD, E3/4 TB HDD, F1/DVD/Blu-Ray Player, F2/DVD/Blu-Ray Re-writer, G1/Standard Version, G2/Professional Version" << endl;
        cout << "Enter item codes separated by space (e.g., D1 E1 F2): ";

        // Read additional items input
        cin.ignore(); // Ignore newline character (buffer)
        getline(cin, itemCode); //getline to get spaces as well

        //Basically here we split the user input, search the array for the split word, then add to the bill
        // D1 E1 F2 is split up into 3 parts
        size_t pos = 0;
        while ((pos = itemCode.find(" ")) != string::npos) 
        
        {
            string code = itemCode.substr(0, pos);
            if (isValidItemCode(code)) {
                for (int i = 0; i < 17; ++i) {
                    if (code == itemCodes[i]) {
                        additionalItemsCost += itemPrices[i];
                        break;
                    }
                }
            }
            
            itemCode.erase(0, pos + 1);
        }
        // Calculate cost of the last item (or only item)
        if (isValidItemCode(itemCode)) {
            for (int i = 0; i < 17; ++i) {
                if (itemCode == itemCodes[i]) {
                    additionalItemsCost += itemPrices[i];
                    break;
                }
            }
        }
    }

    // Calculate total price
    double totalPrice = basicComponentsCost + additionalItemsCost;

    // Calculate discount and new  price
    double discount = 0.0;
    if (additionalItemsCost > 0) 
    {
        if (additionalItemsCost <= 0.0)
         {
            discount = 0.05; // 5% discount for one additional item
        } 
        else
         {
            discount = 0.10; // 10% discount for two or more additional items
        }
    }
    double discountAmount = totalPrice * discount;
    double discountedPrice = totalPrice - discountAmount;

    // Output chosen items, total price, discount, and new price
    cout << "Chosen Case: " << chosenCase << " - " << itemDescriptions[0] << " - $" << itemPrices[0] << endl;
    cout << "Chosen RAM: " << chosenRAM << " - " << itemDescriptions[2] << " - $" << itemPrices[2] << endl;

    cout << "Chosen Main HDD: " << chosenHDD << " - " << itemDescriptions[5] << " - $" << itemPrices[5] << endl;

    cout << "Additional Items Cost: $" << additionalItemsCost << endl;
    cout << fixed << setprecision(2);

    cout << "Total Price: $" << totalPrice << endl;
    cout << "Discount Amount: $" << discountAmount << endl;


    cout << "Discounted Price: $" << discountedPrice << endl;

    return 0;
}
//Function to check user input ( meant for input validation )
bool isValidItemCode(const string& code) 
{
    for (const string& itemCode : itemCodes)
     {
        if (code == itemCode) 
        {
            return true;
        }
    }
    return false;
}
