#include <iostream>

using namespace std;

struct NoArvore{
	int data;
	NoArvore *left;
	NoArvore *right;
};

struct No {
	NoArvore *data;
	No *next;
};

void push(No *&topo, NoArvore *data){
	No *novoNo = new No;
	novoNo -> data = data;
	novoNo -> next = topo;
	topo = novoNo;
}

void top(No *&topo){
	if(topo == NULL){
		cout << "pilha vazia" << endl;
		return;
	}
	cout << "topo: " << topo -> data -> data;
}

void exibirPilha(No *&topo){
	cout << "[ ";
	No *atual = topo;
	while(atual != NULL){
		cout << atual -> data -> data << " ";
		atual = atual -> next;
	}
	cout << "]" << endl;
}

int size(No *&topo){
	int count = 0;
	No *atual = topo;
	while(atual != NULL){
		count ++;
		atual = atual -> next;
	}
	return count;
}

void pop(No *&topo){
	No *aux = topo;
	topo = topo -> next;
	delete aux;
}

void exibirArvore(NoArvore *raiz){
	if(raiz == NULL){
		return;
	}
	cout << raiz -> data << " ";
	exibirArvore(raiz -> left);
	exibirArvore(raiz -> right);
}

int nivelNoArvore(NoArvore *raiz, int contador = 0){
	if(raiz != NULL){
		contador ++;
		nivelNoArvore(raiz -> left, contador);
		nivelNoArvore(raiz -> right, contador);
		cout << "nivel do no " << raiz -> data << ": " << contador - 1 << endl;
	}
	return contador;
}

int contarNoArvore(NoArvore *raiz){
	if(raiz != NULL){
		return 1 + contarNoArvore(raiz -> left) + contarNoArvore(raiz -> right);
	}
	return 0;
}

int somarNoArvore(NoArvore *raiz){
	if(raiz != NULL){
		return raiz -> data + somarNoArvore(raiz -> left) + somarNoArvore(raiz -> right);
	}
	return 0;
}

double mediaArvore(NoArvore *raiz){
	return (double) somarNoArvore(raiz)/contarNoArvore(raiz);
}

void PreOrdemArvorePilha(NoArvore *raiz){
	No *pilha = new No;
	pilha = NULL;
	push(pilha, raiz);
	while(pilha!=NULL){
		NoArvore *aux = pilha -> data;
		cout << aux -> data << " ";
		pop(pilha);
		if(aux -> right != NULL){
			push(pilha, aux -> right);
		}
		if(aux -> left != NULL){
			push(pilha, aux -> left);
		}
	}
	cout << endl;
}

void OrdemArvorePilhaMatando(NoArvore *raizExterna){
	No *pilha = new No;
	NoArvore *raiz = raizExterna;
	pilha = NULL;
	push(pilha, raiz);
	while(pilha!=NULL){
		NoArvore *aux = pilha -> data;
		if(aux -> left != NULL){
			push(pilha, aux -> left);
		}else{
			cout << aux -> data << " ";
			pop(pilha);
			NoArvore *deletado = aux;	
			if(pilha != NULL){
				aux = pilha -> data;
				aux -> left = NULL;
			}
			if(deletado -> right != NULL){
				push(pilha, deletado -> right);
			}
		}
	}
	cout << endl;
}

void OrdemArvorePilha(NoArvore *raiz){
	No *pilha = new No;
	pilha = NULL;
	push(pilha, raiz);
	while(pilha != NULL){
		if(pilha->data->left != NULL){
			push(pilha, pilha->data->left);
		} else{
			No *aux = pilha;
			cout << pilha -> data -> data << " ";
			pop(pilha);
			while(aux -> data -> right == NULL && pilha != NULL){
				aux = pilha;
				cout << pilha -> data -> data << " ";
				pop(pilha);
			}
			if(aux -> data -> right != NULL){
				push(pilha, aux -> data ->right);
			}
		}
	}
	cout << endl;
}

void PosOrdemArvorePilha(NoArvore *raiz){
	No *pilha = new No;
	pilha = NULL;
	push(pilha, raiz);
	int count = 0;
	while(pilha!=NULL){
		No *aux = pilha;
		if(aux -> data -> right != NULL){
			push(pilha, aux  -> data -> right);
		}
		if(aux -> data -> left != NULL){
			push(pilha, aux -> data -> left);
		} else if(aux -> data -> right == NULL){
			cout << pilha -> data -> data << " ";
			No *deletado = pilha;
			pop(pilha);
			while(pilha != NULL && (deletado -> data == pilha -> data -> right || pilha -> data -> right == NULL)){
				cout << pilha -> data -> data << " ";
				deletado = pilha;
				pop(pilha);
			}
		}
	}
	cout << endl;
}

