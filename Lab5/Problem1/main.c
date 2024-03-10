#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_MONTHS 12

typedef struct {
    char month[10];
    double sales;
} MonthlySales;

// Function to read sales data from a file and populate the MonthlySales array
void readSalesData(MonthlySales salesData[]) {
    FILE *file = fopen("sales_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Array to store month names
    char months[NUM_MONTHS][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    // Loop to read sales data for each month
    for (int i = 0; i < NUM_MONTHS; i++) {
        // Initialize salesData element and read sales value from the file
        salesData[i].sales = 0;
        fscanf(file, "%lf", &salesData[i].sales);

        // Copy month name to the salesData element
        strcpy(salesData[i].month, months[i]);
    }

    // Close the file after reading
    fclose(file);
}

// Function to print the monthly sales report
void printSalesReport(MonthlySales salesData[]) {
    printf("Monthly sales report for 2022:\n");
    printf("%-10s %10s\n", "Month", "Sales");

    // Loop to print sales data for each month
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-10s $%10.2lf\n", salesData[i].month, salesData[i].sales);
    }
}

// Function to print sales summary including minimum, maximum, and average sales
void printSalesSummary(MonthlySales salesData[]) {
    double minSales = salesData[0].sales, maxSales = salesData[0].sales, sumSales = 0;
    char minMonth[10], maxMonth[10];
    strcpy(minMonth, salesData[0].month);
    strcpy(maxMonth, salesData[0].month);

    // Loop to find minimum, maximum, and calculate total sales
    for (int i = 1; i < NUM_MONTHS; i++) {
        if (salesData[i].sales < minSales) {
            minSales = salesData[i].sales;
            strcpy(minMonth, salesData[i].month);
        }
        if (salesData[i].sales > maxSales) {
            maxSales = salesData[i].sales;
            strcpy(maxMonth, salesData[i].month);
        }
        sumSales += salesData[i].sales;
    }

    double avgSales = sumSales / NUM_MONTHS;
    printf("\nSales summary:\n");
    printf("%-20s %10.2lf (%s)\n", "Minimum sales:", minSales, minMonth);
    printf("%-20s %10.2lf (%s)\n", "Maximum sales:", maxSales, maxMonth);
    printf("%-20s %10.2lf\n", "Average sales:", avgSales);
}

// Function to print six-month moving averages
void printSixMonthMovingAverages(MonthlySales salesData[]) {
    printf("\nSix-Month Moving Average Report:\n");
    printf("%-10s %-10s %10s\n", "Start", "End", "Average");

    // Loop to calculate and print six-month moving averages
    for (int i = 0; i < NUM_MONTHS - 5; i++) {
        double sum = 0;

        // Calculate the sum of sales for the next six months
        for (int j = i; j < i + 6; j++) {
            sum += salesData[j].sales;
        }

        // Print the start month, end month, and the average sales for the six-month period
        printf("%-10s %-10s $%10.2lf\n", salesData[i].month, salesData[i + 5].month, sum / 6);
    }
}

// Function to print the sales report sorted from highest to lowest sales
void printSortedSalesReport(MonthlySales salesData[]) {
    printf("\nSales Report (Highest to Lowest):\n");
    printf("%-10s %10s\n", "Month", "Sales");

    // Bubble sort to sort salesData array based on sales values in descending order
    for (int i = 0; i < NUM_MONTHS; i++) {
        for (int j = i + 1; j < NUM_MONTHS; j++) {
            if (salesData[i].sales < salesData[j].sales) {
                MonthlySales temp = salesData[i];
                salesData[i] = salesData[j];
                salesData[j] = temp;
            }
        }
    }

    // Loop to print the sorted sales report
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-10s $%10.2lf\n", salesData[i].month, salesData[i].sales);
    }
}

// Main function
int main() {
    MonthlySales salesData[NUM_MONTHS];

    // Read sales data from the file
    readSalesData(salesData);

    // Print the monthly sales report
    printSalesReport(salesData);

    // Print the sales summary
    printSalesSummary(salesData);

    // Print six-month moving averages
    printSixMonthMovingAverages(salesData);

    // Print the sorted sales report
    printSortedSalesReport(salesData);

    // Return 0 to indicate successful execution
    return 0;
}
