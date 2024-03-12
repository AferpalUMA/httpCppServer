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

