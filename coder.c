#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stredit.h"
#include "coder.h"

static const int ASCII = 256; //Количество символов в таблице ASCII

void mutableCaesarEncode (char* str, const int key) {
	mutableStrip(str);
	int size = strlen(str);
	for (int i = 0; i < size; i++) {
		str[i] = (str[i] + key) % ASCII;
	} 
}

char* immutableCaesarEncode (const char* str, const int key) {
	char* newStr = immutableStrip(str);
	mutableToLower(newStr);
	int size = strlen(newStr);
	for (int i = 0; i < size; i++) {
		newStr[i] = (newStr[i] + key) % ASCII;
	}

	return newStr;
}

void mutableCaesarDecode(char* str, int key) {
	mutableCaesarEncode(str, -key);
}

char* immutableCaesarDecode (const char* str, const int key) {
	return immutableCaesarEncode(str, -key);
}

void mutableXorEncode (char* str, const char* key) {
	mutableStrip(str);
	mutableToLower(str);
	int size = strlen(str);
	int keySize = strlen (key);
	int j = 0;
	for (int i = 0; i < size; i++) {
		str[i] = (char)(str[i] ^ key[j]);
		j = (j + 1) % keySize;
	}
}

char* immutableXorEncode (const char* str, const char* key) {
	char* newStr = immutableStrip(str);
	mutableToLower(newStr);
	int size = strlen(newStr);
	int keySize = strlen(key);
	int j = 0;
	for (int i = 0; i < size; i++) {
		newStr[i] = (char)(newStr[i] ^ key[j]);
		j = (j + 1) % keySize;
	}

	return newStr;
}

void mutableXorDecode (char* str, const char* key) {
	mutableXorEncode(str, key);
}

char* immutableXorDecode (const char* str, const char* key) {
	return immutableXorEncode (str, key);
}
