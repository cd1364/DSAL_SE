/*
Name : Daphal Chaitanya Ramdas
Class : SE IT
Div : A
Batch : A
Roll no. : 25015
Assignment No. 8 : Graph: Shortest Path Algorithm
*/

#include <iostream>
#define max 20
using namespace std;

class graph
{
    int g[max][max], n, c[max], ch[max], min_dist, client_dist, visit_dist;
    char v[max], str[max][max], min_path[max], client_path[max], visit_path[max];

public:
    graph(int m)
    {
        n = m;
        visit_dist = 0;
        client_dist = 0;
        min_dist = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                g[i][j] = 0;
    }

    void accept_v();
    void accept_e();
    void display();
    void dj_init(int);
    void dj_init();
    void dj(char, char, int);
    void dj_client(char, char);
};

void graph::accept_v()
{
    int i = 0;
    cout << "\nName of Cities...";
    while (i < n)
    {
        cout << "\nEnter Name of City : [" << i + 1 << "] :: ";
        cin >> v[i];
        i++;
    }
}

void graph::accept_e()
{
    char ch;
    char v1, v2;
    int i, j, cst;

    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
        {
            if (i == j)
            {
                g[i][j] = 0;
                continue;
            }
            else
                cout << "\n\tRent between cities [" << v[i] << "][" << v[j] << "] :  ";
            cin >> cst;
            g[i][j] = g[j][i] = cst;
        }
}

void graph::display()
{
    int i, j;
    i = 0;

    cout << "\n";
    while (i < n)
    {
        cout << "\t" << v[i];
        i++;
    }

    for (i = 0; i < n; i++)
    {
        cout << "\n"
             << v[i];
        for (j = 0; j < n; j++)
        {
            cout << "\t" << g[i][j];
        }
    }
}

void graph::dj_init()
{
    int i, j;

    for (i = 0; i < n; i++)
    {
        c[i] = 9999;
        ch[i] = 0;
        for (j = 0; j < n; j++)
        {
            str[i][j] = '-';
        }
    }
}

void graph::dj_init(int i)
{
    for (int j = 0; j < n; j++)
    {
        str[i][j] = '-';
    }
}
void graph::dj(char s, char d, int f)
{
    dj_init();
    int i, j, l, k, flag, min = 999, cst = 0;
    i = 0;
    while (v[i] != s)
        i++;
    c[i] = 0;

    k = 0;
    str[i][k] = v[i];
    do
    {
        ch[i] = 1;
        min = 999;
        for (j = 0; j < n; j++)
        {
            flag = 0;
            cst = c[i] + g[i][j];
            if (g[i][j] != 0 && i != j && cst < c[j])
            {
                k = 0;
                c[j] = cst;
                dj_init(j);
                while (flag == 0)
                {
                    str[j][k] = str[i][k];
                    k++;
                    if (str[i][k] == '-')
                        flag = 1;
                }
                str[j][k] = v[j];
            }
        }

        for (l = 0; l < n; l++)
        {
            if (c[l] <= min && ch[l] == 0)
            {
                min = c[l];
                i = l;
            }
        }

    } while (v[i] != d);

    j = 0;
    if (f == 0)
        min_dist = c[i];
    else
        client_dist = c[i];
    if (f == 0)
        cout << "\nMinimum Distance : " << c[i] << "\nShortest Path : ";
    while (str[i][j] != '-')
    {
        if (f == 0)
            min_path[j] = str[i][j];
        if (f == 0)
            cout << " " << str[i][j];
        j++;
    }
    min_path[j] = '\0';
    cout << "\n\n";
    j = 1;
    while (str[i][j] != '-' && f == 1)
    {
        client_path[j - 1] = str[i][j];
        j++;
    }
    client_path[j - 1] = '\0';
    cout << "\nShortest Distance\n\n";
    for (int h = 0; h < n; h++)
    {
        cout << "\n " << v[h] << " " << c[h] << "\n\t";
        for (int m = 0; m < n; m++)
        {
            cout << " " << str[h][m];
        }
    }
}

int main()
{
    int n, ch;
    char v1, v2;
    cout << "\nEnter Number of Cities :: ";
    cin >> n;

    graph g(n);

    do
    {
        cout << "\nEnter Your Choice :: \n1.Accept City Name\n2.Accept Routes\n3.Display\n4.Shortest Distance\n5.Exit\nInput-->> ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            g.accept_v();
            break;

        case 2:
            g.accept_e();
            break;

        case 3:
            g.display();
            break;

        case 4:
            cout << "\nEnter Start Point :: ";
            cin >> v1;
            cout << "\nEnter Destination :: ";
            cin >> v2;

            g.dj(v1, v2, 0);

            break;
        }
    } while (ch != 5);
    return 0;
}

/*
OUTPUT :

Enter Number of Cities :: 5

Enter Your Choice ::
1.Accept City Name
2.Accept Routes
3.Display
4.Shortest Distance
5.Exit
Input-->> 1

Name of Cities...
Enter Name of City : [1] :: x

Enter Name of City : [2] :: y

Enter Name of City : [3] :: z

Enter Name of City : [4] :: u

Enter Name of City : [5] :: v

Enter Your Choice ::
1.Accept City Name
2.Accept Routes
3.Display
4.Shortest Distance
5.Exit
Input-->> 2

        Rent between cities [x][y] :  9

        Rent between cities [x][z] :  8

        Rent between cities [x][u] :  2

        Rent between cities [x][v] :  64

        Rent between cities [y][z] :  5

        Rent between cities [y][u] :  78

        Rent between cities [y][v] :  34

        Rent between cities [z][u] :  15

        Rent between cities [z][v] :  68

        Rent between cities [u][v] :  79

Enter Your Choice ::
1.Accept City Name
2.Accept Routes
3.Display
4.Shortest Distance
5.Exit
Input-->> 3

        x       y       z       u       v
x       0       9       8       2       64
y       9       0       5       78      34
z       8       5       0       15      68
u       2       78      15      0       79
v       64      34      68      79      0
Enter Your Choice ::
1.Accept City Name
2.Accept Routes
3.Display
4.Shortest Distance
5.Exit
Input-->> 4

Enter Start Point :: x

Enter Destination :: v

Minimum Distance : 43
Shortest Path :  x y v


Shortest Distance


 x 0
         x - - - -
 y 9
         x y - - -
 z 8
         x z - - -
 u 2
         x u - - -
 v 43
         x y v - -
Enter Your Choice ::
1.Accept City Name
2.Accept Routes
3.Display
4.Shortest Distance
5.Exit
Input-->> 5
*/