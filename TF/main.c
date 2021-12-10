#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

int main()
{
    int opcao, opcao_c, x, c, z, teste_cpv, valor;
    Lista *cliente;
    cliente = new_lista();
    Cliente pesssoa;

    Listap *produto;
    produto = new_listap();
    Produto item;

    Listav *venda;
    venda = new_listav();
    Venda compra;

    printf("\nGerencia de clientes e produtos.\n");
    printf("--------------------------------\n\n");

    do
    {
        printf("Para gerenciar, insira o numero correspondente.\n");
        setbuf(stdin, NULL);
        printf("1- Clientes.\n2- Produtos.\n3- Venda.\n4- Mostragens\n0- Sair.\nN:");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            do
            {
                setbuf(stdin, NULL);
                printf("\nClientes:\n1- Inserir.\n2- Alterar.\n3- Consulta.\n4- Remover.\n5- Lista de Clientes.\n0- Sair.\nN:");
                scanf("%d", &opcao_c);
                switch (opcao_c)
                {
                case 1:
                    do
                    {
                        setbuf(stdin, NULL);
                        printf("\nCPF do Cliente:");
                        scanf("%d", &pesssoa.cpf);
                        x = check_cpf_c(cliente, pesssoa.cpf);
                        if (x == SUCCESS)
                            printf("Digite um CPF que nao exista no banco de dados ou digite -1 para voltar!!!\n\n");

                    } while (x != ELEM_NOT_FOUND && pesssoa.cpf != -1);
                    if (pesssoa.cpf != -1)
                    {
                        printf("Nome do Cliente:");
                        setbuf(stdin, NULL);
                        gets(pesssoa.nome);
                        printf("Telefone do Cliente:");
                        setbuf(stdin, NULL);
                        gets(pesssoa.telefone);

                        printf("\nEndereco:\n");
                        printf("-----------------\n");
                        printf("Rua:");
                        setbuf(stdin, NULL);
                        gets(pesssoa.endc.rua);

                        printf("Numero:");
                        setbuf(stdin, NULL);
                        scanf("%d", &pesssoa.endc.numero);
                        printf("Cidade:");
                        setbuf(stdin, NULL);
                        gets(pesssoa.endc.cidade);
                        printf("Estado:");
                        setbuf(stdin, NULL);
                        gets(pesssoa.endc.estado);

                        printf("\nData de nascimento:\n");
                        printf("-----------------\n");
                        printf("Dia:");
                        setbuf(stdin, NULL);
                        scanf("%d", &pesssoa.datnasc.dia);
                        printf("Mes:");
                        setbuf(stdin, NULL);
                        scanf("%d", &pesssoa.datnasc.mes);
                        printf("Ano:");
                        setbuf(stdin, NULL);
                        scanf("%d", &pesssoa.datnasc.ano);
                        list_push_ord_c(cliente, pesssoa);
                    }

                    break;
                case 2:

                    do
                    {
                        setbuf(stdin, NULL);
                        printf("\nDigite o cpf para altear dados do cliente.\n");
                        scanf("%d", &teste_cpv);
                        x = check_cpf_c(cliente, teste_cpv);
                        if (x == ELEM_NOT_FOUND)
                            printf("Digite um CPF que exista no banco de dados ou digite -1 para voltar!!!\n\n");

                    } while (x != SUCCESS && teste_cpv != -1);
                    if (teste_cpv != -1)
                        list_change_c(cliente, teste_cpv);

                    break;
                case 3:

                    do
                    {
                        setbuf(stdin, NULL);
                        printf("\nDigite o cpf para consultar.\n");
                        scanf("%d", &teste_cpv);
                        x = check_cpf_c(cliente, teste_cpv);
                        if (x == ELEM_NOT_FOUND)
                            printf("Digite um CPF que exista no banco de dados ou digite -1 para voltar!!!\n\n");

                    } while (x != SUCCESS && teste_cpv != -1);
                    if (teste_cpv != -1)
                        list_query_c(cliente, teste_cpv);

                    break;
                case 4:

                    do
                    {
                        setbuf(stdin, NULL);
                        printf("\nDigite o cpf para deletar.\n");
                        scanf("%d", &teste_cpv);
                        x = check_cpf_c(cliente, teste_cpv);
                        if (x == ELEM_NOT_FOUND)
                            printf("Digite um CPF que exista no banco de dados ou digite -1 para voltar!!!\n\n");
                        z = check_c_v(venda, teste_cpv);
                        if (z == SUCCESS)
                            printf("O cliente ainda tem uma compra na rede, delete a primeiro; -1 para cancelar\n");
                        x += z;
                    } while (x != ELEM_NOT_FOUND && teste_cpv != -1);
                    if (teste_cpv != -1)
                        list_pop_c(cliente, teste_cpv);

                    break;
                case 5:
                    list_print_c(cliente);
                    break;
                }

            } while (opcao_c != 0);

            break;
        //fim Cliente
        case 2:
            do
            {

                setbuf(stdin, NULL);
                printf("\nProduto:\n1- Inserir.\n2- Alterar.\n3- Consulta.\n4- Remover.\n5- Lista de Produtos.\n0- Sair.\nN:");
                scanf("%d", &opcao_c);
                switch (opcao_c)
                {
                case 1:
                    printf("\n--------------------------\n");
                    do
                    {
                        setbuf(stdin, NULL);
                        printf("\nCodigo do produto:");
                        scanf("%d", &item.codigo);
                        x = check_cod_p(produto, item.codigo);
                        if (x == SUCCESS)
                            printf("Digite um CODIGO que nao exista no banco de dados ou digite -1 para voltar!!!\n\n");

                    } while (x != ELEM_NOT_FOUND && item.codigo != -1);
                    if (item.codigo != -1)
                    {
                        printf("Descricao produto:");
                        setbuf(stdin, NULL);
                        gets(item.descricao);

                        printf("Quantidade em Estoque:");
                        setbuf(stdin, NULL);
                        scanf("%d", &item.qtdinestoque);
                        printf("Preco unitario:");
                        setbuf(stdin, NULL);
                        scanf("%f", &item.preco_unitario);
                        list_push_ord_p(produto, item);
                    }
                    printf("\n--------------------------\n");
                    break;
                case 2:

                    do
                    {
                        setbuf(stdin, NULL);
                        printf("\nDigite o codigo para altear dados do produto.\n");
                        scanf("%d", &teste_cpv);
                        x = check_cod_p(produto, teste_cpv);
                        if (x == ELEM_NOT_FOUND)
                            printf("Digite um CODIGO que nao exista no banco de dados ou digite -1 para voltar!!!\n\n");

                    } while (x != SUCCESS && teste_cpv != -1);
                    if (teste_cpv != -1)
                        list_change_p(produto, teste_cpv);

                    break;
                case 3:

                    do
                    {
                        setbuf(stdin, NULL);
                        printf("\nDigite o codigo para consultar.\n");
                        scanf("%d", &teste_cpv);
                        x = check_cod_p(produto, teste_cpv);
                        if (x == ELEM_NOT_FOUND)
                            printf("Digite um CODIGO que nao exista no banco de dados ou digite -1 para voltar!!!\n\n");

                    } while (x != SUCCESS && teste_cpv != -1);
                    if (teste_cpv != -1)
                        list_query_p(produto, teste_cpv);

                    break;
                case 4:
                    
                    do
                    {
                        setbuf(stdin, NULL);
                        printf("\nDigite o codigo para consultar.\n");
                        scanf("%d", &teste_cpv);
                        x = check_cod_p(produto, teste_cpv);
                        if (x == ELEM_NOT_FOUND)
                            printf("Digite um CODIGO que nao exista no banco de dados ou digite -1 para voltar!!!\n\n");
                        z = check_p_v(venda, teste_cpv);
                        if (z == SUCCESS)
                            printf("O produto esta em uma compra na rede, delete a primeiro; -1 para cancelar\n");
                        x += z;
                    } while (x != ELEM_NOT_FOUND && teste_cpv != -1);
                    if (teste_cpv != -1)
                        list_pop_p(produto, teste_cpv);

                    break;
                case 5:
                    list_print_p(produto);
                    break;
                }

            } while (opcao_c != 0);
            break;
            //fim produto
        //Começo Venda
        case 3:
            do
            {

                setbuf(stdin, NULL);
                printf("\nVenda:\n1- Inserir.\n2- Alterar.\n3- Consulta.\n4- Remover.\n5- Lista de Vendas.\n0- Sair.\nN:");
                scanf("%d", &opcao_c);
                switch (opcao_c)
                {
                case 1:

                    do
                    {
                        printf("\n-----------------------------------\n");
                        setbuf(stdin, NULL);
                        printf("\nCodigo da venda:");
                        scanf("%d", &compra.codigo);
                        x = check_cod_v(venda, compra.codigo);
                        if (x == SUCCESS)
                            printf("Digite um CODIGO que não exista no banco de dados!!!\n\n");

                        setbuf(stdin, NULL);
                        printf("\nCPF do Cliente:");
                        scanf("%d", &compra.cpf);
                        
                        c = check_cpf_c(cliente, compra.cpf);
                        if (c == ELEM_NOT_FOUND)
                            printf("Digite um CPF que exista no banco de dados !!!\n\n");
                        else
                            list_query_c_n(cliente,compra.cpf);

                        setbuf(stdin, NULL);
                        printf("\nCodigo da produto:");
                        scanf("%d", &compra.cod_prod);
                        z = check_cod_p(produto, compra.cod_prod);
                        if (z == ELEM_NOT_FOUND)
                            printf("Digite um CODIGO que  exista no banco de dados!!!\n\n");
                        else
                            list_query_p_n(produto,compra.cod_prod);

                        if (x == SUCCESS || c == ELEM_NOT_FOUND || z == ELEM_NOT_FOUND)
                        {
                            setbuf(stdin, NULL);
                            printf("Digite  -1 para sair!!!\nPara continuar digite 0!!!\n");
                            scanf("%d", &x);
                            if (x == -1)
                                break;
                        }

                    } while (x != ELEM_NOT_FOUND || c != SUCCESS || z != SUCCESS);
                    if (x != -1)
                    {
                        do
                        {
                            printf("\n-----------------------------------\n");
                            printf("\nQuantidade comprada:");
                            setbuf(stdin, NULL);
                            scanf("%d", &valor);
                            x = list_qtd_p(produto, compra.cod_prod);

                            if (x >= 0 && ((x - valor) >= 0))
                            {

                                compra.qtd_comprada = valor;
                                list_decrease_p(produto, compra.cod_prod, valor);
                                list_push_ord_v(venda, compra);
                            }
                            else if (x >= 0)
                            {
                                printf("\nO valor para compra nao eh permitido!!!\nPara cancelar digite -1 !!!\n");
                                printf("\nQuantidade no estoque: %d", x);
                            }

                        } while (valor != -1 && (x - valor) < 0);
                    }
                    printf("\n--------------------------\n");
                    break;
                case 2:

                    do
                    {
                        setbuf(stdin, NULL);
                        printf("\nDigite o codigo para altear dados do venda.\n");
                        scanf("%d", &teste_cpv);
                        x = check_cod_v(venda, teste_cpv);
                        if (x == ELEM_NOT_FOUND)
                            printf("Digite um CODIGO que nao exista no banco de dados ou digite -1 para voltar!!!\n\n");

                    } while (x != SUCCESS && teste_cpv != -1);
                    if (teste_cpv != -1)
                        list_change_v(venda, teste_cpv, produto);

                    break;
                case 3:

                    do
                    {
                        setbuf(stdin, NULL);
                        printf("\nDigite o codigo para consultar.\n");
                        scanf("%d", &teste_cpv);
                        x = check_cod_v(venda, teste_cpv);
                        if (x == ELEM_NOT_FOUND)
                            printf("Digite um CODIGO que nao exista no banco de dados ou digite -1 para voltar!!!\n\n");

                    } while (x != SUCCESS && teste_cpv != -1);
                    if (teste_cpv != -1)
                        list_query_v(venda, teste_cpv);

                    break;
                case 4:
                    
                    do
                    {
                        setbuf(stdin, NULL);
                        printf("\nDigite o codigo para consultar.\n");
                        scanf("%d", &teste_cpv);
                        x = check_cod_v(venda, teste_cpv);
                        if (x == ELEM_NOT_FOUND)
                            printf("Digite um CODIGO que nao exista no banco de dados ou digite -1 para voltar!!!\n\n");

                    } while (x != SUCCESS && teste_cpv != -1);
                    if (teste_cpv != -1)
                        list_pop_v(venda, teste_cpv);

                    break;
                case 5:
                    list_print_v(venda);
                    break;
                }

            } while (opcao_c != 0);
            break;
        //Fim venda
        //Começo mostragens
        case 4:
            
            do
            {
                setbuf(stdin, NULL);
                printf("\nMostragens:\n1- Todos os Clientes.\n2- Todos os Produtos.\n3- Todas as Vendas.\n4- Compras com a quantidade acima fornecida.\n5- Produtos que estao com a quantidade abaixo do valor informado.\n0- Sair.\nN:");
                scanf("%d", &opcao_c);
                switch (opcao_c)
                {
                case 1:
                    list_print_c(cliente);
                    break;
                case 2:
                    list_print_p(produto);
                    break;
                case 3:
                    list_print_v(venda);
                    break;
                case 4:
                    printf("\nDigite o valor para analise:"); 
                    scanf("%d", &valor);
                    list_big_v(venda,valor);
                    break;
                case 5:
                    printf("\nDigite o valor para analise:");
                    scanf("%d", &valor);
                    list_small_p(produto, valor);

                    break;
                }
            } while (opcao_c != 0);
            break;
            //fim mostragens
        }
        
    } while (opcao != 0);
}