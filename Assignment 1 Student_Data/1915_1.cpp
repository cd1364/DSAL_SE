/* 
Name : Daphal Chaitanya Ramdas
Class : SE IT  
Div : A
Batch : A
Roll no. : 1915
Assignment No. 1 : Searching and Sorting
*/

#include<iostream>
#include<string.h>
#include<iomanip>

using namespace std;

int const size = 15 ;

struct student{
    int roll_no;
    string name;
    float sgpa;
   
};

//1
void input(struct student s[]){
    for(int i=0;i<size;i++){
       
        cout<<"\nEnter the Roll number of the student : ";
        cin>>s[i].roll_no;
       
        cout<<"\nEnter the Name of Roll No. "<< s[i].roll_no <<" : ";
        cin>>s[i].name;
       
        cout<<"\nEnter the SGPA of Roll No. "<< s[i].roll_no <<" : ";
        cin>>s[i].sgpa;
       
       
    }
}

//2
void display(struct student list[size]){
   
    cout<<"\n";
     cout<<"---------------------------------------------------\n";
    cout <<left<<setw(10)<<"Sr.No."<<left<<setw(10)<<"Roll No."<<left <<setw(25)<< "Student Name"<<left<<setw(15)<<"SGPA" <<endl;
    cout<<"---------------------------------------------------";
    cout<<"\n";
   
    for(int i=0; i<size; i++){
            cout <<left<<setw(10)<< i+1 <<left<<setw(10)<< list[i].roll_no <<left <<setw(25)<< list[i].name<<left<<setw(15)<<list[i].sgpa <<endl;
    }
}

//3
void bubble_sort (struct student s[]){
    for(int k = 0; k < size; k++){
        for (int j = 0; j < (size - 1); j++){
            if (s[j].roll_no > s[j+1].roll_no){
                struct student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;

            }
        }
    }
    cout << "\n\t\t* Bubble sort : Roll No. *" << endl;
    display(s);
}

//4
void insertion_sort(struct student s[size]){
    for (int a = 1; a < size; a++){
       
        int key = s[a].roll_no;
        string key1 = s[a].name;
        float key2 = s[a].sgpa;
       
        int b = a - 1;
        while((b>=0) && (s[b].name > key1)){
            s[b+1].roll_no = s[b].roll_no;
            s[b+1].name = s[b].name;
            s[b+1].sgpa = s[b].sgpa;
            b = b - 1;

        }
        s[b+1].roll_no = key;
        s[b+1].name = key1;
        s[b+1].sgpa = key2;
    }
    cout << "\n\t\t* Insertion sort : Name *" << endl;
        display(s);
}

//5
void quick_sort(struct student s[], int size, int first, int last){
   
 
     int p, i, j;
    struct student temp;  
   
    p = i = first;
    j = last;

        if(first < last)
            {
                while(i < j){
                    while(s[i].sgpa >=s[p].sgpa && i < last)
                        i++;

                    while(s[j].sgpa < s[p].sgpa)
                        j--;

                    if(i < j){
                        temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }
                }
                temp = s[j];
                s[j] = s[p];
                s[p] = temp;

                quick_sort(s,size,first,j-1);
                quick_sort(s,size, j+1, last);
               
               
            }
            
            
}

//6
// Linear search
void search_sgpa(struct student list[size]){
    float sgpa;
    int z = 0;
   
    cout << "\nEnter SGPA : " ;
    cin >> sgpa;

    cout<<"\n";
     cout<<"--------------------------------------------------------\n";
    cout <<left<<setw(10)<<"Sr.No."<<left<<setw(10)<<"Roll No."<<left <<setw(25)<< "Student Name"<<left<<setw(15)<<"SGPA" <<endl;
    cout<<"--------------------------------------------------------";
    cout<<"\n";

    for (int i = 0; i < size ;i++)
    {
        if ((i<size) && (list[i].sgpa == sgpa))
        {
           
           
            cout <<left<<setw(10)<< i+1 <<left<<setw(10)<< list[i].roll_no <<left <<setw(25)<< list[i].name<<left<<setw(15)<<list[i].sgpa <<endl;            
            continue;
        }
    }   
        
}



