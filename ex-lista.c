#include <stdio.h>
#include <stdlib.h>
#define MAX 4
#define INVALIDO -1
typedef struct {
	int chave;
	int prox;
}ELEMENTOS;
typedef struct {
	ELEMENTOS A[MAX];
	//indice do próximo elemento disponivel {dispo}
	int dispo;
	// onde o inicio está apontado, qual elemento é o iinicio da lista;
	int inicio; 

}LISTA;

void inicializarEstrutura(LISTA *l){
	int i=0;
	// Cada Posição Do ARRAY está recebendo o seu respectivo próximo;
	for(i=0;i<MAX-1;i++) l->A[i].prox = i+1;
	l->A[MAX-1].prox = INVALIDO;
	// l->dispo esta em 0;
	l->dispo = 0;
	//incio invalido pois não há elementos inserido por isso inicio não aponta pra ngm e fica invalido;
	l->inicio = INVALIDO;
}
int tamanho(LISTA *l){
	int i = l->inicio, tam =0;
	//vai percorrer os proximo elementos ded toda á lista até encontra um inválido;
	while(i != INVALIDO){
		tam++;
		i = l->A[i].prox;
	}
	return tam;
}
void imprime(LISTA *l){
	int i = l->inicio;
	// Memso Modelo Pra Percorrer para ver  o tamanho percorre e imprime no determinado indice do i;
	while(i!= INVALIDO ){
		printf("Lista: %i ", l->A[i].chave);
	}
}
// Busca com a lista ordenada
int buscaSequencial(LISTA *l, int x){
	int i = l->inicio;
	//Truque se os elementos foram maior que o procurado não precisa continuar o laço isso se a lista for ordenada;
	while(i != INVALIDO && l->A[i].chave < x) i = l->A[i].prox;
	if(l->A[i].chave == x ) return i;
	else return -1;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// {FUNÇÕES DE INSERIR ELEMENTOS NA LISTA}
///Essa Função Retorna Qual Próximo Elemento Disponível para uso e atualiza o disponivel;
int obterNO(LISTA *l){
	int disponivel = l->dispo;
	//verificação de disponibilidade para atualização do (l->dispo) 
	if(l->dispo != INVALIDO){
		//atualizando o (l->dispo) para um proximo de acordo com o valor atual do (l->dispo)
		l->dispo = l->A[l->dispo].prox;
	}
	return disponivel;
}
// Tendo o Valor do Indice Que Está Disponivel na Lista pode se fazer a inserção dos elementos;
int inserirElementos(LISTA *l, int x){
	//verfica se a lista ta cheia caso esteja não há como adicionar
	if(l->dispo == INVALIDO) return -1;
	//ant é o indice do anterior ao  (x) que será inserido. 
	int ant = INVALIDO;
	int i = l->inicio;
	// vai verificar se i é invalido ese o valor salvo é menor que  o X indicado;
	// vai ajudar se tem anterior para pode ajudar os "Ponteiros"
	while(i != INVALIDO && l->A[i].chave < x){ 
		ant = i;
		i = l->A[i].prox;
	}
	//obtendo o indice disponivel para inserir os elementos e inseri na posição retornada;
	i = obterNO(l);
	l->A[i].chave = x;
	//vERIRFICA SE  O ELEMENTO TEM ANTERIOR, SE NÃO TIVER ELE É O PRIMEIRO DA LISTA;
	if(ant == INVALIDO){
		// o proximo vai ser quem era o inicio da lista;
		l->A[i].prox = l->inicio;
		// o inicio vai o ser elemento adicionado;
		l->inicio = i;
	}
	else {
		// Se tiver anterior o proximo do elemento adicionado vai apontar pro próximo do seu anterior pois ele esta sendo inserido entre seu anteirior e o seu sucessor
		l->A[i].prox = l->A[ant].prox;
		// e o seu anterior o proximo do seu anterior vai apontar para o indice do elemento adicionado;
		l->A[ant].prox = i; 
	}
}
// Função para Retornar o Indice Eliminado para os disponíveis;
void devolveNo(LISTA *l, int i){
	l->A[i].prox = l->dispo;
	l->dispo = i;
}
/// {Função de EXCLUSÂO de elementos}
int excluir(LISTA *l, int x){
	int ant = INVALIDO;
	int i = l->inicio;
	// Percorre ATÉ ENCONTRA OU CHEGAR AO FIM AS CONDIÇÕES;
	while(i != INVALIDO && l->A[i].chave < x){ ;
		ant = i;
		i = l->A[i].prox;
	}
	// Se o i Fo INVÁLIDO significa que o laço foi até o final do arranjo e não satisfez a segunda codição 
	// Segunda condição é pra enquanto elemento da chave que está salvo no array(Vetor) ser menor que o X (Elemento pássado pelo usário)
	//Então ele nem foio maior nem igual entao o elemento X Não Existe Não Podendo Ser apagado;  
	if(i == INVALIDO || l->A[i].chave != x) return -1;
	// Se tiver Não Tiver Anterior ou seja  o valor é o 1· o valor do inicio é atualizado para o próximo da posição do Elemento que será apagado
	if(ant == INVALIDO) l->inicio = l->A[i].prox;
	else l->A[ant].prox = l->A[i].prox;
	devolveNo(l,i);
	return 1;
}

int main (){
	// Agora é Só Usar as Funções ;) :)
	return 0;
}


