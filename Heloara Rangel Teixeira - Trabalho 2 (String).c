    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define MAX 1000
    
    void trocar(char *nome) 
    {
        int i;
        for (i = 0 ; nome[i] != '\0'; i++) 
        {
            if (nome[i] == 'o') 
            {
                nome[i] = '0';
            }
            
            else if (nome[i] == 'a') 
            {
                nome[i] = '@';
            }
            
            else if (nome[i] == '0') 
            {
                (nome[i] = 'o');
            } 
            
            else if (nome[i] == '@') 
            {
                nome[i] = 'a';
            }
        }
    }
    
    void inverter(char *string2)
    {
        int tamanho = strlen(string2);
        int i, aux, j = tamanho - 1;
        
        for(i = 0; i < j;i++, j--)
        {
            aux = string2[i]; 
            string2[i] = string2[j]; 
            string2[j] = aux;
        }
    }
    
    void incorporar(char *nome, char *string1, char *string2) 
    {
        int i, k = 0, j = 0;
        for (i=0; (i < strlen(nome)); i++) 
        {
            if (i % 2 == 0)
            {
                string1[k++] = nome[i];
            } 
            
            else 
            {
                string2[j++] = nome[i];
            }
        }
        string1[k] = '\0';
        string2[j] = '\0';
        
        inverter(string2);
    }
    
    void intercalar (char *string1, char *string2, char *mensagemCriptografada) 
    {
        int i, j=0; 
        
        for (i=0; string2[i] != '\0' || string1[i] != '\0'; i++) 
        {
            if (string1[i] !='\0') 
            {
                mensagemCriptografada[j++] = string1[i];
            }
            
            if (string2[i] !='\0') 
            {
                mensagemCriptografada[j++] = string2[i];
            }
        }
        
        mensagemCriptografada[j]='\0';
    }
    
    void criptografar(char *nome, char *string1, char *string2, char *mensagemCriptografada) 
    {
        trocar(nome);
    
        incorporar(nome, string1, string2);
    
        intercalar(string1,string2,mensagemCriptografada);
        
    }
    
    int main () {
        
        char nome[MAX], string1[MAX], string2[MAX], mensagemCriptografada[MAX];
        
        printf("Digite a mensagem que deseja criptografar:");
        fgets(nome, MAX, stdin);
        nome[strlen(nome) - 1] = '\0';
        
        criptografar(nome,string1, string2, mensagemCriptografada);
        printf("mensagem criptografada:%s",mensagemCriptografada);
        
        criptografar(nome,string1, string2, mensagemCriptografada);
        printf("\nmensagem descriptografada:%s",nome);
        
        
        return 0;
        
    }





















