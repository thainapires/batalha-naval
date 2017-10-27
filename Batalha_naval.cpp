#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include<conio.h>
using namespace std;

int menu();
void jogar();
void atacar();
void instrucoes();
void imprime_header();
void informacoes_grupo();
void criarmapa(char mapa[5][5], char mapa2[10][10]);
void imprime_mapa(char mapa[5][5], char mapa2[10][10]);
void posicionar_barco_de_1(char mapa[5][5], char mapa2[10][10], string jogador, int i);
void posicionar_barco_de_2(char mapa[5][5], char mapa2[10][10], string jogador, int i);
char mapa_curto_jogador_1[5][5], mapa_curto_jogador_2[5][5], mapa_longo_jogador_1[10][10], mapa_longo_jogador_2[10][10];
char mapa_atacar_1_curto[5][5], mapa_atacar_2_curto[5][5], mapa_atacar_1_longo[10][10], mapa_atacar_2_longo[10][10];
string jogador1, jogador2;
bool ataque;
int tamanho = 0;

int main(void){
    setlocale(LC_ALL, "Portuguese");
    system("mode con:cols=80 lines=26");
	int op;
	imprime_header();
	do{
        op = menu();
        switch (op){
            case 1: jogar();
            break;
            case 2: instrucoes();
            break;
            case 3: informacoes_grupo();
            break;
            case 4: return 0;
            break;
        }
	} while (op != 4);
}

int menu(){
    bool num;
    int opc = 0;
    char o;
    string opcao;
    do{
        imprime_header();
        cout<< "\n \t\t\t    __________________________\n";
        cout<< "\n \t\t\t     1: Jogar                 ";
        cout<< "\n \t\t\t     2: Instruções            ";
        cout<< "\n \t\t\t     3: Informações do grupo  ";
        cout<< "\n \t\t\t     4: Sair                  ";
        cout<< "\n \t\t\t    __________________________\n";
        cout<< "\n \t\t\t     Digite a opcão: ";
        cin>> opcao;
        if(opcao.size() == 1){
            o = opcao[0];
            if(isdigit(o)){
                num = true;
                opc = o - 48;
        }
        if(isalpha(o)){
            num = false;
        }
        }
        else{
            num = false;
        }
    }while(num == false);
    return opc;
}

void instrucoes(){
    imprime_header();
     cout<<"\t\t\t\t  Instruções\n\n";
    cout<<"    1)Este é um jogo para ser jogado por dois jogadores\n\n";
    cout<<"    2)(Curto->X Barcos | Tabuleiro 5x5) / (Longo-> X Barcos | Tabuleiro 10x10).\n\n";
    cout<<"    3)Para posicionar o barco, o jogador deve escolher em qual linha e coluna\n";
    cout<<"    ,para barcos que tenham mais de uma posicao, deverá ser escolhido se quer\n";
    cout<<"    posicionar na vertical ou horizontal e logo após escolher qual opção entre\n";
    cout<<"    as disponiveis, deseja posicionar.\n\n";
    cout<<"    4) Na hora de atacar, o jogador que acertar, deverá jogar novamente, caso\n";
    cout<<"    contrario, é a vez de seu oponente jogar.\n\n";
    cout<<"    5) Ganha quem conseguir acertar todos os barcos primeiro\n\n";
    cout<<"                 <APERTE QUALQUER TECLA PARA VOLTAR AO MENU> ";
    fflush(stdin);
    getch();
}

void informacoes_grupo(){
    imprime_header();
    cout<<"\t\t\t     Nome dos integrantes: \n\n";
    cout<<"\t\t\t\tThainá Simões \n\t\t\t\tLucas Leite \n\t\t\t\tDavid Uribe \n\t\t\t\tCaroline Ferreira \n\t\t\t\tRaphael Souza \n\t\t\t\tDenis Crispe \n\t\t\t\tMatheus Mencalha \n\n";
    cout<<"                 <APERTE QUALQUER TECLA PARA VOLTAR AO MENU> ";
    fflush(stdin);
    getch();
}

