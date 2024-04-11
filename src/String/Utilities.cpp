#include"Utilities.h"
int toHex(int n){
	int arr[4]={0, 0, 0, 0};
        int i=0;
        while(n>0){
                arr[3-(i++)]=n%16;
                n/=16;
        }
	int runner=2;
	int res=0;
	for(int i=0; i<4; i++){
		runner%=4;
		res*=16;
		res+=arr[runner];
		runner++;
	}
	return res;
}
int lengthOf(const char* str){
	if(!str){return 0;}
	int i=0;
	while(*(str+i)!='\0'){i++;}
	return i;
}
bool strcmp(const char* str1, const char* str2){
	if(!str1 || !str2){
		return false;
	}
	while(*str1!='\0' && *str2!='\0'){
		if(*(str1++)!=*(str2++)){return false;}
	}
	if(*str1!='\0' || *str2!='\0'){return false;}
	return true;
}
void strcpy(char* dest, const char* origin){
	if(!origin || !dest){
		return;
	}

	while(*origin!='\0'){
		*(dest++)=*(origin++);
	}
}
void strconcat(char* dest, const char* origin){
	if(!origin || !dest){
		return;
	}
	while(*dest!='\0'){dest++;}
	strcpy(dest, origin);
}
void strreverse(char* str){
	char* end=str;
	while(*(end+1)!='\0'){end++;}
	while(str<end){
		char aux=*str;
		*(str++)=*end;
		*(end--)=aux;
	}
}