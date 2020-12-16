#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> 
#include "stredit.h"

int strToInt (const char* str) {
	int res = 0;
	int size = strlen(str);
	int i  = 0;
	int sign = 0;
	if (!(isNumber(str))) {
		printf("ERROR: Строка содержит буквы");
		exit(1);
	}
	
	if (str[0] == '-') {
		i = 1;
		sign =1;
	}
	
	for (; i < size; i++) {
		res += str[i] - '0';
		res *= 10;
	}
	res /= 10;
	if (sign == 1 ) {
		res = -res;
	}
	return res;
}

void mutableToUpper (char* str) {
	int i = 0;
	while (str[i] != '\0') {
		if ((str[i] >= 'a') && (str[i] <= 'z')) {
			str[i] += 'A' - 'a';
		}
		i++;
	}
}

void mutableToLower (char* str) {
	int i = 0;
	while (str[i] != '\0') {
		if ((str[i] >= 'A') && (str[i] <= 'Z')) {
			str[i] -= 'A' - 'a';
		}
		i++;
	}
}

char* immutableToUpper (const char* str) {
	int size = strlen(str);
	char* newStr = (char*) malloc (sizeof(char) * (size + 1));
	int i = 0;
	while (str[i] != '\0') {
		if ((str[i] >= 'a') && (str[i] <= 'z')) {
			newStr[i] = str[i] + ('A' - 'a');
		}
		else {
			newStr[i] = str[i];
		}
		i++;
	}

	return newStr;
}

char* immutableToLower (const char* str) {
	int size = strlen(str);
	char* newStr = (char*) malloc (sizeof(char) * size);
	int i = 0;
	while (str[i] != '\0') {
		if ((str[i] >= 'a') && (str[i] <= 'z')) {
			newStr[i] = str[i] - ('A' - 'a');
		}
		else {
			*(newStr + i) = str[i];
		}
		i++;
	}

	return newStr;
}

void mutableStrip (char* str) {
	int size = strlen(str);
	int startSpaces = 0;
	int i = 0;
	while (str[i] == ' ') {
		startSpaces++;
		i++;
	}

	int endSpaces = 0;
	i  = size - 1;
	while (str[i] == ' ') {
		endSpaces++;	
		i--;
	}

	int newSize = size - startSpaces - endSpaces;
	for (int j = 0; j < newSize; j++) {
		str[j] = str[startSpaces + j];
	}
	str[newSize] = '\0';
}

char* immutableStrip (const char* str) {
	int size = strlen(str);
	int startSpaces = 0;
	int i = 0;
	while (str[i] == ' ') {
		startSpaces++;
		i++;
	}

	int endSpaces = 0;
	i = size - 1;
	while (str[i] == ' ') {
		endSpaces++;
		i--;
	}

	int newSize = size - startSpaces - endSpaces;
	char* newStr = (char*) malloc (sizeof(char) * newSize);
	for (int j = 0; j < newSize; j++) {
		newStr[j] = str[startSpaces + j];
	}
	newStr[newSize] = '\0';

	return newStr;
}

void mutableRemoveSpaces(char* str) {
	int size = strlen(str);
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (str[i] != ' ') {
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
}

char* immutableRemoveSpaces(const char* str) {
	int size = strlen(str);
	char* newStr = (char*) malloc (sizeof(char) * size);
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (str[i] != ' ') {
			newStr[j] = str[i];
			j++;
		}
	}
	newStr[j] = '\0';
	return newStr;
}

void mutableFilter (char* str) {
	int size = strlen(str);
	int j = 0;
	for (int i = 0; i < size; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9')
			|| (str[i] == ' '))
		{
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
}

char* immutableFilter (const char* str) {
	int size = strlen(str);
	char* newStr = (char*) malloc (sizeof(char) * size);
	int j = 0;
	for (int i = 0; i < size; i++) {
		if ((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9')
			|| (str[i] == ' '))
		{
			newStr[j] = str[i];
			j++;
		}
	}
	newStr[j] = '\0';
	return newStr;
}

bool isNumber (const char* str) {
	int size = strlen(str);
	int j = 0;
	int f1 = 0;
	for (int i = 0; i < size; i++) {
		if (!((str[i] >= '0' && str[i] <= '9')
			|| (str[i] == '-')
			|| (str[i] == '.')))
		{
			return false;
		}
		else if (str[i] == '.') {
			if (f1 == 1) {
				return false;
			}
			f1 = 1;
		}
		else if (str[i] == '-' && i != 0) {
			return false;
		}
	}
	return true;
}

bool isAlpha (const char* str) {
	int size = strlen(str);
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (!((str[i] >= 'a' && str[i] <= 'z') 
			|| (str[i] >= 'A' && str[i] <= 'Z')))
		{
			return false;
		}
	}
	return true;
}

