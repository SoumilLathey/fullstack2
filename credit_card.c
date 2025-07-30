#include<stdio.h>
int len(long int number){
    int count=0;
     while(number!=0){
        number=number/10;
        count++;}
        return count;
     
}
    

int exttracno(long int number){
    int i,j,k,flag=0;
    int arr[100];
    k=len(number);
    int start=0;
    int end=k-1;
    int temp;
    while(start>end){
        temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    for(i=0;i<k;i++){
        arr[i]=arr[start];
    }
    for(i=0;i<k;i++){
        arr[i]=number%10;
        number=number/10;
    }
    int sum=0;
    int tsum=0;
    int psum=0;
    int osum=0;
    for(i=0;i<k;i=i+2){
        sum=arr[i]+sum;
    }
    for(i=0;i<k;i++){
        tsum=arr[i]+sum;
    }
    for(i=0;i<k;i=i+2){
        psum=(arr[i]*2)+sum;
    }
    osum=tsum-sum+psum;
    if(osum%10==0){
        flag=1;
    }
    return flag;

}
int main(void){
    long int number,flag=0;
    printf("enter any number");
    scanf("%ld",&number);
    int length=0;
    flag=exttracno(number);
    length=len(number);
    if(length==15){
        printf("AMERICAN EXPRESS");
    }
    else if(length==16){
        printf("MASTER CARD");
    }
    else if(flag==0){
        printf("INVALID");
    }
     else{
        printf("VISA");
    }
    return 0;


}