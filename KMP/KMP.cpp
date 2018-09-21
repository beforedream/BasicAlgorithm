#include <iostream>
#include <cstring>
using namespace std;

int subStr_KMP(char *source, char *target){
	int targetLength = strlen(target);
	int next[targetLength];
	for(int i = 0; i < targetLength; i++){
		if(i == 0){
			next[i] = 0;
		}
		else{
			next[i] = 0;
			for(int j = 1; j < i; j++){
				int flag = 0;
				for(int k = 0; k < j; k++){
					if(target[k] != target[i - j + k]){
						flag = 1;
						break;
					}
				}
				if(flag == 0 && i != 1){
					next[i] = j;
				}
			}
		}
	}
	for(int i = 0; i < targetLength; i++){
		cout << i << " : " << next[i] << endl;
	}
	int i = 0, j = 0;
	for(; i < strlen(source) && j < strlen(target);){
		if(source[i] == target[j]){
			i++; 
			j++;
		}
		else if(j == 0){
			i++;
		}
		else{
			j = next[j];
		}
	}
	if(i == strlen(source)){
		return -1;
	}
	else{
		return i - j;
	}
}
int main(void){
	char a[25] = "abcabbcadbababa";
	char b[25] = "abab";
	cout << subStr_KMP(a, b) << endl;
	return 0;
} 

