#include <stdio.h>
#include <stdlib.h>

const double pi = 3.1415926538;
double square_area(double length);
double sphere_volume(double radius);
double cube_surface_area(double length);

int main(void)
{
	int option;
	double side_length;
	double area;
	double radius;
	double volume;
	double surface_area;

	do
	{
		//Print menu
		printf("1) Compute the area of a square\n");
		printf("2) Compute the volume of a sphere\n");
		printf("3) Compute the surface area of a cube\n");
		printf("4) Quit\n");
		printf("Enter an option: ");

		//Run selected function
		scanf("%d", &option);
		switch (option)
		{
			case 1:
				//Area of a square
				printf("\nEnter the side legnth (cm): ");
				scanf("%lf", &side_length);
				area = square_area(side_length);
				printf("Area of the square: %.2lf (cm)\n\n", area);
				break;
			case 2:
				//Volume of a sphere
				printf("\nEnter the radius (cm): ");
				scanf("%lf", &radius);
				volume = sphere_volume(radius);
				printf("Volume of the sphere: %.2lf (cm)\n\n", volume);
				break;
			case 3:
				//Surface area of a cube
				printf("\nEnter the side legnth (cm): ");
				scanf("%lf", &side_length);
				surface_area = cube_surface_area(side_length);
				printf("Surface area of the cube: %.2lf (cm)\n\n", surface_area);
				break;
			case 4:
				printf("\nGoodbye!\n");
				break;
			default:
				printf("Umm... that wasn't an option. Could you try that again?\n\n");
		}
	} while (option != 4);

	return 0;
}

//calculation functions
double square_area(double length) { return length * length; }
double sphere_volume(double radius) { return (4.0/3.0) * pi * (radius * radius * radius); }
double cube_surface_area(double length) { return 6 * square_area(length); }
