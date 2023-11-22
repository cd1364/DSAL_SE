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