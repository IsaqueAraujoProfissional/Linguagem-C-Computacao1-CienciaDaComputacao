#include <stdio.h>

int isVogal(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || 
		c == 'u' || c == 'A' || c == 'E' || c == 'I' || 
		c == 'O' || c == 'U';
}

int vogal1(char set[]) {
	int cnt = 0, i = 0;
	while (set[i] != '\0') 
		if(isVogal(set[i++]))
			cnt++;
	return cnt;
}

int vogal2(char *set) {
    /*if(*set == '\0'){
        return 0;
    }else{
        return vogal2(set+1)+isVogal(*set);
    }*/
    /*return *set == '\0' ? 0: isVogal(*set)+vogal2(set+1);*/
    return (*set == '\0') ? 0 : vogal2(set+1) +(isVogal(*set));
    
}
int vogal3(char *set){
    int quant = 0;
    while(*set!= '\0'){
        quant+=isVogal(*set);
        set++;
    }
    return quant;
}
int main()
{
	char set[] = "ABcei";
	printf("Ha %d vogais no alfabeto. (Vetor)\n", vogal1(set));
	printf("Ha %d vogais no alfabeto. (Ponteiro  recursivo)\n", vogal3(set));
	return 0;
}
