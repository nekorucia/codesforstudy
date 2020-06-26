#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INT 999999
#define CITIES 90

double highway[CITIES+1][CITIES+1]; 
int visit[CITIES+1];
double dist[CITIES+1];
// int index[CITIES+1]; //������ ��带 �����ϴ� �迭�� ����� ������ ���� �����Ұ� 
int start,goal; 

void INPUT(int start,int goal) // highway �迭 �ʱ�ȭ. ���ͽ�Ʈ�� �˰��� ������ ���� ������ �׷����� 2���� �迭 91x91 �� �����ϰ� ���� ������ ����ġ (�Ÿ�)���� �־���. 
{
    int i,j;

    for(i=0;i<91;i++)
        for(j=0;j<91;j++)
        {
            if(i!=j)
                highway[i][j]=MAX_INT;
            else if(i==j)
                highway[i][j]=0;
        }
    
    highway[17][12]=20.1; highway[17][18]=74.1; highway[17][19]=105.8; highway[18][20]=106.4; highway[18][11]=43.7; highway[18][10]=76.4; highway[19][20]=59.9; highway[19][80]=70.5; highway[20][76]=66.7; highway[20][68]=47.8; highway[20][77]=39.1; highway[21][9]=76.6; highway[21][68]=99.9; highway[21][22]=34; highway[21][61]=33.3; highway[22][69]=95.1; highway[22][23]=40.2; highway[22][24]=24.8; highway[22][61]=90.4; highway[23][30]=38; highway[23][26]=23; highway[24][59]=85.5; highway[24][26]=58.7; highway[24][28]=51.4; highway[25][30]=26.4; highway[25][31]=31.5; highway[25][36]=82.05; highway[25][26]=13; highway[26][27]=15; highway[27][28]=9.92; highway[27][29]=15.4; highway[28][29]=10.71; highway[28][44]=55.95; highway[29][42]=48.89; highway[30][8]=43.5; highway[30][31]=18.5; highway[31][32]=50.6; highway[32][33]=12.2; highway[32][35]=30.4; highway[33][8]=54.9; highway[33][34]=34.5; highway[34][36]=22.61; highway[35][14]=12.84; highway[35][36]=8.6; highway[36][37]=8; highway[36][41]=39.3; highway[36][38]=16.4; highway[37][38]=8.62; highway[38][39]=13.25; highway[39][40]=2.14; highway[40][41]=11.34; highway[40][15]=15.3; highway[41][42]=12.4; highway[42][43]=47.49; highway[43][44]=69.7; highway[43][6]=47.89; highway[43][46]=62.47; highway[44][45]=49.73; highway[44][51]=30.1; highway[45][47]=42.5; highway[45][46]=52.64; highway[45][52]=59.51; highway[46][47]=74.2; highway[47][48]=66.3; highway[47][49]=25.1; highway[48][13]=26; highway[48][50]=48.2; highway[49][50]=17.2; highway[49][53]=82.5; highway[50][55]=77.81; highway[51][52]=75.7; highway[51][60]=72.64; highway[52][53]=7.6; highway[53][54]=12.72; highway[54][66]=47.04; highway[54][56]=34.38; highway[55][66]=61.36; highway[55][67]=112.46; highway[56][57]=8.43; highway[56][60]=13.28; highway[57][58]=8.22; highway[57][66]=28.56; highway[58][61]=18.5; highway[58][59]=9.6; highway[59][60]=8.2; highway[61][62]=3.3; highway[62][63]=16.3; highway[62][65]=28.5; highway[63][64]=15.84; highway[63][65]=12.1; highway[64][71]=31.1; highway[64][66]=35; highway[65][70]=24.9; highway[66][67]=63.02; highway[67][73]=36.63; highway[68][69]=41.6; highway[69][77]=41.01; highway[69][70]=27.6; highway[70][71]=34.19; highway[70][75]=33.81; highway[71][72]=15.7; highway[71][82]=30.1; highway[72][73]=8; highway[72][74]=16.49; highway[73][83]=39.9; highway[73][90]=37.27; highway[75][82]=46.5; highway[75][76]=2.38; highway[75][77]=15.07; highway[76][78]=4.94; highway[78][79]=4.94; highway[79][80]=7.62; highway[80][81]=25.3; highway[80][87]=53.46; highway[81][16]=9.11; highway[81][90]=21.08; highway[81][82]=13.08; highway[82][83]=44.7;  highway[83][84]=19.96; highway[84][85]=19.96; highway[85][88]=26.71; highway[86][88]=7.86; highway[87][88]=6.86;

    for(i=0;i<91;i++)
        for(j=0;j<91;j++)
        {
            if(highway[i][j]!=MAX_INT)
                highway[j][i]=highway[i][j];
            else if(highway[i][j]==MAX_INT)
                highway[i][j]=highway[j][i];
        }

    for(i=0;i<91;i++)
        dist[i]=MAX_INT; // ���ͽ�Ʈ�� �˰��� ���� �Ÿ� �迭 �ʱ�ȭ. 
}

