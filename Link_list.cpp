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
  void add_node_end_list();
  void add_node_start_list();
  void remove_node_start_list();
  void remove_node_end_list();
  void remove_node_for_value();
  void remove_node_for_index();
  void add_node_at_index();
  void get_value_at_given_index();
  void find_value_return_index();
  void find_length_of_list();
  void display_list();
};
void Link_list::add_node_end_list()
{
  int input;
  cout << "Enter value for to add end of your list\n";
  cin >> input;
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
void Link_list::add_node_start_list()
{
  int input;
  cout << "Enter value to add start of your list\n";
  cin >> input;
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
void Link_list::remove_node_for_value()
{
  cout << "Enter value you want to remove from list\n";
  int input;
  cin >> input;
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
void Link_list::remove_node_for_index()
{
   Node *temp;
   int counter=0,input,a;
   cout << "Enter index from 0 to end of list to remove value of node\n";
   cin >> input;
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
void Link_list::add_node_at_index()
{
  Node *temp;
  int counter=0,input,a;
  cout << "Enter index to add value in your list\n";
  cin >> input;
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
      add_node_start_list();
      break;
    }
    else if(input>=counter-1)
    {
      add_node_end_list();
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
void Link_list::get_value_at_given_index()
{
  Node *temp;
  int counter=0,input,a;
  cout << "Enter index to find value in that index\n";
  cin >> input;
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
      cout << "Value at index " << temp3->get_data() << endl;
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
void Link_list::find_value_return_index()
{
  cout << "Enter value to find its index position\n";
  int input,check=0,counter=1;
  cin >> input;
  Node *temp;
  temp=first;
  if(temp->get_data()==input)//for first node
  {
    cout << "Index position 0" << endl;
  }
  else
  {
    while(temp!=NULL)
    {
    if(temp->get_Next()->get_Next()==NULL&&temp->get_Next()->get_data()==input)//For to find last node
    {
      cout << "Index position " << counter << endl;
      break;
    }
    else if(temp->get_Next()->get_data()==input&&temp->get_Next()->get_Next()!=NULL)//for find middle node
    {
     cout << "Index position " << counter << endl;
     break;
    }
    if(temp->get_Next()->get_Next()==NULL&&temp->get_Next()->get_data()!=input)//for print no match
    {
      cout << "There is no match in your list\n";
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
  int a;
  for(a=0;a<5;a++)
  list.add_node_end_list();
  //list.add_node_start_list();
  //list.remove_node_start_list();
  //list.remove_node_end_list();
  //list.remove_node_for_value();
  //list.remove_node_for_index();
  //list.add_node_at_index();
  //list.get_value_at_given_index();
  //list.find_value_return_index();
  list.find_length_of_list();
  list.display_list();
}
