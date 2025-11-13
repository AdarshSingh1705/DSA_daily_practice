  #include<iostream>
using namespace std;

int fab(int num){
    
     if(num == 1){
        return 0;
      }
     else if(num == 2){
        return 1;
     }
     else {
         int a = 1, b =0, c =0;
          for(int i = 3; i <= num; i++){
        
     c= a+b;
     b = a;
     a = c;
    }
     return c;
  }
}

int main(){

    int num;
    int result =0;
    cout<<"enter the term"<<endl;
    cin>> num;
    result = fab(num);
    cout<< num<<"'th term is:- "<< result << endl;
   
    return 0;

}