void jogar(){
    char curto_ou_longo;
    bool c_ou_l = false;
    system("color f0");
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tNome";
    Sleep(10*10);
    cout<<" do";
    Sleep(10*10);
    cout<<" jogador 1: ";
    cin>>jogador1;
    system("cls");
    system("color f");
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tNome";
    Sleep(10*10);
    cout<<" do";
    Sleep(10*10);
    cout<<" jogador 2: ";
    cin>>jogador2;
    system("cls");
    system("color 1f");
    do{
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t     O jogo sera curto ou longo? (c/l): ";
        cin>>curto_ou_longo;
        if(tolower(curto_ou_longo) == 'c' || tolower(curto_ou_longo) == 'l' ){
            c_ou_l = true;
            if(tolower(curto_ou_longo) == 'c'){
                tamanho = 5;
            }
            if(tolower(curto_ou_longo) == 'l'){
                tamanho = 10;
            }
            criarmapa(mapa_curto_jogador_1, mapa_longo_jogador_1);
            criarmapa(mapa_curto_jogador_2, mapa_longo_jogador_2);
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\tVez de "<<jogador1<<" posicionar seus barcos!";
            cout<<"\t\t\t\t\t APERTE QUALQUER TECLA PARA POSICIONAR SEUS BARCOS ";
            fflush(stdin);
            getch();
            system("cls");
            if(tamanho == 5){
                posicionar_barco_de_1(mapa_curto_jogador_1, mapa_longo_jogador_1, jogador1,1);
                for(int i = 1; i < 4; i++){
                    posicionar_barco_de_2(mapa_curto_jogador_1, mapa_longo_jogador_1, jogador1, i);
                }
            }
            if(tamanho == 10){
                for(int i = 1; i < 3; i++){
                    posicionar_barco_de_1(mapa_curto_jogador_1, mapa_longo_jogador_1, jogador1, i);
                }
                for(int i = 1; i < 6; i++){
                    posicionar_barco_de_2(mapa_curto_jogador_1, mapa_longo_jogador_1, jogador1, i);
                }
            }
            cout<<"\t\t\tAPERTE QUALQUER TECLA PARA PASSAR PARA O PRÓXIMO JOGADOR ";
            fflush(stdin);
            getch();
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\t\t\tVez de "<<jogador2<<" posicionar seus barcos!";
            cout<<"\t\t\t\t\t APERTE QUALQUER TECLA PARA POSICIONAR SEUS BARCOS ";
            fflush(stdin);
            getch();
            system("cls");
            if(tamanho == 5){
                posicionar_barco_de_1(mapa_curto_jogador_2, mapa_longo_jogador_2, jogador2, 1);
                for(int i = 1; i < 4; i++){
                    posicionar_barco_de_2(mapa_curto_jogador_2, mapa_longo_jogador_2, jogador2, i);
                }
            }
            if(tamanho == 10){
                for(int i = 1; i < 3; i++){
                    posicionar_barco_de_1(mapa_curto_jogador_2, mapa_longo_jogador_2, jogador2, i);
                }
                for(int i = 1; i < 10; i++){
                    posicionar_barco_de_2(mapa_curto_jogador_2, mapa_longo_jogador_2, jogador2, i);
                }
            }
        }
        else{
            system("cls");
            cout<<"\t\t          Por favor digite c ou l ";
            c_ou_l = false;
        }
    }while(c_ou_l == false);
    atacar();
}

void criarmapa(char mapa[][5], char mapa2[][10]){
    if(tamanho == 5){
        for(int linha = 0; linha < tamanho; linha++){
            for (int coluna = 0; coluna < tamanho; coluna++){
                mapa[linha][coluna] = '~';
            }
        }
    }
    else if(tamanho == 10){
        for(int linha = 0; linha < tamanho; linha++){
            for (int coluna = 0; coluna < tamanho; coluna++){
                mapa2[linha][coluna] = '~';
            }
        }
    }
}

void posicionar_barco_de_1(char mapa[5][5], char mapa2[10][10], string jogador, int i){
    int linha, coluna;
    bool flag;
    string linha_str, coluna_str;
    if(tamanho == 5){
        do{
            do{
                cout<<"\n\t\t"<<"Nome: "<<jogador<<" | Posicione seu "<<i<<"º barco de uma casa.\n\n";
                imprime_mapa(mapa, mapa2);
                cout<<"    Digite a linha: ";
                cin>>linha_str;
                cout<<"    Digite a coluna: ";
                cin>>coluna_str;
                if(linha_str.size() == 1  && coluna_str.size() == 1){
                   char l = toupper(linha_str[0]);
                   char c = coluna_str[0];
                   if(isalpha(l)){
                        if(l >= 65 && l <= 69){
                            linha = l-65;
                        }
                        else{
                            linha = tamanho;
                        }
                   }
                   else{
                        linha = tamanho;
                   }

                   if(isdigit(c)){
                        coluna  = c - 48;
                   }
                   else{
                        coluna = tamanho;
                   }
                }
                else{
                    linha = tamanho;
                    coluna = tamanho;
                }
                system("cls");
       }while((coluna > tamanho-1 || coluna < 0 || linha > tamanho-1 || coluna < 0) == true);
            if(mapa [linha][coluna] == '~'){
                mapa[linha][coluna] = '0';
                flag = true;
            }
            else{
                system("cls");
                flag = false;
            }
        }while(flag == false);
    }

    else if(tamanho == 10){
        do{
            do{
                cout<<"\n\t\t"<<"É hora de posicionar seu barco de uma casa "<<jogador<<"!\n\n";
                imprime_mapa(mapa, mapa2);
                cout<<"    Digite a linha: ";
                cin>>linha_str;
                cout<<"    Digite a coluna: ";
                cin>>coluna_str;
                if(linha_str.size() == 1  && coluna_str.size() == 1){
                   char l = toupper(linha_str[0]);
                   char c = coluna_str[0];
                   cout<<l<<"\n";
                   cout<<c<<"\n";
                   if(isalpha(l)){
                        if(l >= 65 && l <= 74){
                            linha = l-65;
                        }
                        else{
                            linha = tamanho;
                        }
                   }
                   else{
                        linha = tamanho;
                   }
                   if(isdigit(c)){
                        coluna  = c - 48;
                   }
                   else{
                        coluna = tamanho;
                   }
                }
                else{
                    linha = tamanho;
                    coluna = tamanho;
                }
                system("cls");
       }while((coluna > tamanho-1 || coluna < 0 || linha > tamanho-1 || coluna < 0) == true);

            if(mapa2 [linha][coluna] == '~'){
                mapa2[linha][coluna] = '0';
                flag = true;
            }
            else {
                system("cls");
                flag = false;
            }
        }while(flag == false);
    }
}

