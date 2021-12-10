#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4
typedef struct No No;
typedef struct Nop Nop;
typedef struct Nov Nov;
typedef struct data
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct endereco
{
    char rua[50];
    int numero;
    char cidade[50];
    char estado[50];
} Endereco;

typedef struct cliente
{
    int cpf;
    char nome[35];
    char telefone[15];
    Endereco endc;
    Data datnasc;

} Cliente;
typedef struct produto
{
    int codigo;
    char descricao[50];
    int qtdinestoque;
    float preco_unitario;
} Produto;

typedef struct venda
{
    int codigo;
    int cpf;
    int cod_prod;
    int qtd_comprada;
} Venda;

//Definição do tipo lista
typedef struct lista
{
    No *begin;

} Lista;
//Definição do nó da lista
struct No
{
    No *prev;
    No *next;
    Cliente date;
};
typedef struct listap//lista produto
{
    Nop *begin;

} Listap;
struct Nop
{
    Nop *prev;
    Nop *next;
    Produto date;
};
typedef struct listav//lista venda
{
    Nov *begin;

} Listav;
struct Nov
{
    Nov *prev;
    Nov *next;
    Venda date;
};

//Funções do cliente
Lista *new_lista();// criação de lista
int list_push_ord_c(Lista *li, Cliente al);// inseir ordenado
int list_query_c(Lista *li, int cpf);// procura cliente na lista pelo o CPF
int list_pop_c(Lista *li, int cpf);// remove cliente pelo CPF dele
int list_change_c(Lista *li, int cpf);// altera o cliente pelo CPF
int check_cpf_c(Lista *li, int cpf); // Verifica se existe este CPF na lista
int list_print_cr(Lista *li);// imprime a lista de clientes inversamente
int list_print_c(Lista *li);// imprime a lista de cliente
int list_query_c_n(Lista *li, int cpf);

//Funções de produto
Listap *new_listap();
int list_push_ord_p(Listap *li, Produto al);
int list_change_p(Listap *li, int cod);
int list_print_p(Listap *li);
int check_cod_p(Listap *li, int cod);
int list_query_p(Listap *li, int cod);
int list_pop_p(Listap *li, int cod);
int list_qtd_p(Listap *li, int cod);
int list_decrease_p(Listap *li, int cod ,int valor);
int list_small_p(Listap *li, int valor);
int list_query_p_n(Listap *li, int cod_prod);

//Venda
Listav *new_listav();
int list_push_ord_v(Listav *li, Venda al);
int list_query_v(Listav *li, int cod);
int list_pop_v(Listav *li, int cod);
int check_cod_v(Listav *li, int cod);
int list_print_v(Listav *li);
int list_change_v(Listav *li, int cod, Listap *l2);
int check_c_v(Listav *li, int cod);
int check_p_v(Listav *li, int cod);
int list_up_v(Listav *li, int valor);
int list_big_v(Listav *li,int valor);
