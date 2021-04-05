/*
Given a database with user names.
Each time a new user wants to register, he sends to the system a request with his name.
If such a name does not exist in the system database, it is inserted into the database.
and the user gets confirming the successful registration.
If the name already exists in the system database, the system makes up a new user name,
sends it to the user as a prompt Numbers, starting with 1, are appended one after another to
name (name1, name2..) and so on. Print all user names with their corresponding database names.
*/

#include <bits/stdc++.h>
using namespace std;

// this insert_usernames_in_database function will print all user names with their corresponding database names
void insert_usernames_in_database(vector < string >user_names)
{
    map < string , int > user_entry;
    int size_of_username = user_names.size();
    for(int i = 0; i < size_of_username; i++)
    {
        if(user_entry.find(user_names[i]) == user_entry.end())
        {
            cout << "The User name is unique: ";
            cout << user_names[i] << endl;
            user_entry[user_names[i]]++;
        }
        else if(user_entry.find(user_names[i]) != user_entry.end())
        {
            cout << "The User name is not unique: ";
            cout << user_names[i] << user_entry[user_names[i]] << endl;
            user_entry[user_names[i]]++;

        }
    }
}

int main()
{
    cout << "Enter the number of User Names : \n";
    int Number;
    cin >> Number;
    vector < string > user_names;
    cout << "Enter user names:\n";
    for (int i = 0; i < Number; i++)
    {
	    string name;
	    cin >> name;
	    user_names.push_back(name);
    }
    insert_usernames_in_database(user_names);
}

/*
Standard Input and Output

Enter the number of User Names :
8
Enter user names:
karim
rahim
khan
bhab
gssoc
gssoc
karim
rahim
The User name is unique: karim
The User name is unique: rahim
The User name is unique: khan
The User name is unique: bhab
The User name is unique: gssoc
The User name is not unique: gssoc1
The User name is not unique: karim1
The User name is not unique: rahim1

Time Complexity : O( logN )
Space Complexity : O(N)

*/
