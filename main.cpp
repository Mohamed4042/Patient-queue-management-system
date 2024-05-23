
#include <iostream>
#include <list>
#include <string>

using namespace std;

class Patient
{
public:
    string name;
    int age;
    string condition;
    int priority; 

    Patient(string name,int age, string &condition){
        this->name=name;
        this->age=age;
        this->condition=condition;

        if(condition== "critical")
            priority=3;
        else if(condition == "urgent")
            priority=2;
        else
            priority=1;
    }
   
};

bool comparePatients(const Patient &p1,const Patient &p2){
        return p1.priority> p2.priority;
    }

class EmergencyRoom {
    private:
        list<Patient> patients;

    public:
        void add_patient(string name, int age, string condition){
            Patient patient(name, age, condition);
            patients.push_back(patient);
            patients.sort(comparePatients);
            cout << "Patient " << name << " added to the queue." << endl;
        }
        void process_patient(){

            if(patients.empty()){
                cout << "Queue is empty." << endl;
                return;
            }
            Patient patient = patients.front();
            patients.pop_front();
            cout<< "Processing patient...\n";
            cout<< "Processing patient: "<< patient.name << " (Priority: " << patient.priority << ")"<< endl;

        }
        void update_patient(string name, string new_condition)
        {
            int new_priority;
            bool found = false;
            //search for the name and update its priority
            for(auto it=patients.begin(); it !=patients.end() ; it++)
            {
                if(it->name==name)
                {
                    it->condition=new_condition;
                    
                    if (new_condition == "critical") 
                        new_priority = 3;
                     else if (new_condition == "urgent") 
                        new_priority = 2;
                     else 
                        new_priority = 1;
                    
            
                    //re-sort the queue
                if(new_priority> it->priority || new_priority< it->priority){
                    it->priority=new_priority;
                    patients.sort(comparePatients);
                    cout<<"Priority/Condition of patient " << name << " updated to " << new_condition << endl;
                }
                else
                    cout << "Priority unchanged for " << name << "." << endl;
                found = true;
                break;
                }
            }
            if (!found) 
                cout << "Patient " << name << " not found in the queue." << endl;
        }

        int queue_size() {
            return patients.size();
        }
        void display_queue() {
            if (patients.empty()) {
                cout << "Queue is empty." << endl;
                return;
            }

            cout << "Current Patients in the queue:" << endl;
            for (Patient patient : patients) 
                cout<< "Name: " << patient.name <<", Age: "<< patient.age << ", Condition: " << patient.condition << ", priority: " << patient.priority << endl;
        }
        string front_name() {
            if (patients.empty()) 
                cout<< "Queue is empty.\n";
            
            return patients.front().name;
        }
};      


int main() {
    EmergencyRoom er;

    er.add_patient("Ahmed", 35, "critical");
    er.add_patient("Mazen", 45, "urgent");
    er.add_patient("Omar", 25, "normal");

    cout<<"Front Patient Name: " << er.front_name() << endl;;
    er.display_queue();

    er.update_patient("Ahmed", "urgent");
    er.display_queue();

    er.process_patient();
    er.display_queue();


}