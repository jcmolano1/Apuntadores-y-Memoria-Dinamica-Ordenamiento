//
// Created by Jose Carlos Molano on 27/08/20.
//
#include <iostream>
#include <time.h>
using namespace std;
#include "Funciones.h"

void funcionamiento()
{
    int *n = new int;
    int c;
    int *vec;
    int **mat;
    cout<<"Tamaño del arreglo a crear: ";
    cin>>*n;
    cout<<"Número maximo de cifras: ";
    cin>>c;
    vec = new int[*n];
    mat=new int*[10];
    llenado(n,vec,c);
    imprimirvec(n,vec);
    matrizcubetas(n,vec,mat);
    delete[] mat;
    delete[] vec;
    delete n;
}
void llenado(int*n, int *vec, int c)
{
    srand(time(0));
    cout<<"Arreglo de longitud "<<*n<<": ";
    if (c==3)
    {
        for (int i=0;i<*n;i++)
        {
            *(vec+i)=(1+rand()%999);
        }
    }
    if (c==2)
    {
        for (int i=0;i<*n;i++)
        {
            *(vec+i)=(1+rand()%99);
        }
    }
    if (c==1)
    {
        for (int i=0;i<*n;i++)
        {
            *(vec+i)=(1+rand()%9);
        }
    }
}

void imprimirvec(int *n, int *vec)
{
    for (int i=0;i<*n;i++)
    {
        cout<<*(vec+i)<<" ";
    }
    cout<<endl;
}
void matrizcubetas(int *n, int *vec, int **mat)
{
    for (int i=0;i<10;i++)
    {
        *(mat+i)=new int[*n];
    }
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<*n;j++){
            *(*(mat+i)+j)=0;
        }
    }
    int unit;//fila
    int col=0;//columna
    /*
     * Unidades
     */
    for(int i=0;i<*n;i++)
    {
        //unit->Fila
        //10 columnas
        unit=*(vec+i)%10;
        if (*(*(mat+unit)+col)==0)
        {
            *(*(mat+unit)+col)=*(vec+i);
        } else{
            do{
                col++;
            } while(*(*(mat+unit)+col)!=0);
            *(*(mat+unit)+col)=*(vec+i);
            col=0;
        }
    }
    col=0;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<*n;j++){
            if(*(*(mat+i)+j)!=0)
            {
                *(vec+col)=*(*(mat+i)+j);
                col++;
            }
        }

    }
    cout<<endl;
    cout<<"Arreglo ordenado por unidades: ";
    for (int i=0;i<*n;i++)
    {
        cout<<*(vec+i)<<" ";
    }
    /*
     * Decenas
     */
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<*n;j++){
            *(*(mat+i)+j)=0;
        }
    }
    col=0;
    for(int i=0;i<*n;i++)
    {
        //unit->Fila
        //10 columnas
        unit=(*(vec+i)/10)%10;
        if (*(*(mat+unit)+col)==0)
        {
            *(*(mat+unit)+col)=*(vec+i);
        } else{
            do{
                col++;
            } while(*(*(mat+unit)+col)!=0);
            *(*(mat+unit)+col)=*(vec+i);
            col=0;
        }
    }
    col=0;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<*n;j++){
            if(*(*(mat+i)+j)!=0)
            {
                *(vec+col)=*(*(mat+i)+j);
                col++;
            }
        }
    }
    cout<<endl;
    cout<<"Arreglo ordenado por unidades y decenas: ";
    for (int i=0;i<*n;i++)
    {
        cout<<*(vec+i)<<" ";
    }
    /*
     * Centenas
     */
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<*n;j++){
            *(*(mat+i)+j)=0;
        }
    }
    col=0;
    for(int i=0;i<*n;i++)
    {
        unit=(*(vec+i)/10)/10;
        if (*(*(mat+unit)+col)==0)
        {
            *(*(mat+unit)+col)=*(vec+i);
        } else{
            do{
                col++;
            } while(*(*(mat+unit)+col)!=0);
            *(*(mat+unit)+col)=*(vec+i);
            col=0;
        }
    }
    col=0;
    for (int i=0;i<10;i++)
    {
        for (int j=0;j<*n;j++){
            if(*(*(mat+i)+j)!=0)
            {
                *(vec+col)=*(*(mat+i)+j);
                col++;
            }
        }
    }
    cout<<endl;
    cout<<"Arreglo ordenado por unidades, decenas y centenas: ";
    for (int i=0;i<*n;i++)
    {
        cout<<*(vec+i)<<" ";
    }
    for (int i=0;i<10;i++)
    {
        delete mat[i];
    }
}