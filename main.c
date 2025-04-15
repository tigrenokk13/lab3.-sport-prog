#include <stdio.h>
#define PI 3.14159

int main() {
    //Завдання 1:  Користувач вводить довжину в метрах. Виведіть її в сантиметрах і міліметрах.
    float meters;
    printf("Task 1: Convert meters to centimeters and millimeters\n");
    printf("Enter length in meters: ");
    scanf("%f", &meters);

    float centimeters = meters * 100;
    float millimeters = meters * 1000;

    printf("Centimeters: %.2f cm\n", centimeters);
    printf("Millimeters: %.2f mm\n\n", millimeters);

    //Завдання 2: Напишіть програму, яка зчитує радіус кола та обчислює його площу.Формула: S=π∗r2

    float radius;
    printf("Task 2: Calculate the area of a circle\n");
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    float area = PI * radius * radius;
    printf("Area of the circle: %.2f\n\n", area);

    //Завдання 3: Користувач вводить кількість секунд. Виведіть еквівалент у годинах, хвилинах і секундах.13
    double total_seconds;
    printf("Task 3: Convert seconds to hours, minutes, and seconds\n");
    printf("Enter total seconds: ");
    scanf("%lf", &total_seconds);

    double hours = total_seconds / 3600.0;
    double minutes = (total_seconds / 60.0);
    double seconds = total_seconds;

    printf("Hours (decimal): %.6f\n", hours);
    printf("Minutes (decimal): %.6f\n", minutes);
    printf("Seconds: %.f\n\n", seconds);


    //Завдання 4: Напишіть програму, яка зчитує ціле число та перевіряє, чи є воно парним.
    int number;
    printf("Task 4: Check if a number is even\n");
    printf("Enter an integer: ");
    scanf("%d", &number);

    printf("%s\n\n", (number % 2 == 0) ? "The number is even." : "The number is odd.");


    //Завдання 5: Користувач вводить малу літеру англійського алфавіту. Перетворіть її на велику.
    char letter;
    printf("Task 5: Convert lowercase letter to uppercase\n");
    printf("Enter a lowercase letter: ");
    scanf(" %c", &letter); 

    if (letter >= 'a' && letter <= 'z') {
        char upper = letter - 32;
        printf("Uppercase letter: %c\n", upper);
    } else {
        printf("That is not a lowercase English letter.\n");
    }

    return 0;
}
