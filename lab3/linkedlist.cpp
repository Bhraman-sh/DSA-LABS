#include<iostream>

class NODE
{
public:
    //Necessary operation;

    NODE(int value)
    {
       this->data=value;
       this->next=NULL;
    }
    ~NODE()
    {
        //delete this;    
    }

    NODE * addAtBeg(int data)
    {
        NODE *q;
        
        q = new NODE(data);
        q->next = this;

        return q;
    }

    void append(int data)
    {
        NODE *p = this;
        NODE *q;

        while(p->next != NULL)
        {
            p = p->next;
        }
        q = new NODE(data);
        p->next = q;
        q->next = NULL;
    }

    NODE * addBefore(int value, int data)
    {
        NODE *p, *q;
        p = this;
        
        if(this->data == value) //If the specified node is the first node
        {
            q = new NODE(data);
            q->next = this;
            return q;
        }

        while(p->next->data != value)
        {
            p = p->next;
            if (p->next == NULL)
            {
                std::cout<<"Specified value not found!! "<<std::endl;
                return this;
            }
        }

        q = new NODE(data);
        q->next = p->next;
        p->next = q;

        return this;
    }

    void addAfter(int value, int data)
    {
        NODE *p, *q;
        p = this;

        while(p->data != value)
        {
            p = p->next;
        }
         q = new NODE(data);
         q->next = p->next;
         p->next = q;
    }

    void deleteAtEnd()
    {
        NODE *p = this;
        NODE *q;

        while(p->next != NULL)
        {
            q = p;
            p = p->next;
        }
        if (q != NULL)
    {
        // More than one node in the list
        delete p;
        q->next = NULL;
    }
    else
    {
        // Only one node in the list, so delete it
        delete this;
    }
    }

    NODE * deleteAtBeg()
    {
        NODE *p;
        p = this->next;
        delete(this);
        return p;
    }

    void deleteAfter(int value)
    {
        NODE *p, *q;
        p = this;
        while(p->data != value)
        {
            p = p->next;
            if(p->next ==  NULL)
            {
                std::cout<<"Specified value not found or there specified value is the last element of the list"<<std::endl;
                return;
            }
        }
        q = p->next;
        p->next = q->next;   
        delete q;
    }

    void display()
    {
        NODE *p = this;
        while(p != NULL)
        {
            std::cout<<p->data<<' ';
            p = p->next;
        }
        std::cout<<std::endl;
    }
    //Data and pointer

private:
    int data;
    NODE *next;
};

int main()
{
    NODE *n1 = new NODE(3);
    n1->append(5);
    n1->append(37);
    n1->append(69);

    std::cout<<"Node After adding at end "<<std::endl;
    n1->display();

    n1 = n1->addBefore(3,12);
    n1 = n1->addBefore(34, 13);

    std::cout<<"NOde after adding before certain value "<<std::endl;
    n1->display();

    n1 = n1->addAtBeg(39);
    std::cout<<"Node after adding at beginnning "<<std::endl;
    n1->display();

    std::cout<<"The node on the list are: "<<std::endl;
    n1->display();

    n1->deleteAtEnd();

    std::cout<<"The node after deletion form end: "<<std::endl;
    n1->display();

    n1 = n1->deleteAtBeg();
    std::cout<<"The node after deletion from front: "<<std::endl;
    n1->display();

    n1->deleteAfter(3);
    std::cout<<"The node after deleting after value 5: "<<std::endl;
    n1->display();

    return 0;
}