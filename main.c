//
//  main.c
//  T-Beem
//
//  Created by Omar Jaw on 10/20/18.
//  Copyright © 2018 Omar Jaw.
//

#include <stdio.h>
#include <math.h>


int main()
{
    int concgrade;
    float fy = 4200;
    float f_c;
    float Pmin,Pmax,Beta1;
    float gammac=2500;
    // gammac is in kg/m^3
    float fi=0.9;
    float Ecu = 0.003;
    float Et=0.005;
    float b,bw,ht,hf,s,l,Mu,d;
    float x,y;
    float MnF;
    int R;
    float Rn,AsRequired;
    long double Prequired;
    float result,resultF;
    float ifTrue,ifFalse;
    float Asmax;
    
    // Pmin is Raw min
    
    printf("Welcome to T-Beam Tool by Omar Jawhar 2018\n\n\n");
    printf("Steel Grade (fy) is set to Grade 60, which is 4200 Kg/cm squared\n\n");
    printf("First of all, please select your Concrete Strength ( 20-25-28-30-35-40 MPa ) \n");
    

    scanf("%d",&concgrade);
    while (concgrade != 20 && concgrade != 25 && concgrade != 28 && concgrade != 30 && concgrade != 35 && concgrade != 40)
    {
        printf("Please read carefully, only values of 20,25,28,30,35,40 are allowed\n");
        scanf("%d",&concgrade);
    }
    
 if (f_c == 20)
 {
     f_c=200;
     Pmin= 0.0033;
     Pmax= 0.0136;
     Beta1= 0.85;
 }
    
    if (f_c == 25)
    {
        f_c=250.00;
        Pmin= 0.0033;
        Pmax= 0.0158;
        Beta1= 0.85;
    }
    
    if (concgrade == 28)
    {
        f_c=280.00;
        Pmin= 0.0033;
        Pmax= 0.0181;
        Beta1= 0.85;
    }
    
    if (f_c == 30)
    {
        f_c=300.00;
        Pmin= 0.0033;
        Pmax= 0.0203;
        Beta1= 0.85;
    }
    
    
    if (f_c == 35)
    {
        f_c=350.00;
        Pmin= 0.0033;
        Pmax= 0.0226;
        Beta1= 0.814;
    }
    
    
    if (f_c == 40)
    {
        f_c=400.00;
        Pmin= 0.0033;
        Pmax= 0.0245;
        Beta1= 0.764;
    }
    
    // THE END OF DECLARATION OF TABLE OF CONSTANTS F'C
    
    printf("Please enter the width of T-Beam (STRICTLY IN CM)\n");
    scanf("%f",&b);
    
    printf("Please enter the width of Web (STRICTLY IN CM)\n");
    scanf("%f",&bw);
    
    printf("Please enter the Total Height (STRICTLY IN CM)\n");
    scanf("%f",&ht);
    
    printf("Please enter the Height of Flange (STRICTLY IN CM)\n");
    scanf("%f",&hf);
    
    printf("Please enter the Spacing between 2 T-Beams from center to center (STRICTLY IN CM)\n");
    scanf("%f",&s);
    
    printf("Please enter the span (length of T-Beam) (STRICTLY IN CM)\n");
    scanf("%f",&l);
    
    printf("Please enter the Ultimate Moment imposed on T-Beam (STRICTLY IN KG-M)\n");
    scanf("%f",&Mu);
    
    d= ht - 6 ;
    
    // x is l/4 and y is 16hf+bw and are used to give b the new minimum value
    
    x=l/4;
    y= (16*hf)+bw ;
    
    if (x<y && x<s) {
        b=x;
    }
    else if (y<x && y<s) {
        b=y;
    }
    else {
        b=s;
    }
    
    // we have given b the new value which is the least between L and X and Y
    
    
    MnF = ( 0.85 * f_c * (b * hf)*(d - hf/2) ) / 100 ;
    
    printf("Mnf is %f",MnF);
    
    if ( fi*MnF > Mu ) {
        printf("YOU HAVE A RECTANGULAR T-BEAM OF WIDTH %.2f\n",b);
        R=1;
        
        // R means Rectangular T-Beam, 1 is True 0 is False.
    }
    else {
        printf("YOU HAVE A TRUE T-BEAM\n");
    R=0;
    }
    
    
    
    // ***********************************************START OF STAGE 2 *********************************************************
    
    
    
    
    // if true T-Beam
    
    if (R==0)
        
    {
        
        AsRequired=  ((Mu)/(fi*fy*(d-(hf/2))))*100;
        Asmax= (0.85/fy)*f_c*((b*hf)+((Beta1*Ecu*d)/(Ecu+Et) -hf)*bw);
        
        printf(" Your As should be as follows : %f ≤ As ≤ %f",AsRequired,Asmax);
    }


else if (R==1) {

    // if Rectangular T-Beam Case:

    Rn= ((Mu)/(fi*b*(d*d)))*100;
    
    printf("Rn is %f\n\n",Rn);

    result= 1-((2*Rn)/(0.85*f_c));
    printf("RESULT IS %f\n\n",result);
    resultF= sqrt(result);
    printf("SQRT IS %f",resultF);


    Prequired= 0.85*(f_c/fy)*(1-resultF);
    
    printf("Prequired is %Lf\n\n",Prequired);

    ifTrue= Prequired*b*d;
    ifFalse= Pmin*b*d;



    if (Prequired <= Pmax && Prequired >= Pmin) {


        printf("As Required should be > or = to %f",ifTrue);

        }
else {
            printf("As Required should be > or = to %f",ifFalse);
    }
    
    




}
    


}
