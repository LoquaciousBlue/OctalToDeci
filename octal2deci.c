// A c code that asks for an octal formatted string and returns its decimal value. 

#define STRINGSIZE 100  

//Validates input string contains only integers 0-8 from string and string length input. Returns 0 if invalid input, else returns 1.
int checkString(char str[], int length) {
    int i = 0;
    for(i = 0; i < length; i++) {
        if(str[i] >= 48 && str[i] <= 56) {  //48 = 0 , 56 = 8 
            continue;
        } elsae {
            return 0;  // not 0-8 or non-int input 
        }
    }
    return 1; //Input valid
}

//Calculates and returns string length as int based on input string
int stringLength(char str[]) {
    int length = 0;
    for (length = 0; str[length] != '\0'; ++length);
    printf("%c", str[length]);
    return length;  
}

//Calculates decimal value from octal representation 
int octa2Deci(char str[], int length) {
    int val, i = 0;
    int temp = 0;
    for(i = 0; i < length; i++) {  //Iterate through octal string from left 
        temp = (int)str[i]-48;  //Converts character to ascii value and subtracts common value 48 giving plain int 
        temp = temp*pow8(length-i-1); //calculates decimal value at array index
        val = val+temp; //add to total decimal
    }
    return val;
}

//Calculates exponents of 8 and returns its val based on exponent value input num
int pow8(int num) {
    int val = 1;
    int i = 0;
    if (num == 0) {  //Special 8^0 case. 
        return val;
    }
    for(i = 0; i < num; i++) {  //Calculates 8^num
        val = val*8;
    }
    return val;
}

int main() {
    char str[STRINGSIZE];  //Initialize a generic string of 100 characters
    int length = 0;
    printf("Please input an octal formatted string:");
    scanf("%s", str);
    length = stringLength(str);

    if(checkString(str, length) == 0) {
        printf("\nInvalid Integer");
        return 0;
    } else {
        printf("\nDecimal Value: %d", octa2Deci(str, length));
        return 0;
    }

}