//7
int binary_search(struct student s[])
{  

insertion_sort(s);

    string key;

    cout << "\nEnter the Name you want to search : " ;
    cin >> key;

 
    int low = 0;
    int high = size - 1;
   
    while(low <= high){
        int mid = (low + high)/2;

        if (key == s[mid].name){
            return mid;
        }

        else if (key < s[mid].name){
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }
    return -1;

}

void view (struct student list[size], int size){
   
    cout<<"\n";
     cout<<"--------------------------------------------------------\n";
    cout <<left<<setw(10)<<"Sr.No."<<left<<setw(10)<<"Roll No."<<left <<setw(25)<< "Student Name"<<left<<setw(15)<<"SGPA" <<endl;
    cout<<"--------------------------------------------------------";
    cout<<"\n";
   
    for(int j=0; j<size; j++){
            cout <<left<<setw(10)<< j+1 <<left<<setw(10)<< list[j].roll_no <<left <<setw(25)<< list[j].name<<left<<setw(15)<<list[j].sgpa <<endl;
    }
}

int main()
{
    struct student s[size];  //s is name of array
        input(s); //1
           
        display(s); //2
           
    int choice,cont=0;    
    do{
   
        cout<<"\n##### MENU #####"<<endl;
        cout<<"\n1. Bubble sort (To sort Roll Number)\n2. Insertion Sort (To sort Student Name)\n3. Quick Sort (To find Top 10 rank)\n4. Linear Search (To find Students with Same SGPA)\n5. Binary Search (To find Student Name form database)"<<endl;
       
       
        cout<<"\nSelect the Operation : ";
        cin >> choice;

       
        switch(choice)
        {
       
        case 1:
            bubble_sort(s);
            break;
           
        case 2:
            insertion_sort(s);
            break;

        case 3:
            cout << "\n\t\t* Quick sort : SGPA *" << endl;
            quick_sort(s,size,0,size-1);
            view(s,10);
            break;

       
        case 4:
            search_sgpa(s);
            break;
       
        case 5:
            {int result = binary_search(s); //7
                if (result == -1){
                    cout << "Data not found!!\n";
                }
               
                else{
                    cout << "Name is found at Sr. no. : " << result+1 << endl;
                }
            }
            break;
       
        default:
            cout<<"Invalid Input !!"<<endl;
        }
        cout << "\nEnter 0 to EXIT or Enter 1 to RETURN MENU : " ;
        cin >> cont ;
            if(cont!=1){
                cout<<"Thank you !!";
                break;
            }

    }while(cont<=5);
   
}

/*
Enter the Roll number of the student : 1915

Enter the Name of Roll No. 1915 : CHAITANYA

Enter the SGPA of Roll No. 1915 : 8.82

Enter the Roll number of the student : 1913

Enter the Name of Roll No. 1913 : KEDAR

Enter the SGPA of Roll No. 1913 : 8.40

Enter the Roll number of the student : 1925

Enter the Name of Roll No. 1925 : OMKAR

Enter the SGPA of Roll No. 1925 : 9.16

Enter the Roll number of the student : 1927

Enter the Name of Roll No. 1927 : KAUSTUBH

Enter the SGPA of Roll No. 1927 : 8.82

Enter the Roll number of the student : 1918

Enter the Name of Roll No. 1918 : AVNEESH

Enter the SGPA of Roll No. 1918 : 9.68

Enter the Roll number of the student : 1908

Enter the Name of Roll No. 1908 : TANMAY

Enter the SGPA of Roll No. 1908 : 9.55

Enter the Roll number of the student : 1930

Enter the Name of Roll No. 1930 : AJAY

Enter the SGPA of Roll No. 1930 : 9.69

Enter the Roll number of the student : 1971

Enter the Name of Roll No. 1971 : VIJAY

Enter the SGPA of Roll No. 1971 : 8.70

Enter the Roll number of the student : 1901

Enter the Name of Roll No. 1901 : RAMESH

Enter the SGPA of Roll No. 1901 : 9.7

Enter the Roll number of the student : 1910

Enter the Name of Roll No. 1910 : SACHIN

Enter the SGPA of Roll No. 1910 : 8.89

Enter the Roll number of the student : 1917

Enter the Name of Roll No. 1917 : AMEY

Enter the SGPA of Roll No. 1917 : 8.82

Enter the Roll number of the student : 1963

Enter the Name of Roll No. 1963 : DINESH

Enter the SGPA of Roll No. 1963 : 8.00

Enter the Roll number of the student : 1906

Enter the Name of Roll No. 1906 : MAYUR

Enter the SGPA of Roll No. 1906 : 9.99

Enter the Roll number of the student : 1955

Enter the Name of Roll No. 1955 : ROHIT

Enter the SGPA of Roll No. 1955 : 9.43

Enter the Roll number of the student : 1935

Enter the Name of Roll No. 1935 : VIRAT

Enter the SGPA of Roll No. 1935 : 9.12

---------------------------------------------------
Sr.No.    Roll No.  Student Name             SGPA
---------------------------------------------------
1         1915      CHAITANYA                8.82
2         1913      KEDAR                    8.4
3         1925      OMKAR                    9.16
4         1927      KAUSTUBH                 8.82
5         1918      AVNEESH                  9.68
6         1908      TANMAY                   9.55
7         1930      AJAY                     9.69
8         1971      VIJAY                    8.7
9         1901      RAMESH                   9.7
10        1910      SACHIN                   8.89
11        1917      AMEY                     8.82
12        1963      DINESH                   8
13        1906      MAYUR                    9.99
14        1955      ROHIT                    9.43
15        1935      VIRAT                    9.12

##### MENU #####

1. Bubble sort (To sort Roll Number)
2. Insertion Sort (To sort Student Name)
3. Quick Sort (To find Top 10 rank)
4. Linear Search (To find Students with Same SGPA)
5. Binary Search (To find Student Name form database)

Select the Operation : 1

                * Bubble sort : Roll No. *

---------------------------------------------------
Sr.No.    Roll No.  Student Name             SGPA
---------------------------------------------------
1         1901      RAMESH                   9.7
2         1906      MAYUR                    9.99
3         1908      TANMAY                   9.55
4         1910      SACHIN                   8.89
5         1913      KEDAR                    8.4
6         1915      CHAITANYA                8.82
7         1917      AMEY                     8.82
8         1918      AVNEESH                  9.68
9         1925      OMKAR                    9.16
10        1927      KAUSTUBH                 8.82
11        1930      AJAY                     9.69
12        1935      VIRAT                    9.12
13        1955      ROHIT                    9.43
14        1963      DINESH                   8
15        1971      VIJAY                    8.7

Enter 0 to EXIT or Enter 1 to RETURN MENU : 1

##### MENU #####

1. Bubble sort (To sort Roll Number)
2. Insertion Sort (To sort Student Name)
3. Quick Sort (To find Top 10 rank)
4. Linear Search (To find Students with Same SGPA)
5. Binary Search (To find Student Name form database)

Select the Operation : 2

                * Insertion sort : Name *

---------------------------------------------------
Sr.No.    Roll No.  Student Name             SGPA
---------------------------------------------------
1         1930      AJAY                     9.69
2         1917      AMEY                     8.82
3         1918      AVNEESH                  9.68
4         1915      CHAITANYA                8.82
5         1963      DINESH                   8
6         1927      KAUSTUBH                 8.82
7         1913      KEDAR                    8.4
8         1906      MAYUR                    9.99
9         1925      OMKAR                    9.16
10        1901      RAMESH                   9.7
11        1955      ROHIT                    9.43
12        1910      SACHIN                   8.89
13        1908      TANMAY                   9.55
14        1971      VIJAY                    8.7
15        1935      VIRAT                    9.12

Enter 0 to EXIT or Enter 1 to RETURN MENU : 1

##### MENU #####

1. Bubble sort (To sort Roll Number)
2. Insertion Sort (To sort Student Name)
3. Quick Sort (To find Top 10 rank)
4. Linear Search (To find Students with Same SGPA)
5. Binary Search (To find Student Name form database)

Select the Operation : 3

                * Quick sort : SGPA *

--------------------------------------------------------
Sr.No.    Roll No.  Student Name             SGPA
--------------------------------------------------------
1         1906      MAYUR                    9.99
2         1901      RAMESH                   9.7
3         1930      AJAY                     9.69
4         1918      AVNEESH                  9.68
5         1908      TANMAY                   9.55
6         1955      ROHIT                    9.43
7         1925      OMKAR                    9.16
8         1935      VIRAT                    9.12
9         1910      SACHIN                   8.89
10        1927      KAUSTUBH                 8.82

Enter 0 to EXIT or Enter 1 to RETURN MENU : 1

##### MENU #####

1. Bubble sort (To sort Roll Number)
2. Insertion Sort (To sort Student Name)
3. Quick Sort (To find Top 10 rank)
4. Linear Search (To find Students with Same SGPA)
5. Binary Search (To find Student Name form database)

Select the Operation : 4

Enter SGPA : 8.82

--------------------------------------------------------
Sr.No.    Roll No.  Student Name             SGPA
--------------------------------------------------------
10        1927      KAUSTUBH                 8.82
11        1917      AMEY                     8.82
12        1915      CHAITANYA                8.82

Enter 0 to EXIT or Enter 1 to RETURN MENU : 1

##### MENU #####

1. Bubble sort (To sort Roll Number)
2. Insertion Sort (To sort Student Name)
3. Quick Sort (To find Top 10 rank)
4. Linear Search (To find Students with Same SGPA)
5. Binary Search (To find Student Name form database)

Select the Operation : 5

                * Insertion sort : Name *

---------------------------------------------------
Sr.No.    Roll No.  Student Name             SGPA
---------------------------------------------------
1         1930      AJAY                     9.69
2         1917      AMEY                     8.82
3         1918      AVNEESH                  9.68
4         1915      CHAITANYA                8.82
5         1963      DINESH                   8
6         1927      KAUSTUBH                 8.82
7         1913      KEDAR                    8.4
8         1906      MAYUR                    9.99
9         1925      OMKAR                    9.16
10        1901      RAMESH                   9.7
11        1955      ROHIT                    9.43
12        1910      SACHIN                   8.89
13        1908      TANMAY                   9.55
14        1971      VIJAY                    8.7
15        1935      VIRAT                    9.12

Enter the Name you want to search : MAYUR
Name is found at Sr. no. : 8

Enter 0 to EXIT or Enter 1 to RETURN MENU : 1

##### MENU #####

1. Bubble sort (To sort Roll Number)
2. Insertion Sort (To sort Student Name)
3. Quick Sort (To find Top 10 rank)
4. Linear Search (To find Students with Same SGPA)
5. Binary Search (To find Student Name form database)

Select the Operation : 5

                * Insertion sort : Name *

---------------------------------------------------
Sr.No.    Roll No.  Student Name             SGPA
---------------------------------------------------
1         1930      AJAY                     9.69
2         1917      AMEY                     8.82
3         1918      AVNEESH                  9.68
4         1915      CHAITANYA                8.82
5         1963      DINESH                   8
6         1927      KAUSTUBH                 8.82
7         1913      KEDAR                    8.4
8         1906      MAYUR                    9.99
9         1925      OMKAR                    9.16
10        1901      RAMESH                   9.7
11        1955      ROHIT                    9.43
12        1910      SACHIN                   8.89
13        1908      TANMAY                   9.55
14        1971      VIJAY                    8.7
15        1935      VIRAT                    9.12

Enter the Name you want to search : RAHUL
Data not found!!

Enter 0 to EXIT or Enter 1 to RETURN MENU : 1

##### MENU #####

1. Bubble sort (To sort Roll Number)
2. Insertion Sort (To sort Student Name)
3. Quick Sort (To find Top 10 rank)
4. Linear Search (To find Students with Same SGPA)
5. Binary Search (To find Student Name form database)

Select the Operation : 6
Invalid Input !!

Enter 0 to EXIT or Enter 1 to RETURN MENU : 0
Thank you !!
 */