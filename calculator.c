#include <stdio.h>
#include <cs50.h>

int main(){
int m;


char behavior;
float note_global;




//debut de programme
printf("-----This machine is for calcule your result final-----\n");
//the programme ask about the number of exams and the number shouldnt be less than 1
do{
m=get_int("Enter number of the school subject do you have: ");
}while(m<1);
//m is a variable of the number exams
string x[m];
float y[60];
float beh[m];
int a[20];
float total[m];
float result[m];
int coefficient[m];
int some_coefficient;
float result2=0;
for(int i=0;i<m;i++){

    x[i]=get_string("What's name of the %i subject: ",i+1);

}
//string x[] is variable for stocker les names of the subject school

int g=0 ,d=0;
for(int l=0;l<m;l++){
    do{
        coefficient[l]=get_int("Enter the coefficient of %s's subject: ",x[g]);}while(coefficient[l]<1);
    some_coefficient+=coefficient[l];
    //coeficinet is vaiable for stocker the coefficient of each subject and the coefficient shouldnt be less than 1

    do{
        a[l]=get_int("How much exams do you past in %s: ",x[g]);}while(a[l]<1);

    for(int j=0;j<a[l];j++){
        do{
            y[d]=get_float("Enter your %i note's exam of your %s's subject: ",j+1,x[g]);
        }while(y[d]<0 || y[d]>20);
    //y[] is a variable for stocker note of each exam
    d++;
    }
    do{
        behavior=get_char("Do you have a behavior exam in %s's subject (y/n): ",x[g]);
    //existe than exam behavior or no
    }while(behavior!='y'&& behavior!='Y' && behavior!='n'&& behavior!='N');
    if(behavior=='Y'||behavior=='y'){
        do {
            beh[l]=get_float("Enter your note behavior in %s's subject: ",x[g]);
        }while(beh[l]<0 || beh[l]>20);
    }
    else if(behavior=='N'||behavior=='n'){
        beh[l]=0;
    }
    g++;
}
int v=0;
d=0;
for(int w=0;w<m;w++){
    if(beh[w]==0){
        printf("-----For %s's note-----\n",x[w]);
        while(d<a[w]){
            
            printf("Note N°%i: %.2f\n",d+1,y[v]);
            total[w]+=y[v];
        d++;
        v++;
        
    }
    result[w]=total[w]/a[w];
    printf("--->Your result final in your subject school %s is: %.2f\n",x[w],result[w]);
    
}
    else{
        printf("-----For %s's note-----\n",x[w]);
        printf("Your behavior's note in %s is: %.2f\n",x[w],beh[w]);
        while(d<a[w]){
            
            printf("Note N°%i is: %.2f\n",d+1,y[v]);
            total[w]+=y[v];
       
        d++;
        v++;
    }
    
    result[w]=((total[w]/a[w])*0.75)+(beh[w]*0.25);
    printf("--->Your result final in your subject school %s is: %.2f\n",x[w],result[w]);
}
 d=0;


}
for(int h=0;h<m;h++){
    result2+=result[h]*coefficient[h];
}
note_global=result2/some_coefficient;
printf("<<<Finely your globel note is: %.2f >>>",note_global);

}
