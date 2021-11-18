#include<iostream>
#include<ctime>
#include<chrono>
#include<vector>
#include<string>
#include<fstream>
#include<limits>
#include<sstream>
#include<stdlib.h>
#include<iomanip>


using namespace std;


// a variable to keep track no.of passwords;;
static unsigned long long totalNoOfPassGen=0;
std::fstream PASSFILE("passfile.tmp", std::fstream::in | std::fstream::out | std::fstream::app );


void getParsedOptions(int argc, const char *argv[] ) {
    int i = 1;
    while (i < argc)
    {
        std::string s = argv[i];
        if (s=="-h" || s=="--help" )
        {
            std::cout<<"Just run the file directly dammit..,\n no help cause you already know how to use a wordlist .."<<std::endl;
            exit(EXIT_SUCCESS);
        }
        //declare other options here like --version, --shit.. 
        i++;
    }
    
}

class details
{
    public:
        std::string vicName, 
                    wName, 
                    petName,
                    kidName, 
                    DOB, 
                    DOByear, 
                    licenseNo;
        details( ) : vicName(""), wName(""), petName(""), kidName(""), DOB(""), DOByear(""), licenseNo(""){}

       /* void setVictimDetails(std::vector<std::string> vicDetails) {
            this->vicName = vicDetails[1];
            this->
            this->petName = vicDetails[3];
            this->kidName = vicDetails[4];
            this->DOB = vicDetails[5];
            // 1st error maybe at this place (update: was;;)   :)
            this->
        }*/
        
        void getDOBRight(void);
        void generateWithName(void);
        void generateWithWname(void);
        void generateWithPetname(void);
        void generateWithKidname(void);
        void generateWithDOB(void);
        void generateWithAtTheRate(void);
        void generateWithHashes(void);
        void generateWithAtHash(void);

        ~details();
};

 details::~details() {

}

void details::getDOBRight() {
    /*
    one more way t do this
    int n = 0;
    while ((n = this->DOB.find("-", n)) != string::npos ) {
        this->DOB.replace(n, 1, "");
        n += 1;
    }
    */
    /*std::string tmp("");
    for (int i = this->DOB.front(); i <= this->DOB.back(); i++ ) {
        if (this->DOB.at(i) < '0' || this->DOB.at(i) > '9') { tmp = tmp + this->DOB.at(i); }
        else continue;
    }
    this->DOB.clear();
    this->DOB = tmp;*/
    std::string tmp;
    tmp = this->DOB;
    tmp.erase(std::remove(tmp.begin(),tmp.end(),'-'),tmp.end());
    this->DOB.clear();
    this->DOB = tmp;
}

void details::generateWithName(void) {
    std::string tmp;
    tmp = this->vicName + this->DOB;
    PASSFILE<<tmp<<std::endl;
    tmp = this->vicName + this->DOByear;
    PASSFILE<<tmp<<std::endl;
    totalNoOfPassGen += 2;
    for (size_t i = 0; i <= 99999; i++) {
        PASSFILE<<this->vicName<<i<<std::endl;
        totalNoOfPassGen++;
    }
    
}

void details::generateWithWname(void) {
    std::string tmp;
    tmp = this->wName + this->DOB;
    PASSFILE<<tmp<<std::endl;
    tmp = this->wName + this->DOByear;
    PASSFILE<<tmp<<std::endl;
    totalNoOfPassGen += 2;
    for (size_t i = 0; i <= 9999; i++) {
        PASSFILE<<this->wName<<i<<std::endl;
        totalNoOfPassGen++;
    }
}