void posicionar_barco_de_2(char mapa[5][5], char mapa2[10][10], string jogador, int i){
    int linha,coluna;
    bool flag, op1 = false, op2, mais1, v, h;
    char l, c;
    string linha_str, coluna_str;
    system("cls");
    if(tamanho == 5){
        do{
            do{
                cout<<"\n\t\t"<<"Nome: "<<jogador<<" | Posicione seu "<<i<<"º barco de duas casas.\n\n";
                imprime_mapa(mapa, mapa2);
                cout<<"    Digite a linha: ";
                cin>>linha_str;
                cout<<"    Digite a coluna: ";
                cin>>coluna_str;
                if(linha_str.size() == 1  && coluna_str.size() == 1){
                   l = toupper(linha_str[0]);
                   c = coluna_str[0];
                   if(isalpha(l)){
                        if(l >= 65 && l <= 69){
                            linha = l-65;
                        }
                        else{
                            linha = tamanho;
                        }
                   }
                   else{
                        linha = tamanho;
                   }

                   if(isdigit(c)){
                        coluna  = c - 48;
                   }
                   else{
                        coluna = tamanho;
                   }
                }
                else{
                    linha = tamanho;
                    coluna = tamanho;
                }
                if(mapa[linha][coluna+1] != '~' && mapa[linha][coluna-1] != '~' && mapa[linha+1][coluna] != '~' && mapa[linha-1][coluna] != '~'){
                    cout<<"\n\tNão é possível posicionar um barco de duas casas nessa posição\n\t pois não há espaços\n";
                    linha = tamanho;
                    coluna = tamanho;
                    cout<<"\t\t\tAPERTE ENTER PARA TENTAR OUTRO LUGAR ";
                    fflush(stdin);
                    getch();
                }
                system("cls");
       }while((coluna > tamanho-1 || coluna < 0 || linha > tamanho-1 || coluna < 0) == true );
            if(mapa [linha][coluna] == '~'){
                bool vh = false;
                flag = true;
                mapa[linha][coluna] = '0';
                do{
                    system("cls");
                    cout<<"\n\t\t"<<"Nome: "<<jogador<<" | Posicione seu "<<i<<"º barco de duas casas.\n\n";
                    imprime_mapa(mapa, mapa2);
                    char hor_vet;
                    if((mapa[linha][coluna-1] != '~' && mapa[linha][coluna+1] != '~') || (coluna-1 < 0 && mapa[linha][coluna+1] != '~') || (mapa[linha][coluna-1] != '~' && coluna+1 > 4)){
                        h = false;
                    }
                    else{
                        h = true;
                    }
                    if(mapa[linha-1][coluna] != '~' && mapa[linha+1][coluna] != '~' || (linha-1 < 0 && mapa[linha+1][coluna] != '~') || (mapa[linha-1][coluna] != '~' && linha+1 > 4)){
                        v = false;
                    }
                    else{
                        v = true;
                    }

                    cout<<"    Você deseja posicionar o barco em qual direção: \n";
                    if(h == true){
                        cout<<"    ->Horizontal(h)\n";
                    }
                    if(v == true){
                        cout<<"    ->Vertical(v)\n";
                    }
                    cout<<"    Digite a letra: ";
                    cin>>hor_vet;
                    if(tolower(hor_vet) == 'h' && h == true){
                        vh = true;
                        bool flagg = false;
                        do{
                            cout<<"    Suas opcoes: \n";
                            if(mapa[linha][coluna-1] == '~'){
                                if(coluna-1 >=0){
                                    cout<<"    1)Linha: "<<l<<" ";
                                    cout<<"Coluna: "<<coluna-1<<" \n";
                                    op1 = true;
                                }
                            }
                            if(mapa[linha][coluna+1] == '~'){
                                if(coluna+1 < 5){
                                    if(op1 == true){
                                        cout<<"    2)Linha: "<<l<<" ";
                                        cout<<"Coluna: "<<coluna+1<<" \n";
                                        op2 = true;
                                        mais1 = true;
                                    }
                                    else{
                                       cout<<"    1) Linha: "<<l<<" ";
                                        cout<<"Coluna: "<<coluna+1<<" \n";
                                        op1 = true;
                                        mais1 = false;
                                    }
                                }
                            }

                            int opcao;
                            cout<<"    Qual opcao voce deseja posicionar o barco? ";
                            cin>>opcao;
                            if(opcao == 1 && op1 == true){
                                if(mais1 == true){
                                    mapa[linha][coluna-1] = '0';
                                    flagg = true;
                                }
                                else{
                                    mapa[linha][coluna+1] = '0';
                                    flagg = true;
                                }
                            }
                            else if (opcao == 2 && op2 == true){
                                mapa[linha][coluna+1] = '0';
                                flagg = true;
                            }
                            else{
                                flagg = false;
                                system("cls");
                                cout<<"\n\t\t"<<"Nome: "<<jogador<<" | Posicione seu "<<i<<"º barco de duas casas.\n\n";
                                imprime_mapa(mapa, mapa2);
                                cout<<"\n    POR FAVOR DIGITE UMA OPÇÃO VALIDA "<<jogador<<"!\n\n";
                            }
                        }while(flagg == false);
                        system("cls");
                        cout<<"\n\t\t\t    Seu mapa final "<<jogador<<"!\n\n";
                        imprime_mapa(mapa, mapa2);
                    }
                    else if(tolower(hor_vet) == 'v' && v == true){
                        vh = true;
                        bool flaggg = false;
                        do{
                            cout<<"    Suas opcoes: \n";
                            if(mapa[linha-1][coluna] == '~'){
                                if(linha-1 >= 0){
                                    char a = linha + 64;
                                    cout<<"\t1) Linha: "<<a<<" ";
                                    cout<<"Coluna: "<<coluna<<" \n";
                                    op1 = true;
                                }
                                else{
                                    op1 = false;
                                }
                            }
                            if(mapa[linha+1][coluna] == '~'){
                                if(linha+1 < 5){
                                    char b = linha + 66;
                                    if(op1 == true){
                                        cout<<"\t2) Linha: "<<b<<" ";
                                        cout<<"Coluna: "<<coluna<<" \n";
                                        op2 = true;
                                        mais1 = true;
                                    }
                                    else{
                                        cout<<"\t1) Linha: "<<b<<" ";
                                        cout<<"Coluna: "<<coluna<<" \n";
                                        op1 = true;
                                        mais1 = false;
                                    }
                                }
                            }
                            if(mapa[linha+1][coluna] == '0' && mapa[linha-1][coluna] == '0'){
                                cout<<"\nPosicoes verticais nao disponiveis\n";
                            }
                            int opcao;
                            cout<<"\tQual opção você deseja posicionar o barco? ";
                            cin>>opcao;
                            if(opcao == 1 && op1 == true){
                                if(mais1 == true){
                                    mapa[linha-1][coluna] = '0';
                                    flaggg = true;
                                }
                                else{
                                    mapa[linha+1][coluna] = '0';
                                    flaggg = true;
                                }
                            }
                            else if (opcao == 2 && op2 == true){
                                mapa[linha+1][coluna] = '0';
                                flaggg = true;
                            }
                            else{
                                flaggg = false;
                                system("cls");
                                cout<<"\n\t\t"<<"Nome: "<<jogador<<" | Posicione seu "<<i<<"º barco de duas casas.\n\n";
                                imprime_mapa(mapa, mapa2);
                                cout<<"\n\t"<<"POR FAVOR DIGITE UMA OPCAO VALIDA "<<jogador<<"!\n\n";
                            }
                        }while(flaggg == false);
                        system("cls");
                        cout<<"\n\t\t\t    Seu mapa final "<<jogador<<"!\n\n";
                        imprime_mapa(mapa, mapa2);
                    }
                    else{
                        vh = false;
                    }
                }while(vh == false);
            }
            else if(mapa [linha][coluna] == '0'){
                flag = false;
                system("cls");
            }
        }while(flag == false);
    }

    else if(tamanho == 10){
        do{
            do{
                cout<<"\n\t\t"<<"Nome: "<<jogador<<" | Posicione seu "<<i<<"º barco de duas casas.\n\n";
                imprime_mapa(mapa, mapa2);
                cout<<"\tDigite a linha: ";
                cin>>linha_str;
                cout<<"\tDigite a coluna: ";
                cin>>coluna_str;
                if(linha_str.size() == 1  && coluna_str.size() == 1){
                   l = toupper(linha_str[0]);
                   c = coluna_str[0];
                   if(isalpha(l)){
                        if(l >= 65 && l <= 74){
                            linha = l-65;
                        }
                        else{
                            linha = tamanho;
                        }
                   }
                   else{
                        linha = tamanho;
                   }

                   if(isdigit(c)){
                        coluna  = c - 48;
                    }
                    else{
                        coluna = tamanho;
                    }
                }
                else{
                    linha = tamanho;
                    coluna = tamanho;
                }
                if(mapa2[linha][coluna+1] != '~' && mapa2[linha][coluna-1] != '~' && mapa2[linha+1][coluna] != '~' && mapa2[linha-1][coluna] != '~'){
                    cout<<"\n\tNão é possível posicionar um barco de duas casas nessa posição\n\t pois não há espaços\n";
                    linha = tamanho;
                    coluna = tamanho;
                    cout<<"\t\t\tAPERTE ENTER ";
                    fflush(stdin);
                    getchar();
                }
                system("cls");
       }while((coluna > tamanho-1 || coluna < 0 || linha > tamanho-1 || coluna < 0) == true);

            if(mapa2 [linha][coluna] == '~'){
                mapa2[linha][coluna] = '0';
                bool fv = false;
                flag = true;
                do{
                    system("cls");
                    cout<<"\n\t\t"<<"Nome: "<<jogador<<" | Posicione seu "<<i<<"º barco de duas casas.\n\n";
                    imprime_mapa(mapa, mapa2);
                    char hor_vet;
                    if((mapa2[linha-1][coluna] != '~' && mapa2[linha+1][coluna] != '~') || (linha-1 < 0 && mapa2[linha+1][coluna] != '~') || (mapa[linha-1][coluna] != '~' && linha+1 > 9)){
                        h = false;
                    }
                    else{
                        h = true;
                    }
                    if((mapa2[linha-1][coluna] != '~' && mapa2[linha+1][coluna] != '~') || (linha-1 < 0 && mapa2[linha+1][coluna] != '~') || (mapa[linha-1][coluna] != '~' && linha+1 > 9)){
                        v = false;
                    }
                    else{
                        v = true;
                    }
                    cout<<"\tVocê deseja posicionar o barco em qual direção: ";
                    if(h == true){
                        cout<<"\n\tHorizontal(h)";
                    }
                    if(v == true){
                        cout<<"\n\tVertical(v)";
                    }
                    cin>>hor_vet;
                    if(tolower(hor_vet) == 'h' && h == true){
                        fv= true;
                        bool flagg = false;
                        do{
                            cout<<"\tSuas opcoes: \n";
                            if(mapa2[linha][coluna-1] == '~'){
                                if(coluna-1 >=0){
                                    cout<<"\t1) Linha: "<<l<<" ";
                                    cout<<"Coluna: "<<coluna-1<<" \n";
                                    op1 = true;
                                }
                            }
                            if(mapa2[linha][coluna+1] == '~'){
                                if(coluna+1 < 10){
                                    if(op1 == true){
                                    cout<<"\t2) Linha: "<<l<<" ";
                                    cout<<"Coluna: "<<coluna+1<<" \n";
                                    op2 = true;
                                    mais1 = true;
                                    }
                                    else{
                                     cout<<"\t1) Linha: "<<l<<" ";
                                    cout<<"Coluna: "<<coluna+1<<" \n";
                                    op1 = true;
                                    mais1 = false;
                                    }
                                }
                            }
                            if(mapa2[linha][coluna+1] == '0' && mapa2[linha][coluna-1] == '0'){
                                cout<<"\nPosicoes horizontais nao disponiveis\n";
                            }
                            int opcao;
                            cout<<"\tQual opcao voce deseja posicionar o barco? ";
                            cin>>opcao;
                            if(opcao == 1 && op1 == true){
                                if(mais1 == true){
                                mapa2[linha][coluna-1] = '0';
                                flagg = true;
                                }
                                else{
                                   mapa2[linha][coluna+1] = '0';
                                    flagg = true;
                                }
                            }
                            else if (opcao == 2 && op2 == true){
                                mapa2[linha][coluna+1] = '0';
                                flagg = true;
                            }
                            else{
                                flagg = false;
                                system("cls");
                                cout<<"\n\t\t"<<"Nome: "<<jogador<<" | Posicione seu "<<i<<"º barco de duas casas.\n\n";
                                imprime_mapa(mapa, mapa2);
                                cout<<"\n\t"<<"POR FAVOR DIGITE UMA OPCAO VALIDA "<<jogador<<"!\n\n";
                            }
                        }while(flagg == false);

                        system("cls");
                        cout<<"\n\t\t\t    Seu mapa final "<<jogador<<"!\n\n";
                        imprime_mapa(mapa, mapa2);
                    }
                    else if(tolower(hor_vet) == 'v' && v == true){
                        fv = true;
                        bool flaggg = false;
                        do{
                            cout<<"\tSuas opcoes: \n";
                            if(mapa2[linha-1][coluna] == '~'){
                                if(linha-1 >= 0){
                                    char c = linha + 64;
                                    cout<<"\t1) Linha: "<<c<<" ";
                                    cout<<"Coluna: "<<coluna<<" \n";
                                    op1 = true;
                                }
                            }
                            if(mapa2[linha+1][coluna] == '~'){
                                if(linha+1 < 10){
                                    char d = linha + 66;
                                    if(op1 == true){
                                    cout<<"\t2) Linha: "<<d<<" ";
                                    cout<<"Coluna: "<<coluna<<" \n";
                                    op2 = true;
                                    mais1 = true;
                                    }
                                    else{
                                      cout<<"\t1) Linha: "<<d<<" ";
                                        cout<<"Coluna: "<<coluna<<" \n";
                                        op1 = true;
                                        mais1 = false;
                                    }
                                }
                            }
                            if(mapa2[linha+1][coluna] == '0' && mapa2[linha-1][coluna] == '0'){
                                cout<<"\nPosicoes verticais nao disponiveis\n";
                            }
                            int opcao;
                            cout<<"\tQual opção você deseja posicionar o barco? ";
                            cin>>opcao;
                            if(opcao == 1 && op1 == true){
                                if(mais1 == true){
                                mapa2[linha-1][coluna] = '0';
                                flaggg = true;
                                }
                                else{
                                    mapa2[linha+1][coluna] = '0';
                                    flaggg = true;
                                }
                            }
                            else if (opcao == 2 && op2 == true){
                                mapa2[linha+1][coluna] = '0';
                                flaggg = true;
                            }
                            else{
                                flaggg = false;
                                system("cls");
                                cout<<"\n\t\t"<<"Nome: "<<jogador<<" | Posicione seu "<<i<<"º barco de duas casas.\n\n";
                                imprime_mapa(mapa, mapa2);
                                cout<<"\n\t"<<"POR FAVOR DIGITE UMA OPCAO VALIDA "<<jogador<<"!\n\n";
                            }
                        }while(flaggg == false);

                        system("cls");
                        cout<<"\n\t\t\t    Seu mapa final "<<jogador<<"!\n\n";
                        imprime_mapa(mapa, mapa2);
                    }
                    else{
                        fv = false;
                    }
                }while(fv == false);
            }
            else if(mapa2 [linha][coluna] == '0'){
                cout<<"Ja existe um barco posicionado nessa posicao, digite outra posicao\n";
                flag = false;
                system("cls");
            }
        }while(flag == false);
    }
}

