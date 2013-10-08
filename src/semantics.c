/**
 * @file semantics.c
 * @author Arthur Foscarini, Fernando Soller Mecking; Mateus Cardoso da Silva
 * @date 03 Oct 2013
 * @brief Arquivo contendo as funções para avaliação semântica
 */

#include "semantics.h"


int semanticEvaluation(comp_tree* ast){
	int result = IKS_SUCCESS;
	//inserir verificacao das declaracoes
	result = verifyIdentifier(ast); //uso correto de identificadores
	//inserir tipos e tamanho de dados
	//inserir coercao de tipos
	//inserir argumentos e parametros
	//inserir verificacao de tipos em comandos
	return result;
}



/**
 * Funcao de verificacao do uso correto dos identificadores,
 * eh necessario que ja tenha ocorrida a verificacao de suas declaracoes
 * e de escopo
 */
int verifyIdentifier(comp_tree* ast){
	if(ast==NULL)
		return IKS_SUCCESS;
	comp_tree* aux = ast;
	nodeList* auxList;
	int result = IKS_SUCCESS;
	while(aux != NULL){
		auxList = aux->sonList;
		//processing current node
		if(aux->type == IKS_AST_VETOR_INDEXADO){
			if(auxList->node->symbol->usage != ID_VETOR)
				return IKS_ERROR_VECTOR;
		}
		else if(aux->type == IKS_AST_CHAMADA_DE_FUNCAO){
			if(auxList->node->symbol->usage != ID_FUNCAO)
				return IKS_ERROR_FUNCTION;
		}
		else if(aux->father != NULL 
							&& aux->type == IKS_AST_IDENTIFICADOR 
							&& aux->father->type != IKS_AST_VETOR_INDEXADO
							&& aux->father->type != IKS_AST_CHAMADA_DE_FUNCAO){
			if(aux->symbol->usage != ID_VARIAVEL)
				return IKS_ERROR_VARIABLE;
		}
		//processing all sons
		while(auxList!=NULL){
			if(auxList->node!=NULL){
				result = verifyIdentifier(auxList->node);
				if(result != IKS_SUCCESS)
					return result;
			}
			auxList = auxList->next;
		}
		
		//go to next brother
		aux = aux->broList;
	}
	return IKS_SUCCESS;
}

/**
 * Funcao de verificacao do uso correto dos parametros nas chamadas de funcao
 */
int verifyArguments(comp_tree*){
	if(ast==NULL)
		return IKS_SUCCESS;
	comp_tree* aux = ast;
	nodeList* auxList;
	int result = IKS_SUCCESS;
	while(aux != NULL){
		auxList = aux->sonList;
		//processing current node
		if(aux->type == IKS_AST_FUNCAO)
			currentFunction = aux;
		if(aux->type == IKS_AST_CHAMADA_DE_FUNCAO){
			
		
		}
		
		//processing all sons
		while(auxList!=NULL){
			if(auxList->node!=NULL){
				result = verifyArguments(auxList->node);
				if(result != IKS_SUCCESS)
					return result;
			}
			auxList = auxList->next;
		}
		
		//go to next brother
		aux = aux->broList;
	}
	return IKS_SUCCESS;	
}
