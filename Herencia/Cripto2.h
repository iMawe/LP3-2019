#include <iostream>
#include <string.h>
#include <stdio.h>  // printf
#include <ctype.h>  // isalpha, isupper


using namespace std;

class Cripto{
public:
	int key;
	string alpha;
public:
	Cripto(int k = -3, string al = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz'1234567890,.;:-_?"){
		key = k;
		alpha = al;
	}

	string encriptar(string str){
        for(int i = 0; i < str.size(); i++){
	        int pos = alpha.find(str[i]);
	        int k;
	    	if (key > 0){
	    		k = key % alpha.size();
	      		if(k + pos > (alpha.size()-1)) str[i] = alpha[(k + pos) - alpha.size()];
	      		else str[i] = alpha[pos + k];
	    	}
	    	
	    	else{
	    		int k = (-key) % alpha.size();
	    		if(pos - k < 0) str[i] = alpha[alpha.size() + (pos - k)];
	    		else str[i] = alpha[pos - k];
				
			}
      	}
      	return str;

    }
	string desencriptar(string str){
		key = -(key);
		for(int i = 0; i < str.size(); i++){
	        int pos = alpha.find(str[i]);
	        int k;
	    	if (key > 0){
	    		k = key % alpha.size();
	      		if(k + pos > (alpha.size()-1)) str[i] = alpha[(k + pos) - alpha.size()];
	      		else str[i] = alpha[pos + k];
	    	}
	    	
	    	else{
	    		int k = (-key) % alpha.size();
	    		if(pos - k < 0) str[i] = alpha[alpha.size() + (pos - k)];
	    		else str[i] = alpha[pos - k];
				
			}
      	}
      	return str;
    }
};

class Caesar: public Cripto{
private:
	string alpha;
	int key;
public:
	Caesar(string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz'1234567890,.;:-_?"): alpha (alp), key (3){}
	~Caesar(){}

    
};