void imprime_header(){
    system("cls");
    system("color 1f");
    cout<<"\n";
    cout<<"    __|__ |___| |\\ \n";
	cout<<"    |o__| |___| | \\        	  BATALHA\n";
	cout<<"    |___| |___| |o \\               NAVAL\n";
	cout<<"   _|___| |___| |__o\\          IEEE - CEFET-RJ\n";
	cout<<"  /...\\_____|___|____\\_/           GRUPO 7\n";
	cout<<"  \\   o * o * * o o  /\n";
	cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
}

void imprime_mapa(char mapa[5][5], char mapa2[10][10]){
    char cont;
        if(tamanho == 5){
            cout<<"\t\t\t\t |0|1|2|3|4|\n";
            for(int cont1=0;cont1<5;cont1++){
                cont = cont1+65;
                cout<<"\t\t\t\t"<<cont<<"|";
                for(int cont2=0;cont2<5;cont2++){
                    cout<<mapa[cont1][cont2]<<"|";
                }
                cout<<"\n";
            }
        }
        else if(tamanho == 10){
            cout<<"\t\t\t\t |0|1|2|3|4|5|6|7|8|9|\n";
            for(int cont1=0;cont1<10;cont1++){
                cont = cont1+65;
                cout<<"\t\t\t\t"<<cont<<"|";
                for(int cont2=0;cont2<10;cont2++){
                    cout<<mapa2[cont1][cont2]<<"|";
                }
                cout<<"\n";
            }
        }
        cout<<"\n    -------------------------------------------------------------------------\n";
        if(ataque == true){
            cout<<"    | Legenda:              |  Regras:                                      |\n";
            cout<<"    | ~:Agua                |  São aceitas somente letras para a linha      |\n";
            cout<<"    | #: Tiro não acertado  |  São aceitos somente números para a coluna    |\n";
            cout<<"    | X: Tiro acertado      |                                               |\n";
        }
        else{
            cout<<"    | Legenda:              |  Regras:                                      |\n";
            cout<<"    | ~:Agua                |  São aceitas somente letras para a linha      |\n";
            cout<<"    | 0: Barco posicionado  |  São aceitos somente números para a coluna    |\n";
        }
        cout<<"    -------------------------------------------------------------------------\n";
}

