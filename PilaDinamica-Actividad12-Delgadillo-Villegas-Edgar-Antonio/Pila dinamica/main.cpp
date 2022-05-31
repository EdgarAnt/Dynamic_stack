#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;

void validacion();


 void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
 }



class Nodo{
public:
    int value;
    Nodo *next;

};

void push(Nodo *&pila, int n){
    Nodo *temp=new Nodo();
    temp->value= n;
    temp->next = pila;
    pila = temp;
};

void pop(Nodo *&pila)
{
    Nodo *temp = pila;
    pila = temp->next;
    delete(temp);
}

void display(Nodo *&pila, int cont)
{
    Nodo *temp = pila;

    cout<<endl;
    while(temp!=NULL){
        if(temp==pila){
        gotoxy(8,3);
        cout<<"|"<<temp->value<<"|";
        temp=temp->next;
        }else{
            cout<<"\t|"<<temp->value<<"|";
            temp=temp->next;
        }
            cout<<endl;

    }


};

void mostrar_tope(Nodo *&pila){
    Nodo *temp = pila;
    if(temp!=NULL){
        system("cls");
        gotoxy(30,10);
        cout<<"El tope es:  "<<char(186)<<" "<<temp->value<<" "<<char(186)<<endl;
        gotoxy(43,9);
        printf("%c%c%c%c%c", 201,205,205,205,187);
        gotoxy(43,11);
        printf("%c%c%c%c%c", 204,205,205,205,185);
        cout<<"\n\n\n\n\n\n\n\n";
        system("pause");
    }else{
        system("cls");
        cout<<"LA PILA ESTA VACIA"<<endl;
        system("pause");
    }
};

int menu()
{
    int opc;
    gotoxy(52,7);
    cout<<"1) Push";
    gotoxy(52,9);
    cout<<"2) Pop ";
    gotoxy(52,11);
    cout<<"4) Mostrar tope ";
    gotoxy(52,13);
    cout<<"0) Salir ";
    gotoxy(57,17);
    cout<<"Opcion: ";
    cin>>opc;
    return opc;
}

int main()
{
    Nodo *pila=NULL;
    int value, cont=0, opc=1;

    do
        {
            switch (menu())
            {
            case 1:
                cont++;
                push(pila,cont);
                system("CLS");
                display(pila,cont);
                break;
            case 2:
                cont --;
                pop(pila);
                system("cls");
                display(pila,cont);
                break;

            case 3:
                mostrar_tope(pila);
                system("cls");


            case 0:
                opc=0;

                break;

            default:
                std::cout<<"Opcion no disponible";
                }
        }while(opc!=0);
}



void validacion()
{
    char dato='x0';
        if(isdigit(dato))
            cout<<"Es un numero"<<endl;
        else
            cout<<"No es un numero"<<endl;
}
