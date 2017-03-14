#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
struct fullo
{
    char arithmos;
    char xrwma[10];
    int aksia;
};
int moirasma_arithmos()
{
    int a;
    a=(rand()%8)+7;
    return a;
}
int moirasma_xrwma()
{
    int a;
    a=rand()%4;
    return a;
}
struct fullo moirasma_paiktis()
{
    struct fullo f;
    int x,y;
    x=moirasma_arithmos();
    if (x==7)
    {
        f.arithmos='7';
        f.aksia=7;
    }
    else if (x==8)
    {
        f.arithmos='8';
        f.aksia=8;
    }
    else if (x==9)
    {
        f.arithmos='9';
        f.aksia=9;
    }
    else if (x==10)
        f.aksia=10;
    else if (x==11)
    {
        f.arithmos='J';
        f.aksia=2;
    }
    else if (x==12)
    {
        f.arithmos='Q';
        f.aksia=3;
    }
    else if (x==13)
    {
        f.arithmos='K';
        f.aksia=4;
    }
    else if(x==14)
    {
        f.arithmos='A';
        f.aksia=11;
    }
    y=moirasma_xrwma();
    if (y==0)
        strcpy(f.xrwma,"koupa");
    else if(y==1)
        strcpy(f.xrwma,"karo");
    else if(y==2)
        strcpy(f.xrwma,"mpastouni");
    else if(y==3)
        strcpy(f.xrwma,"spathi");
    return f;
}
float pontarisma()
{
    float poso;
    do
    {
        printf("Pliktrologise to poso pou theleis na pontareis:");
        scanf("%f",&poso);
    }
    while(poso<=0);
    return poso;
}
char erwtisi()
{
    char apantisi;
    do
    {
        printf("Epithumeis na travikseis allo fullo?(y/n) \n");
        apantisi=getch();
    }
    while (apantisi!='y' && apantisi!='n' && apantisi!='Y' && apantisi!='N');
    return apantisi;
}
struct person
{
    char name[20];
    float ypoloipo;
    struct fullo f;
};
int main()
{
    srand(time(NULL));
    int i,j,h,k,arithmos_paiktwn,sunolo,sunolo1,elegxos=1,elegxos1=1,test=-1;//test:elegxei posoi guroi paixtikan afou triplasiastike i kava
    float arxiko_poso,kava,arxiki_kava,stoixima,max;
    char apantisi;
    struct person *myperson;
    struct f;
    do
    {
        printf("Dwse to plithos twn summetexontwn kai ton arithmo twn xrimatwn pou exoun arxika se eurw:");
        scanf("%d %f",&arithmos_paiktwn,&arxiko_poso);
    }
    while(arithmos_paiktwn<=0 || arithmos_paiktwn>10 || arxiko_poso<=0);
    myperson=(struct person*)calloc(arithmos_paiktwn+1,sizeof(struct person));
    if (myperson==NULL)
        printf("Den mporei na desmeutei mnimi");
    else
    {
        strcpy(myperson[0].name,"MANA");
        myperson[0].ypoloipo=arxiko_poso;
        for(i=1;i<=arithmos_paiktwn;i++)
        {
            printf("Dwse to onoma tou paikti #%d : \n",i);
            fflush(stdin);
            scanf("%s",myperson[i].name);
            myperson[i].ypoloipo=arxiko_poso;
        }
        arxiki_kava=myperson[0].ypoloipo/4;
        myperson[0].ypoloipo-=arxiki_kava;
        kava=arxiki_kava;
            for(i=1;i<=arithmos_paiktwn;i++)
                myperson[i].f=moirasma_paiktis();
            i=1;//o arithmos pou antistoixei ston paikti pou paizei
            while(elegxos==1)
            {
                if(myperson[i].f.aksia==10)
                    printf("%s:To fullo sou #1 einai 10 %s \n",myperson[i].name,myperson[i].f.xrwma);
                else
                    printf("%s:To fullo sou #1 einai %c %s \n",myperson[i].name,myperson[i].f.arithmos,myperson[i].f.xrwma);
                sunolo1=0;//to sunolo twn pontwn pou exei sugkentrwsei i mana
                j=0;//0:o paiktis sunexizei na trava fulla,1:21 i o paiktis kaike,2 o paiktis travikse 5 fulla kai den kaike i den ekane 21,3:o paiktis den tha traviksei allo fullo
                h=1;//o arithmos twn fullwn pou exei traviksei o kathe paiktis
                k=0;//o arithmos twn fullwn pou exei traviksei i mana
                sunolo=myperson[i].f.aksia;//to sunolo twn pontwn pou exei sugkentrwsei o paiktis
                do
                    stoixima=pontarisma();
                while (stoixima<0 || stoixima>kava || stoixima>myperson[i].ypoloipo);
                apantisi=erwtisi();
                while(j==0)
                {
                    if(apantisi=='y')
                    {
                        h++;
                        myperson[i].f=moirasma_paiktis();
                        sunolo+=myperson[i].f.aksia;
                        if(myperson[i].f.aksia==10)
                            printf("%s:To fullo sou #%d einai 10 %s (sunolo:%d) \n",myperson[i].name,h,myperson[i].f.xrwma,sunolo);
                        else if(sunolo==22 && h==2)
                            printf("%s:To fullo sou #%d einai %c %s (sunolo:21) \n",myperson[i].name,h,myperson[i].f.arithmos,myperson[i].f.xrwma);
                        else
                            printf("%s:To fullo sou #%d einai %c %s (sunolo:%d) \n",myperson[i].name,h,myperson[i].f.arithmos,myperson[i].f.xrwma,sunolo);
                        if(sunolo==21)
                        {
                            j=1;
                            myperson[i].ypoloipo+=stoixima;
                            kava-=stoixima;
                            printf("Sugxaritiria ekanes 21.To poso pou pontares tha prostethei sta xrimata sou!! \n");
                        }
                        else if(sunolo>21)
                            if(h==2 && sunolo==22)
                            {
                                j=1;
                                myperson[i].ypoloipo+=stoixima;
                                kava-=stoixima;
                                printf("Sugxaritiria ekanes 21.To poso pou pontares tha prostethei sta xrimata sou!! \n");
                            }
                            else
                            {
                                j=1;
                                myperson[i].ypoloipo-=stoixima;
                                kava+=stoixima;
                                printf("Kaikes!! \n");
                            }
                        else if(sunolo<21)
                            if(h==5)
                                j=2;
                            else
                                apantisi=erwtisi();
                    }
                    else if(apantisi=='n')
                        j=3;
                    if(j==2)
                    {
                        while(sunolo1<21)
                        {
                            k++;
                            myperson[0].f=moirasma_paiktis();
                            sunolo1+=myperson[0].f.aksia;
                            if(myperson[0].f.aksia==10)
                                printf("%s :To fullo sou #%d einai 10 %s \n",myperson[0].name,k,myperson[0].f.xrwma);
                            else
                                printf("%s :To fullo sou #%d einai %c %s \n",myperson[0].name,k,myperson[0].f.arithmos,myperson[0].f.xrwma);
                        }
                        if(sunolo1==21)
                        {
                            printf("I mana ekane 21.Dustuxws exases \n");
                            kava+=stoixima;
                            myperson[i].ypoloipo-=stoixima;
                        }
                        else if(k==2 && sunolo1==22)
                        {
                            printf("I mana ekane 21.Dustuxws exases \n");
                            kava+=stoixima;
                            myperson[i].ypoloipo-=stoixima;
                        }
                        else
                        {
                            printf("I mana kaike.Kerdises!! \n");
                            kava-=stoixima;
                            myperson[i].ypoloipo+=stoixima;
                        }
                    }
                    else if(j==3)
                    {
                        while(sunolo1<17)
                        {
                            k++;
                            myperson[0].f=moirasma_paiktis();
                            sunolo1+=myperson[0].f.aksia;
                            if(myperson[0].f.aksia==10)
                                printf("%s :To fullo sou #%d einai 10 %s \n",myperson[0].name,k,myperson[0].f.xrwma);
                            else
                                printf("%s :To fullo sou #%d einai %c %s \n",myperson[0].name,k,myperson[0].f.arithmos,myperson[0].f.xrwma);
                        }
                        if(sunolo1==21)
                        {
                            printf("I mana ekane 21.Dustuxws exases \n");
                            kava+=stoixima;
                            myperson[i].ypoloipo-=stoixima;
                        }
                        else if(sunolo1>21)
                        {
                            printf("I mana kaike.Kerdises!! \n");
                            kava-=stoixima;
                            myperson[i].ypoloipo+=stoixima;
                        }
                        else
                            if(sunolo1>=sunolo)
                            {
                                printf("To sunolo tis manas einai %d,to diko sou einai %d.Exases! \n",sunolo1,sunolo);
                                kava+=stoixima;
                                myperson[i].ypoloipo-=stoixima;
                            }
                            else if(sunolo>sunolo1)
                            {
                                printf("To sunolo tis manas einai %d,to diko sou einai %d.Kerdises! \n",sunolo1,sunolo);
                                kava-=stoixima;
                                myperson[i].ypoloipo+=stoixima;
                            }

                    }
                }
                if(test<=arithmos_paiktwn)
                {
                    if(kava==0)
                        elegxos=0;
                    if(elegxos1==1 && kava>=3*arxiki_kava)
                        elegxos1=0;//elegxos1:elegxei an triplasiastike i kava
                    if(elegxos1==0)
                        test++;
                    if(test==arithmos_paiktwn)
                        elegxos=0;
                }
                if(i==arithmos_paiktwn)
                    i=0;
                i++;
            }
        }
        myperson[0].ypoloipo=myperson[0].ypoloipo+kava+arxiki_kava;
        max=myperson[0].ypoloipo;
        for(i=1;i<=arithmos_paiktwn;i++)
            if(myperson[i].ypoloipo>max)
                max=myperson[i].ypoloipo;
        for(i=0;i<=arithmos_paiktwn;i++)
            if(myperson[i].ypoloipo==max)
                printf("O nikitis tou paixnidiou einai o paiktis %s me sunolo %f eurw \n",myperson[i].name,myperson[i].ypoloipo);
        system("pause");
}
