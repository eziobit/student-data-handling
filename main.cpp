#include <iostream>
#include <fstream>
//#include <iomanip>
#include <string>
std::string file_name();
// in this programe you can add new student with name id and marks of subject. 
// after adding the program will make a new  txt file(id.txt) with student data.
// you can delete and display data on screen using this program.
struct student_data{
	int id, roll;
	std::string name;
	
	
	struct student_data *next_st;
};
struct student_data* start = NULL;
void add_data(){
	struct student_data* ptr =new student_data;
	int n_id, n_roll;std::string n_name;
	std::cout<<"Please Enter the Student id ";std::cin>>n_id;
	std::cout<<"please Enter the student roll No. ";std::cin>>n_roll;
	std::cout<<"Please Enter the student name ";std::cin>>n_name;
	
	ptr->id= n_id;
	ptr->roll= n_roll;
	ptr->name=n_name;
	
	ptr->next_st=start;
	start=ptr;
	
	std::fstream file;
	std::string file_name;
	file_name="data/"+n_name+".txt";
	file.open(file_name.c_str(), std::fstream::in| std::fstream::out| std::fstream::trunc);
	file<<n_id<<std::endl<<n_roll<<std::endl<<n_name;
	file.close();
	
	
	std::fstream log;
	log.open("data/log.txt",std::fstream::in| std::fstream::out| std::fstream::app);
	log<<file_name.c_str()<<std::endl;
	log.close();
	
}

void load_data(int n_id, int n_roll,std::string n_name){
	struct student_data* ptr =new student_data;
	
	ptr->id= n_id;
	ptr->roll= n_roll;
	ptr->name=n_name;
	
	ptr->next_st=start;
	start=ptr;
}




/*std::string c_file_name(){
	std::fstream file;
	file.open("data/log.txt", std::fstream::in| std::fstream::out| std::fstream::app);
	std::string name;
	file>>name;
	return name;
	file.close();
}
*/
#define p system("pause");
void fetch_data(){
	std::fstream log;
	log.open("data/log.txt", std::fstream::in| std::fstream::out| std::fstream::app);
	std::string namef;
	std::cout<<"fetching data"<<std::endl;
	while(!log.eof()){
		
		getline(log,namef);
		//std::cout<<namef;
		if(log.eof()==true){
			std::cout<<"fetching data Done"<<std::endl;
		}else{
		
		std::fstream file_s;
		file_s.open(namef.c_str(), std::fstream::in| std::fstream::out| std::fstream::app);
		std::string id ,roll;std::string name;
		getline(file_s,id);
		getline(file_s,roll);
		getline(file_s,name);
		file_s.close();
		int id_i = stoi(id);
		int roll_i= stoi(roll);
		load_data(id_i,roll_i,name);
	//	std::cout<<id_i<<std::endl<<roll_i<<std::endl<<name<<std::endl;
			
	//	p
	}//if
	}
		log.close();
}


/*
void delete_data(){
	if(start==NULL){
		std::cout<<"\nList is Empty\n";
	}
}

*/


void display() {
	std::cout<<"\n\n\n< DATA >";
   struct student_data* ptr;
   ptr = start;
   while (ptr != NULL) {
      std::cout<<"\n\nID: "<< ptr->id <<"\nRoll: "<< ptr->roll <<"\nName "<<ptr->name;
      ptr = ptr->next_st;
   }
}





int main() {
//	std::cout<<"kain"<<std::setw(10)<<"king";
		fetch_data();
	add_data();

display();
	
	
}
