#include<stdio.h>
#include<stdlib.h>

struct no{
    int info;
    struct no* elo;
};

typedef struct no No;

struct pilha{
    No* no;
};

typedef struct pilha Pilha;

Pilha* cria(){
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->no = NULL;
    return pilha;
}

void vazia(Pilha* pilha){   
    if(pilha->no == NULL){
        printf("\nA pilha esta vazia!\n");
    }else{
        printf("\nA lista nao esta vazia!\n");
    }
}

No* insere_no(No* no , int info){
    No* no_topo = (No*) malloc(sizeof(No));
    no_topo->info = info;
    no_topo->elo = no;
    return no_topo;
}

void push(Pilha* pilha , int info){
    pilha->no = insere_no(pilha->no, info);
}

void imprime(Pilha* pilha){
    No* no;
    no = pilha->no; 
    printf("\nPilha: %p \nPilha->no: %p\n", pilha, pilha->no);
    while(no != NULL){
        printf("No %p => |INFO: %d | ELO: %p| \n", no, no->info, no->elo);
        no = no->elo;
    }
    printf("\n\n");
}

void busca(Pilha* pilha, int info){
    int cont_ocorrecia = 0;
	No* no;
    no = pilha->no; 
    int posicao = 1;
    while(no != NULL){
        if(info == no->info){
        	printf("Informacao %d encotrada na posicao %d da pilha. \n",no->info, posicao);
			cont_ocorrecia++;
		}
        no = no->elo;
        posicao++;
    }
    if(cont_ocorrecia == 0){
    	printf("A informacao %d nao encontrada na Pilha. \n", info);
	}
    printf("\n\n");
}

No* retira_no(No* no){
    No* no_topo = no->elo;
    free(no);
    return no_topo;
}

void pop(Pilha* pilha){
    pilha->no = retira_no(pilha->no);
}

void libera(Pilha* pilha){
    No* no_topo = pilha->no;;
    No* novo_no_topo;
    while(no_topo != NULL){
        novo_no_topo = no_topo->elo;
        free(no_topo);
        no_topo = novo_no_topo;
    }
    free(pilha);
}


int main(){
	
	Pilha* pilha1;
	int opcao, num;
	
	do{
		
		printf("\n\n   :::   MENU   :::   \n\n");
		printf(" 1 - Criar pilha \n 2 - Empilhar \n 3 - Desempilhar \n 4 - Busca \n 5 - Imprime \n 6 - Libera \n 7 - Sair \n\n Escolha: ");
		scanf("%d", &opcao);

		if(opcao == 1){
			pilha1 = cria();
		}else if(opcao == 2){
			printf("Digite a informacao: ");
			scanf("%d", &num);	
			push(pilha1, num);
		}else if(opcao == 3){
			pop(pilha1);
		}else if(opcao == 4){
			printf("Digite a informacao: ");
			scanf("%d", &num);	
			busca(pilha1, num);
		}else if(opcao == 5){
			imprime(pilha1);
		}else if(opcao == 6){
			libera(pilha1);
		}else if(opcao == 7){
			printf("\n\n   SAINDO DO PROGRAMA");
		}else{
			printf("\n\n   VALOR INCORRETO");
		}
	}while(opcao != 7);

}
