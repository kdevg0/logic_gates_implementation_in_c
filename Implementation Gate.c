#include <stdio.h>

/*                      MIT License

                        Copyright (c) 2018 kdevg0

						Permission is hereby granted, free of charge, to any person obtaining a copy
						of this software and associated documentation files (the "Software"), to deal
						in the Software without restriction, including without limitation the rights
						to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
						copies of the Software, and to permit persons to whom the Software is
						furnished to do so, subject to the following conditions:

						The above copyright notice and this permission notice shall be included in all
						copies or substantial portions of the Software.

						THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
						IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
						FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
						AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
						LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
						OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
						SOFTWARE.
*/


/*                                                            Section 1
                                                          __________________
               This is the section where the logics of the gates(including the ones I created) are .In other words virtual/simulated logic gates.
*/
int and_gate( int digit_x1 , int digit_y1 )
{
	int z1;
	if ( (digit_x1 == 0) || (digit_y1 == 0) ){
		z1 = 0;
	} else {
		z1 = 1;
	}
	
	return z1;
}

int or_gate( int digit_x2 , int digit_y2 )
{
	int z2;
	if ( (digit_x2 == 0) && (digit_y2 == 0) ){
		z2 = 0;
    } else {
    	z2 = 1;
	}
	
	return z2;
}

int not_gate( int k1 )
{
	int k2;
	if (k1 == 0){
		k2 = 1;
	} else {
		k2 = 0;
	}
	
	return k2;
}

int gate1( int digit_x3 , int digit_y3 )
{
	int z3;
	if(digit_x3 == digit_y3){
		z3 = 0;
	} else {
		z3 = 1;
	}
	
	return z3;
}

int gate2( int digit_x4 , int digit_y4 )
{
	int z4;
	if ( (digit_x4 == 0) && (digit_y4 == 1) ){
		z4 = 1;
	} else {
		z4 = 0;
	}
	
	return z4;
}


int gate4( int sanskrit_e, int japanese_a, int japanese_e )  //Used in 'subtraction' circuit only.
{
	int asomia_ka, asomia_ga, asomia_kha, japanese_wu;
	
	asomia_ka = and_gate( sanskrit_e, japanese_e );
	asomia_ga = not_gate( sanskrit_e );
	asomia_kha = and_gate( asomia_ga, japanese_a );
	japanese_wu = or_gate( asomia_kha, asomia_ka );
	
	return japanese_wu;
}



int gate_algorithm( int g1, int g2, int g3, int g4, int g5, int g6 )    
{
	int f1, f2, f3, m1, m2, n;
	f2 = and_gate( g2, g5 );
	m1 = and_gate( g2, g4 );
	f1 = or_gate( g1, m1) ;
	m2 = and_gate( g2, g6 );
	f3 = or_gate( g3, m2 );
	if (f2 == 1){
		n = 2;
	} else {
		if ( f1 == 1){
			n = 1;
		} else {
			n = 3;
		}
	}
	
	return n;
}



/*                                                              Section 2
                                                            _________________
        This section controls the logic of the inputs.Like whether A is binary or not,if the user wants to proceed or not etc.....
        
*/



int select_specify_character_update ( char input_key ) //Function that gives chance the user to edit any number and to specify the number which is to be edited.
{
	char character, specify_character_value;
	
	if ( input_key == 'n' )
	{
		    printf("So,you'll be editing it.\n");
		    character = 'K';    // Character is set to K, to initiate the while loop.
			while ( (character != 'A') && (character != 'B') ) {  //  (1)
			     printf("Now,please specify the number.For example, if it is A,then type A and press enter.Similarly type B if you want to edit that one.\n");
				 scanf(" %c", &character);
		          if ( ( character == 'A') || ( character == 'B' ) ){ //  (2)
			          specify_character_value = character;
					} else {
			          printf("Invalid character.\n");
					}
	        }
	}  //If the user wants to edit.
	else 
	{
	 	if( input_key == 'y' ){
	 		printf("You've chosen yes.\n");
			specify_character_value = 'y';  
	 	} else {                            
			printf("You've chosen an undefined answer.\n");
		}  // If 'y' is not returned,then while loop in main function will continue to execute,since it won't know if update1 equals 1.
		
	} 
	
	return specify_character_value;
    
	}
	
	
	/*
	 (1) --- Because "||" means the condition "character is not 'A' or character is not 'B'".Suppose it is || instead of && .In that case,since it is
	         set to 'K' which is not equal to 'A',so loop will initiate.But if someone now chooses A,it will satisfy "not 'B'" and the loop will not 
			 exit because of that "not 'B'" condition.If he again selects B, that will satisfy "not 'A'".Thus he'll be stuck in the loop.
	         
	         
	  
	  
	 (2) ---  Because "&&" means the "character is not 'A' or character is not 'B'".Suppose it is && instead of || .Then,choosing "character == 'A'" 
	           will not mean "character == 'B'".Similarly if "character == 'B'", then it won't satisfy "character == 'A'".In both cases , only else will
	           be executed.
	*/


