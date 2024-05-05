#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Member{
	private:
		string Name,item_author,item;
		int ID,item_id,item_year;
	public:
		Member(){
			Name = item_author = "";
			ID = item_id = item_year = 0;
		}
		void borrow_item(int user_id){
			cout<<"Enter the ID: ";
			cin>>item_id;
			ifstream IFile;
			IFile.open("item.txt",ios::in | ios::out);
			while(!IFile.eof()){
				IFile >> item >> item_id >> item_year >>item_author;
				if(item_id == item_id){
					IFile.close();
					break;
				}
			}
			ofstream OFile;
			OFile.open("Borrow_data.txt",ios::app);
			OFile << user_id <<" "<< item_id << endl;
			cout<<"You Have successfully borrowed "<<endl;
		}
		void return_item(){
			int user_id,item_id;
			int temp_U_id,temp_i_id;
			cout<<"Enter the User ID: ";
			cin>>user_id;
			cout<<"Enter the Item ID";
			cin>>item_id;
			ifstream IFile;
			IFile.open("Borrow_data.txt",ios::in | ios::out);
			ofstream OFile;
			OFile.open("Return_data.txt",ios::out);
			while(!IFile.eof()){
				IFile >> temp_U_id >> temp_i_id;
				if (temp_U_id != user_id || temp_i_id != item_id)
				 OFile << temp_U_id << " " <<temp_i_id << endl;
			}
			IFile.close();
			OFile.close();
			cout<<"Item has been Returned" << endl;
			}		
};

class RegisteredUser{
	protected:
		string Name;
		string Password,Department;
		int ID;
	public:
	void Registered(){
		Name="";
		Password="";
	}
	void setName(){
		cout<<"Enter Your Name: ";
		cin>>Name;
	}
	string getName(){
		return Name;
	}
	void setID(){
		cout<<"Enter Your ID: ";
		cin>>ID;
	}
	int getID(){
		return ID;
	}
	void setPassword(){
		cout<<"Enter Your Password: ";
		cin>>Password;
	}
	string getPassword(){
		return Password;
	}
	void setDepartment(){
		cout<<"Enter your Department";
		cin>>Department;
	}
	string getDepartment(){
		return Department;
	}
	void displaydetails() {
	   cout<<"Detail:"<<endl;
	   cout<<"ID = "<<ID<<endl;
       cout<<"Name = "<<Name<<endl;
       cout<<"Password = "<<Password<<endl;
    }
};
class FacultyUser : public RegisteredUser
{
	private:
		string Course;
	public:
		FacultyUser(){
			Course="";
		}
		void setCourse(){
			cout<<"Enter your Course:"<<endl;
			cin>>Course;
		}
		string getCourse(){
			return Course;
		}
		void write_member_data(){
			ofstream OFile;
			OFile.open("Faculty_member.txt",ios::app);
			OFile << ID <<" "<< Name <<" "<< Password <<" "<< Course << Department << endl;
			OFile.close();
		}
		bool check_member_data(int id_check,string pass_check){
			bool status=false;
			ifstream IFile;
			IFile.open("Faculty_member.txt", ios::in | ios::out);
			while(!IFile.eof())
			{
			IFile >> ID >> Name >> Password >> Course ;
			if((pass_check==Password) && (id_check==ID) )
			{
				cout<<"You have Logged in: "<<endl;
				status=true;
				break;
			}
			else if (id_check != ID){
        		cout<<"Invalid ID "<<endl;
        		break;}
      		else if (pass_check != Password){
        		cout<<"Invalid Password "<<endl;
        		break;}
        	IFile.close();
		   }
		   return status;
		}		
};

class StudentUser : public RegisteredUser{
private:
    string Degree;
public:
    string getDegree(){
    	return Degree;	}
	void setDegree(){
		cout<<"Enter the Degree: "<<endl;
		cin>> Degree;
	}
	void write_member_data(){
			ofstream OFile;
			OFile.open("Student_member.txt",ios::app);
			OFile << ID <<" "<< Name <<" "<< Password <<" "<<Degree << " " << Department << endl;
			OFile.close();
	}
	bool check_member_data(int id_check,string pass_check){
			bool status=false;
			ifstream IFile;
			IFile.open("Student_member.txt", ios::in | ios::out);
			while(!IFile.eof())
			{
			IFile >> ID >> Name >> Password >> Degree ;
			if((pass_check==Password) && (id_check==ID) ){
				cout<<"You have Logged in: "<<endl;
				status=true;
				break;
			}
			else if (id_check != ID){
        		cout<<"Invalid ID "<<endl;
        		break;}
      		else if (pass_check != Password){
        		cout<<"Invalid Password "<<endl;
        		break;}
        	IFile.close();
		   }
		   return status;
		}
};

