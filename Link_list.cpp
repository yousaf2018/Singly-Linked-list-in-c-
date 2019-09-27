#include <iostream>
using namespace std;
class Node
{
private:
  int data;
  Node *Next;
public:
  void set_data(int);
  int get_data();
  void set_Next(Node*);
  Node* get_Next();
  Node(int data)
  {
    this->data=data;
    Next=NULL;
  }
};
void Node::set_data(int data)
{
  this->data=data;
}
int Node::get_data()
{
  return data;
}
void Node::set_Next(Node* ptr)
{
  Next=ptr;
}
Node* Node::get_Next()
{
  return Next;
}
class Link_list
{
private:
  Node *first;
public:
  Link_list()
  {
    first=NULL;
  }
  void add_node_end_list(int);
  void add_node_start_list(int);
  void remove_node_start_list();
  void remove_node_end_list();
  void remove_node_for_value(int);
  void remove_node_for_index(int);
  void add_node_at_index(int);
  int get_value_at_given_index(int);
  int find_value_return_index(int);
  void find_length_of_list();
  void display_list();
};
void Link_list::add_node_end_list(int input)
{

  Node *temp=new Node(input);
  if(first==NULL)
  {
    first=temp;
  }
  else
  {
    Node *temp2;
    temp2=first;
    while(temp2->get_Next()!=NULL)
    {
      temp2=temp2->get_Next();
    }
    temp2->set_Next(temp);
  }
}
void Link_list::add_node_start_list(int input)
{
  Node *temp2=new Node(input);
  Node *temp;
  temp=first;
  if(first==NULL)
  {
    first=temp2;
  }
  else
  {
   temp2->set_Next(temp);
   first=temp2;
  }
}
void Link_list::remove_node_start_list()
{
  first=first->get_Next();
}
void Link_list::display_list()
{
  Node *temp;
  temp=first;
  while(temp!=NULL)
  {
    cout << temp->get_data() << endl;
    temp=temp->get_Next();
  }
}
void Link_list::remove_node_end_list()
{
  Node *temp;
  temp=first;
  if(first->get_Next()==NULL)
  {
    first=NULL;
  }
  else
  {
  while(temp->get_Next()->get_Next()!=NULL)
  {
    temp=temp->get_Next();
  }
  temp->set_Next(NULL);
  }
}
void Link_list::remove_node_for_value(int input)
{
  Node *temp;
  temp=first;
  if(temp->get_data()==input)//for to remove first node
  {
    temp=temp->get_Next();
    first=temp;
  }
  else
  {
    while(temp!=NULL)
    {
    if(temp->get_Next()->get_Next()==NULL&&temp->get_Next()->get_data()==input)//For to remove last node
    {
      temp->set_Next(NULL);
    }
    else if(temp->get_Next()->get_data()==input&&temp->get_Next()->get_Next()!=NULL)//for to remove middle node
    {
     Node *temp2;
     temp2=temp;
     temp2=temp2->get_Next()->get_Next();
     temp->set_Next(temp2);
     break;
    }
    temp=temp->get_Next();
    }
  }
}
void Link_list::remove_node_for_index(int input)
{
   Node *temp;
   int counter=0,a;
   temp=first;
   while(temp!=NULL)
   {
     temp=temp->get_Next();
     counter++;
   }
   Node *temp3;
   temp3=first;
   for(a=0;a<=counter;a++)
   {

     if(input==0)
     {
       remove_node_start_list();
       break;
     }
     else if(input==counter-1)
     {
       remove_node_end_list();
       break;
     }
     else if(a==input-1)
     {
       Node *temp2;
       temp2=temp3;
       temp2=temp2->get_Next()->get_Next();
       temp3->set_Next(temp2);
       break;
     }
     temp3=temp3->get_Next();
   }
}
void Link_list::add_node_at_index(int input)
{
  Node *temp;
  int counter=0,a;
  temp=first;
  while(temp!=NULL)
  {
    temp=temp->get_Next();
    counter++;
  }
  Node *temp3;
  temp3=first;
  for(a=0;a<=counter;a++)
  {

    if(input<=0)
    {
      int data;
      cout << "Enter value to add start of your list\n";
      cin >> data;
      add_node_start_list(data);
      break;
    }
    else if(input>=counter-1)
    {
      int data;
      cout << "Enter value for to add end of your list\n";
      cin >> data;
      add_node_end_list(data);
      break;
    }
    else if(a==input-1)
    {
      int value;
      cout << "Enter value for node at provided index\n";
      cin >> value;
      Node *temp=new Node(value);
      Node *temp2=temp3;
      Node *temp4=temp3->get_Next();
      temp2->set_Next(temp);
      temp2->get_Next()->set_Next(temp4);

      break;
    }
    temp3=temp3->get_Next();
  }
}
int Link_list::get_value_at_given_index(int input)
{
  Node *temp;
  int counter=0,a;
  temp=first;
  while(temp!=NULL)
  {
    temp=temp->get_Next();
    counter++;
  }
  Node *temp3;
  temp3=first;
  for(a=0;a<=input;a++)
  {

    if(input==0)
    {
      return temp3->get_data();
      break;
    }
    else if(a==input)
    {
      cout << "Value at index " << temp3->get_data() << endl;
      break;
    }
    temp3=temp3->get_Next();
  }
}
int Link_list::find_value_return_index(int input)
{
  int check=0,counter=1;
  Node *temp;
  temp=first;
  if(temp->get_data()==input)//for first node
  {
    return 0;
  }
  else
  {
    while(temp!=NULL)
    {
    if(temp->get_Next()->get_Next()==NULL&&temp->get_Next()->get_data()==input)//For to find last node
    {
      return counter;
      break;
    }
    else if(temp->get_Next()->get_data()==input&&temp->get_Next()->get_Next()!=NULL)//for find middle node
    {
     return counter;
     break;
    }
    else if(temp->get_Next()->get_Next()==NULL&&temp->get_Next()->get_data()!=input)
    {
      return -1;
      break;
    }
    temp=temp->get_Next();
    counter++;
    }
  }
}
void Link_list::find_length_of_list()
{
  Node *temp=first;
  int counter=0;
  while(temp!=NULL)
  {
    counter++;
    temp=temp->get_Next();
  }
  cout << "Total length of your list " << counter << endl;
}
int main()
{
  Link_list list;
  int a,input,choice;
  while(true)
  {
  cout << "Here is menue for list to perform functions\n";
  cout << "Enter 1 to add node end of list\n";
  cout << "Enter 2 to add node start of list\n";
  cout << "Enter 3 remove node start of your list\n";
  cout << "Enter 4 remove node end of your list\n";
  cout << "Enter 5 remove node with your input value\n";
  cout << "Enter 6 remove node with index position\n";
  cout << "Enter 7 add value in your list at provided index\n";
  cout << "Enter 8 Return value from provided index position\n";
  cout << "Enter 9 Find value in your list with index position\n";
  cout << "Enter 10 Calculate size of your list\n";
  cout << "Enter 11 Display all values in your list\n";
  cin >> input;
  if(input==1)
  {
    int data;
    cout << "Enter value for to add end of your list\n";
    cin >> data;
    list.add_node_end_list(data);
  }
  else if(input==2)
  {
    int data;
    cout << "Enter value to add start of your list\n";
    cin >> data;
    list.add_node_start_list(data);
  }
  else if(input==3)
  {
    list.remove_node_start_list();
  }
  else if(input==4)
  {
    list.remove_node_end_list();
  }
  else if(input==5)
  {
    cout << "Enter value you want to remove from list\n";
    int data;
    cin >> data;
    list.remove_node_for_value(data);
  }
  else if(input==6)
  {
    int data;
    cout << "Enter index from 0 to end of list to remove value of node\n";
    cin >> data;
    list.remove_node_for_index(data);
  }
  else if(input==7)
  {
    int data;
    cout << "Enter index to add value in your list\n";
    cin >> data;
    list.add_node_at_index(data);
  }
  else if(input==8)
  {
    int data,check;
    cout << "Enter index to find value in that index\n";
    cin >> data;
    check=list.get_value_at_given_index(data);
    cout << "Value at index " << data << " is " << check << endl;
  }
  else if(input==9)
  {
    cout << "Enter value to find its index position\n";
    int check,data;
    cin >> data;
    check=list.find_value_return_index(data);
    if(check!=-1)
    {
      cout << "Value " << data << " is stored at index " << check << endl;
    }
    else if(check==-1)
    {
      cout << "No match is found for your input value\n";
    }
  }
  else if(input==10)
  {
    list.find_length_of_list();
  }
  else if(input==11)
  {
    list.display_list();
  }
  cout << "Enter 1 for to continue use functions for list or 0 to stop\n";
  cin >> choice;
  if(choice!=1)
  {
    break;
  }
 }
}
