//LinkedListImplementation.cpp
#include<iostream>  //for input and output operations
using namespace std; //std is a standard C++ library which is allows you to use objects and functions from std library
 
// Node class to represent link list,ahd have 3 member variables row,col,data
class Node
{
    public:
    int row; //To store row index
    int col; //To store col index
    int data; //To store data index
    Node *next;  //To point the next node in the list
};
 
// Create_new_node function in the linked list
void create_new_node(Node **p, int row_index,int col_index, int x) //**p is a pointer to a pointer,and three parameters row_index,col_index and x value
{
    Node *temp = *p;
    Node *r;
     
    if (temp == NULL) // If link list is empty then 
    {
     // create first node and assign value.
        temp = new Node();
        temp->row = row_index;
        temp->col = col_index;
        temp->data = x;
        temp->next = NULL;
        *p = temp;
    }
     
    else    // If link list is already created
    {
         // then append newly created node
        while (temp->next != NULL)   
            temp = temp->next;
             
        r = new Node();
        r->row = row_index;
        r->col = col_index;
        r->data = x;
        r->next = NULL;
        temp->next = r;
    }
}
 


void headList(Node *start)  // Function head contents of linked list
{
    // starting from start
    Node *ptr = start;
    cout << "row:    "; //Display the row index
    while (ptr != NULL)
    {
        cout << ptr->row << " ";
        ptr = ptr->next;
    }
    cout << endl;
    cout << "column: "; //Display the column index
 
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->col << " "; 
        ptr = ptr->next;
    }
    cout << endl;
    cout << "Value:  "; //Display the Value of the matrix
    ptr = start;
     
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
 
int main()
{     
    // 4x5 sparse matrix 
    int sparseMatrix[4][5] = { { 0 , 0 , 3 , 0 , 4 },
                               { 0 , 0 , 5 , 7 , 0 },
                               { 0 , 0 , 0 , 0 , 0 },
                               { 0 , 2 , 6 , 0 , 0 } };
     
    // Creating head/first node of list as NULL
    Node *first = NULL;
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
             // Pass only those values which 
            // are non - zero
            if (sparseMatrix[i][j] != 0)
            {
                create_new_node(&first, i, j,sparseMatrix[i][j]);
            }                   
        }
    }
    headList(first);
    cout << endl;
    return 0;
}