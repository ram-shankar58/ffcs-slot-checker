//FFCS time table clash checker
#include <iostream>
#include <string>
using namespace std;
class subject{
    public:
    string teacher;
    string subjectname;
    string subcode;
    int credit;
    int size;
    string *periods;
    static int counter;
    subject(){
        teacher="";
        subjectname="";
        subcode="";
        credit=0;
        size=0;
        periods={0};

    }
    
    subject(string subjectname, string subcode, string teacher, int credit, initializer_list<string> inputarray){
        this->teacher=teacher;
        this->subjectname=subjectname;
        this->subcode=subcode;
        this->credit=credit;
        this->size=inputarray.size();
        periods=new string[size];
        int i=0;

        for (auto element:inputarray){ //for each loop. auto assumes the datatype
            periods[i]=element;
            i++;
        }
        counter++;


    }
    friend void display(subject subs);

};
void display(subject subs){
        cout<<subs.subjectname<<' '<<subs.subcode<<' '<<subs.teacher<<' ';
        for(int j=0;j<subs.size;j++){
                cout<<subs.periods[j]<<' ';
        }
        cout<<endl;
}

int subject::counter=0;

class timetable{
    public:
    subject *subs;
    int n;
    timetable(subject *subse, int numsubs){
        n=numsubs;
        subs=new subject[numsubs];
        for(int i=0;i<n;i++){
            subs[i]=subse[i];
        }
    }
    void displayall(){
        for (int i=0; i<n;i++){
            cout<<subs[i].subjectname<<' '<<subs[i].subcode<<' '<<subs[i].teacher<<' ';
            for(int j=0;j<subs[i].size;j++){
                cout<<subs[i].periods[j]<<' ';
            }
            cout<<subs[i].credit<<endl;
        }
    }
    void clashcheck(subject *arr,int arraysize){ //arraysize is the number of subjects
        int l=0;
        int tempo;
        int count;
        subject temp[3];
        string theory[]={"A1","F1","D1","TB1","TG1","S11","A2","F2","D2","TB2","TG2","S3","B1","G1","E1","TC1","TAA1","nothing1","B2","G2","E2","TC2","TAA2","S1","C1","A1","F1","TD1","TBB1","nothing2","C2","A2","F2","TD2","TBB2","S4","D1","B1","G1","TE1","TCC1","nothing3","D2","B2","G2","TE2","TCC2","S2","E1","C1","TA1","TF1","TDD1","S15","E2","C2","TA2","TF2","TDD2","nothing4"};
        string lab[]={"L1","L2","L3","L4","L5","L6","L31","L32","L33","L34","L35","L36","L7","L8","L9","L10","L11","L12","L37","L38","L39","L40","L41","L42","L13","L14","L15","L16","L17","L18","L43","L44","L45","L46","L47","L48","L19","L20","L21","L22","L23","L24","L49","L50","L51","L52","L53","L54","L25","L26","L27","L28","L29","L30","L55","L56","L57","L58","L59","L60"};
        for(int i=0;i<60;i++){
            l=0;
            count=0;
            tempo=i; //index of the slot
            for (int j=0;j<arraysize;j++){
                for(int k=0;k<arr[j].size;k++){
                    if (arr[j].periods[k]==theory[i] or arr[j].periods[k]==lab[i]){
                        temp[l]=arr[j];
                        count++;
                        l++;
                    }
                }
                
            }
            if (count>1){
                cout<<"THere has been a clash!"<<endl;
                /*for(int j=0;j<arraysize;j++){
                    for(int k=0;k<arr[j].size;k++){
                        if (arr[j].periods[k]==theory[i] or arr[j].periods[k]==lab[i]){
                            display(arr[j]);
                        }
                    }
                }*/
                for(int h=0;h<l;h++){
                    display(temp[h]);
                }
                

            }
        }


    }

};
//our class definitions are all done!
int main(){
    //FOrmat is subject(string subjectname, string subcode, string teacher, int credit, int size, int *inputarray)
    //above is the format for entering the data
    //Below is the way to enter the subjects
    
    subject allsub[4];
    allsub[0]=subject("Java","BCSE103E","Sandhya",3,{"TCC1"});
    allsub[1]=subject("Maths","BMAT201L","Dhivya",4,{"A1,TA1,TAA1"});
    allsub[2]=subject("DSA","BCSE201L","Srinvas",3,{"D2","TD2","L1","L23"});
    allsub[3]=subject("OS","BCSE303L","Shyamala",4,{"C1","TC1","L2","L32"});
    timetable t1(allsub,4);
    t1.clashcheck(allsub,4);
    
}