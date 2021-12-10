#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

// Clientes
Lista *new_lista()
{
    Lista *li;
    li = (Lista *)malloc(sizeof(struct lista)); // poderia ser Lista

    if (li != NULL)
        li->begin = NULL;

    return li;
}
int list_push_ord_c(Lista *li, Cliente al)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;
    else
    {
        No *node;
        node = malloc(sizeof(No));
        if (node == NULL)
            return OUT_OF_MEMORY;

        node->date = al;
        if (li->begin == NULL) // Verifica se a algum elemento na lista se nao tiver insere no incio
        {
            li->begin = node;
            li->begin->prev = li->begin->next = NULL;

            return SUCCESS;
        }
        else if (al.cpf <= li->begin->date.cpf) // inserir no inicio
        {
            
            node->prev = NULL;
            node->next = li->begin;
            li->begin->prev = node;
            li->begin = node;

            return SUCCESS;
        }
        No *aux = li->begin;
        while (aux != NULL)
        {

            if (aux->next == NULL) // insere no final
            {
               
                node->next = NULL;
                node->prev = aux;
                aux->next = node;
                
                return SUCCESS;
            }
            else if (al.cpf >= aux->date.cpf && al.cpf < aux->next->date.cpf) // inserie entre 2 valores ordenadamente
            {
               
                node->prev = aux;
                node->next = aux->next;
                aux->next->prev = node;
                aux->next = node;

                return SUCCESS;
            }

            aux = aux->next;
        }
    }
    return ELEM_NOT_FOUND;
}
int list_query_c(Lista *li, int cpf)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    No *aux = li->begin;
    printf("\n\nCliente: \n");
    int flag = 0;
    do
    {
        if (aux->date.cpf == cpf)
        {
            printf("\n-------------------------------\n");
            printf("CPF:%d\n", aux->date.cpf);
            printf("Nome:");
            puts(aux->date.nome);
            printf("Telefone:");
            puts(aux->date.telefone);

            printf("\nEndereco:");
            printf("\n-----------------\n");
            printf("Rua:");
            puts(aux->date.endc.rua);
            printf("Numero: %d\n", aux->date.endc.numero);
            printf("Cidade:");
            puts(aux->date.endc.cidade);
            printf("Estado:");
            puts(aux->date.endc.estado);

            printf("\nData de nascimento: %d/%d/%d\n", aux->date.datnasc.dia, aux->date.datnasc.mes, aux->date.datnasc.ano);

            printf("-------------------------------\n");
            flag++;
        }
        aux = aux->next;
    } while (aux != NULL || flag != 1);
    return SUCCESS;
}
int list_query_c_n(Lista *li, int cpf)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    No *aux = li->begin;
    
    int flag = 0;
    do
    {
        if (aux->date.cpf == cpf)
        {
            printf("\n\nCliente: \n");
            printf("\n-------------------------------\n");
            printf("CPF:%d\n", aux->date.cpf);
            printf("Nome:");
            puts(aux->date.nome);
            printf("-------------------------------\n");
            flag++;
        }
        aux = aux->next;
    } while (aux != NULL || flag != 1);
    return SUCCESS;
}
int list_pop_c(Lista *li, int cpf)
{
    if (li == NULL || li->begin == NULL)
        return INVALID_NULL_POINTER;

    No *aux = li->begin;
    if (aux->date.cpf == cpf) // remover no inicio
    {

        if (aux->next == NULL)
            li->begin = NULL;
        else
            aux->next->prev = NULL;
        li->begin = aux->next;

        free(aux);
        return SUCCESS;
    }
    do
    {
        if (aux->next == NULL && aux->date.cpf == cpf) // remover no final
        {
            aux->prev->next = NULL;
            free(aux);
            return SUCCESS;
        }
        else if (aux->date.cpf == cpf) // remover entre valores
        {
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            free(aux);
            return SUCCESS;
        }
        aux = aux->next;
    } while (aux != NULL);
}
int list_change_c(Lista *li, int cpf)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    No *aux = li->begin;

    int flag = 0, n, numero, alterar;
    char x;
    do
    {
        if (aux->date.cpf == cpf)
        {
            flag++;

            do
            {
                list_query_c(li, cpf);
                printf("\nAlterar:\n1- Nome.\n2- Telefone.\n3- Endereco.\n4- Data de Nascimento\n0- Sair.\nN:");
                scanf("%d", &alterar);
                switch (alterar)
                {
                case 1:
                    setbuf(stdin, NULL);
                    printf("Nome:");
                    gets(aux->date.nome);
                    break;
                case 2:
                    setbuf(stdin, NULL);
                    printf("Telefone:");
                    gets(aux->date.telefone);
                    break;
                case 3:
                    setbuf(stdin, NULL);
                    printf("Rua:");
                    gets(aux->date.endc.rua);

                    printf("Numero:");
                    setbuf(stdin, NULL);
                    scanf("%d", &aux->date.endc.numero);
                    printf("Cidade:");
                    setbuf(stdin, NULL);
                    gets(aux->date.endc.cidade);
                    printf("Estado:");
                    setbuf(stdin, NULL);
                    gets(aux->date.endc.estado);
                    break;
                case 4:
                    printf("Dia:");
                    setbuf(stdin, NULL);
                    scanf("%d", &aux->date.datnasc.dia);
                    printf("Mes:");
                    setbuf(stdin, NULL);
                    scanf("%d", &aux->date.datnasc.mes);
                    printf("Ano:");
                    setbuf(stdin, NULL);
                    scanf("%d", &aux->date.datnasc.ano);
                    break;
                }
            } while (alterar != 0);
        }

        aux = aux->next;
    } while (aux != NULL || flag != 1);

    return SUCCESS;
}
int check_cpf_c(Lista *li, int cpf)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    No *aux = li->begin;
    while (aux != NULL)
    {
        if (aux->date.cpf == cpf)
            return SUCCESS;
        aux = aux->next;
    }
    return ELEM_NOT_FOUND;
}
int list_print_cr(Lista *li)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    No *aux = li->begin;
    while (aux->next != NULL)
        aux = aux->next;

    printf("\n\nLista Reversa: \n");
    do
    {
        puts(aux->date.nome);
        printf("CPF:%d\n", aux->date.cpf);
        printf("-------------------------------\n");
        aux = aux->prev;
    } while (aux != NULL);
    return SUCCESS;
}
int list_print_c(Lista *li)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    No *aux = li->begin;
    printf("\n\nLISTA DE CLIENTES: \n");

    while (aux != NULL)
    {
        printf("\n-------------------------------\n");
        printf("CPF:%d\n", aux->date.cpf);
        printf("Nome:");
        puts(aux->date.nome);
        printf("Telefone:");
        puts(aux->date.telefone);

        printf("\nEndereco:");
        printf("\n-----------------\n");
        printf("Rua:");
        puts(aux->date.endc.rua);
        printf("Numero: %d\n", aux->date.endc.numero);
        printf("Cidade:");
        puts(aux->date.endc.cidade);
        printf("Estado:");
        puts(aux->date.endc.estado);

        printf("\nData de nascimento: %d/%d/%d\n", aux->date.datnasc.dia, aux->date.datnasc.mes, aux->date.datnasc.ano);

        printf("-------------------------------\n");
        aux = aux->next;
    }
    return SUCCESS;
}
//Produto

