#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <string>

using namespace std;

int ktowygral(int gol1, int gol2, int &punkty1, int &punkty2, int &bramki1, int &bramki2)
{
    if (gol1==gol2)
    {
        punkty1+=1;
        punkty2+=1;
    }

    else if (gol1>gol2)
    {
        punkty1+=3;
    }

    else if (gol2>gol1)
    {
        punkty2+=3;
    }

    bramki1 += (gol1-gol2);
    bramki2 += (gol2-gol1);


}


int wybortaknie (char &w)
{
    w = getch();

    if (w!='t'&&w!='n')
        while(w!='t'&&w!='n')
        {
            cout<<"Co kurwa zle wpisujesz!";
            cout<<'\n';
            w = getch();
        }
}


int mecz (string team1, string team2, int &gol1, int &gol2)
{

                system("cls");


                cout<<"----------------------"<<endl;
                cout<<"Mecz "<<team1<<" - "<<team2<<endl;
                cout<<"----------------------"<<endl;
                cout<<"Gole "<<team1<<": ";
                cin>>gol1;
                cout<<"Gole "<<team2<<": ";
                cin>>gol2;
                cout<<"----------------------"<<endl;
                cout<<"Wynik: "<<gol1<<" - "<<gol2<<endl;
                cout<<"----------------------"<<endl;



}



int remis (int a, int b, string team1, string team2)
    {
        cout<<endl;
        cout<<"Zlota bramka: "<<endl;
        cout<<"1. "<<team1<<endl;
        cout<<"2. "<<team2<<endl;

        int ch;

        while(!(cin>>ch)||ch>2||ch<1)
        {
            cin.clear();
            cin.sync();
            cout<<"Co kurwa zle wpisujesz!";
            cout<<'\n';
        }

        if (ch==1)
            return 0;
        else if (ch==2)
            return 1;
        else
            return -1;

    }


int losowanie ()
{
             system("cls");
             cout<<"Losowanie..."<<endl;
             Sleep(500);
             system("cls");
             cout<<"Losowanie.."<<endl;
             Sleep(500);
             system("cls");
             cout<<"Losowanie."<<endl;
             Sleep(500);
             system("cls");
}