void exibirArvorePar(NoArvore *raiz){
	if(raiz == NULL){
		return;
	}
	if(raiz -> data % 2 == 0){
		cout << raiz -> data << " ";
	}
	exibirArvorePar(raiz -> left);
	exibirArvorePar(raiz -> right);
}

void exibirArvoreImpar(NoArvore *raiz){
	if(raiz == NULL){
		return;
	}
	if(raiz -> data % 2 != 0){
		cout << raiz -> data << " ";
	}
	exibirArvoreImpar(raiz -> left);
	exibirArvoreImpar(raiz -> right);
}

void destruirArvore(NoArvore *&raiz){
	if(raiz != NULL){
		destruirArvore( raiz -> left);
		destruirArvore( raiz -> right);
		raiz = NULL;
		delete raiz;
	}
}

int main() {
	NoArvore *raiz = new NoArvore;
	raiz -> data = 2;
	raiz -> left = NULL;
	raiz -> right = NULL;
	
	NoArvore *no1 = new NoArvore;
	no1 -> data = 7;
	no1 -> left = NULL;
	no1 -> right = NULL;
	
	NoArvore *no2 = new NoArvore;
	no2 -> data = 5;
	no2 -> left = NULL;
	no2 -> right = NULL;
	
	NoArvore *no3 = new NoArvore;
	no3 -> data = 2;
	no3 -> left = NULL;
	no3 -> right = NULL;
	
	NoArvore *no4 = new NoArvore;
	no4 -> data = 6;
	no4 -> left = NULL;
	no4 -> right = NULL;
	
	NoArvore *no5 = new NoArvore;
	no5 -> data = 5;
	no5 -> left = NULL;
	no5 -> right = NULL;
	
	NoArvore *no6 = new NoArvore;
	no6 -> data = 11;
	no6 -> left = NULL;
	no6 -> right = NULL;
	
	NoArvore *no7 = new NoArvore;
	no7 -> data = 9;
	no7 -> left = NULL;
	no7 -> right = NULL;
	
	NoArvore *no8 = new NoArvore;
	no8 -> data = 4;
	no8 -> left = NULL;
	no8 -> right = NULL;
	
	raiz -> left = no1;
	raiz -> right = no2;
	no1 -> left = no3;
	no1 -> right = no4;
	no4 -> left = no5;
	no4 -> right = no6;
	no2 -> right = no7;
	no7 -> left = no8;
	
	exibirArvore(raiz);
	cout << endl;
	destruirArvore(raiz);
	exibirArvore(raiz);
	
	raiz = new NoArvore;
	raiz -> data = 2;
	raiz -> left = NULL;
	raiz -> right = NULL;
	
	no1 = new NoArvore;
	no1 -> data = 7;
	no1 -> left = NULL;
	no1 -> right = NULL;
	
	no2 = new NoArvore;
	no2 -> data = 5;
	no2 -> left = NULL;
	no2 -> right = NULL;
	
	no3 = new NoArvore;
	no3 -> data = 2;
	no3 -> left = NULL;
	no3 -> right = NULL;
	
	no4 = new NoArvore;
	no4 -> data = 6;
	no4 -> left = NULL;
	no4 -> right = NULL;
	
	no5 = new NoArvore;
	no5 -> data = 5;
	no5 -> left = NULL;
	no5 -> right = NULL;
	
	no6 = new NoArvore;
	no6 -> data = 11;
	no6 -> left = NULL;
	no6 -> right = NULL;
	
	no7 = new NoArvore;
	no7 -> data = 9;
	no7 -> left = NULL;
	no7 -> right = NULL;
	
	no8 = new NoArvore;
	no8 -> data = 4;
	no8 -> left = NULL;
	no8 -> right = NULL;
	
	raiz -> left = no1;
	raiz -> right = no2;
	no1 -> left = no3;
	no1 -> right = no4;
	no4 -> left = no5;
	no4 -> right = no6;
	no2 -> right = no7;
	no7 -> left = no8;
	
	cout << "Exibir Arvore: ";
	exibirArvore(raiz);
	cout << endl;
	cout << "Exibir Arvore Par: ";
	exibirArvorePar(raiz);
	cout << endl;
	cout << "Exibir Arvore Impar: ";
	exibirArvoreImpar(raiz);
	cout << endl;
	cout << "quantidade de nos: " << contarNoArvore(raiz) << endl;
	cout << "soma dos nos: " << somarNoArvore(raiz) << endl;
	cout << "media dos nos da arvore: " << mediaArvore(raiz) << endl;
	cout << "Exibir Arvore sem recursividade (pre-ordem): ";
	PreOrdemArvorePilha(raiz);
	cout << "Exibir Arvore sem recursividade (ordem): ";
	OrdemArvorePilha(raiz);
	cout << "Exibir Arvore sem recursividade (pos-ordem): ";
	PosOrdemArvorePilha(raiz);
	return 0;
}
