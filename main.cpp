#include<iostream>
#include <cctype>
using namespace std;
string EncryptionCaesarCipher(string  , int );
string DecryptionCaesarCipher(string  , int );
void DecryptionCaesarCipherNoKey(string );
int EnterKey();
void print();
int main() {
	int choice=0;
	for(;;) {
		print();
		cin>>choice;
		cout<<"\n";
		if(choice <1 || choice >3) {
			cout<<"wrong entry! ! !\n";
			char yN;
			cout<<"Do you want to continue [ Y / N ] : ";
			cin>>yN;
			if(yN == 'n' || yN =='N')
				break;
		} else {
			switch(choice) {
				case 1: {
					string text ;
					cout<<"Enter Text  : ";
					cin.ignore(1,'\n');
					getline(cin,text);
					int key=EnterKey();
					string encryptionText =EncryptionCaesarCipher(text,key);
					if(encryptionText !="")
						cout<<"\nEncryption Text :"<<encryptionText;
				}
				break;
				case 2: {
					string text ;
					cout<<"Enter Text  : ";
					cin.ignore(1,'\n');
					getline(cin,text);
					int key=EnterKey();
					string encryptionText =EncryptionCaesarCipher(text,key);
					if(encryptionText !="")
						cout<<"\nEncryption Text :"<<encryptionText;
				}
				break;
				case 3: {
					string text ;
					cout<<"Enter Text  : ";
					cin.ignore(1,'\n');
					getline(cin,text);
					DecryptionCaesarCipherNoKey(text);
				}
				break;
			}
		}
		char yNn;
		cout<<"\n*********************\nDo you want to continue [ Y / N ] : ";
		cin>>yNn;
		if(yNn == 'n' || yNn =='N')
			break;
	}

}
void print() {
	cout<<"\n\n----------Encryption Process------------\n\n----------C a e s a r Cipher------------\n";
	cout<<"what do you want to do?"<<endl;
	cout<<"1 _ Encryption\n2 _ Decryption\n3 _ You don't have the key\n\n\npleASE eNTER CHOice :";
}
int EnterKey() {
	int key ;
	cout<<"Entere Key : ";
	for(;;) {
		cin>>key;
		if(key <1 || key >26) {
			cout<<"wrong entry , Enter the key from 1 to 26 : ";
		} else
			break;
	}
	return key;
}
string EncryptionCaesarCipher(string text , int key) {
	string newText = "";
	for(int i=0; i<text.length(); i++) {
		char t =text[i];
		if(isupper(t)) {   //test upper case latter
			int n = t+key;
			if(n > 90) {
				n=(n%90) +65-1;
			}
			newText+=n;
		} else if(islower(t)) {  //test upper case latter
			int n = t+key;
			if(n > 122) {
				n=(n%122) +97;
			}
			newText+=n;
		} else if(t==32) {
			newText+=t;
		} else { // nother input
			cout<<"Error enter value . ! ! !" ;
			return newText="";
		}
	}
	return newText;
}
string DecryptionCaesarCipher(string text , int key) {
	string newText = "";
	for(int i=0; i<text.length(); i++) {
		char t =text[i];
		if(isupper(t)) {   //test upper case latter
			int n = t-key;
			if(n < 65) {
				// n=(n%90) +26;
				n=n +26;
			}
			newText+=n;
		} else if(islower(t)) {  //test upper case latter
			int n = t-key;
			if(n <97) {
				n=n +26;
			}
			newText+=n;
		} else if(t==32) {
			newText+=t;
		} else { // nother input
			cout<<"Error enter value . ! ! !" ;
			return newText="";
		}
	}
	return newText;
}
void DecryptionCaesarCipherNoKey(string text) {
	int flag=0;
	for(int key=1; key<=26; key++) {
		string newText = "";
		for(int i=0; i<text.length(); i++) {
			char t =text[i];
			if(isupper(t)) {   //test upper case latter
				int n = t-key;
				if(n < 65) {
					// n=(n%90) +26;
					n=n +26;
				}
				newText+=n;
			} else if(islower(t)) {  //test upper case latter
				int n = t-key;
				if(n <97) {
					n=n +26;
				}
				newText+=n;
			} else if(t==32) {
				newText+=t;
			} else { // nother input
				cout<<"Error enter value . ! ! !" ;
				flag++;
				break ;
			}
		}
		if(flag ==0)
			cout<<"Key "<<key<<" text = "<<newText<<endl;
		else
			break;
	}
}