int specify_digit_location ( char edit_number ) //Function to specify the location of the digit in number which is to be updated.
{
	int digit, specify_digit;
	
	if ( ( edit_number == 'A') || ( edit_number == 'B') ){
	    digit = 0;  //Digit set to 0, to initiate the while loop.
    	while ( (digit == 0) || (digit > 6) ) {  //  (3)
	        printf("Enter the location of the digit.For Example,if it is %c3,then type 3 and press enter.\n", edit_number);
	        scanf("%d", &digit);
	        if ( (digit != 0) && (digit <= 6) ) {  // (4)
				specify_digit = digit;
			} else { 
			    printf("Invalid location.Please enter a correct value.\n");
			}
       }    
    }
    return specify_digit;
}

/*
    (3)  Becasuse && will mean a number which is equal to zero and is greater than 6.

    (4)  Because if we use ||  and then, if 7 is entered,then if condition will be executed.But since it is not stated by the while loop ,
	    so while loop wont't allow it to happen.So,it will show the "Enter the location of the digit.For Example,if it is %c3,then type 3 and press enter.\n",but 
		else statement  will still not be executed.
		
		
*/
int new_number ( )
{
    int new_number;
	printf("Enter the new number followed by the enter key.\n");
	scanf("%d", &new_number);
	return new_number;
}

int determine_invalid ( int x1, int x2, int x3, int x4, int x5, int x6 ){
	if ( ( x1 > 1 ) ||  ( x2 > 1 ) || ( x3 > 1 ) || ( x4 > 1 ) || ( x5 > 1 ) || ( x6 > 1 ) ){
		return 1;
	} else {
		return 0;
	}
}

