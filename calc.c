#include <stdio.h>
#include <stdlib.h>
int main()
{
    char char1[100];
    char sign;
    char char2[100];
    int result = 0;
    printf("Enter first num:\n");
    fgets(char1, 100, stdin);
    int num1 = atoi(char1);
    printf("Enter sign(+,-,*,/)\n");
    sign = getchar();
    printf("Enter second num:\n");
    fgets(char2, 100, stdin);
    int num2 = atoi(char2);
    if(sign == '+'){
      result = num1 + num2;
    }
    else if(sign == '-'){
      result = num1 - num2;
    }
    else if(sign == '/'){
      int i = 0;
      while(0 == 0){
        if(i * num2 > num1){
          result = i - 1;
          break;
        }
        i = i + 1;
      }
    }
    else if(sign == '*'){
      for(int i=0; i<num2; i++){
        result = result + num1;
      }
    }
    printf("Result:\n");
    printf("%d", result);
    getchar();
    return 0;
}
