

int main(){
    char nom[255];
    int age;

    char *ptr_nom = &nom;
    int *ptr_age = &age;

    char **ptr_ptr_nom = &ptr_nom;
    int **ptr_ptr_age = &ptr_age

    **ptr_ptr_nom = "Hello Baby";
    **ptr_ptr_age = 42;

    printf("Nom : %s, Age : %d", nom, age); 
     
}