void atacar(){
    ataque = true;
    int contcurto1 = 7, contcurto2 = 7, contlongo1 = 12, contlongo2 = 12;
    criarmapa(mapa_atacar_1_curto, mapa_atacar_1_longo);
    criarmapa(mapa_atacar_2_curto, mapa_atacar_2_longo);
    string linha_atq1, coluna_atq1, linha_atq2, coluna_atq2;
    char l, c;
    int linha = 0, coluna =0;
    bool acertou1 = false, acertou2 = false;
    if(tamanho == 5){
        do{
            do{
                system("cls");
                do{
                    cout<<"\t\t\t     Vez de "<<jogador1<<" atacar!\n\n";
                    imprime_mapa(mapa_atacar_1_curto, mapa_atacar_1_longo);
                    cout<<"\tDigite a linha: ";
                    cin>>linha_atq1;
                    cout<<"\tDigite a coluna: ";
                    cin>>coluna_atq1;
                    if(linha_atq1.size() == 1  && coluna_atq1.size() == 1){
                        l = toupper(linha_atq1[0]);
                        c = coluna_atq1[0];
                        if(isalpha(l)){
                            if(l >= 65 && l <= 69){
                                linha = l-65;
                            }
                            else{
                                linha = tamanho;
                            }
                        }
                        else{
                            linha = tamanho;
                        }

                        if(isdigit(c)){
                            coluna  = c - 48;
                        }
                        else{
                            coluna = tamanho;
                        }
                    }
                    else{
                        linha = tamanho;
                        coluna = tamanho;
                    }
                    system("cls");
                }while(linha > tamanho-1 || linha< 0 || coluna > tamanho-1 || coluna < 0);

                if(mapa_atacar_1_curto[linha][coluna] == '#' || mapa_atacar_1_curto[linha][coluna] == 'X'){
                    cout<<"\tVoce já tentou essa opcao, por favor digite outra";
                    acertou1 = true;
                }
                else{
                    if(mapa_curto_jogador_2[linha][coluna] == '0'){
                        mapa_atacar_1_curto[linha][coluna] = 'X';
                        contcurto1--;
                        system("cls");
                        cout<<"\t\t\t     Vez de "<<jogador1<<" atacar!\n\n";
                        imprime_mapa(mapa_atacar_1_curto, mapa_atacar_1_longo);
                        cout<<"\tParabéns! Você acertou um barco do seu inimigo!\n";
                        cout<<"\tAperte qualquer tecla para atacar novamente! ";
                        acertou1 = true;
                    if(contcurto1 == 0){
                        acertou1 = false;
                    }
                    fflush(stdin);
                    getch();
                    }
                    else if(mapa_curto_jogador_2[linha][coluna] == '~'){
                        mapa_atacar_1_curto[linha][coluna] = '#';
                        cout<<"\tVoce acertou na agua!\n";
                        cout<<"\tAperte qualquer tecla para o próximo jogador atacar! ";
                        acertou1 = false;
                        fflush(stdin);
                        getchar();
                    }
                }
            }while(acertou1 == true);

            if(contcurto1 != 0){
                do{
                    system("cls");
                    do{
                        cout<<"\t\t\t     Vez de "<<jogador2<<" atacar!\n\n";
                        imprime_mapa(mapa_atacar_2_curto, mapa_atacar_2_longo);
                        cout<<"\tDigite a linha: ";
                        cin>>linha_atq2;
                        cout<<"\tDigite a coluna: ";
                        cin>>coluna_atq2;
                        if(linha_atq2.size() == 1  && coluna_atq2.size() == 1){
                        l = toupper(linha_atq2[0]);
                        c = coluna_atq2[0];
                        if(isalpha(l)){
                            if(l >= 65 && l <= 69){
                                linha = l-65;
                            }
                            else{
                                linha = tamanho;
                            }
                        }
                        else{
                            linha = tamanho;
                        }

                        if(isdigit(c)){
                            coluna  = c - 48;
                        }
                        else{
                            coluna = tamanho;
                        }
                        }
                        else{
                            linha = tamanho;
                            coluna = tamanho;
                        }
                    system("cls");
                    }while(linha > tamanho-1 || linha< 0 || coluna > tamanho-1 || coluna < 0);

                    if(mapa_atacar_2_curto[linha][coluna] == '#' || mapa_atacar_2_curto[linha][coluna] == 'X'){
                        cout<<"\tVoce já tentou essa opcao, por favor digite outra";
                        cout<<"\tAperte qualquer tecla para tentar novamente! ";
                        fflush(stdin);
                        getch();
                        acertou2 = true;
                    }
                    else{
                        if(mapa_curto_jogador_1[linha][coluna] == '0'){
                            mapa_atacar_2_curto[linha][coluna] = 'X';
                            contcurto2--;
                            system("cls");
                            cout<<"\t\t\t     Vez de "<<jogador2<<" atacar!\n\n";
                            imprime_mapa(mapa_atacar_2_curto, mapa_atacar_2_longo);
                            cout<<"\tParabéns! Você acertou um barco do seu inimigo!\n";
                            cout<<"\tAperte qualquer tecla para atacar novamente! ";
                            acertou2 = true;
                            if(contcurto2 == 0){
                                acertou2 = false;
                            }
                            fflush(stdin);
                            getch();
                        }
                        else if(mapa_curto_jogador_1[linha][coluna] == '~'){
                            mapa_atacar_2_curto[linha][coluna] = '#';
                            cout<<"\tVoce acertou na agua!\n";
                            cout<<"\tAperte qualquer tecla para o próximo jogador atacar! ";
                            acertou2 = false;
                            fflush(stdin);
                            getch();
                        }
                    }
                }while(acertou2 == true);
            }
        }while(contcurto1 != 0 && contcurto2 != 0);
    }
    else if(tamanho == 10){
        do{
            do{
                system("cls");
                do{
                    cout<<"\t\t\t     Vez de "<<jogador1<<" atacar!\n\n";
                    imprime_mapa(mapa_atacar_1_curto, mapa_atacar_1_longo);
                    cout<<"\tDigite a linha: ";
                    cin>>linha_atq1;
                    cout<<"\tDigite a coluna: ";
                    cin>>coluna_atq1;
                    if(linha_atq1.size() == 1  && coluna_atq1.size() == 1){
                        l = toupper(linha_atq1[0]);
                        c = coluna_atq1[0];
                        if(isalpha(l)){
                            if(l >= 65 && l <= 69){
                                linha = l-65;
                            }
                            else{
                                linha = tamanho;
                            }
                        }
                        else{
                            linha = tamanho;
                        }

                        if(isdigit(c)){
                            coluna  = c - 48;
                        }
                        else{
                            coluna = tamanho;
                        }
                    }
                    else{
                        linha = tamanho;
                        coluna = tamanho;
                    }
                    system("cls");
                }while(linha > tamanho-1 || linha< 0 || coluna > tamanho-1 || coluna < 0);

                if(mapa_atacar_1_longo[linha][coluna] == '#' || mapa_atacar_1_longo[linha][coluna] == 'X'){
                    cout<<"\tVoce já tentou essa opcao, por favor digite outra";
                    cout<<"\tAperte qualquer tecla para tentar novamente! ";
                    fflush(stdin);
                    getch();
                    acertou1 = true;
                }
                else{
                    if(mapa_longo_jogador_2[linha][coluna] == '0'){
                        mapa_atacar_1_longo[linha][coluna] = 'X';
                        contlongo1--;
                        system("cls");
                        cout<<"\t\t\t     Vez de "<<jogador1<<" atacar!\n\n";
                        imprime_mapa(mapa_atacar_1_curto, mapa_atacar_1_longo);
                        cout<<"\tParabéns! Você acertou um barco do seu inimigo!\n";
                        cout<<"\tAperte qualquer para atacar novamente! ";
                        acertou1 = true;
                        if(contlongo1 == 0){
                            acertou1 = false;
                        }
                        fflush(stdin);
                        getchar();
                    }
                    else if(mapa_longo_jogador_2[linha][coluna] == '~'){
                        mapa_atacar_1_longo[linha][coluna] = '#';
                        cout<<"\tVoce acertou na agua!\n";
                        cout<<"\tAperte qualquer tecla para o próximo jogador atacar! ";
                        acertou1 = false;
                        fflush(stdin);
                        getchar();
                    }
                }
            }while(acertou1 == true);

            if(contlongo1 != 0){
                do{
                    system("cls");
                    do{
                        cout<<"\t\t\t     Vez de "<<jogador2<<" atacar!\n\n";
                        imprime_mapa(mapa_atacar_2_curto, mapa_atacar_2_longo);
                        cout<<"\tDigite a linha: ";
                        cin>>linha_atq2;
                        cout<<"\tDigite a coluna: ";
                        cin>>coluna_atq2;
                        if(linha_atq2.size() == 1  && coluna_atq2.size() == 1){
                        l = toupper(linha_atq2[0]);
                        c = coluna_atq2[0];
                        if(isalpha(l)){
                            if(l >= 65 && l <= 69){
                                linha = l-65;
                            }
                            else{
                                linha = tamanho;
                            }
                        }
                        else{
                            linha = tamanho;
                        }

                        if(isdigit(c)){
                            coluna  = c - 48;
                        }
                        else{
                            coluna = tamanho;
                        }
                        }
                        else{
                            linha = tamanho;
                            coluna = tamanho;
                        }
                        system("cls");
                    }while(linha > tamanho-1 || linha< 0 || coluna > tamanho-1 || coluna < 0);

                    if(mapa_atacar_2_longo[linha][coluna] == '#' || mapa_atacar_2_longo[linha][coluna] == 'X'){
                        cout<<"\tVoce já tentou essa opcao, por favor digite outra";
                        cout<<"\tAperte qualquer tecla para tentar novamente! ";
                        fflush(stdin);
                        getch();
                        acertou2 = true;
                    }
                    else{
                        if(mapa_longo_jogador_1[linha][coluna] == '0'){
                            mapa_atacar_2_longo[linha][coluna] = 'X';
                            contlongo2--;
                            system("cls");
                            cout<<"\t\t\t     Vez de "<<jogador2<<" atacar!\n\n";
                            imprime_mapa(mapa_atacar_2_curto, mapa_atacar_2_longo);
                            cout<<"\tParabéns! Você acertou um barco do seu inimigo!\n";
                            cout<<"\tAperte qualquer tecla para atacar novamente! ";
                            acertou2 = true;
                            if(contlongo2 == 0){
                                acertou2 = false;
                            }
                            fflush(stdin);
                            getch();
                        }
                        else if(mapa_longo_jogador_1[linha][coluna] == '~'){
                            mapa_atacar_2_longo[linha][coluna] = '#';
                            cout<<"\tVoce acertou na agua!\n";
                            cout<<"\tAperte qualquer tecla para o próximo jogador atacar! ";
                            acertou2 = false;
                            fflush(stdin);
                            getch();
                        }
                    }
                }while(acertou2 == true);
            }
        }while(contlongo1 != 0 && contlongo2 != 0);
    }

    system("cls");
    if(contcurto1 == 0 || contlongo1 == 0 ){
        cout<<"\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"                         O jogador de nome: "<<jogador1<<" ganhou                          \n";
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"\t\t    Aperte qualquer tecla para voltar ao menu ";
        fflush(stdin);
        getch();
    }

    if(contcurto2 == 0 || contlongo2 == 0 ){
        cout<<"\n\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"                         O jogador de nome: "<<jogador2<<" ganhou                          \n";
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        cout<<"\t\t    Aperte qualquer tecla para voltar ao menu ";
        fflush(stdin);
        getch();
    }

}
