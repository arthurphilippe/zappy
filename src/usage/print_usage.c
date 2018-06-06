/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** print_usage file
*/

#include <stdio.h>

void print_usage_server()
{
	printf("USAGE: ./zappy_server -p port -x width -y height -n name1");
	puts(" name2 ... -c clientsNb -f freq\n\tport\t\tis the port number");
	puts("\twidth\t\tis the width of the world");
	puts("\theight\t\tis the height of the world");
	puts("\tnameX\t\tis the name of the team X");
	puts("\tclientsNb\tis the number of authorized clients per team");
	printf("\tfreq\t\tis the reciprocal of time unit for execution of ");
	puts("action");
}
