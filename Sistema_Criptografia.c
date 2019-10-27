#include <stdio.h>
#include <string.h>
#include <locale.h> 

void CrifaDeCesar(char *src, int chave) {
	
int n = 0;
	
	while (src[n] != 0){
		
		if ((src[n] + chave) > 240)
		{
			src[n] -= 192;
		
		}
		
		if ((src[n] + chave) < 48)
		{
			src[n] += 192;
		
		}

		src[n] = src[n] + chave;
		n++;
	}
}

int main() {
	
	// define a cor de fundo e cor de letra do programa: 
	system("color 0b");

    //habilita a acentua��o para o portugu�s	
    setlocale(LC_ALL, "Portuguese");

// variaveis declaradas, e usadas no sistema de criptografia abaixo:	
char texto[128], aux[128], senha1[26], senha2[26], senha3[26], senhaG[26], resp[3];
int i, res, opcao;


// inicio do la�o de repeti��o "do while" referente 
//� vontade do usu�rio continuar executando o programa
// caso ele deseje , no fim do programa existe a pergunta
// se o usuario digitar que deseja voltar para o menu, esse
//  "do while" far� isso:
do {
	      // titulo e boas vindas ao usu�rio:
	      system("cls");
	      printf("_____________________________________________________________________________________________________________________\n");
          printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          printf("\n                                                 NAVIO - P�ROLA NEGRA                                               ");
          printf("\n_____________________________________________________________________________________________________________________\n\n\n\n");
          
          printf("\t\tSeja Bem Vindo(a) ao sistema de criptografia e descriptografia de mensagens para o Navio.\n\n\n");
          
          printf("\t\tObserva��es:\n\n");
          printf("\t\tLimite de at� 128 caracteres.\n");
          printf("\t\tN�o utilizar acentos,pontua��es ou caracteres especiais na mensagem.\n");
          printf("\t\tN�o utilizar espa�o na senha.\n\n\n");
          
         // inicio do MENU de op��es:  
          printf("                                  ________________________________________________\n");
		  printf("                                 |______________________MENU______________________|\n");
          printf("                                 | 1   -  Criptografar uma mensagem para o Navio. |\n");
          printf("                                 | 2   -  Descriptografar uma mensagem.           |\n");
          printf("                                 | 3   -  SAIR.                                   |\n");
          printf("                                 |________________________________________________|\n\n\n");
          printf("Digite a opc�o desejada: ");
          scanf("%d", &opcao);
          setbuf(stdin, NULL);
          
          
        // teste para saber op��o desejada pelo usu�rio, 
	    // e dessa forma iniciar o bloco de codigo correto:
        if (opcao == 1){  
		  // --------------------------------------------------- -cabe�alho da pagina---------------------------------------------------------
		  system("cls");
	      printf("_____________________________________________________________________________________________________________________\n");
          printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          printf("\n                                                 NAVIO - P�ROLA NEGRA                                               ");
          printf("\n_____________________________________________________________________________________________________________________\n\n\n\n");
          // --------------------------------------------------- --------------------------------------------------------------------------------
		 printf("\n\t\t\t\t\tVamos criptografar uma mensagem para o Navio.\n\n\n\n\n");
		 printf("Digite a mensagem: \n\n");
		 gets(texto);
		 setbuf(stdin, NULL);
		
		// la�o para contar os caracteres digitados:
		for (i = 0; i < 127; i++){ 
		
			aux[i] = texto[i];		
		}// fim do for para contar os caracteres digitados e guarda-los no vetor aux[i]


		// recebimento e valida��o de senha para 
		// executar a criptografia da mensagem 
		//digitada anteriormente:
		printf("\n\nCrie uma senha para criptografar a mensagem: "); 
		gets(senha1);
		printf("\n\nConfirme sua senha novamente: ");
		gets(senha2);
		res = strcmp(senha1, senha2);
	
	   // Laco de repeticao para configurar senha,
	   // no caso, ver se a senha digitada est� correta
	   // caso n�o esteja, este la�o se repete at� que 
	   // a senha seja diferente da que est� gravada 
	   // na variavel "chave2", quando for igual, o
	   // programa segue seu curso:
		while (res != 0){ 	
          // --------------------------------------------------- -cabe�alho da pagina---------------------------------------------------------
          system("cls");
	      printf("_____________________________________________________________________________________________________________________\n");
          printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          printf("\n                                                 NAVIO - P�ROLA NEGRA                                               ");
          printf("\n_____________________________________________________________________________________________________________________\n\n\n\n");
          //-----------------------------------------------------------------------------------------------------------------------------------
			system("color 0c");
            printf("\n\n\n\nsenha incorreta! criptografia Negada. Tente outra vez: ");
			gets(senha2);
			res = strcmp(senha1, senha2);
			
		}// fim do la�o
		
		// este if depende do while acima,
		// quando a condi��o do la�o while acima
		// for falsa, ou seja, a variavel "res", ap�s 
		// comparada com a senha alocada na variavel 
		// "chave2" for igual, no caso o retorno for 
		// verdadeiro este if ira executar a criptografia:
		if (res == 0){
			// ------------------------------------------------------------------------------------------------------------------------------------	
			system("cls");
	      printf("_____________________________________________________________________________________________________________________\n");
          printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          printf("\n                                                 NAVIO - P�ROLA NEGRA                                               ");
          printf("\n_____________________________________________________________________________________________________________________\n\n\n\n");
		// ------------------------------------------------------------------------------------------------------------------------------------		
            system("color 0a");
			printf("\n\n\n\n\t\t\t\t\tsenha correta! Criptografia Liberada!\n");
			// chamada da fun��o para criptografar:
		    CrifaDeCesar(aux, 4);
			
			//esse c�digo abaixo cria um ponteiro na 
			// mem�ria, dessa forma conseguimos gravar
			// o conteudo da variavel aux,(que est� contendo
			// o texto criptografado), num arquivo txt, e ainda
			// mostramos na tela:
			FILE *file;
			file = fopen("texto_criptografado.txt", "wt");
			fprintf(file,aux);
			fclose(file);
			
			// exibindo o texto criptografado na tela:
			printf("\n\n\nMensagem criptografada: %s\n\n", aux); 		
			printf("\n\nMensagem Criptografada e salva em um arquivo TXT com Sucesso.\n\n\n\n\n");
		    system("PAUSE");
		    system("color 0b");
		    // salvando a senha criada num txt
			for (i = 0; i < 26; i++){ 
			senhaG[i] = senha2[i];		
		  }
		    CrifaDeCesar(senhaG, 4);		
			FILE *senha;
			senha = fopen("win_sistem.dat", "wt");
			fprintf(senha,senhaG);
			fclose(senha);
		    	
       } // fim do if de criptografia.
     
      //  este else if, corresponde ao if 
      // que foi aberto l� em cima, ele serve para
      // que se a op��o digitada pelo usuario no inicio 
      // do programa seja a n�mero 2, este if ir� iniciar 
	  //o bloco de c�digo referente � descriptografia da
	  // mensagem que foi digitada e consequentemente criptografada:
       } else if(opcao == 2){   
          // --------------------------------------------------- -cabe�alho da pagina---------------------------------------------------------
          system("cls");
	      printf("_____________________________________________________________________________________________________________________\n");
          printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          printf("\n                                                 NAVIO - P�ROLA NEGRA                                               ");
          printf("\n_____________________________________________________________________________________________________________________\n\n\n\n");
          //------------------------------------------------------------------------------------------------------------------------------------
          
          	// importar o texto criptografado do arquivo TXT
			FILE *file;
          	file = fopen("texto_criptografado.txt", "rt"); 
			fgets(aux, 128, file);
			printf("\n\nMensagem a ser descriptografada: \n\n%s\n\n\n", aux);
            fclose(file);
            
           	// importando senha e descriptografando
			FILE *senha;
          	senha = fopen("win_sistem.dat", "rt"); 
			fgets(senhaG, 26, senha);
          	fclose(senha);
            CrifaDeCesar(senhaG, -4); 
			
            // entrada da senha do usuario:
  			printf("\nDigite a senha para descriptografar a mensagem: ");
			gets(senha3);
			res = strcmp(senha3,senhaG);

            // Laco de repeticao para configurar senha
			while (res != 0){ 
			    system("color 0c");
				printf("\nSenha incorreta! descriptografia negada! Tente outra vez: \n");
				gets(senha3);
				res = strcmp(senha3, senhaG);
			}
			    // quando a senha for confirmada executara a descriptografia:
				if (res == 0){
				// --------------------------------------------------- -cabe�alho da pagina---------------------------------------------------------
				system("cls");
	          	printf("_____________________________________________________________________________________________________________________\n");
          		printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          		printf("\n                                                 NAVIO - P�ROLA NEGRA                                               ");
          		printf("\n_____________________________________________________________________________________________________________________\n\n\n\n");
				// ------------------------------------------------------------------------------------------------------------------------------------	
				system("color 0a");
				printf("\n\n\t\t\t\t\tSenha correta! Decriptografia Liberada! \n");
                CrifaDeCesar(aux, -4); 
                
                // salvando descriptografia em um arquivo TXT
                FILE *file;
			    file = fopen("texto_descriptografado.txt", "wt");
			    fprintf(file,aux);
			    fclose(file);
			    
			    // Mostrando na tela texto descriptografado:
				printf("\n\nMensagem Descriptografada �: %s\n\n",aux);
				printf("\n\nMensagem Descriptografada e salva em TXT com Sucesso! \n\n\n\n");
			    system("PAUSE");
			    system("color 0b");
			}
		  }
		  else if(opcao == 3){
		  	     // for�a o fechamento do programa:
                 exit(0);
               }
	      
	      // --------------------------------------------------- -cabe�alho da pagina---------------------------------------------------------
	      system("cls");
	      printf("_____________________________________________________________________________________________________________________\n");
          printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          printf("\n                                                 NAVIO - P�ROLA NEGRA                                               ");
          printf("\n_____________________________________________________________________________________________________________________\n\n\n\n");
	      //--------------------------------------------------------------------------------------------------------------------------------------
	
	     printf("\n\n\n\n\n\n\t\t\t\tDeseja voltar para o menu inicial?  Sim ou N�o? : ");
	     scanf("%s", &resp);
	     strupr(resp);
 }
	while(strcmp(resp,"SIM") == 0);
    system("cls");
 //-------------------------------------------------------------------------------------------------------------------------------------------------------   
    printf ("\nRodando em sistema:");
    system ("ver");
	printf ("programa completamente executado em\n");
    system ("date/t");
    printf ("as ");
    system ("time/t");
    printf ("\n\n");
	printf("\n\n\n\n\n\n\n\t\t\t\t\t\tPrograma Finalizado!\n\n\n\n\n\n\n\n\n");
	system("PAUSE");
	return 0;
	
} //fim