class Items{
	private:
	int linecount;
	string line;
	public:
		void Item(){
			linecount=0;
			line="";
		}
		void addItem(int Item_year,int Item_id,string Item,string Item_author){
			ofstream OFile;
			OFile.open("Item.txt",ios :: app);
			OFile << Item <<" "<<Item_id<<" "<<Item_author<<" "<<Item_year<<endl;
			OFile.close();
			cout<<"Item has been added successfully!"<<endl;
		}
		void removeItem(int item_id){		
			ifstream IFile("Item.txt");
			while(getline(IFile,line))
			{
				linecount++;
				if(linecount==item_id)
				break;
			}
			if(line=="")
				cout<<"No item detected\n";
			else
				cout<<"Item detected successfully\n";
			ifstream Fin("item.txt");
			ofstream Fout("temp.txt");
			int count=1;
			while(getline(Fin,line)){
				if(count!=item_id)
				Fout << line <<endl;
				count++;
			}
			remove("Item.txt");
			rename("temp.txt","Item.txt");
			Fin.close();
			Fout.close();
		}
		void printdetails(int item_id){
			ifstream IFile;
			IFile.open("Iteam.txt");
			while(getline(IFile,line)){
				linecount++;
				if(linecount == item_id)
				break;
			}
			if(line=="")
				cout<<"No Item Found: "<<endl;
			else
			cout<<"Item found successfully.\nDetails of the item are\n "<<line<<endl;
		}
};

class Book : public Items {
protected:
    string author,title;
    int year,id;
public:
	void setauthor() {
        cout << "Enter the author: ";
        cin>>author;}
    void setyear() {
        cout << "Enter the year: ";
        cin >> year;}
    void settitle(){
        cout << "Enter the title: ";
        
        
        cin>> title;}
    void setid() {
        cout << "Enter the ID: ";
        cin >> id;}
	int getid(){
		return id;}
    string getauthor() {
        return author;}
    int getyear() {
        return year;}
    string gettitle(){
        return title;}
};

void old_member(){
	int id,choice,opt;
	string pass;
	bool Degree,course;
	Items item;
	Book book;
	Member member;
	RegisteredUser user;
	FacultyUser F;
    StudentUser S;
    cout << "Enter Your Detail:" <<endl << endl;
	cout <<"1. Faculty User"<<endl;
	cout <<"2. Student User"<<endl;
	cout <<"3. Exit "<<endl;
	cout <<"Enter your choice :";
	cin >>choice;
	while(choice>3 && choice <0){
		cout<<"Invalid. Enter Again "<<endl;
		cin>>choice;}
	switch(choice){
		case 1:
			XYZ:{
				cout<<"Enter your Id :"<<endl;
    			cin>>id;
    			cout<<"Enter your Password :"<<endl;
    			cin>>pass;
    			course = F.check_member_data( id , pass);
    			while (course==false)
				goto XYZ;
			}
			cout<<"-->Display Profile"<<endl;
    		ABC:{
			cout<<"1.Add Item: "<<endl;
    		cout<<"2.Remove Item: "<<endl;
    		cout<<"3.Exit: "<<endl;
    		cout<<"Enter your choice :";
    		cin>>opt;
			while(opt>3 && opt<0){
				cout<<"Invalid. Enter Again "<<endl;
				cin>>opt;
			}	
			}
    		switch(opt){           
        		case 1:
            		cout<<"Enter the Detail of the books: "<<endl;           
            	    book.setauthor();
            	    book.setid();
            	    book.setyear();
            	    book.settitle(); 
            	    item.addItem(book.getyear(),book.getid(),book.gettitle(),book.getauthor());
            	    goto ABC;
            	    break;
				case 2:
        		    cout<<"Enter the item id to remove : ";
        		    cin>>id;
        		    item.removeItem(id);
        		    goto ABC;
        		    break;
        		case 3:
				    exit(0);
					break;
			}
		case 2:
			HIJ:{
			cout<<"Enter your Id :"<<endl;
    	    cin>>id;
    		cout<<"Enter your Password :"<<endl;
    		cin>>pass;
    		}
    		Degree = S.check_member_data( id , pass);
    		while(Degree==false)
    		goto HIJ;
    		cout<<"Display Details"<<endl;
    		cout<<"1.Borrow Item "<<endl;
    		cout<<"2.Return Item"<<endl;
    		cout<<"3.Exit"<<endl;
    		cout<<"Enter your choice :";
    		cin>>opt;
    		while(opt>3 && opt<0){
				cout<<"Invalid. Enter Again "<<endl;
				cin>>opt;
			}
			switch(opt){
    			case 1:
   					member.borrow_item(S.getID());
    				break;
    			case 2:
					member.return_item();
					break;
    			case 3:
    				exit(0);
				    break;
			}
     break;	
    }
};
void new_member()
{
    int choice;
    FacultyUser F;
    StudentUser S;
    cout << "Enter Your Detail:" << endl;
    cout << "1. Faculty Member" << endl;
    cout << "2. Student Member" << endl;
    cin >> choice;
    if (choice == 1){
        F.setName();
        F.setID();
        F.setDepartment();
        F.setCourse();
        F.setPassword();
        F.write_member_data(); 
    }
    else if (choice == 2){
        S.setName();
        S.setID();
        S.setDepartment();
        S.setDegree();
        S.setPassword();
        S.write_member_data(); 
    }
}

int main()
{	
	cout<<"_______________________Wellcome To Air University Library_______________________"<<endl<<endl;
	DEF:{
		cout<<endl;
	int choice;
	cout<<"Enter Your Choice"<<endl;
	cout<<"-> 1)New Member "<<endl;
	cout<<"-> 2)Old Member "<<endl;
	cout<<"-> 3)Exit "<<endl;
	cin>>choice;
	while(choice>3 && choice <0){
		cout<<"Invalid. Enter Again "<<endl;
		cin>>choice;
	}
	switch (choice){
		case 1:
			new_member();
			goto DEF;
			break;
		case 2:
			old_member();
			goto DEF;			
			break;
		case 3:
			exit(0);
			break;
	}}
	return 0;
}