#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class UserHash{
private:
    vector<bool> hash_table;
public:
    UserHash(int size){
        hash_table.resize(size, false);
    }

    int hash_func1(const string& s);
    int hash_func2(const string& s);
    int hash_func3(const string& s);
    int hash_func4(const string& s);

    void insert(const string& s);
    void search(const string& s);

};

int UserHash::hash_func1(const string& s){
    int result = 0;
    int size = hash_table.size();
    for(int i=0; i<s.length(); i++){
        result += (s[i] % size);
    }

    return result % size;
}

int UserHash::hash_func2(const string& s){
    int result = 1;
    int size = hash_table.size();
    for(int i=0;i<s.length();i++){
        result += s[i] * pow(19,i);
        result %= size;
    }

    return result % size;
}

int UserHash::hash_func3(const string& s){
    int result = 7;
    int size = hash_table.size();
    for(int i=0;i<s.length();i++){
        result += s[i] * pow(30,i);
        result %= size;
    }

    return result % size;
}

int UserHash::hash_func4(const string& s){
    int result = 3;
    int prime = 7;
    int size = hash_table.size();
    for(int i=0;i<s.length();i++){
        result += s[i] * pow(3,i) * pow(prime,i);
        result %= size;
    }

    return result % size;
}

void UserHash::search(const string& s){
    if(hash_table[hash_func1(s)] == true && hash_table[hash_func2(s)] == true &&
       hash_table[hash_func3(s)] == true && hash_table[hash_func4(s)] == true){
        cout << "element je vjerojatno u tablici" << endl;
    }else{
        cout << "element nije u tablici" << endl;
    }
}

void UserHash::insert(const string& s){
    int index1 = hash_func1(s);
    int index2 = hash_func2(s);
    int index3 = hash_func3(s);
    int index4 = hash_func4(s);

    hash_table[index1] = true;
    hash_table[index2] = true;
    hash_table[index3] = true;
    hash_table[index4] = true;
}


int main(){
    UserHash user_db(100);

    vector<string> usernames = {
            "jopis107", "hstranput", "Matej293", "MateaCucman", "JosipCestar",
            "lanamak", "DanijelaValjak", "filipuranjek", "domagojziros", "lsanic",
            "TomislavVinkovic", "IvoSusac", "matej2810", "KresimirSecan",
            "inespejic", "InesSimunovic", "IvanFrantal", "Frle001", "inesstrapac",
            "mkolak", "Dpritisa", "istvavk", "mtoldi", "lbrodar5", "mkristic",
            "andreamatasovic", "balentovicanja", "IvanaVinkovic", "prakidzija",
            "DMV1204", "JMesaric", "KarloKampic", "jurick1910", "LarisaDarojkovic"
    };

    for (auto& users:usernames){
        user_db.insert(users);
    }

    user_db.search("andreamatasovic");
}