Listap *new_listap()
{
    Listap *li;
    li = (Listap *)malloc(sizeof(struct listap)); // poderia ser Lista

    if (li != NULL)
        li->begin = NULL;

    return li;
}
int list_push_ord_p(Listap *li, Produto al)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;
    else
    {
        Nop *node;
        node = malloc(sizeof(Nop));
        if (node == NULL)
            return OUT_OF_MEMORY;

        node->date = al;
        if (li->begin == NULL) // Verifica se a algum elemento na lista se nao tiver insere no incio
        {
            li->begin = node;
            li->begin->prev = li->begin->next = NULL;

            return SUCCESS;
        }
        else if (al.codigo <= li->begin->date.codigo) // inserir no inicio
        {

            node->prev = NULL;
            node->next = li->begin;
            li->begin->prev = node;
            li->begin = node;

            return SUCCESS;
        }
        Nop *aux = li->begin;
        while (aux != NULL)
        {

            if (aux->next == NULL) // insere no final
            {
                
                node->next = NULL;
                node->prev = aux;
                aux->next = node;
                
                return SUCCESS;
            }
            else if (al.codigo >= aux->date.codigo && al.codigo < aux->next->date.codigo) // inserie entre 2 valores ordenadamente
            {
                
                node->prev = aux;
                node->next = aux->next;
                aux->next->prev = node;
                aux->next = node;

                return SUCCESS;
            }

            aux = aux->next;
        }
    }
    return ELEM_NOT_FOUND;
}
int list_change_p(Listap *li, int cod)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nop *aux = li->begin;

    int flag = 0, n, numero, alterar;
    char x;
    do
    {
        if (aux->date.codigo == cod)
        {
            flag++;

            do
            {
                list_query_p(li, cod);
                setbuf(stdin, NULL);
                printf("Alterar:\n1- Descricao.\n2- Quantidade em estoque.\n3- Preco unitario.\n0- Sair.\nN:");
                scanf("%d", &alterar);
                switch (alterar)
                {
                case 1:
                    setbuf(stdin, NULL);
                    printf("\nDigite uma nova descricao:");
                    gets(aux->date.descricao);
                    break;
                case 2:
                    setbuf(stdin, NULL);
                    printf("Digite uma nova quantidade:");
                    scanf("%d", &aux->date.qtdinestoque);
                    break;
                case 3:
                    setbuf(stdin, NULL);
                    printf("Digite um novo preco:");
                    scanf("%f", &aux->date.preco_unitario);
                    break;
                }
            } while (alterar != 0);
        }
        aux = aux->next;

    } while (aux != NULL || flag != 1);

    return SUCCESS;
}
int check_cod_p(Listap *li, int cod)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nop *aux = li->begin;
    while (aux != NULL)
    {
        if (aux->date.codigo == cod)
            return SUCCESS;
        aux = aux->next;
    }
    return ELEM_NOT_FOUND;
}
int list_query_p(Listap *li, int cod)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nop *aux = li->begin;
    printf("\n\nProduto: \n");
    int flag = 0;
    do
    {
        if (aux->date.codigo == cod)
        {

            printf("-------------------------------\n");
            printf("Cod:%d\n", aux->date.codigo);
            printf("Descricao: ");
            puts(aux->date.descricao);
            printf("Quantidade em estoque: %d\n", aux->date.qtdinestoque);
            printf("Preco: %.2f\n", aux->date.preco_unitario);
            printf("-------------------------------\n");
            flag++;
        }
        aux = aux->next;
    } while (aux != NULL || flag != 1);
    return SUCCESS;
}
int list_pop_p(Listap *li, int cod)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nop *aux = li->begin;
    if (aux->date.codigo == cod) // remover no inicio
    {
        if (aux->next == NULL)
            li->begin = NULL;
        else
            aux->next->prev = NULL;
        li->begin = aux->next;

        free(aux);
        return SUCCESS;
    }
    do
    {
        if (aux->next == NULL && aux->date.codigo == cod) // remover no final
        {
            aux->prev->next = NULL;
            free(aux);
            return SUCCESS;
        }
        else if (aux->date.codigo == cod) // remover entre valores
        {
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            free(aux);
            return SUCCESS;
        }
        aux = aux->next;
    } while (aux != NULL);
}
int list_print_p(Listap *li)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nop *aux = li->begin;
    printf("\n\nLISTA DE PRODUTOS: \n");
    while (aux != NULL)
    {
        printf("-------------------------------\n");
        printf("Cod:%d\n", aux->date.codigo);
        printf("Descricao: ");
        puts(aux->date.descricao);
        printf("Quantidade em estoque: %d\n", aux->date.qtdinestoque);
        printf("Preco: %.2f\n", aux->date.preco_unitario);
        printf("-------------------------------\n");
        aux = aux->next;
    }
    return SUCCESS;
}
int list_qtd_p(Listap *li, int cod)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nop *aux = li->begin;
    while (aux != NULL)
    {
        if (aux->date.codigo == cod)
            return aux->date.qtdinestoque;
        aux = aux->next;
    }
    return ELEM_NOT_FOUND;
}
int list_decrease_p(Listap *li, int cod, int valor)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nop *aux = li->begin;
    while (aux != NULL)
    {
        if (aux->date.codigo == cod)
        {
            aux->date.qtdinestoque -= valor;
            return SUCCESS;
        }
        aux = aux->next;
    }
    return ELEM_NOT_FOUND;
}
int list_small_p(Listap *li, int valor)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nop *aux = li->begin;
    printf("\n\nLISTA DE PRODUTOS ACIMA DE UM VALOR DETERMINADO %d: \n",valor);
    while (aux != NULL)
    {
        if ( aux->date.qtdinestoque < valor )
        {
            printf("-------------------------------\n");
            printf("Cod:%d\n", aux->date.codigo);
            printf("Descricao: ");
            puts(aux->date.descricao);
            printf("Quantidade em estoque: %d\n", aux->date.qtdinestoque);
            printf("Preco: %.2f\n", aux->date.preco_unitario);
            printf("-------------------------------\n");
        }
        aux = aux->next;
    }
    return SUCCESS;
}
int list_query_p_n(Listap *li, int cod_prod)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nop *aux = li->begin;
   
    int flag = 0;
    do
    {
        if (aux->date.codigo == cod_prod)
        {
            printf("\n\nProduto: \n");
            printf("\n-------------------------------\n");
            printf("Codigo:%d\n", aux->date.codigo);
            printf("Descricao:");
            puts(aux->date.descricao);
            printf("Quantidade:%d\n", aux->date.qtdinestoque);
            printf("-------------------------------\n");
            flag++;
        }
        aux = aux->next;
    } while (aux != NULL || flag != 1);
    return SUCCESS;
}

