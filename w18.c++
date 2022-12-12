#include<iostream>
#include<cstdlib>
using namespace std;
class node 
{
    public:
    int value;
    node *pre;
    node *next;
     node()
     {
        pre=NULL;
        next = NULL;
        value = 0;
     }
};
class DDL
{
    node *head;
    public:
    DDL()
    {
        head = NULL;
    }
    void Insert_(int v)
    {
        node *temp = new node();
        temp->value= v;
        if(head ==NULL)
        {
            head = temp;
        }
        else {
            node *s = head;
            while(s->next!=NULL)
            {
                s=s->next;
            }
            s->next=temp;
            temp->pre=s;
            // s->next=temp;
        }
    }
    void Print_()
    {
      
        node *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->value<<" <=> ";
            temp=temp->next;
        }
    }
    void Insert_Begin(int v)
    {
        node *temp = new  node();
        temp->value=v;
        if(head == NULL)
        {
            head = temp;
        }
        else {
            
            temp->next=head;
            head->pre = temp;
            head=temp;
        }
        
    }
    void Insert_Middle(int v,int n)
    {
        node *temp = new node();
        temp ->value = v;
        if(n==1)
        {
            temp->next=head;
            head->pre=temp;
            head = temp ;
        }
        else {
            node *r = head ;
            while(n>1)
            {
                n--;
                if(r->next!=NULL)
                {
                    r=r->next;
                }
                else {
                    cout<<"position not found\n ";
                    return ;
                }
                
            }
              temp->next=r->next;
                r->next=temp;
                temp->pre=r;
        }
    }
    void Delete_(int n)
    {
        node *temp = head ;
        if(n==1)
        {
            temp=temp->next;
            head->pre=NULL;
            head=temp;
           
        }
        else {
            node *s= head;

            while(n>1)
            {
                n--;
                if(s->next!=NULL)
                s=s->next;
                else {
                    cout<<"Position not found \n";
                    return;
                }
            } 
            temp=s->next;
            s->pre->next=temp;
            s->next=temp;
            
        }
    }
    void Search_(int n)
    {
        int count =0;
        node *temp =head;
        while (temp!=NULL)
        {
            count++;
            if(temp->value== n)
            {
                cout<<"Element Founded \n";
                return;
            }
            temp=temp->next;
        }
        cout<<"Element Not Founded \n";
        
    }
};
int main()
{
    DDL l;
    int choice;
   while(1)
   {
     cout<<"\n==========================================================\n";
     cout<<"Enter 1 to insert value \n";
     cout<<"Enter 2 to for insert begin \n";
     cout<<"Enter 3 for insert middle \n";
     cout<<"Enter 4 delete from give index \n";
     cout<<"Enter 5 for search any element \n";
     cout<<"Enter 6 for print all element \n";
     cout<<"Enter 7 for Exit \n";
     cout<<"\n";
     cout<<"Enter your choice ";
     cin>>choice;
     switch(choice)
     {
        int r,s;
        case 1:
                cout<<"Enter value ";
                cin>>r;
                l.Insert_(r);
                break;
        case 2:
                  cout<<"Enter value ";
                  cin>>r;
                  l.Insert_Begin(r);
                  break;
        case 3:
                  cout<<"Enter value \n";
                  cin>>r;
                  cout<<"ok enter index\n";
                  cin>>s;
                 l.Insert_Middle(r,s);
                 break;
        case 4:
                  cout<<"Enter value ";
                cin>>r;
                l.Delete_(r);
                break;
        case 5:
                  cout<<"Enter value ";
                cin>>r;
                l.Search_(r);
                break;
        case 6:
               l.Print_();
               break;
        case 7:
                exit(0);
            default:
            cout<<"Enter a valid number : ";
            break;
     }
     
   }

}
