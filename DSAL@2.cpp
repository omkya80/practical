#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Dictionary
{
  private:
  
  unordered_map<string,string>hashTable;
  
  public:
  
  void insert(const string &key, const string &value)
  {
  
  if(hashTable.find(key) != hashTable.end())
  {
    cout<<"key"<<"'already exists. Updating its value.\n'";
  }
  
  hashTable[key] = value;
  cout<<"Inserted/Updated:("<<key<<","<<value<<")\n";
  
  }
  
  void find(const string &key)
  {
  
    if(hashTable.find(key) != hashTable.end())
    {
      cout<<"found:("<<key<<","<<hashTable[key]<<")\n";
    }
    else
    {
      cout<<"key'"<<key<<"'not found.\n";
    }
  }
  
  void remove(const string &key) 
  {
     if (hashTable.erase(key)) 
     {
       cout << "Key '" << key << "' deleted successfully.\n";
     } 
     else 
     {
	cout << "Key '" << key << "' not found.\n";
     }
  }
  
  void display() 
  {
     if (hashTable.empty()) 
     {
        cout << "The dictionary is empty.\n";
     } 
     else 
     {
        cout << "Current dictionary contents:\n";
        for (const auto &pair : hashTable) 
        {
        cout << "(" << pair.first << ", " << pair.second << ")\n";
        }
    }
  }
};

int main()
{
  Dictionary dict;
  int choice;
  string key, value;
  
  do
  {
    cout<<"\n Dictionary Operation :\n";
    cout<<"\n1.Insert :\n";
    cout<<"\n2.Find :\n";
    cout<<"\n3.Delete :\n";
    cout<<"\n4.Display :\n";
    cout<<"\n5.Exit :\n";
    cout<<"Enter Your Choice:";
    cin>>choice;
    
    switch(choice)
    {
      case 1:
        cout<<"Enter Key";
        cin>>key;
        cout<<"Enter value:";
        cin>>value;
        dict.insert(key,value);
        break;
        
     case 2:
	cout << "Enter key to find: ";
	cin >> key;
	dict.find(key);
	break; 
     case 3:
	cout << "Enter key to delete: ";
	cin >> key;
	dict.remove(key);
	break; 
	
     case 4:
	dict.display();
	break;
     case 5:
	cout << "Exiting program.\n";
	break;
	default:
	cout << "Invalid choice. Please try again.\n";
   }
} while (choice != 5);
return 0;
}

        
 
