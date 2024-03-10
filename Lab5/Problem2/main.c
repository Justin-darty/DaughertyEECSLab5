#include <stdio.h>

// Function to calculate and print possible combinations of scoring plays for a given NFL score
void calculate_combinations(int score) {
    // Display a header for the output
    printf("Possible combinations of scoring plays for %d points:\n", score);

    // Nested loops to iterate through different combinations of touchdowns (tds), field goals (fgs),
    // safeties, two-point conversions, and one-point field goals
    for (int tds = 0; tds <= score / 6; tds++) {
        for (int fgs = 0; fgs <= score / 3; fgs++) {
            for (int safeties = 0; safeties <= score / 2; safeties++) {
                for (int two_pt_conversions = 0; two_pt_conversions <= tds; two_pt_conversions++) {
                    for (int one_pt_fgs = 0; one_pt_fgs <= tds; one_pt_fgs++) {
                        // Calculate the total score for the current combination
                        int total = (tds * 6) + (fgs * 3) + (safeties * 2) + (two_pt_conversions * 2) + (one_pt_fgs * 1);

                        // Check if the total score matches the input score
                        if (total == score) {
                            // Print the combination of scoring plays
                            printf("%d TD + %d 2pt, %d FG, %d 1pt FG, %d Safety\n", tds, two_pt_conversions, fgs, one_pt_fgs, safeties);
                        }
                    }
                }
            }
        }
    }
}

// Main function
int main() {
    int score;

    // Repeat the process until the user enters 0 or 1
    do {
        // Prompt the user to enter the NFL score
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);

        // Check if the entered score is greater than 1
        if (score > 1) {
            // Call the function to calculate and print possible combinations for the given score
            calculate_combinations(score);
        }
    } while (score > 1);

    // Return 0 to indicate successful execution
    return 0;
}

