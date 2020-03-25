#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class anagram{
	public:
		anagram();
		~anagram();
		ifstream wejscie;
		ofstream wyjscie;
		string napis1;
		string napis2;
		bool znak;
		string ZnakZ;
		
	void sprawdz_plik();
	void wczytaj();
	void sortowanie(string s1,string s2);
	void sprawdzCzyAnagram(string s1,string s2);
	void zapis(string s1,string s2);
};
anagram::anagram(){
	wejscie.open("wejscie.txt");
	wyjscie.open("wyjscie.txt");
	wyjscie<<"[\n";
}
anagram::~anagram(){
	wyjscie<<"]";
	wejscie.close();
	wyjscie.close();
}
void anagram::sprawdz_plik(){
	if(wejscie.good()&&wyjscie.good()){
		wczytaj();
	}
	else{
		cout<<"Blad";
	}
}
void anagram::wczytaj(){
	while(!wejscie.eof()){
		wejscie>>napis1;
		wejscie>>napis2;
		sortowanie(napis1,napis2);
		
	}
	
}
void anagram::sortowanie(string s1,string s2){
	for (int i=0; i<s1.length()-1; i++){
		for (int j=0; j<s1.length()-1; j++){
			if (s1[j]>s1[j+1]){
				swap(s1[j],s1[j+1]);
			}
		}
	}
	for (int i=0; i<s2.length()-1; i++){
		for (int j=0; j<s2.length()-1; j++){
			if (s2[j]>s2[j+1]){
				swap(s2[j],s2[j+1]);
			}
		}
	}
	
	sprawdzCzyAnagram(s1,s2);
}
void anagram::sprawdzCzyAnagram(string s1,string s2){
	znak = true;
	for(int i=0;i<s1.length();i++){
		if(s1[i] != s2[i]){
			znak = false;
		}
	}
	zapis(s1,s2);
}
void anagram::zapis(string s1,string s2){
	if(znak == true){
		ZnakZ = "TAK";
	}
	else{
		ZnakZ = "NIE";
	}
	wyjscie<<"{\"slowo1\":\""+napis1+"\",\"slowo2\":\""+napis2+"\",\"anagram\":\""+ZnakZ+"\"""}"<<endl;
	ZnakZ = "";
}
int main() {
	anagram a1;
	a1.sprawdz_plik();

	return 0;
}
