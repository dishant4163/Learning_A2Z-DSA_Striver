// Asteroid Collision

/* Asteroid Collision_Coding Ninjas -> (  https://shorturl.at/ZpG1v  )


vector<int> collidingAsteroids(vector<int>& asteroids) {
    //Write your code here.
    int n = asteroids.size();
    stack<int> st;

    for(int i=0; i < n; i++) {
        if(asteroids[i] > 0 || st.empty()) st.push(asteroids[i]);
        else {
            while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                st.pop();
            }

            if(!st.empty() && st.top() == abs(asteroids[i])) st.pop();
            else if(st.empty() || st.top() <= 0) st.push(asteroids[i]);
        }
    }

    // Collect results from the stack
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    // The result is in reverse order, so reverse it back
    reverse(ans.begin(), ans.end());
    

    return ans;
}


*/



#include<bits/stdc++.h>
using namespace std;

//OPtimal soln with List
list<int> asteroidsCollide(vector<int>& ast) {
    int n = ast.size();
    //decalring list as a stack (follows => LIFO method)
    list<int> li; //list<int> is used to simulate a stack

    for(int i = 0; i < n; i++) {
        if(ast[i] > 0) li.push_back(ast[i]);
        else {
            while(!li.empty() && li.back() > 0 && li.back() < abs(ast[i])) {
                li.pop_back();
            }

            if(!li.empty() && li.back() == abs(ast[i])) li.pop_back();
            else if (li.empty() || li.back() < 0) li.push_back(ast[i]);
        }
    }

    // otherwise direct return the list
    return li; //if want to return list then function is also retunn in list<int> instead of vector<int>
}





//OPtimal soln with Stack
vector<int> collidingAsteroids(vector<int>& asteroids) {
    int n = asteroids.size(); // Get the number of asteroids
    stack<int> st; // Stack to keep track of remaining asteroids

    for (int i = 0; i < n; i++) {
        // If the asteroid is moving right or the stack is empty, push it onto the stack
        if (asteroids[i] > 0 || st.empty()) {
            st.push(asteroids[i]);
        } else {
            // While there are right-moving asteroids and the current asteroid is left-moving
            while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])) {
                st.pop(); // Destroy right-moving asteroids that are smaller
            }

            // Check for collisions
            if (!st.empty() && st.top() == abs(asteroids[i])) {
                st.pop(); // Both asteroids are equal and destroy each other
            } else if (st.empty() || st.top() <= 0) {
                st.push(asteroids[i]); // No collision or only left-moving asteroids in stack
            }
        }
    }

    // Collect results from the stack
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    // The result is in reverse order, so reverse it back
    reverse(ans.begin(), ans.end());

    return ans; // Return the final state of asteroids
}







int main() {

// OPtimal soln with List(using LiFO)
    vector<int> asteroids = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16};
    list<int> result = asteroidsCollide(asteroids);

    cout << "Remaining asteroids after collisions: ";
    for (int asteroid : result) {
        cout << asteroid << " " ;
    }
    cout << endl;






// OPtimal soln with Stack(using LiFO)
    vector<int> Asteroids = {4, 7, 1, 1, 2, -3, -7, 17, 15, -16, -18};
    vector<int> solve = collidingAsteroids(Asteroids);
    // Print the output
    cout << "Remaining asteroids: ";
    for (int asteroid : solve) {
        cout << asteroid << " ";
    }
    cout << endl;






    return 0;
}

