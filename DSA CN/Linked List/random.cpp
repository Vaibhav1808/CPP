#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};
Node* takeInput(){
    int data;
    cin >> data;

    Node* head = NULL;
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
        }
        else{
            Node* temp = head;
            while(temp -> next != NULL){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
        cin >> data;
    }
    return head;
}

Node* takeInputBetter(){
    int data;
    cin >> data;

    Node* head = NULL;
    Node* tail = NULL;
    while(data != -1){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = tail -> next;
        }
        cin >> data;
        }
    return head;
}

void printLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int length(Node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head -> next;
    }
    return count;
}

void printIthNode(Node *head, int i)
{
    //Write your code here
    int count = 0;
    while(head != NULL){
        count++;
        if(count == i+1){
            cout << head -> data;
        }
        head = head -> next;
    }
}

int length(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp -> next;
    }
    return count;
}

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
    if(head == NULL){
        return head;
    }

    if(pos == 0){
        Node* temp = head;
        head = head -> next;
        temp -> next = NULL;
        delete temp;
    }
    else if(pos >= length(head)){
        return head;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;
        int count = 0;
        while(count < pos){
            count++;
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
    }
    return head;
}

int lengthRec(Node *head) {
    // Write your code here
    if(head == NULL){
        return 0;
    }
	return length(head -> next) + 1;
}

Node* insertNode(Node *head, int i, int data) {
	// Write your code here
    if(head == NULL){
        if(i = 0){
            Node* newNode = new Node(data);
            return newNode;
        }
        return head;
    }
    Node* newNode = new Node(data);
    if(i == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    head -> next = insertNode(head-> next, i-1, data);
    return head;
}

Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if(head == NULL){
        return NULL;
    }
    if(pos == 0){
        head = head->next;
        return head;
    }
    head->next = deleteNodeRec(head->next,pos-1);
    return head;
}

int findNode(Node *head, int n){
    // Write your code here.
    int pos = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == n){
            return pos;
            break;
        }
        else{
            pos++;
            temp = temp -> next;
        }
    }
    return -1;
}

Node *removeDuplicates(Node *head)
{
    Node* temp = head;
	if(head == NULL){
        return head;
    }
    
    while(temp -> next != NULL){
        if(temp -> data == temp -> next -> data){
            temp -> next = temp -> next -> next;
        }
        else{
            temp = temp -> next;
        }
    }
    return head;
}

Node *removeDuplicatesUnsorted(Node *head)
{
    // Write your code here
    if(head == NULL){
        return head;
    }
    Node* temp1 = head;
    while(temp1 != NULL){
        Node* temp2 = head -> next;
        while(temp2 != NULL){
            if(temp1 -> next != NULL && (temp1 -> data == temp2 -> data)){
                Node* waste = temp2;
                temp2 = temp2 -> next;
                delete(waste);
                
            }
            else{
                temp2 = temp2 -> next;
            }
        }
        temp1 = temp1 -> next;
    }
}

void printReverse(Node *head)
{
    if(head == NULL){
        return;
    }
    printReverse(head -> next);
    cout << head-> data << " ";
}

Node *midPoint(Node *head)
{
    if(head == NULL){
        return head;
    }
    
    Node* slow = head;
    Node* fast = head -> next;
    
    
    if(head != NULL){
        while(fast != NULL && fast -> next != NULL){
             slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
 {
    if(head1 == NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }
    Node *fh=NULL,*ft=NULL; 
    while(head1!=NULL && head2!=NULL){
        if(head1->data < head2->data){ 
            if(fh==NULL){ 
                fh=head1;
                ft=head1;
            } 
            else {
                ft->next=head1;
                ft=head1;
            }
            head1=head1->next;
        }
        else {
            if(fh==NULL){ 
                fh=head2;
                ft=head2;
            }
            else {
                ft->next=head2;
                ft=head2;
            }
            head2=head2->next;
        }
    }
    if(head1!=NULL)
        ft->next=head1;
    if(head2!=NULL)
        ft->next=head2;
    return fh;
}

Node* sortList012(Node *head)
{
    // Write your code here.
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0){
            count0++;
        }
        else if(temp -> data == 1){
            count1++;
        }
        else{
            count2++;
        }
        temp = temp -> next;
    }
    temp = head;
    while(temp != NULL){
        if(count0 != 0){
            temp -> data = 0;
            count0--;
        }
        else if(count1 != 0){
            temp -> data = 1;
            count1--;
        }
        else if(count2 != 0){
            temp -> data = 2;
            count2--;
        }
        temp = temp -> next;
    }
    return head;
}

bool checkPalindrome(vector<int> v){
    int n = v.size();
    int s = 0;
    int e = n-1;

    while(s <= e){
        if(v[s] != v[e]){
            return 0;
            s++;
            e--;
        }
        return 1;
    }
}

bool isPalindrome(Node* head){
    vector<int> v;
    Node* temp = head;

    while(temp != NULL){
        v.push_back(temp -> data);
        temp = temp -> next;
    }

    return checkPalindrome(v);
}

// Node* reverse(Node* head){
//     Node* curr = head;
//     Node* prev = NULL;
//     Node* next = NULL;

//     while(curr != NULL){
//         next = curr -> next;
//         curr -> next = prev;
//         prev = curr;
//         curr = next;
//     }
//     return prev;
// }
// void insertatTail(Node* &head, Node* &tail, int val){
//     Node* temp = new Node(val);
//     // empty list
//     if(head == NULL){
//         head = temp;
//         tail = temp;
//         return;
//     }
//     else{
//         tail -> next = temp;
//         tail = temp;
//     }
// }
// Node* add(Node* first, Node* second){
//     int carry = 0;
//     Node* ansHead = NULL;
//     Node* ansTail = NULL;

//     while(first != NULL and second != NULL){
//         int sum = carry + first -> data + second -> data;
//         int digit = sum % 10;
//         Node* temp = new Node(digit);

//         insertatTail(ansHead, ansTail, digit);

//         carry = sum / 10;
//         first = first -> next;
//         second = second -> next;
//     }
// }

// Node* addtwoLL(Node* first, Node* second){
//     // step 1 reverse both LL 
//     reverse(first);
//     reverse(second);

//     // step 2 add them
//     Node* ans = add(first, second);
//     ans = reverse(ans);
//     return ans;
// }

Node* findmid(Node* head){
    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL and fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

Node* merge(Node* left, Node* right){
    if(left == NULL){
        return right;
    }
    if(right == NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL and right != NULL){
        if(left -> data <= right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while(right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    ans = ans -> next;
    return ans;
}

Node* mergesort(Node* head){
    // base case
    if(head == NULL or head -> next == NULL){
        return head;
    }

    // break LL in two halves after finding mid
    Node* mid = findmid(head);
    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;

    // recursive calls to sort both the halves
    left = mergesort(left);
    right = mergesort(right);

    // merge both halves
    Node* result = merge(left, right);

    return result;
}

int main(){
    // Node* n1 = new Node(10);
    // Node* n2 = new Node(20);
    // Node* n3 = new Node(30);
    // Node* n4 = new Node(-12);
    // Node* head = n1;
    // printLL(head);
    Node* head = takeInputBetter();
    printLL(head);
    cout << endl;
    cout << length(head);
    return 0;
}