int main (int argc, char **argv)
{
	int a1, a2, a3, a4, a5, a6;  //Inputs of A.
	int b1, b2, b3, b4, b5, b6;  //Inputs of B.
	int p1, p2, p3, p4, p5, p6;  //Used in all circuits.
	int not_p1, not_p2, not_p3, not_p4, not_p5, not_p6;  //Used in 'compare' circuit.
	int a1_gate1, a2_gate1, a3_gate1, a4_gate1, a5_gate1, a6_gate1;  //Used in 'compare' circuit.
	int b1_gate1, b2_gate1, b3_gate1, b4_gate1, b5_gate1, b6_gate1;  //Used in 'compare' circuit.
	int intermediate1_1, intermediate1_2, intermediate1_3, intermediate2_1, result; //Intermediate for 'compare' and also result.
	int v1_1, v1_2, v1_3, v2_1, v2_2, v2_3, v3_1, v3_2, v3_3, v4_1, v4_2, v4_3; //Used in 'compare' circuit.
	int sum_led1, sum_led2, sum_led3, sum_led4, sum_led5, sum_led6, sum_led7; //Shows resuts of 'sum' circuit.
	int sub_led1, sub_led2, sub_led3, sub_led4, sub_led5, sub_led6; //Shows results of 'subtraction' circuit.
	int a6_n_b6, a5_n_b5, a4_n_b4, a3_n_b3, a2_n_b2, a1_n_b1;  //Used in 'sum' circuit.
	int sumstrj_1, sumstrj_2, sumstrj_3, sumstrj_4, sumstrj_5; //Used in 'sum' circuit.
	int sumstrj_1_n, sumstrj_2_n, sumstrj_3_n, sumstrj_4_n, sumstrj_5_n;  //Used in'sum' circuit.
	int a2_g2_b2, a3_g2_b3, a4_g2_b4, a5_g2_b5, a6_g2_b6;  //Used in 'substrction circuit.
	int substrj_1, substrj_2, substrj_3, substrj_4;  //Used in 'subtraction' circuit.
	int update2, updated_number;
	char key, sign;
	char update1 = 'k'; //It's set to 'k' so that the while loop in line number 239 starts.
	
	printf("Konnichiwa!!!!!Nomoskar!!!!!Hello!!!!!Namaste!!!!!\n");
	printf("I created this program to test whether the circuit I made works or not.I don't want to buy ICs.Don't have that much money.\n");
	printf("This program can implement/simulate the 'compare', 'addition' and 'subtraction' algorithms which I developed. \n");
	printf("This program can only implement cuicuits having a maximum input of 6 digits for each number. \n");
	printf("In case the number is not a 6 digit one, enter '0' as its previous digits, just like what you'll do in the physical one.\n");
	printf("This program uses scanf() function.So,be warned !!!!! I won't be able to save you if you enter more than 6 numbers in a row.\n");
	printf("Suppose you entered 1 1 1 0 1 1 1 as the number A and pressed enter, then you entered 1 1 1 0 1 1 as the number B and pressed enter.\n");
	printf("Then one of the digits of A, will overwrite B's.Buffer Overrun.So, be sure of what you enter.\n");
	printf("I'll, however, be able to save you from the mistake of entering an invalid binary number.You'll be given chances for that.\n");
	printf("Now enter the number A1 A2 A3 A4 A5 A6 and then press Enter.\n");
	scanf("%d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6);
	printf("Now enter the number B1 B2 B3 B4 B5 B6 and then press Enter.\n");
	scanf("%d %d %d %d %d %d", &b1, &b2, &b3, &b4, &b5, &b6);
	printf("So,you've entered A1 A2 A3 A4 A5 A6 = %d %d %d %d %d %d and B1 B2 B3 B4 B5 B6 = %d %d %d %d %d %d\n", a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6 );
	while ( ( update1 != 'y' ) ){          // Input logics starts here.Refer to section 2.
	    if ( ( determine_invalid ( a1, a2, a3, a4, a5, a6 ) == 1 ) || ( determine_invalid ( b1, b2, b3, b4, b5, b6 ) == 1) ) {
		    if ( ( determine_invalid ( a1, a2, a3, a4, a5, a6 ) == 1 ) ) {
			    printf("Number A = %d %d %d %d %d %d is not a valid binary number.Please try to locate and correct the values.\n", a1, a2, a3, a4, a5, a6);
				update1 = 'A';
		    } else {
		    	printf("Number B = %d %d %d %d %d %d is not a valid binary number.Please try to locate and correct the values.\n", b1, b2, b3, b4, b5, b6);
				update1 = 'B';
			}    // If both are true,then first A will be chosen as the update 1.Then user will be given chance to edit B.
	    } else {
		         printf("Both A1 A2 A3 A4 A5 A6 = %d %d %d %d %d %d and B1 B2 B3 B4 B5 B6 = %d %d %d %d %d %d ", a1, a2, a3, a4, a5, a6, b1, b2, b3, b4, b5, b6 );
		         printf("are valid binary numbers.\n");
				 printf("If you want to proceed then press y and Enter.Press n and Enter to edit what you've typed in.\n");
	             scanf(" %c", &key); //Can be used......
	  		     update1 = select_specify_character_update ( key );
		   }  // To determine whether to update the number A or number B or nothing at all.
        
		if ( (update1 == 'A') || (update1 == 'B') ) {
	     update2 = specify_digit_location ( update1 );
  	     updated_number = new_number ( );
		 switch ( update1 ){
			 case 'A':
				switch ( update2 ) {
					case 1:
						a1 = updated_number;
					    break;
					case 2:
						a2 = updated_number;
					    break;
					case 3:
						a3 = updated_number;
					    break;
					case 4:
						a4 = updated_number;
					    break;
					case 5:
						a5 = updated_number;
					    break;
					case 6:
						a6 = updated_number;
					    break;
				}
			  break;
			
			  case 'B':
				switch ( update2 ) {
					case 1:
						b1 = updated_number;
					    break;
					case 2:
						b2 = updated_number;
					    break;
					case 3:
						b3 = updated_number;
					    break;
					case 4:
						b4 = updated_number;
					    break;
					case 5:
						b5 = updated_number;
					    break;
					case 6:
						b6 = updated_number;
					    break;
				}
			   break;
	        }
	    } 	
	}
	     
	
	printf(" So, you chosed:-  \n A1 A2 A3 A4 A5 A6 = %d %d %d %d %d %d \n", a1, a2, a3, a4, a5, a6);
	printf(" And B1 B2 B3 B4 B5 B6 = %d %d %d %d %d %d\n\n", b1, b2, b3, b4, b5, b6);
	
	p1 = gate1( a1, b1 );                    //   Logic of the compare circuit starts here.I call these virtual/simulated connections.
	p2 = gate1( a2, b2 );                    //   Refer to Section 1 for values/virtual gates.
	p3 = gate1( a3, b3 );                    //   And also refer to my project paper for a quick visualization.
	p4 = gate1( a4, b4 );
	p5 = gate1( a5, b5 );
	p6 = gate1( a6, b6 );
	
	not_p1 = not_gate( p1 );
	not_p2 = not_gate( p2 );
	not_p3 = not_gate( p3 );
	not_p4 = not_gate( p4 );
	not_p5 = not_gate( p5 );
	not_p6 = not_gate( p6 );
	
	a1_gate1 = and_gate( a1 , p1 );
	a2_gate1 = and_gate( a2 , p2 );
	a3_gate1 = and_gate( a3 , p3 );
	a4_gate1 = and_gate( a4 , p4 );
	a5_gate1 = and_gate( a5 , p5 );
	a6_gate1 = and_gate( a6 , p6 );
	
	b1_gate1 = and_gate( b1 , p1);
	b2_gate1 = and_gate( b2 , p2);
	b3_gate1 = and_gate( b3 , p3);
	b4_gate1 = and_gate( b4 , p4);
	b5_gate1 = and_gate( b5 , p5);
	b6_gate1 = and_gate( b6 , p6);
	
	intermediate1_1 = gate_algorithm( a1_gate1, not_p1, b1_gate1, a2_gate1, not_p2, b2_gate1 );    //compare at the 1st stage......i.e.A1,B1 with A2,B2
	intermediate1_2 = gate_algorithm( a3_gate1, not_p3, b3_gate1, a4_gate1, not_p4, b4_gate1 );    //compare at the 1st stage......i.e.A3,B3 with A4,B4
	intermediate1_3 = gate_algorithm( a5_gate1, not_p5, b5_gate1, a6_gate1, not_p6, b6_gate1 );    //compare at the 1st stage......i.e.A5,B5 with A6,B6
	
	
	if ( intermediate1_1 == 1 ){
		v1_1 = 1, v1_2 = 0, v1_3 = 0;
	} else {
		if ( intermediate1_1 == 2 ){
			v1_1 = 0, v1_2 = 1, v1_3 = 0;
		} else{
			v1_1 = 0, v1_2 = 0, v1_3 = 1;
		}
	}
	
	if ( intermediate1_2 == 1){
		v2_1 = 1, v2_2 = 0, v2_3 = 0;
	} else {
		if ( intermediate1_2 == 2 ){
			v2_1 = 0, v2_2 = 1, v2_3 = 0;
		} else {
			v2_1 = 0, v2_2 = 0, v2_3 = 1;
		}
	}
		
	if ( intermediate1_3 == 1){
		v3_1 = 1, v3_2 = 0, v3_3 = 0;
	} else {
		if ( intermediate1_3 == 2 ){
			v3_1 = 0, v3_2 = 1, v3_3 = 0;
		} else {
			v3_1 = 0, v3_2 = 0, v3_3 = 1;
		}
	}	
	
	
	intermediate2_1 = gate_algorithm( v1_1, v1_2, v1_3, v2_1, v2_2, v2_3 );   //compare at the 2nd stage......i.e. intermediate1_1 with intermediate1_2
	
	if ( intermediate2_1 == 1){
		v4_1 = 1, v4_2 = 0, v4_3 = 0;
	} else {
		if ( intermediate2_1 == 2 ){
			v4_1 = 0, v4_2 = 1, v4_3 = 0;
		} else {
			v4_1 = 0, v4_2 = 0, v4_3 = 1;
		}
	}	
	
	result = gate_algorithm( v4_1, v4_2, v4_3, v3_1, v3_2, v3_3 );  //compare at the last stage......i.e. intermediate2_1 with intermediate1_3
	
	if ( result == 1){
		sign = '>';
	} else {
		if ( result == 2 ){
			sign = '=';
		} else {
			sign = '<';
		}
	}
	

	printf("So, according to the circuit I created, here are the results :-\n A1 A2 A3 A4 A5 A6 %c B1 B2 B3 B4 B5 B6 \n\n", sign);
	
	
	                                    
	a6_n_b6 = and_gate( a6 , b6 );        // Logic of the circuit that adds numbers, starts here.I call these virtual/simulated connections.
	a5_n_b5 = and_gate( a5 , b5 );        // Refer to Section 1 for values/virtual gates.
	a4_n_b4 = and_gate( a4 , b4 );        // And also refer to my project paper for a quick visualization.
	a3_n_b3 = and_gate( a3 , b3 );
	a2_n_b2 = and_gate( a2 , b2 );
	a1_n_b1 = and_gate( a1 , b1 );
	sum_led6 = gate1( p5 , a6_n_b6 );
	sumstrj_5_n = and_gate( p5 , a6_n_b6 );
	sumstrj_5   = or_gate( a5_n_b5 , sumstrj_5_n );
	sumstrj_4_n = and_gate( p4 , sumstrj_5 );
	sumstrj_4   = or_gate( a4_n_b4 , sumstrj_4_n );
	sumstrj_3_n = and_gate( p3 , sumstrj_4 );
	sumstrj_3   = or_gate( a3_n_b3 , sumstrj_3_n );
	sumstrj_2_n = and_gate( p2 , sumstrj_3 );
	sumstrj_2   = or_gate( a2_n_b2 , sumstrj_2_n );
	sumstrj_1_n = and_gate( p1 , sumstrj_2 );
	sumstrj_1   = or_gate( a1_n_b1 , sumstrj_1_n );
	sum_led7 = p6;  
	sum_led6 = gate1( p5 , a6_n_b6 );
	sum_led5 = gate1( p4 , sumstrj_5 );
	sum_led4 = gate1( p3 , sumstrj_4 );
	sum_led3 = gate1( p2 , sumstrj_3 );
	sum_led2 = gate1( p1 , sumstrj_2);
	sum_led1 = sumstrj_1;
	
	
	printf("Also , A1 A2 A3 A4 A5 A6 + B1 B2 B3 B4 B5 B6 = ");
	printf("%d %d %d %d %d %d %d.\n\n", sum_led1, sum_led2, sum_led3, sum_led4, sum_led5, sum_led6, sum_led7);
	
	
	a6_g2_b6  = gate2( a6 , b6 );   // Logic of the circuit that subtracts numbers, starts here.I call these virtual/simulated connections.
	a5_g2_b5  = gate2( a5 , b5 );   // Refer to Section 1 for values/virtual gates.
	a4_g2_b4  = gate2( a4 , b4 );   // And also refer to my project paper for a quick visualization.
	a3_g2_b3  = gate2( a3 , b3 );
	a2_g2_b2  = gate2( a2 , b2 );
	substrj_4 = gate4( p5 , a6_g2_b6 , a5_g2_b5 );
	substrj_3 = gate4( p4 , substrj_4 , a4_g2_b4 );
	substrj_2 = gate4( p3 , substrj_3 , a3_g2_b3 );
	substrj_1 = gate4( p2 , substrj_2 , a2_g2_b2 );
	sub_led6  = p6 ;
	sub_led5  = gate1( p5 , a6_g2_b6 );
	sub_led4  = gate1( p4 , substrj_4 );
	sub_led3  = gate1( p3 , substrj_3 );
	sub_led2  = gate1( p2 , substrj_2 );
	sub_led1  = gate1( p1 , substrj_1 );

	if( sign == '<' ){
		printf("Since A<B , so the circuit algorithm I developed can't determine the subtraction. \n");
		printf("I never modified it to show (-)ve numbers.\n\n");
	} else {
		printf("And, A1 A2 A3 A4 A5 A6 - B1 B2 B3 B4 B5 B6 = ");
	    printf("%d %d %d %d %d %d. \n\n", sub_led1, sub_led2, sub_led3, sub_led4, sub_led5, sub_led6);
	}
	
	
	printf("Come back again!!!!!Arigatou...Dhonyobaad...Thank you...Dhanyabaad...");
	
	
	return 0;
	
}