void DIKSTRA(int start) // ���ͽ�Ʈ�� �˰��� �Լ� 
{
    int i,j; 
    double min;
    int v;

    dist[start]=0; 

    for(i=0;i<91;i++)
    {
        min=MAX_INT;
        for(j=0;j<91;j++)
        {
            if(visit[j]==0&&min>dist[j])
            {
                min=dist[j];
                v=j; 
            }
        }
        visit[v]=1;

        for(j=0;j<91;j++)
        {
            if(dist[j]>dist[v]+highway[v][j]&&highway[v][j]!=MAX_INT)
                dist[j]=dist[v]+highway[v][j];
        }
    }
}

int CITYTOKEY(char* cityname)
{
    int i=1;

    char* nodes[] = {"��õ","����","����","����","�׸�","�뿵","����","����","����","��ô","����","����","�׸�","�λ�","����","����","���","����","��õ","����","�ȵ�","����","����","��õ","���뱸","��ȣ","����","���","��ǳ","ȭ��","��õ","�Ⱦ�","���","����","���","�뵿","����","����","����","����","â��","����","����","�Ծ�","����","��õ","���","����","�强","��â","���","����","�ͻ�","���","����õ","������","����","ȸ��","���","�곻","û��","����","����","õ��","��â","����","����","��õ","����","���","�ȼ�","����","������","������","ȣ��","����","����","��Ɽ��","���","�ϳ�","�Ǳ�","�Ű�","��â","����","���׽ŵ���","�Ϸ�","������","�����","����","����"};
    
    for(i=1;i<91;i++)
    {
        if(strcmp(cityname,nodes[i-1])==0)
            break;
        else if(strcmp(cityname,nodes[i-1])!=0)
            continue;
    }

    if(i>90)
    {
        printf("�ش� ���ð� �������� �ʽ��ϴ�.\n");
        return -1;
    }

    return i;
}

int main(void)
{
    char city_name[15];
    clock_t time_start, time_end; 
    
    time_start=clock();

    printf("����� �Է� : ");
    scanf("%s",city_name);
    start = CITYTOKEY(city_name); // ����� �̸��� ������ key�� ������ start ������ ����
    if(start==-1) {return -1;}

    printf("������ �Է� : ");
    scanf("%s",city_name);
    goal = CITYTOKEY(city_name); // ������ �̸��� ������ key�� ������ goal ������ ���� 
    if(goal==-1) {return -1;}

    INPUT(start,goal); // ������� �������� key ���� ����

    DIKSTRA(start);
    if(dist[goal]==MAX_INT)
    {
    printf("��ΰ� �������� �ʽ��ϴ�. \n");
    return -1;
    }
    
    printf("�ּ� �Ÿ� : %f \n",dist[goal]);

    time_end=clock();

    printf("�����ð� : %f \n",(double)(time_end - time_start)/CLOCKS_PER_SEC);

    return 0;
}