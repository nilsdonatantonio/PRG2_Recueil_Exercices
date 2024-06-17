
int main(){
    char array[60];

    char *ptr;
    char strs[3];

    ptr = array;

    sprintf(ptr, "%s", "Mercredi");

    strs[2] = ptr;

    ptr +=28;

    sprintf(ptr, "%s", "Lundi");

    strs[0] = ptr;

    ptr += 14;

    sprintf(ptr, "%s", "Mardi");

    strs[1] = ptr;


    for(int i = 0; i <= 3; ++i){
        printf("%s\n", strs[i]);
    }
}