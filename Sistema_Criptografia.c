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

    //habilita a acentuação para o português	
    setlocale(LC_ALL, "Portuguese");

// variaveis declaradas, e usadas no sistema de criptografia abaixo:	
char texto[128], aux[128], senha1[26], senha2[26], senha3[26], senhaG[26], resp[3];
int i, res, opcao;


// inicio do laço de repetição "do while" referente 
//á vontade do usuário continuar executando o programa
// caso ele deseje , no fim do programa existe a pergunta
// se o usuario digitar que deseja voltar para o menu, esse
//  "do while" fará isso:
do {
	      // titulo e boas vindas ao usuário:
	      system("cls");
	      printf("_____________________________________________________________________________________________________________________\n");
          printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          printf("\n                                                 NAVIO - PÉROLA NEGRA                                               ");
          printf("\n_____________________________________________________________________________________________________________________\n\n\n\n");
          
          printf("\t\tSeja Bem Vindo(a) ao sistema de criptografia e descriptografia de mensagens para o Navio.\n\n\n");
          
          printf("\t\tObservações:\n\n");
          printf("\t\tLimite de até 128 caracteres.\n");
          printf("\t\tNão utilizar acentos,pontuações ou caracteres especiais na mensagem.\n");
          printf("\t\tNão utilizar espaço na senha.\n\n\n");
          
         // inicio do MENU de opções:  
          printf("                                  ________________________________________________\n");
		  printf("                                 |______________________MENU______________________|\n");
          printf("                                 | 1   -  Criptografar uma mensagem para o Navio. |\n");
          printf("                                 | 2   -  Descriptografar uma mensagem.           |\n");
          printf("                                 | 3   -  SAIR.                                   |\n");
          printf("                                 |________________________________________________|\n\n\n");
          printf("Digite a opcão desejada: ");
          scanf("%d", &opcao);
          setbuf(stdin, NULL);
          
          
        // teste para saber opção desejada pelo usuário, 
	    // e dessa forma iniciar o bloco de codigo correto:
        if (opcao == 1){  
		  // --------------------------------------------------- -cabeçalho da pagina---------------------------------------------------------
		  system("cls");
	      printf("_____________________________________________________________________________________________________________________\n");
          printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          printf("\n                                                 NAVIO - PÉROLA NEGRA                                               ");
          printf("\n_____________________________________________________________________________________________________________________\n\n\n\n");
          // --------------------------------------------------- --------------------------------------------------------------------------------
		 printf("\n\t\t\t\t\tVamos criptografar uma mensagem para o Navio.\n\n\n\n\n");
		 printf("Digite a mensagem: \n\n");
		 gets(texto);
		 setbuf(stdin, NULL);
		
		// laço para contar os caracteres digitados:
		for (i = 0; i < 127; i++){ 
		
			aux[i] = texto[i];		
		}// fim do for para contar os caracteres digitados e guarda-los no vetor aux[i]


		// recebimento e validação de senha para 
		// executar a criptografia da mensagem 
		//digitada anteriormente:
		printf("\n\nCrie uma senha para criptografar a mensagem: "); 
		gets(senha1);
		printf("\n\nConfirme sua senha novamente: ");
		gets(senha2);
		res = strcmp(senha1, senha2);
	
	   // Laco de repeticao para configurar senha,
	   // no caso, ver se a senha digitada está correta
	   // caso não esteja, este laço se repete até que 
	   // a senha seja diferente da que está gravada 
	   // na variavel "chave2", quando for igual, o
	   // programa segue seu curso:
		while (res != 0){ 	
          // --------------------------------------------------- -cabeçalho da pagina---------------------------------------------------------
          system("cls");
	      printf("_____________________________________________________________________________________________________________________\n");
          printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          printf("\n                                                 NAVIO - PÉROLA NEGRA                                               ");
          printf("\n_____________________________________________________________________________________________________________________\n\n\n\n");
          //-----------------------------------------------------------------------------------------------------------------------------------
			system("color 0c");
            printf("\n\n\n\nsenha incorreta! criptografia Negada. Tente outra vez: ");
			gets(senha2);
			res = strcmp(senha1, senha2);
			
		}// fim do laço
		
		// este if depende do while acima,
		// quando a condição do laço while acima
		// for falsa, ou seja, a variavel "res", após 
		// comparada com a senha alocada na variavel 
		// "chave2" for igual, no caso o retorno for 
		// verdadeiro este if ira executar a criptografia:
		if (res == 0){
			// ------------------------------------------------------------------------------------------------------------------------------------	
			system("cls");
	      printf("_____________________________________________________________________________________________________________________\n");
          printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          printf("\n                                                 NAVIO - PÉROLA NEGRA                                               ");
          printf("\n_____________________________________________________________________________________________________________________\n\n\n\n");
		// ------------------------------------------------------------------------------------------------------------------------------------		
            system("color 0a");
			printf("\n\n\n\n\t\t\t\t\tsenha correta! Criptografia Liberada!\n");
			// chamada da função para criptografar:
		    CrifaDeCesar(aux, 4);
			
			//esse código abaixo cria um ponteiro na 
			// memória, dessa forma conseguimos gravar
			// o conteudo da variavel aux,(que está contendo
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
      // que foi aberto lá em cima, ele serve para
      // que se a opção digitada pelo usuario no inicio 
      // do programa seja a número 2, este if irá iniciar 
	  //o bloco de código referente à descriptografia da
	  // mensagem que foi digitada e consequentemente criptografada:
       } else if(opcao == 2){   
          // --------------------------------------------------- -cabeçalho da pagina---------------------------------------------------------
          system("cls");
	      printf("_____________________________________________________________________________________________________________________\n");
          printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          printf("\n                                                 NAVIO - PÉROLA NEGRA                                               ");
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
				// --------------------------------------------------- -cabeçalho da pagina---------------------------------------------------------
				system("cls");
	          	printf("_____________________________________________________________________________________________________________________\n");
          		printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          		printf("\n                                                 NAVIO - PÉROLA NEGRA                                               ");
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
				printf("\n\nMensagem Descriptografada é: %s\n\n",aux);
				printf("\n\nMensagem Descriptografada e salva em TXT com Sucesso! \n\n\n\n");
			    system("PAUSE");
			    system("color 0b");
			}
		  }
		  else if(opcao == 3){
		  	     // força o fechamento do programa:
                 exit(0);
               }
	      
	      // --------------------------------------------------- -cabeçalho da pagina---------------------------------------------------------
	      system("cls");
	      printf("_____________________________________________________________________________________________________________________\n");
          printf("\n                                               SISTEMA DE CRIPTOGRAFIA                                              ");
          printf("\n                                                 NAVIO - PÉROLA NEGRA                                               ");
          printf("\n_____________________________________________________________________________________________________________________\n\n\n\n");
	      //--------------------------------------------------------------------------------------------------------------------------------------
	
	     printf("\n\n\n\n\n\n\t\t\t\tDeseja voltar para o menu inicial?  Sim ou Não? : ");
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








