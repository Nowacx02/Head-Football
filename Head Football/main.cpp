#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <ctime>
#include <string>

using namespace std;

int mecz (string team1, string team2, int &gol1, int &gol2)
{

                system("cls");


                cout<<"----------------------"<<endl;
                cout<<"Mecz "<<team1<<" - "<<team2<<endl;
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


int main()
{
    system("cls");

    cout << "Menu" << endl;
    cout << "------------------" << endl;
    cout << "1.Turniej Play-Off" << endl;
    cout << "2.Exit" << endl;

    char menu;

    menu = getch();

    if (menu!='1'&&menu!='2')
        while(menu!='1'&&menu!='2')
        {
            cout<<"Co kurwa zle wpisujesz!";
            cout<<'\n';
            menu = getch();
        }

    if(menu=='2')
        return 0;


    if(menu=='1')
    {
        system("cls");
        cout<<"Ilosc graczy: "<<endl;
        cout<<"------------------------"<<endl;
        cout<<"1. 4 Graczy"<<endl;
        cout<<"2. 8 Graczy"<<endl;
        cout<<"3. 16 Graczy"<<endl;
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
             /*system("cls");
             cout<<"Losowanie..."<<endl;
             Sleep(500);
             system("cls");
             cout<<"Losowanie.."<<endl;
             Sleep(500);
             system("cls");
             cout<<"Losowanie."<<endl;
             Sleep(500);
             system("cls");*/

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


             cout<<g[wyl[0]]<<" - "<<g[wyl[1]]<<endl;
             cout<<g[wyl[2]]<<" - "<<g[wyl[3]]<<endl;
             cout<<g[wyl[4]]<<" - "<<g[wyl[5]]<<endl;
             cout<<g[wyl[6]]<<" - "<<g[wyl[7]]<<endl;

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
                int wynik14[4];
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
                    wynik14[j]=wyl[i];

                else if(gol[i+1]>gol[i])
                    wynik14[j]=wyl[i+1];


                j++;
                getchar(); getchar();
                }



                system("cls");
                cout<<'\n';
                cout<<"Wyniki meczow 1/4"<<endl;
                cout<<"--------------------"<<endl;

                for(int i=0;i<=7;i+=2)
                {
                    cout<<'\n';
                    cout<<g[wyl[i]]<<" - "<<g[wyl[i+1]]<<"  "<<gol[i]<<" : "<<gol[i+1]<<endl;
                }

                getchar(); getchar();

                //Mecze Polfinalowe

                system("cls");

                cout<<"Mecze Polfinalowe: "<<endl;
                cout<<"--------------------"<<endl;
                cout<<endl;


                for(int i=0;i<=3;i+=2)
                {
                   cout<<g[wynik14[i]]<<" - "<<g[wynik14[i+1]]<<endl;
                   cout<<endl;
                }

                getchar(); getchar();

                int gole[4];
                int wynik12[2];
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
                    wynik12[j]=wynik14[i];

                    else if(gole[i+1]>gole[i])
                    wynik12[j]=wynik14[i+1];


                j++;
                getchar(); getchar();
                }


                system("cls");
                cout<<'\n';
                cout<<"Wyniki meczow 1/2"<<endl;
                cout<<"--------------------"<<endl;

                for(int i=0;i<=3;i+=2)
                {
                    cout<<'\n';
                    cout<<g[wynik14[i]]<<" - "<<g[wynik14[i+1]]<<"  "<<gole[i]<<" : "<<gole[i+1]<<endl;
                }

                getchar(); getchar();

                //Finał

                system("cls");

                cout<<"FINAL: "<<endl;
                cout<<"--------------------"<<endl;
                cout<<endl;

                cout<<g[wynik12[0]]<<" - "<<g[wynik12[1]]<<endl;

                getchar(); getchar();

                int goll[2];
                int finale;


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
                    finale=wynik12[i];

                    else if(goll[i+1]>goll[i])
                    finale=wynik12[i+1];

                }


                cout<<endl;
                cout<<"ZWYCIEZCA: "<<g[finale]<<endl;






                     }
                     break;
     }

    }


    return 0;
}