int main()
{
    system("cls");

    cout << "Menu" << endl;
    cout<<"------------------------"<<endl;
    cout << "1.Turniej Play-Off" << endl;
    cout << "2.Mistrzostwa" << endl;
    cout<<endl;
    cout<<endl;
    cout << "3.Exit" << endl;
    cout<<"------------------------"<<endl;

    char menu;

    menu = getch();

    if (menu!='1'&&menu!='2'&&menu!='3')
        while(menu!='1'&&menu!='2'&&menu!='3')
        {
            cout<<"Co kurwa zle wpisujesz!";
            cout<<'\n';
            menu = getch();
        }

    if(menu=='1')
    {
        system("cls");
        cout<<"Ilosc graczy: "<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1. 4 Graczy"<<endl;
        cout<<"2. 8 Graczy"<<endl;
        cout<<"3. 16 Graczy"<<endl;
        cout<<"------------------------"<<endl;
        cout<<'\n';
        cout<<'\n';
        cout<<"4. Wroc"<<endl;


    //Wybór

    char w;

    w = getch();

    if (w!='1'&&w!='2'&&w!='3'&&w!='4')
        while(w!='1'&&w!='2'&&w!='3'&&w!='4')
        {
            cout<<"Co kurwa zle wpisujesz!";
            cout<<'\n';
            w = getch();
        }

     switch(w)
     {
         case '1':
             {

             system("cls");


             string g[4];
             cout<<"Wpisz nazwy graczy:"<<'\n';
             for(int i=0;i<=3;i++)
                cin>> g[i];

             //Losowanie
             losowanie();

             int wyl[4];
             srand(time(NULL));

             for(int i=0;i<=3;i++)
             {
                  int r =(rand()%4);

                    wyl[i] = r;
                    for(int j=0;j<i;j++)
                    {

                       if(r==wyl[j])
                       {
                       r=(rand()%4);
                       wyl[i] = r;
                       j=-1;
                       }
                    }
             }


             system("cls");

             cout<<"Polfinaly:"<<endl;
             cout<<"--------------------"<<endl;

             cout<<g[wyl[0]]<<" - "<<g[wyl[1]]<<endl;
             cout<<g[wyl[2]]<<" - "<<g[wyl[3]]<<endl;

             }
        break;

         case '2':

         {

             system("cls");


             string g[8];
             cout<<"Wpisz nazwy graczy:"<<'\n';
             for(int i=0;i<=7;i++)
                cin>> g[i];

             //Losowanie
             losowanie();

             int wyl[8];
             srand(time(NULL));

             for(int i=0;i<=7;i++)
             {
                  int r =(rand()%8);

                    wyl[i] = r;
                    for(int j=0;j<i;j++)
                    {

                       if(r==wyl[j])
                       {
                       r=(rand()%8);
                       wyl[i] = r;
                       j=-1;
                       }
                    }
             }


             system("cls");

             cout<<"Cwiercfinaly:"<<endl;
             cout<<"--------------------"<<endl;
             cout<<'\n';


             for(int i=0;i<=7;i+=2)
             {
                 cout<<g[wyl[i]]<<" - "<<g[wyl[i+1]]<<endl;
                 cout<<endl;
             }
             cout<<"--------------------"<<endl;

             cout<<'\n';
             cout<<'\n';
             cout<<'\n';
             cout<<"1. Zacznij mecze"<<endl;
             cout<<'\n';
             cout<<"9.Wroc do menu"<<endl;


                char menu;

                menu = getch();

                if (menu!='1'&&menu!='9')
                    while(menu!='1'&&menu!='9')
                    {
                        cout<<"Co kurwa zle wpisujesz!";
                        cout<<'\n';
                        menu = getch();
                    }

                if (menu == '9')
                {
                    main();
                }

                //Mecze cwiercfinalowe

                int gol[8];
                int wynik14[4],losers14[4];
                int j=0;

                for(int i=0;i<=7;i+=2)
                {
                mecz(g[wyl[i]],g[wyl[i+1]],gol[i],gol[i+1]);
                if(gol[i]==gol[i+1])
                {
                 if((remis(gol[i],gol[i+1],g[wyl[i]],g[wyl[i+1]]))==0)
                    gol[i]+=1;

                 else
                    gol[i+1]+=1;
                }

                if(gol[i]>gol[i+1])
                {
                    wynik14[j]=wyl[i];
                    losers14[j]=wyl[i+1];
                }


                else if(gol[i+1]>gol[i])
                {
                    wynik14[j]=wyl[i+1];
                    losers14[j]=wyl[i];
                }



                j++;
                getchar(); getchar();
                }



                system("cls");
                cout<<"Wyniki meczow 1/4"<<endl;
                cout<<"--------------------"<<endl;
                cout<<'\n';

                for(int i=0;i<=7;i+=2)
                {
                    cout<<g[wyl[i]]<<" - "<<g[wyl[i+1]]<<"  "<<gol[i]<<" : "<<gol[i+1]<<endl;
                    cout<<'\n';
                }

                cout<<"--------------------"<<endl;

                getchar(); getchar();

                //Mecze Polfinalowe

                system("cls");

                cout<<"Polfinaly: "<<endl;
                cout<<"--------------------"<<endl;
                cout<<endl;


                for(int i=0;i<=3;i+=2)
                {
                   cout<<g[wynik14[i]]<<" - "<<g[wynik14[i+1]]<<endl;
                   cout<<endl;
                }
                cout<<"--------------------"<<endl;

                getchar(); getchar();

                int gole[4];
                int wynik12[2],losers12[2];
                j=0;

                for(int i=0;i<=3;i+=2)
                {
                    mecz(g[wynik14[i]],g[wynik14[i+1]],gole[i],gole[i+1]);

                    if(gole[i]==gole[i+1])
                    {
                    if((remis(gole[i],gole[i+1],g[wynik14[i]],g[wynik14[i+1]]))==0)
                    gole[i]+=1;

                    else
                    gole[i+1]+=1;
                    }

                    if(gole[i]>gole[i+1])
                    {
                        wynik12[j]=wynik14[i];
                        losers12[j]=wynik14[i+1];
                    }


                    else if(gole[i+1]>gole[i])
                    {
                       wynik12[j]=wynik14[i+1];
                       losers12[j]=wynik14[i];
                    }



                j++;
                getchar(); getchar();
                }


                system("cls");
                cout<<"Wyniki meczow 1/2"<<endl;
                cout<<"--------------------"<<endl;
                cout<<'\n';

                for(int i=0;i<=3;i+=2)
                {
                    cout<<g[wynik14[i]]<<" - "<<g[wynik14[i+1]]<<"  "<<gole[i]<<" : "<<gole[i+1]<<endl;
                    cout<<'\n';
                }
                cout<<"--------------------"<<endl;

                //o 3 miejsce

                char deco3;

                cout<<'\n';
                cout<<'\n';
                cout<<'\n';
                cout<<'\n';
                cout<<'\n';
                cout<<'\n';
                cout<<"Czy grasz mecz o 3 miejsce?(t,n): ";
                wybortaknie(deco3);

                if(deco3=='t')
                {
                    system("cls");
                    cout<<"Mecz o 3 miejsce: "<<endl;
                    cout<<"--------------------"<<endl;
                    cout<<endl;

                    cout<<g[losers12[0]]<<" - "<<g[losers12[1]]<<endl;
                    cout<<'\n';
                    cout<<"--------------------"<<endl;


                    getchar(); getchar();

                    int golo3[2];

                    mecz(g[losers12[0]],g[losers12[1]],golo3[0],golo3[1]);

                    if(golo3[0]==golo3[1])
                    {
                        if((remis(golo3[0],golo3[1],g[losers12[0]],g[losers12[1]]))==0)
                        golo3[0]+=1;

                        else
                        golo3[1]+=1;
                    }


                    if(golo3[1]>golo3[0])
                    {
                        int d;
                        d = losers12[0];
                        losers12[0]=losers12[1];
                        losers12[1]=d;
                    }

                }


                getchar(); getchar();

                //Finał

                system("cls");
                cout<<"FINAL: "<<endl;
                cout<<"--------------------"<<endl;
                cout<<'\n';

                cout<<g[wynik12[0]]<<" - "<<g[wynik12[1]]<<endl;

                cout<<'\n';
                cout<<"--------------------"<<endl;

                getchar(); getchar();

                int goll[2];
                int winner,loser;


                for(int i=0;i<1;i++)
                {

                mecz(g[wynik12[i]],g[wynik12[i+1]],goll[i],goll[i+1]);

                    if(goll[i]==goll[i+1])
                    {
                    if((remis(goll[i],goll[i+1],g[wynik12[i]],g[wynik12[i+1]]))==0)
                    goll[i]+=1;

                    else
                    goll[i+1]+=1;
                    }

                    if(goll[i]>goll[i+1])
                    {
                        winner=wynik12[i];
                        loser=wynik12[i+1];
                    }


                    else if(goll[i+1]>goll[i])
                    {
                        winner=wynik12[i+1];
                        loser=wynik12[i];
                    }


                }


                //WYNIKI
                system("cls");
                cout<<"WYNIKI: "<<endl;
                cout<<"--------------------"<<endl;
                cout<<"[1]. "<<g[winner]<<endl;
                cout<<"--------------------"<<endl;
                cout<<"[2]. "<<g[loser]<<endl;
                cout<<"[3]. "<<g[losers12[0]]<<endl;
                cout<<"4. "<<g[losers12[1]]<<endl;
                cout<<"--------------------"<<endl;
                cout<<"1/4. "<<g[losers14[0]]<<endl;
                cout<<"1/4. "<<g[losers14[1]]<<endl;
                cout<<"1/4. "<<g[losers14[2]]<<endl;
                cout<<"1/4. "<<g[losers14[3]]<<endl;
                cout<<"--------------------"<<endl;


                getchar(); getchar();




                     }break;

         case '4':
             {
                 main();
             } break;
     }

    }


    else if(menu=='2')
        {
            system("cls");
            cout<<"Ilosc graczy: "<<endl;
            cout<<"------------------------"<<endl;
            cout<<"1. 8. Graczy"<<endl;
            cout<<"2."<<endl;
            cout<<"3."<<endl;
            cout<<"------------------------"<<endl;
            cout<<'\n';
            cout<<'\n';
            cout<<"4. Wroc"<<endl;

            char w;

            w = getch();

            if (w!='1'&&w!='2'&&w!='3'&&w!='4')
                while(w!='1'&&w!='2'&&w!='3'&&w!='4')
                {
                    cout<<"Co kurwa zle wpisujesz!";
                    cout<<'\n';
                    w = getch();
        }

             system("cls");

             string g[8];
             cout<<"Wpisz nazwy graczy:"<<'\n';
             for(int i=0;i<=7;i++)
                cin>> g[i];

             //Losowanie
             losowanie();

             int dru[8];
             int pkt[8] = {0,0,0,0,0,0,0,0};
             int bramki[8] = {0,0,0,0,0,0,0,0};

             srand(time(NULL));

             for(int i=0;i<=7;i++)
             {
                  int r =(rand()%8);

                    dru[i] = r;
                    for(int j=0;j<i;j++)
                    {

                       if(r==dru[j])
                       {
                       r=(rand()%8);
                       dru[i] = r;
                       j=-1;
                       }
                    }
             }

             cout<<"------------------------"<<endl;
             cout<<"GRUPA A"<<endl;
             cout<<"------------------------"<<endl;

             for(int i=0;i<=7;i+=2)
             {
                 cout<<g[dru[i]]<<endl;
             }

             cout<<'\n';

             cout<<"------------------------"<<endl;
             cout<<"GRUPA B"<<endl;
             cout<<"------------------------"<<endl;
;
             for(int i=0;i<=7;i+=2)
             {
                 cout<<g[dru[i+1]]<<endl;
             }

             getchar(); getchar();

             int goal[2];

             // 1 Kolejka

             for(int i=0;i<=7;i+=4)
             {
                 system("cls");

                 cout<<"1 Kolejka"<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<"Gr.A. "<<g[dru[i]]  <<" - "<< g[dru[i+2]]<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<"Gr.B. "<<g[dru[i+1]]<<" - "<< g[dru[i+3]]<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<"Gole "<<g[dru[i]]  <<": ";
                 cin>>goal[0];
                 cout<<"Gole "<<g[dru[i+2]]<<": ";
                 cin>>goal[1];
                 ktowygral(goal[0],goal[1],pkt[i],pkt[i+2],bramki[i],bramki[i+2]);
                 cout<<"------------------------"<<endl;
                 cout<<"Wynik: "<<g[dru[i]]  <<" - "<< g[dru[i+2]]<<"  "<<goal[0]<<" : "<<goal[1]<<endl;
                 cout<<"------------------------"<<endl;

                 cout<<"Gole "<<g[dru[i+1]]  <<": ";
                 cin>>goal[0];
                 cout<<"Gole "<<g[dru[i+3]]<<": ";
                 cin>>goal[1];
                 ktowygral(goal[0],goal[1],pkt[i+1],pkt[i+3],bramki[i+1],bramki[i+3]);
                 cout<<"------------------------"<<endl;
                 cout<<"Wynik: "<<g[dru[i+1]]  <<" - "<< g[dru[i+3]]<<"  "<<goal[0]<<" : "<<goal[1]<<endl;
                 cout<<"------------------------"<<endl;


                 getchar(); getchar();
             }

             // 2 Kolejka

               for(int i=0;i<=2;i+=2)
             {
                 system("cls");

                 cout<<"2 Kolejka"<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<"Gr.A. "<<g[dru[i]]  <<" - "<< g[dru[i+4]]<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<"Gr.B. "<<g[dru[i+1]]<<" - "<< g[dru[i+5]]<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<"Gole "<<g[dru[i]]  <<": ";
                 cin>>goal[0];
                 cout<<"Gole "<<g[dru[i+4]]<<": ";
                 cin>>goal[1];
                 ktowygral(goal[0],goal[1],pkt[i],pkt[i+4],bramki[i],bramki[i+4]);
                 cout<<"------------------------"<<endl;
                 cout<<"Wynik: "<<g[dru[i]]  <<" - "<< g[dru[i+4]]<<"  "<<goal[0]<<" : "<<goal[1]<<endl;
                 cout<<"------------------------"<<endl;

                 cout<<"Gole "<<g[dru[i+1]]  <<": ";
                 cin>>goal[0];
                 cout<<"Gole "<<g[dru[i+5]]<<": ";
                 cin>>goal[1];
                 ktowygral(goal[0],goal[1],pkt[i+1],pkt[i+5],bramki[i+1],bramki[i+5]);
                 cout<<"------------------------"<<endl;
                 cout<<"Wynik: "<<g[dru[i+1]]  <<" - "<< g[dru[i+5]]<<"  "<<goal[0]<<" : "<<goal[1]<<endl;
                 cout<<"------------------------"<<endl;


                 getchar(); getchar();
             }



             //3 Kolejka

                 system("cls");

                 cout<<"3 Kolejka"<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<"Gr.A. "<<g[dru[0]]  <<" - "<< g[dru[6]]<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<"Gr.B. "<<g[dru[1]]<<" - "<< g[dru[7]]<<endl;
                 cout<<"------------------------"<<endl;
                 //A
                 cout<<"Gole "<<g[dru[0]]  <<": ";
                 cin>>goal[0];
                 cout<<"Gole "<<g[dru[6]]<<": ";
                 cin>>goal[1];
                 ktowygral(goal[0],goal[1],pkt[0],pkt[6],bramki[0],bramki[6]);
                 cout<<"------------------------"<<endl;
                 cout<<"Wynik: "<<g[dru[0]]  <<" - "<< g[dru[6]]<<"  "<<goal[0]<<" : "<<goal[1]<<endl;
                 cout<<"------------------------"<<endl;
                 //B
                 cout<<"Gole "<<g[dru[1]]  <<": ";
                 cin>>goal[0];
                 cout<<"Gole "<<g[dru[7]]<<": ";
                 cin>>goal[1];
                 ktowygral(goal[0],goal[1],pkt[1],pkt[7],bramki[1],bramki[7]);
                 cout<<"------------------------"<<endl;
                 cout<<"Wynik: "<<g[dru[1]]  <<" - "<< g[dru[7]]<<"  "<<goal[0]<<" : "<<goal[1]<<endl;
                 cout<<"------------------------"<<endl;

                 getchar(); getchar();

                 system("cls");

                 cout<<"3 Kolejka"<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<"Gr.A. "<<g[dru[2]]  <<" - "<< g[dru[4]]<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<"Gr.B. "<<g[dru[3]]<<" - "<< g[dru[5]]<<endl;
                 cout<<"------------------------"<<endl;
                 //A
                 cout<<"Gole "<<g[dru[2]]  <<": ";
                 cin>>goal[0];
                 cout<<"Gole "<<g[dru[4]]<<": ";
                 cin>>goal[1];
                 ktowygral(goal[0],goal[1],pkt[2],pkt[4],bramki[2],bramki[4]);
                 cout<<"------------------------"<<endl;
                 cout<<"Wynik: "<<g[dru[2]]  <<" - "<< g[dru[4]]<<"  "<<goal[0]<<" : "<<goal[1]<<endl;
                 cout<<"------------------------"<<endl;
                 //B
                 cout<<"Gole "<<g[dru[3]]  <<": ";
                 cin>>goal[0];
                 cout<<"Gole "<<g[dru[5]]<<": ";
                 cin>>goal[1];
                 ktowygral(goal[0],goal[1],pkt[3],pkt[5],bramki[3],bramki[5]);
                 cout<<"------------------------"<<endl;
                 cout<<"Wynik: "<<g[dru[3]]  <<" - "<< g[dru[5]]<<"  "<<goal[0]<<" : "<<goal[1]<<endl;
                 cout<<"------------------------"<<endl;

                 getchar(); getchar();


            //Wyniki Fazy Grupowej

             system("cls");
             cout<<"------------------------"<<endl;
             cout<<"TABELA GRUPA A"<<endl;
             cout<<"------------------------"<<endl;

             for (int i=0; i<=5; i+=2)
                for (int j=0; j<=5; j+=2)
                {
                    if (pkt[j+2]>pkt[j])
                    {
                        swap(dru[j+2],dru[j]);
                        swap(pkt[j+2],pkt[j]);
                        swap(bramki[j+2],bramki[j]);
                    }

                    else if (pkt[j]==pkt[j+2])
                    {
                        if(bramki[j+2]>bramki[j])
                        {
                        swap(dru[j+2],dru[j]);
                        swap(bramki[j+2],bramki[j]);
                        }

                    }
                }

            cout<<"1. "<<g[dru[0]]<<"      Pkt. "<<pkt[0]<<"  Br. "<<bramki[0]<<endl;
            cout<<"2. "<<g[dru[2]]<<"      Pkt. "<<pkt[2]<<"  Br. "<<bramki[2]<<endl;
            cout<<"------------------------"<<endl;
            cout<<"3. "<<g[dru[4]]<<"      Pkt. "<<pkt[4]<<"  Br. "<<bramki[4]<<endl;
            cout<<"4. "<<g[dru[6]]<<"      Pkt. "<<pkt[6]<<"  Br. "<<bramki[6]<<endl;


             cout<<endl;
             cout<<endl;
             cout<<"------------------------"<<endl;
             cout<<"TABELA GRUPA B"<<endl;
             cout<<"------------------------"<<endl;

             for (int i=1; i<=6; i+=2)
                for (int j=1; j<=6; j+=2)
                {
                    if (pkt[j+2]>pkt[j])
                    {
                        swap(dru[j+2],dru[j]);
                        swap(pkt[j+2],pkt[j]);
                        swap(bramki[j+2],bramki[j]);
                    }

                    else if (pkt[j]==pkt[j+2])
                    {
                        if(bramki[j+2]>bramki[j])
                        {
                        swap(dru[j+2],dru[j]);
                        swap(bramki[j+2],bramki[j]);
                        }

                    }
                }

            cout<<"1. "<<g[dru[1]]<<"      Pkt. "<<pkt[1]<<"  Br. "<<bramki[1]<<endl;
            cout<<"2. "<<g[dru[3]]<<"      Pkt. "<<pkt[3]<<"  Br. "<<bramki[3]<<endl;
            cout<<"------------------------"<<endl;
            cout<<"3. "<<g[dru[5]]<<"      Pkt. "<<pkt[5]<<"  Br. "<<bramki[5]<<endl;
            cout<<"4. "<<g[dru[7]]<<"      Pkt. "<<pkt[7]<<"  Br. "<<bramki[7]<<endl;



            getchar(); getchar();


            //Polfinaly

                system("cls");

                cout<<"Polfinaly: "<<endl;
                cout<<"--------------------"<<endl;
                cout<<endl;


                cout<<g[dru[0]]<<" - "<<g[dru[3]]<<endl;
                cout<<endl;

                cout<<g[dru[1]]<<" - "<<g[dru[2]]<<endl;
                cout<<endl;

                cout<<"--------------------"<<endl;

                getchar(); getchar();


                 int semi[2];

                 system("cls");
                 cout<<"Semi-Finals (1/2)"<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<g[dru[0]]  <<" - "<< g[dru[3]]<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<g[dru[1]]<<" - "<< g[dru[2]]<<endl;
                 cout<<"------------------------"<<endl;


                 //1
                 cout<<"Gole "<<g[dru[0]]  <<": ";
                 cin>>goal[0];
                 cout<<"Gole "<<g[dru[3]]<<": ";
                 cin>>goal[1];
                 cout<<"------------------------"<<endl;

                 if(goal[0]==goal[1])
                 {
                     if((remis(goal[0],goal[1],g[dru[0]],g[dru[3]]))==0)
                        goal[0]+=1;

                     else
                        goal[1]+=1;
                 }

                 cout<<"Wynik: "<<g[dru[0]]  <<" - "<< g[dru[3]]<<"  "<<goal[0]<<" : "<<goal[1]<<endl;
                 cout<<"------------------------"<<endl;

                 if(goal[0]<goal[1])
                 {
                     semi[0]=dru[0];
                     dru[0]=dru[3];
                     dru[3]=semi[0];
                 }


                 //2
                 cout<<"Gole "<<g[dru[1]]  <<": ";
                 cin>>goal[0];
                 cout<<"Gole "<<g[dru[2]]<<": ";
                 cin>>goal[1];
                 cout<<"------------------------"<<endl;

                 if(goal[0]==goal[1])
                 {
                     if((remis(goal[0],goal[1],g[dru[1]],g[dru[2]]))==0)
                        goal[0]+=1;

                     else
                        goal[1]+=1;
                 }

                 cout<<"Wynik: "<<g[dru[1]]  <<" - "<< g[dru[2]]<<"  "<<goal[0]<<" : "<<goal[1]<<endl;
                 cout<<"------------------------"<<endl;

                 if(goal[0]<goal[1])
                 {
                     semi[1]=dru[1];
                     dru[1]=dru[2];
                     dru[2]=semi[1];
                 }

                  getchar(); getchar();


                 //Mecz o 3 miejsce

                 system("cls");
                 cout<<"Mecz o 3 miejsce"<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<g[dru[2]]  <<" - "<< g[dru[3]]<<endl;
                 cout<<"------------------------"<<endl;

                 cout<<"Gole "<<g[dru[2]]<<": ";
                 cin>>goal[0];
                 cout<<"Gole "<<g[dru[3]]<<": ";
                 cin>>goal[1];
                 cout<<"------------------------"<<endl;

                 if(goal[0]==goal[1])
                 {
                     if((remis(goal[0],goal[1],g[dru[2]],g[dru[3]]))==0)
                        goal[0]+=1;

                     else
                        goal[1]+=1;
                 }

                 cout<<"Wynik: "<<g[dru[2]]  <<" - "<< g[dru[3]]<<"  "<<goal[0]<<" : "<<goal[1]<<endl;
                 cout<<"------------------------"<<endl;


                 if(goal[0]<goal[1])
                 {
                     swap(dru[2],dru[3]);
                 }

                 getchar(); getchar();

                 //Final

                 system("cls");
                 cout<<"FINAL!"<<endl;
                 cout<<"------------------------"<<endl;
                 cout<<g[dru[0]]  <<" - "<< g[dru[1]]<<endl;
                 cout<<"------------------------"<<endl;

                 cout<<"Gole "<<g[dru[0]]<<": ";
                 cin>>goal[0];
                 cout<<"Gole "<<g[dru[1]]<<": ";
                 cin>>goal[1];
                 cout<<"------------------------"<<endl;

                 if(goal[0]==goal[1])
                 {
                     if((remis(goal[0],goal[1],g[dru[0]],g[dru[1]]))==0)
                        goal[0]+=1;

                     else
                        goal[1]+=1;
                 }

                 cout<<"Wynik: "<<g[dru[0]]  <<" - "<< g[dru[1]]<<"  "<<goal[0]<<" : "<<goal[1]<<endl;
                 cout<<"------------------------"<<endl;

                 //int finale;

                 if(goal[0]<goal[1])
                 {
                     swap(dru[0],dru[1]);

                     /*finale=dru[0];
                     dru[0]=dru[1];
                     dru[1]=finale;*/
                 }

                 getchar(); getchar();


                //Wyniki

                system("cls");
                cout<<"WYNIKI: "<<endl;
                cout<<"--------------------"<<endl;
                cout<<"[1]. "<<g[dru[0]]<<endl;
                cout<<"--------------------"<<endl;
                cout<<"[2]. "<<g[dru[1]]<<endl;
                cout<<"[3]. "<<g[dru[2]]<<endl;
                cout<<"4. "<<g[dru[3]]<<endl;
                cout<<"--------------------"<<endl;
                cout<<"Grp. "<<g[dru[4]]<<endl;
                cout<<"Grp. "<<g[dru[5]]<<endl;
                cout<<"Grp. "<<g[dru[6]]<<endl;
                cout<<"Grp. "<<g[dru[7]]<<endl;
                cout<<"--------------------"<<endl;




                getchar(); getchar();




        }


    else if(menu=='3')
        return 0;

    return 0;
}
