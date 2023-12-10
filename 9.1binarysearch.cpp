#include<iostream>
#include<string.h>
using namespace std;
typedef struct student
    {
        int roll_num;
        char name [20];
        float marks;
    }stud;
        void create(stud s[20],int n);
        void display(stud s[20],int n);
        int bsearch(stud s[20], char x[20],int low,int high);
int main()
    {
        stud s[20];
        int ch,n,key,result;
        char x[20];
        do
        {
            cout<<"\n 1) Create Student Database ";
            cout<<"\n 2) Display Student Records ";
            
            cout<<"\n 3) Binary search ";
            cout<<"\n 4) Exit ";
            cout<<"\n Enetr Your Choice:=";
            cin>>ch;
            switch(ch)
            {
                case 1: cout<<"\n Enter The Number Of Records:=";
                cin>>n;
                create(s,n);
                break;
                case 2: display(s,n);
                break;
                
                case 3:
                cout<<"\n Enter the name of student which u want to search:=";
                cin>>x;
                
                result=bsearch(s,x,0,(n-1));
                if(result==-1)
                {
                    cout<<" \n name is present! \n";
                }else
                {
                    cout<<" \n The student is not present :\t" << s[result].name;
                }
                    break;
                    case 4:return 0;
                    default:cout<<"\n Invalid choice !! Please enter again."<<endl;
            }
        }while(ch!=4);
        
    }
void create(stud s[20],int n)
    {
        int i;
        for(i=0;i<n;i++)
        {
            cout<<"\n Enter the roll number:=";
            cin>>s[i].roll_num;
            cout<<"\n Enter the Name:=";
            cin>>s[i].name;
            cout<<"\n Enter the marks:=";
            cin>>s[i].marks;
        }
    }
void display(stud s[20],int n)
    {
        int i;
        cout<<"\n"<< "\t"<< "Roll No"<< "\t";
        cout<<" Name" <<"\t"<< "Marks";
        for(i=0;i<n;i++)
        { 
            cout<<"\n";
            cout<<"\t "<< s[i].roll_num<<"\t ";
            cout<<s[i].name<<"\t "<<s[i].marks;
        }
    }
int bsearch(stud s[20], char x[20],int low,int high)
    {
        int mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(strcmp(x,s[mid].name)==0)
            {
                return mid;
            }
            else if(strcmp(x,s[mid].name)<0)
                {
                    high=mid-1;
                }
                else
                    {
                        low=mid+1;
                    }
        }
        return -1;
    }