/*//(Design a Browser History_Coding Ninja)-> https://tinyurl.com/4mj3n87y   



class Node {
    public:
        string data;
        Node* next;
        Node* back;
        Node() : data(0), next(nullptr), back(nullptr){};
        Node(string x) : data(x), next(nullptr), back(nullptr) {}
        Node(string x, Node* next, Node* random) : data(x), next(next), back(random) {}
};


class Browser
{
    Node* currentPage;
    public:
    
    Browser(string &homepage)
    {
        // Write you code here
        currentPage = new Node(homepage);
    }

    void visit(string &url)
    {
        // Write you code here
        Node* newNode = new Node(url);
        currentPage->next = newNode;
        newNode->back = currentPage;
        currentPage=newNode;
    }

    string back(int steps)
    {
        // Write you code here
        while(steps) {
            if(currentPage->back) {
                currentPage = currentPage->back;
            } else{
                break;
            }

            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps)
    {
        // Write you code here
        while(steps) {
            if (currentPage->next) {
                currentPage = currentPage->next;
            } else{
                break;
            }
            steps--;
        }
        return currentPage->data;
    }
};



*/

#include<bits/stdc++.h>
using namespace std;

/* Soln 1: OPtimal (using Doubly LL)  
   Approach:-
1. First Create a class Node have attributes as a link, Previous (Denoting the previous Node), Next (Denoting Next Node) 

2. Node Made class BrowserHistory have attribute as Node Current where Current denotes the website in which you are currently 

3. The constructor BrowserHistory(string homepage) initializes the object with the homepage of the browser set Current Node as current.link=homepage 

4. We have a visit(String url) function to visit a URL from the current page: when visit(String url) is called it will a made new node have a link as URL and Previous  as Current and Next as null then we will change the pointer of Current.next to the new node that we made then just do one thing make new Node as Current Node

5. For Function forward(int step) we will travel in a forward direction in the list and if attend the end of the string before completing all steps then we return the last link and if  all steps are complete then we will return Node.link that travelling 

6. For Function back(int step) we will do similar to forward just that we travel in the opposite direction



   Complexity Analysis:-
  # TC: O(N)
  # SC: O(K)
*/

class Node {
    public:
        string data;
        Node* next;
        Node* back;
        Node() : data(0), next(nullptr), back(nullptr){};
        Node(string x) : data(x), next(nullptr), back(nullptr) {}
        Node(string x, Node* next, Node* random) : data(x), next(next), back(random) {}
};


class Browser
{
    Node* currentPage;
    public:
    
    Browser(string &homepage)
    {
        // Write you code here
        currentPage = new Node(homepage);
    }

    void visit(string url)
    {
        // Write you code here
        Node* newNode = new Node(url);
        currentPage->next = newNode;
        newNode->back = currentPage;
        currentPage=newNode;
    }

    string back(int steps)
    {
        // Write you code here
        while(steps) {
            if(currentPage->back) {
                currentPage = currentPage->back;
            } else{
                break;
            }

            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps)
    {
        // Write you code here
        while(steps) {
            if (currentPage->next) {
                currentPage = currentPage->next;
            } else{
                break;
            }
            steps--;
        }
        return currentPage->data;
    }
};










int main() {



//Soln 1: Optimal 
// Input case :
    string homepage = "gfg.org";
    // Initialise the object of Browser History
    Browser obj(homepage);
    string url = "google.com";
    obj.visit(url);
    url = "facebook.com";
    obj.visit(url);
    url = "youtube.com";
    obj.visit(url);
    cout << obj.back(1) << endl;
    cout << obj.back(1) << endl;
    cout << obj.forward(1) << endl;
    obj.visit("linkedin.com");
    cout << obj.forward(2) << endl;
    cout << obj.back(2) << endl;
    cout << obj.back(7) << endl;





    return 0;
}