//Venda
Listav *new_listav()
{
    Listav *li;
    li = (Listav *)malloc(sizeof(struct listav)); // poderia ser Lista

    if (li != NULL)
        li->begin = NULL;

    return li;
}
int list_push_ord_v(Listav *li, Venda al)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;
    else
    {
        Nov *node;
        node = malloc(sizeof(Nov));
        if (node == NULL)
            return OUT_OF_MEMORY;

        node->date = al;
        if (li->begin == NULL) // Verifica se a algum elemento na lista se nao tiver insere no incio
        {
            li->begin = node;
            li->begin->prev = li->begin->next = NULL;

            return SUCCESS;
        }
        else if (al.codigo <= li->begin->date.codigo) // inserir no inicio
        {

            node->prev = NULL;
            node->next = li->begin;
            li->begin->prev = node;
            li->begin = node;

            return SUCCESS;
        }
        Nov *aux = li->begin;
        while (aux != NULL)
        {

            if (aux->next == NULL) // insere no final
            {
                
                node->next = NULL;
                node->prev = aux;
                aux->next = node;
                
                return SUCCESS;
            }
            else if (al.codigo >= aux->date.codigo && al.codigo < aux->next->date.codigo) // inserie entre 2 valores ordenadamente
            {
                
                node->prev = aux;
                node->next = aux->next;
                aux->next->prev = node;
                aux->next = node;

                return SUCCESS;
            }

            aux = aux->next;
        }
    }
    return ELEM_NOT_FOUND;
}
int check_cod_v(Listav *li, int cod)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nov *aux = li->begin;
    while (aux != NULL)
    {
        if (aux->date.codigo == cod)
            return SUCCESS;
        aux = aux->next;
    }
    return ELEM_NOT_FOUND;
}
int list_pop_v(Listav *li, int cod)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nov *aux = li->begin;
    if (aux->date.codigo == cod) // remover no inicio
    {
        if (aux->next == NULL)
            li->begin = NULL;
        else
            aux->next->prev = NULL;
        li->begin = aux->next;

        free(aux);
        return SUCCESS;
    }
    do
    {
        if (aux->next == NULL && aux->date.codigo == cod) // remover no final
        {
            aux->prev->next = NULL;
            free(aux);
            return SUCCESS;
        }
        else if (aux->date.codigo == cod) // remover entre valores
        {
            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;
            free(aux);
            return SUCCESS;
        }
        aux = aux->next;
    } while (aux != NULL);
}
int list_query_v(Listav *li, int cod)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nov *aux = li->begin;
    printf("\n\nLista: \n");
    int flag = 0;
    do
    {
        if (aux->date.codigo == cod)
        {

            printf("Cod da venda:%d\n", aux->date.codigo);
            printf("CPF do cliente: %d\n", aux->date.cpf);
            printf("Cod do produto: %d\n", aux->date.cod_prod);
            printf("Quantidade do produto: %d\n", aux->date.qtd_comprada);
            printf("-------------------------------\n");
            flag++;
        }
        aux = aux->next;
    } while (aux != NULL || flag != 1);
    return SUCCESS;
}
int list_change_v(Listav *li, int cod, Listap *l2)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nov *aux = li->begin;
    Nop *aux2 = l2->begin;

    int flag = 0, n, numero, alterar, valor;
    char x;
    do
    {
        if (aux->date.codigo == cod)
        {
            flag++;

            do
            {
                list_query_v(li, cod);
                setbuf(stdin, NULL);
                printf("Alterar:\n1- Quantidade comprada.\n0- Sair.\nN:");
                scanf("%d", &alterar);
                switch (alterar)
                {
                case 1:

                    while (aux2 != NULL && aux2->date.codigo != aux->date.cod_prod)
                        aux2 = aux2->next;

                    aux2->date.qtdinestoque += aux->date.qtd_comprada;
                    int flag = 1;
                    do
                    {

                        printf("Produto: %d", aux2->date.codigo);
                        setbuf(stdin, NULL);
                        printf("\nDigite a quantidade a ser comprada:");
                        scanf("%d", &valor);
                        if ((aux2->date.qtdinestoque - valor) >= 0) ///precisa de um do aqui para voltar caso o usuario errar a entrada
                        {
                            flag = 0;
                            aux->date.qtd_comprada = valor;
                            list_decrease_p(l2, aux2->date.codigo, valor);
                        }
                        else
                            printf("Valor inferior!Valor do estoque eh %d.\n", aux2->date.qtdinestoque);

                    } while (flag != 0);
                    break;
                }
            } while (alterar != 0);
        }
        aux = aux->next;

    } while (aux != NULL || flag != 1);

    return SUCCESS;
}
int check_c_v(Listav *li, int cod)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nov *aux = li->begin;
    while (aux != NULL)
    {
        if (aux->date.cpf == cod)
            return SUCCESS;
        aux = aux->next;
    }
    return ELEM_NOT_FOUND;
}
int check_p_v(Listav *li, int cod)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nov *aux = li->begin;
    while (aux != NULL)
    {
        if (aux->date.cod_prod == cod)
            return SUCCESS;
        aux = aux->next;
    }
    return ELEM_NOT_FOUND;
}
int list_print_v(Listav *li)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nov *aux = li->begin;
    printf("\n\nLista: \n");
    while (aux != NULL)
    {
        printf("Cod da venda:%d\n", aux->date.codigo);
        printf("CPF do cliente: %d\n", aux->date.cpf);

        printf("Cod do produto: %d\n", aux->date.cod_prod);
        printf("Quantidade do produto: %d\n", aux->date.qtd_comprada);
        printf("-------------------------------\n");
        aux = aux->next;
    }
    return SUCCESS;
}
int list_up_v(Listav *li, int valor)
{
    int i = 0;
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nov *aux = li->begin;
    while (aux != NULL)
    {
        if (aux->date.qtd_comprada > valor)
            i++;
        aux = aux->next;
    }
    return i;
}
int list_big_v(Listav *li,int valor)
{
    if (li == NULL)
        return INVALID_NULL_POINTER;

    Nov *aux = li->begin;
    printf("\n\nLISTA DE COMPRA ACIMA DE UM VALOR DETERMINADO %d: \n",valor);
    while (aux != NULL)
    {
        if ( aux->date.qtd_comprada > valor)
        {
            printf("Cod da venda:%d\n", aux->date.codigo);
            printf("CPF do cliente: %d\n", aux->date.cpf);
            printf("Cod do produto: %d\n", aux->date.cod_prod);
            printf("Quantidade do produto: %d\n", aux->date.qtd_comprada);
            printf("-------------------------------\n");
        }
        aux = aux->next;
    }
    return SUCCESS;
}