void details::generateWithPetname() {
    //multicomment with multi cursor
    std::string tmp;
    tmp = this->petName + this->DOB;
    PASSFILE<<tmp<<std::endl;
    tmp = this->petName + this->DOByear;
    PASSFILE<<tmp<<std::endl;
    totalNoOfPassGen += 2;
    for (size_t i = 0; i <= 9999; i++) {
        PASSFILE<<this->petName<<i<<std::endl;
        totalNoOfPassGen++;
    }
}
void details::generateWithKidname() {
    //multicomment with multi cursor
    std::string tmp;
    tmp = this->wName + this->DOB;
    PASSFILE<<tmp<<std::endl;
    tmp = this->wName + this->DOByear;
    PASSFILE<<tmp<<std::endl;
    totalNoOfPassGen += 2;
    for (size_t i = 0; i <= 9999; i++) {
        PASSFILE<<this->wName<<i<<std::endl;
        totalNoOfPassGen++;
    }
}
void details::generateWithDOB() {
    //multicomment with multi cursor    
    //pushing undashed value;
    PASSFILE<<this->DOB<<std::endl;
    totalNoOfPassGen++;
}
void details::generateWithAtTheRate() {
    //multicomment with multi cursor
    std::string tmp;
    tmp = this->vicName + '@' + this->DOB;
    PASSFILE<<tmp<<std::endl;
    tmp = this->vicName + '@' + this->DOByear;
    PASSFILE<<tmp<<std::endl;
    totalNoOfPassGen += 2;
    for (size_t i = 0; i <= 9999; i++) {
        PASSFILE<<this->vicName<<'@'<<i<<std::endl;
        totalNoOfPassGen++;
    }
}
void details::generateWithHashes() {
    //multicomment with multi cursor
    std::string tmp;
    tmp = this->vicName + '#' + this->DOB;
    PASSFILE<<tmp<<std::endl;
    tmp = this->vicName + '#' + this->DOByear;
    PASSFILE<<tmp<<std::endl;
    totalNoOfPassGen += 2;
    for (size_t i = 0; i <= 9999; i++) {
        PASSFILE<<this->vicName<<'#'<<i<<std::endl;
        totalNoOfPassGen++;
    }
}
void details::generateWithAtHash() {
    //multicomment with multi cursor
    std::string tmp;
    tmp = '@' + this->vicName + '#' + this->DOB;
    PASSFILE<<tmp<<std::endl;
    tmp = '@' + this->vicName + '#' + this->DOByear;
    PASSFILE<<tmp<<std::endl;
    totalNoOfPassGen += 2;
    for (size_t i = 0; i <= 9999; i++) {
        PASSFILE<<'@'<<this->vicName<<'#'<<i<<std::endl;
        totalNoOfPassGen++;
    }
    tmp = '#' + this->vicName + '@' + this->DOB;
    PASSFILE<<tmp<<std::endl;
    tmp = '#' + this->vicName + '@' + this->DOByear;
    PASSFILE<<tmp<<std::endl;
    totalNoOfPassGen += 2;
    for (size_t i = 0; i <= 9999; i++) {
        PASSFILE<<'#'<<this->vicName<<'@'<<i<<std::endl;
        totalNoOfPassGen++;
    }
}

//main function here

int main(int argc, char const *argv[]) {
    //getopt
    if(argc > 0) getParsedOptions(argc, argv);

    bool loop = true;

    std::string tempDetails;
    //std::vector<std::string> vicDetails;
    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    

    //victim object declareation
    details victimDetails;

    //getting victim details    
    std::cout<<"Enter Victim's name :";
    getline(std::cin, tempDetails);
    victimDetails.vicName = tempDetails;
    std::cout<<"Enter Victim's wife name :";
    getline(std::cin, tempDetails);
    victimDetails.wName = tempDetails;
    std::cout<<"Enter Victim's pet name :";
    getline(std::cin, tempDetails);
    victimDetails.petName = tempDetails;
    std::cout<<"Enter Victim's kid name :";
    getline(std::cin, tempDetails);
    victimDetails.kidName = tempDetails;
    while(loop){
        std::cout<<"Enter Victim's Date of birth in (dd-mm-yyyy):";
        getline(std::cin, tempDetails);
        victimDetails.DOB = tempDetails;
        if (victimDetails.DOB.length()<10) {
            std::cout<<"Enter right details"<<std::endl;
            loop = true;
        }
        else loop = false;
    }
    victimDetails.getDOBRight();
    victimDetails.DOByear = victimDetails.DOB.substr(victimDetails.DOB.length() - 4);
            //ex: 10-10-1987
            //          ^4th index from last will give birth year


    
    //loaded details to victim object;;



    //generating passwords
    //when i'll update it i will make it look good,
    //but currently looking at only functonality
    victimDetails.generateWithName();
    victimDetails.generateWithWname();
    victimDetails.generateWithPetname();
    victimDetails.generateWithKidname();
    victimDetails.generateWithDOB();
    victimDetails.generateWithAtTheRate();
    victimDetails.generateWithHashes();
    victimDetails.generateWithAtHash();


    //ending we will print no of passwords generataed;;

    std::cout<<"Total no of passwords generated :"<<totalNoOfPassGen;
    auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
    std::tm _tm = *std::gmtime(&timenow);
    std::stringstream tss;
    tss << std::put_time(&_tm, "%Y-%m-%d_%H:%M:%S");
    auto s = tss.str();
    //std::cout<<s; 

    s = "password_" + s + ".txt";//rename passfile.tmp 
    //std::cout<<s; 
    char * writable = new char[s.size() + 1];
    std::copy(s.begin(), s.end(), writable);
    writable[s.size()] = '\0'; 
    PASSFILE.close();
    std::rename("passfile.tmp",writable);
    //printf("\n%s\n",writable);
    //system(writable);
    // system("del passfile.tmp");

    // don't forget to free the string after finished using it
    delete[] writable;

    return 0;
}
